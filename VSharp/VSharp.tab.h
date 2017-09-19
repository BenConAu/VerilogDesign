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
/* "%code requires" blocks.  */
#line 23 "VSharp.y" /* yacc.c:1915  */

#include "UIntConstant.h"
#include "EnumItem.h"

class ASTNode;
class ParserContext;

#line 52 "VSharp.tab.h" /* yacc.c:1915  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MODULE_TOKEN = 258,
    OUT_TOKEN = 259,
    STATE_TOKEN = 260,
    UINT_TOKEN = 261,
    UINT64_TOKEN = 262,
    UINT32_TOKEN = 263,
    UINT16_TOKEN = 264,
    UINT8_TOKEN = 265,
    VOID_TOKEN = 266,
    INITIAL_TOKEN = 267,
    RETURN_TOKEN = 268,
    AND_OP = 269,
    OR_OP = 270,
    ENUM_TOKEN = 271,
    DRIVE_TOKEN = 272,
    CLOCK_TOKEN = 273,
    FINISH_TOKEN = 274,
    CASE_TOKEN = 275,
    SWITCH_TOKEN = 276,
    DEFAULT_TOKEN = 277,
    INTCONSTANT = 278,
    BOOLCONSTANT = 279,
    STRINGLITERAL = 280,
    AT = 281,
    SEMICOLON = 282,
    COLON = 283,
    EQUAL = 284,
    STAR = 285,
    PLUS = 286,
    MINUS = 287,
    LEFT_PAREN = 288,
    RIGHT_PAREN = 289,
    LT = 290,
    GT = 291,
    LT_OP = 292,
    GT_OP = 293,
    LT_EQUAL_OP = 294,
    GT_EQUAL_OP = 295,
    SHIFTLEFT = 296,
    SHIFTRIGHT = 297,
    ARROW = 298,
    DOT = 299,
    COMMA = 300,
    HAT = 301,
    BANG = 302,
    AMPERSAND = 303,
    QUESTION = 304,
    EQUAL_OP = 305,
    NOTEQUAL_OP = 306,
    BOOL_TOKEN = 307,
    STRUCT_TOKEN = 308,
    TRANSITION_TOKEN = 309,
    LEFT_BRACE = 310,
    RIGHT_BRACE = 311,
    LEFT_BRACKET = 312,
    RIGHT_BRACKET = 313,
    IF_TOKEN = 314,
    ELSE_TOKEN = 315,
    IMPORT_TOKEN = 316,
    WIRE_TOKEN = 317,
    CONST_TOKEN = 318,
    IDENTIFIER = 319
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 32 "VSharp.y" /* yacc.c:1915  */

    UIntConstant constVal;
    int symIndex;
    ASTNode* pNode;
    EnumItem _EnumItem;

#line 136 "VSharp.tab.h" /* yacc.c:1915  */
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



int yyparse (ParserContext* pContext);

#endif /* !YY_YY_VSHARP_TAB_H_INCLUDED  */
