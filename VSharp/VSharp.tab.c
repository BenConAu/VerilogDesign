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

#include "ParserContext.h"
#include "ASTTree.h"
#include "VSharp.tab.h"

#define YY_EXTRA_TYPE ParserContext*
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
#include "EnumItem.h"

class ASTNode;
class ParserContext;

#line 120 "VSharp.tab.c" /* yacc.c:355  */

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
    PLUS = 287,
    MINUS = 288,
    LEFT_PAREN = 289,
    RIGHT_PAREN = 290,
    LT = 291,
    GT = 292,
    LT_OP = 293,
    GT_OP = 294,
    LT_EQUAL_OP = 295,
    GT_EQUAL_OP = 296,
    SHIFTLEFT = 297,
    SHIFTRIGHT = 298,
    ARROW = 299,
    DOT = 300,
    COMMA = 301,
    HAT = 302,
    BANG = 303,
    AMPERSAND = 304,
    QUESTION = 305,
    EQUAL_OP = 306,
    NOTEQUAL_OP = 307,
    BOOL_TOKEN = 308,
    STRUCT_TOKEN = 309,
    TRANSITION_TOKEN = 310,
    LEFT_BRACE = 311,
    RIGHT_BRACE = 312,
    LEFT_BRACKET = 313,
    RIGHT_BRACKET = 314,
    IF_TOKEN = 315,
    ELSE_TOKEN = 316,
    IMPORT_TOKEN = 317,
    WIRE_TOKEN = 318,
    CONST_TOKEN = 319,
    IDENTIFIER = 320
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 32 "VSharp.y" /* yacc.c:355  */

    UIntConstant constVal;
    int symIndex;
    ASTNode* pNode;
    EnumItem _EnumItem;

#line 205 "VSharp.tab.c" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */

#line 235 "VSharp.tab.c" /* yacc.c:358  */

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
#define YYFINAL  41
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   614

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  66
/* YYNRULES -- Number of rules.  */
#define YYNRULES  149
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  283

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   320

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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   172,   172,   173,   177,   178,   179,   180,   181,   182,
     186,   189,   190,   194,   195,   199,   200,   204,   205,   209,
     210,   211,   212,   213,   214,   215,   219,   224,   225,   229,
     231,   235,   239,   243,   247,   252,   253,   257,   258,   259,
     263,   264,   268,   269,   270,   274,   275,   276,   280,   281,
     282,   283,   284,   288,   289,   290,   294,   295,   299,   300,
     304,   305,   309,   310,   314,   318,   319,   320,   322,   323,
     327,   328,   329,   330,   331,   335,   339,   340,   344,   348,
     352,   353,   357,   358,   362,   363,   367,   368,   372,   376,
     379,   380,   384,   385,   389,   390,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   406,   407,   408,   412,   417,
     418,   422,   423,   428,   429,   433,   434,   438,   439,   443,
     444,   445,   446,   450,   454,   455,   459,   460,   464,   465,
     466,   470,   474,   475,   477,   481,   485,   486,   490,   491,
     495,   496,   500,   501,   502,   506,   507,   508,   512,   515
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
  "ALWAYS_TOKEN", "RETURN_TOKEN", "AND_OP", "OR_OP", "ENUM_TOKEN",
  "DRIVE_TOKEN", "CLOCK_TOKEN", "FINISH_TOKEN", "CASE_TOKEN",
  "SWITCH_TOKEN", "DEFAULT_TOKEN", "INTCONSTANT", "BOOLCONSTANT",
  "STRINGLITERAL", "AT", "SEMICOLON", "COLON", "EQUAL", "STAR", "PLUS",
  "MINUS", "LEFT_PAREN", "RIGHT_PAREN", "LT", "GT", "LT_OP", "GT_OP",
  "LT_EQUAL_OP", "GT_EQUAL_OP", "SHIFTLEFT", "SHIFTRIGHT", "ARROW", "DOT",
  "COMMA", "HAT", "BANG", "AMPERSAND", "QUESTION", "EQUAL_OP",
  "NOTEQUAL_OP", "BOOL_TOKEN", "STRUCT_TOKEN", "TRANSITION_TOKEN",
  "LEFT_BRACE", "RIGHT_BRACE", "LEFT_BRACKET", "RIGHT_BRACKET", "IF_TOKEN",
  "ELSE_TOKEN", "IMPORT_TOKEN", "WIRE_TOKEN", "CONST_TOKEN", "IDENTIFIER",
  "$accept", "translation_unit", "external_declaration",
  "import_statement", "enum_definition", "enum_list", "enum_item",
  "statement_list", "statement", "switch_statement", "case_list",
  "case_statement", "expression_statement", "assignment_statement",
  "assignment_operator", "selection_statement", "selection_rest_statement",
  "unary_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "exclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression", "expression",
  "postfix_expression", "primary_expression", "glom_expression",
  "glom_list", "declaration", "variable_identifier", "module_prototype",
  "module_header_with_parameters", "module_header", "module_param_decl",
  "function_definition", "function_prototype",
  "function_header_with_parameters", "function_header",
  "function_param_decl", "type_name_specifier", "fully_specified_type",
  "struct_specifier", "struct_declaration_list", "struct_declaration",
  "module_definition", "module_states", "state_list", "module_member",
  "drive_list_definition", "drive_statement_list", "drive_definition",
  "module_state", "init_declarator_list", "single_declaration",
  "declaration_statement", "compound_statement", "function_call",
  "function_call_header_no_param", "function_call_header", "fn_call_arg",
  "return_statement", "transition_statement", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320
};
# endif

