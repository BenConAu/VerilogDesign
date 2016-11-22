/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SYMBOL_TOKEN = 258,
     REGISTER_TOKEN = 259,
     CONSTANT_TOKEN = 260,
     NONE_TOKEN = 261,
     OFFSET_TOKEN = 262,
     DEREF_TOKEN = 263,
     ADDRESSOF_TOKEN = 264,
     COLON_TOKEN = 265,
     RAM_TOKEN = 266,
     NOFLAGS_TOKEN = 267
   };
#endif
/* Tokens.  */
#define SYMBOL_TOKEN 258
#define REGISTER_TOKEN 259
#define CONSTANT_TOKEN 260
#define NONE_TOKEN 261
#define OFFSET_TOKEN 262
#define DEREF_TOKEN 263
#define ADDRESSOF_TOKEN 264
#define COLON_TOKEN 265
#define RAM_TOKEN 266
#define NOFLAGS_TOKEN 267




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "PACodeGen.y"
{
    int symIndex;
    int flags;
    OperandType opType;
    ISAOperand argType;
}
/* Line 1529 of yacc.c.  */
#line 80 "PACodeGen.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

