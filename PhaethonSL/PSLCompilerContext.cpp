#include "PSLCompilerContext.h"
#include "ASTTree.h"
#include "PSL.tab.h"
#define YY_EXTRA_TYPE PSLCompilerContext *
#include "lex.h"
#include "../PhaethonObjWriter/AsmObjWriter.h"
#include "../PhaethonObjWriter/BinaryObjWriter.h"

PSLCompilerContext::PSLCompilerContext(
    FILE *pFile,
    const char *pszAsmName,
    const char *pszObjName,
    const char *pszBinName) : _symbolTable(this)
{
    _pEntryPoint = nullptr;
    _numStructs = 0;
    _numGlobals = 0;

    _symbolTable.AddBuiltin();

    if (pszAsmName != nullptr)
    {
        _writers.push_back(std::unique_ptr<ObjWriter>(new AsmObjWriter(pszAsmName)));
    }

    if (pszObjName != nullptr)
    {
        _writers.push_back(std::unique_ptr<ObjWriter>(new BinaryObjWriter(pszObjName)));
    }

    if (pszBinName != nullptr)
    {
        _writers.push_back(std::unique_ptr<ObjWriter>(new BinObjWriter(pszBinName)));
    }

    if (_writers.size() == 0)
    {
        throw "No object writers specified";
    }

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
    OpCodes::Enum opCode,
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
        if (rawArgs[i] == nullptr || rawArgs[i]->size() == 0)
        {
            // We are done processing the arguments
            break;
        }

        for (size_t a = 0; a < rawArgs[i]->size(); a++)
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
    OpCodes::Enum opCode = OpCodes::Unknown;

    if (a1.GetResultType() == ExpressionResultType::Register)
    {
        switch (a2.GetResultType())
        {
        case ExpressionResultType::Register:
            opCode = OpCodes::MovRR;
            break;

        case ExpressionResultType::Constant:
            opCode = OpCodes::MovRC;
            break;

        case ExpressionResultType::DerefConstant:
            opCode = OpCodes::MovRdC;
            break;

        case ExpressionResultType::DerefRegisterOffset:
            opCode = OpCodes::MovRdRo;
            break;

        case ExpressionResultType::DerefRegisterIndex:
            opCode = OpCodes::MovRdRoR;
            break;

        default:
            throw "Unexpected operand type for LHS is register";
        }
    }
    else if (a1.GetResultType() == ExpressionResultType::DerefRegisterOffset)
    {
        if (a2.GetResultType() == ExpressionResultType::Register)
        {
            opCode = OpCodes::MovdRoR;
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
            opCode = OpCodes::MovdRoRR;
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
