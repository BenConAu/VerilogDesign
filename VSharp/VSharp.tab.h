/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_VSHARP_TAB_H_INCLUDED
# define YY_YY_VSHARP_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MODULE_TOKEN = 258,
    OUT_TOKEN = 259,
    STATE_TOKEN = 260,
    INTCONSTANT = 261,
    FLOATCONSTANT = 262,
    BOOLCONSTANT = 263,
    REG_INDEX = 264,
    AT = 265,
    SEMICOLON = 266,
    EQUAL = 267,
    STAR = 268,
    PLUS = 269,
    MINUS = 270,
    LEFT_PAREN = 271,
    RIGHT_PAREN = 272,
    LT = 273,
    GT = 274,
    LT_OP = 275,
    GT_OP = 276,
    SHIFTLEFT = 277,
    SHIFTRIGHT = 278,
    ARROW = 279,
    DOT = 280,
    COMMA = 281,
    AMPERSAND = 282,
    EQUAL_OP = 283,
    NOTEQUAL_OP = 284,
    PTR_TOKEN = 285,
    BYTE_TOKEN = 286,
    WORD_TOKEN = 287,
    BOOL_TOKEN = 288,
    FLOAT_TOKEN = 289,
    VOID_TOKEN = 290,
    STRUCT_TOKEN = 291,
    RETURN_TOKEN = 292,
    LEFT_BRACE = 293,
    RIGHT_BRACE = 294,
    LEFT_BRACKET = 295,
    RIGHT_BRACKET = 296,
    IF_TOKEN = 297,
    ELSE_TOKEN = 298,
    WHILE_TOKEN = 299,
    NULLPTR_TOKEN = 300,
    SIZEOF_TOKEN = 301,
    OFFSETPTR_TOKEN = 302,
    CASTPTR_TOKEN = 303,
    READPORT_TOKEN = 304,
    PACKBYTE_TOKEN = 305,
    DATASEGEND_TOKEN = 306,
    SAVEREG_TOKEN = 307,
    RSP_TOKEN = 308,
    IDENTIFIER = 309
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 22 "VSharp.y" /* yacc.c:1915  */

    int intVal;
    float floatVal;
    int symIndex;
    ASTNode* pNode;
    OpCode opCode;
    RegIndex regIndex;

#line 118 "VSharp.tab.h" /* yacc.c:1915  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int yyparse (PSLCompilerContext* pContext);

#endif /* !YY_YY_VSHARP_TAB_H_INCLUDED  */
