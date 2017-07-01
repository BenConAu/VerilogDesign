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

#include "PSLCompilerContext.h"
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

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MODULE_TOKEN = 258,
    OUT_TOKEN = 259,
    STATE_TOKEN = 260,
    INTCONSTANT = 261,
    FLOATCONSTANT = 262,
    BOOLCONSTANT = 263,
    REG_INDEX = 264,
    AT = 265,
    SEMICOLON = 266,
    EQUAL = 267,
    STAR = 268,
    PLUS = 269,
    MINUS = 270,
    LEFT_PAREN = 271,
    RIGHT_PAREN = 272,
    LT = 273,
    GT = 274,
    LT_OP = 275,
    GT_OP = 276,
    SHIFTLEFT = 277,
    SHIFTRIGHT = 278,
    ARROW = 279,
    DOT = 280,
    COMMA = 281,
    AMPERSAND = 282,
    EQUAL_OP = 283,
    NOTEQUAL_OP = 284,
    PTR_TOKEN = 285,
    BYTE_TOKEN = 286,
    WORD_TOKEN = 287,
    BOOL_TOKEN = 288,
    FLOAT_TOKEN = 289,
    VOID_TOKEN = 290,
    STRUCT_TOKEN = 291,
    RETURN_TOKEN = 292,
    LEFT_BRACE = 293,
    RIGHT_BRACE = 294,
    LEFT_BRACKET = 295,
    RIGHT_BRACKET = 296,
    IF_TOKEN = 297,
    ELSE_TOKEN = 298,
    WHILE_TOKEN = 299,
    NULLPTR_TOKEN = 300,
    SIZEOF_TOKEN = 301,
    OFFSETPTR_TOKEN = 302,
    CASTPTR_TOKEN = 303,
    READPORT_TOKEN = 304,
    PACKBYTE_TOKEN = 305,
    DATASEGEND_TOKEN = 306,
    SAVEREG_TOKEN = 307,
    RSP_TOKEN = 308,
    IDENTIFIER = 309
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 22 "VSharp.y" /* yacc.c:355  */

    int intVal;
    float floatVal;
    int symIndex;
    ASTNode* pNode;
    OpCode opCode;
    RegIndex regIndex;

#line 186 "VSharp.tab.c" /* yacc.c:355  */
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

#line 216 "VSharp.tab.c" /* yacc.c:358  */

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
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   328

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  209

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   137,   137,   138,   142,   143,   144,   148,   149,   153,
     154,   155,   156,   157,   158,   162,   166,   168,   173,   174,
     178,   182,   186,   187,   191,   192,   193,   197,   198,   199,
     203,   204,   205,   209,   210,   211,   215,   216,   220,   221,
     225,   229,   230,   231,   232,   233,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   252,   256,
     261,   266,   271,   275,   279,   283,   287,   288,   292,   293,
     297,   298,   302,   303,   304,   305,   306,   307,   308,   312,
     317,   318,   322,   323,   328,   332,   333,   337,   338,   342,
     343,   347,   351,   355,   356,   360,   364,   365,   369,   370,
     374,   375,   379,   380,   382,   386,   390,   394
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MODULE_TOKEN", "OUT_TOKEN",
  "STATE_TOKEN", "INTCONSTANT", "FLOATCONSTANT", "BOOLCONSTANT",
  "REG_INDEX", "AT", "SEMICOLON", "EQUAL", "STAR", "PLUS", "MINUS",
  "LEFT_PAREN", "RIGHT_PAREN", "LT", "GT", "LT_OP", "GT_OP", "SHIFTLEFT",
  "SHIFTRIGHT", "ARROW", "DOT", "COMMA", "AMPERSAND", "EQUAL_OP",
  "NOTEQUAL_OP", "PTR_TOKEN", "BYTE_TOKEN", "WORD_TOKEN", "BOOL_TOKEN",
  "FLOAT_TOKEN", "VOID_TOKEN", "STRUCT_TOKEN", "RETURN_TOKEN",
  "LEFT_BRACE", "RIGHT_BRACE", "LEFT_BRACKET", "RIGHT_BRACKET", "IF_TOKEN",
  "ELSE_TOKEN", "WHILE_TOKEN", "NULLPTR_TOKEN", "SIZEOF_TOKEN",
  "OFFSETPTR_TOKEN", "CASTPTR_TOKEN", "READPORT_TOKEN", "PACKBYTE_TOKEN",
  "DATASEGEND_TOKEN", "SAVEREG_TOKEN", "RSP_TOKEN", "IDENTIFIER",
  "$accept", "translation_unit", "external_declaration", "statement_list",
  "statement", "expression_statement", "selection_statement",
  "selection_rest_statement", "savereg_statement", "expression",
  "assignment_expression", "equality_expression", "relational_expression",
  "shift_expression", "additive_expression", "multiplicative_expression",
  "unary_expression", "assignment_operator", "postfix_expression",
  "primary_expression", "sizeof_expression", "offset_expression",
  "cast_expression", "readport_expression", "declaration",
  "variable_identifier", "module_prototype", "module_declarator",
  "module_header_with_parameters", "module_header",
  "parameter_declaration", "fully_specified_type", "struct_specifier",
  "struct_declaration_list", "struct_declaration", "module_definition",
  "module_states", "state_list", "module_member", "module_state",
  "init_declarator_list", "single_declaration", "declaration_statement",
  "compound_statement", "function_call", "function_call_header_no_param",
  "function_call_header", "jump_statement", "return_statement",
  "packbyte_statement", YY_NULLPTR
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
     305,   306,   307,   308,   309
};
# endif

