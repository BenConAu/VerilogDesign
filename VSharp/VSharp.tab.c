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
    SLASH = 287,
    PLUS = 288,
    MINUS = 289,
    LEFT_PAREN = 290,
    RIGHT_PAREN = 291,
    LT = 292,
    GT = 293,
    LT_OP = 294,
    GT_OP = 295,
    LT_EQUAL_OP = 296,
    GT_EQUAL_OP = 297,
    SHIFTLEFT = 298,
    SHIFTRIGHT = 299,
    ARROW = 300,
    DOT = 301,
    COMMA = 302,
    HAT = 303,
    BANG = 304,
    BAR = 305,
    AMPERSAND = 306,
    QUESTION = 307,
    EQUAL_OP = 308,
    NOTEQUAL_OP = 309,
    BOOL_TOKEN = 310,
    STRUCT_TOKEN = 311,
    TRANSITION_TOKEN = 312,
    LEFT_BRACE = 313,
    RIGHT_BRACE = 314,
    LEFT_BRACKET = 315,
    RIGHT_BRACKET = 316,
    IF_TOKEN = 317,
    ELSE_TOKEN = 318,
    IMPORT_TOKEN = 319,
    WIRE_TOKEN = 320,
    CONST_TOKEN = 321,
    IDENTIFIER = 322
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

#line 207 "VSharp.tab.c" /* yacc.c:355  */
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

#line 237 "VSharp.tab.c" /* yacc.c:358  */

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
#define YYLAST   632

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  152
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  287

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   322

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
      65,    66,    67
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   175,   175,   176,   180,   181,   182,   183,   184,   185,
     189,   192,   193,   197,   198,   202,   203,   207,   208,   212,
     213,   214,   215,   216,   217,   218,   222,   227,   228,   232,
     234,   238,   242,   246,   250,   255,   256,   260,   261,   262,
     266,   267,   268,   272,   273,   274,   278,   279,   280,   284,
     285,   286,   287,   288,   292,   293,   294,   298,   299,   303,
     304,   308,   309,   313,   314,   318,   319,   323,   327,   328,
     329,   331,   332,   336,   337,   338,   339,   340,   344,   348,
     349,   353,   357,   361,   362,   366,   367,   371,   372,   376,
     377,   381,   385,   388,   389,   393,   394,   398,   399,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   415,   416,
     417,   421,   426,   427,   431,   432,   437,   438,   442,   443,
     447,   448,   452,   453,   454,   455,   459,   463,   464,   468,
     469,   473,   474,   475,   479,   483,   484,   486,   490,   494,
     495,   499,   500,   504,   505,   509,   510,   511,   515,   516,
     517,   521,   524
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
  "STRINGLITERAL", "AT", "SEMICOLON", "COLON", "EQUAL", "STAR", "SLASH",
  "PLUS", "MINUS", "LEFT_PAREN", "RIGHT_PAREN", "LT", "GT", "LT_OP",
  "GT_OP", "LT_EQUAL_OP", "GT_EQUAL_OP", "SHIFTLEFT", "SHIFTRIGHT",
  "ARROW", "DOT", "COMMA", "HAT", "BANG", "BAR", "AMPERSAND", "QUESTION",
  "EQUAL_OP", "NOTEQUAL_OP", "BOOL_TOKEN", "STRUCT_TOKEN",
  "TRANSITION_TOKEN", "LEFT_BRACE", "RIGHT_BRACE", "LEFT_BRACKET",
  "RIGHT_BRACKET", "IF_TOKEN", "ELSE_TOKEN", "IMPORT_TOKEN", "WIRE_TOKEN",
  "CONST_TOKEN", "IDENTIFIER", "$accept", "translation_unit",
  "external_declaration", "import_statement", "enum_definition",
  "enum_list", "enum_item", "statement_list", "statement",
  "switch_statement", "case_list", "case_statement",
  "expression_statement", "assignment_statement", "assignment_operator",
  "selection_statement", "selection_rest_statement", "unary_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "expression", "postfix_expression",
  "primary_expression", "glom_expression", "glom_list", "declaration",
  "variable_identifier", "module_prototype",
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
     315,   316,   317,   318,   319,   320,   321,   322
};
# endif

#define YYPACT_NINF -165

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-165)))

