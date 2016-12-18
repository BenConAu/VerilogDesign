%{

#include "ASTTree.h"
#include "PSLCompilerContext.h"
#include "PSL.tab.h"

#define YY_EXTRA_TYPE PSLCompilerContext*
#define YY_USER_ACTION yyextra->UserAction(yylloc, yytext);

%}

%option bison-locations
%option reentrant
%option bison-bridge
%option noyywrap
%option yylineno

%%
"//".*"\n"           ;
"\n"                 ;
"*"                  { return STAR; }
"+"                  { return PLUS; }
"="                  { return EQUAL; }
";"                  { return SEMICOLON; }
"{"                  { return LEFT_BRACE; }
"}"                  { return RIGHT_BRACE; }
"("                  { return LEFT_PAREN; }
")"                  { return RIGHT_PAREN; }
"->"                 { return ARROW; }
"<"                  { return LT; }
">"                  { return GT; }
"\."                 { return DOT; }
","                  { return COMMA; }
"&"                  { return AMPERSAND; }
"ptr"                { return PTR_TOKEN; }
"word"               { return WORD_TOKEN; }
"float"              { return FLOAT_TOKEN; }
"void"               { return VOID_TOKEN; }
"struct"             { return STRUCT_TOKEN; }
"nullptr"            { return NULLPTR_TOKEN; }
"debugout"           { return DEBUGOUT_TOKEN; }
"sizeof"             { return SIZEOF_TOKEN; }
"offsetptr"          { return OFFSETPTR_TOKEN; }
"castptr"            { return CASTPTR_TOKEN; }
"return"             { return RETURN_TOKEN; }
[0-9]+               { yylval->intVal = atoi(yytext); return INTCONSTANT; }
"f"[0-9]+"\."[0-9]*  { yylval->floatVal = (float)atof(yytext + 1); return FLOATCONSTANT; }
[A-Za-z_][A-Za-z0-9_]* { yylval->symIndex = yyextra->AddSymbol(yytext); return IDENTIFIER; }
.                    ;
%%