#define YYPACT_NINF -173

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-173)))

#define YYTABLE_NINF -104

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     137,   -37,    -5,  -173,  -173,  -173,  -173,  -173,   -22,  -173,
    -173,   -13,   108,   462,   462,  -173,   109,  -173,  -173,  -173,
    -173,   -10,    75,   199,  -173,    81,    90,     5,  -173,    -2,
    -173,  -173,    64,  -173,   115,   118,    96,   105,   142,  -173,
    -173,  -173,  -173,  -173,   230,  -173,  -173,   213,   402,  -173,
    -173,   101,   309,  -173,  -173,     5,   402,  -173,   110,    47,
    -173,  -173,   122,   159,   139,   402,  -173,     7,   160,  -173,
    -173,  -173,   249,  -173,  -173,  -173,  -173,  -173,   150,  -173,
      66,   195,  -173,  -173,    99,    66,    99,   165,    99,  -173,
     197,    67,   369,  -173,  -173,  -173,  -173,  -173,  -173,   202,
      52,    46,   138,    55,   196,   227,    -6,  -173,   216,    50,
    -173,  -173,  -173,   180,  -173,  -173,   211,    92,  -173,  -173,
    -173,   182,  -173,    66,  -173,   185,    66,   214,  -173,   223,
      84,  -173,   204,   342,  -173,    81,    81,    81,   237,  -173,
    -173,  -173,   123,   242,   -19,    66,   -19,   236,   -19,   244,
     -19,   112,    66,    31,   402,  -173,  -173,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,  -173,  -173,   208,   274,    66,    -9,  -173,  -173,
      31,  -173,  -173,   228,   215,   241,   255,   -27,  -173,   -11,
    -173,  -173,  -173,  -173,  -173,   251,     3,  -173,  -173,   246,
    -173,  -173,    99,  -173,   247,    99,  -173,  -173,  -173,   248,
    -173,   202,   202,    52,    52,    46,    46,    46,    46,   138,
     138,    55,   196,   227,   257,  -173,   259,   225,   261,  -173,
     256,  -173,  -173,  -173,  -173,  -173,  -173,   267,    17,  -173,
    -173,   240,   -19,    81,   -19,   258,    66,   273,  -173,  -173,
    -173,   245,   272,  -173,    50,   144,  -173,   250,    31,  -173,
     262,   275,  -173,    66,   276,     2,  -173,    81,  -173,  -173,
    -173,   280,   254,  -173,  -173,  -173,   268,   549,   549,   429,
     489,  -173,  -173
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    96,    97,    98,    99,   100,     0,   101,
     102,     0,     0,     0,     0,   103,     0,     2,     6,     7,
       9,     0,     0,     0,     5,     0,     0,     0,   107,     0,
       8,     4,     0,   131,     0,     0,     0,     0,     0,   105,
     106,     1,     3,   113,     0,   114,    80,     0,     0,    81,
      82,     0,     0,    88,    89,     0,     0,    90,     0,   132,
      78,    84,     0,     0,     0,     0,    10,     0,     0,   115,
     135,   121,     0,   117,   122,   119,   120,    83,     0,    86,
       0,     0,    72,    73,     0,     0,     0,     0,     0,   136,
       0,    79,     0,    17,    25,    19,    20,    21,    40,    42,
      45,    48,    53,    56,    58,    60,    62,    64,     0,    37,
      65,    71,    70,     0,    22,    68,     0,     0,    24,    23,
      91,     0,    94,     0,    92,     0,     0,     0,   104,    15,
       0,    13,     0,     0,   109,     0,     0,     0,     0,   116,
     118,    87,    79,     0,    37,     0,    38,     0,    39,     0,
      76,     0,     0,   140,     0,   137,    18,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    33,     0,     0,     0,   132,   139,   138,
       0,    95,   134,     0,     0,     0,     0,     0,    11,     0,
     108,   110,   129,   130,   128,     0,     0,   124,   148,     0,
      74,   149,     0,    75,     0,     0,   147,   145,   142,     0,
      41,    43,    44,    46,    47,    49,    50,    51,    52,    54,
      55,    57,    59,    61,     0,    69,    72,     0,     0,   144,
       0,   133,    85,    16,    12,    14,   111,     0,     0,   123,
     125,     0,    77,     0,   146,     0,     0,     0,    66,    32,
      93,     0,     0,   126,     0,     0,    34,    36,   141,    63,
       0,     0,   127,     0,     0,     0,    27,     0,   143,    67,
     112,     0,     0,    26,    28,    35,     0,     0,     0,     0,
       0,    30,    29
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -173,  -173,   285,  -173,  -173,  -173,   140,   -85,   -91,  -173,
    -173,    60,  -173,    88,  -173,  -173,  -173,   172,    36,    37,
      19,    45,   164,   166,   167,  -173,  -173,   -78,   -52,  -173,
    -173,  -173,   113,  -173,  -173,  -173,  -173,   289,    22,  -173,
    -173,  -173,   283,   200,     6,  -173,  -173,   207,  -173,  -173,
    -173,   269,  -173,  -173,   148,  -173,  -173,  -173,    32,  -132,
    -173,  -173,  -173,  -172,  -173,  -173
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    16,    17,    18,    19,   130,   131,    92,    93,    94,
     265,   266,    95,    96,   176,    97,   256,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   144,   110,
     111,   151,    70,   112,    21,    22,    23,    50,    24,    25,
      26,    27,    57,    28,   113,    30,   133,   134,    31,    45,
      72,    73,    74,   196,   197,    75,    32,    33,   114,    53,
     115,   116,   117,   208,   118,   119
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     109,   156,   143,   192,   193,   194,    29,   147,   229,    56,
     170,     2,     3,     4,     5,     6,     7,   236,    43,   135,
     136,   123,    29,   263,     9,   264,   174,   195,    34,    51,
     234,    35,   146,    58,   148,   205,   150,   252,   129,   175,
     109,    82,    83,    36,   171,   182,    44,   237,   184,   126,
      29,    85,    37,    51,    78,    82,    83,   206,    10,   273,
     239,    58,   121,    59,    84,    85,    71,   199,    13,    14,
      15,   132,   137,    88,   204,   207,    76,   123,    29,    86,
     173,   124,   142,   125,   158,   159,   268,    88,   160,   161,
      82,    83,    60,   224,    71,   174,   142,   227,   228,    84,
      85,   153,   207,   154,    76,   126,   166,   167,   175,    41,
      46,   257,     1,    20,    86,     2,     3,     4,     5,     6,
       7,    47,    88,    82,    83,    54,     8,   179,     9,    20,
     187,   142,  -103,    85,    38,   275,    55,    52,   180,   132,
       1,   188,    63,     2,     3,     4,     5,     6,     7,    61,
     242,    62,    64,   244,     8,    88,     9,   153,   202,   154,
     209,    65,    10,    11,   142,   263,    79,   264,   259,   203,
      66,    12,    13,    14,    15,   122,   162,   163,   164,   165,
     207,   215,   216,   217,   218,   271,   254,   127,   156,   156,
      10,    11,   279,   280,   211,   212,   128,   213,   214,    12,
      13,    14,    15,    48,   129,     2,     3,     4,     5,     6,
       7,   219,   220,    39,    40,   141,   138,    48,     9,     2,
       3,     4,     5,     6,     7,   109,   109,   109,   109,   145,
     149,   152,     9,   157,    49,    67,     2,     3,     4,     5,
       6,     7,   169,   168,   172,   177,   178,   181,    68,     9,
     183,   185,    10,   186,    67,     2,     3,     4,     5,     6,
       7,   195,    13,    14,    15,   230,    10,    68,     9,   189,
     198,   200,   201,   225,   231,   232,    13,    14,    15,   233,
     238,   241,   243,    10,   248,   245,   246,    69,   247,   249,
     250,   251,   258,    13,    14,    15,   255,   260,   226,    83,
     262,    42,    10,   270,   261,   272,   139,    84,    85,   276,
     277,   267,    13,    14,    15,     2,     3,     4,     5,     6,
       7,   269,    86,    80,   278,   274,   253,   235,     9,   210,
      88,    81,   221,    82,    83,   222,    77,   223,   120,   142,
     191,   140,    84,    85,   240,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     0,     0,     0,    86,     0,     0,
       0,     9,    10,     0,    87,    88,    89,     0,     0,    90,
       0,     0,    13,    14,    91,     2,     3,     4,     5,     6,
       7,     0,     0,    80,     0,     0,     0,     0,     9,     0,
       0,    81,     0,    82,    83,    10,     0,     0,     0,   190,
       0,     0,    84,    85,     0,    13,    14,    15,     2,     3,
       4,     5,     6,     7,     0,     0,     0,    86,     0,     0,
       0,     9,    10,     0,    87,    88,   155,     0,     0,    90,
       0,     0,    13,    14,    91,     2,     3,     4,     5,     6,
       7,     0,     0,    80,     0,     0,     0,     0,     9,     0,
       0,    81,     0,    82,    83,    10,     0,     0,     0,     0,
       0,     0,    84,    85,     0,    13,    14,    15,     2,     3,
       4,     5,     6,     7,     0,     0,     0,    86,     0,     0,
       0,     9,    10,     0,    87,    88,   281,     0,     0,    90,
       0,     0,    13,    14,    91,     2,     3,     4,     5,     6,
       7,     0,     0,    80,     0,     0,     0,     0,     9,     0,
       0,    81,     0,    82,    83,    10,     0,     0,     0,     0,
       0,     0,    84,    85,     0,     0,     0,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,     0,     0,
       0,     0,    10,     0,    87,    88,   282,     0,     0,    90,
       0,     0,    13,    14,    91,     2,     3,     4,     5,     6,
       7,     0,     0,    80,     0,     0,     0,     0,     9,     0,
       0,    81,     0,    82,    83,     0,     0,     0,     0,     0,
       0,     0,    84,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,     0,     0,
       0,     0,    10,     0,    87,    88,     0,     0,     0,    90,
       0,     0,    13,    14,    91
};

