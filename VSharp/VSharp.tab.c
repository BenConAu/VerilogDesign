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
#include "FunctionExpandType.h"

class ASTNode;
class ParserContext;

#line 121 "VSharp.tab.c" /* yacc.c:355  */

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
    STAGE_TOKEN = 279,
    INTCONSTANT = 280,
    BOOLCONSTANT = 281,
    STRINGLITERAL = 282,
    AT = 283,
    SEMICOLON = 284,
    COLON = 285,
    EQUAL = 286,
    STAR = 287,
    SLASH = 288,
    PLUS = 289,
    MINUS = 290,
    LEFT_PAREN = 291,
    RIGHT_PAREN = 292,
    LT = 293,
    GT = 294,
    LT_OP = 295,
    GT_OP = 296,
    LT_EQUAL_OP = 297,
    GT_EQUAL_OP = 298,
    SHIFTLEFT = 299,
    SHIFTRIGHT = 300,
    ARROW = 301,
    DOT = 302,
    COMMA = 303,
    HAT = 304,
    BANG = 305,
    BAR = 306,
    AMPERSAND = 307,
    QUESTION = 308,
    EQUAL_OP = 309,
    NOTEQUAL_OP = 310,
    BOOL_TOKEN = 311,
    STRUCT_TOKEN = 312,
    TRANSITION_TOKEN = 313,
    LEFT_BRACE = 314,
    RIGHT_BRACE = 315,
    LEFT_BRACKET = 316,
    RIGHT_BRACKET = 317,
    IF_TOKEN = 318,
    ELSE_TOKEN = 319,
    IMPORT_TOKEN = 320,
    WIRE_TOKEN = 321,
    CONST_TOKEN = 322,
    BLOCKING_TOKEN = 323,
    NONBLOCKING_TOKEN = 324,
    IDENTIFIER = 325
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 33 "VSharp.y" /* yacc.c:355  */

    UIntConstant constVal;
    int symIndex;
    ASTNode* pNode;
    EnumItem _EnumItem;
    FunctionExpandType _FunctionExpandType;

#line 212 "VSharp.tab.c" /* yacc.c:355  */
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

#line 242 "VSharp.tab.c" /* yacc.c:358  */

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
#define YYFINAL  44
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   642

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  156
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  297

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   325

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
      65,    66,    67,    68,    69,    70
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   181,   181,   182,   186,   187,   188,   189,   190,   191,
     195,   198,   199,   203,   204,   208,   209,   213,   214,   218,
     219,   220,   221,   222,   223,   224,   228,   233,   234,   238,
     240,   244,   248,   252,   256,   261,   262,   266,   267,   268,
     272,   273,   274,   278,   279,   280,   284,   285,   286,   290,
     291,   292,   293,   294,   298,   299,   300,   304,   305,   309,
     310,   314,   315,   319,   320,   324,   325,   329,   333,   334,
     335,   337,   338,   342,   343,   344,   345,   346,   350,   354,
     355,   359,   363,   367,   368,   372,   373,   377,   378,   379,
     383,   384,   388,   389,   393,   397,   400,   401,   405,   406,
     407,   411,   412,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   428,   429,   430,   434,   439,   440,   444,   445,
     450,   451,   455,   456,   460,   461,   465,   466,   467,   468,
     472,   476,   477,   481,   482,   486,   487,   488,   492,   496,
     497,   499,   503,   507,   508,   512,   513,   517,   518,   522,
     523,   524,   528,   529,   530,   534,   537
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
  "SWITCH_TOKEN", "DEFAULT_TOKEN", "STAGE_TOKEN", "INTCONSTANT",
  "BOOLCONSTANT", "STRINGLITERAL", "AT", "SEMICOLON", "COLON", "EQUAL",
  "STAR", "SLASH", "PLUS", "MINUS", "LEFT_PAREN", "RIGHT_PAREN", "LT",
  "GT", "LT_OP", "GT_OP", "LT_EQUAL_OP", "GT_EQUAL_OP", "SHIFTLEFT",
  "SHIFTRIGHT", "ARROW", "DOT", "COMMA", "HAT", "BANG", "BAR", "AMPERSAND",
  "QUESTION", "EQUAL_OP", "NOTEQUAL_OP", "BOOL_TOKEN", "STRUCT_TOKEN",
  "TRANSITION_TOKEN", "LEFT_BRACE", "RIGHT_BRACE", "LEFT_BRACKET",
  "RIGHT_BRACKET", "IF_TOKEN", "ELSE_TOKEN", "IMPORT_TOKEN", "WIRE_TOKEN",
  "CONST_TOKEN", "BLOCKING_TOKEN", "NONBLOCKING_TOKEN", "IDENTIFIER",
  "$accept", "translation_unit", "external_declaration",
  "import_statement", "enum_definition", "enum_list", "enum_item",
  "statement_list", "statement", "switch_statement", "case_list",
  "case_statement", "expression_statement", "assignment_statement",
  "assignment_operator", "selection_statement", "selection_rest_statement",
  "unary_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "expression", "postfix_expression",
  "primary_expression", "glom_expression", "glom_list", "declaration",
  "variable_identifier", "module_prototype",
  "module_header_with_parameters", "module_header", "duplicate_type",
  "module_param_decl", "function_definition", "function_prototype",
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
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325
};
# endif

