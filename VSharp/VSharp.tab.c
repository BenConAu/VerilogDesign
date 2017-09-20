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
#line 32 "VSharp.y" /* yacc.c:355  */

    UIntConstant constVal;
    int symIndex;
    ASTNode* pNode;
    EnumItem _EnumItem;

#line 204 "VSharp.tab.c" /* yacc.c:355  */
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

#line 234 "VSharp.tab.c" /* yacc.c:358  */

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
#define YYLAST   620

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  66
/* YYNRULES -- Number of rules.  */
#define YYNRULES  148
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  281

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
       0,   171,   171,   172,   176,   177,   178,   179,   180,   181,
     185,   188,   189,   193,   194,   198,   199,   203,   204,   208,
     209,   210,   211,   212,   213,   214,   218,   223,   224,   228,
     230,   234,   238,   242,   246,   251,   252,   256,   257,   258,
     262,   263,   267,   268,   269,   273,   274,   275,   279,   280,
     281,   282,   283,   287,   288,   289,   293,   294,   298,   299,
     303,   304,   308,   309,   313,   317,   318,   319,   321,   322,
     326,   327,   328,   329,   330,   334,   338,   339,   343,   347,
     351,   352,   356,   357,   361,   362,   366,   367,   371,   375,
     378,   379,   383,   384,   388,   389,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   405,   406,   407,   411,   416,
     417,   421,   422,   427,   428,   432,   433,   437,   438,   442,
     443,   444,   445,   449,   453,   454,   458,   459,   463,   464,
     468,   472,   473,   475,   479,   483,   484,   488,   489,   493,
     494,   498,   499,   500,   504,   505,   506,   510,   513
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
  "enum_definition", "enum_list", "enum_item", "statement_list",
  "statement", "switch_statement", "case_list", "case_statement",
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

#define YYPACT_NINF -174

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-174)))

