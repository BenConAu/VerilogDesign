%{

#include "ASTTree.h"
#include "ParserContext.h"
#include "VSharp.tab.h"

#define YY_EXTRA_TYPE ParserContext*
#define YY_USER_ACTION yyextra->UserAction(yylloc, yytext);

%}

%option bison-locations
%option reentrant
%option bison-bridge
%option noyywrap
%option yylineno
%option stack

%x STRING_LITERAL

%%
"//".*"\n"           ;
"\n"                 ;
"@"                  { return AT; }
"*"                  { return STAR; }
"+"                  { return PLUS; }
"-"                  { return MINUS; }
"="                  { return EQUAL; }
":"                  { return COLON; }
"^"                  { return HAT; }
"!"                  { return BANG; }
";"                  { return SEMICOLON; }
"{"                  { return LEFT_BRACE; }
"}"                  { return RIGHT_BRACE; }
"("                  { return LEFT_PAREN; }
")"                  { return RIGHT_PAREN; }
"["                  { return LEFT_BRACKET; }
"]"                  { return RIGHT_BRACKET; }
"?"                  { return QUESTION; }
"->"                 { return ARROW; }
"<<"                 { return SHIFTLEFT; }
">>"                 { return SHIFTRIGHT; }
".<"                 { return LT_OP; }
">."                 { return GT_OP; }
"<="                 { return LT_EQUAL_OP; }
">="                 { return GT_EQUAL_OP; }
"<"                  { return LT; }
">"                  { return GT; }
"\."                 { return DOT; }
","                  { return COMMA; }
"&"                  { return AMPERSAND; }
"&&"                 { return AND_OP; }
"||"                 { return OR_OP; }
"=="                 { return EQUAL_OP; }
"!="                 { return NOTEQUAL_OP; }
"out"                { return OUT_TOKEN; }
"state"              { return STATE_TOKEN; }
"uint"               { return UINT_TOKEN; }
"uint64"             { return UINT64_TOKEN; }
"uint32"             { return UINT32_TOKEN; }
"uint16"             { return UINT16_TOKEN; }
"uint8"              { return UINT8_TOKEN; }
"void"               { return VOID_TOKEN; }
"clock"              { return CLOCK_TOKEN; }
"initial"            { return INITIAL_TOKEN; }
"bool"               { return BOOL_TOKEN; }
"struct"             { return STRUCT_TOKEN; }
"drive"              { return DRIVE_TOKEN; }
"module"             { return MODULE_TOKEN; }
"transition"         { return TRANSITION_TOKEN; }
"return"             { return RETURN_TOKEN; }
"import"             { return IMPORT_TOKEN; }
"if"                 { return IF_TOKEN; }
"else"               { return ELSE_TOKEN; }
"enum"               { return ENUM_TOKEN; }
"const"              { return CONST_TOKEN; }
"__finish"           { return FINISH_TOKEN; }
"wire"               { return WIRE_TOKEN; }
"switch"                    { return SWITCH_TOKEN; }
"case"                      { return CASE_TOKEN; }
"default"                   { return DEFAULT_TOKEN; }
"true"                      { yylval->constVal = UIntConstant((unsigned int)1, 1); return BOOLCONSTANT; }
"false"                     { yylval->constVal = UIntConstant((unsigned int)0, 1); return BOOLCONSTANT; }
[0-9]+                      { yylval->constVal = { static_cast<unsigned int>(atoi(yytext)), 32 }; return INTCONSTANT; }
[0-9]+"u"[0-9]+             { yylval->constVal = UIntConstant(yytext, 10); return INTCONSTANT; }
"0x"[0-9A-Fa-f]+            { yylval->constVal = { static_cast<unsigned int>(strtol(yytext + 2, nullptr, 16)), 32 }; return INTCONSTANT; }
"0x"[0-9A-Fa-f]+"u"[0-9]+   { yylval->constVal = UIntConstant(yytext + 2, 16); return INTCONSTANT; }
"0b"[0-1]+                  { yylval->constVal = { static_cast<unsigned int>(strtol(yytext + 2, nullptr, 2)), static_cast<unsigned int>(strlen(yytext) - 2) }; return INTCONSTANT; }
[A-Za-z_][A-Za-z0-9_]*      { yylval->symIndex = yyextra->AddSymbol(yytext); return IDENTIFIER; }
"\""                 { yy_push_state(STRING_LITERAL, yyscanner); yyextra->StartString(); }
.                    ;

<STRING_LITERAL>"\"" { yy_pop_state(yyscanner); return STRINGLITERAL; }
<STRING_LITERAL>"\n" { yyextra->ReportError(*yylloc, "String literal cannot span lines"); }
<STRING_LITERAL>.    { yyextra->AppendString(yytext); }

%%