#define YYPACT_NINF -173

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-173)))

#define YYTABLE_NINF -111

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     151,    18,    -4,  -173,  -173,  -173,  -173,  -173,   -49,  -173,
     -28,  -173,    -1,    66,     4,     4,  -173,    70,  -173,  -173,
    -173,  -173,    32,    58,   113,  -173,    38,    93,   178,  -173,
      45,  -173,  -173,    89,  -173,    87,     5,   231,    75,   102,
      83,   138,  -173,  -173,  -173,  -173,  -173,   244,  -173,  -173,
     216,   350,  -173,  -173,   106,   312,  -173,  -173,   178,   350,
    -173,   122,    78,  -173,  -173,  -173,   115,  -173,   126,  -173,
    -173,   233,   231,   233,   233,    27,  -173,    69,   156,   150,
     123,   146,   163,   164,   204,    15,  -173,   192,   -17,  -173,
    -173,  -173,  -173,   196,    96,   166,  -173,   350,  -173,    14,
     182,  -173,  -173,  -173,   269,  -173,  -173,  -173,  -173,  -173,
     194,  -173,   231,   229,   200,  -173,   235,    13,   377,  -173,
    -173,  -173,  -173,  -173,   255,    82,   203,  -173,  -173,  -173,
    -173,   215,  -173,   231,  -173,   231,   231,   219,   252,   -17,
     257,   -17,   -17,    -3,    12,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,  -173,   225,   231,  -173,  -173,    12,   265,
      44,  -173,   227,   334,  -173,    38,    38,    38,   273,  -173,
    -173,  -173,   270,   231,   276,   231,  -173,  -173,  -173,  -173,
     231,    -9,  -173,  -173,   263,   245,   272,   277,  -173,   233,
    -173,   233,  -173,  -173,  -173,   267,  -173,  -173,    69,    69,
     156,   156,   150,   150,   150,   150,   123,   123,   146,   163,
     164,   204,   279,  -173,    -6,  -173,   287,    40,  -173,    11,
    -173,  -173,  -173,  -173,  -173,   285,    -7,  -173,  -173,   280,
    -173,   290,   295,   292,  -173,  -173,  -173,   -17,   -17,   294,
     231,   231,  -173,  -173,  -173,  -173,  -173,   291,   173,  -173,
    -173,   274,    38,  -173,  -173,    12,  -173,   284,   288,   303,
    -173,    82,   128,  -173,   299,  -173,  -173,   320,  -173,   231,
     321,   -14,  -173,    38,  -173,   322,   296,  -173,  -173,  -173,
     305,   572,   572,   442,   507,  -173,  -173
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,   103,   104,   105,   106,   107,     0,   108,
       0,   109,     0,     0,     0,     0,   110,     0,     2,     6,
       7,     9,     0,     0,     0,     5,     0,     0,     0,   114,
       0,     8,     4,     0,   138,     0,     0,     0,     0,     0,
       0,     0,   112,   113,     1,     3,   120,     0,   121,    83,
       0,     0,    84,    85,     0,     0,    94,    95,     0,     0,
      96,     0,   139,    81,    90,    91,     0,    87,     0,    75,
      76,     0,     0,     0,     0,    82,    40,    43,    46,    49,
      54,    57,    59,    61,    63,    65,    67,     0,    37,    68,
      74,    73,    71,     0,     0,     0,   100,     0,    10,     0,
       0,   122,   142,   128,     0,   124,   129,   126,   127,    86,
       0,    92,     0,     0,     0,   143,     0,    82,     0,    17,
      25,    19,    20,    21,     0,    37,     0,    22,    24,    23,
      97,     0,   101,     0,    98,     0,     0,     0,     0,    38,
       0,    39,    79,     0,   147,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   111,     0,     0,   146,   145,     0,    15,
       0,    13,     0,     0,   116,     0,     0,     0,     0,   123,
     125,    93,     0,     0,     0,     0,   144,    18,    31,    33,
       0,   139,   102,   141,     0,     0,     0,     0,    77,     0,
      78,     0,   154,   152,   149,     0,    41,    42,    44,    45,
      47,    48,    50,    51,    52,    53,    55,    56,    58,    60,
      62,    64,     0,    72,     0,   151,     0,     0,    11,     0,
     115,   117,   136,   137,   135,     0,     0,   131,   155,     0,
     156,     0,     0,     0,   140,    89,    88,    80,   153,     0,
       0,     0,    69,    16,    12,    14,   118,     0,     0,   130,
     132,     0,     0,    32,    99,   148,    66,     0,     0,     0,
     133,     0,     0,    34,    36,   150,    70,     0,   134,     0,
       0,     0,    27,     0,   119,     0,     0,    26,    28,    35,
       0,     0,     0,     0,     0,    30,    29
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -173,  -173,   337,  -173,  -173,  -173,   139,   -89,  -116,  -173,
    -173,    84,  -173,   109,  -173,  -173,  -173,    59,    62,    79,
      19,    90,   218,   214,   217,   213,  -173,  -173,   -37,   -54,
    -173,  -173,  -173,    33,  -173,  -173,  -173,  -173,  -173,   330,
     -19,  -173,  -173,  -173,   323,   246,     8,  -173,  -173,   220,
    -173,  -173,  -173,   293,  -173,  -173,   153,  -173,  -173,  -173,
     -18,  -172,  -173,  -173,  -173,  -162,  -173,  -173
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    18,    19,    20,   170,   171,   118,   119,   120,
     281,   282,   121,   122,   190,   123,   273,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,   124,    88,
      89,    90,   143,   102,    91,    22,    23,    24,    66,    53,
      25,    26,    27,    28,    60,    29,   126,    31,   173,   174,
      32,    48,   104,   105,   106,   236,   237,   107,    33,    34,
     127,    56,    92,    93,    94,   204,   128,   129
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      87,   125,   187,   232,   233,   234,   225,   279,    30,   280,
       2,     3,     4,     5,     6,     7,   201,   139,   235,   141,
     142,    38,   133,     9,   251,    30,   175,   176,   103,   108,
     164,   161,    54,    21,    37,   140,    61,    69,    70,   202,
     256,    67,    39,    68,   165,   199,   287,    71,    72,   144,
      21,   145,   136,   259,    35,    30,   252,   200,    54,   110,
      11,    46,    73,   144,   125,   145,    61,   131,   162,    40,
      44,    74,   257,     1,    16,   182,     2,     3,     4,     5,
       6,     7,    75,  -110,   177,   103,   108,     8,    36,     9,
     274,    47,   227,    41,    10,    49,   193,    55,   194,   195,
     254,   146,   147,   275,   228,   172,    50,   203,   205,   133,
     169,   289,    30,   189,   134,    62,   135,    51,    63,     2,
       3,     4,     5,     6,     7,   222,    11,    12,   224,   164,
      57,   203,     9,   167,    95,    13,    14,    15,    96,   136,
      16,    58,    97,   165,   168,   247,   239,   248,   241,   279,
      52,   280,   137,   242,     1,    64,    65,     2,     3,     4,
       5,     6,     7,   152,   153,   154,   155,    98,     8,    11,
       9,   212,   213,   214,   215,    10,   111,   187,   187,    14,
      15,   172,    59,    16,     2,     3,     4,     5,     6,     7,
     148,   149,   132,   269,   150,   151,   138,     9,    69,    70,
     156,   157,   293,   294,   271,   206,   207,    11,    12,    72,
     208,   209,   158,   266,   267,   159,    13,    14,    15,   160,
      51,    16,     2,     3,     4,     5,     6,     7,   203,   210,
     211,   163,    74,   166,    11,     9,   169,   125,   125,   125,
     125,   178,   285,    75,    14,    15,   216,   217,    16,    99,
       2,     3,     4,     5,     6,     7,    69,    70,    69,    70,
      42,    43,   100,     9,   181,   183,    71,    72,    10,    72,
     184,   185,    11,   191,    99,     2,     3,     4,     5,     6,
       7,    73,    14,    15,   188,   192,    16,   100,     9,   196,
      74,   197,    74,    10,   198,   223,   226,   229,   235,   238,
      11,    75,   243,    75,   101,   240,   249,   244,   245,   250,
      14,    15,   253,   246,    16,   258,   268,   261,     2,     3,
       4,     5,     6,     7,   263,    11,   112,   262,   264,   179,
     265,     9,   278,   272,   113,    14,    15,    69,    70,    16,
       2,     3,     4,     5,     6,     7,   276,    71,    72,   284,
     277,   286,   290,     9,    45,   291,     2,     3,     4,     5,
       6,     7,    73,   283,   292,   288,   255,   270,    11,     9,
     114,    74,   115,   219,   221,   116,   218,   220,    14,    15,
     109,   130,   117,     2,     3,     4,     5,     6,     7,   260,
      11,   112,     0,   231,   230,     0,     9,   180,     0,   113,
      14,    15,    69,    70,    16,     0,    11,     0,     0,     0,
       0,     0,    71,    72,     0,     0,    14,    15,     0,     0,
      16,     0,     0,     0,     0,     0,     0,    73,     0,     0,
       0,     0,     0,    11,     0,   114,    74,   186,     0,     0,
     116,     0,     0,    14,    15,     0,     0,   117,     2,     3,
       4,     5,     6,     7,     0,     0,   112,     0,     0,     0,
       0,     9,     0,     0,   113,     0,     0,    69,    70,     0,
       0,     0,     0,     0,     0,     0,     0,    71,    72,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    73,     0,     0,     0,     0,     0,    11,     0,
     114,    74,   295,     0,     0,   116,     0,     0,    14,    15,
       0,     0,   117,     2,     3,     4,     5,     6,     7,     0,
       0,   112,     0,     0,     0,     0,     9,     0,     0,   113,
       0,     0,    69,    70,     0,     0,     0,     0,     0,     0,
       0,     0,    71,    72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,     0,     0,
       0,     0,     0,    11,     0,   114,    74,   296,     0,     0,
     116,     0,     0,    14,    15,     0,     0,   117,     2,     3,
       4,     5,     6,     7,     0,     0,   112,     0,     0,     0,
       0,     9,     0,     0,   113,     0,     0,    69,    70,     0,
       0,     0,     0,     0,     0,     0,     0,    71,    72,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    73,     0,     0,     0,     0,     0,    11,     0,
     114,    74,     0,     0,     0,   116,     0,     0,    14,    15,
       0,     0,   117
};

