%{

#include <iostream>
using namespace std;
#define YY_DECL extern "C" int yylex()

#include "PhaethonAsmTypes.h"
#include "PhaethonAsmLib.h"
#include "PhaethonAsm.tab.h"

%}

%option noyywrap

%%
"//".*"\n"           ;
[ \t\n]              ;
"::"                 { return MEMBEROF_TOKEN; }
":"                  { return COLON_TOKEN; }
","                  { return COMMA_TOKEN; }
"["                  { return ADDR_LEFT; }
"]"                  { return ADDR_RIGHT; }
"->"                 { return DEREF_TOKEN; }
[0-9]+               { yylval.intVal = atoi(yytext); return INT_TOKEN; }
"mov"                { yylval.instrIndex = Instructions::Mov; return INSTR_TOKEN_2; }
"fconv"              { yylval.instrIndex = Instructions::Fconv; return INSTR_TOKEN_1; }
"fadd"               { yylval.instrIndex = Instructions::Fadd; return INSTR_TOKEN_2; }
"fsub"               { yylval.instrIndex = Instructions::Fadd; return INSTR_TOKEN_2; }
"fmuladd"            { yylval.instrIndex = Instructions::Fmuladd; return INSTR_TOKEN_3; }
"fmin"               { yylval.instrIndex = Instructions::Fmin; return INSTR_TOKEN_3; }
"fmul"               { yylval.instrIndex = Instructions::Fmul; return INSTR_TOKEN_2; }
"cmp"                { yylval.instrIndex = Instructions::Cmp; return INSTR_TOKEN_2; }
"jmp"                { yylval.instrIndex = Instructions::Jmp; return INSTR_TOKEN_1; }
"dout"               { yylval.instrIndex = Instructions::Dout; return INSTR_TOKEN_1; }
"struct"             { return STRUCT_TOKEN; }
"ends"               { return ENDS_TOKEN; }
"r"[0-9]+            { yylval.regIndex = atoi(yytext + 1); return REG_TOKEN; }
[A-Za-z][A-Za-z0-9]* { yylval.symIndex = AddSymbol(yytext); return SYMBOL_TOKEN; }
.                    ;
%%