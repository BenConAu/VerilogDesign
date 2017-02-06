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
    DOUTR_TOKEN = 297,
    EXECR_TOKEN = 298,
    EXIT_TOKEN = 299,
    EMIT_TOKEN = 300,
    SIZEOF_TOKEN = 301,
    OFFSETPTR_TOKEN = 302,
    CASTPTR_TOKEN = 303,
    READPORT_TOKEN = 304,
    WRITEPORT_TOKEN = 305,
    PACKBYTE_TOKEN = 306,
    DATASEGEND_TOKEN = 307,
    IDENTIFIER = 308
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
    int token;

#line 184 "PSL.tab.c" /* yacc.c:355  */
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

#line 214 "PSL.tab.c" /* yacc.c:358  */

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
#define YYLAST   269

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  213

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   133,   133,   134,   138,   139,   140,   144,   145,   149,
     150,   151,   152,   153,   154,   155,   159,   163,   165,   170,
     171,   175,   179,   180,   184,   185,   186,   190,   191,   192,
     196,   197,   198,   202,   203,   204,   208,   209,   213,   214,
     218,   222,   223,   224,   225,   226,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   244,   248,   253,
     258,   263,   267,   271,   275,   276,   280,   281,   285,   286,
     290,   294,   295,   296,   297,   298,   299,   300,   304,   309,
     310,   314,   315,   320,   324,   328,   329,   333,   337,   338,
     342,   343,   347,   348,   352,   353,   355,   359,   363,   367,
     369,   374,   378,   379,   383,   388
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
  "NOTEQUAL_OP", "PTR_TOKEN", "BYTE_TOKEN", "WORD_TOKEN", "BOOL_TOKEN",
  "FLOAT_TOKEN", "VOID_TOKEN", "STRUCT_TOKEN", "RETURN_TOKEN",
  "LEFT_BRACE", "RIGHT_BRACE", "LEFT_BRACKET", "RIGHT_BRACKET", "IF_TOKEN",
  "ELSE_TOKEN", "WHILE_TOKEN", "NULLPTR_TOKEN", "DOUTR_TOKEN",
  "EXECR_TOKEN", "EXIT_TOKEN", "EMIT_TOKEN", "SIZEOF_TOKEN",
  "OFFSETPTR_TOKEN", "CASTPTR_TOKEN", "READPORT_TOKEN", "WRITEPORT_TOKEN",
  "PACKBYTE_TOKEN", "DATASEGEND_TOKEN", "IDENTIFIER", "$accept",
  "translation_unit", "external_declaration", "statement_list",
  "statement", "expression_statement", "selection_statement",
  "selection_rest_statement", "expression", "assignment_expression",
  "equality_expression", "relational_expression", "shift_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "assignment_operator", "postfix_expression", "primary_expression",
  "sizeof_expression", "offset_expression", "cast_expression",
  "readport_expression", "declaration", "variable_identifier",
  "function_prototype", "function_declarator",
  "function_header_with_parameters", "function_header",
  "parameter_declaration", "fully_specified_type", "struct_specifier",
  "struct_declaration_list", "struct_declaration", "function_definition",
  "init_declarator_list", "single_declaration", "declaration_statement",
  "compound_statement", "function_call", "function_call_header_no_param",
  "function_call_header", "jump_statement", "return_statement",
  "emit_statement", "opcode0_token", "opcode1_token", "packbyte_statement",
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
     305,   306,   307,   308
};
# endif

#define YYPACT_NINF -101

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-101)))