#define YYPACT_NINF -130

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-130)))

#define YYTABLE_NINF -78

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,   -35,     5,  -130,  -130,  -130,  -130,  -130,   -27,  -130,
      11,  -130,  -130,    16,    22,    37,    48,    17,    64,  -130,
      81,  -130,    10,    89,    69,  -130,  -130,    98,  -130,  -130,
      48,    89,  -130,    54,    97,  -130,  -130,  -130,    56,    92,
      89,    58,  -130,  -130,   131,  -130,  -130,  -130,  -130,    59,
    -130,   225,    95,  -130,    61,   254,  -130,    87,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,   274,    72,  -130,   111,   120,
     121,   125,  -130,    46,  -130,  -130,    21,     9,    36,    52,
     129,  -130,    45,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
     127,    -4,   130,    -2,  -130,  -130,   165,  -130,   -19,  -130,
    -130,    89,    89,    89,   225,   225,    89,   225,   225,   225,
     225,   225,   225,   225,   225,   225,  -130,    91,    93,   225,
     225,  -130,  -130,   225,  -130,  -130,   143,   225,  -130,   134,
     137,   138,    87,    -6,   214,  -130,  -130,  -130,  -130,   144,
    -130,  -130,  -130,  -130,   139,   140,   141,   150,  -130,   149,
       9,   -19,     9,    36,    36,    52,    52,   129,   129,  -130,
    -130,  -130,   116,    21,  -130,   117,   158,   225,   225,   225,
    -130,  -130,  -130,  -130,  -130,   159,   160,  -130,   161,  -130,
     167,  -130,   162,   164,   156,   225,   225,   225,  -130,    87,
      87,   225,   157,   169,  -130,  -130,   145,  -130,   163,   225,
    -130,    87,   225,   170,  -130,   173,  -130,   180,  -130
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    73,    72,    76,    74,    75,     0,    77,
       0,     2,     6,     0,     0,    65,     0,     0,     0,     4,
       0,    92,     0,     0,     0,     1,     3,     0,    84,    64,
       0,     0,    66,     0,    93,     5,    62,    68,     0,     0,
       0,     0,    85,    95,     0,    87,    89,    90,    67,     0,
      70,     0,     0,    78,     0,     0,    80,     0,    86,    88,
      71,    48,    50,    49,    57,     0,     0,    51,     0,     0,
       0,     0,    52,    63,    94,    21,    22,    24,    27,    30,
      33,    36,    38,    41,    53,    54,    55,    56,    46,    43,
       0,     0,     0,     0,    79,    81,     0,    91,    39,    63,
      47,     0,     0,     0,     0,   100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    40,     0,     0,     0,
       0,    99,    98,     0,    69,    82,     0,     0,    96,     0,
       0,     0,     0,    63,     0,     7,     9,    10,    14,     0,
      11,    12,   105,    13,     0,     0,     0,     0,   102,     0,
      25,    38,    26,    28,    29,    31,    32,    34,    35,    37,
      45,    44,     0,    23,   104,     0,     0,     0,     0,     0,
      20,    97,     8,    15,    58,     0,     0,    61,     0,    42,
       0,   106,     0,     0,     0,     0,     0,   101,    83,     0,
       0,     0,     0,     0,   103,    16,    19,    17,     0,     0,
      60,     0,     0,     0,    18,     0,    59,     0,   107
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -130,  -130,   174,  -130,    60,  -130,  -130,  -130,  -130,   -51,
    -103,    73,   -34,   -33,   -22,    -9,    86,  -130,   -14,  -130,
    -130,  -130,  -130,  -130,     7,   142,  -130,  -130,  -130,  -130,
     175,   -15,  -130,  -130,   148,  -130,  -130,  -130,   181,  -130,
    -130,  -130,   -78,  -129,  -130,  -130,  -130,  -130,  -130,  -130
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,   134,   135,   136,   137,   195,   138,   139,
      75,    76,    77,    78,    79,    80,    81,   120,    82,    83,
      84,    85,    86,    87,    43,    88,    13,    14,    15,    16,
      32,    17,    18,    55,    56,    19,    28,    44,    45,    46,
      20,    21,    47,    97,    89,    90,    91,   141,   142,   143
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      74,    33,   148,   170,     1,   117,   118,    12,    39,   125,
     105,    25,   106,   122,     1,    33,    49,    12,   140,    22,
     164,   119,   123,    23,   166,    54,    37,    24,    38,   109,
     110,     2,     3,     4,     5,     6,     7,     8,   126,    29,
      54,     2,     3,     4,     5,     6,     7,     8,   -77,   107,
     108,    98,    31,   147,    27,     9,   140,   116,   111,   112,
     196,   197,   105,    30,   106,     9,   113,   114,   162,   117,
     118,    34,   204,   150,   152,    35,   153,   154,     2,     3,
       4,     5,     6,     7,   194,   119,   144,   145,   146,   155,
     156,   149,    36,   151,   151,   151,   151,   151,   151,   151,
     151,   151,     9,    41,   157,   158,   151,    40,    50,    51,
      52,    53,    57,    60,    92,    93,   182,   183,   184,     2,
       3,     4,     5,     6,     7,    96,    99,   101,     2,     3,
       4,     5,     6,     7,   192,   193,    41,    42,   102,   103,
     198,   104,   115,     9,   121,   160,   124,   161,   203,   165,
     167,   205,     9,   168,   169,   173,   174,   179,   180,   175,
     176,     2,     3,     4,     5,     6,     7,   177,   178,   181,
      58,    61,    62,    63,    64,   185,   186,   187,   188,   189,
      65,   190,   191,   199,    26,     9,   200,   206,   201,   202,
     207,   208,    66,   163,   172,     2,     3,     4,     5,     6,
       7,   159,   127,    95,   128,    48,     0,   129,   100,   130,
      67,    68,    69,    70,    71,   131,    72,   132,     0,   133,
      61,    62,    63,    64,     0,    59,     0,     0,     0,    65,
       0,    61,    62,    63,    64,     0,     0,     0,     0,     0,
      65,    66,     0,     0,     2,     3,     4,     5,     6,     7,
       0,   127,    66,   171,     0,     0,   129,     0,   130,    67,
      68,    69,    70,    71,   131,    72,   132,     0,   133,     0,
      67,    68,    69,    70,    71,     0,    72,     0,     0,    73,
      61,    62,    63,    64,     2,     3,     4,     5,     6,     7,
       0,     0,     0,    94,     0,     0,     0,     0,     0,     0,
       0,    66,     0,     0,     0,     0,     0,     0,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
      68,    69,    70,    71,     0,    72,     0,     0,    73
};

