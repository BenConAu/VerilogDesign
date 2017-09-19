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

class ASTNode;
class ParserContext;

#line 119 "VSharp.tab.c" /* yacc.c:355  */

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
    CASE_TOKEN = 275,
    SWITCH_TOKEN = 276,
    DEFAULT_TOKEN = 277,
    INTCONSTANT = 278,
    BOOLCONSTANT = 279,
    STRINGLITERAL = 280,
    AT = 281,
    SEMICOLON = 282,
    COLON = 283,
    EQUAL = 284,
    STAR = 285,
    PLUS = 286,
    MINUS = 287,
    LEFT_PAREN = 288,
    RIGHT_PAREN = 289,
    LT = 290,
    GT = 291,
    LT_OP = 292,
    GT_OP = 293,
    LT_EQUAL_OP = 294,
    GT_EQUAL_OP = 295,
    SHIFTLEFT = 296,
    SHIFTRIGHT = 297,
    ARROW = 298,
    DOT = 299,
    COMMA = 300,
    HAT = 301,
    BANG = 302,
    AMPERSAND = 303,
    QUESTION = 304,
    EQUAL_OP = 305,
    NOTEQUAL_OP = 306,
    BOOL_TOKEN = 307,
    STRUCT_TOKEN = 308,
    TRANSITION_TOKEN = 309,
    LEFT_BRACE = 310,
    RIGHT_BRACE = 311,
    LEFT_BRACKET = 312,
    RIGHT_BRACKET = 313,
    IF_TOKEN = 314,
    ELSE_TOKEN = 315,
    IMPORT_TOKEN = 316,
    WIRE_TOKEN = 317,
    CONST_TOKEN = 318,
    IDENTIFIER = 319
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 31 "VSharp.y" /* yacc.c:355  */

    UIntConstant constVal;
    int symIndex;
    ASTNode* pNode;

#line 202 "VSharp.tab.c" /* yacc.c:355  */
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

#line 232 "VSharp.tab.c" /* yacc.c:358  */

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
#define YYFINAL  37
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   610

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  144
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  277

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   168,   168,   169,   173,   174,   175,   176,   177,   181,
     184,   185,   189,   190,   194,   195,   199,   200,   201,   202,
     203,   204,   205,   209,   214,   215,   219,   221,   225,   229,
     233,   237,   242,   243,   247,   248,   249,   253,   254,   258,
     259,   260,   264,   265,   266,   270,   271,   272,   273,   274,
     278,   279,   280,   284,   285,   289,   290,   294,   295,   299,
     300,   304,   308,   309,   310,   312,   313,   317,   318,   319,
     320,   321,   325,   329,   330,   334,   338,   342,   343,   347,
     348,   352,   353,   357,   358,   362,   366,   369,   370,   374,
     375,   379,   380,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   396,   397,   398,   402,   407,   408,   412,   413,
     418,   422,   423,   427,   428,   432,   433,   434,   435,   439,
     443,   444,   448,   449,   453,   454,   458,   462,   463,   465,
     469,   473,   474,   478,   479,   483,   484,   488,   489,   490,
     494,   495,   496,   500,   503
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
  "CLOCK_TOKEN", "FINISH_TOKEN", "CASE_TOKEN", "SWITCH_TOKEN",
  "DEFAULT_TOKEN", "INTCONSTANT", "BOOLCONSTANT", "STRINGLITERAL", "AT",
  "SEMICOLON", "COLON", "EQUAL", "STAR", "PLUS", "MINUS", "LEFT_PAREN",
  "RIGHT_PAREN", "LT", "GT", "LT_OP", "GT_OP", "LT_EQUAL_OP",
  "GT_EQUAL_OP", "SHIFTLEFT", "SHIFTRIGHT", "ARROW", "DOT", "COMMA", "HAT",
  "BANG", "AMPERSAND", "QUESTION", "EQUAL_OP", "NOTEQUAL_OP", "BOOL_TOKEN",
  "STRUCT_TOKEN", "TRANSITION_TOKEN", "LEFT_BRACE", "RIGHT_BRACE",
  "LEFT_BRACKET", "RIGHT_BRACKET", "IF_TOKEN", "ELSE_TOKEN",
  "IMPORT_TOKEN", "WIRE_TOKEN", "CONST_TOKEN", "IDENTIFIER", "$accept",
  "translation_unit", "external_declaration", "import_statement",
  "enum_definition", "enum_list", "statement_list", "statement",
  "switch_statement", "case_list", "case_statement",
  "expression_statement", "assignment_statement", "assignment_operator",
  "selection_statement", "selection_rest_statement", "unary_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression",
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
     315,   316,   317,   318,   319
};
# endif