#define YYTABLE_NINF -107

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     143,   -46,    12,  -165,  -165,  -165,  -165,  -165,    -9,  -165,
    -165,     2,    26,   401,   401,  -165,    65,  -165,  -165,  -165,
    -165,   -21,    43,   157,  -165,    28,    59,    32,  -165,    25,
    -165,  -165,    82,  -165,    -7,   437,    60,    66,   117,  -165,
    -165,  -165,  -165,  -165,   237,  -165,  -165,   173,   350,  -165,
    -165,    71,   317,  -165,  -165,    32,   350,  -165,    81,    48,
    -165,  -165,    92,  -165,  -165,    22,   437,    22,    22,    76,
    -165,    96,   110,   126,    94,   119,   130,   139,   189,    -8,
    -165,   175,    21,  -165,  -165,  -165,  -165,   178,    79,   144,
     350,  -165,    -1,   161,  -165,  -165,  -165,   255,  -165,  -165,
    -165,  -165,  -165,   148,  -165,   437,   186,   158,  -165,   194,
     -12,   379,  -165,  -165,  -165,  -165,  -165,   207,    77,   169,
    -165,  -165,  -165,  -165,   170,  -165,   437,  -165,   437,   437,
     211,    21,   215,    21,    21,    53,   192,   437,   437,   437,
     437,   437,   437,   437,   437,   437,   437,   437,   437,   437,
     437,   437,   437,   437,   437,  -165,   185,   437,  -165,  -165,
     192,   224,    58,  -165,   200,   278,  -165,    28,    28,    28,
     245,  -165,  -165,  -165,   242,   437,   243,   437,  -165,  -165,
    -165,  -165,   437,   -15,  -165,  -165,   234,   214,   241,  -165,
      22,  -165,    22,  -165,  -165,  -165,   239,  -165,  -165,    96,
      96,   110,   110,   126,   126,   126,   126,    94,    94,   119,
     130,   139,   189,   249,  -165,    -2,  -165,   256,   -33,  -165,
       4,  -165,  -165,  -165,  -165,  -165,   250,   -11,  -165,  -165,
     246,  -165,   247,   253,   258,  -165,  -165,    21,    21,   259,
     437,   437,  -165,  -165,  -165,  -165,  -165,   266,   233,  -165,
    -165,   240,    28,  -165,  -165,   192,  -165,   238,   244,   267,
    -165,    77,    93,  -165,   248,  -165,  -165,   273,  -165,   437,
     277,    -3,  -165,    28,  -165,   279,   251,  -165,  -165,  -165,
     254,   565,   565,   441,   503,  -165,  -165
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    99,   100,   101,   102,   103,     0,   104,
     105,     0,     0,     0,     0,   106,     0,     2,     6,     7,
       9,     0,     0,     0,     5,     0,     0,     0,   110,     0,
       8,     4,     0,   134,     0,     0,     0,     0,     0,   108,
     109,     1,     3,   116,     0,   117,    83,     0,     0,    84,
      85,     0,     0,    91,    92,     0,     0,    93,     0,   135,
      81,    87,     0,    75,    76,     0,     0,     0,     0,    82,
      40,    43,    46,    49,    54,    57,    59,    61,    63,    65,
      67,     0,    37,    68,    74,    73,    71,     0,     0,     0,
       0,    10,     0,     0,   118,   138,   124,     0,   120,   125,
     122,   123,    86,     0,    89,     0,     0,     0,   139,     0,
      82,     0,    17,    25,    19,    20,    21,     0,    37,     0,
      22,    24,    23,    94,     0,    97,     0,    95,     0,     0,
       0,    38,     0,    39,    79,     0,   143,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   107,     0,     0,   142,   141,
       0,    15,     0,    13,     0,     0,   112,     0,     0,     0,
       0,   119,   121,    90,     0,     0,     0,     0,   140,    18,
      31,    33,     0,   135,    98,   137,     0,     0,     0,    77,
       0,    78,     0,   150,   148,   145,     0,    41,    42,    44,
      45,    47,    48,    50,    51,    52,    53,    55,    56,    58,
      60,    62,    64,     0,    72,     0,   147,     0,     0,    11,
       0,   111,   113,   132,   133,   131,     0,     0,   127,   151,
       0,   152,     0,     0,     0,   136,    88,    80,   149,     0,
       0,     0,    69,    16,    12,    14,   114,     0,     0,   126,
     128,     0,     0,    32,    96,   144,    66,     0,     0,     0,
     129,     0,     0,    34,    36,   146,    70,     0,   130,     0,
       0,     0,    27,     0,   115,     0,     0,    26,    28,    35,
       0,     0,     0,     0,     0,    30,    29
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -165,  -165,   291,  -165,  -165,  -165,    95,   -96,  -109,  -165,
    -165,    44,  -165,    68,  -165,  -165,  -165,    49,    50,    52,
      11,    54,   167,   168,   166,   176,  -165,  -165,   -35,   -51,
    -165,  -165,  -165,    19,  -165,  -165,  -165,  -165,   283,   -34,
    -165,  -165,  -165,   280,   187,     6,  -165,  -165,   181,  -165,
    -165,  -165,   235,  -165,  -165,   107,  -165,  -165,  -165,   -20,
    -164,  -165,  -165,  -165,  -151,  -165,  -165
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    16,    17,    18,    19,   162,   163,   111,   112,   113,
     271,   272,   114,   115,   182,   116,   263,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,   117,    82,
      83,    84,   135,    95,    85,    21,    22,    23,    50,    24,
      25,    26,    27,    57,    28,   119,    30,   165,   166,    31,
      45,    97,    98,    99,   227,   228,   100,    32,    33,   120,
      53,    86,    87,    88,   195,   121,   122
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      81,   118,   179,   223,   224,   225,    29,    43,   153,   216,
      96,   167,   168,   226,   131,   126,   133,   134,   269,    20,
     270,    34,    29,   136,   101,   137,   244,   241,    61,    51,
      62,   132,   246,    58,   161,    20,    56,    44,     2,     3,
       4,     5,     6,     7,   154,   129,    63,    64,   249,    35,
      29,     9,    38,    51,   103,  -106,   277,    66,    36,   242,
     118,    58,   124,    96,   247,    41,   169,   156,     1,    37,
     174,     2,     3,     4,     5,     6,     7,   101,   126,    46,
      68,   157,     8,   127,     9,   128,    52,    10,   264,    69,
      47,   185,    59,   186,   187,    54,   164,    13,    14,    15,
     190,   194,   196,    29,   265,   218,    55,   181,   129,   279,
      60,   136,   191,   137,   269,   159,   270,   219,    89,   213,
      10,    11,   215,   156,    90,   194,   160,   138,   139,    12,
      13,    14,    15,   144,   145,   146,   147,   157,   104,   237,
     230,   238,   232,   140,   141,    91,     1,   233,   125,     2,
       3,     4,     5,     6,     7,   203,   204,   205,   206,   130,
       8,    48,     9,     2,     3,     4,     5,     6,     7,   142,
     143,   164,   148,   149,   179,   179,     9,    48,   150,     2,
       3,     4,     5,     6,     7,   283,   284,   197,   198,   151,
     199,   200,     9,    49,   201,   202,   192,   261,    10,    11,
      39,    40,   207,   208,   152,   256,   257,    12,    13,    14,
      15,   161,    10,   155,   158,   173,    63,    64,   193,   170,
     194,   175,    13,    14,    15,   176,    65,    66,    10,   177,
     118,   118,   118,   118,   275,   180,   183,   184,    13,    14,
      15,    67,    92,     2,     3,     4,     5,     6,     7,   188,
      68,   189,   214,   259,   217,    93,     9,    63,    64,    69,
      92,     2,     3,     4,     5,     6,     7,   220,    66,   226,
     229,   231,   234,    93,     9,   235,   236,   239,   240,   248,
     243,   253,   251,   252,     2,     3,     4,     5,     6,     7,
     258,    68,    10,   254,   255,   268,    94,     9,   262,   266,
      69,   274,    13,    14,    15,   267,   276,    42,   280,   281,
      10,   273,   282,   245,   171,   278,   260,   209,   211,   210,
      13,    14,    15,     2,     3,     4,     5,     6,     7,   212,
     102,   105,   172,    10,   250,   123,     9,   221,     0,   106,
       0,    63,    64,    13,    14,    15,   222,     0,     0,     0,
       0,    65,    66,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     0,     0,     0,     0,    67,     0,     0,     9,
       0,     0,    10,     0,   107,    68,   108,     0,     0,   109,
       0,     0,    13,    14,   110,     2,     3,     4,     5,     6,
       7,     0,     0,   105,     0,     0,     0,     0,     9,     0,
       0,   106,     0,    63,    64,    10,     0,     2,     3,     4,
       5,     6,     7,    65,    66,    13,    14,    15,     0,     0,
       9,     0,     0,     0,     0,     0,     0,     0,    67,     0,
       0,     0,     0,     0,    10,     0,   107,    68,   178,     0,
       0,   109,     0,     0,    13,    14,   110,     2,     3,     4,
       5,     6,     7,     0,     0,   105,    10,     0,     0,     0,
       9,    63,    64,   106,     0,    63,    64,     0,    15,     0,
       0,    65,    66,     0,     0,    65,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    67,     0,     0,     0,
      67,     0,     0,     0,     0,    68,    10,     0,   107,    68,
     285,     0,     0,   109,    69,     0,    13,    14,   110,     2,
       3,     4,     5,     6,     7,     0,     0,   105,     0,     0,
       0,     0,     9,     0,     0,   106,     0,    63,    64,     0,
       0,     0,     0,     0,     0,     0,     0,    65,    66,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,     0,     0,     0,     0,     0,    10,     0,
     107,    68,   286,     0,     0,   109,     0,     0,    13,    14,
     110,     2,     3,     4,     5,     6,     7,     0,     0,   105,
       0,     0,     0,     0,     9,     0,     0,   106,     0,    63,
      64,     0,     0,     0,     0,     0,     0,     0,     0,    65,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,     0,     0,     0,     0,     0,
      10,     0,   107,    68,     0,     0,     0,   109,     0,     0,
      13,    14,   110
};

