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
    INTCONSTANT = 258,
    FLOATCONSTANT = 259,
    BOOLCONSTANT = 260,
    REG_INDEX = 261,
    AT = 262,
    SEMICOLON = 263,
    EQUAL = 264,
    STAR = 265,
    PLUS = 266,
    MINUS = 267,
    LEFT_PAREN = 268,
    RIGHT_PAREN = 269,
    LT = 270,
    GT = 271,
    LT_OP = 272,
    GT_OP = 273,
    SHIFTLEFT = 274,
    SHIFTRIGHT = 275,
    ARROW = 276,
    DOT = 277,
    COMMA = 278,
    AMPERSAND = 279,
    EQUAL_OP = 280,
    NOTEQUAL_OP = 281,
    PTR_TOKEN = 282,
    BYTE_TOKEN = 283,
    WORD_TOKEN = 284,
    BOOL_TOKEN = 285,
    FLOAT_TOKEN = 286,
    VOID_TOKEN = 287,
    STRUCT_TOKEN = 288,
    RETURN_TOKEN = 289,
    LEFT_BRACE = 290,
    RIGHT_BRACE = 291,
    LEFT_BRACKET = 292,
    RIGHT_BRACKET = 293,
    IF_TOKEN = 294,
    ELSE_TOKEN = 295,
    WHILE_TOKEN = 296,
    NULLPTR_TOKEN = 297,
    DOUTR_TOKEN = 298,
    DINR_TOKEN = 299,
    DLENR_TOKEN = 300,
    EXECR_TOKEN = 301,
    EXIT_TOKEN = 302,
    VPENABLE_TOKEN = 303,
    MOVRC_TOKEN = 304,
    MOVRR_TOKEN = 305,
    EMIT_TOKEN = 306,
    SIZEOF_TOKEN = 307,
    OFFSETPTR_TOKEN = 308,
    CASTPTR_TOKEN = 309,
    READPORT_TOKEN = 310,
    WRITEPORT_TOKEN = 311,
    PACKBYTE_TOKEN = 312,
    DATASEGEND_TOKEN = 313,
    SAVEREG_TOKEN = 314,
    RSP_TOKEN = 315,
    IDENTIFIER = 316
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

#line 125 "VSharp.tab.h" /* yacc.c:1915  */
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
