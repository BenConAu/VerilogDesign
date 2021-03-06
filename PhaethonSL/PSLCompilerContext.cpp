#include "PSLCompilerContext.h"
#include "ASTTree.h"
#include "PSL.tab.h"
#define YY_EXTRA_TYPE PSLCompilerContext *
#include "lex.h"
#include "../PhaethonObjWriter/AsmObjWriter.h"
#include "../PhaethonObjWriter/BinaryObjWriter.h"
#include "../PhaethonObjWriter/BinObjectWriter.h"
#include "../PhaethonObjWriter/MifObjWriter.h"

PSLCompilerContext::PSLCompilerContext(
    const char *pszInputFile
    ) : _symbolTable(this)
{
	FILE *pFile = ::fopen(pszInputFile, "r");

    _pEntryPoint = nullptr;
    _numStructs = 0;
    _numGlobals = 0;

    _symbolTable.AddBuiltin();

    std::string base = pszInputFile;
    base = base.substr(0, base.length() - 3);

    _writers.push_back(std::unique_ptr<ObjWriter>(new AsmObjWriter((base + "asm").c_str())));
    _writers.push_back(std::unique_ptr<ObjWriter>(new BinaryObjWriter((base + "pao").c_str())));
    _writers.push_back(std::unique_ptr<ObjWriter>(new BinObjWriter((base + "bin").c_str())));
    _writers.push_back(std::unique_ptr<ObjWriter>(new MifObjWriter((base + "mif").c_str())));

    yylex_init(&pScanner);
    yyset_extra(this, pScanner);

    // set flex to read from file instead of defaulting to STDIN:
    yyrestart(pFile, pScanner);
}

PSLCompilerContext::~PSLCompilerContext()
{
    yylex_destroy(pScanner);
}

int PSLCompilerContext::AddSymbol(const char *pszSymbol)
{
    //    printf("Adding symbol\n");
    for (size_t i = 0; i < _symbols.size(); i++)
    {
        if (_symbols[i].compare(pszSymbol) == 0)
        {
            return i;
        }
    }

    _symbols.push_back(pszSymbol);
    return (_symbols.size() - 1);
}

void PSLCompilerContext::AddStructDef(ASTNode *pNode)
{
    auto rootStart = _rootNodes.begin();

    // Insert at end of struct list
    _rootNodes.insert(rootStart + _numStructs, std::unique_ptr<ASTNode>(pNode));

    // Seam moves along by 1
    _numStructs++;
}

void PSLCompilerContext::AddGlobal(ASTNode *pNode)
{
    auto rootStart = _rootNodes.begin();

    _rootNodes.insert(rootStart + _numStructs + _numGlobals, std::unique_ptr<ASTNode>(pNode));

    _numGlobals++;
}

void PSLCompilerContext::AddFuncDef(ASTNode *pNode)
{
    // Just tack onto the end
    _rootNodes.push_back(std::unique_ptr<ASTNode>(pNode));
}

void PSLCompilerContext::Parse()
{
    //printf("Doing Bison parse\n");

    // Parse through the input until there is no more:
    yyparse(this);

    //printf("Doing Verify pass\n");

    // Verify the tree
    for (size_t i = 0; i < _rootNodes.size(); i++)
    {
        _rootNodes[i]->VerifyNode();
    }

    //printf("Doing Process pass\n");

    // Before processing, reorder things so that the entry point is before
    // all of the other functions. It needs to have the code first, because
    // it is an entry point after all.
    for (size_t i = _numStructs + _numGlobals + 1; i < _rootNodes.size(); i++)
    {
        // Add after most recent function node unless it is main
        FunctionDeclaratorNode *pFuncNode = dynamic_cast<FunctionDeclaratorNode *>(_rootNodes[i].get());

        if (pFuncNode->IsEntryPoint())
        {
            //printf("Moving entry point\n");
            std::unique_ptr<ASTNode> temp = std::move(_rootNodes[i]);
            _rootNodes[i] = std::move(_rootNodes[_numStructs + _numGlobals]);
            _rootNodes[_numStructs + _numGlobals] = std::move(temp);
        }
    }

    // Process the tree
    for (size_t i = 0; i < _rootNodes.size(); i++)
    {
        _rootNodes[i]->ProcessNode();
    }

    //printf("Doing Finish pass\n");

    // Code output is complete
    for (size_t i = 0; i < _writers.size(); i++)
    {
        _writers[i]->FinishCode();
    }
}

