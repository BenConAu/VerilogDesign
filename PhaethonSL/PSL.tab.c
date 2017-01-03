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
    WORD_TOKEN = 282,
    BOOL_TOKEN = 283,
    FLOAT_TOKEN = 284,
    VOID_TOKEN = 285,
    STRUCT_TOKEN = 286,
    RETURN_TOKEN = 287,
    LEFT_BRACE = 288,
    RIGHT_BRACE = 289,
    LEFT_BRACKET = 290,
    RIGHT_BRACKET = 291,
    IF_TOKEN = 292,
    ELSE_TOKEN = 293,
    WHILE_TOKEN = 294,
    NULLPTR_TOKEN = 295,
    DEBUGOUT_TOKEN = 296,
    SIZEOF_TOKEN = 297,
    OFFSETPTR_TOKEN = 298,
    CASTPTR_TOKEN = 299,
    DATASEGEND_TOKEN = 300,
    IDENTIFIER = 301
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

#line 176 "PSL.tab.c" /* yacc.c:355  */
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

#line 206 "PSL.tab.c" /* yacc.c:358  */

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
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   225

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  181

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

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
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   120,   120,   121,   125,   126,   127,   131,   132,   136,
     137,   138,   139,   140,   144,   148,   150,   155,   156,   160,
     164,   165,   169,   170,   171,   175,   176,   177,   181,   182,
     183,   187,   188,   189,   193,   194,   198,   199,   203,   207,
     208,   209,   210,   211,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   228,   232,   237,   242,   246,   250,
     254,   255,   259,   260,   264,   265,   269,   273,   274,   275,
     276,   277,   278,   282,   287,   288,   292,   293,   298,   302,
     306,   307,   311,   315,   316,   320,   321,   325,   326,   330,
     331,   333,   337,   341,   345
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTCONSTANT", "FLOATCONSTANT",
  "BOOLCONSTANT", "AT", "SEMICOLON", "EQUAL", "STAR", "PLUS", "MINUS",
  "LEFT_PAREN", "RIGHT_PAREN", "LT", "GT", "LT_OP", "GT_OP", "SHIFTLEFT",
  "SHIFTRIGHT", "ARROW", "DOT", "COMMA", "AMPERSAND", "EQUAL_OP",
  "NOTEQUAL_OP", "PTR_TOKEN", "WORD_TOKEN", "BOOL_TOKEN", "FLOAT_TOKEN",
  "VOID_TOKEN", "STRUCT_TOKEN", "RETURN_TOKEN", "LEFT_BRACE",
  "RIGHT_BRACE", "LEFT_BRACKET", "RIGHT_BRACKET", "IF_TOKEN", "ELSE_TOKEN",
  "WHILE_TOKEN", "NULLPTR_TOKEN", "DEBUGOUT_TOKEN", "SIZEOF_TOKEN",
  "OFFSETPTR_TOKEN", "CASTPTR_TOKEN", "DATASEGEND_TOKEN", "IDENTIFIER",
  "$accept", "translation_unit", "external_declaration", "statement_list",
  "statement", "expression_statement", "selection_statement",
  "selection_rest_statement", "expression", "assignment_expression",
  "equality_expression", "relational_expression", "shift_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "assignment_operator", "postfix_expression", "primary_expression",
  "sizeof_expression", "offset_expression", "cast_expression",
  "declaration", "variable_identifier", "function_prototype",
  "function_declarator", "function_header_with_parameters",
  "function_header", "parameter_declaration", "fully_specified_type",
  "struct_specifier", "struct_declaration_list", "struct_declaration",
  "function_definition", "init_declarator_list", "single_declaration",
  "declaration_statement", "compound_statement", "function_call",
  "function_call_header_no_param", "function_call_header",
  "jump_statement", "return_statement", "debugout_statement", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF -137

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-137)))

