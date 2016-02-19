%{

#define YY_DECL extern "C" int yylex()

#include "ASTTree.h"
#include "PSLGlobal.h"
#include "PSL.tab.h"

%}

%option noyywrap
%option yylineno

%%
"//".*"\n"           ;
"\n"                 ;
"*"                  { return STAR; }
"="                  { return EQUAL; }
";"                  { return SEMICOLON; }
"{"                  { return LEFT_BRACE; }
"}"                  { return RIGHT_BRACE; }
"("                  { return LEFT_PAREN; }
")"                  { return RIGHT_PAREN; }
"int"                { return INT_TOKEN; }
[0-9]+               { yylval.intVal = atoi(yytext); return INTCONSTANT; }
"f"[0-9]+"\."[0-9]*  { yylval.floatVal = (float)atof(yytext + 1); return FLOATCONSTANT; }
[A-Za-z][A-Za-z0-9]* { yylval.symIndex = AddSymbol(yytext); return IDENTIFIER; }
.                    ;
%%