#define YYTABLE_NINF -104

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     136,   -54,     0,  -174,  -174,  -174,  -174,  -174,    24,  -174,
    -174,    34,    68,   411,   411,  -174,    54,  -174,  -174,  -174,
    -174,    12,    -3,   151,  -174,    70,    44,   198,  -174,    89,
    -174,  -174,   140,  -174,    79,   148,   108,   124,   167,  -174,
    -174,  -174,  -174,  -174,   259,  -174,  -174,   223,   113,  -174,
    -174,   137,   320,  -174,  -174,   198,   113,  -174,   146,    51,
    -174,  -174,   153,   186,   171,   113,  -174,     5,   181,  -174,
    -174,  -174,   284,  -174,  -174,  -174,  -174,  -174,   173,  -174,
      -9,   205,  -174,  -174,    71,    -9,    71,   175,    71,  -174,
     209,    -8,   379,  -174,  -174,  -174,  -174,  -174,  -174,   210,
     101,   -13,    90,    87,   197,   230,    -6,  -174,   218,    56,
    -174,  -174,  -174,   182,  -174,  -174,   217,    45,  -174,  -174,
    -174,   188,  -174,    -9,  -174,   189,    -9,   219,  -174,   225,
      31,  -174,   194,   298,  -174,    70,    70,   236,  -174,  -174,
    -174,   135,   245,   -24,    -9,   -24,   229,   -24,   246,   -24,
      46,    -9,   224,   113,  -174,  -174,    -9,    -9,    -9,    -9,
      -9,    -9,    -9,    -9,    -9,    -9,    -9,    -9,    -9,    -9,
      -9,  -174,  -174,   214,   117,    -9,    42,  -174,  -174,   224,
    -174,  -174,   238,   222,   248,   260,    47,  -174,   -16,  -174,
    -174,  -174,  -174,   254,    26,  -174,  -174,   250,  -174,  -174,
      71,  -174,   262,    71,  -174,  -174,  -174,   261,  -174,   210,
     210,   101,   101,   -13,   -13,   -13,   -13,    90,    90,    87,
     197,   230,   270,  -174,   271,   242,   276,  -174,   277,  -174,
    -174,  -174,  -174,  -174,  -174,   289,   -11,  -174,  -174,   258,
     -24,    70,   -24,   281,    -9,   294,  -174,  -174,  -174,   266,
     291,  -174,    56,   160,  -174,   265,   224,  -174,   274,   292,
    -174,    -9,   306,    -4,  -174,    70,  -174,  -174,  -174,   307,
     282,  -174,  -174,  -174,   287,   556,   556,   438,   497,  -174,
    -174
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    96,    97,    98,    99,   100,     0,   101,
     102,     0,     0,     0,     0,   103,     0,     2,     6,     7,
       9,     0,     0,     0,     5,     0,     0,     0,   107,     0,
       8,     4,     0,   130,     0,     0,     0,     0,     0,   105,
     106,     1,     3,   113,     0,   114,    80,     0,     0,    81,
      82,     0,     0,    88,    89,     0,     0,    90,     0,   131,
      78,    84,     0,     0,     0,     0,    10,     0,     0,   115,
     134,   121,     0,   117,   122,   119,   120,    83,     0,    86,
       0,     0,    72,    73,     0,     0,     0,     0,     0,   135,
       0,    79,     0,    17,    25,    19,    20,    21,    40,    42,
      45,    48,    53,    56,    58,    60,    62,    64,     0,    37,
      65,    71,    70,     0,    22,    68,     0,     0,    24,    23,
      91,     0,    94,     0,    92,     0,     0,     0,   104,    15,
       0,    13,     0,     0,   109,     0,     0,     0,   116,   118,
      87,    79,     0,    37,     0,    38,     0,    39,     0,    76,
       0,     0,   139,     0,   136,    18,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,    33,     0,     0,     0,   131,   138,   137,     0,
      95,   133,     0,     0,     0,     0,     0,    11,     0,   108,
     110,   129,   128,     0,     0,   124,   147,     0,    74,   148,
       0,    75,     0,     0,   146,   144,   141,     0,    41,    43,
      44,    46,    47,    49,    50,    51,    52,    54,    55,    57,
      59,    61,     0,    69,    72,     0,     0,   143,     0,   132,
      85,    16,    12,    14,   111,     0,     0,   123,   125,     0,
      77,     0,   145,     0,     0,     0,    66,    32,    93,     0,
       0,   126,     0,     0,    34,    36,   140,    63,     0,     0,
     127,     0,     0,     0,    27,     0,   142,    67,   112,     0,
       0,    26,    28,    35,     0,     0,     0,     0,     0,    30,
      29
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -174,  -174,   304,  -174,  -174,  -174,   159,  -102,   -91,  -174,
    -174,    76,  -174,   115,  -174,  -174,  -174,   193,    38,    52,
      29,    53,   190,   187,   195,  -174,  -174,   -78,   -52,  -174,
    -174,  -174,    21,  -174,  -174,  -174,  -174,   309,    33,  -174,
    -174,  -174,   303,   207,     3,  -174,  -174,   226,  -174,  -174,
    -174,   293,  -174,  -174,   169,  -174,  -174,  -174,    37,  -131,
    -174,  -174,  -174,  -173,  -174,  -174
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    16,    17,    18,    19,   130,   131,    92,    93,    94,
     263,   264,    95,    96,   175,    97,   254,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   143,   110,
     111,   150,    70,   112,    21,    22,    23,    50,    24,    25,
      26,    27,    57,    28,   113,    30,   133,   134,    31,    45,
      72,    73,    74,   194,   195,    75,    32,    33,   114,    53,
     115,   116,   117,   206,   118,   119
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     109,   155,   142,    29,   191,   192,   227,   146,   250,   169,
      34,   234,    82,    83,    82,    83,   261,   135,   262,    29,
     173,    20,    85,    84,    85,   152,    51,   153,   159,   160,
      58,    46,   145,   174,   147,    35,   149,    20,    86,    43,
     109,   235,    47,   170,    88,   181,    88,    29,   183,   193,
      51,    78,   271,   141,    41,   141,  -103,     1,    58,   121,
       2,     3,     4,     5,     6,     7,   197,    44,   132,   136,
       8,   123,     9,   202,   205,    29,   186,    71,    54,   178,
     123,    76,   237,   266,   124,   172,   125,   187,    36,    55,
     179,   200,   222,    38,    82,    83,   225,   226,    37,   126,
     173,   205,   201,   232,    85,    71,    10,    11,   126,    76,
     255,   129,    61,   174,    62,    12,    13,    14,    15,     2,
       3,     4,     5,     6,     7,    52,    88,   161,   162,   163,
     164,     9,   157,   158,   273,   141,   132,   165,   166,     1,
     224,    83,     2,     3,     4,     5,     6,     7,   240,    84,
      85,   242,     8,    59,     9,    48,   207,     2,     3,     4,
       5,     6,     7,    64,    86,    10,   257,    60,   152,     9,
     153,    63,    88,   277,   278,    13,    14,    15,   205,    65,
     261,   141,   262,   269,   252,    49,   155,   155,    10,    11,
     213,   214,   215,   216,    66,   209,   210,    12,    13,    14,
      15,    79,    56,    10,     2,     3,     4,     5,     6,     7,
     122,   211,   212,    13,    14,    15,     9,   127,   217,   218,
      39,    40,   128,   109,   109,   109,   109,    48,   203,     2,
       3,     4,     5,     6,     7,   129,   137,   140,   144,   148,
     156,     9,   151,   167,   168,   171,   176,    82,    83,   204,
      10,   177,   180,   182,   185,   184,    84,    85,   188,   193,
      13,    14,    15,   198,    67,     2,     3,     4,     5,     6,
       7,    86,   196,   199,   228,    10,    68,     9,   223,    88,
     229,   230,   236,   231,   239,    13,    14,    15,   141,    67,
       2,     3,     4,     5,     6,     7,   241,   243,   244,   245,
     246,    68,     9,   247,     2,     3,     4,     5,     6,     7,
     248,    10,   249,   253,   256,    69,     9,   258,   260,   268,
      42,    13,    14,    15,   259,   265,     2,     3,     4,     5,
       6,     7,   267,    80,   270,   274,    10,   275,     9,   272,
     138,    81,   276,    82,    83,   233,    13,    14,    15,   208,
      10,   251,    84,    85,   189,   220,    77,   219,   120,   190,
      13,    14,    15,   238,   221,   139,     0,    86,     0,     0,
       0,     0,    10,     0,    87,    88,    89,     0,     0,    90,
       0,     0,    13,    14,    91,     2,     3,     4,     5,     6,
       7,     0,    80,     0,     0,     0,     0,     9,     0,     0,
      81,     0,    82,    83,     0,     0,     0,     0,     0,     0,
       0,    84,    85,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     0,     0,     0,    86,     0,     0,     9,
       0,    10,     0,    87,    88,   154,     0,     0,    90,     0,
       0,    13,    14,    91,     2,     3,     4,     5,     6,     7,
       0,    80,     0,     0,     0,     0,     9,     0,     0,    81,
       0,    82,    83,    10,     0,     0,     0,     0,     0,     0,
      84,    85,     0,     0,     0,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,     0,     0,     0,     0,
      10,     0,    87,    88,   279,     0,     0,    90,     0,     0,
      13,    14,    91,     2,     3,     4,     5,     6,     7,     0,
      80,     0,     0,     0,     0,     9,     0,     0,    81,     0,
      82,    83,     0,     0,     0,     0,     0,     0,     0,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    86,     0,     0,     0,     0,    10,
       0,    87,    88,   280,     0,     0,    90,     0,     0,    13,
      14,    91,     2,     3,     4,     5,     6,     7,     0,    80,
       0,     0,     0,     0,     9,     0,     0,    81,     0,    82,
      83,     0,     0,     0,     0,     0,     0,     0,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,     0,     0,     0,     0,    10,     0,
      87,    88,     0,     0,     0,    90,     0,     0,    13,    14,
      91
};

