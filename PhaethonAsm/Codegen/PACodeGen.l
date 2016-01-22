%{

#include <iostream>
using namespace std;
#define YY_DECL extern "C" int yylex()

#include "PACodeGenLib.h"
#include "PACodeGen.tab.h"

%}

%option noyywrap

%%
[ \t\n]           ;
"Register"        { return REGISTER_TOKEN; }
"Constant"        { return CONSTANT_TOKEN; }
"ConstAddress"    { return CONSTADDRESS_TOKEN; }
"RegAddress"      { return REGADDRESS_TOKEN; }
"None"            { return NONE_TOKEN; }
[A-Za-z]+         { yylval.symIndex = AddSymbol(yytext); return SYMBOL_TOKEN; }
.                 ;
%%
