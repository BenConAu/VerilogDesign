%{

#include <iostream>
using namespace std;
#define YY_DECL extern "C" int yylex()

#include "PhaethonAsmTypes.h"
#include "PhaethonAsm.tab.h"

%}

%option noyywrap

%%
"//".*"\n"        ;
[ \t\n]           ;
","               { return COMMA_TOKEN; }
"["               { return ADDR_LEFT; }
"]"               { return ADDR_RIGHT; }
[0-9]+            { yylval.intVal = atoi(yytext); return INT_TOKEN; }
"mov"             { yylval.instrIndex = Instructions::Mov; return INSTR_TOKEN_2; }
"fconv"           { yylval.instrIndex = Instructions::Fconv; return INSTR_TOKEN_1; }
"fadd"            { yylval.instrIndex = Instructions::Fadd; return INSTR_TOKEN_2; }
"r"[0-9]+         { yylval.regIndex = atoi(yytext + 1); return REG_TOKEN; }
.                ;
%%