void PSLCompilerContext::SetEntryPoint(FunctionDeclaratorNode *pEntryPoint)
{
    if (_pEntryPoint != nullptr)
    {
        throw "Cannot have two entry points";
    }

    _pEntryPoint = pEntryPoint;
}

void PSLCompilerContext::OutputInstruction(
    OpCode opCode,
    const ExpressionResult &a1,
    const ExpressionResult &a2,
    const ExpressionResult &a3)
{
    // Nice to operate on these like they are an array
    const ExpressionResult *rawArgs[3] = { &a1, &a2, &a3 };

    // The arguments are non by default if nothing else specified
    ObjArgument passArgs[3];

    int curr = 0;
    for (int i = 0; i < 3; i++)
    {
        if (rawArgs[i] == nullptr || rawArgs[i]->GetOperandCount() == 0)
        {
            // We are done processing the arguments
            break;
        }

        for (size_t a = 0; a < rawArgs[i]->GetOperandCount(); a++)
        {
            if (curr == 3)
            {
                throw "Too many operands passed to OutputInstrution";
            }

            passArgs[curr] = rawArgs[i]->GetOperand(a).GetObjArgument();
            curr++;
        }
    }

    for (int i = 0; i < _writers.size(); i++)
    {
        _writers[i]->OutputInstruction(opCode, passArgs);
    }
}

void PSLCompilerContext::OutputMovInstruction(
    const ExpressionResult &a1,
    const ExpressionResult &a2)
{
    OpCode opCode = OpCode::Unknown;

    if (a1.GetResultType() == ExpressionResultType::Register)
    {
        switch (a2.GetResultType())
        {
        case ExpressionResultType::Register:
            opCode = OpCode::MovRR;
            break;

        case ExpressionResultType::Constant:
            opCode = OpCode::MovRC;
            break;

        case ExpressionResultType::DerefConstant:
            opCode = OpCode::MovRdC;
            break;

        case ExpressionResultType::DerefRegisterOffset:
            opCode = OpCode::MovRdRo;
            break;

        case ExpressionResultType::DerefRegisterIndex:
            opCode = OpCode::MovRdRoR;
            break;

        default:
            throw "Unexpected operand type for LHS is register";
        }
    }
    else if (a1.GetResultType() == ExpressionResultType::DerefRegisterOffset)
    {
        if (a2.GetResultType() == ExpressionResultType::Register)
        {
            opCode = OpCode::MovdRoR;
        }
        else
        {
            throw "Unexpected operand type for LHS is dRo";
        }
    }
    else if (a1.GetResultType() == ExpressionResultType::DerefRegisterIndex)
    {
        if (a2.GetResultType() == ExpressionResultType::Register)
        {
            opCode = OpCode::MovdRoRR;
        }
        else
        {
            throw "Unexpected operand type for LHS is dRiR";
        }
    }
    else
    {
        throw "Unexpected operand type for LHS";
    }

    OutputInstruction(
        opCode,
        a1,
        a2);
}

void PSLCompilerContext::OutputLabel(const char *pszLabel)
{
    for (int i = 0; i < _writers.size(); i++)
    {
        _writers[i]->OutputLabel(pszLabel);
    }
}

void PSLCompilerContext::UserAction(void *pVoidLocation, const char *pszText)
{
    YYLTYPE *pLocation = (YYLTYPE *)pVoidLocation;

    pLocation->first_line = pLocation->last_line;
    pLocation->first_column = pLocation->last_column;
    for (int i = 0; pszText[i] != '\0'; i++)
    {
        if (pszText[i] == '\n')
        {
            pLocation->last_line++;
            pLocation->last_column = 0;
        }
        else
        {
            pLocation->last_column++;
        }
    }
}
