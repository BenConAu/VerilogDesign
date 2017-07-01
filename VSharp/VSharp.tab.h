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
    INTCONSTANT = 260,
    FLOATCONSTANT = 261,
    BOOLCONSTANT = 262,
    REG_INDEX = 263,
    AT = 264,
    SEMICOLON = 265,
    EQUAL = 266,
    STAR = 267,
    PLUS = 268,
    MINUS = 269,
    LEFT_PAREN = 270,
    RIGHT_PAREN = 271,
    LT = 272,
    GT = 273,
    LT_OP = 274,
    GT_OP = 275,
    SHIFTLEFT = 276,
    SHIFTRIGHT = 277,
    ARROW = 278,
    DOT = 279,
    COMMA = 280,
    AMPERSAND = 281,
    EQUAL_OP = 282,
    NOTEQUAL_OP = 283,
    PTR_TOKEN = 284,
    BYTE_TOKEN = 285,
    WORD_TOKEN = 286,
    BOOL_TOKEN = 287,
    FLOAT_TOKEN = 288,
    VOID_TOKEN = 289,
    STRUCT_TOKEN = 290,
    RETURN_TOKEN = 291,
    LEFT_BRACE = 292,
    RIGHT_BRACE = 293,
    LEFT_BRACKET = 294,
    RIGHT_BRACKET = 295,
    IF_TOKEN = 296,
    ELSE_TOKEN = 297,
    WHILE_TOKEN = 298,
    NULLPTR_TOKEN = 299,
    DOUTR_TOKEN = 300,
    DINR_TOKEN = 301,
    DLENR_TOKEN = 302,
    EXECR_TOKEN = 303,
    EXIT_TOKEN = 304,
    VPENABLE_TOKEN = 305,
    MOVRC_TOKEN = 306,
    MOVRR_TOKEN = 307,
    EMIT_TOKEN = 308,
    SIZEOF_TOKEN = 309,
    OFFSETPTR_TOKEN = 310,
    CASTPTR_TOKEN = 311,
    READPORT_TOKEN = 312,
    WRITEPORT_TOKEN = 313,
    PACKBYTE_TOKEN = 314,
    DATASEGEND_TOKEN = 315,
    SAVEREG_TOKEN = 316,
    RSP_TOKEN = 317,
    IDENTIFIER = 318
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

#line 127 "VSharp.tab.h" /* yacc.c:1915  */
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
