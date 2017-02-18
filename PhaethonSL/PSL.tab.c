/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "PSL.y" /* yacc.c:339  */

#define YYDEBUG 1

#include "PSLCompilerContext.h"
#include "ASTTree.h"
#include "PSL.tab.h"

#define YY_EXTRA_TYPE PSLCompilerContext*
#include "lex.h"

void yyerror(YYLTYPE*, void*, const char *s);

#define scanner pContext->pScanner


#line 82 "PSL.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "PSL.tab.h".  */
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
    EXECR_TOKEN = 300,
    EXIT_TOKEN = 301,
    MOVRC_TOKEN = 302,
    MOVRR_TOKEN = 303,
    EMIT_TOKEN = 304,
    SIZEOF_TOKEN = 305,
    OFFSETPTR_TOKEN = 306,
    CASTPTR_TOKEN = 307,
    READPORT_TOKEN = 308,
    WRITEPORT_TOKEN = 309,
    PACKBYTE_TOKEN = 310,
    DATASEGEND_TOKEN = 311,
    SAVEREG_TOKEN = 312,
    RSP_TOKEN = 313,
    IDENTIFIER = 314
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 22 "PSL.y" /* yacc.c:355  */

    int intVal;
    float floatVal;
    int symIndex;
    ASTNode* pNode;
    OpCode opCode;
    RegIndex regIndex;

#line 191 "PSL.tab.c" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */

#line 221 "PSL.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   273

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  227

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   314

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   142,   142,   143,   147,   148,   149,   153,   154,   158,
     159,   160,   161,   162,   163,   164,   165,   169,   173,   175,
     180,   181,   185,   189,   193,   194,   198,   199,   200,   204,
     205,   206,   210,   211,   212,   216,   217,   218,   222,   223,
     227,   228,   232,   236,   237,   238,   239,   240,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     259,   263,   268,   273,   278,   282,   286,   290,   291,   295,
     296,   300,   301,   305,   309,   310,   311,   312,   313,   314,
     315,   319,   324,   325,   329,   330,   335,   339,   343,   344,
     348,   352,   353,   357,   358,   362,   363,   367,   368,   370,
     374,   378,   382,   384,   386,   391,   395,   396,   397,   401,
     402,   406,   411
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTCONSTANT", "FLOATCONSTANT",
  "BOOLCONSTANT", "REG_INDEX", "AT", "SEMICOLON", "EQUAL", "STAR", "PLUS",
  "MINUS", "LEFT_PAREN", "RIGHT_PAREN", "LT", "GT", "LT_OP", "GT_OP",
  "SHIFTLEFT", "SHIFTRIGHT", "ARROW", "DOT", "COMMA", "AMPERSAND",
  "EQUAL_OP", "NOTEQUAL_OP", "PTR_TOKEN", "BYTE_TOKEN", "WORD_TOKEN",
  "BOOL_TOKEN", "FLOAT_TOKEN", "VOID_TOKEN", "STRUCT_TOKEN",
  "RETURN_TOKEN", "LEFT_BRACE", "RIGHT_BRACE", "LEFT_BRACKET",
  "RIGHT_BRACKET", "IF_TOKEN", "ELSE_TOKEN", "WHILE_TOKEN",
  "NULLPTR_TOKEN", "DOUTR_TOKEN", "DINR_TOKEN", "EXECR_TOKEN",
  "EXIT_TOKEN", "MOVRC_TOKEN", "MOVRR_TOKEN", "EMIT_TOKEN", "SIZEOF_TOKEN",
  "OFFSETPTR_TOKEN", "CASTPTR_TOKEN", "READPORT_TOKEN", "WRITEPORT_TOKEN",
  "PACKBYTE_TOKEN", "DATASEGEND_TOKEN", "SAVEREG_TOKEN", "RSP_TOKEN",
  "IDENTIFIER", "$accept", "translation_unit", "external_declaration",
  "statement_list", "statement", "expression_statement",
  "selection_statement", "selection_rest_statement", "savereg_statement",
  "expression", "assignment_expression", "equality_expression",
  "relational_expression", "shift_expression", "additive_expression",
  "multiplicative_expression", "unary_expression", "assignment_operator",
  "postfix_expression", "primary_expression", "sizeof_expression",
  "offset_expression", "cast_expression", "readport_expression",
  "declaration", "variable_identifier", "function_prototype",
  "function_declarator", "function_header_with_parameters",
  "function_header", "parameter_declaration", "fully_specified_type",
  "struct_specifier", "struct_declaration_list", "struct_declaration",
  "function_definition", "init_declarator_list", "single_declaration",
  "declaration_statement", "compound_statement", "function_call",
  "function_call_header_no_param", "function_call_header",
  "jump_statement", "return_statement", "emit_statement", "opcode0_token",
  "opcode1_token", "opcode2_token", "packbyte_statement",
  "writeport_statement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

