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

#ifndef YY_YY_PSL_TAB_H_INCLUDED
# define YY_YY_PSL_TAB_H_INCLUDED
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
    AT = 261,
    SEMICOLON = 262,
    EQUAL = 263,
    STAR = 264,
    PLUS = 265,
    MINUS = 266,
    LEFT_PAREN = 267,
    RIGHT_PAREN = 268,
    LT = 269,
    GT = 270,
    LT_OP = 271,
    GT_OP = 272,
    SHIFTLEFT = 273,
    SHIFTRIGHT = 274,
    ARROW = 275,
    DOT = 276,
    COMMA = 277,
    AMPERSAND = 278,
    EQUAL_OP = 279,
    NOTEQUAL_OP = 280,
    PTR_TOKEN = 281,
    BYTE_TOKEN = 282,
    WORD_TOKEN = 283,
    BOOL_TOKEN = 284,
    FLOAT_TOKEN = 285,
    VOID_TOKEN = 286,
    STRUCT_TOKEN = 287,
    RETURN_TOKEN = 288,
    LEFT_BRACE = 289,
    RIGHT_BRACE = 290,
    LEFT_BRACKET = 291,
    RIGHT_BRACKET = 292,
    IF_TOKEN = 293,
    ELSE_TOKEN = 294,
    WHILE_TOKEN = 295,
    NULLPTR_TOKEN = 296,
    DEBUGOUT_TOKEN = 297,
    SIZEOF_TOKEN = 298,
    OFFSETPTR_TOKEN = 299,
    CASTPTR_TOKEN = 300,
    READPORT_TOKEN = 301,
    PACKBYTE_TOKEN = 302,
    DATASEGEND_TOKEN = 303,
    IDENTIFIER = 304
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 22 "PSL.y" /* yacc.c:1915  */

	int intVal;
    float floatVal;
	int symIndex;
    ASTNode* pNode;

#line 111 "PSL.tab.h" /* yacc.c:1915  */
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

#endif /* !YY_YY_PSL_TAB_H_INCLUDED  */