#define YYTABLE_NINF -77

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      31,    27,  -101,  -101,  -101,  -101,  -101,   -46,  -101,    16,
    -101,  -101,    18,    55,    50,   102,    39,    96,  -101,    99,
    -101,   102,    74,  -101,  -101,   113,  -101,  -101,   102,  -101,
      58,    -3,  -101,  -101,    98,   102,  -101,  -101,  -101,   216,
      66,   177,  -101,   111,   115,  -101,   122,   125,   124,   131,
     135,   137,   138,  -101,    -4,   164,  -101,  -101,  -101,   149,
    -101,    -7,     8,    37,    54,   148,  -101,    30,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,   117,  -101,  -101,   158,   -10,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,   177,  -101,   119,
    -101,   120,     1,  -101,    25,    76,  -101,  -101,   167,   177,
     177,    43,   102,   102,   102,   177,   177,   177,   177,   102,
    -101,  -101,  -101,   177,   177,   177,   177,   177,   177,   177,
     177,   177,  -101,   123,   126,   177,   177,   169,  -101,  -101,
     177,  -101,   163,    -1,  -101,  -101,  -101,   170,   171,  -101,
    -101,  -101,   172,   174,   173,   183,   186,   176,   181,   184,
    -101,   192,     8,    76,     8,    37,    37,    54,    54,   148,
     148,  -101,  -101,  -101,   185,    -7,  -101,   196,  -101,   224,
      18,    18,   221,   216,  -101,   219,   220,  -101,   177,   177,
     222,  -101,  -101,   198,  -101,   194,  -101,  -101,    78,   177,
     177,   223,   215,   177,   231,    18,   233,   225,   228,   235,
     177,  -101,  -101,  -101,  -101,   177,  -101,  -101,   230,   232,
     237,  -101,  -101
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    72,    71,    75,    73,    74,     0,    76,     0,
       2,     6,     0,     0,    65,    64,     0,     0,     4,     0,
      84,     0,     0,     1,     3,     0,    83,    63,     0,    66,
       0,    85,     5,    61,     0,     0,    48,    50,    49,     0,
       0,     0,    88,     0,     0,    51,     0,     0,     0,     0,
       0,     0,     0,    52,    62,     0,     7,     9,    10,     0,
      21,    22,    24,    27,    30,    33,    36,    38,    41,    53,
      54,    55,    56,    87,    46,     0,    11,    43,     0,     0,
      12,    97,    13,    14,    15,    67,    70,     0,    68,     0,
      77,     0,     0,    79,    62,    39,    62,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,     0,
      89,     8,    16,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    40,     0,     0,     0,     0,    85,    91,    90,
       0,    86,     0,     0,    78,    80,    98,     0,     0,   102,
     103,   101,     0,     0,     0,     0,     0,     0,     0,     0,
      94,     0,    25,    38,    26,    28,    29,    31,    32,    34,
      35,    37,    45,    44,     0,    23,    96,     0,    81,     0,
       0,     0,     0,     0,    57,     0,     0,    60,     0,     0,
       0,    42,    69,     0,    17,    20,    18,    99,     0,     0,
       0,     0,     0,    93,     0,     0,     0,     0,     0,     0,
       0,    95,    82,    19,   100,     0,    59,   105,     0,     0,
       0,    58,   104
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -101,  -101,   239,  -101,   191,  -101,  -101,  -101,   -85,   -41,
     127,   -40,    -6,     4,     6,   128,  -101,   -38,  -101,  -101,
    -101,  -101,  -101,   -21,   210,  -101,  -101,  -101,  -101,   226,
      -2,  -101,  -101,   159,  -101,  -101,  -101,  -101,  -100,  -101,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    55,    56,    57,    58,   184,    59,    60,
      61,    62,    63,    64,    65,    66,   126,    67,    68,    69,
      70,    71,    72,    11,    74,    12,    13,    14,    15,    29,
      16,    17,    92,    93,    18,    19,    20,    76,    26,    77,
      78,    79,    80,    81,    82,   142,   143,    83,    84
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      98,    95,   131,   129,    73,    87,   168,    22,   108,    88,
     109,    89,   130,    30,   137,   138,    23,   113,   114,    34,
     147,   148,   149,    75,   115,   116,    30,     1,     2,     3,
       4,     5,     6,    91,    73,   169,   134,   108,   122,   109,
     164,    21,     1,     2,     3,     4,     5,     6,     7,   -76,
     123,   124,    25,    75,     8,   117,   118,     1,     2,     3,
       4,     5,     6,     7,   119,   120,   125,   150,    27,     8,
     185,   186,    28,   152,   154,   153,   153,   153,   153,   153,
     153,   153,   153,   153,     8,   139,   140,   141,   153,   166,
      91,   196,    31,   191,   192,   203,   123,   124,   123,   124,
     144,   145,   146,    32,   197,   198,    33,   151,    35,   155,
     156,    86,   125,    90,   125,   208,    36,    37,    38,    96,
     209,   157,   158,    99,    39,   159,   160,   100,     1,     2,
       3,     4,     5,     6,   101,   188,    40,   102,   103,     1,
       2,     3,     4,     5,     6,   104,    41,   105,    42,   106,
     107,    43,   201,    44,    45,     8,   112,   121,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    36,    37,    38,
     127,   128,   132,   133,   136,    39,   162,    87,   167,   163,
      36,    37,    38,   170,   171,   172,   174,    40,    39,   177,
       1,     2,     3,     4,     5,     6,   173,    41,   175,   110,
      40,   176,    43,   178,    44,    45,   179,   180,   182,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    45,    36,
      37,    38,   181,    47,    48,    49,    50,   183,   187,    53,
      94,   189,   190,   195,   193,   194,   199,   200,   202,    40,
     204,   206,   207,   210,   212,   211,   111,   205,    24,   161,
      97,   135,     0,   165,    85,     0,     0,    45,     0,     0,
       0,     0,    47,    48,    49,    50,     0,     0,    53,    94
};

