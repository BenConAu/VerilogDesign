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
"Deref"           { return DEREF_TOKEN; }
"AddressOf"       { return ADDRESSOF_TOKEN; }
"Offset"          { return OFFSET_TOKEN; }
"None"            { return NONE_TOKEN; }
"RAM"             { return RAM_TOKEN; }
"NoFlags"         { return NOFLAGS_TOKEN; }
":"               { return COLON_TOKEN; }
[A-Za-z]+         { yylval.symIndex = AddSymbol(yytext); return SYMBOL_TOKEN; }
.                 ;
%%
