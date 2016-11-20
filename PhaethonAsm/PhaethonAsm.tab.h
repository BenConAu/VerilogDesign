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
     INT_TOKEN = 258,
     INSTR_TOKEN_0 = 259,
     INSTR_TOKEN_1 = 260,
     INSTR_TOKEN_2 = 261,
     INSTR_TOKEN_3 = 262,
     REG_TOKEN = 263,
     COMMA_TOKEN = 264,
     ADDR_LEFT = 265,
     ADDR_RIGHT = 266,
     COLON_TOKEN = 267,
     STRUCT_TOKEN = 268,
     ENDS_TOKEN = 269,
     DATASEGMENT_TOKEN = 270,
     ENDDATA_TOKEN = 271,
     LEFT_PAREN_TOKEN = 272,
     RIGHT_PAREN_TOKEN = 273,
     MEMBEROF_TOKEN = 274,
     DEREF_TOKEN = 275,
     ADDRESSOF_TOKEN = 276,
     AT_TOKEN = 277,
     SIZEOF_TOKEN = 278,
     SYMBOL_TOKEN = 279
   };
#endif
/* Tokens.  */
#define INT_TOKEN 258
#define INSTR_TOKEN_0 259
#define INSTR_TOKEN_1 260
#define INSTR_TOKEN_2 261
#define INSTR_TOKEN_3 262
#define REG_TOKEN 263
#define COMMA_TOKEN 264
#define ADDR_LEFT 265
#define ADDR_RIGHT 266
#define COLON_TOKEN 267
#define STRUCT_TOKEN 268
#define ENDS_TOKEN 269
#define DATASEGMENT_TOKEN 270
#define ENDDATA_TOKEN 271
#define LEFT_PAREN_TOKEN 272
#define RIGHT_PAREN_TOKEN 273
#define MEMBEROF_TOKEN 274
#define DEREF_TOKEN 275
#define ADDRESSOF_TOKEN 276
#define AT_TOKEN 277
#define SIZEOF_TOKEN 278
#define SYMBOL_TOKEN 279




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 21 "PhaethonAsm.y"
{
	int intVal;
	float floatVal;
	Instructions::Enum instrIndex;
	int regIndex;
	int symIndex;
	Argument arg;
	StructDef* structDef;
	StructMember* structMember;
	DataSegmentDef* dataSegmentDef;
	DataSegmentItemDef* dataSegmentItemDef;
	DataSegmentItemEntry* dataSegmentItemEntry;
	InstructionNode* instructonNode;
}
/* Line 1529 of yacc.c.  */
#line 112 "PhaethonAsm.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE yylloc;