#define YYPACT_NINF -89

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-89)))

#define YYTABLE_NINF -80

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      44,   -11,   -89,   -89,   -89,   -89,   -89,   -41,   -89,     3,
     -89,   -89,    11,    55,    72,   152,     8,    97,   -89,   114,
     -89,   152,    91,   -89,   -89,   136,   -89,   -89,   152,   -89,
      69,    29,   -89,   -89,   128,   152,   -89,   -89,   -89,   -89,
     103,    87,     5,   -89,   134,   137,   -89,   139,   144,   143,
     154,   158,   160,   161,   -89,    11,    -8,   193,   -89,   -89,
     -89,   -89,   141,   -89,    -1,    22,    65,    48,   166,   -89,
      28,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   135,   -89,
     -89,   186,    40,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
       5,   -89,   142,   -89,   145,    51,   -89,    53,     6,   -89,
     -89,   194,     5,     5,    70,   152,   152,   152,     5,     5,
       5,   -89,     5,   152,   -89,   -89,   -89,     5,     5,     5,
       5,     5,     5,     5,     5,     5,   -89,   147,   148,     5,
       5,   199,   -89,   -89,     5,   -89,   187,    15,   -89,   -89,
     -89,   195,   196,   -89,   -89,   -89,   -89,   -89,   -89,   198,
     190,   191,   201,   200,   202,   205,   203,   207,   -89,   212,
      22,     6,    22,    65,    65,    48,    48,   166,   166,   -89,
     -89,   -89,   213,    -1,   -89,   218,   -89,   230,    11,    11,
     228,     5,     5,   -89,   224,   225,   -89,     5,     5,   226,
     -89,   -89,   215,   -89,   214,   -89,   -89,   227,   217,     5,
       5,   241,   233,     5,   249,    11,   250,     5,   236,   246,
     253,     5,   -89,   -89,   -89,   -89,   248,     5,   -89,   -89,
     251,   255,   252,   256,   -89,   -89,   -89
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    75,    74,    78,    76,    77,     0,    79,     0,
       2,     6,     0,     0,    68,    67,     0,     0,     4,     0,
      87,     0,     0,     1,     3,     0,    86,    66,     0,    69,
       0,    88,     5,    64,     0,     0,    50,    52,    51,    59,
       0,     0,     0,    91,     0,     0,    53,     0,     0,     0,
       0,     0,     0,     0,    54,     0,    65,     0,     7,     9,
      10,    16,     0,    23,    24,    26,    29,    32,    35,    38,
      40,    43,    55,    56,    57,    58,    90,    48,     0,    11,
      45,     0,     0,    12,   100,    13,    14,    15,    70,    73,
       0,    71,     0,    80,     0,     0,    82,    65,    41,    65,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,    95,     0,    92,     8,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
       0,    88,    94,    93,     0,    89,     0,     0,    81,    83,
     101,     0,     0,   106,   107,   108,   105,   109,   110,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,     0,
      27,    40,    28,    30,    31,    33,    34,    36,    37,    39,
      47,    46,     0,    25,    99,     0,    84,     0,     0,     0,
       0,     0,     0,    60,     0,     0,    63,     0,     0,     0,
      44,    72,     0,    18,    21,    19,   102,     0,     0,     0,
       0,     0,     0,    96,     0,     0,     0,     0,     0,     0,
       0,     0,    98,    85,    20,   103,     0,     0,    62,   112,
       0,     0,     0,     0,   104,    61,   111
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -89,   -89,   258,   -89,   211,   -89,   -89,   -89,   -89,   -88,
     -42,   140,   -29,   -18,   -31,    -3,   146,   -89,    13,   -89,
     -89,   -89,   -89,   -89,   -12,   231,   -89,   -89,   -89,   -89,
     245,    -9,   -89,   -89,   174,   -89,   -89,   -89,   -89,   -54,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    57,    58,    59,    60,   193,    61,    62,
      63,    64,    65,    66,    67,    68,    69,   130,    70,    71,
      72,    73,    74,    75,    11,    77,    12,    13,    14,    15,
      29,    16,    17,    95,    96,    18,    19,    20,    79,    26,
      80,    81,    82,    83,    84,    85,   149,   150,   151,    86,
      87
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     101,   111,   135,    23,    21,   112,    30,   113,    36,    37,
      38,    39,    34,    76,   141,   142,    78,    40,    22,    30,
     155,   156,   157,   176,   117,   118,    94,   127,   128,    41,
       1,     2,     3,     4,     5,     6,     7,   126,    90,   119,
     120,   172,    91,   129,    92,    76,    25,    46,    78,   127,
     128,   -79,   177,    98,   133,    48,    49,    50,    51,   123,
     124,    54,     8,   134,    97,   129,   112,    31,   113,    27,
     158,     1,     2,     3,     4,     5,     6,     7,     1,     2,
       3,     4,     5,     6,   121,   122,    94,   138,   160,   162,
     165,   166,   174,   197,   198,    28,   152,   153,   154,   201,
     202,   163,   164,     8,   159,    32,    36,    37,    38,    39,
       8,   208,   209,   143,   144,   145,   146,   147,   148,   216,
     167,   168,    33,   220,   194,   195,    35,    41,    89,   222,
     161,   161,   161,   161,   161,   161,   161,   161,   161,    36,
      37,    38,    39,   161,    93,    46,    99,   102,    40,   116,
     103,   214,   104,    48,    49,    50,    51,   105,   106,    54,
      41,   212,    97,     1,     2,     3,     4,     5,     6,   107,
      42,   108,    43,   109,   110,    44,   125,    45,    46,     1,
       2,     3,     4,     5,     6,    47,    48,    49,    50,    51,
      52,    53,    54,    55,   131,    56,    36,    37,    38,    39,
     132,   136,   140,   175,   137,    40,   170,   171,    90,   178,
     179,     8,   180,   181,   182,   183,   184,    41,   185,   186,
       1,     2,     3,     4,     5,     6,   187,    42,   189,   114,
     188,   191,    44,   192,    45,    46,   196,   199,   200,   203,
     207,   206,    47,    48,    49,    50,    51,    52,    53,    54,
      55,   190,    56,   204,   205,   210,   211,   213,   215,   217,
     218,   219,   221,   224,   226,   223,   225,    24,   115,   139,
     173,   169,   100,    88
};