static const yytype_int16 yycheck[] =
{
      37,    55,   118,   175,   176,   177,   168,    21,     0,    23,
       6,     7,     8,     9,    10,    11,     4,    71,    25,    73,
      74,    70,    31,    19,    30,    17,    12,    13,    47,    47,
      47,    16,    24,     0,    38,    72,    28,    25,    26,    27,
      29,    36,    70,    38,    61,    48,    60,    35,    36,    36,
      17,    38,    61,    60,    36,    47,    62,    60,    50,    51,
      56,    29,    50,    36,   118,    38,    58,    59,    53,    70,
       0,    59,    61,     3,    70,   112,     6,     7,     8,     9,
      10,    11,    70,    70,    70,   104,   104,    17,    70,    19,
     262,    59,    48,    27,    24,    37,   133,    59,   135,   136,
      60,    32,    33,   265,    60,    97,    48,   144,   145,    31,
      70,   283,   104,    31,    36,    70,    38,     4,    29,     6,
       7,     8,     9,    10,    11,   162,    56,    57,   165,    47,
      37,   168,    19,    37,    59,    65,    66,    67,    36,    61,
      70,    48,    59,    61,    48,   199,   183,   201,   185,    21,
      37,    23,    37,   190,     3,    68,    69,     6,     7,     8,
       9,    10,    11,    40,    41,    42,    43,    29,    17,    56,
      19,   152,   153,   154,   155,    24,    70,   293,   294,    66,
      67,   173,     4,    70,     6,     7,     8,     9,    10,    11,
      34,    35,    70,    20,    44,    45,    70,    19,    25,    26,
      54,    55,   291,   292,   258,   146,   147,    56,    57,    36,
     148,   149,    49,   250,   251,    51,    65,    66,    67,    15,
       4,    70,     6,     7,     8,     9,    10,    11,   265,   150,
     151,    39,    59,    37,    56,    19,    70,   291,   292,   293,
     294,    59,   279,    70,    66,    67,   156,   157,    70,     5,
       6,     7,     8,     9,    10,    11,    25,    26,    25,    26,
      14,    15,    18,    19,    70,    36,    35,    36,    24,    36,
      70,    36,    56,    70,     5,     6,     7,     8,     9,    10,
      11,    50,    66,    67,    29,    70,    70,    18,    19,    70,
      59,    39,    59,    24,    37,    70,    31,    70,    25,    29,
      56,    70,    39,    70,    60,    29,    39,    62,    36,    30,
      66,    67,    25,    36,    70,    30,    25,    37,     6,     7,
       8,     9,    10,    11,    29,    56,    14,    37,    36,    60,
      36,    19,    29,    59,    22,    66,    67,    25,    26,    70,
       6,     7,     8,     9,    10,    11,    62,    35,    36,    29,
      62,    30,    30,    19,    17,    59,     6,     7,     8,     9,
      10,    11,    50,    64,    59,   281,   227,   258,    56,    19,
      58,    59,    60,   159,   161,    63,   158,   160,    66,    67,
      50,    58,    70,     6,     7,     8,     9,    10,    11,   236,
      56,    14,    -1,   173,    60,    -1,    19,   104,    -1,    22,
      66,    67,    25,    26,    70,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    66,    67,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    58,    59,    60,    -1,    -1,
      63,    -1,    -1,    66,    67,    -1,    -1,    70,     6,     7,
       8,     9,    10,    11,    -1,    -1,    14,    -1,    -1,    -1,
      -1,    19,    -1,    -1,    22,    -1,    -1,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,
      -1,    -1,    70,     6,     7,     8,     9,    10,    11,    -1,
      -1,    14,    -1,    -1,    -1,    -1,    19,    -1,    -1,    22,
      -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    58,    59,    60,    -1,    -1,
      63,    -1,    -1,    66,    67,    -1,    -1,    70,     6,     7,
       8,     9,    10,    11,    -1,    -1,    14,    -1,    -1,    -1,
      -1,    19,    -1,    -1,    22,    -1,    -1,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      58,    59,    -1,    -1,    -1,    63,    -1,    -1,    66,    67,
      -1,    -1,    70
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,     8,     9,    10,    11,    17,    19,
      24,    56,    57,    65,    66,    67,    70,    72,    73,    74,
      75,   104,   106,   107,   108,   111,   112,   113,   114,   116,
     117,   118,   121,   129,   130,    36,    70,    38,    70,    70,
      70,    27,   116,   116,     0,    73,    29,    59,   122,    37,
      48,     4,    37,   110,   117,    59,   132,    37,    48,     4,
     115,   117,    70,    29,    68,    69,   109,    36,    38,    25,
      26,    35,    36,    50,    59,    70,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   105,   133,   134,   135,    59,    36,    59,    29,     5,
      18,    60,   104,   111,   123,   124,   125,   128,   131,   110,
     117,    70,    14,    22,    58,    60,    63,    70,    78,    79,
      80,    83,    84,    86,    99,   100,   117,   131,   137,   138,
     115,   117,    70,    31,    36,    38,    61,    37,    70,   100,
      99,   100,   100,   103,    36,    38,    32,    33,    34,    35,
      44,    45,    40,    41,    42,    43,    54,    55,    49,    51,
      15,    16,    53,    39,    47,    61,    37,    37,    48,    70,
      76,    77,   117,   119,   120,    12,    13,    70,    59,    60,
     124,    70,    99,    36,    70,    36,    60,    79,    29,    31,
      85,    70,    70,    99,    99,    99,    70,    39,    37,    48,
      60,     4,    27,    99,   136,    99,    88,    88,    89,    89,
      90,    90,    91,    91,    91,    91,    92,    92,    93,    94,
      95,    96,    99,    70,    99,   136,    31,    48,    60,    70,
      60,   120,   132,   132,   132,    25,   126,   127,    29,    99,
      29,    99,    99,    39,    62,    36,    36,   100,   100,    39,
      30,    30,    62,    25,    60,    77,    29,    61,    30,    60,
     127,    37,    37,    29,    36,    36,    99,    99,    25,    20,
      84,   100,    59,    87,   132,   136,    62,    62,    29,    21,
      23,    81,    82,    64,    29,    99,    30,    60,    82,   132,
      30,    59,    59,    78,    78,    60,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    72,    73,    73,    73,    73,    73,    73,
      74,    75,    75,    76,    76,    77,    77,    78,    78,    79,
      79,    79,    79,    79,    79,    79,    80,    81,    81,    82,
      82,    83,    84,    85,    86,    87,    87,    88,    88,    88,
      89,    89,    89,    90,    90,    90,    91,    91,    91,    92,
      92,    92,    92,    92,    93,    93,    93,    94,    94,    95,
      95,    96,    96,    97,    97,    98,    98,    99,   100,   100,
     100,   100,   100,   101,   101,   101,   101,   101,   102,   103,
     103,   104,   105,   106,   106,   107,   107,   108,   108,   108,
     109,   109,   110,   110,   111,   112,   113,   113,   114,   114,
     114,   115,   115,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   117,   117,   117,   118,   119,   119,   120,   120,
     121,   121,   122,   122,   123,   123,   124,   124,   124,   124,
     125,   126,   126,   127,   127,   128,   128,   128,   129,   130,
     130,   130,   131,   132,   132,   133,   133,   134,   134,   135,
     135,   135,   136,   136,   136,   137,   138
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
       3,     2,     1,     2,     2,     2,     3,     3,     6,     6,
       1,     1,     2,     3,     2,     2,     2,     3,     3,     6,
       3,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     2,     2,     1,     5,     1,     2,     3,     6,
       2,     2,     2,     3,     1,     2,     1,     1,     1,     1,
       4,     1,     2,     3,     4,     3,     3,     3,     1,     2,
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
#line 186 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddModuleDef((yyval.pNode)); }
#line 1731 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 5:
#line 187 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddFunction((yyval.pNode)); }
#line 1737 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 6:
#line 188 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddImport((yyval.pNode)); }
#line 1743 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 189 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddTypeDef((yyval.pNode)); }
#line 1749 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 8:
#line 190 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddTypeDef((yyval.pNode)); }
#line 1755 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 191 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddGlobal((yyval.pNode)); }
#line 1761 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 195 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ImportStatementNode(pContext, (yyloc)); }
#line 1767 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 198 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<EnumDefinitionNode*>((yyval.pNode))->SetIdentifier((yyvsp[-3].symIndex)); }
#line 1773 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 199 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<EnumDefinitionNode*>((yyval.pNode))->SetIdentifier((yyvsp[-4].symIndex)); }
#line 1779 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 203 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new EnumDefinitionNode(pContext, (yyloc), (yyvsp[0]._EnumItem)); }
#line 1785 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 204 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<EnumDefinitionNode*>((yyval.pNode))->AddEnum((yyvsp[0]._EnumItem)); }
#line 1791 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 15:
#line 208 "VSharp.y" /* yacc.c:1661  */
    { (yyval._EnumItem) = EnumItem((yyvsp[0].symIndex)); }
#line 1797 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 209 "VSharp.y" /* yacc.c:1661  */
    { (yyval._EnumItem) = EnumItem((yyvsp[-2].symIndex), (yyvsp[0].constVal)); }
#line 1803 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 213 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 1809 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 214 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 1815 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 218 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1821 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 219 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1827 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 220 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1833 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 221 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1839 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 222 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1845 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 223 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1851 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 224 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1857 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 229 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<SwitchStatementNode*>((yyval.pNode))->SetTest((yyvsp[-4].pNode)); }
#line 1863 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 233 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new SwitchStatementNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 1869 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 234 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<SwitchStatementNode*>((yyval.pNode))->AddNode((yyvsp[0].pNode)); }
#line 1875 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 239 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new CaseStatementNode(pContext, (yyloc), (yyvsp[-4].pNode), (yyvsp[-1].pNode)); }
#line 1881 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 240 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new CaseStatementNode(pContext, (yyloc), nullptr, (yyvsp[-1].pNode)); }
#line 1887 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 244 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ExpressionStatementNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 1893 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 248 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new AssignmentNode(pContext, (yyloc), (yyvsp[-3].pNode), (yyvsp[-1].pNode)); }
#line 1899 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 257 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); dynamic_cast<IfStatementNode*>((yyval.pNode))->SetExpression((yyvsp[-2].pNode)); }
#line 1905 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 261 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IfStatementNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode)); }
#line 1911 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 262 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IfStatementNode(pContext, (yyloc), (yyvsp[0].pNode), nullptr); }
#line 1917 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 266 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1923 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 267 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new UnaryOperatorNode(pContext, (yyloc), (yyvsp[0].pNode), Operator::Negate); }
#line 1929 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 268 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new UnaryOperatorNode(pContext, (yyloc), (yyvsp[0].pNode), Operator::LogicalNot); }
#line 1935 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 40:
#line 272 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1941 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 41:
#line 273 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Multiply); }
#line 1947 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 42:
#line 274 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Divide); }
#line 1953 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 278 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1959 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 44:
#line 279 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Add); }
#line 1965 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 280 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Subtract); }
#line 1971 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 284 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1977 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 285 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::ShiftLeft); }
#line 1983 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 48:
#line 286 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::ShiftRight); }
#line 1989 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 290 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1995 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 291 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LessThan); }
#line 2001 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 292 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::GreaterThan); }
#line 2007 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 52:
#line 293 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LessThanEqual); }
#line 2013 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 294 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::GreaterThanEqual); }
#line 2019 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 54:
#line 298 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2025 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 299 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Equal); }
#line 2031 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 56:
#line 300 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::NotEqual); }
#line 2037 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 304 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2043 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 305 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::BitwiseXor); }
#line 2049 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 309 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2055 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 310 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::BitwiseOr); }
#line 2061 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 314 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2067 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 315 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LogicalAnd); }
#line 2073 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 319 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2079 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 320 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LogicalOr); }
#line 2085 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 324 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2091 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 325 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TernaryExpressionNode(pContext, (yyloc), (yyvsp[-4].pNode), (yyvsp[-2].pNode), (yyvsp[0].pNode)); }
#line 2097 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 329 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2103 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 333 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2109 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 334 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IndexSelectionNode(pContext, (yyloc), (yyvsp[-3].pNode), (yyvsp[-1].pNode)); }
#line 2115 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 336 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new BitSelectionNode(pContext, (yyloc), (yyvsp[-5].pNode), (yyvsp[-3].pNode), (yyvsp[-1].pNode)); }
#line 2121 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 337 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2127 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 338 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FieldSelectionNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].symIndex)); }
#line 2133 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 342 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2139 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 343 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2145 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 344 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, (yyloc), (yyvsp[0].constVal)); }
#line 2151 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 345 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, (yyloc), (yyvsp[0].constVal)); }
#line 2157 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 346 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ParenNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2163 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 350 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new GlomExpressionNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2169 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 79:
#line 354 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 2175 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 80:
#line 355 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<ListNode*>((yyval.pNode))->AddNode((yyvsp[0].pNode)); }
#line 2181 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 81:
#line 359 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2187 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 82:
#line 363 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IdentifierNode(pContext, (yyloc), (yyvsp[0].symIndex)); }
#line 2193 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 83:
#line 367 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2199 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 84:
#line 368 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2205 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 85:
#line 372 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<ModuleDefinitionNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 2211 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 86:
#line 373 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<ModuleDefinitionNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 2217 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 87:
#line 377 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleDefinitionNode(pContext, (yyloc), (yyvsp[-1].symIndex), -1, FunctionExpandType::None); }
#line 2223 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 88:
#line 378 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleDefinitionNode(pContext, (yyloc), (yyvsp[-4].symIndex), (yyvsp[-2].symIndex), FunctionExpandType::None); }
#line 2229 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 89:
#line 379 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleDefinitionNode(pContext, (yyloc), (yyvsp[-1].symIndex), -1, (yyvsp[-3]._FunctionExpandType)); }
#line 2235 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 90:
#line 383 "VSharp.y" /* yacc.c:1661  */
    { (yyval._FunctionExpandType) = FunctionExpandType::StageBlocking; }
#line 2241 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 91:
#line 384 "VSharp.y" /* yacc.c:1661  */
    { (yyval._FunctionExpandType) = FunctionExpandType::StageNonblocking; }
#line 2247 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 92:
#line 388 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleParameterNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), false); }
#line 2253 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 93:
#line 389 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleParameterNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), true); }
#line 2259 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 94:
#line 393 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->SetStatementList((yyvsp[0].pNode)); }
#line 2265 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 95:
#line 397 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2271 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 96:
#line 400 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 2277 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 97:
#line 401 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 2283 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 98:
#line 405 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionDeclaratorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[-1].symIndex), nullptr); }
#line 2289 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 99:
#line 406 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionDeclaratorNode(pContext, (yyloc), (yyvsp[-5].pNode), (yyvsp[-4].symIndex), (yyvsp[-2].pNode)); }
#line 2295 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 100:
#line 407 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionDeclaratorNode(pContext, (yyloc), nullptr, (yyvsp[-1].symIndex), nullptr); }
#line 2301 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 101:
#line 411 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionParameterNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), false); }
#line 2307 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 102:
#line 412 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionParameterNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), true); }
#line 2313 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 103:
#line 416 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 64); }
#line 2319 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 104:
#line 417 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 32); }
#line 2325 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 105:
#line 418 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 16); }
#line 2331 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 106:
#line 419 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 8); }
#line 2337 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 107:
#line 420 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Void); }
#line 2343 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 108:
#line 421 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Clock); }
#line 2349 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 109:
#line 422 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 1); }
#line 2355 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 110:
#line 423 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Unknown, (yyvsp[0].symIndex)); }
#line 2361 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 111:
#line 424 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2367 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 112:
#line 428 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); dynamic_cast<TypeNode*>((yyval.pNode))->SetModifier(TypeModifier::Wire); }
#line 2373 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 113:
#line 429 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); dynamic_cast<TypeNode*>((yyval.pNode))->SetModifier(TypeModifier::Const); }
#line 2379 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 114:
#line 430 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2385 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 115:
#line 434 "VSharp.y" /* yacc.c:1661  */
    {
	                                    							  (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<StructSpecifierNode*>((yyval.pNode))->SetName((yyvsp[-3].symIndex)); }
#line 2392 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 116:
#line 439 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructSpecifierNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 2398 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 117:
#line 440 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2404 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 118:
#line 444 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructDeclarationNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[-1].symIndex)); }
#line 2410 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 119:
#line 446 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructDeclarationNode(pContext, (yyloc), (yyvsp[-5].pNode), (yyvsp[-4].symIndex), (yyvsp[-2].constVal)); }
#line 2416 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 120:
#line 450 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2422 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 121:
#line 451 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<ModuleDefinitionNode*>((yyval.pNode))->SetStatementList((yyvsp[0].pNode)); }
#line 2428 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 122:
#line 455 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), nullptr); }
#line 2434 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 123:
#line 456 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2440 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 124:
#line 460 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 2446 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 125:
#line 461 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2452 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 126:
#line 465 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2458 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 127:
#line 466 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2464 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 128:
#line 467 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2470 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 129:
#line 468 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2476 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 130:
#line 472 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new DriveListDefinitionNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2482 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 131:
#line 476 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 2488 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 132:
#line 477 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2494 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 133:
#line 481 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new DriveDefinitionNode(pContext, (yyloc), (yyvsp[-2].constVal), (yyvsp[0].pNode)); }
#line 2500 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 134:
#line 482 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new DriveDefinitionNode(pContext, (yyloc), (yyvsp[-3].constVal), nullptr); }
#line 2506 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 135:
#line 486 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StateDeclaratorNode(pContext, (yyloc), (yyvsp[-1].symIndex), (yyvsp[0].pNode)); }
#line 2512 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 136:
#line 487 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StateDeclaratorNode(pContext, (yyloc), KnownStates::Initial, (yyvsp[0].pNode)); }
#line 2518 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 137:
#line 488 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StateDeclaratorNode(pContext, (yyloc), KnownStates::Always, (yyvsp[0].pNode)); }
#line 2524 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 138:
#line 492 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2530 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 139:
#line 496 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new VariableDeclarationNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), nullptr, nullptr); }
#line 2536 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 140:
#line 498 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new VariableDeclarationNode(pContext, (yyloc), (yyvsp[-4].pNode), (yyvsp[-3].symIndex), (yyvsp[-1].pNode), nullptr); }
#line 2542 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 141:
#line 499 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new VariableDeclarationNode(pContext, (yyloc), (yyvsp[-3].pNode), (yyvsp[-2].symIndex), nullptr, (yyvsp[0].pNode)); }
#line 2548 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 142:
#line 503 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2554 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 143:
#line 507 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), nullptr); }
#line 2560 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 144:
#line 508 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2566 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 145:
#line 512 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2572 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 146:
#line 513 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2578 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 147:
#line 517 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-1].symIndex), nullptr, nullptr); }
#line 2584 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 148:
#line 518 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-4].symIndex), (yyvsp[-2].pNode), nullptr); }
#line 2590 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 149:
#line 522 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-2].symIndex), nullptr, (yyvsp[0].pNode)); }
#line 2596 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 150:
#line 523 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-5].symIndex), (yyvsp[-3].pNode), (yyvsp[0].pNode)); }
#line 2602 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 151:
#line 524 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2608 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 152:
#line 528 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallParamNode(pContext, (yyloc), false, (yyvsp[0].pNode)); }
#line 2614 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 153:
#line 529 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallParamNode(pContext, (yyloc), true, (yyvsp[0].pNode)); }
#line 2620 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 154:
#line 530 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallParamNode(pContext, (yyloc)); }
#line 2626 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 155:
#line 534 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ReturnNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2632 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 156:
#line 537 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TransitionNode(pContext, (yyloc), (yyvsp[-1].symIndex)); }
#line 2638 "VSharp.tab.c" /* yacc.c:1661  */
    break;


#line 2642 "VSharp.tab.c" /* yacc.c:1661  */
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
#line 540 "VSharp.y" /* yacc.c:1906  */