static const yytype_int16 yycheck[] =
{
      41,    39,    87,    13,    25,     8,     7,    53,    12,    12,
      14,    14,    22,    15,    99,   100,     0,    24,    25,    21,
     105,   106,   107,    25,    16,    17,    28,    26,    27,    28,
      29,    30,    31,    35,    55,    36,    35,    12,     8,    14,
     125,    14,    26,    27,    28,    29,    30,    31,    32,    53,
      20,    21,    34,    55,    53,    18,    19,    26,    27,    28,
      29,    30,    31,    32,    10,    11,    36,   108,    13,    53,
     170,   171,    22,   113,   114,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    53,    42,    43,    44,   126,   130,
      92,    13,    53,   178,   179,   195,    20,    21,    20,    21,
     102,   103,   104,     7,   189,   190,     7,   109,    34,   115,
     116,    53,    36,    15,    36,   200,     3,     4,     5,    53,
     205,   117,   118,    12,    11,   119,   120,    12,    26,    27,
      28,    29,    30,    31,    12,   173,    23,    12,    14,    26,
      27,    28,    29,    30,    31,    14,    33,    12,    35,    12,
      12,    38,   193,    40,    41,    53,     7,     9,    45,    46,
      47,    48,    49,    50,    51,    52,    53,     3,     4,     5,
      53,    13,    53,    53,     7,    11,    53,     8,    15,    53,
       3,     4,     5,    13,    13,    13,    13,    23,    11,    13,
      26,    27,    28,    29,    30,    31,    22,    33,    15,    35,
      23,    15,    38,    22,    40,    41,    22,    15,    12,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    41,     3,
       4,     5,    37,    46,    47,    48,    49,     3,     7,    52,
      53,    12,    12,    39,    12,    37,    13,    22,     7,    23,
       7,    13,     7,    13,     7,    13,    55,    22,     9,   121,
      40,    92,    -1,   126,    28,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    -1,    -1,    52,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    26,    27,    28,    29,    30,    31,    32,    53,    55,
      56,    77,    79,    80,    81,    82,    84,    85,    88,    89,
      90,    14,    53,     0,    56,    34,    92,    13,    22,    83,
      84,    53,     7,     7,    84,    34,     3,     4,     5,    11,
      23,    33,    35,    38,    40,    41,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    57,    58,    59,    60,    62,
      63,    64,    65,    66,    67,    68,    69,    71,    72,    73,
      74,    75,    76,    77,    78,    84,    91,    93,    94,    95,
      96,    97,    98,   101,   102,    83,    53,     8,    12,    14,
      15,    84,    86,    87,    53,    71,    53,    78,    63,    12,
      12,    12,    12,    14,    14,    12,    12,    12,    12,    14,
      35,    58,     7,    24,    25,    16,    17,    18,    19,    10,
      11,     9,     8,    20,    21,    36,    70,    53,    13,    13,
      22,    62,    53,    53,    35,    87,     7,    62,    62,    42,
      43,    44,    99,   100,    84,    84,    84,    62,    62,    62,
      63,    84,    65,    71,    65,    66,    66,    67,    67,    68,
      68,    69,    53,    53,    62,    64,    63,    15,     7,    36,
      13,    13,    13,    22,    13,    15,    15,    13,    22,    22,
      15,    37,    12,     3,    61,    92,    92,     7,    71,    12,
      12,    62,    62,    12,    37,    39,    13,    62,    62,    13,
      22,    63,     7,    92,     7,    22,    13,     7,    62,    62,
      13,    13,     7
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    56,    56,    56,    57,    57,    58,
      58,    58,    58,    58,    58,    58,    59,    60,    60,    61,
      61,    62,    63,    63,    64,    64,    64,    65,    65,    65,
      66,    66,    66,    67,    67,    67,    68,    68,    69,    69,
      70,    71,    71,    71,    71,    71,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    80,    81,    81,    82,    82,
      83,    84,    84,    84,    84,    84,    84,    84,    85,    86,
      86,    87,    87,    88,    89,    90,    90,    91,    92,    92,
      93,    93,    94,    94,    95,    95,    95,    96,    97,    98,
      98,    99,   100,   100,   101,   102
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     5,     5,     3,
       1,     1,     1,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     1,     2,
       1,     1,     4,     1,     3,     3,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     9,     7,
       4,     2,     1,     2,     1,     1,     2,     3,     3,     6,
       2,     1,     1,     1,     1,     1,     1,     4,     5,     1,
       2,     3,     6,     2,     1,     2,     4,     1,     2,     3,
       2,     2,     2,     5,     3,     6,     3,     1,     3,     5,
       7,     1,     1,     1,     9,     7
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
#line 138 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddFuncDef((yyval.pNode)); }
#line 1571 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 5:
#line 139 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); pContext->AddStructDef((yyval.pNode)); }
#line 1577 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 6:
#line 140 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddGlobal((yyval.pNode)); }
#line 1583 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 144 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StatementListNode(pContext, (yyvsp[0].pNode)); }
#line 1589 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 8:
#line 145 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 1595 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 149 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1601 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 150 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1607 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 151 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1613 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 152 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1619 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 153 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1625 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 154 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1631 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 15:
#line 155 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1637 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 159 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 1643 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 164 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); dynamic_cast<IfStatementNode*>((yyval.pNode))->SetStatementList((yyvsp[-2].pNode)); }
#line 1649 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 166 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new WhileStatementNode(pContext, (yyvsp[-2].pNode), (yyvsp[0].pNode)); }
#line 1655 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 170 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IfStatementNode(pContext, (yyvsp[-2].pNode), (yyvsp[0].pNode)); }
#line 1661 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 171 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IfStatementNode(pContext, (yyvsp[0].pNode), nullptr); }
#line 1667 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 175 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1673 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 179 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1679 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 180 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new AssignmentNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode)); }
#line 1685 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 184 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1691 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 185 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Equal); }
#line 1697 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 186 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::NotEqual); }
#line 1703 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 190 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1709 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 191 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LessThan); }
#line 1715 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 192 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::GreaterThan); }
#line 1721 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 196 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1727 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 197 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::ShiftLeft); }
#line 1733 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 198 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::ShiftRight); }
#line 1739 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 202 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1745 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 203 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Add); }
#line 1751 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 204 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Subtract); }
#line 1757 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 208 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1763 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 209 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Multiply); }
#line 1769 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 213 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1775 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 214 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new UnaryOperatorNode(pContext, (yyvsp[0].pNode), Operator::Negate); }
#line 1781 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 41:
#line 222 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1787 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 42:
#line 223 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IndexSelectionNode(pContext, (yyloc), (yyvsp[-3].pNode), (yyvsp[-1].pNode)); }
#line 1793 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 224 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1799 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 44:
#line 225 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FieldSelectionNode(pContext, (yyloc), (yyvsp[-2].pNode), false, (yyvsp[0].symIndex)); }
#line 1805 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 226 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FieldSelectionNode(pContext, (yyloc), (yyvsp[-2].pNode), true, (yyvsp[0].symIndex)); }
#line 1811 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 230 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1817 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 231 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new AddressOfNode(pContext, (yyvsp[0].pNode)); }
#line 1823 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 48:
#line 232 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, ConstantNode::Word, (yyvsp[0].intVal)); }
#line 1829 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 233 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, ConstantNode::Bool, (yyvsp[0].intVal)); }
#line 1835 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 234 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, (yyvsp[0].floatVal)); }
#line 1841 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 235 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, ConstantNode::Pointer); }
#line 1847 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 52:
#line 236 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new KnownConstantNode(pContext, KnownConstants::DataSegmentEnd); }
#line 1853 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 237 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1859 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 54:
#line 238 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1865 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 239 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1871 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 56:
#line 240 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1877 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 244 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new SizeOfNode(pContext, (yyvsp[-1].pNode)); }
#line 1883 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 249 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OffsetNode(pContext, (yyloc), (yyvsp[-6].pNode), (yyvsp[-3].pNode), (yyvsp[-1].pNode)); }
#line 1889 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 254 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new CastNode(pContext, (yyloc), (yyvsp[-4].pNode), (yyvsp[-1].pNode)); }
#line 1895 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 259 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ReadPortNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 1901 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 263 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 1907 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 267 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IdentifierNode(pContext, (yyloc), (yyvsp[0].symIndex)); }
#line 1913 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 271 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 1919 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 275 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1925 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 276 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1931 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 280 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 1937 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 281 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 1943 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 285 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionDeclaratorNode(pContext, (yyvsp[-2].pNode), (yyvsp[-1].symIndex), -1); }
#line 1949 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 286 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionDeclaratorNode(pContext, (yyvsp[-5].pNode), (yyvsp[-4].symIndex), (yyvsp[-2].symIndex)); }
#line 1955 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 290 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionParameterNode(pContext, (yyvsp[-1].pNode), (yyvsp[0].symIndex)); }
#line 1961 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 294 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Basic, WORD_TOKEN); }
#line 1967 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 295 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Basic, BYTE_TOKEN); }
#line 1973 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 296 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Basic, FLOAT_TOKEN); }
#line 1979 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 297 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Basic, VOID_TOKEN); }
#line 1985 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 298 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Basic, BOOL_TOKEN); }
#line 1991 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 299 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Struct, (yyvsp[0].symIndex)); }
#line 1997 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 300 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2003 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 304 "PSL.y" /* yacc.c:1661  */
    {
	                                    							  (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<StructSpecifierNode*>((yyval.pNode))->SetName((yyvsp[-3].symIndex)); }
#line 2010 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 79:
#line 309 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructSpecifierNode(pContext, (yyvsp[0].pNode)); }
#line 2016 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 80:
#line 310 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2022 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 81:
#line 314 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructDeclarationNode(pContext, (yyvsp[-2].pNode), (yyvsp[-1].symIndex), -1); }
#line 2028 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 82:
#line 316 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructDeclarationNode(pContext, (yyvsp[-5].pNode), (yyvsp[-4].symIndex), (yyvsp[-2].intVal)); }
#line 2034 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 83:
#line 320 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->SetStatementList((yyvsp[0].pNode)); }
#line 2040 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 84:
#line 324 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2046 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 85:
#line 328 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new VariableDeclarationNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), nullptr); }
#line 2052 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 86:
#line 329 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new VariableDeclarationNode(pContext, (yyloc), (yyvsp[-3].pNode), (yyvsp[-2].symIndex), (yyvsp[0].pNode)); }
#line 2058 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 87:
#line 333 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2064 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 88:
#line 337 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StatementListNode(pContext, nullptr); }
#line 2070 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 89:
#line 338 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2076 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 90:
#line 342 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2082 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 91:
#line 343 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2088 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 92:
#line 347 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-1].symIndex), nullptr, nullptr); }
#line 2094 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 93:
#line 348 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-4].symIndex), (yyvsp[-2].pNode), nullptr); }
#line 2100 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 94:
#line 352 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-2].symIndex), nullptr, (yyvsp[0].pNode)); }
#line 2106 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 95:
#line 354 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-5].symIndex), (yyvsp[-3].pNode), (yyvsp[0].pNode)); }
#line 2112 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 96:
#line 355 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2118 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 97:
#line 359 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2124 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 98:
#line 363 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ReturnNode(pContext, (yyvsp[-1].pNode)); }
#line 2130 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 99:
#line 368 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new EmitNode(pContext, (yyvsp[-2].token), nullptr); }
#line 2136 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 100:
#line 370 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new EmitNode(pContext, (yyvsp[-4].token), (yyvsp[-2].pNode)); }
#line 2142 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 101:
#line 374 "PSL.y" /* yacc.c:1661  */
    { (yyval.token) = EXIT_TOKEN; }
#line 2148 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 102:
#line 378 "PSL.y" /* yacc.c:1661  */
    { (yyval.token) = DOUTR_TOKEN; }
#line 2154 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 103:
#line 379 "PSL.y" /* yacc.c:1661  */
    { (yyval.token) = EXECR_TOKEN; }
#line 2160 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 104:
#line 384 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new PackByteNode(pContext, (yyloc), (yyvsp[-6].pNode), (yyvsp[-4].pNode), (yyvsp[-2].pNode)); }
#line 2166 "PSL.tab.c" /* yacc.c:1661  */
    break;

  case 105:
#line 389 "PSL.y" /* yacc.c:1661  */
    { (yyval.pNode) = new WritePortNode(pContext, (yyloc), (yyvsp[-4].pNode), (yyvsp[-2].pNode)); }
#line 2172 "PSL.tab.c" /* yacc.c:1661  */
    break;


#line 2176 "PSL.tab.c" /* yacc.c:1661  */
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
#line 392 "PSL.y" /* yacc.c:1906  */

