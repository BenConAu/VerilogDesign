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
#line 1 "VSharp.y" /* yacc.c:339  */

#define YYDEBUG 1

#include "VSharpCompilerContext.h"
#include "ASTTree.h"
#include "VSharp.tab.h"

#define YY_EXTRA_TYPE PSLCompilerContext*
#include "lex.h"

void yyerror(YYLTYPE*, void*, const char *s);

#define scanner pContext->pScanner


#line 82 "VSharp.tab.c" /* yacc.c:339  */

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
   by #include "VSharp.tab.h".  */
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
#line 23 "VSharp.y" /* yacc.c:355  */

#include "UIntConstant.h"

#line 116 "VSharp.tab.c" /* yacc.c:355  */

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
    INTCONSTANT = 275,
    BOOLCONSTANT = 276,
    STRINGLITERAL = 277,
    AT = 278,
    SEMICOLON = 279,
    COLON = 280,
    EQUAL = 281,
    STAR = 282,
    PLUS = 283,
    MINUS = 284,
    LEFT_PAREN = 285,
    RIGHT_PAREN = 286,
    LT = 287,
    GT = 288,
    LT_OP = 289,
    GT_OP = 290,
    SHIFTLEFT = 291,
    SHIFTRIGHT = 292,
    ARROW = 293,
    DOT = 294,
    COMMA = 295,
    HAT = 296,
    AMPERSAND = 297,
    EQUAL_OP = 298,
    NOTEQUAL_OP = 299,
    BOOL_TOKEN = 300,
    STRUCT_TOKEN = 301,
    TRANSITION_TOKEN = 302,
    LEFT_BRACE = 303,
    RIGHT_BRACE = 304,
    LEFT_BRACKET = 305,
    RIGHT_BRACKET = 306,
    IF_TOKEN = 307,
    ELSE_TOKEN = 308,
    SIZEOF_TOKEN = 309,
    IDENTIFIER = 310
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 28 "VSharp.y" /* yacc.c:355  */

    UIntConstant constVal;
    int symIndex;
    ASTNode* pNode;

#line 190 "VSharp.tab.c" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */

#line 220 "VSharp.tab.c" /* yacc.c:358  */

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
#define YYFINAL  29
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   338

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  231

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

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
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   150,   150,   151,   155,   156,   157,   158,   162,   163,
     167,   168,   172,   173,   177,   178,   179,   180,   181,   185,
     189,   194,   195,   199,   203,   204,   208,   209,   213,   214,
     215,   219,   220,   221,   225,   226,   227,   231,   232,   233,
     237,   238,   242,   243,   247,   248,   252,   253,   257,   261,
     262,   263,   265,   266,   270,   271,   272,   273,   277,   281,
     282,   286,   290,   294,   298,   299,   303,   304,   308,   309,
     313,   317,   320,   321,   325,   326,   330,   331,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   347,   352,   353,
     357,   358,   363,   367,   368,   372,   373,   377,   378,   379,
     380,   384,   388,   389,   393,   394,   398,   399,   403,   407,
     408,   410,   414,   418,   419,   423,   424,   428,   429,   433,
     434,   435,   439,   440,   441,   445,   448
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MODULE_TOKEN", "OUT_TOKEN",
  "STATE_TOKEN", "UINT_TOKEN", "UINT64_TOKEN", "UINT32_TOKEN",
  "UINT16_TOKEN", "UINT8_TOKEN", "VOID_TOKEN", "INITIAL_TOKEN",
  "RETURN_TOKEN", "AND_OP", "OR_OP", "ENUM_TOKEN", "DRIVE_TOKEN",
  "CLOCK_TOKEN", "FINISH_TOKEN", "INTCONSTANT", "BOOLCONSTANT",
  "STRINGLITERAL", "AT", "SEMICOLON", "COLON", "EQUAL", "STAR", "PLUS",
  "MINUS", "LEFT_PAREN", "RIGHT_PAREN", "LT", "GT", "LT_OP", "GT_OP",
  "SHIFTLEFT", "SHIFTRIGHT", "ARROW", "DOT", "COMMA", "HAT", "AMPERSAND",
  "EQUAL_OP", "NOTEQUAL_OP", "BOOL_TOKEN", "STRUCT_TOKEN",
  "TRANSITION_TOKEN", "LEFT_BRACE", "RIGHT_BRACE", "LEFT_BRACKET",
  "RIGHT_BRACKET", "IF_TOKEN", "ELSE_TOKEN", "SIZEOF_TOKEN", "IDENTIFIER",
  "$accept", "translation_unit", "external_declaration", "enum_definition",
  "enum_list", "statement_list", "statement", "expression_statement",
  "selection_statement", "selection_rest_statement", "expression",
  "unary_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "exclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "assignment_expression", "assignment_operator",
  "postfix_expression", "primary_expression", "glom_expression",
  "glom_list", "declaration", "variable_identifier", "module_prototype",
  "module_header_with_parameters", "module_header", "module_param_decl",
  "function_definition", "function_prototype",
  "function_header_with_parameters", "function_header",
  "function_param_decl", "fully_specified_type", "struct_specifier",
  "struct_declaration_list", "struct_declaration", "module_definition",
  "module_states", "state_list", "module_member", "drive_list_definition",
  "drive_statement_list", "drive_definition", "module_state",
  "init_declarator_list", "single_declaration", "declaration_statement",
  "compound_statement", "function_call", "function_call_header_no_param",
  "function_call_header", "fn_call_arg", "return_statement",
  "transition_statement", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310
};
# endif

