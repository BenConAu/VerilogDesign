%{

#include <iostream>
using namespace std;
#define YY_DECL extern "C" int yylex()

#include "../PhaethonISA/PhaethonOpCode.h"
#include "PhaethonAsmLib.h"
#include "StructDef.h"
#include "DataSegmentDef.h"
#include "InstructionNode.h"
#include "PhaethonAsm.tab.h"

#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno;

%}

%option noyywrap
%option yylineno

%%
"//".*"\n"           ;
[ \t\n]              ;
"::"                 { return MEMBEROF_TOKEN; }
":"                  { return COLON_TOKEN; }
","                  { return COMMA_TOKEN; }
"["                  { return ADDR_LEFT; }
"]"                  { return ADDR_RIGHT; }
"&"                  { return ADDRESSOF_TOKEN; }
"@"                  { return AT_TOKEN; }
"->"                 { return DEREF_TOKEN; }
"("                  { return LEFT_PAREN_TOKEN; }
")"                  { return RIGHT_PAREN_TOKEN; }
[0-9]+               { yylval.intVal = atoi(yytext); return INT_TOKEN; }
"f"[0-9]+"\."[0-9]*  { yylval.floatVal = (float)atof(yytext + 1); return INT_TOKEN; }
"mov"                { yylval.instrIndex = Instructions::Mov; return INSTR_TOKEN_2; }
"fconv"              { yylval.instrIndex = Instructions::Fconv; return INSTR_TOKEN_1; }
"fadd"               { yylval.instrIndex = Instructions::Fadd; return INSTR_TOKEN_2; }
"fsub"               { yylval.instrIndex = Instructions::Fadd; return INSTR_TOKEN_2; }
"fmuladd"            { yylval.instrIndex = Instructions::Fmuladd; return INSTR_TOKEN_3; }
"fmin"               { yylval.instrIndex = Instructions::Fmin; return INSTR_TOKEN_2; }
"fmax"               { yylval.instrIndex = Instructions::Fmax; return INSTR_TOKEN_2; }
"fmul"               { yylval.instrIndex = Instructions::Fmul; return INSTR_TOKEN_2; }
"fdiv"               { yylval.instrIndex = Instructions::Fdiv; return INSTR_TOKEN_2; }
"vfadd"              { yylval.instrIndex = Instructions::Vfadd; return INSTR_TOKEN_2; }
"cmp"                { yylval.instrIndex = Instructions::Cmp; return INSTR_TOKEN_2; }
"jmp"                { yylval.instrIndex = Instructions::Jmp; return INSTR_TOKEN_1; }
"jne"                { yylval.instrIndex = Instructions::Jne; return INSTR_TOKEN_1; }
"je"                 { yylval.instrIndex = Instructions::Je; return INSTR_TOKEN_1; }
"dout"               { yylval.instrIndex = Instructions::Dout; return INSTR_TOKEN_1; }
"inc"                { yylval.instrIndex = Instructions::Inc; return INSTR_TOKEN_1; }
"add"                { yylval.instrIndex = Instructions::Add; return INSTR_TOKEN_2; }
"dec"                { yylval.instrIndex = Instructions::Dec; return INSTR_TOKEN_1; }
"muladd"             { yylval.instrIndex = Instructions::MulAdd; return INSTR_TOKEN_3; }
"push"               { yylval.instrIndex = Instructions::Push; return INSTR_TOKEN_1; }
"pop"                { yylval.instrIndex = Instructions::Pop; return INSTR_TOKEN_1; }
"call"               { yylval.instrIndex = Instructions::Call; return INSTR_TOKEN_1; }
"ret"                { yylval.instrIndex = Instructions::Ret; return INSTR_TOKEN_0; }
"rcall"              { yylval.instrIndex = Instructions::RCall; return INSTR_TOKEN_2; }
"rret"               { yylval.instrIndex = Instructions::RRet; return INSTR_TOKEN_0; }
"struct"             { return STRUCT_TOKEN; }
"ends"               { return ENDS_TOKEN; }
"datasegment"        { return DATASEGMENT_TOKEN; }
"enddata"            { return ENDDATA_TOKEN; }
"sizeof"             { return SIZEOF_TOKEN; }
"r"[0-9]+            { yylval.regIndex = atoi(yytext + 1); return REG_TOKEN; }
"rsp"                { yylval.regIndex = 64; return REG_TOKEN; }
"rfl"                { yylval.regIndex = 65; return REG_TOKEN; }
[A-Za-z][A-Za-z0-9]* { yylval.symIndex = AddSymbol(yytext); return SYMBOL_TOKEN; }
.                    ;
%%