#define YYPACT_NINF -175

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-175)))

#define YYTABLE_NINF -101

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     142,   -47,   -15,  -175,  -175,  -175,  -175,  -175,     4,  -175,
    -175,     8,    50,   128,   128,  -175,    31,  -175,  -175,  -175,
    -175,    42,    40,   168,  -175,    36,  -175,  -175,    78,  -175,
      77,    86,    61,    65,   130,  -175,  -175,  -175,  -175,   232,
    -175,  -175,   203,   401,  -175,  -175,    76,     1,  -175,  -175,
      83,   119,    95,   401,  -175,    -5,   112,  -175,  -175,  -175,
     116,    44,   218,   117,   251,  -175,  -175,  -175,  -175,  -175,
     129,  -175,   277,   277,   147,  -175,  -175,   -23,   132,   342,
    -175,   116,   116,   162,   310,  -175,  -175,   218,   401,  -175,
     137,    84,  -175,  -175,  -175,  -175,  -175,    27,   277,    27,
      27,   121,  -175,   178,    49,   120,    88,   113,   171,   204,
      -1,  -175,  -175,   -25,  -175,  -175,  -175,  -175,   185,    54,
     165,   200,   -38,  -175,    -4,  -175,  -175,  -175,  -175,   206,
     -13,  -175,   277,   211,   181,  -175,   213,    38,   369,  -175,
    -175,  -175,  -175,  -175,   208,    57,  -175,  -175,  -175,  -175,
     183,  -175,  -175,   184,   -25,   217,   -25,   -25,    59,    32,
     401,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   188,   424,  -175,  -175,
      32,  -175,  -175,  -175,  -175,  -175,   230,    43,  -175,  -175,
     227,   277,   236,   277,  -175,  -175,  -175,  -175,   277,  -175,
     228,  -175,    27,  -175,   207,  -175,  -175,  -175,   237,  -175,
     178,   178,    49,    49,   120,   120,   120,   120,    88,    88,
     113,   171,   204,   244,  -175,   246,   219,  -175,   220,   248,
    -175,    57,  -175,   242,  -175,   245,   256,   252,   -25,  -175,
    -175,   253,   277,   264,  -175,   262,  -175,   235,   116,  -175,
    -175,    32,  -175,   233,  -175,   101,  -175,   238,  -175,  -175,
     277,   265,   -11,  -175,   116,   269,   247,  -175,  -175,  -175,
     249,   546,   546,   428,   487,  -175,  -175
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    93,    94,    95,    96,    97,     0,    98,
      99,     0,     0,     0,     0,   100,     0,     2,     5,     6,
       8,     0,     0,     0,   104,     0,     7,     4,     0,   126,
       0,     0,     0,     0,     0,   102,   103,     1,     3,     0,
     110,    77,     0,     0,    78,    79,     0,   127,    75,    81,
       0,     0,     0,     0,     9,     0,     0,   111,   130,   117,
       0,     0,     0,     0,     0,   113,   118,   115,   116,    80,
       0,    83,     0,     0,     0,   101,    12,     0,     0,     0,
     106,     0,     0,     0,     0,    85,    86,     0,     0,    87,
       0,   127,   112,   114,    84,    69,    70,     0,     0,     0,
       0,    76,    37,    39,    42,    45,    50,    53,    55,    57,
      59,    61,   129,    34,    62,    68,    67,    65,     0,     0,
       0,     0,     0,    10,     0,   105,   107,   125,   124,     0,
       0,   120,     0,     0,     0,   131,     0,    76,     0,    14,
      22,    16,    17,    18,     0,    34,    19,    21,    20,    88,
       0,    91,    89,     0,    35,     0,    36,    73,     0,   135,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   134,   133,
       0,   128,    82,    11,    13,   108,     0,     0,   119,   121,
       0,     0,     0,     0,   132,    15,    28,    30,     0,    92,
       0,    71,     0,    72,     0,   142,   140,   137,     0,    38,
      40,    41,    43,    44,    46,    47,    48,    49,    51,    52,
      54,    56,    58,     0,    66,    69,     0,   139,     0,     0,
     122,     0,   143,     0,   144,     0,     0,     0,    74,    76,
     141,     0,     0,     0,    63,     0,   123,     0,     0,    29,
      90,   136,    60,     0,   109,     0,    31,    33,   138,    64,
       0,     0,     0,    24,     0,     0,     0,    23,    25,    32,
       0,     0,     0,     0,     0,    27,    26
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -175,  -175,   276,  -175,  -175,  -175,  -106,  -130,  -175,  -175,
      37,  -175,   118,  -175,  -175,  -175,   145,     7,    33,   -36,
      29,   136,   138,   148,  -175,  -175,   -69,   -84,  -175,  -175,
    -175,    12,   108,  -175,  -175,  -175,   283,  -175,  -175,  -175,
    -175,   239,   202,   -18,  -175,  -175,   250,  -175,  -175,  -175,
     263,  -175,  -175,   205,  -175,  -175,  -175,   -12,   -80,  -175,
    -175,  -175,  -174,  -175,  -175
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    16,    17,    18,    19,    77,   138,   139,   140,   262,
     263,   141,   142,   198,   143,   256,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   144,   113,   114,   115,
     158,    58,   116,    21,    22,    23,    45,    59,    60,    61,
      62,    89,    24,    25,    26,    79,    80,    27,    40,    64,
      65,    66,   130,   131,    67,    28,    29,   146,    85,   117,
     118,   119,   207,   147,   148
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     145,   127,   128,   112,   120,    46,   227,    81,   195,   260,
     129,   261,    20,   154,   174,   156,   157,    30,   183,   176,
      31,    63,   122,   185,    46,    70,   184,    68,    20,   155,
      72,    37,   177,   123,     1,    78,   204,     2,     3,     4,
       5,     6,     7,   188,    90,   267,    63,     8,   175,     9,
      95,    96,    68,   186,   145,    95,    96,   205,    73,    82,
      98,    78,   229,   190,    97,    98,    95,    96,    32,    90,
     150,   159,    33,   160,    41,    34,    98,   258,    86,    99,
     162,   163,   100,    10,    11,    42,   197,   100,   179,    87,
     206,   101,    12,    13,    14,    15,   101,    39,   100,   180,
      47,   176,  -100,   231,   202,    48,   223,   101,   226,    51,
      49,   206,    50,    72,   177,   203,    52,   152,   238,   153,
      53,   260,   233,   261,   235,   166,   167,   168,   169,   236,
     214,   215,   216,   217,     2,     3,     4,     5,     6,     7,
      71,    73,   208,   195,   195,     1,     9,    74,     2,     3,
       4,     5,     6,     7,   159,    75,   160,    54,     8,    76,
       9,   164,   165,   170,   171,   273,   274,    83,   257,   210,
     211,    84,    43,   252,     2,     3,     4,     5,     6,     7,
      10,    91,   206,   121,   269,   129,     9,   145,   145,   145,
     145,   265,    15,    94,    10,    11,   124,   212,   213,   218,
     219,   151,    44,    12,    13,    14,    15,    43,   161,     2,
       3,     4,     5,     6,     7,    35,    36,   172,   173,   178,
      10,     9,    88,   181,     2,     3,     4,     5,     6,     7,
      13,    14,    15,   182,   187,   196,     9,    55,     2,     3,
       4,     5,     6,     7,   191,   192,   193,   199,   200,    56,
       9,   201,   224,   228,   232,    10,    55,     2,     3,     4,
       5,     6,     7,   234,   237,    13,    14,    15,    56,     9,
      10,   239,   242,   241,   243,   246,   247,   244,   245,   248,
      13,    14,    15,   249,    10,   250,   251,   253,    57,   254,
     255,   259,    38,   266,    13,    14,    15,   270,   264,   268,
      95,    96,   271,    10,   272,   230,   209,    92,   220,    97,
      98,   221,   240,    13,    14,    15,     2,     3,     4,     5,
       6,     7,   222,   132,    99,    69,   149,    93,     9,   126,
       0,   133,   100,    95,    96,   189,     0,     0,     0,     0,
       0,   101,    97,    98,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     0,     0,     0,    99,     0,     0,
       9,     0,    10,     0,   134,   100,   135,     0,     0,   136,
       0,     0,    13,    14,   137,     2,     3,     4,     5,     6,
       7,     0,   132,     0,     0,     0,     0,     9,     0,     0,
     133,     0,    95,    96,    10,     0,     0,     0,   125,     0,
       0,    97,    98,     0,    13,    14,    15,     2,     3,     4,
       5,     6,     7,     0,     0,     0,    99,     0,     0,     9,
       0,    10,     0,   134,   100,   194,     0,     0,   136,     0,
       0,    13,    14,   137,     2,     3,     4,     5,     6,     7,
       0,   132,     0,     0,     0,     0,     9,   225,    96,   133,
       0,    95,    96,    10,     0,     0,    97,    98,     0,     0,
      97,    98,     0,    13,    14,    15,     0,     0,     0,     0,
       0,    99,     0,     0,     0,    99,     0,     0,     0,   100,
      10,     0,   134,   100,   275,     0,     0,   136,   101,     0,
      13,    14,   137,     2,     3,     4,     5,     6,     7,     0,
     132,     0,     0,     0,     0,     9,     0,     0,   133,     0,
      95,    96,     0,     0,     0,     0,     0,     0,     0,    97,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    99,     0,     0,     0,     0,    10,
       0,   134,   100,   276,     0,     0,   136,     0,     0,    13,
      14,   137,     2,     3,     4,     5,     6,     7,     0,   132,
       0,     0,     0,     0,     9,     0,     0,   133,     0,    95,
      96,     0,     0,     0,     0,     0,     0,     0,    97,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    99,     0,     0,     0,     0,    10,     0,
     134,   100,     0,     0,     0,   136,     0,     0,    13,    14,
     137
};