#define YYPACT_NINF -157

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-157)))

#define YYTABLE_NINF -86

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      64,   -13,    37,  -157,  -157,  -157,  -157,  -157,    26,  -157,
    -157,    46,  -157,    41,  -157,  -157,  -157,    28,     6,   121,
      49,  -157,  -157,    84,  -157,    83,    94,    73,    76,  -157,
    -157,   185,  -157,  -157,   121,   283,  -157,    96,    42,  -157,
    -157,   106,   116,   110,   283,    -1,   124,  -157,  -157,  -157,
     129,    53,   134,   123,   199,  -157,  -157,  -157,  -157,  -157,
     125,  -157,    35,   149,   150,  -157,  -157,    51,   130,   268,
    -157,   129,   129,   164,   218,  -157,  -157,   134,   283,  -157,
     131,   -10,  -157,  -157,  -157,  -157,  -157,    57,    57,    90,
    -157,  -157,   160,     1,    97,   101,   114,   156,   184,   186,
    -157,    -5,  -157,  -157,  -157,  -157,   168,    63,   161,   170,
     -32,  -157,   -11,  -157,  -157,  -157,  -157,   188,   -14,  -157,
      35,   159,  -157,   181,   -22,   251,  -157,  -157,  -157,   191,
    -157,  -157,  -157,  -157,   163,  -157,  -157,   165,    -7,    -7,
      58,   133,   283,    35,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35,  -157,   166,    68,    35,  -157,
    -157,   133,  -157,  -157,  -157,  -157,  -157,   202,   127,  -157,
    -157,   195,   208,    35,  -157,  -157,  -157,  -157,   190,    57,
    -157,   178,  -157,  -157,  -157,   204,  -157,    -7,   160,   160,
       1,     1,    97,    97,   101,   101,   114,   156,   184,  -157,
     210,   192,   186,  -157,   194,   217,   222,  -157,  -157,   211,
     219,    -7,  -157,  -157,   220,   231,  -157,   228,  -157,  -157,
     129,  -157,   133,   205,  -157,  -157,   200,  -157,  -157,   129,
    -157
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    78,    79,    80,    81,    82,     0,    83,
      84,     0,    85,     0,     2,     5,     7,     0,     0,     0,
       0,     6,     4,     0,   108,     0,     0,     0,     0,     1,
       3,     0,    92,    63,     0,     0,    64,     0,   109,    61,
      66,     0,     0,     0,     0,     0,     0,    93,   112,    99,
       0,     0,     0,     0,     0,    95,   100,    97,    98,    65,
       0,    68,     0,     0,     0,    86,    10,     0,     0,     0,
      88,     0,     0,     0,     0,    70,    71,     0,     0,    72,
       0,   109,    94,    96,    69,    56,    57,     0,     0,    62,
     111,    26,    28,    31,    34,    37,    40,    42,    44,    46,
      23,    24,    49,    55,    54,    52,     0,     0,     0,     0,
       0,     8,     0,    87,    89,   107,   106,     0,     0,   102,
       0,     0,   113,     0,    62,     0,    12,    14,    15,     0,
      16,    18,    17,    73,     0,    76,    74,     0,    25,    59,
       0,   117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,     0,     0,   116,
     115,     0,   110,    67,     9,    11,    90,     0,     0,   101,
     103,     0,     0,     0,   114,    13,    19,    77,     0,     0,
      58,     0,   124,   122,   119,     0,    27,    24,    29,    30,
      32,    33,    35,    36,    38,    39,    41,    43,    45,    53,
      56,     0,    47,   121,     0,     0,     0,   125,   126,     0,
       0,    60,    62,   123,     0,     0,    50,     0,   105,   104,
       0,    75,   118,     0,    91,    20,    22,   120,    51,     0,
      21
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -157,  -157,   242,  -157,  -157,  -157,   143,  -157,  -157,  -157,
     -55,   138,    19,    21,    22,    23,   132,   135,   128,   137,
    -137,  -157,   -62,  -157,  -157,  -157,    14,   102,  -157,  -157,
    -157,   253,  -157,  -157,  -157,  -157,   225,   -16,  -157,  -157,
     216,  -157,  -157,  -157,   243,  -157,  -157,   187,  -157,  -157,
    -157,   -65,   -70,  -157,  -157,  -157,  -156,  -157,  -157
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,    15,    67,   125,   126,   127,   128,   225,
     129,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   158,   187,   102,   103,   140,    48,   104,    17,    18,
      19,    36,    49,    50,    51,    52,    79,    20,    21,    69,
      70,    22,    32,    54,    55,    56,   118,   119,    57,    23,
      24,    58,    75,   105,   106,   107,   184,   131,   132
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     101,   115,   116,    37,   183,   203,   117,    90,   141,   130,
     142,    71,   101,   166,    16,    53,    62,   164,    37,    60,
     136,   155,   137,   165,   183,   138,   139,    16,    68,   144,
     145,   206,   156,   -85,   156,   169,    80,    33,    53,   167,
      63,    29,    25,   157,     1,   157,    34,     2,     3,     4,
       5,     6,     7,    68,    72,    85,    86,     8,   101,     9,
     130,    80,   134,   101,    87,   171,   227,     1,    62,    26,
       2,     3,     4,     5,     6,     7,    31,    85,    86,   101,
       8,    27,     9,    88,    76,   183,    10,    11,   200,    86,
      89,   110,    63,    77,   160,   101,    12,    87,   179,   101,
     111,    28,   201,   161,    38,    88,   101,   180,    39,    10,
      11,   101,    89,    40,    42,    41,    88,   211,   209,    12,
     141,    43,   142,    89,    44,    35,   185,     2,     3,     4,
       5,     6,     7,   146,   147,   148,   149,   181,    78,     9,
       2,     3,     4,     5,     6,     7,   205,    85,    86,    65,
     226,    61,     9,    85,    86,   182,    87,   150,   151,   230,
     101,    64,    87,   188,   189,    66,    10,   190,   191,   108,
     192,   193,    73,   194,   195,    88,    12,    74,    81,    10,
      84,    88,    89,   109,   117,   112,   135,   143,    89,    12,
      45,     2,     3,     4,     5,     6,     7,   152,   153,   159,
     163,   154,    46,     9,    45,     2,     3,     4,     5,     6,
       7,   173,   162,   168,   172,   176,    46,     9,   177,   207,
     178,   199,   204,   210,     2,     3,     4,     5,     6,     7,
      10,   120,   208,   212,    47,   215,     9,   214,    85,    86,
      12,   218,   220,   216,    10,   217,   219,    87,    82,   221,
     222,   223,   224,   229,    12,    30,   228,     2,     3,     4,
       5,     6,     7,    10,   120,   121,    88,   122,   175,     9,
     123,    85,    86,   124,     2,     3,     4,     5,     6,     7,
      87,   186,   198,   213,   196,   114,     9,    59,   197,     2,
       3,     4,     5,     6,     7,   202,    10,    83,   121,    88,
     174,     9,   133,   123,     0,   170,   124,     0,     0,     0,
       0,     0,     0,    10,     0,     0,     0,   113,     0,     0,
       0,     0,     0,    12,     0,     0,     0,     0,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    12
};

