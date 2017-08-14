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
    UINT_TOKEN = 261,
    UINT32_TOKEN = 262,
    UINT16_TOKEN = 263,
    UINT8_TOKEN = 264,
    VOID_TOKEN = 265,
    INITIAL_TOKEN = 266,
    RETURN_TOKEN = 267,
    AND_OP = 268,
    OR_OP = 269,
    INTCONSTANT = 270,
    BOOLCONSTANT = 271,
    AT = 272,
    SEMICOLON = 273,
    COLON = 274,
    EQUAL = 275,
    STAR = 276,
    PLUS = 277,
    MINUS = 278,
    LEFT_PAREN = 279,
    RIGHT_PAREN = 280,
    LT = 281,
    GT = 282,
    LT_OP = 283,
    GT_OP = 284,
    SHIFTLEFT = 285,
    SHIFTRIGHT = 286,
    ARROW = 287,
    DOT = 288,
    COMMA = 289,
    AMPERSAND = 290,
    EQUAL_OP = 291,
    NOTEQUAL_OP = 292,
    BOOL_TOKEN = 293,
    STRUCT_TOKEN = 294,
    TRANSITION_TOKEN = 295,
    LEFT_BRACE = 296,
    RIGHT_BRACE = 297,
    LEFT_BRACKET = 298,
    RIGHT_BRACKET = 299,
    IF_TOKEN = 300,
    ELSE_TOKEN = 301,
    WHILE_TOKEN = 302,
    SIZEOF_TOKEN = 303,
    PACKBYTE_TOKEN = 304,
    RSP_TOKEN = 305,
    IDENTIFIER = 306
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

#line 112 "VSharp.tab.h" /* yacc.c:1915  */
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