static const yytype_int16 yycheck[] =
{
      52,    92,    80,     0,   135,   136,   179,    85,    19,    15,
      64,    27,    23,    24,    23,    24,    20,    12,    22,    16,
      44,     0,    33,    32,    33,    33,    23,    35,    41,    42,
      27,    34,    84,    57,    86,    35,    88,    16,    47,    27,
      92,    57,    45,    49,    55,   123,    55,    44,   126,    23,
      47,    48,    56,    64,     0,    64,    64,     3,    55,    56,
       6,     7,     8,     9,    10,    11,   144,    55,    65,    64,
      16,    29,    18,   151,   152,    72,    45,    44,    34,    34,
      29,    44,    56,   256,    33,    29,    35,    56,    64,    45,
      45,    45,   170,    25,    23,    24,   174,   175,    64,    57,
      44,   179,    56,    56,    33,    72,    52,    53,    57,    72,
     241,    64,    33,    57,    35,    61,    62,    63,    64,     6,
       7,     8,     9,    10,    11,    55,    55,    37,    38,    39,
      40,    18,    31,    32,   265,    64,   133,    50,    51,     3,
      23,    24,     6,     7,     8,     9,    10,    11,   200,    32,
      33,   203,    16,    64,    18,     4,   153,     6,     7,     8,
       9,    10,    11,    55,    47,    52,   244,    27,    33,    18,
      35,    23,    55,   275,   276,    62,    63,    64,   256,    55,
      20,    64,    22,   261,   236,    34,   277,   278,    52,    53,
     161,   162,   163,   164,    27,   157,   158,    61,    62,    63,
      64,    64,     4,    52,     6,     7,     8,     9,    10,    11,
      64,   159,   160,    62,    63,    64,    18,    64,   165,   166,
      13,    14,    36,   275,   276,   277,   278,     4,     4,     6,
       7,     8,     9,    10,    11,    64,    55,    64,    33,    64,
      30,    18,    33,    46,    14,    27,    64,    23,    24,    25,
      52,    34,    64,    64,    29,    36,    32,    33,    64,    23,
      62,    63,    64,    34,     5,     6,     7,     8,     9,    10,
      11,    47,    27,    27,    36,    52,    17,    18,    64,    55,
      58,    33,    28,    23,    34,    62,    63,    64,    64,     5,
       6,     7,     8,     9,    10,    11,    34,    36,    28,    28,
      58,    17,    18,    27,     6,     7,     8,     9,    10,    11,
      33,    52,    23,    55,    33,    56,    18,    23,    27,    27,
      16,    62,    63,    64,    58,    60,     6,     7,     8,     9,
      10,    11,    58,    13,    28,    28,    52,    55,    18,   263,
      56,    21,    55,    23,    24,   186,    62,    63,    64,   156,
      52,   236,    32,    33,    56,   168,    47,   167,    55,   133,
      62,    63,    64,   194,   169,    72,    -1,    47,    -1,    -1,
      -1,    -1,    52,    -1,    54,    55,    56,    -1,    -1,    59,
      -1,    -1,    62,    63,    64,     6,     7,     8,     9,    10,
      11,    -1,    13,    -1,    -1,    -1,    -1,    18,    -1,    -1,
      21,    -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    47,    -1,    -1,    18,
      -1,    52,    -1,    54,    55,    56,    -1,    -1,    59,    -1,
      -1,    62,    63,    64,     6,     7,     8,     9,    10,    11,
      -1,    13,    -1,    -1,    -1,    -1,    18,    -1,    -1,    21,
      -1,    23,    24,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      52,    -1,    54,    55,    56,    -1,    -1,    59,    -1,    -1,
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
      97,    99,   100,   101,   103,   104,   105,   106,   108,   109,
     110,   113,   121,   122,    64,    35,    64,    64,    25,   108,
     108,     0,    67,    27,    55,   114,    34,    45,     4,    34,
     102,   109,    55,   124,    34,    45,     4,   107,   109,    64,
      27,    33,    35,    23,    55,    55,    27,     5,    17,    56,
      97,   103,   115,   116,   117,   120,   123,   102,   109,    64,
      13,    21,    23,    24,    32,    33,    47,    54,    55,    56,
      59,    64,    72,    73,    74,    77,    78,    80,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    98,   109,   123,   125,   126,   127,   129,   130,
     107,   109,    64,    29,    33,    35,    57,    64,    36,    64,
      70,    71,   109,   111,   112,    12,    64,    55,    56,   116,
      64,    64,    92,    93,    33,    93,    92,    93,    64,    93,
      96,    33,    33,    35,    56,    73,    30,    31,    32,    41,
      42,    37,    38,    39,    40,    50,    51,    46,    14,    15,
      49,    27,    29,    44,    57,    79,    64,    34,    34,    45,
      64,    92,    64,    92,    36,    29,    45,    56,    64,    56,
     112,   124,   124,    23,   118,   119,    27,    92,    34,    27,
      45,    56,    92,     4,    25,    92,   128,   109,    82,    83,
      83,    84,    84,    85,    85,    85,    85,    86,    86,    87,
      88,    89,    92,    64,    23,    92,    92,   128,    36,    58,
      33,    23,    56,    71,    27,    57,    28,    56,   119,    34,
      93,    34,    93,    36,    28,    28,    58,    27,    33,    23,
      19,    78,    93,    55,    81,   124,    33,    92,    23,    58,
      27,    20,    22,    75,    76,    60,   128,    58,    27,    92,
      28,    56,    76,   124,    28,    55,    55,    72,    72,    56,
      56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    66,    67,    67,    67,    67,    67,    67,
      68,    69,    69,    70,    70,    71,    71,    72,    72,    73,
      73,    73,    73,    73,    73,    73,    74,    75,    75,    76,
      76,    77,    78,    79,    80,    81,    81,    82,    82,    82,
      83,    83,    84,    84,    84,    85,    85,    85,    86,    86,
      86,    86,    86,    87,    87,    87,    88,    88,    89,    89,
      90,    90,    91,    91,    92,    93,    93,    93,    93,    93,
      94,    94,    94,    94,    94,    95,    96,    96,    97,    98,
      99,    99,   100,   100,   101,   101,   102,   102,   103,   104,
     105,   105,   106,   106,   107,   107,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   109,   109,   109,   110,   111,
     111,   112,   112,   113,   113,   114,   114,   115,   115,   116,
     116,   116,   116,   117,   118,   118,   119,   119,   120,   120,
     121,   122,   122,   122,   123,   124,   124,   125,   125,   126,
     126,   127,   127,   127,   128,   128,   128,   129,   130
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
       1,     2,     5,     4,     1,     2,     3,     2,     2,     2,
       5,     3,     6,     3,     1,     2,     1,     3,     3
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
#line 176 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddModuleDef((yyval.pNode)); }
#line 1709 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 5:
#line 177 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddFunction((yyval.pNode)); }
#line 1715 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 6:
#line 178 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddImport((yyval.pNode)); }
#line 1721 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 179 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddTypeDef((yyval.pNode)); }
#line 1727 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 8:
#line 180 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddTypeDef((yyval.pNode)); }
#line 1733 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 181 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddGlobal((yyval.pNode)); }
#line 1739 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 185 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ImportStatementNode(pContext, (yyloc)); }
#line 1745 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 188 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<EnumDefinitionNode*>((yyval.pNode))->SetIdentifier((yyvsp[-3].symIndex)); }
#line 1751 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 189 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<EnumDefinitionNode*>((yyval.pNode))->SetIdentifier((yyvsp[-4].symIndex)); }
#line 1757 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 193 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new EnumDefinitionNode(pContext, (yyloc), (yyvsp[0]._EnumItem)); }
#line 1763 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 194 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<EnumDefinitionNode*>((yyval.pNode))->AddEnum((yyvsp[0]._EnumItem)); }
#line 1769 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 15:
#line 198 "VSharp.y" /* yacc.c:1661  */
    { (yyval._EnumItem) = EnumItem((yyvsp[0].symIndex)); }
#line 1775 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 199 "VSharp.y" /* yacc.c:1661  */
    { (yyval._EnumItem) = EnumItem((yyvsp[-2].symIndex), (yyvsp[0].constVal)); }
#line 1781 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 203 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 1787 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 204 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 1793 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 208 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1799 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 209 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1805 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 210 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1811 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 211 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1817 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 212 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1823 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 213 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1829 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 214 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1835 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 219 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<SwitchStatementNode*>((yyval.pNode))->SetTest((yyvsp[-4].pNode)); }
#line 1841 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 223 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new SwitchStatementNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 1847 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 224 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<SwitchStatementNode*>((yyval.pNode))->AddNode((yyvsp[0].pNode)); }
#line 1853 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 229 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new CaseStatementNode(pContext, (yyloc), (yyvsp[-4].pNode), (yyvsp[-1].pNode)); }
#line 1859 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 230 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new CaseStatementNode(pContext, (yyloc), nullptr, (yyvsp[-1].pNode)); }
#line 1865 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 234 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ExpressionStatementNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 1871 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 238 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new AssignmentNode(pContext, (yyloc), (yyvsp[-3].pNode), (yyvsp[-1].pNode)); }
#line 1877 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 247 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); dynamic_cast<IfStatementNode*>((yyval.pNode))->SetExpression((yyvsp[-2].pNode)); }
#line 1883 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 251 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IfStatementNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode)); }
#line 1889 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 252 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IfStatementNode(pContext, (yyloc), (yyvsp[0].pNode), nullptr); }
#line 1895 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 256 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1901 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 257 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new UnaryOperatorNode(pContext, (yyloc), (yyvsp[0].pNode), Operator::Negate); }
#line 1907 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 258 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new UnaryOperatorNode(pContext, (yyloc), (yyvsp[0].pNode), Operator::LogicalNot); }
#line 1913 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 40:
#line 262 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1919 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 41:
#line 263 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Multiply); }
#line 1925 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 42:
#line 267 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1931 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 268 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Add); }
#line 1937 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 44:
#line 269 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Subtract); }
#line 1943 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 273 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1949 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 274 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::ShiftLeft); }
#line 1955 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 275 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::ShiftRight); }
#line 1961 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 48:
#line 279 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1967 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 280 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LessThan); }
#line 1973 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 281 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::GreaterThan); }
#line 1979 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 282 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LessThanEqual); }
#line 1985 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 52:
#line 283 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::GreaterThanEqual); }
#line 1991 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 287 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1997 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 54:
#line 288 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Equal); }
#line 2003 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 289 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::NotEqual); }
#line 2009 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 56:
#line 293 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2015 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 294 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::BitwiseXor); }
#line 2021 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 298 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2027 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 299 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LogicalAnd); }
#line 2033 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 303 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2039 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 304 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LogicalOr); }
#line 2045 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 308 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2051 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 309 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TernaryExpressionNode(pContext, (yyloc), (yyvsp[-4].pNode), (yyvsp[-2].pNode), (yyvsp[0].pNode)); }
#line 2057 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 313 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2063 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 317 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2069 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 318 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IndexSelectionNode(pContext, (yyloc), (yyvsp[-3].pNode), (yyvsp[-1].pNode)); }
#line 2075 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 320 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new BitSelectionNode(pContext, (yyloc), (yyvsp[-5].pNode), (yyvsp[-3].constVal), (yyvsp[-1].constVal)); }
#line 2081 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 321 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2087 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 322 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FieldSelectionNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].symIndex)); }
#line 2093 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 326 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2099 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 327 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2105 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 328 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, (yyloc), (yyvsp[0].constVal)); }
#line 2111 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 329 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, (yyloc), (yyvsp[0].constVal)); }
#line 2117 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 330 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ParenNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2123 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 334 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new GlomExpressionNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2129 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 338 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 2135 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 339 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<ListNode*>((yyval.pNode))->AddNode((yyvsp[0].pNode)); }
#line 2141 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 343 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2147 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 79:
#line 347 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IdentifierNode(pContext, (yyloc), (yyvsp[0].symIndex)); }
#line 2153 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 80:
#line 351 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2159 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 81:
#line 352 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2165 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 82:
#line 356 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<ModuleDefinitionNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 2171 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 83:
#line 357 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<ModuleDefinitionNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 2177 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 84:
#line 361 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleDefinitionNode(pContext, (yyloc), (yyvsp[-1].symIndex), -1); }
#line 2183 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 85:
#line 362 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleDefinitionNode(pContext, (yyloc), (yyvsp[-4].symIndex), (yyvsp[-2].symIndex)); }
#line 2189 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 86:
#line 366 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleParameterNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), false); }
#line 2195 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 87:
#line 367 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleParameterNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), true); }
#line 2201 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 88:
#line 371 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->SetStatementList((yyvsp[0].pNode)); }
#line 2207 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 89:
#line 375 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2213 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 90:
#line 378 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 2219 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 91:
#line 379 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 2225 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 92:
#line 383 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionDeclaratorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[-1].symIndex), -1); }
#line 2231 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 93:
#line 384 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionDeclaratorNode(pContext, (yyloc), (yyvsp[-5].pNode), (yyvsp[-4].symIndex), (yyvsp[-2].symIndex)); }
#line 2237 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 94:
#line 388 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionParameterNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), false); }
#line 2243 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 95:
#line 389 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionParameterNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), true); }
#line 2249 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 96:
#line 393 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 64); }
#line 2255 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 97:
#line 394 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 32); }
#line 2261 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 98:
#line 395 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 16); }
#line 2267 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 99:
#line 396 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 8); }
#line 2273 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 100:
#line 397 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Void); }
#line 2279 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 101:
#line 398 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Clock); }
#line 2285 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 102:
#line 399 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 1); }
#line 2291 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 103:
#line 400 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Unknown, (yyvsp[0].symIndex)); }
#line 2297 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 104:
#line 401 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), (yyvsp[-1].constVal)); }
#line 2303 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 105:
#line 405 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); dynamic_cast<TypeNode*>((yyval.pNode))->SetModifier(TypeModifier::Wire); }
#line 2309 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 106:
#line 406 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); dynamic_cast<TypeNode*>((yyval.pNode))->SetModifier(TypeModifier::Const); }
#line 2315 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 107:
#line 407 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2321 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 108:
#line 411 "VSharp.y" /* yacc.c:1661  */
    {
	                                    							  (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<StructSpecifierNode*>((yyval.pNode))->SetName((yyvsp[-3].symIndex)); }
#line 2328 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 109:
#line 416 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructSpecifierNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 2334 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 110:
#line 417 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2340 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 111:
#line 421 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructDeclarationNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[-1].symIndex)); }
#line 2346 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 112:
#line 423 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructDeclarationNode(pContext, (yyloc), (yyvsp[-5].pNode), (yyvsp[-4].symIndex), (yyvsp[-2].constVal)); }
#line 2352 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 113:
#line 427 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2358 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 114:
#line 428 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<ModuleDefinitionNode*>((yyval.pNode))->SetStatementList((yyvsp[0].pNode)); }
#line 2364 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 115:
#line 432 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), nullptr); }
#line 2370 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 116:
#line 433 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2376 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 117:
#line 437 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 2382 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 118:
#line 438 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2388 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 119:
#line 442 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2394 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 120:
#line 443 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2400 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 121:
#line 444 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2406 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 122:
#line 445 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2412 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 123:
#line 449 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new DriveListDefinitionNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2418 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 124:
#line 453 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 2424 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 125:
#line 454 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2430 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 126:
#line 458 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new DriveDefinitionNode(pContext, (yyloc), (yyvsp[-2].constVal), (yyvsp[0].pNode)); }
#line 2436 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 127:
#line 459 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new DriveDefinitionNode(pContext, (yyloc), (yyvsp[-3].constVal), nullptr); }
#line 2442 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 128:
#line 463 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StateDeclaratorNode(pContext, (yyloc), (yyvsp[-1].symIndex), (yyvsp[0].pNode)); }
#line 2448 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 129:
#line 464 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StateDeclaratorNode(pContext, (yyloc), -1, (yyvsp[0].pNode)); }
#line 2454 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 130:
#line 468 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2460 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 131:
#line 472 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new VariableDeclarationNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), nullptr, nullptr); }
#line 2466 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 132:
#line 474 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new VariableDeclarationNode(pContext, (yyloc), (yyvsp[-4].pNode), (yyvsp[-3].symIndex), (yyvsp[-1].pNode), nullptr); }
#line 2472 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 133:
#line 475 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new VariableDeclarationNode(pContext, (yyloc), (yyvsp[-3].pNode), (yyvsp[-2].symIndex), nullptr, (yyvsp[0].pNode)); }
#line 2478 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 134:
#line 479 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2484 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 135:
#line 483 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), nullptr); }
#line 2490 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 136:
#line 484 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2496 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 137:
#line 488 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2502 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 138:
#line 489 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2508 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 139:
#line 493 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-1].symIndex), nullptr, nullptr); }
#line 2514 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 140:
#line 494 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-4].symIndex), (yyvsp[-2].pNode), nullptr); }
#line 2520 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 141:
#line 498 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-2].symIndex), nullptr, (yyvsp[0].pNode)); }
#line 2526 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 142:
#line 499 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-5].symIndex), (yyvsp[-3].pNode), (yyvsp[0].pNode)); }
#line 2532 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 143:
#line 500 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2538 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 144:
#line 504 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallParamNode(pContext, (yyloc), false, (yyvsp[0].pNode)); }
#line 2544 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 145:
#line 505 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallParamNode(pContext, (yyloc), true, (yyvsp[0].pNode)); }
#line 2550 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 146:
#line 506 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallParamNode(pContext, (yyloc)); }
#line 2556 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 147:
#line 510 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ReturnNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2562 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 148:
#line 513 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TransitionNode(pContext, (yyloc), (yyvsp[-1].symIndex)); }
#line 2568 "VSharp.tab.c" /* yacc.c:1661  */
    break;


#line 2572 "VSharp.tab.c" /* yacc.c:1661  */
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
#line 516 "VSharp.y" /* yacc.c:1906  */