static const yytype_int16 yycheck[] =
{
      62,    71,    72,    19,   141,   161,    20,    62,    30,    74,
      32,    12,    74,    24,     0,    31,    26,    49,    34,    35,
      30,    26,    32,    55,   161,    87,    88,    13,    44,    28,
      29,   168,    39,    55,    39,    49,    52,    31,    54,    50,
      50,     0,    55,    50,     3,    50,    40,     6,     7,     8,
       9,    10,    11,    69,    55,    20,    21,    16,   120,    18,
     125,    77,    78,   125,    29,   120,   222,     3,    26,    32,
       6,     7,     8,     9,    10,    11,    48,    20,    21,   141,
      16,    55,    18,    48,    31,   222,    45,    46,    20,    21,
      55,    40,    50,    40,    31,   157,    55,    29,    40,   161,
      49,    55,   157,    40,    55,    48,   168,    49,    24,    45,
      46,   173,    55,    30,    20,    32,    48,   179,   173,    55,
      30,    48,    32,    55,    48,     4,   142,     6,     7,     8,
       9,    10,    11,    36,    37,    34,    35,     4,     4,    18,
       6,     7,     8,     9,    10,    11,    19,    20,    21,    33,
     220,    55,    18,    20,    21,    22,    29,    43,    44,   229,
     222,    55,    29,   144,   145,    55,    45,   146,   147,    20,
     148,   149,    48,   150,   151,    48,    55,    48,    55,    45,
      55,    48,    55,    33,    20,    55,    55,    27,    55,    55,
       5,     6,     7,     8,     9,    10,    11,    41,    14,    31,
      30,    15,    17,    18,     5,     6,     7,     8,     9,    10,
      11,    30,    51,    25,    55,    24,    17,    18,    55,    24,
      55,    55,    20,    33,     6,     7,     8,     9,    10,    11,
      45,    13,    24,    55,    49,    25,    18,    33,    20,    21,
      55,    24,    31,    51,    45,    51,    24,    29,    49,    30,
      30,    20,    24,    53,    55,    13,    51,     6,     7,     8,
       9,    10,    11,    45,    13,    47,    48,    49,   125,    18,
      52,    20,    21,    55,     6,     7,     8,     9,    10,    11,
      29,   143,   154,   181,   152,    69,    18,    34,   153,     6,
       7,     8,     9,    10,    11,   158,    45,    54,    47,    48,
      49,    18,    77,    52,    -1,   118,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,     8,     9,    10,    11,    16,    18,
      45,    46,    55,    57,    58,    59,    82,    84,    85,    86,
      93,    94,    97,   105,   106,    55,    32,    55,    55,     0,
      58,    48,    98,    31,    40,     4,    87,    93,    55,    24,
      30,    32,    20,    48,    48,     5,    17,    49,    82,    88,
      89,    90,    91,    93,    99,   100,   101,   104,   107,    87,
      93,    55,    26,    50,    55,    33,    55,    60,    93,    95,
      96,    12,    55,    48,    48,   108,    31,    40,     4,    92,
      93,    55,    49,   100,    55,    20,    21,    29,    48,    55,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    78,    79,    80,    83,   109,   110,   111,    20,    33,
      40,    49,    55,    49,    96,   108,   108,    20,   102,   103,
      13,    47,    49,    52,    55,    61,    62,    63,    64,    66,
     107,   113,   114,    92,    93,    55,    30,    32,    78,    78,
      81,    30,    32,    27,    28,    29,    36,    37,    34,    35,
      43,    44,    41,    14,    15,    26,    39,    50,    77,    31,
      31,    40,    51,    30,    49,    55,    24,    50,    25,    49,
     103,    66,    55,    30,    49,    62,    24,    55,    55,    40,
      49,     4,    22,    76,   112,    93,    67,    78,    68,    68,
      69,    69,    70,    70,    71,    71,    72,    73,    74,    55,
      20,    66,    75,   112,    20,    19,    76,    24,    24,    66,
      33,    78,    55,    83,    33,    25,    51,    51,    24,    24,
      31,    30,    30,    20,    24,    65,   108,   112,    51,    53,
     108
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    57,    58,    58,    58,    58,    59,    59,
      60,    60,    61,    61,    62,    62,    62,    62,    62,    63,
      64,    65,    65,    66,    67,    67,    68,    68,    69,    69,
      69,    70,    70,    70,    71,    71,    71,    72,    72,    72,
      73,    73,    74,    74,    75,    75,    76,    76,    77,    78,
      78,    78,    78,    78,    79,    79,    79,    79,    80,    81,
      81,    82,    83,    84,    85,    85,    86,    86,    87,    87,
      88,    89,    90,    90,    91,    91,    92,    92,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    94,    95,    95,
      96,    96,    97,    98,    98,    99,    99,   100,   100,   100,
     100,   101,   102,   102,   103,   103,   104,   104,   105,   106,
     106,   106,   107,   108,   108,   109,   109,   110,   110,   111,
     111,   111,   112,   112,   112,   113,   114
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     5,     6,
       1,     3,     1,     2,     1,     1,     1,     1,     1,     2,
       5,     3,     1,     1,     1,     2,     1,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     1,
       4,     6,     1,     3,     1,     1,     1,     1,     3,     1,
       3,     2,     1,     2,     2,     3,     3,     6,     2,     3,
       2,     2,     2,     3,     3,     6,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     5,     1,     2,
       3,     6,     2,     2,     3,     1,     2,     1,     1,     1,
       1,     4,     1,     2,     4,     4,     3,     3,     1,     2,
       5,     4,     1,     2,     3,     2,     2,     2,     5,     3,
       6,     3,     1,     2,     1,     3,     3
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
#line 155 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddModuleDef((yyval.pNode)); }
#line 1609 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 5:
#line 156 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddTypeDef((yyval.pNode)); }
#line 1615 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 6:
#line 157 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddTypeDef((yyval.pNode)); }
#line 1621 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 158 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddGlobal((yyval.pNode)); }
#line 1627 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 8:
#line 162 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<EnumDefinitionNode*>((yyval.pNode))->SetIdentifier((yyvsp[-3].symIndex)); }
#line 1633 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 163 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<EnumDefinitionNode*>((yyval.pNode))->SetIdentifier((yyvsp[-4].symIndex)); }
#line 1639 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 167 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new EnumDefinitionNode(pContext, (yyloc), (yyvsp[0].symIndex)); }
#line 1645 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 168 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<EnumDefinitionNode*>((yyval.pNode))->AddEnum((yyvsp[0].symIndex)); }
#line 1651 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 172 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyvsp[0].pNode)); }
#line 1657 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 173 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 1663 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 177 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1669 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 15:
#line 178 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1675 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 179 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1681 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 180 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1687 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 181 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1693 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 185 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ExpressionStatementNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 1699 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 190 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); dynamic_cast<IfStatementNode*>((yyval.pNode))->SetExpression((yyvsp[-2].pNode)); }
#line 1705 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 194 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IfStatementNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode)); }
#line 1711 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 195 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IfStatementNode(pContext, (yyloc), (yyvsp[0].pNode), nullptr); }
#line 1717 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 199 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1723 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 203 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1729 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 204 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new UnaryOperatorNode(pContext, (yyloc), (yyvsp[0].pNode), Operator::Negate); }
#line 1735 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 208 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1741 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 209 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Multiply); }
#line 1747 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 213 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1753 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 214 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Add); }
#line 1759 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 215 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Subtract); }
#line 1765 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 219 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1771 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 220 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::ShiftLeft); }
#line 1777 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 221 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::ShiftRight); }
#line 1783 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 225 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1789 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 226 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LessThan); }
#line 1795 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 227 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::GreaterThan); }
#line 1801 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 231 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1807 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 232 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Equal); }
#line 1813 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 233 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::NotEqual); }
#line 1819 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 40:
#line 237 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1825 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 41:
#line 238 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::BitwiseXor); }
#line 1831 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 42:
#line 242 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1837 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 243 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LogicalAnd); }
#line 1843 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 44:
#line 247 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1849 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 248 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LogicalOr); }
#line 1855 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 252 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1861 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 253 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new AssignmentNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode)); }
#line 1867 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 261 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1873 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 262 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IndexSelectionNode(pContext, (yyloc), (yyvsp[-3].pNode), (yyvsp[-1].pNode)); }
#line 1879 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 264 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new BitSelectionNode(pContext, (yyloc), (yyvsp[-5].pNode), (yyvsp[-3].constVal), (yyvsp[-1].constVal)); }
#line 1885 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 52:
#line 265 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1891 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 266 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FieldSelectionNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].symIndex)); }
#line 1897 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 54:
#line 270 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1903 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 271 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1909 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 56:
#line 272 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, (yyloc), (yyvsp[0].constVal)); }
#line 1915 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 273 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, (yyloc), (yyvsp[0].constVal)); }
#line 1921 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 277 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new GlomExpressionNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 1927 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 281 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyvsp[0].pNode)); }
#line 1933 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 282 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<ListNode*>((yyval.pNode))->AddNode((yyvsp[0].pNode)); }
#line 1939 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 286 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 1945 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 290 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IdentifierNode(pContext, (yyloc), (yyvsp[0].symIndex)); }
#line 1951 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 294 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 1957 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 298 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<ModuleDeclaratorNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 1963 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 299 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<ModuleDeclaratorNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 1969 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 303 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleDeclaratorNode(pContext, (yyvsp[-1].symIndex), -1); }
#line 1975 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 304 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleDeclaratorNode(pContext, (yyvsp[-4].symIndex), (yyvsp[-2].symIndex)); }
#line 1981 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 308 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleParameterNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), false); }
#line 1987 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 309 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleParameterNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), true); }
#line 1993 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 313 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->SetStatementList((yyvsp[0].pNode)); }
#line 1999 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 317 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2005 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 320 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 2011 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 321 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 2017 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 325 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionDeclaratorNode(pContext, (yyvsp[-2].pNode), (yyvsp[-1].symIndex), -1); }
#line 2023 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 326 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionDeclaratorNode(pContext, (yyvsp[-5].pNode), (yyvsp[-4].symIndex), (yyvsp[-2].symIndex)); }
#line 2029 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 330 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionParameterNode(pContext, (yyvsp[-1].pNode), (yyvsp[0].symIndex), false); }
#line 2035 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 331 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionParameterNode(pContext, (yyvsp[-1].pNode), (yyvsp[0].symIndex), true); }
#line 2041 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 335 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 64); }
#line 2047 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 79:
#line 336 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 32); }
#line 2053 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 80:
#line 337 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 16); }
#line 2059 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 81:
#line 338 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 8); }
#line 2065 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 82:
#line 339 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Void); }
#line 2071 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 83:
#line 340 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Clock); }
#line 2077 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 84:
#line 341 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 1); }
#line 2083 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 85:
#line 342 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Unknown, (yyvsp[0].symIndex)); }
#line 2089 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 86:
#line 343 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), (yyvsp[-1].constVal)); }
#line 2095 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 87:
#line 347 "VSharp.y" /* yacc.c:1661  */
    {
	                                    							  (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<StructSpecifierNode*>((yyval.pNode))->SetName((yyvsp[-3].symIndex)); }
#line 2102 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 88:
#line 352 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructSpecifierNode(pContext, (yyvsp[0].pNode)); }
#line 2108 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 89:
#line 353 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2114 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 90:
#line 357 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructDeclarationNode(pContext, (yyvsp[-2].pNode), (yyvsp[-1].symIndex)); }
#line 2120 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 91:
#line 359 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructDeclarationNode(pContext, (yyvsp[-5].pNode), (yyvsp[-4].symIndex), (yyvsp[-2].constVal)); }
#line 2126 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 92:
#line 363 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<ModuleDeclaratorNode*>((yyval.pNode))->SetStatementList((yyvsp[0].pNode)); }
#line 2132 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 93:
#line 367 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, nullptr); }
#line 2138 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 94:
#line 368 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2144 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 95:
#line 372 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyvsp[0].pNode)); }
#line 2150 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 96:
#line 373 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2156 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 97:
#line 377 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2162 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 98:
#line 378 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2168 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 99:
#line 379 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2174 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 100:
#line 380 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2180 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 101:
#line 384 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new DriveListDefinitionNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2186 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 102:
#line 388 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyvsp[0].pNode)); }
#line 2192 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 103:
#line 389 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2198 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 104:
#line 393 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new DriveDefinitionNode(pContext, (yyloc), (yyvsp[-3].constVal), (yyvsp[-1].pNode)); }
#line 2204 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 105:
#line 394 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new DriveDefinitionNode(pContext, (yyloc), (yyvsp[-3].constVal), nullptr); }
#line 2210 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 106:
#line 398 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StateDeclaratorNode(pContext, (yyloc), (yyvsp[-1].symIndex), (yyvsp[0].pNode)); }
#line 2216 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 107:
#line 399 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StateDeclaratorNode(pContext, (yyloc), -1, (yyvsp[0].pNode)); }
#line 2222 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 108:
#line 403 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2228 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 109:
#line 407 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new VariableDeclarationNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), nullptr); }
#line 2234 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 110:
#line 409 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new VariableDeclarationNode(pContext, (yyloc), (yyvsp[-4].pNode), (yyvsp[-3].symIndex), (yyvsp[-1].constVal), nullptr); }
#line 2240 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 111:
#line 410 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new VariableDeclarationNode(pContext, (yyloc), (yyvsp[-3].pNode), (yyvsp[-2].symIndex), (yyvsp[0].pNode)); }
#line 2246 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 112:
#line 414 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2252 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 113:
#line 418 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, nullptr); }
#line 2258 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 114:
#line 419 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2264 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 115:
#line 423 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2270 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 116:
#line 424 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2276 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 117:
#line 428 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-1].symIndex), nullptr, nullptr); }
#line 2282 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 118:
#line 429 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-4].symIndex), (yyvsp[-2].pNode), nullptr); }
#line 2288 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 119:
#line 433 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-2].symIndex), nullptr, (yyvsp[0].pNode)); }
#line 2294 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 120:
#line 434 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-5].symIndex), (yyvsp[-3].pNode), (yyvsp[0].pNode)); }
#line 2300 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 121:
#line 435 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2306 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 122:
#line 439 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallParamNode(pContext, (yyloc), false, (yyvsp[0].pNode)); }
#line 2312 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 123:
#line 440 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallParamNode(pContext, (yyloc), true, (yyvsp[0].pNode)); }
#line 2318 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 124:
#line 441 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallParamNode(pContext, (yyloc)); }
#line 2324 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 125:
#line 445 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ReturnNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2330 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 126:
#line 448 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TransitionNode(pContext, (yyvsp[-1].symIndex)); }
#line 2336 "VSharp.tab.c" /* yacc.c:1661  */
    break;


#line 2340 "VSharp.tab.c" /* yacc.c:1661  */
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
#line 451 "VSharp.y" /* yacc.c:1906  */