#define YYTABLE_NINF -72

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      92,    14,  -137,  -137,  -137,  -137,   -22,  -137,    16,  -137,
    -137,    44,    73,    70,   170,    65,   108,  -137,   110,  -137,
     170,    91,  -137,  -137,   105,  -137,  -137,   170,  -137,    79,
      49,  -137,  -137,   111,   170,  -137,  -137,  -137,    51,    81,
      26,  -137,   118,   124,  -137,   128,   129,   141,   142,  -137,
      -8,   149,  -137,  -137,  -137,   150,  -137,    35,     3,    46,
      40,   134,  -137,    32,  -137,  -137,  -137,  -137,  -137,  -137,
     112,  -137,  -137,   146,    10,  -137,  -137,  -137,  -137,  -137,
      26,  -137,   115,  -137,   121,   136,  -137,    -5,     6,  -137,
    -137,   161,    26,    26,    51,   170,   170,   170,    26,   170,
    -137,  -137,  -137,    26,    26,    26,    26,    26,    26,    26,
      26,    26,  -137,   123,   125,    26,    26,   165,  -137,  -137,
      26,  -137,   159,    -2,  -137,  -137,  -137,   167,   171,   -10,
     172,   186,   187,  -137,   188,     3,     6,     3,    46,    46,
      40,    40,   134,   134,  -137,  -137,  -137,   151,    35,  -137,
     192,  -137,   202,    44,    44,   199,  -137,   195,   196,   197,
    -137,  -137,   174,  -137,   173,  -137,  -137,    26,    26,    26,
     205,    44,   191,   201,  -137,  -137,  -137,    26,  -137,   204,
    -137
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    67,    70,    68,    69,     0,    71,     0,     2,
       6,     0,     0,    61,    60,     0,     0,     4,     0,    79,
       0,     0,     1,     3,     0,    78,    59,     0,    62,     0,
      80,     5,    57,     0,     0,    46,    48,    47,     0,     0,
       0,    83,     0,     0,    49,     0,     0,     0,     0,    50,
      58,     0,     7,     9,    10,     0,    19,    20,    22,    25,
      28,    31,    34,    36,    39,    51,    52,    53,    82,    44,
       0,    11,    41,     0,     0,    12,    92,    13,    63,    66,
       0,    64,     0,    72,     0,     0,    74,    58,    37,    58,
      45,     0,     0,     0,     0,     0,     0,     0,    87,     0,
      84,     8,    14,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,     0,     0,    80,    86,    85,
       0,    81,     0,     0,    73,    75,    93,     0,     0,     0,
       0,     0,     0,    89,     0,    23,    36,    24,    26,    27,
      29,    30,    32,    33,    35,    43,    42,     0,    21,    91,
       0,    76,     0,     0,     0,     0,    54,     0,     0,     0,
      40,    65,     0,    15,    18,    16,    94,     0,     0,    88,
       0,     0,     0,     0,    90,    77,    17,     0,    56,     0,
      55
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -137,  -137,   207,  -137,   168,  -137,  -137,  -137,   -79,   -40,
     102,   -28,   -27,   -26,     4,   109,  -137,    -4,  -137,  -137,
    -137,  -137,    -3,   182,  -137,  -137,  -137,  -137,   198,   -12,
    -137,  -137,   137,  -137,  -137,  -137,  -137,  -136,  -137,  -137,
    -137,  -137,  -137,  -137
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,     9,    51,    52,    53,    54,   163,    55,    56,
      57,    58,    59,    60,    61,    62,   116,    63,    64,    65,
      66,    67,    10,    69,    11,    12,    13,    14,    28,    15,
      16,    85,    86,    17,    18,    19,    71,    25,    72,    73,
      74,    75,    76,    77
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      91,   121,    29,   155,    98,   151,    99,    98,    33,    99,
     113,   114,    70,   127,   128,    29,    22,   164,   165,   105,
     106,    68,    84,   119,    21,   115,   113,   114,    20,    35,
      36,    37,   120,   152,    88,   176,   147,    38,   -71,    70,
     112,   115,     1,     2,     3,     4,     5,     6,    68,    39,
     109,   110,   113,   114,    35,    36,    37,    80,   133,   103,
     104,    81,     7,    82,   107,   108,    44,   115,    46,    47,
      48,    49,    87,    84,    39,   135,   137,    24,   138,   139,
     149,   140,   141,   130,   131,   132,    26,   134,   172,   173,
     129,    44,    27,    46,    47,    48,    49,    87,   179,   136,
     136,   136,   136,   136,   136,   136,   136,   136,    35,    36,
      37,    30,   136,   142,   143,    31,    38,    32,     1,     2,
       3,     4,     5,     6,    34,    79,    83,    89,    39,   174,
      92,     1,     2,     3,     4,     5,    93,    40,     7,    41,
      94,    95,    42,   111,    43,    44,    45,    46,    47,    48,
      49,    50,    35,    36,    37,    96,    97,   102,   117,   118,
      38,   122,     1,     2,     3,     4,     5,   123,   126,   145,
     124,   146,    39,    80,   150,     1,     2,     3,     4,     5,
     153,    40,     7,   100,   154,   156,    42,   160,    43,    44,
      45,    46,    47,    48,    49,    50,     1,     2,     3,     4,
       5,   157,   158,   159,   161,   162,   166,   167,   168,   169,
     170,   171,   175,   177,   178,    23,     7,   180,   148,   101,
     144,    90,   125,     0,     0,    78
};