static const yytype_int16 yycheck[] =
{
      52,    92,    80,   135,   136,   137,     0,    85,   180,     4,
      16,     6,     7,     8,     9,    10,    11,    28,    28,    12,
      13,    30,    16,    21,    19,    23,    45,    24,    65,    23,
      57,    36,    84,    27,    86,     4,    88,    20,    65,    58,
      92,    24,    25,    65,    50,   123,    56,    58,   126,    58,
      44,    34,    65,    47,    48,    24,    25,    26,    53,    57,
      57,    55,    56,    65,    33,    34,    44,   145,    63,    64,
      65,    65,    65,    56,   152,   153,    44,    30,    72,    48,
      30,    34,    65,    36,    32,    33,   258,    56,    42,    43,
      24,    25,    28,   171,    72,    45,    65,   175,   176,    33,
      34,    34,   180,    36,    72,    58,    51,    52,    58,     0,
      35,   243,     3,     0,    48,     6,     7,     8,     9,    10,
      11,    46,    56,    24,    25,    35,    17,    35,    19,    16,
      46,    65,    65,    34,    26,   267,    46,    56,    46,   133,
       3,    57,    24,     6,     7,     8,     9,    10,    11,    34,
     202,    36,    56,   205,    17,    56,    19,    34,    46,    36,
     154,    56,    53,    54,    65,    21,    65,    23,   246,    57,
      28,    62,    63,    64,    65,    65,    38,    39,    40,    41,
     258,   162,   163,   164,   165,   263,   238,    65,   279,   280,
      53,    54,   277,   278,   158,   159,    37,   160,   161,    62,
      63,    64,    65,     4,    65,     6,     7,     8,     9,    10,
      11,   166,   167,    13,    14,    65,    56,     4,    19,     6,
       7,     8,     9,    10,    11,   277,   278,   279,   280,    34,
      65,    34,    19,    31,    35,     5,     6,     7,     8,     9,
      10,    11,    15,    47,    28,    65,    35,    65,    18,    19,
      65,    37,    53,    30,     5,     6,     7,     8,     9,    10,
      11,    24,    63,    64,    65,    37,    53,    18,    19,    65,
      28,    35,    28,    65,    59,    34,    63,    64,    65,    24,
      29,    35,    35,    53,    59,    37,    29,    57,    29,    28,
      34,    24,    34,    63,    64,    65,    56,    24,    24,    25,
      28,    16,    53,    28,    59,    29,    57,    33,    34,    29,
      56,    61,    63,    64,    65,     6,     7,     8,     9,    10,
      11,    59,    48,    14,    56,   265,   238,   187,    19,   157,
      56,    22,   168,    24,    25,   169,    47,   170,    55,    65,
     133,    72,    33,    34,   196,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    19,    53,    -1,    55,    56,    57,    -1,    -1,    60,
      -1,    -1,    63,    64,    65,     6,     7,     8,     9,    10,
      11,    -1,    -1,    14,    -1,    -1,    -1,    -1,    19,    -1,
      -1,    22,    -1,    24,    25,    53,    -1,    -1,    -1,    57,
      -1,    -1,    33,    34,    -1,    63,    64,    65,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    19,    53,    -1,    55,    56,    57,    -1,    -1,    60,
      -1,    -1,    63,    64,    65,     6,     7,     8,     9,    10,
      11,    -1,    -1,    14,    -1,    -1,    -1,    -1,    19,    -1,
      -1,    22,    -1,    24,    25,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    63,    64,    65,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    19,    53,    -1,    55,    56,    57,    -1,    -1,    60,
      -1,    -1,    63,    64,    65,     6,     7,     8,     9,    10,
      11,    -1,    -1,    14,    -1,    -1,    -1,    -1,    19,    -1,
      -1,    22,    -1,    24,    25,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    -1,    -1,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    53,    -1,    55,    56,    57,    -1,    -1,    60,
      -1,    -1,    63,    64,    65,     6,     7,     8,     9,    10,
      11,    -1,    -1,    14,    -1,    -1,    -1,    -1,    19,    -1,
      -1,    22,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    53,    -1,    55,    56,    -1,    -1,    -1,    60,
      -1,    -1,    63,    64,    65
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,     8,     9,    10,    11,    17,    19,
      53,    54,    62,    63,    64,    65,    67,    68,    69,    70,
      98,   100,   101,   102,   104,   105,   106,   107,   109,   110,
     111,   114,   122,   123,    65,    36,    65,    65,    26,   109,
     109,     0,    68,    28,    56,   115,    35,    46,     4,    35,
     103,   110,    56,   125,    35,    46,     4,   108,   110,    65,
      28,    34,    36,    24,    56,    56,    28,     5,    18,    57,
      98,   104,   116,   117,   118,   121,   124,   103,   110,    65,
      14,    22,    24,    25,    33,    34,    48,    55,    56,    57,
      60,    65,    73,    74,    75,    78,    79,    81,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    99,   110,   124,   126,   127,   128,   130,   131,
     108,   110,    65,    30,    34,    36,    58,    65,    37,    65,
      71,    72,   110,   112,   113,    12,    13,    65,    56,    57,
     117,    65,    65,    93,    94,    34,    94,    93,    94,    65,
      94,    97,    34,    34,    36,    57,    74,    31,    32,    33,
      42,    43,    38,    39,    40,    41,    51,    52,    47,    15,
      16,    50,    28,    30,    45,    58,    80,    65,    35,    35,
      46,    65,    93,    65,    93,    37,    30,    46,    57,    65,
      57,   113,   125,   125,   125,    24,   119,   120,    28,    93,
      35,    28,    46,    57,    93,     4,    26,    93,   129,   110,
      83,    84,    84,    85,    85,    86,    86,    86,    86,    87,
      87,    88,    89,    90,    93,    65,    24,    93,    93,   129,
      37,    59,    34,    24,    57,    72,    28,    58,    29,    57,
     120,    35,    94,    35,    94,    37,    29,    29,    59,    28,
      34,    24,    20,    79,    94,    56,    82,   125,    34,    93,
      24,    59,    28,    21,    23,    76,    77,    61,   129,    59,
      28,    93,    29,    57,    77,   125,    29,    56,    56,    73,
      73,    57,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    67,    68,    68,    68,    68,    68,    68,
      69,    70,    70,    71,    71,    72,    72,    73,    73,    74,
      74,    74,    74,    74,    74,    74,    75,    76,    76,    77,
      77,    78,    79,    80,    81,    82,    82,    83,    83,    83,
      84,    84,    85,    85,    85,    86,    86,    86,    87,    87,
      87,    87,    87,    88,    88,    88,    89,    89,    90,    90,
      91,    91,    92,    92,    93,    94,    94,    94,    94,    94,
      95,    95,    95,    95,    95,    96,    97,    97,    98,    99,
     100,   100,   101,   101,   102,   102,   103,   103,   104,   105,
     106,   106,   107,   107,   108,   108,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   110,   110,   110,   111,   112,
     112,   113,   113,   114,   114,   115,   115,   116,   116,   117,
     117,   117,   117,   118,   119,   119,   120,   120,   121,   121,
     121,   122,   123,   123,   123,   124,   125,   125,   126,   126,
     127,   127,   128,   128,   128,   129,   129,   129,   130,   131
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       3,     5,     6,     1,     3,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     7,     1,     2,     6,
       5,     2,     4,     1,     5,     3,     1,     1,     2,     2,
       1,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     5,     1,     1,     4,     6,     1,     3,
       1,     1,     1,     1,     3,     3,     1,     3,     2,     1,
       2,     2,     2,     3,     3,     6,     2,     3,     2,     2,
       2,     3,     3,     6,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     2,     2,     1,     5,     1,
       2,     3,     6,     2,     2,     2,     3,     1,     2,     1,
       1,     1,     1,     4,     1,     2,     3,     4,     3,     3,
       3,     1,     2,     5,     4,     1,     2,     3,     2,     2,
       2,     5,     3,     6,     3,     1,     2,     1,     3,     3
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, ParserContext* pContext)
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, ParserContext* pContext)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, ParserContext* pContext)
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, ParserContext* pContext)
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
yyparse (ParserContext* pContext)
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
#line 177 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddModuleDef((yyval.pNode)); }
#line 1709 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 5:
#line 178 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddFunction((yyval.pNode)); }
#line 1715 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 6:
#line 179 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddImport((yyval.pNode)); }
#line 1721 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 180 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddTypeDef((yyval.pNode)); }
#line 1727 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 8:
#line 181 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddTypeDef((yyval.pNode)); }
#line 1733 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 182 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddGlobal((yyval.pNode)); }
#line 1739 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 186 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ImportStatementNode(pContext, (yyloc)); }
#line 1745 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 189 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<EnumDefinitionNode*>((yyval.pNode))->SetIdentifier((yyvsp[-3].symIndex)); }
#line 1751 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 190 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<EnumDefinitionNode*>((yyval.pNode))->SetIdentifier((yyvsp[-4].symIndex)); }
#line 1757 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 194 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new EnumDefinitionNode(pContext, (yyloc), (yyvsp[0]._EnumItem)); }
#line 1763 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 195 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<EnumDefinitionNode*>((yyval.pNode))->AddEnum((yyvsp[0]._EnumItem)); }
#line 1769 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 15:
#line 199 "VSharp.y" /* yacc.c:1661  */
    { (yyval._EnumItem) = EnumItem((yyvsp[0].symIndex)); }