static const yytype_uint8 yycheck[] =
{
      42,    55,    90,     0,    15,    13,    15,    15,     3,     4,
       5,     6,    21,    25,   102,   103,    25,    12,    59,    28,
     108,   109,   110,     8,    25,    26,    35,    21,    22,    24,
      27,    28,    29,    30,    31,    32,    33,     9,     9,    17,
      18,   129,    13,    37,    15,    57,    35,    42,    57,    21,
      22,    59,    37,    40,    14,    50,    51,    52,    53,    11,
      12,    56,    59,    23,    59,    37,    13,    59,    15,    14,
     112,    27,    28,    29,    30,    31,    32,    33,    27,    28,
      29,    30,    31,    32,    19,    20,    95,    36,   117,   118,
     121,   122,   134,   181,   182,    23,   105,   106,   107,   187,
     188,   119,   120,    59,   113,     8,     3,     4,     5,     6,
      59,   199,   200,    43,    44,    45,    46,    47,    48,   207,
     123,   124,     8,   211,   178,   179,    35,    24,    59,   217,
     117,   118,   119,   120,   121,   122,   123,   124,   125,     3,
       4,     5,     6,   130,    16,    42,    59,    13,    12,     8,
      13,   205,    13,    50,    51,    52,    53,    13,    15,    56,
      24,   203,    59,    27,    28,    29,    30,    31,    32,    15,
      34,    13,    36,    13,    13,    39,    10,    41,    42,    27,
      28,    29,    30,    31,    32,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    59,    59,     3,     4,     5,     6,
      14,    59,     8,    16,    59,    12,    59,    59,     9,    14,
      14,    59,    14,    23,    23,    14,    16,    24,    16,    14,
      27,    28,    29,    30,    31,    32,    23,    34,    16,    36,
      23,    13,    39,     3,    41,    42,     8,    13,    13,    13,
      23,    14,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    38,    59,    38,    40,    14,    23,     8,     8,    23,
      14,     8,    14,     8,     8,    14,    14,     9,    57,    95,
     130,   125,    41,    28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    27,    28,    29,    30,    31,    32,    33,    59,    61,
      62,    84,    86,    87,    88,    89,    91,    92,    95,    96,
      97,    15,    59,     0,    62,    35,    99,    14,    23,    90,
      91,    59,     8,     8,    91,    35,     3,     4,     5,     6,
      12,    24,    34,    36,    39,    41,    42,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    59,    63,    64,    65,
      66,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      78,    79,    80,    81,    82,    83,    84,    85,    91,    98,
     100,   101,   102,   103,   104,   105,   109,   110,    90,    59,
       9,    13,    15,    16,    91,    93,    94,    59,    78,    59,
      85,    70,    13,    13,    13,    13,    15,    15,    13,    13,
      13,    99,    13,    15,    36,    64,     8,    25,    26,    17,
      18,    19,    20,    11,    12,    10,     9,    21,    22,    37,
      77,    59,    14,    14,    23,    69,    59,    59,    36,    94,
       8,    69,    69,    43,    44,    45,    46,    47,    48,   106,
     107,   108,    91,    91,    91,    69,    69,    69,    70,    91,
      72,    78,    72,    73,    73,    74,    74,    75,    75,    76,
      59,    59,    69,    71,    70,    16,     8,    37,    14,    14,
      14,    23,    23,    14,    16,    16,    14,    23,    23,    16,
      38,    13,     3,    67,    99,    99,     8,    69,    69,    13,
      13,    69,    69,    13,    38,    40,    14,    23,    69,    69,
      14,    23,    70,     8,    99,     8,    69,    23,    14,     8,
      69,    14,    69,    14,     8,    14,     8
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    61,    62,    62,    62,    63,    63,    64,
      64,    64,    64,    64,    64,    64,    64,    65,    66,    66,
      67,    67,    68,    69,    70,    70,    71,    71,    71,    72,
      72,    72,    73,    73,    73,    74,    74,    74,    75,    75,
      76,    76,    77,    78,    78,    78,    78,    78,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    87,    88,
      88,    89,    89,    90,    91,    91,    91,    91,    91,    91,
      91,    92,    93,    93,    94,    94,    95,    96,    97,    97,
      98,    99,    99,   100,   100,   101,   101,   102,   102,   102,
     103,   104,   105,   105,   105,   106,   107,   107,   107,   108,
     108,   109,   110
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     5,     5,
       3,     1,     2,     1,     1,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       1,     2,     1,     1,     4,     1,     3,     3,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     9,     7,     4,     2,     1,     2,     1,     1,     2,
       3,     3,     6,     2,     1,     1,     1,     1,     1,     1,
       4,     5,     1,     2,     3,     6,     2,     1,     2,     4,
       1,     2,     3,     2,     2,     2,     5,     3,     6,     3,
       1,     3,     5,     7,     9,     1,     1,     1,     1,     1,
       1,     9,     7
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (&yylloc, pContext, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, pContext); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, PSLCompilerContext* pContext)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (pContext);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, PSLCompilerContext* pContext)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, pContext);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, PSLCompilerContext* pContext)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , pContext);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, pContext); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, PSLCompilerContext* pContext)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (pContext);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (PSLCompilerContext* pContext)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, &yylloc, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
#line 147 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddFuncDef((yyval.pNode)); }
#line 1591 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 5:
#line 148 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); pContext->AddStructDef((yyval.pNode)); }
#line 1597 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 6:
#line 149 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddGlobal((yyval.pNode)); }
#line 1603 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 153 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StatementListNode(pContext, (yyvsp[0].pNode)); }
#line 1609 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 8:
#line 154 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 1615 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 158 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1621 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 159 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1627 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 160 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1633 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 161 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1639 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 162 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1645 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 163 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1651 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 15:
#line 164 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1657 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 165 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1663 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 169 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 1669 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 174 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); dynamic_cast<IfStatementNode*>((yyval.pNode))->SetStatementList((yyvsp[-2].pNode)); }
#line 1675 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 176 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new WhileStatementNode(pContext, (yyvsp[-2].pNode), (yyvsp[0].pNode)); }
#line 1681 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 180 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IfStatementNode(pContext, (yyvsp[-2].pNode), (yyvsp[0].pNode)); }
#line 1687 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 181 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IfStatementNode(pContext, (yyvsp[0].pNode), nullptr); }
#line 1693 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 185 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new SaveRegistersNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 1699 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 189 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1705 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 193 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1711 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 194 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new AssignmentNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode)); }
#line 1717 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 198 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1723 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 199 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Equal); }
#line 1729 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 200 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::NotEqual); }
#line 1735 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 204 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1741 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 205 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LessThan); }
#line 1747 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 206 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::GreaterThan); }
#line 1753 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 210 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1759 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 211 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::ShiftLeft); }
#line 1765 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 212 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::ShiftRight); }
#line 1771 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 216 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1777 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 217 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Add); }
#line 1783 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 218 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Subtract); }
#line 1789 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 222 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1795 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 223 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Multiply); }
#line 1801 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 40:
#line 227 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1807 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 41:
#line 228 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new UnaryOperatorNode(pContext, (yyvsp[0].pNode), Operator::Negate); }
#line 1813 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 236 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1819 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 44:
#line 237 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IndexSelectionNode(pContext, (yyloc), (yyvsp[-3].pNode), (yyvsp[-1].pNode)); }
#line 1825 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 238 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1831 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 239 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FieldSelectionNode(pContext, (yyloc), (yyvsp[-2].pNode), false, (yyvsp[0].symIndex)); }
#line 1837 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 240 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FieldSelectionNode(pContext, (yyloc), (yyvsp[-2].pNode), true, (yyvsp[0].symIndex)); }
#line 1843 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 48:
#line 244 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1849 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 245 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new AddressOfNode(pContext, (yyvsp[0].pNode)); }
#line 1855 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 246 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, ConstantNode::Word, (yyvsp[0].intVal)); }
#line 1861 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 247 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, ConstantNode::Bool, (yyvsp[0].intVal)); }
#line 1867 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 52:
#line 248 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, (yyvsp[0].floatVal)); }
#line 1873 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 249 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, ConstantNode::Pointer); }
#line 1879 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 54:
#line 250 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new KnownConstantNode(pContext, KnownConstants::DataSegmentEnd); }
#line 1885 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 251 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1891 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 56:
#line 252 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1897 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 253 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1903 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 254 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1909 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 255 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new RegisterNode(pContext, (yyloc), (yyvsp[0].regIndex)); }
#line 1915 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 259 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new SizeOfNode(pContext, (yyvsp[-1].pNode)); }
#line 1921 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 264 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OffsetNode(pContext, (yyloc), (yyvsp[-6].pNode), (yyvsp[-3].pNode), (yyvsp[-1].pNode)); }
#line 1927 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 269 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new CastNode(pContext, (yyloc), (yyvsp[-4].pNode), (yyvsp[-1].pNode)); }
#line 1933 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 274 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ReadPortNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 1939 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 278 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 1945 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 282 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IdentifierNode(pContext, (yyloc), (yyvsp[0].symIndex)); }
#line 1951 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 286 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 1957 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 290 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1963 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 291 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1969 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 295 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 1975 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 296 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 1981 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 300 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionDeclaratorNode(pContext, (yyvsp[-2].pNode), (yyvsp[-1].symIndex), -1); }
#line 1987 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 301 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionDeclaratorNode(pContext, (yyvsp[-5].pNode), (yyvsp[-4].symIndex), (yyvsp[-2].symIndex)); }
#line 1993 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 305 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionParameterNode(pContext, (yyvsp[-1].pNode), (yyvsp[0].symIndex)); }
#line 1999 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 309 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Basic, WORD_TOKEN); }
#line 2005 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 310 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Basic, BYTE_TOKEN); }
#line 2011 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 311 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Basic, FLOAT_TOKEN); }
#line 2017 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 312 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Basic, VOID_TOKEN); }
#line 2023 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 313 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Basic, BOOL_TOKEN); }
#line 2029 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 79:
#line 314 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Struct, (yyvsp[0].symIndex)); }
#line 2035 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 80:
#line 315 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2041 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 81:
#line 319 "PSL.y" /* yacc.c:1661  */
    {
	                                    							  (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<StructSpecifierNode*>((yyval.pNode))->SetName((yyvsp[-3].symIndex)); }
#line 2048 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 82:
#line 324 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructSpecifierNode(pContext, (yyvsp[0].pNode)); }
#line 2054 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 83:
#line 325 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2060 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 84:
#line 329 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructDeclarationNode(pContext, (yyvsp[-2].pNode), (yyvsp[-1].symIndex), -1); }
#line 2066 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 85:
#line 331 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructDeclarationNode(pContext, (yyvsp[-5].pNode), (yyvsp[-4].symIndex), (yyvsp[-2].intVal)); }
#line 2072 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 86:
#line 335 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->SetStatementList((yyvsp[0].pNode)); }
#line 2078 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 87:
#line 339 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2084 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 88:
#line 343 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new VariableDeclarationNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), nullptr); }
#line 2090 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 89:
#line 344 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new VariableDeclarationNode(pContext, (yyloc), (yyvsp[-3].pNode), (yyvsp[-2].symIndex), (yyvsp[0].pNode)); }
#line 2096 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 90:
#line 348 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2102 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 91:
#line 352 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StatementListNode(pContext, nullptr); }
#line 2108 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 92:
#line 353 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2114 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 93:
#line 357 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2120 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 94:
#line 358 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2126 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 95:
#line 362 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-1].symIndex), nullptr, nullptr); }
#line 2132 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 96:
#line 363 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-4].symIndex), (yyvsp[-2].pNode), nullptr); }
#line 2138 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 97:
#line 367 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-2].symIndex), nullptr, (yyvsp[0].pNode)); }
#line 2144 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 98:
#line 369 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-5].symIndex), (yyvsp[-3].pNode), (yyvsp[0].pNode)); }
#line 2150 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 99:
#line 370 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2156 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 100:
#line 374 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2162 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 101:
#line 378 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ReturnNode(pContext, (yyvsp[-1].pNode)); }
#line 2168 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 102:
#line 383 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new EmitNode(pContext, (yyloc), (yyvsp[-2].opCode), nullptr, nullptr); }
#line 2174 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 103:
#line 385 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new EmitNode(pContext, (yyloc), (yyvsp[-4].opCode), (yyvsp[-2].pNode), nullptr); }
#line 2180 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 104:
#line 387 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new EmitNode(pContext, (yyloc), (yyvsp[-6].opCode), (yyvsp[-4].pNode), (yyvsp[-2].pNode)); }
#line 2186 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 105:
#line 391 "PSL.y" /* yacc.c:1661  */
    { (yyval.opCode) = OpCode::Exit; }
#line 2192 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 106:
#line 395 "PSL.y" /* yacc.c:1661  */
    { (yyval.opCode) = OpCode::DoutR; }
#line 2198 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 107:
#line 396 "PSL.y" /* yacc.c:1661  */
    { (yyval.opCode) = OpCode::DinR; }
#line 2204 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 108:
#line 397 "PSL.y" /* yacc.c:1661  */
    { (yyval.opCode) = OpCode::ExecR; }
#line 2210 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 109:
#line 401 "PSL.y" /* yacc.c:1661  */
    { (yyval.opCode) = OpCode::MovRC; }
#line 2216 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 110:
#line 402 "PSL.y" /* yacc.c:1661  */
    { (yyval.opCode) = OpCode::MovRR; }
#line 2222 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 111:
#line 407 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new PackByteNode(pContext, (yyloc), (yyvsp[-6].pNode), (yyvsp[-4].pNode), (yyvsp[-2].pNode)); }
#line 2228 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 112:
#line 412 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new WritePortNode(pContext, (yyloc), (yyvsp[-4].pNode), (yyvsp[-2].pNode)); }
#line 2234 "PSL.tab.c" /* yacc.c:1661  */
    break;


#line 2238 "PSL.tab.c" /* yacc.c:1661  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, pContext, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (&yylloc, pContext, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, pContext);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, pContext);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, pContext, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, pContext);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, pContext);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 415 "PSL.y" /* yacc.c:1906  */