static const yytype_int16 yycheck[] =
{
      40,    80,    14,    13,    12,     7,    14,    12,    20,    14,
      20,    21,    24,    92,    93,    27,     0,   153,   154,    16,
      17,    24,    34,    13,    46,    35,    20,    21,    14,     3,
       4,     5,    22,    35,    38,   171,   115,    11,    46,    51,
       8,    35,    26,    27,    28,    29,    30,    31,    51,    23,
      10,    11,    20,    21,     3,     4,     5,     8,    98,    24,
      25,    12,    46,    14,    18,    19,    40,    35,    42,    43,
      44,    45,    46,    85,    23,   103,   104,    33,   105,   106,
     120,   107,   108,    95,    96,    97,    13,    99,   167,   168,
      94,    40,    22,    42,    43,    44,    45,    46,   177,   103,
     104,   105,   106,   107,   108,   109,   110,   111,     3,     4,
       5,    46,   116,   109,   110,     7,    11,     7,    26,    27,
      28,    29,    30,    31,    33,    46,    15,    46,    23,   169,
      12,    26,    27,    28,    29,    30,    12,    32,    46,    34,
      12,    12,    37,     9,    39,    40,    41,    42,    43,    44,
      45,    46,     3,     4,     5,    14,    14,     7,    46,    13,
      11,    46,    26,    27,    28,    29,    30,    46,     7,    46,
      34,    46,    23,     8,    15,    26,    27,    28,    29,    30,
      13,    32,    46,    34,    13,    13,    37,    36,    39,    40,
      41,    42,    43,    44,    45,    46,    26,    27,    28,    29,
      30,    15,    15,    15,    12,     3,     7,    12,    12,    12,
      36,    38,     7,    22,    13,     8,    46,    13,   116,    51,
     111,    39,    85,    -1,    -1,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    26,    27,    28,    29,    30,    31,    46,    48,    49,
      69,    71,    72,    73,    74,    76,    77,    80,    81,    82,
      14,    46,     0,    49,    33,    84,    13,    22,    75,    76,
      46,     7,     7,    76,    33,     3,     4,     5,    11,    23,
      32,    34,    37,    39,    40,    41,    42,    43,    44,    45,
      46,    50,    51,    52,    53,    55,    56,    57,    58,    59,
      60,    61,    62,    64,    65,    66,    67,    68,    69,    70,
      76,    83,    85,    86,    87,    88,    89,    90,    75,    46,
       8,    12,    14,    15,    76,    78,    79,    46,    64,    46,
      70,    56,    12,    12,    12,    12,    14,    14,    12,    14,
      34,    51,     7,    24,    25,    16,    17,    18,    19,    10,
      11,     9,     8,    20,    21,    35,    63,    46,    13,    13,
      22,    55,    46,    46,    34,    79,     7,    55,    55,    64,
      76,    76,    76,    56,    76,    58,    64,    58,    59,    59,
      60,    60,    61,    61,    62,    46,    46,    55,    57,    56,
      15,     7,    35,    13,    13,    13,    13,    15,    15,    15,
      36,    12,     3,    54,    84,    84,     7,    12,    12,    12,
      36,    38,    55,    55,    56,     7,    84,    22,    13,    55,
      13
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    49,    49,    49,    50,    50,    51,
      51,    51,    51,    51,    52,    53,    53,    54,    54,    55,
      56,    56,    57,    57,    57,    58,    58,    58,    59,    59,
      59,    60,    60,    60,    61,    61,    62,    62,    63,    64,
      64,    64,    64,    64,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    66,    67,    68,    69,    70,    71,
      72,    72,    73,    73,    74,    74,    75,    76,    76,    76,
      76,    76,    76,    77,    78,    78,    79,    79,    80,    81,
      82,    82,    83,    84,    84,    85,    85,    86,    86,    87,
      87,    87,    88,    89,    90
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     2,     1,
       1,     1,     1,     1,     2,     5,     5,     3,     1,     1,
       1,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     1,     2,     1,     1,
       4,     1,     3,     3,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     9,     7,     2,     1,     2,
       1,     1,     2,     3,     3,     6,     2,     1,     1,     1,
       1,     1,     4,     5,     1,     2,     3,     6,     2,     1,
       2,     4,     1,     2,     3,     2,     2,     2,     5,     3,
       6,     3,     1,     3,     5
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
#line 125 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddFuncDef((yyval.pNode)); }
#line 1538 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 5:
#line 126 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); pContext->AddStructDef((yyval.pNode)); }
#line 1544 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 6:
#line 127 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddGlobal((yyval.pNode)); }
#line 1550 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 131 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StatementListNode(pContext, (yyvsp[0].pNode)); }
#line 1556 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 8:
#line 132 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 1562 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 136 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1568 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 137 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1574 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 138 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1580 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 139 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1586 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 140 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1592 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 144 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 1598 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 15:
#line 149 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); dynamic_cast<IfStatementNode*>((yyval.pNode))->SetStatementList((yyvsp[-2].pNode)); }
#line 1604 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 151 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new WhileStatementNode(pContext, (yyvsp[-2].pNode), (yyvsp[0].pNode)); }
#line 1610 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 155 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IfStatementNode(pContext, (yyvsp[-2].pNode), (yyvsp[0].pNode)); }
#line 1616 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 156 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IfStatementNode(pContext, (yyvsp[0].pNode), nullptr); }
#line 1622 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 160 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1628 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 164 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1634 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 165 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new AssignmentNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode)); }
#line 1640 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 169 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1646 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 170 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Equal); }
#line 1652 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 171 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::NotEqual); }
#line 1658 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 175 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1664 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 176 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LessThan); }
#line 1670 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 177 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::GreaterThan); }
#line 1676 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 181 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1682 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 182 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::ShiftLeft); }
#line 1688 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 183 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::ShiftRight); }
#line 1694 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 187 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1700 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 188 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Add); }
#line 1706 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 189 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Subtract); }
#line 1712 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 193 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1718 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 194 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Multiply); }
#line 1724 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 198 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1730 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 199 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new UnaryOperatorNode(pContext, (yyvsp[0].pNode), Operator::Negate); }
#line 1736 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 207 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1742 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 40:
#line 208 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IndexSelectionNode(pContext, (yyloc), (yyvsp[-3].pNode), (yyvsp[-1].pNode)); }
#line 1748 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 41:
#line 209 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1754 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 42:
#line 210 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FieldSelectionNode(pContext, (yyloc), (yyvsp[-2].pNode), false, (yyvsp[0].symIndex)); }
#line 1760 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 211 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FieldSelectionNode(pContext, (yyloc), (yyvsp[-2].pNode), true, (yyvsp[0].symIndex)); }
#line 1766 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 44:
#line 215 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1772 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 216 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new AddressOfNode(pContext, (yyvsp[0].pNode)); }
#line 1778 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 217 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, ConstantNode::Word, (yyvsp[0].intVal)); }
#line 1784 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 218 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, ConstantNode::Bool, (yyvsp[0].intVal)); }
#line 1790 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 48:
#line 219 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, (yyvsp[0].floatVal)); }
#line 1796 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 220 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, ConstantNode::Pointer); }
#line 1802 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 221 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new KnownConstantNode(pContext, KnownConstants::DataSegmentEnd); }
#line 1808 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 222 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1814 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 52:
#line 223 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1820 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 224 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1826 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 54:
#line 228 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new SizeOfNode(pContext, (yyvsp[-1].pNode)); }
#line 1832 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 233 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OffsetNode(pContext, (yyloc), (yyvsp[-6].pNode), (yyvsp[-3].pNode), (yyvsp[-1].pNode)); }
#line 1838 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 56:
#line 238 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new CastNode(pContext, (yyloc), (yyvsp[-4].pNode), (yyvsp[-1].pNode)); }
#line 1844 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 242 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 1850 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 246 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IdentifierNode(pContext, (yyloc), (yyvsp[0].symIndex)); }
#line 1856 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 250 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 1862 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 254 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1868 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 255 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1874 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 259 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 1880 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 260 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 1886 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 264 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionDeclaratorNode(pContext, (yyvsp[-2].pNode), (yyvsp[-1].symIndex), -1); }
#line 1892 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 265 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionDeclaratorNode(pContext, (yyvsp[-5].pNode), (yyvsp[-4].symIndex), (yyvsp[-2].symIndex)); }
#line 1898 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 269 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionParameterNode(pContext, (yyvsp[-1].pNode), (yyvsp[0].symIndex)); }
#line 1904 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 273 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Basic, WORD_TOKEN); }
#line 1910 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 274 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Basic, FLOAT_TOKEN); }
#line 1916 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 275 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Basic, VOID_TOKEN); }
#line 1922 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 276 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Basic, BOOL_TOKEN); }
#line 1928 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 277 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Struct, (yyvsp[0].symIndex)); }
#line 1934 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 278 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 1940 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 282 "PSL.y" /* yacc.c:1661  */
    {
	                                    							  (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<StructSpecifierNode*>((yyval.pNode))->SetName((yyvsp[-3].symIndex)); }
#line 1947 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 287 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructSpecifierNode(pContext, (yyvsp[0].pNode)); }
#line 1953 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 288 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 1959 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 292 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructDeclarationNode(pContext, (yyvsp[-2].pNode), (yyvsp[-1].symIndex), -1); }
#line 1965 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 294 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructDeclarationNode(pContext, (yyvsp[-5].pNode), (yyvsp[-4].symIndex), (yyvsp[-2].intVal)); }
#line 1971 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 298 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->SetStatementList((yyvsp[0].pNode)); }
#line 1977 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 79:
#line 302 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1983 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 80:
#line 306 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new VariableDeclarationNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), nullptr); }
#line 1989 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 81:
#line 307 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new VariableDeclarationNode(pContext, (yyloc), (yyvsp[-3].pNode), (yyvsp[-2].symIndex), (yyvsp[0].pNode)); }
#line 1995 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 82:
#line 311 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2001 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 83:
#line 315 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StatementListNode(pContext, nullptr); }
#line 2007 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 84:
#line 316 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2013 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 85:
#line 320 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2019 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 86:
#line 321 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2025 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 87:
#line 325 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-1].symIndex), nullptr, nullptr); }
#line 2031 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 88:
#line 326 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-4].symIndex), (yyvsp[-2].pNode), nullptr); }
#line 2037 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 89:
#line 330 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-2].symIndex), nullptr, (yyvsp[0].pNode)); }
#line 2043 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 90:
#line 332 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-5].symIndex), (yyvsp[-3].pNode), (yyvsp[0].pNode)); }
#line 2049 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 91:
#line 333 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2055 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 92:
#line 337 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2061 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 93:
#line 341 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ReturnNode(pContext, (yyvsp[-1].pNode)); }
#line 2067 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 94:
#line 346 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new DebugOutNode(pContext, (yyvsp[-2].pNode)); }
#line 2073 "PSL.tab.c" /* yacc.c:1661  */
    break;


#line 2077 "PSL.tab.c" /* yacc.c:1661  */
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
#line 349 "PSL.y" /* yacc.c:1906  */