static const yytype_int16 yycheck[] =
{
      84,    81,    82,    72,    73,    23,   180,    12,   138,    20,
      23,    22,     0,    97,    15,    99,   100,    64,    56,    44,
      35,    39,    45,    27,    42,    43,    64,    39,    16,    98,
      29,     0,    57,    56,     3,    53,     4,     6,     7,     8,
       9,    10,    11,    56,    62,    56,    64,    16,    49,    18,
      23,    24,    64,    57,   138,    23,    24,    25,    57,    64,
      33,    79,    19,   132,    32,    33,    23,    24,    64,    87,
      88,    33,    64,    35,    34,    25,    33,   251,    34,    47,
      31,    32,    55,    52,    53,    45,    29,    55,    34,    45,
     159,    64,    61,    62,    63,    64,    64,    55,    55,    45,
      64,    44,    64,   187,    45,    27,   175,    64,   177,    23,
      33,   180,    35,    29,    57,    56,    55,    33,   202,    35,
      55,    20,   191,    22,   193,    37,    38,    39,    40,   198,
     166,   167,   168,   169,     6,     7,     8,     9,    10,    11,
      64,    57,   160,   273,   274,     3,    18,    64,     6,     7,
       8,     9,    10,    11,    33,    36,    35,    27,    16,    64,
      18,    41,    42,    50,    51,   271,   272,    55,   248,   162,
     163,    55,     4,   242,     6,     7,     8,     9,    10,    11,
      52,    64,   251,    36,   264,    23,    18,   271,   272,   273,
     274,   260,    64,    64,    52,    53,    64,   164,   165,   170,
     171,    64,    34,    61,    62,    63,    64,     4,    30,     6,
       7,     8,     9,    10,    11,    13,    14,    46,    14,    34,
      52,    18,     4,    58,     6,     7,     8,     9,    10,    11,
      62,    63,    64,    33,    28,    27,    18,     5,     6,     7,
       8,     9,    10,    11,    33,    64,    33,    64,    64,    17,
      18,    34,    64,    23,    27,    52,     5,     6,     7,     8,
       9,    10,    11,    27,    36,    62,    63,    64,    17,    18,
      52,    64,    28,    36,    28,    27,    34,    58,    58,    34,
      62,    63,    64,    27,    52,    33,    33,    23,    56,    27,
      55,    58,    16,    28,    62,    63,    64,    28,    60,   262,
      23,    24,    55,    52,    55,   187,   161,    56,   172,    32,
      33,   173,   204,    62,    63,    64,     6,     7,     8,     9,
      10,    11,   174,    13,    47,    42,    87,    64,    18,    79,
      -1,    21,    55,    23,    24,   130,    -1,    -1,    -1,    -1,
      -1,    64,    32,    33,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    47,    -1,    -1,
      18,    -1,    52,    -1,    54,    55,    56,    -1,    -1,    59,
      -1,    -1,    62,    63,    64,     6,     7,     8,     9,    10,
      11,    -1,    13,    -1,    -1,    -1,    -1,    18,    -1,    -1,
      21,    -1,    23,    24,    52,    -1,    -1,    -1,    56,    -1,
      -1,    32,    33,    -1,    62,    63,    64,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    47,    -1,    -1,    18,
      -1,    52,    -1,    54,    55,    56,    -1,    -1,    59,    -1,
      -1,    62,    63,    64,     6,     7,     8,     9,    10,    11,
      -1,    13,    -1,    -1,    -1,    -1,    18,    23,    24,    21,
      -1,    23,    24,    52,    -1,    -1,    32,    33,    -1,    -1,
      32,    33,    -1,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    47,    -1,    -1,    -1,    55,
      52,    -1,    54,    55,    56,    -1,    -1,    59,    64,    -1,
      62,    63,    64,     6,     7,     8,     9,    10,    11,    -1,
      13,    -1,    -1,    -1,    -1,    18,    -1,    -1,    21,    -1,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    52,
      -1,    54,    55,    56,    -1,    -1,    59,    -1,    -1,    62,
      63,    64,     6,     7,     8,     9,    10,    11,    -1,    13,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    21,    -1,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    52,    -1,
      54,    55,    -1,    -1,    -1,    59,    -1,    -1,    62,    63,
      64
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,     8,     9,    10,    11,    16,    18,
      52,    53,    61,    62,    63,    64,    66,    67,    68,    69,
      96,    98,    99,   100,   107,   108,   109,   112,   120,   121,
      64,    35,    64,    64,    25,   107,   107,     0,    67,    55,
     113,    34,    45,     4,    34,   101,   108,    64,    27,    33,
      35,    23,    55,    55,    27,     5,    17,    56,    96,   102,
     103,   104,   105,   108,   114,   115,   116,   119,   122,   101,
     108,    64,    29,    57,    64,    36,    64,    70,   108,   110,
     111,    12,    64,    55,    55,   123,    34,    45,     4,   106,
     108,    64,    56,   115,    64,    23,    24,    32,    33,    47,
      55,    64,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    97,   124,   125,   126,
      91,    36,    45,    56,    64,    56,   111,   123,   123,    23,
     117,   118,    13,    21,    54,    56,    59,    64,    71,    72,
      73,    76,    77,    79,    91,    92,   122,   128,   129,   106,
     108,    64,    33,    35,    92,    91,    92,    92,    95,    33,
      35,    30,    31,    32,    41,    42,    37,    38,    39,    40,
      50,    51,    46,    14,    15,    49,    44,    57,    34,    34,
      45,    58,    33,    56,    64,    27,    57,    28,    56,   118,
      91,    33,    64,    33,    56,    72,    27,    29,    78,    64,
      64,    34,    45,    56,     4,    25,    91,   127,   108,    81,
      82,    82,    83,    83,    84,    84,    84,    84,    85,    85,
      86,    87,    88,    91,    64,    23,    91,   127,    23,    19,
      77,    92,    27,    91,    27,    91,    91,    36,    92,    64,
      97,    36,    28,    28,    58,    58,    27,    34,    34,    27,
      33,    33,    91,    23,    27,    55,    80,   123,   127,    58,
      20,    22,    74,    75,    60,    91,    28,    56,    75,   123,
      28,    55,    55,    71,    71,    56,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    66,    67,    67,    67,    67,    67,    68,
      69,    69,    70,    70,    71,    71,    72,    72,    72,    72,
      72,    72,    72,    73,    74,    74,    75,    75,    76,    77,
      78,    79,    80,    80,    81,    81,    81,    82,    82,    83,
      83,    83,    84,    84,    84,    85,    85,    85,    85,    85,
      86,    86,    86,    87,    87,    88,    88,    89,    89,    90,
      90,    91,    92,    92,    92,    92,    92,    93,    93,    93,
      93,    93,    94,    95,    95,    96,    97,    98,    98,    99,
      99,   100,   100,   101,   101,   102,   103,   104,   104,   105,
     105,   106,   106,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   108,   108,   108,   109,   110,   110,   111,   111,
     112,   113,   113,   114,   114,   115,   115,   115,   115,   116,
     117,   117,   118,   118,   119,   119,   120,   121,   121,   121,
     122,   123,   123,   124,   124,   125,   125,   126,   126,   126,
     127,   127,   127,   128,   129
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       5,     6,     1,     3,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     7,     1,     2,     6,     5,     2,     4,
       1,     5,     3,     1,     1,     2,     2,     1,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     1,     4,     6,     1,     3,     1,     1,     1,
       1,     3,     3,     1,     3,     2,     1,     2,     2,     2,
       3,     3,     6,     2,     3,     2,     2,     2,     3,     3,
       6,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     2,     2,     1,     5,     1,     2,     3,     6,
       2,     2,     3,     1,     2,     1,     1,     1,     1,     4,
       1,     2,     3,     4,     3,     3,     1,     2,     5,     4,
       1,     2,     3,     2,     2,     2,     5,     3,     6,     3,
       1,     2,     1,     3,     3
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
#line 173 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddModuleDef((yyval.pNode)); }
#line 1702 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 5:
#line 174 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddImport((yyval.pNode)); }
#line 1708 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 6:
#line 175 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddTypeDef((yyval.pNode)); }
#line 1714 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 176 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddTypeDef((yyval.pNode)); }
#line 1720 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 8:
#line 177 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddGlobal((yyval.pNode)); }
#line 1726 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 181 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ImportStatementNode(pContext, (yyloc)); }
#line 1732 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 184 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<EnumDefinitionNode*>((yyval.pNode))->SetIdentifier((yyvsp[-3].symIndex)); }
#line 1738 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 185 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<EnumDefinitionNode*>((yyval.pNode))->SetIdentifier((yyvsp[-4].symIndex)); }
#line 1744 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 189 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new EnumDefinitionNode(pContext, (yyloc), (yyvsp[0].symIndex)); }
#line 1750 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 190 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<EnumDefinitionNode*>((yyval.pNode))->AddEnum((yyvsp[0].symIndex)); }
#line 1756 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 194 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 1762 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 15:
#line 195 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 1768 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 199 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1774 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 200 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1780 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 201 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1786 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 202 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1792 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 203 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1798 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 204 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1804 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 205 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1810 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 210 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<SwitchStatementNode*>((yyval.pNode))->SetTest((yyvsp[-4].pNode)); }
#line 1816 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 214 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new SwitchStatementNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 1822 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 215 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<SwitchStatementNode*>((yyval.pNode))->AddNode((yyvsp[0].pNode)); }
#line 1828 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 220 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new CaseStatementNode(pContext, (yyloc), (yyvsp[-4].pNode), (yyvsp[-1].pNode)); }
#line 1834 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 221 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new CaseStatementNode(pContext, (yyloc), nullptr, (yyvsp[-1].pNode)); }
#line 1840 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 225 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ExpressionStatementNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 1846 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 229 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new AssignmentNode(pContext, (yyloc), (yyvsp[-3].pNode), (yyvsp[-1].pNode)); }
#line 1852 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 238 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); dynamic_cast<IfStatementNode*>((yyval.pNode))->SetExpression((yyvsp[-2].pNode)); }
#line 1858 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 242 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IfStatementNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode)); }
#line 1864 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 243 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IfStatementNode(pContext, (yyloc), (yyvsp[0].pNode), nullptr); }
#line 1870 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 247 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1876 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 248 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new UnaryOperatorNode(pContext, (yyloc), (yyvsp[0].pNode), Operator::Negate); }
#line 1882 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 249 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new UnaryOperatorNode(pContext, (yyloc), (yyvsp[0].pNode), Operator::LogicalNot); }
#line 1888 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 253 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1894 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 254 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Multiply); }
#line 1900 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 258 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1906 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 40:
#line 259 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Add); }
#line 1912 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 41:
#line 260 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Subtract); }
#line 1918 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 42:
#line 264 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1924 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 265 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::ShiftLeft); }
#line 1930 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 44:
#line 266 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::ShiftRight); }
#line 1936 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 270 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1942 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 271 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LessThan); }
#line 1948 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 272 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::GreaterThan); }
#line 1954 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 48:
#line 273 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LessThanEqual); }
#line 1960 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 274 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::GreaterThanEqual); }
#line 1966 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 278 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1972 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 279 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Equal); }
#line 1978 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 52:
#line 280 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::NotEqual); }
#line 1984 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 284 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1990 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 54:
#line 285 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::BitwiseXor); }
#line 1996 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 289 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2002 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 56:
#line 290 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LogicalAnd); }
#line 2008 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 294 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2014 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 295 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LogicalOr); }
#line 2020 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 299 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2026 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 300 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TernaryExpressionNode(pContext, (yyloc), (yyvsp[-4].pNode), (yyvsp[-2].pNode), (yyvsp[0].pNode)); }
#line 2032 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 304 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2038 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 308 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2044 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 309 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IndexSelectionNode(pContext, (yyloc), (yyvsp[-3].pNode), (yyvsp[-1].pNode)); }
#line 2050 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 311 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new BitSelectionNode(pContext, (yyloc), (yyvsp[-5].pNode), (yyvsp[-3].constVal), (yyvsp[-1].constVal)); }
#line 2056 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 312 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2062 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 313 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FieldSelectionNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].symIndex)); }
#line 2068 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 317 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2074 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 318 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2080 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 319 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, (yyloc), (yyvsp[0].constVal)); }
#line 2086 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 320 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, (yyloc), (yyvsp[0].constVal)); }
#line 2092 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 321 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ParenNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2098 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 325 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new GlomExpressionNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2104 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 329 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 2110 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 330 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<ListNode*>((yyval.pNode))->AddNode((yyvsp[0].pNode)); }
#line 2116 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 334 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2122 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 338 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IdentifierNode(pContext, (yyloc), (yyvsp[0].symIndex)); }
#line 2128 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 342 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2134 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 343 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2140 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 79:
#line 347 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<ModuleDefinitionNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 2146 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 80:
#line 348 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<ModuleDefinitionNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 2152 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 81:
#line 352 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleDefinitionNode(pContext, (yyloc), (yyvsp[-1].symIndex), -1); }
#line 2158 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 82:
#line 353 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleDefinitionNode(pContext, (yyloc), (yyvsp[-4].symIndex), (yyvsp[-2].symIndex)); }
#line 2164 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 83:
#line 357 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleParameterNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), false); }
#line 2170 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 84:
#line 358 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleParameterNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), true); }
#line 2176 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 85:
#line 362 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->SetStatementList((yyvsp[0].pNode)); }
#line 2182 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 86:
#line 366 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2188 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 87:
#line 369 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 2194 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 88:
#line 370 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 2200 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 89:
#line 374 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionDeclaratorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[-1].symIndex), -1); }
#line 2206 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 90:
#line 375 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionDeclaratorNode(pContext, (yyloc), (yyvsp[-5].pNode), (yyvsp[-4].symIndex), (yyvsp[-2].symIndex)); }
#line 2212 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 91:
#line 379 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionParameterNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), false); }
#line 2218 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 92:
#line 380 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionParameterNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), true); }
#line 2224 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 93:
#line 384 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 64); }
#line 2230 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 94:
#line 385 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 32); }
#line 2236 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 95:
#line 386 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 16); }
#line 2242 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 96:
#line 387 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 8); }
#line 2248 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 97:
#line 388 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Void); }
#line 2254 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 98:
#line 389 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Clock); }
#line 2260 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 99:
#line 390 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 1); }
#line 2266 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 100:
#line 391 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Unknown, (yyvsp[0].symIndex)); }
#line 2272 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 101:
#line 392 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), (yyvsp[-1].constVal)); }
#line 2278 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 102:
#line 396 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); dynamic_cast<TypeNode*>((yyval.pNode))->SetModifier(TypeModifier::Wire); }
#line 2284 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 103:
#line 397 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); dynamic_cast<TypeNode*>((yyval.pNode))->SetModifier(TypeModifier::Const); }
#line 2290 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 104:
#line 398 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2296 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 105:
#line 402 "VSharp.y" /* yacc.c:1661  */
    {
	                                    							  (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<StructSpecifierNode*>((yyval.pNode))->SetName((yyvsp[-3].symIndex)); }
#line 2303 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 106:
#line 407 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructSpecifierNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 2309 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 107:
#line 408 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2315 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 108:
#line 412 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructDeclarationNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[-1].symIndex)); }
#line 2321 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 109:
#line 414 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructDeclarationNode(pContext, (yyloc), (yyvsp[-5].pNode), (yyvsp[-4].symIndex), (yyvsp[-2].constVal)); }
#line 2327 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 110:
#line 418 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<ModuleDefinitionNode*>((yyval.pNode))->SetStatementList((yyvsp[0].pNode)); }
#line 2333 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 111:
#line 422 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), nullptr); }
#line 2339 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 112:
#line 423 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2345 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 113:
#line 427 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 2351 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 114:
#line 428 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2357 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 115:
#line 432 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2363 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 116:
#line 433 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2369 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 117:
#line 434 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2375 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 118:
#line 435 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2381 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 119:
#line 439 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new DriveListDefinitionNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2387 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 120:
#line 443 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 2393 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 121:
#line 444 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2399 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 122:
#line 448 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new DriveDefinitionNode(pContext, (yyloc), (yyvsp[-2].constVal), (yyvsp[0].pNode)); }
#line 2405 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 123:
#line 449 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new DriveDefinitionNode(pContext, (yyloc), (yyvsp[-3].constVal), nullptr); }
#line 2411 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 124:
#line 453 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StateDeclaratorNode(pContext, (yyloc), (yyvsp[-1].symIndex), (yyvsp[0].pNode)); }
#line 2417 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 125:
#line 454 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StateDeclaratorNode(pContext, (yyloc), -1, (yyvsp[0].pNode)); }
#line 2423 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 126:
#line 458 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2429 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 127:
#line 462 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new VariableDeclarationNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), nullptr, nullptr); }
#line 2435 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 128:
#line 464 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new VariableDeclarationNode(pContext, (yyloc), (yyvsp[-4].pNode), (yyvsp[-3].symIndex), (yyvsp[-1].pNode), nullptr); }
#line 2441 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 129:
#line 465 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new VariableDeclarationNode(pContext, (yyloc), (yyvsp[-3].pNode), (yyvsp[-2].symIndex), nullptr, (yyvsp[0].pNode)); }
#line 2447 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 130:
#line 469 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2453 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 131:
#line 473 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), nullptr); }
#line 2459 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 132:
#line 474 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2465 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 133:
#line 478 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2471 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 134:
#line 479 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2477 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 135:
#line 483 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-1].symIndex), nullptr, nullptr); }
#line 2483 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 136:
#line 484 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-4].symIndex), (yyvsp[-2].pNode), nullptr); }
#line 2489 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 137:
#line 488 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-2].symIndex), nullptr, (yyvsp[0].pNode)); }
#line 2495 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 138:
#line 489 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-5].symIndex), (yyvsp[-3].pNode), (yyvsp[0].pNode)); }
#line 2501 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 139:
#line 490 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2507 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 140:
#line 494 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallParamNode(pContext, (yyloc), false, (yyvsp[0].pNode)); }
#line 2513 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 141:
#line 495 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallParamNode(pContext, (yyloc), true, (yyvsp[0].pNode)); }
#line 2519 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 142:
#line 496 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallParamNode(pContext, (yyloc)); }
#line 2525 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 143:
#line 500 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ReturnNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2531 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 144:
#line 503 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TransitionNode(pContext, (yyloc), (yyvsp[-1].symIndex)); }
#line 2537 "VSharp.tab.c" /* yacc.c:1661  */
    break;


#line 2541 "VSharp.tab.c" /* yacc.c:1661  */
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
#line 506 "VSharp.y" /* yacc.c:1906  */

