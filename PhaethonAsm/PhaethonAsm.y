%{
#define YYDEBUG 1
#include <cstdio>
#include <iostream>
using namespace std;

#include "CodeGen/PhaethonOpCode.h"
#include "PhaethonAsmLib.h"
#include "StructDef.h"
#include "DataSegmentDef.h"
#include "InstructionNode.h"

// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;

void yyerror(const char *s);
%}

%union {
	int intVal;
	float floatVal;
	Instructions::Enum instrIndex;
	int regIndex;
	int symIndex;
	Argument arg;
	StructDef* structDef;
	StructMember* structMember;
	DataSegmentDef* dataSegmentDef;
	DataSegmentItemDef* dataSegmentItemDef;
	DataSegmentItemEntry* dataSegmentItemEntry;
	InstructionNode* instructonNode;
}

%token <intVal> INT_TOKEN
%token <instrIndex> INSTR_TOKEN_1
%token <instrIndex> INSTR_TOKEN_2
%token <instrIndex> INSTR_TOKEN_3
%token <regIndex> REG_TOKEN
%token COMMA_TOKEN
%token ADDR_LEFT
%token ADDR_RIGHT
%token COLON_TOKEN
%token STRUCT_TOKEN
%token ENDS_TOKEN
%token DATASEGMENT_TOKEN
%token ENDDATA_TOKEN
%token LEFT_PAREN_TOKEN
%token RIGHT_PAREN_TOKEN
%token MEMBEROF_TOKEN
%token DEREF_TOKEN
%token ADDRESSOF_TOKEN
%token AT_TOKEN
%token SIZEOF_TOKEN
%token <symIndex> SYMBOL_TOKEN
%type <arg> argument
%type <structDef> struct_member_list
%type <structMember> struct_member;
%type <dataSegmentDef> datasegment_item_list
%type <dataSegmentItemDef> datasegment_item
%type <dataSegmentItemDef> constant_list
%type <dataSegmentItemEntry> constant_item
%type <instructonNode> instruction

%%

assembler_unit_list:
      assembler_unit assembler_unit_list
    | assembler_unit
    ;

assembler_unit:
      instruction
    | label
    | struct_definition
	| datasegment_definition
    ;

datasegment_definition:
      DATASEGMENT_TOKEN datasegment_item_list ENDDATA_TOKEN
	;

datasegment_item_list:
      datasegment_item datasegment_item_list                           { $2->AddMember($1); $$ = $2; }
	| datasegment_item                                                 { $$ = DataSegmentDef::Construct($1); }
	;

datasegment_item:
      SYMBOL_TOKEN SYMBOL_TOKEN ADDR_LEFT INT_TOKEN ADDR_RIGHT         {
		  $$ = DataSegmentItemDef::Construct(nullptr); $$->SetIntProperty("type", $1); $$->SetIntProperty("name", $2); $$->SetIntProperty("arraySize", $4);
	}
    | SYMBOL_TOKEN SYMBOL_TOKEN constant_list                          { $3->SetIntProperty("type", $1); $3->SetIntProperty("name", $2); $$ = $3; }
	| SYMBOL_TOKEN constant_list                                       { $2->SetIntProperty("type", $1); $2->SetIntProperty("name", -1); $$ = $2; }
	;

constant_list:
      constant_item constant_list                                      { $2->AddMember($1); $$ = $2; }
	| constant_item                                                    { $$ = DataSegmentItemDef::Construct($1); }
	;

constant_item:
      INT_TOKEN                                                        { $$ = DataSegmentItemEntry::Construct(); $$->SetIntProperty("value", $1); }
	;

struct_definition:
      STRUCT_TOKEN SYMBOL_TOKEN struct_member_list ENDS_TOKEN          { $3->SetIntProperty("name", $2); }
    ;

struct_member_list:
      struct_member struct_member_list                                 { $2->AddMember($1); $$ = $2; }
    | struct_member                                                    { $$ = StructDef::Construct($1); }
    ;

struct_member:
	  SYMBOL_TOKEN                                                     { $$ = StructMember::Construct(); $$->SetIntProperty("name", $1); }
	;

instruction:
      INSTR_TOKEN_3 argument COMMA_TOKEN argument COMMA_TOKEN argument { $$ = InstructionNode::Construct(); $$->StoreInstruction($1, $2, $4, $6); }
	| INSTR_TOKEN_2 argument COMMA_TOKEN argument DEREF_TOKEN argument { $$ = InstructionNode::Construct(); $$->StoreInstruction($1, $2, $4, $6); }
	| INSTR_TOKEN_2 argument DEREF_TOKEN argument COMMA_TOKEN argument { $$ = InstructionNode::Construct(); $$->StoreInstruction($1, $2, $4, $6); }
    | INSTR_TOKEN_2 argument COMMA_TOKEN argument                      { $$ = InstructionNode::Construct(); $$->StoreInstruction($1, $2, $4, Argument::ConstructNone()); }
    | INSTR_TOKEN_1 argument                                           {
    	$$ = InstructionNode::Construct(); $$->StoreInstruction($1, $2, Argument::ConstructNone(), Argument::ConstructNone());
	}
	| INSTR_TOKEN_1                                                    {
    	$$ = InstructionNode::Construct(); $$->StoreInstruction($1, Argument::ConstructNone(), Argument::ConstructNone(), Argument::ConstructNone());
    }
    ;

argument:
      REG_TOKEN                                                        { $$ = Argument::Construct(Argument::Register, $1); }
	| ADDR_LEFT INT_TOKEN ADDR_RIGHT                                   { $$ = Argument::Construct(Argument::ConstAddress, $2);  }
	| ADDR_LEFT REG_TOKEN ADDR_RIGHT                                   { $$ = Argument::Construct(Argument::RegAddress, $2);  }
    | INT_TOKEN                                                        { $$ = Argument::Construct(Argument::Constant, $1); }
	| SYMBOL_TOKEN MEMBEROF_TOKEN SYMBOL_TOKEN                         { $$ = Argument::Construct(Argument::Constant, StructDef::CalcOffset($1, $3)); }
    | AT_TOKEN SYMBOL_TOKEN                                            { $$ = Argument::Construct(Argument::Constant, $2, SymbolType::LabelAddress); }
	| ADDRESSOF_TOKEN SYMBOL_TOKEN                                     { $$ = Argument::Construct(Argument::Constant, $2, SymbolType::VarAddress); }
	| SIZEOF_TOKEN LEFT_PAREN_TOKEN SYMBOL_TOKEN RIGHT_PAREN_TOKEN     { $$ = Argument::Construct(Argument::Constant, StructDef::GetSize($3)); }
    ;

label:
      SYMBOL_TOKEN COLON_TOKEN                                         { AddLabel($1); }

%%

int main(int argc, char** argv)
{
	//yydebug = 1;
	// open a file handle to a particular file:
	FILE *myfile = fopen(argv[1], "r");
	// make sure it is valid:
	if (!myfile)
	{
		cout << "I can't open a.snazzle.file!" << endl;
		return -1;
	}

	// set flex to read from it instead of defaulting to STDIN:
	yyin = myfile;

	// parse through the input until there is no more:
	do
	{
		yyparse();
	} while (!feof(yyin));

	OutputCode();
}

void yyerror(const char *s) {
	cout << "EEK, parse error!  Message: " << s << endl;
	// might as well halt now:
	exit(-1);
}