static const yytype_int16 yycheck[] =
{
      51,    16,   105,   132,     3,    24,    25,     0,    23,    11,
      16,     0,    18,    17,     3,    30,    31,    10,    96,    54,
     123,    40,    26,    18,   127,    40,    16,    54,    18,    20,
      21,    30,    31,    32,    33,    34,    35,    36,    40,    17,
      55,    30,    31,    32,    33,    34,    35,    36,    54,    28,
      29,    65,     4,   104,    38,    54,   134,    12,    22,    23,
     189,   190,    16,    26,    18,    54,    14,    15,   119,    24,
      25,    54,   201,   107,   108,    11,   109,   110,    30,    31,
      32,    33,    34,    35,   187,    40,   101,   102,   103,   111,
     112,   106,    11,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    54,     5,   113,   114,   120,    38,    54,    12,
      54,    19,    54,    54,    19,    54,   167,   168,   169,    30,
      31,    32,    33,    34,    35,    38,    54,    16,    30,    31,
      32,    33,    34,    35,   185,   186,     5,    39,    18,    18,
     191,    16,    13,    54,    17,    54,    16,    54,   199,     6,
      16,   202,    54,    16,    16,    11,    17,    41,    41,    19,
      19,    30,    31,    32,    33,    34,    35,    17,    19,    11,
      39,     6,     7,     8,     9,    16,    16,    16,    11,    17,
      15,    17,    26,    26,    10,    54,    17,    17,    43,    26,
      17,    11,    27,   120,   134,    30,    31,    32,    33,    34,
      35,   115,    37,    55,    39,    30,    -1,    42,    66,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
       6,     7,     8,     9,    -1,    44,    -1,    -1,    -1,    15,
      -1,     6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,
      15,    27,    -1,    -1,    30,    31,    32,    33,    34,    35,
      -1,    37,    27,    39,    -1,    -1,    42,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    -1,
      45,    46,    47,    48,    49,    -1,    51,    -1,    -1,    54,
       6,     7,     8,     9,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    -1,    51,    -1,    -1,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    30,    31,    32,    33,    34,    35,    36,    54,
      56,    57,    79,    81,    82,    83,    84,    86,    87,    90,
      95,    96,    54,    18,    54,     0,    57,    38,    91,    17,
      26,     4,    85,    86,    54,    11,    11,    16,    18,    86,
      38,     5,    39,    79,    92,    93,    94,    97,    85,    86,
      54,    12,    54,    19,    86,    88,    89,    54,    39,    93,
      54,     6,     7,     8,     9,    15,    27,    45,    46,    47,
      48,    49,    51,    54,    64,    65,    66,    67,    68,    69,
      70,    71,    73,    74,    75,    76,    77,    78,    80,    99,
     100,   101,    19,    54,    39,    89,    38,    98,    73,    54,
      80,    16,    18,    18,    16,    16,    18,    28,    29,    20,
      21,    22,    23,    14,    15,    13,    12,    24,    25,    40,
      72,    17,    17,    26,    16,    11,    40,    37,    39,    42,
      44,    50,    52,    54,    58,    59,    60,    61,    63,    64,
      97,   102,   103,   104,    86,    86,    86,    64,    65,    86,
      67,    73,    67,    68,    68,    69,    69,    70,    70,    71,
      54,    54,    64,    66,    65,     6,    65,    16,    16,    16,
      98,    39,    59,    11,    17,    19,    19,    17,    19,    41,
      41,    11,    64,    64,    64,    16,    16,    16,    11,    17,
      17,    26,    64,    64,    65,    62,    98,    98,    64,    26,
      17,    43,    26,    64,    98,    64,    17,    17,    11
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    56,    57,    57,    57,    58,    58,    59,
      59,    59,    59,    59,    59,    60,    61,    61,    62,    62,
      63,    64,    65,    65,    66,    66,    66,    67,    67,    67,
      68,    68,    68,    69,    69,    69,    70,    70,    71,    71,
      72,    73,    73,    73,    73,    73,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    83,    84,    84,
      85,    85,    86,    86,    86,    86,    86,    86,    86,    87,
      88,    88,    89,    89,    90,    91,    91,    92,    92,    93,
      93,    94,    95,    96,    96,    97,    98,    98,    99,    99,
     100,   100,   101,   101,   101,   102,   103,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     2,     5,     5,     3,     1,
       2,     1,     1,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     1,     2,
       1,     1,     4,     1,     3,     3,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     9,
       7,     4,     2,     1,     2,     1,     2,     3,     3,     6,
       2,     3,     1,     1,     1,     1,     1,     1,     4,     5,
       1,     2,     3,     6,     2,     2,     3,     1,     2,     1,
       1,     3,     1,     2,     4,     1,     2,     3,     2,     2,
       2,     5,     3,     6,     3,     1,     3,     9
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
#line 142 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddModuleDef((yyval.pNode)); }
#line 1582 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 5:
#line 143 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); pContext->AddStructDef((yyval.pNode)); }
#line 1588 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 6:
#line 144 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddGlobal((yyval.pNode)); }
#line 1594 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 148 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyvsp[0].pNode)); }
#line 1600 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 8:
#line 149 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 1606 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 153 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1612 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 154 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1618 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 155 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1624 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 156 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1630 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 157 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1636 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 158 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1642 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 15:
#line 162 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 1648 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 167 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); dynamic_cast<IfStatementNode*>((yyval.pNode))->SetStatementList((yyvsp[-2].pNode)); }
#line 1654 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 169 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new WhileStatementNode(pContext, (yyvsp[-2].pNode), (yyvsp[0].pNode)); }
#line 1660 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 173 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IfStatementNode(pContext, (yyvsp[-2].pNode), (yyvsp[0].pNode)); }
#line 1666 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 174 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IfStatementNode(pContext, (yyvsp[0].pNode), nullptr); }
#line 1672 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 178 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new SaveRegistersNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 1678 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 182 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1684 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 186 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1690 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 187 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new AssignmentNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode)); }
#line 1696 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 191 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1702 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 192 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Equal); }
#line 1708 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 193 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::NotEqual); }
#line 1714 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 197 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1720 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 198 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LessThan); }
#line 1726 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 199 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::GreaterThan); }
#line 1732 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 203 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1738 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 204 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::ShiftLeft); }
#line 1744 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 205 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::ShiftRight); }
#line 1750 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 209 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1756 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 210 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Add); }
#line 1762 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 211 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Subtract); }
#line 1768 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 215 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1774 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 216 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Multiply); }
#line 1780 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 220 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1786 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 221 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new UnaryOperatorNode(pContext, (yyvsp[0].pNode), Operator::Negate); }
#line 1792 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 41:
#line 229 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1798 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 42:
#line 230 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IndexSelectionNode(pContext, (yyloc), (yyvsp[-3].pNode), (yyvsp[-1].pNode)); }
#line 1804 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 231 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1810 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 44:
#line 232 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FieldSelectionNode(pContext, (yyloc), (yyvsp[-2].pNode), false, (yyvsp[0].symIndex)); }
#line 1816 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 233 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FieldSelectionNode(pContext, (yyloc), (yyvsp[-2].pNode), true, (yyvsp[0].symIndex)); }
#line 1822 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 237 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1828 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 238 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new AddressOfNode(pContext, (yyvsp[0].pNode)); }
#line 1834 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 48:
#line 239 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, ConstantNode::Word, (yyvsp[0].intVal)); }
#line 1840 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 240 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, ConstantNode::Bool, (yyvsp[0].intVal)); }
#line 1846 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 241 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, (yyvsp[0].floatVal)); }
#line 1852 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 242 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, ConstantNode::Pointer); }
#line 1858 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 52:
#line 243 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new KnownConstantNode(pContext, KnownConstants::DataSegmentEnd); }
#line 1864 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 244 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1870 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 54:
#line 245 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1876 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 246 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1882 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 56:
#line 247 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1888 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 248 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new RegisterNode(pContext, (yyloc), (yyvsp[0].regIndex)); }
#line 1894 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 252 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new SizeOfNode(pContext, (yyvsp[-1].pNode)); }
#line 1900 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 257 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OffsetNode(pContext, (yyloc), (yyvsp[-6].pNode), (yyvsp[-3].pNode), (yyvsp[-1].pNode)); }
#line 1906 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 262 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new CastNode(pContext, (yyloc), (yyvsp[-4].pNode), (yyvsp[-1].pNode)); }
#line 1912 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 267 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ReadPortNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 1918 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 271 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 1924 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 275 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IdentifierNode(pContext, (yyloc), (yyvsp[0].symIndex)); }
#line 1930 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 279 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 1936 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 283 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1942 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 287 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<ModuleDeclaratorNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 1948 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 288 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<ModuleDeclaratorNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 1954 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 292 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleDeclaratorNode(pContext, (yyvsp[-1].symIndex), -1); }
#line 1960 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 293 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleDeclaratorNode(pContext, (yyvsp[-4].symIndex), (yyvsp[-2].symIndex)); }
#line 1966 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 297 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleParameterNode(pContext, (yyvsp[-1].pNode), (yyvsp[0].symIndex), false); }
#line 1972 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 298 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleParameterNode(pContext, (yyvsp[-1].pNode), (yyvsp[0].symIndex), true); }
#line 1978 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 302 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Basic, WORD_TOKEN); }
#line 1984 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 303 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Basic, BYTE_TOKEN); }
#line 1990 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 304 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Basic, FLOAT_TOKEN); }
#line 1996 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 305 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Basic, VOID_TOKEN); }
#line 2002 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 306 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Basic, BOOL_TOKEN); }
#line 2008 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 307 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Struct, (yyvsp[0].symIndex)); }
#line 2014 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 308 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2020 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 79:
#line 312 "VSharp.y" /* yacc.c:1661  */
    {
	                                    							  (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<StructSpecifierNode*>((yyval.pNode))->SetName((yyvsp[-3].symIndex)); }
#line 2027 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 80:
#line 317 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructSpecifierNode(pContext, (yyvsp[0].pNode)); }
#line 2033 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 81:
#line 318 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2039 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 82:
#line 322 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructDeclarationNode(pContext, (yyvsp[-2].pNode), (yyvsp[-1].symIndex), -1); }
#line 2045 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 83:
#line 324 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructDeclarationNode(pContext, (yyvsp[-5].pNode), (yyvsp[-4].symIndex), (yyvsp[-2].intVal)); }
#line 2051 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 84:
#line 328 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<ModuleDeclaratorNode*>((yyval.pNode))->SetStatementList((yyvsp[0].pNode)); }
#line 2057 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 85:
#line 332 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, nullptr); }
#line 2063 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 86:
#line 333 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2069 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 87:
#line 337 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyvsp[0].pNode)); }
#line 2075 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 88:
#line 338 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2081 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 89:
#line 342 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2087 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 90:
#line 343 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2093 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 91:
#line 347 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StateDeclaratorNode(pContext, (yyloc), (yyvsp[-1].symIndex), (yyvsp[0].pNode)); }
#line 2099 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 92:
#line 351 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2105 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 93:
#line 355 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new VariableDeclarationNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), nullptr); }
#line 2111 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 94:
#line 356 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new VariableDeclarationNode(pContext, (yyloc), (yyvsp[-3].pNode), (yyvsp[-2].symIndex), (yyvsp[0].pNode)); }
#line 2117 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 95:
#line 360 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2123 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 96:
#line 364 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, nullptr); }
#line 2129 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 97:
#line 365 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2135 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 98:
#line 369 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2141 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 99:
#line 370 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2147 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 100:
#line 374 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-1].symIndex), nullptr, nullptr); }
#line 2153 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 101:
#line 375 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-4].symIndex), (yyvsp[-2].pNode), nullptr); }
#line 2159 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 102:
#line 379 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-2].symIndex), nullptr, (yyvsp[0].pNode)); }
#line 2165 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 103:
#line 381 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-5].symIndex), (yyvsp[-3].pNode), (yyvsp[0].pNode)); }
#line 2171 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 104:
#line 382 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2177 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 105:
#line 386 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2183 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 106:
#line 390 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ReturnNode(pContext, (yyvsp[-1].pNode)); }
#line 2189 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 107:
#line 395 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new PackByteNode(pContext, (yyloc), (yyvsp[-6].pNode), (yyvsp[-4].pNode), (yyvsp[-2].pNode)); }
#line 2195 "VSharp.tab.c" /* yacc.c:1661  */
    break;


#line 2199 "VSharp.tab.c" /* yacc.c:1661  */
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
#line 398 "VSharp.y" /* yacc.c:1906  */

