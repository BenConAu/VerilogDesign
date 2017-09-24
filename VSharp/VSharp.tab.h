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
    ALWAYS_TOKEN = 268,
    RETURN_TOKEN = 269,
    AND_OP = 270,
    OR_OP = 271,
    ENUM_TOKEN = 272,
    DRIVE_TOKEN = 273,
    CLOCK_TOKEN = 274,
    FINISH_TOKEN = 275,
    CASE_TOKEN = 276,
    SWITCH_TOKEN = 277,
    DEFAULT_TOKEN = 278,
    INTCONSTANT = 279,
    BOOLCONSTANT = 280,
    STRINGLITERAL = 281,
    AT = 282,
    SEMICOLON = 283,
    COLON = 284,
    EQUAL = 285,
    STAR = 286,
    SLASH = 287,
    PLUS = 288,
    MINUS = 289,
    LEFT_PAREN = 290,
    RIGHT_PAREN = 291,
    LT = 292,
    GT = 293,
    LT_OP = 294,
    GT_OP = 295,
    LT_EQUAL_OP = 296,
    GT_EQUAL_OP = 297,
    SHIFTLEFT = 298,
    SHIFTRIGHT = 299,
    ARROW = 300,
    DOT = 301,
    COMMA = 302,
    HAT = 303,
    BANG = 304,
    BAR = 305,
    AMPERSAND = 306,
    QUESTION = 307,
    EQUAL_OP = 308,
    NOTEQUAL_OP = 309,
    BOOL_TOKEN = 310,
    STRUCT_TOKEN = 311,
    TRANSITION_TOKEN = 312,
    LEFT_BRACE = 313,
    RIGHT_BRACE = 314,
    LEFT_BRACKET = 315,
    RIGHT_BRACKET = 316,
    IF_TOKEN = 317,
    ELSE_TOKEN = 318,
    IMPORT_TOKEN = 319,
    WIRE_TOKEN = 320,
    CONST_TOKEN = 321,
    IDENTIFIER = 322
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

#line 139 "VSharp.tab.h" /* yacc.c:1915  */
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
