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
    INTCONSTANT = 259,
    FLOATCONSTANT = 260,
    BOOLCONSTANT = 261,
    REG_INDEX = 262,
    AT = 263,
    SEMICOLON = 264,
    EQUAL = 265,
    STAR = 266,
    PLUS = 267,
    MINUS = 268,
    LEFT_PAREN = 269,
    RIGHT_PAREN = 270,
    LT = 271,
    GT = 272,
    LT_OP = 273,
    GT_OP = 274,
    SHIFTLEFT = 275,
    SHIFTRIGHT = 276,
    ARROW = 277,
    DOT = 278,
    COMMA = 279,
    AMPERSAND = 280,
    EQUAL_OP = 281,
    NOTEQUAL_OP = 282,
    PTR_TOKEN = 283,
    BYTE_TOKEN = 284,
    WORD_TOKEN = 285,
    BOOL_TOKEN = 286,
    FLOAT_TOKEN = 287,
    VOID_TOKEN = 288,
    STRUCT_TOKEN = 289,
    RETURN_TOKEN = 290,
    LEFT_BRACE = 291,
    RIGHT_BRACE = 292,
    LEFT_BRACKET = 293,
    RIGHT_BRACKET = 294,
    IF_TOKEN = 295,
    ELSE_TOKEN = 296,
    WHILE_TOKEN = 297,
    NULLPTR_TOKEN = 298,
    DOUTR_TOKEN = 299,
    DINR_TOKEN = 300,
    DLENR_TOKEN = 301,
    EXECR_TOKEN = 302,
    EXIT_TOKEN = 303,
    VPENABLE_TOKEN = 304,
    MOVRC_TOKEN = 305,
    MOVRR_TOKEN = 306,
    EMIT_TOKEN = 307,
    SIZEOF_TOKEN = 308,
    OFFSETPTR_TOKEN = 309,
    CASTPTR_TOKEN = 310,
    READPORT_TOKEN = 311,
    WRITEPORT_TOKEN = 312,
    PACKBYTE_TOKEN = 313,
    DATASEGEND_TOKEN = 314,
    SAVEREG_TOKEN = 315,
    RSP_TOKEN = 316,
    IDENTIFIER = 317
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

#line 126 "VSharp.tab.h" /* yacc.c:1915  */
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