static const yytype_int16 yycheck[] =
{
      35,    52,   111,   167,   168,   169,     0,    28,    16,   160,
      44,    12,    13,    24,    65,    30,    67,    68,    21,     0,
      23,    67,    16,    35,    44,    37,    59,    29,    35,    23,
      37,    66,    28,    27,    67,    16,     4,    58,     6,     7,
       8,     9,    10,    11,    52,    60,    24,    25,    59,    37,
      44,    19,    26,    47,    48,    67,    59,    35,    67,    61,
     111,    55,    56,    97,    60,     0,    67,    46,     3,    67,
     105,     6,     7,     8,     9,    10,    11,    97,    30,    36,
      58,    60,    17,    35,    19,    37,    58,    55,   252,    67,
      47,   126,    67,   128,   129,    36,    90,    65,    66,    67,
      47,   136,   137,    97,   255,    47,    47,    30,    60,   273,
      28,    35,    59,    37,    21,    36,    23,    59,    58,   154,
      55,    56,   157,    46,    58,   160,    47,    31,    32,    64,
      65,    66,    67,    39,    40,    41,    42,    60,    67,   190,
     175,   192,   177,    33,    34,    28,     3,   182,    67,     6,
       7,     8,     9,    10,    11,   144,   145,   146,   147,    67,
      17,     4,    19,     6,     7,     8,     9,    10,    11,    43,
      44,   165,    53,    54,   283,   284,    19,     4,    48,     6,
       7,     8,     9,    10,    11,   281,   282,   138,   139,    50,
     140,   141,    19,    36,   142,   143,     4,   248,    55,    56,
      13,    14,   148,   149,    15,   240,   241,    64,    65,    66,
      67,    67,    55,    38,    36,    67,    24,    25,    26,    58,
     255,    35,    65,    66,    67,    67,    34,    35,    55,    35,
     281,   282,   283,   284,   269,    28,    67,    67,    65,    66,
      67,    49,     5,     6,     7,     8,     9,    10,    11,    38,
      58,    36,    67,    20,    30,    18,    19,    24,    25,    67,
       5,     6,     7,     8,     9,    10,    11,    67,    35,    24,
      28,    28,    38,    18,    19,    61,    35,    38,    29,    29,
      24,    28,    36,    36,     6,     7,     8,     9,    10,    11,
      24,    58,    55,    35,    35,    28,    59,    19,    58,    61,
      67,    28,    65,    66,    67,    61,    29,    16,    29,    58,
      55,    63,    58,   218,    59,   271,   248,   150,   152,   151,
      65,    66,    67,     6,     7,     8,     9,    10,    11,   153,
      47,    14,    97,    55,   227,    55,    19,    59,    -1,    22,
      -1,    24,    25,    65,    66,    67,   165,    -1,    -1,    -1,
      -1,    34,    35,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    49,    -1,    -1,    19,
      -1,    -1,    55,    -1,    57,    58,    59,    -1,    -1,    62,
      -1,    -1,    65,    66,    67,     6,     7,     8,     9,    10,
      11,    -1,    -1,    14,    -1,    -1,    -1,    -1,    19,    -1,
      -1,    22,    -1,    24,    25,    55,    -1,     6,     7,     8,
       9,    10,    11,    34,    35,    65,    66,    67,    -1,    -1,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    57,    58,    59,    -1,
      -1,    62,    -1,    -1,    65,    66,    67,     6,     7,     8,
       9,    10,    11,    -1,    -1,    14,    55,    -1,    -1,    -1,
      19,    24,    25,    22,    -1,    24,    25,    -1,    67,    -1,
      -1,    34,    35,    -1,    -1,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    58,    55,    -1,    57,    58,
      59,    -1,    -1,    62,    67,    -1,    65,    66,    67,     6,
       7,     8,     9,    10,    11,    -1,    -1,    14,    -1,    -1,
      -1,    -1,    19,    -1,    -1,    22,    -1,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      57,    58,    59,    -1,    -1,    62,    -1,    -1,    65,    66,
      67,     6,     7,     8,     9,    10,    11,    -1,    -1,    14,
      -1,    -1,    -1,    -1,    19,    -1,    -1,    22,    -1,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      55,    -1,    57,    58,    -1,    -1,    -1,    62,    -1,    -1,
      65,    66,    67
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,     8,     9,    10,    11,    17,    19,
      55,    56,    64,    65,    66,    67,    69,    70,    71,    72,
     101,   103,   104,   105,   107,   108,   109,   110,   112,   113,
     114,   117,   125,   126,    67,    37,    67,    67,    26,   112,
     112,     0,    70,    28,    58,   118,    36,    47,     4,    36,
     106,   113,    58,   128,    36,    47,     4,   111,   113,    67,
      28,    35,    37,    24,    25,    34,    35,    49,    58,    67,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   102,   129,   130,   131,    58,
      58,    28,     5,    18,    59,   101,   107,   119,   120,   121,
     124,   127,   106,   113,    67,    14,    22,    57,    59,    62,
      67,    75,    76,    77,    80,    81,    83,    96,    97,   113,
     127,   133,   134,   111,   113,    67,    30,    35,    37,    60,
      67,    97,    96,    97,    97,   100,    35,    37,    31,    32,
      33,    34,    43,    44,    39,    40,    41,    42,    53,    54,
      48,    50,    15,    16,    52,    38,    46,    60,    36,    36,
      47,    67,    73,    74,   113,   115,   116,    12,    13,    67,
      58,    59,   120,    67,    96,    35,    67,    35,    59,    76,
      28,    30,    82,    67,    67,    96,    96,    96,    38,    36,
      47,    59,     4,    26,    96,   132,    96,    85,    85,    86,
      86,    87,    87,    88,    88,    88,    88,    89,    89,    90,
      91,    92,    93,    96,    67,    96,   132,    30,    47,    59,
      67,    59,   116,   128,   128,   128,    24,   122,   123,    28,
      96,    28,    96,    96,    38,    61,    35,    97,    97,    38,
      29,    29,    61,    24,    59,    74,    28,    60,    29,    59,
     123,    36,    36,    28,    35,    35,    96,    96,    24,    20,
      81,    97,    58,    84,   128,   132,    61,    61,    28,    21,
      23,    78,    79,    63,    28,    96,    29,    59,    79,   128,
      29,    58,    58,    75,    75,    59,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    68,    69,    69,    70,    70,    70,    70,    70,    70,
      71,    72,    72,    73,    73,    74,    74,    75,    75,    76,
      76,    76,    76,    76,    76,    76,    77,    78,    78,    79,
      79,    80,    81,    82,    83,    84,    84,    85,    85,    85,
      86,    86,    86,    87,    87,    87,    88,    88,    88,    89,
      89,    89,    89,    89,    90,    90,    90,    91,    91,    92,
      92,    93,    93,    94,    94,    95,    95,    96,    97,    97,
      97,    97,    97,    98,    98,    98,    98,    98,    99,   100,
     100,   101,   102,   103,   103,   104,   104,   105,   105,   106,
     106,   107,   108,   109,   109,   110,   110,   111,   111,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   113,   113,
     113,   114,   115,   115,   116,   116,   117,   117,   118,   118,
     119,   119,   120,   120,   120,   120,   121,   122,   122,   123,
     123,   124,   124,   124,   125,   126,   126,   126,   127,   128,
     128,   129,   129,   130,   130,   131,   131,   131,   132,   132,
     132,   133,   134
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       3,     5,     6,     1,     3,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     7,     1,     2,     6,
       5,     2,     4,     1,     5,     3,     1,     1,     2,     2,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     5,     1,     1,     4,
       6,     1,     3,     1,     1,     1,     1,     3,     3,     1,
       3,     2,     1,     2,     2,     2,     3,     3,     6,     2,
       3,     2,     2,     2,     3,     3,     6,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     2,     2,
       1,     5,     1,     2,     3,     6,     2,     2,     2,     3,
       1,     2,     1,     1,     1,     1,     4,     1,     2,     3,
       4,     3,     3,     3,     1,     2,     5,     4,     1,     2,
       3,     2,     2,     2,     5,     3,     6,     3,     1,     2,
       1,     3,     3
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
#line 180 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddModuleDef((yyval.pNode)); }
#line 1720 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 5:
#line 181 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddFunction((yyval.pNode)); }
#line 1726 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 6:
#line 182 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddImport((yyval.pNode)); }
#line 1732 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 183 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddTypeDef((yyval.pNode)); }
#line 1738 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 8:
#line 184 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddTypeDef((yyval.pNode)); }
#line 1744 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 185 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddGlobal((yyval.pNode)); }
#line 1750 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 189 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ImportStatementNode(pContext, (yyloc)); }
#line 1756 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 192 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<EnumDefinitionNode*>((yyval.pNode))->SetIdentifier((yyvsp[-3].symIndex)); }
#line 1762 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 193 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<EnumDefinitionNode*>((yyval.pNode))->SetIdentifier((yyvsp[-4].symIndex)); }
#line 1768 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 197 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new EnumDefinitionNode(pContext, (yyloc), (yyvsp[0]._EnumItem)); }
#line 1774 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 198 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<EnumDefinitionNode*>((yyval.pNode))->AddEnum((yyvsp[0]._EnumItem)); }
#line 1780 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 15:
#line 202 "VSharp.y" /* yacc.c:1661  */
    { (yyval._EnumItem) = EnumItem((yyvsp[0].symIndex)); }
#line 1786 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 203 "VSharp.y" /* yacc.c:1661  */
    { (yyval._EnumItem) = EnumItem((yyvsp[-2].symIndex), (yyvsp[0].constVal)); }
#line 1792 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 207 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 1798 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 208 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 1804 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 212 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1810 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 213 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1816 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 214 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1822 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 215 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1828 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 216 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1834 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 217 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1840 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 218 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1846 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 223 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<SwitchStatementNode*>((yyval.pNode))->SetTest((yyvsp[-4].pNode)); }
#line 1852 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 227 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new SwitchStatementNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 1858 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 228 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<SwitchStatementNode*>((yyval.pNode))->AddNode((yyvsp[0].pNode)); }
#line 1864 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 233 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new CaseStatementNode(pContext, (yyloc), (yyvsp[-4].pNode), (yyvsp[-1].pNode)); }
#line 1870 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 234 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new CaseStatementNode(pContext, (yyloc), nullptr, (yyvsp[-1].pNode)); }
#line 1876 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 238 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ExpressionStatementNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 1882 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 242 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new AssignmentNode(pContext, (yyloc), (yyvsp[-3].pNode), (yyvsp[-1].pNode)); }
#line 1888 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 251 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); dynamic_cast<IfStatementNode*>((yyval.pNode))->SetExpression((yyvsp[-2].pNode)); }
#line 1894 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 255 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IfStatementNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode)); }
#line 1900 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 256 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IfStatementNode(pContext, (yyloc), (yyvsp[0].pNode), nullptr); }
#line 1906 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 260 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1912 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 261 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new UnaryOperatorNode(pContext, (yyloc), (yyvsp[0].pNode), Operator::Negate); }
#line 1918 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 262 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new UnaryOperatorNode(pContext, (yyloc), (yyvsp[0].pNode), Operator::LogicalNot); }
#line 1924 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 40:
#line 266 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1930 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 41:
#line 267 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Multiply); }
#line 1936 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 42:
#line 268 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Divide); }
#line 1942 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 272 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1948 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 44:
#line 273 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Add); }
#line 1954 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 274 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Subtract); }
#line 1960 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 278 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1966 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 279 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::ShiftLeft); }
#line 1972 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 48:
#line 280 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::ShiftRight); }
#line 1978 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 284 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1984 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 285 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LessThan); }
#line 1990 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 286 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::GreaterThan); }
#line 1996 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 52:
#line 287 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LessThanEqual); }
#line 2002 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 288 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::GreaterThanEqual); }
#line 2008 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 54:
#line 292 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2014 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 293 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Equal); }
#line 2020 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 56:
#line 294 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::NotEqual); }
#line 2026 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 298 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2032 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 299 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::BitwiseXor); }
#line 2038 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 303 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2044 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 304 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::BitwiseOr); }
#line 2050 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 308 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2056 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 309 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LogicalAnd); }
#line 2062 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 313 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2068 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 314 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LogicalOr); }
#line 2074 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 318 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2080 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 319 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TernaryExpressionNode(pContext, (yyloc), (yyvsp[-4].pNode), (yyvsp[-2].pNode), (yyvsp[0].pNode)); }
#line 2086 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 323 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2092 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 327 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2098 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 328 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IndexSelectionNode(pContext, (yyloc), (yyvsp[-3].pNode), (yyvsp[-1].pNode)); }
#line 2104 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 330 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new BitSelectionNode(pContext, (yyloc), (yyvsp[-5].pNode), (yyvsp[-3].pNode), (yyvsp[-1].pNode)); }
#line 2110 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 331 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2116 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 332 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FieldSelectionNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].symIndex)); }
#line 2122 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 336 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2128 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 337 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2134 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 338 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, (yyloc), (yyvsp[0].constVal)); }
#line 2140 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 339 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, (yyloc), (yyvsp[0].constVal)); }
#line 2146 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 340 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ParenNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2152 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 344 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new GlomExpressionNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2158 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 79:
#line 348 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 2164 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 80:
#line 349 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<ListNode*>((yyval.pNode))->AddNode((yyvsp[0].pNode)); }
#line 2170 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 81:
#line 353 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2176 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 82:
#line 357 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IdentifierNode(pContext, (yyloc), (yyvsp[0].symIndex)); }
#line 2182 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 83:
#line 361 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2188 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 84:
#line 362 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2194 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 85:
#line 366 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<ModuleDefinitionNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 2200 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 86:
#line 367 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<ModuleDefinitionNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 2206 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 87:
#line 371 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleDefinitionNode(pContext, (yyloc), (yyvsp[-1].symIndex), -1); }
#line 2212 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 88:
#line 372 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleDefinitionNode(pContext, (yyloc), (yyvsp[-4].symIndex), (yyvsp[-2].symIndex)); }
#line 2218 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 89:
#line 376 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleParameterNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), false); }
#line 2224 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 90:
#line 377 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleParameterNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), true); }
#line 2230 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 91:
#line 381 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->SetStatementList((yyvsp[0].pNode)); }
#line 2236 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 92:
#line 385 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2242 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 93:
#line 388 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 2248 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 94:
#line 389 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 2254 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 95:
#line 393 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionDeclaratorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[-1].symIndex), nullptr); }
#line 2260 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 96:
#line 394 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionDeclaratorNode(pContext, (yyloc), (yyvsp[-5].pNode), (yyvsp[-4].symIndex), (yyvsp[-2].pNode)); }
#line 2266 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 97:
#line 398 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionParameterNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), false); }
#line 2272 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 98:
#line 399 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionParameterNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), true); }
#line 2278 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 99:
#line 403 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 64); }
#line 2284 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 100:
#line 404 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 32); }
#line 2290 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 101:
#line 405 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 16); }
#line 2296 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 102:
#line 406 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 8); }
#line 2302 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 103:
#line 407 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Void); }
#line 2308 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 104:
#line 408 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Clock); }
#line 2314 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 105:
#line 409 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 1); }
#line 2320 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 106:
#line 410 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Unknown, (yyvsp[0].symIndex)); }
#line 2326 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 107:
#line 411 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2332 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 108:
#line 415 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); dynamic_cast<TypeNode*>((yyval.pNode))->SetModifier(TypeModifier::Wire); }
#line 2338 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 109:
#line 416 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); dynamic_cast<TypeNode*>((yyval.pNode))->SetModifier(TypeModifier::Const); }
#line 2344 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 110:
#line 417 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2350 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 111:
#line 421 "VSharp.y" /* yacc.c:1661  */
    {
	                                    							  (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<StructSpecifierNode*>((yyval.pNode))->SetName((yyvsp[-3].symIndex)); }
#line 2357 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 112:
#line 426 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructSpecifierNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 2363 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 113:
#line 427 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2369 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 114:
#line 431 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructDeclarationNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[-1].symIndex)); }
#line 2375 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 115:
#line 433 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructDeclarationNode(pContext, (yyloc), (yyvsp[-5].pNode), (yyvsp[-4].symIndex), (yyvsp[-2].constVal)); }
#line 2381 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 116:
#line 437 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2387 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 117:
#line 438 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<ModuleDefinitionNode*>((yyval.pNode))->SetStatementList((yyvsp[0].pNode)); }
#line 2393 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 118:
#line 442 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), nullptr); }
#line 2399 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 119:
#line 443 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2405 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 120:
#line 447 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 2411 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 121:
#line 448 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2417 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 122:
#line 452 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2423 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 123:
#line 453 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2429 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 124:
#line 454 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2435 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 125:
#line 455 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2441 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 126:
#line 459 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new DriveListDefinitionNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2447 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 127:
#line 463 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 2453 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 128:
#line 464 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2459 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 129:
#line 468 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new DriveDefinitionNode(pContext, (yyloc), (yyvsp[-2].constVal), (yyvsp[0].pNode)); }
#line 2465 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 130:
#line 469 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new DriveDefinitionNode(pContext, (yyloc), (yyvsp[-3].constVal), nullptr); }
#line 2471 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 131:
#line 473 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StateDeclaratorNode(pContext, (yyloc), (yyvsp[-1].symIndex), (yyvsp[0].pNode)); }
#line 2477 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 132:
#line 474 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StateDeclaratorNode(pContext, (yyloc), KnownStates::Initial, (yyvsp[0].pNode)); }
#line 2483 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 133:
#line 475 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StateDeclaratorNode(pContext, (yyloc), KnownStates::Always, (yyvsp[0].pNode)); }
#line 2489 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 134:
#line 479 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2495 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 135:
#line 483 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new VariableDeclarationNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), nullptr, nullptr); }
#line 2501 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 136:
#line 485 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new VariableDeclarationNode(pContext, (yyloc), (yyvsp[-4].pNode), (yyvsp[-3].symIndex), (yyvsp[-1].pNode), nullptr); }
#line 2507 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 137:
#line 486 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new VariableDeclarationNode(pContext, (yyloc), (yyvsp[-3].pNode), (yyvsp[-2].symIndex), nullptr, (yyvsp[0].pNode)); }
#line 2513 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 138:
#line 490 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2519 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 139:
#line 494 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), nullptr); }
#line 2525 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 140:
#line 495 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2531 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 141:
#line 499 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2537 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 142:
#line 500 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2543 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 143:
#line 504 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-1].symIndex), nullptr, nullptr); }
#line 2549 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 144:
#line 505 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-4].symIndex), (yyvsp[-2].pNode), nullptr); }
#line 2555 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 145:
#line 509 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-2].symIndex), nullptr, (yyvsp[0].pNode)); }
#line 2561 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 146:
#line 510 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-5].symIndex), (yyvsp[-3].pNode), (yyvsp[0].pNode)); }
#line 2567 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 147:
#line 511 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2573 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 148:
#line 515 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallParamNode(pContext, (yyloc), false, (yyvsp[0].pNode)); }
#line 2579 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 149:
#line 516 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallParamNode(pContext, (yyloc), true, (yyvsp[0].pNode)); }
#line 2585 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 150:
#line 517 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallParamNode(pContext, (yyloc)); }
#line 2591 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 151:
#line 521 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ReturnNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2597 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 152:
#line 524 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TransitionNode(pContext, (yyloc), (yyvsp[-1].symIndex)); }
#line 2603 "VSharp.tab.c" /* yacc.c:1661  */
    break;


#line 2607 "VSharp.tab.c" /* yacc.c:1661  */
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
#line 527 "VSharp.y" /* yacc.c:1906  */

