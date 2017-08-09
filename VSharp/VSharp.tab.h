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
    REG_TOKEN = 261,
    UINT32_TOKEN = 262,
    UINT16_TOKEN = 263,
    UINT8_TOKEN = 264,
    INITIAL_TOKEN = 265,
    FUNCTION_TOKEN = 266,
    INTCONSTANT = 267,
    BOOLCONSTANT = 268,
    AT = 269,
    SEMICOLON = 270,
    EQUAL = 271,
    STAR = 272,
    PLUS = 273,
    MINUS = 274,
    LEFT_PAREN = 275,
    RIGHT_PAREN = 276,
    LT = 277,
    GT = 278,
    LT_OP = 279,
    GT_OP = 280,
    SHIFTLEFT = 281,
    SHIFTRIGHT = 282,
    ARROW = 283,
    DOT = 284,
    COMMA = 285,
    AMPERSAND = 286,
    EQUAL_OP = 287,
    NOTEQUAL_OP = 288,
    BOOL_TOKEN = 289,
    VOID_TOKEN = 290,
    STRUCT_TOKEN = 291,
    TRANSITION_TOKEN = 292,
    LEFT_BRACE = 293,
    RIGHT_BRACE = 294,
    LEFT_BRACKET = 295,
    RIGHT_BRACKET = 296,
    IF_TOKEN = 297,
    ELSE_TOKEN = 298,
    WHILE_TOKEN = 299,
    SIZEOF_TOKEN = 300,
    PACKBYTE_TOKEN = 301,
    RSP_TOKEN = 302,
    IDENTIFIER = 303
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 22 "VSharp.y" /* yacc.c:1915  */

    int intVal;
    int symIndex;
    ASTNode* pNode;

#line 109 "VSharp.tab.h" /* yacc.c:1915  */
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