#line 1775 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 200 "VSharp.y" /* yacc.c:1661  */
    { (yyval._EnumItem) = EnumItem((yyvsp[-2].symIndex), (yyvsp[0].constVal)); }
#line 1781 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 204 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 1787 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 205 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 1793 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 209 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1799 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 210 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1805 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 211 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1811 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 212 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1817 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 213 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1823 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 214 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1829 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 215 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1835 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 220 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<SwitchStatementNode*>((yyval.pNode))->SetTest((yyvsp[-4].pNode)); }
#line 1841 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 224 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new SwitchStatementNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 1847 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 225 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<SwitchStatementNode*>((yyval.pNode))->AddNode((yyvsp[0].pNode)); }
#line 1853 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 230 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new CaseStatementNode(pContext, (yyloc), (yyvsp[-4].pNode), (yyvsp[-1].pNode)); }
#line 1859 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 231 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new CaseStatementNode(pContext, (yyloc), nullptr, (yyvsp[-1].pNode)); }
#line 1865 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 235 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ExpressionStatementNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 1871 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 239 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new AssignmentNode(pContext, (yyloc), (yyvsp[-3].pNode), (yyvsp[-1].pNode)); }
#line 1877 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 248 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); dynamic_cast<IfStatementNode*>((yyval.pNode))->SetExpression((yyvsp[-2].pNode)); }
#line 1883 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 252 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IfStatementNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode)); }
#line 1889 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 253 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IfStatementNode(pContext, (yyloc), (yyvsp[0].pNode), nullptr); }
#line 1895 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 257 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1901 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 258 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new UnaryOperatorNode(pContext, (yyloc), (yyvsp[0].pNode), Operator::Negate); }
#line 1907 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 259 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new UnaryOperatorNode(pContext, (yyloc), (yyvsp[0].pNode), Operator::LogicalNot); }
#line 1913 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 40:
#line 263 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1919 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 41:
#line 264 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Multiply); }
#line 1925 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 42:
#line 268 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1931 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 269 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Add); }
#line 1937 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 44:
#line 270 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Subtract); }
#line 1943 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 274 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1949 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 275 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::ShiftLeft); }
#line 1955 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 276 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::ShiftRight); }
#line 1961 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 48:
#line 280 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1967 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 281 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LessThan); }
#line 1973 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 282 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::GreaterThan); }
#line 1979 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 283 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LessThanEqual); }
#line 1985 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 52:
#line 284 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::GreaterThanEqual); }
#line 1991 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 288 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1997 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 54:
#line 289 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Equal); }
#line 2003 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 290 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::NotEqual); }
#line 2009 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 56:
#line 294 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2015 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 295 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::BitwiseXor); }
#line 2021 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 299 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2027 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 300 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LogicalAnd); }
#line 2033 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 304 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2039 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 305 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LogicalOr); }
#line 2045 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 309 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2051 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 310 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TernaryExpressionNode(pContext, (yyloc), (yyvsp[-4].pNode), (yyvsp[-2].pNode), (yyvsp[0].pNode)); }
#line 2057 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 314 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2063 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 318 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2069 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 319 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IndexSelectionNode(pContext, (yyloc), (yyvsp[-3].pNode), (yyvsp[-1].pNode)); }
#line 2075 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 321 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new BitSelectionNode(pContext, (yyloc), (yyvsp[-5].pNode), (yyvsp[-3].constVal), (yyvsp[-1].constVal)); }
#line 2081 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 322 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2087 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 323 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FieldSelectionNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].symIndex)); }
#line 2093 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 327 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2099 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 328 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2105 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 329 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, (yyloc), (yyvsp[0].constVal)); }
#line 2111 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 330 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, (yyloc), (yyvsp[0].constVal)); }
#line 2117 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 331 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ParenNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2123 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 335 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new GlomExpressionNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2129 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 339 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 2135 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 340 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<ListNode*>((yyval.pNode))->AddNode((yyvsp[0].pNode)); }
#line 2141 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 344 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2147 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 79:
#line 348 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IdentifierNode(pContext, (yyloc), (yyvsp[0].symIndex)); }
#line 2153 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 80:
#line 352 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2159 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 81:
#line 353 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2165 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 82:
#line 357 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<ModuleDefinitionNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 2171 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 83:
#line 358 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<ModuleDefinitionNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 2177 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 84:
#line 362 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleDefinitionNode(pContext, (yyloc), (yyvsp[-1].symIndex), -1); }
#line 2183 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 85:
#line 363 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleDefinitionNode(pContext, (yyloc), (yyvsp[-4].symIndex), (yyvsp[-2].symIndex)); }
#line 2189 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 86:
#line 367 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleParameterNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), false); }
#line 2195 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 87:
#line 368 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleParameterNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), true); }
#line 2201 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 88:
#line 372 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->SetStatementList((yyvsp[0].pNode)); }
#line 2207 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 89:
#line 376 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2213 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 90:
#line 379 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 2219 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 91:
#line 380 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 2225 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 92:
#line 384 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionDeclaratorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[-1].symIndex), -1); }
#line 2231 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 93:
#line 385 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionDeclaratorNode(pContext, (yyloc), (yyvsp[-5].pNode), (yyvsp[-4].symIndex), (yyvsp[-2].symIndex)); }
#line 2237 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 94:
#line 389 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionParameterNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), false); }
#line 2243 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 95:
#line 390 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionParameterNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), true); }
#line 2249 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 96:
#line 394 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 64); }
#line 2255 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 97:
#line 395 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 32); }
#line 2261 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 98:
#line 396 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 16); }
#line 2267 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 99:
#line 397 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 8); }
#line 2273 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 100:
#line 398 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Void); }
#line 2279 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 101:
#line 399 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Clock); }
#line 2285 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 102:
#line 400 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 1); }
#line 2291 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 103:
#line 401 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Unknown, (yyvsp[0].symIndex)); }
#line 2297 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 104:
#line 402 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), (yyvsp[-1].constVal)); }
#line 2303 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 105:
#line 406 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); dynamic_cast<TypeNode*>((yyval.pNode))->SetModifier(TypeModifier::Wire); }
#line 2309 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 106:
#line 407 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); dynamic_cast<TypeNode*>((yyval.pNode))->SetModifier(TypeModifier::Const); }
#line 2315 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 107:
#line 408 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2321 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 108:
#line 412 "VSharp.y" /* yacc.c:1661  */
    {
	                                    							  (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<StructSpecifierNode*>((yyval.pNode))->SetName((yyvsp[-3].symIndex)); }
#line 2328 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 109:
#line 417 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructSpecifierNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 2334 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 110:
#line 418 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2340 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 111:
#line 422 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructDeclarationNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[-1].symIndex)); }
#line 2346 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 112:
#line 424 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructDeclarationNode(pContext, (yyloc), (yyvsp[-5].pNode), (yyvsp[-4].symIndex), (yyvsp[-2].constVal)); }
#line 2352 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 113:
#line 428 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2358 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 114:
#line 429 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<ModuleDefinitionNode*>((yyval.pNode))->SetStatementList((yyvsp[0].pNode)); }
#line 2364 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 115:
#line 433 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), nullptr); }
#line 2370 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 116:
#line 434 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2376 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 117:
#line 438 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 2382 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 118:
#line 439 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2388 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 119:
#line 443 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2394 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 120:
#line 444 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2400 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 121:
#line 445 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2406 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 122:
#line 446 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2412 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 123:
#line 450 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new DriveListDefinitionNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2418 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 124:
#line 454 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 2424 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 125:
#line 455 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2430 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 126:
#line 459 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new DriveDefinitionNode(pContext, (yyloc), (yyvsp[-2].constVal), (yyvsp[0].pNode)); }
#line 2436 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 127:
#line 460 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new DriveDefinitionNode(pContext, (yyloc), (yyvsp[-3].constVal), nullptr); }
#line 2442 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 128:
#line 464 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StateDeclaratorNode(pContext, (yyloc), (yyvsp[-1].symIndex), (yyvsp[0].pNode)); }
#line 2448 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 129:
#line 465 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StateDeclaratorNode(pContext, (yyloc), KnownStates::Initial, (yyvsp[0].pNode)); }
#line 2454 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 130:
#line 466 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StateDeclaratorNode(pContext, (yyloc), KnownStates::Always, (yyvsp[0].pNode)); }
#line 2460 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 131:
#line 470 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2466 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 132:
#line 474 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new VariableDeclarationNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), nullptr, nullptr); }
#line 2472 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 133:
#line 476 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new VariableDeclarationNode(pContext, (yyloc), (yyvsp[-4].pNode), (yyvsp[-3].symIndex), (yyvsp[-1].pNode), nullptr); }
#line 2478 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 134:
#line 477 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new VariableDeclarationNode(pContext, (yyloc), (yyvsp[-3].pNode), (yyvsp[-2].symIndex), nullptr, (yyvsp[0].pNode)); }
#line 2484 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 135:
#line 481 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2490 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 136:
#line 485 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), nullptr); }
#line 2496 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 137:
#line 486 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2502 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 138:
#line 490 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2508 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 139:
#line 491 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2514 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 140:
#line 495 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-1].symIndex), nullptr, nullptr); }
#line 2520 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 141:
#line 496 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-4].symIndex), (yyvsp[-2].pNode), nullptr); }
#line 2526 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 142:
#line 500 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-2].symIndex), nullptr, (yyvsp[0].pNode)); }
#line 2532 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 143:
#line 501 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-5].symIndex), (yyvsp[-3].pNode), (yyvsp[0].pNode)); }
#line 2538 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 144:
#line 502 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2544 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 145:
#line 506 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallParamNode(pContext, (yyloc), false, (yyvsp[0].pNode)); }
#line 2550 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 146:
#line 507 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallParamNode(pContext, (yyloc), true, (yyvsp[0].pNode)); }
#line 2556 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 147:
#line 508 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallParamNode(pContext, (yyloc)); }
#line 2562 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 148:
#line 512 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ReturnNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2568 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 149:
#line 515 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TransitionNode(pContext, (yyloc), (yyvsp[-1].symIndex)); }
#line 2574 "VSharp.tab.c" /* yacc.c:1661  */
    break;


#line 2578 "VSharp.tab.c" /* yacc.c:1661  */
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
#line 518 "VSharp.y" /* yacc.c:1906  */

