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
    TYPENAME_TOKEN = 325,
    IDENTIFIER = 326
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

#line 213 "VSharp.tab.c" /* yacc.c:355  */
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

#line 243 "VSharp.tab.c" /* yacc.c:358  */

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
#define YYLAST   698

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  164
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  311

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   326

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
      65,    66,    67,    68,    69,    70,    71
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   185,   185,   186,   190,   191,   192,   193,   194,   195,
     199,   202,   203,   207,   208,   212,   213,   217,   218,   222,
     223,   224,   225,   226,   227,   228,   232,   237,   238,   242,
     244,   245,   249,   253,   257,   261,   266,   267,   271,   272,
     273,   277,   278,   279,   283,   284,   285,   289,   290,   291,
     295,   296,   297,   298,   299,   303,   304,   305,   309,   310,
     314,   315,   319,   320,   324,   325,   329,   330,   334,   338,
     339,   340,   342,   343,   347,   348,   349,   350,   351,   355,
     359,   360,   364,   368,   372,   373,   377,   378,   382,   383,
     384,   388,   389,   393,   394,   398,   399,   403,   404,   408,
     412,   415,   416,   420,   421,   422,   426,   427,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   443,   444,   445,
     449,   454,   455,   459,   460,   465,   466,   470,   471,   475,
     476,   480,   481,   482,   483,   487,   491,   492,   496,   497,
     498,   502,   503,   504,   508,   512,   513,   515,   519,   523,
     524,   528,   529,   533,   534,   538,   539,   541,   545,   546,
     550,   551,   552,   556,   559
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
  "CONST_TOKEN", "BLOCKING_TOKEN", "NONBLOCKING_TOKEN", "TYPENAME_TOKEN",
  "IDENTIFIER", "$accept", "translation_unit", "external_declaration",
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
  "module_header_with_parameters", "module_header", "generic_param_list",
  "generic_param", "duplicate_type", "module_param_decl",
  "function_definition", "function_prototype",
  "function_header_with_parameters", "function_header",
  "function_param_decl", "type_name_specifier", "fully_specified_type",
  "struct_specifier", "struct_declaration_list", "struct_declaration",
  "module_definition", "module_states", "state_list", "module_member",
  "drive_list_definition", "drive_statement_list", "drive_definition",
  "module_state", "init_declarator_list", "single_declaration",
  "declaration_statement", "compound_statement", "function_call",
  "function_call_header_no_param", "function_call_header",
  "function_call_generic_list", "fn_call_arg", "return_statement",
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326
};
# endif

#define YYPACT_NINF -175

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-175)))

#define YYTABLE_NINF -116

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      73,    16,    34,  -175,  -175,  -175,  -175,  -175,   -44,  -175,
      17,  -175,    30,    99,   584,   584,  -175,    38,  -175,  -175,
    -175,  -175,    64,    95,   108,  -175,   128,    98,   162,  -175,
      65,  -175,  -175,   167,  -175,   114,   142,   316,   155,   121,
     175,   212,  -175,  -175,  -175,  -175,  -175,   258,  -175,  -175,
     191,   518,  -175,  -175,   171,   297,  -175,  -175,   162,   518,
    -175,   172,   116,  -175,  -175,  -175,   207,  -175,   386,  -175,
    -175,    14,   316,    14,    14,   150,  -175,   161,   174,   159,
     -11,   158,   196,   195,   233,    49,  -175,   210,   -27,  -175,
    -175,  -175,  -175,   213,   111,   188,  -175,   518,  -175,    -2,
     201,  -175,  -175,  -175,   278,  -175,  -175,  -175,  -175,  -175,
     190,  -175,   316,   234,   200,  -175,   236,   -13,   363,  -175,
    -175,  -175,  -175,  -175,   244,    60,   203,  -175,  -175,  -175,
    -175,   204,  -175,   316,  -175,   316,   316,   208,   209,    94,
    -175,   219,   -27,   241,   -27,   -27,   -24,   180,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,  -175,   220,   316,  -175,
    -175,   180,   250,    77,  -175,   221,   452,  -175,   128,   128,
     128,   -10,  -175,  -175,  -175,   264,   316,   265,   316,  -175,
    -175,  -175,  -175,   316,    89,  -175,  -175,   256,   237,   262,
    -175,   273,   386,  -175,  -175,    14,  -175,    14,  -175,  -175,
    -175,  -175,   119,  -175,  -175,   161,   161,   174,   174,   159,
     159,   159,   159,   -11,   -11,   158,   196,   195,   233,   270,
    -175,    12,  -175,   276,   105,  -175,    25,  -175,  -175,  -175,
    -175,  -175,   280,   150,    18,  -175,   283,  -175,   284,  -175,
     289,   286,   277,  -175,  -175,  -175,  -175,   -27,   -27,   281,
     316,   316,   316,  -175,  -175,  -175,  -175,  -175,   295,    -8,
    -175,  -175,  -175,   268,   128,  -175,  -175,   180,  -175,  -175,
     266,   269,   301,  -175,    60,   169,  -175,   271,  -175,  -175,
     307,  -175,   316,   309,    -7,  -175,   128,  -175,   310,   287,
    -175,  -175,  -175,   291,   627,   429,   495,  -175,   561,  -175,
    -175
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,   108,   109,   110,   111,   112,     0,   113,
       0,   114,     0,     0,     0,     0,   115,     0,     2,     6,
       7,     9,     0,     0,     0,     5,     0,     0,     0,   119,
       0,     8,     4,     0,   144,     0,     0,     0,     0,     0,
       0,     0,   117,   118,     1,     3,   125,     0,   126,    84,
       0,     0,    85,    86,     0,     0,    99,   100,     0,     0,
     101,     0,   145,    82,    95,    96,     0,    88,     0,    76,
      77,     0,     0,     0,     0,    83,    41,    44,    47,    50,
      55,    58,    60,    62,    64,    66,    68,     0,    38,    69,
      75,    74,    72,     0,     0,     0,   105,     0,    10,     0,
       0,   127,   148,   133,     0,   129,   134,   131,   132,    87,
       0,    97,     0,     0,     0,   149,     0,    83,     0,    17,
      25,    19,    20,    21,     0,    38,     0,    22,    24,    23,
     102,     0,   106,     0,   103,     0,     0,     0,     0,     0,
      91,     0,    39,     0,    40,    80,     0,   153,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   116,     0,     0,   152,
     151,     0,    15,     0,    13,     0,     0,   121,     0,     0,
       0,     0,   128,   130,    98,     0,     0,     0,     0,   150,
      18,    32,    34,     0,   145,   107,   147,     0,     0,     0,
      94,     0,     0,    93,    78,     0,    79,     0,   162,   160,
     155,   158,     0,    42,    43,    45,    46,    48,    49,    51,
      52,    53,    54,    56,    57,    59,    61,    63,    65,     0,
      73,     0,   157,     0,     0,    11,     0,   120,   122,   142,
     143,   141,     0,     0,     0,   136,     0,   163,     0,   164,
       0,     0,     0,   146,    90,    89,    92,    81,   161,     0,
       0,     0,     0,    70,    16,    12,    14,   123,     0,     0,
     135,   137,   140,     0,     0,    33,   104,   154,   159,    67,
       0,     0,     0,   138,     0,     0,    35,    37,   156,    71,
       0,   139,     0,     0,     0,    27,     0,   124,     0,     0,
      26,    28,    36,     0,     0,     0,     0,    30,     0,    31,
      29
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -175,  -175,   320,  -175,  -175,  -175,   109,   -85,  -117,  -175,
    -175,    54,  -175,    85,  -175,  -175,  -175,    72,    75,    78,
       5,    76,   197,   199,   202,   198,  -175,  -175,   -37,   -52,
    -175,  -175,  -175,   124,  -175,  -175,  -175,  -175,  -175,   157,
    -175,   317,   -40,  -175,  -175,  -175,   318,   223,     9,  -175,
    -175,   205,  -175,  -175,  -175,   274,  -175,  -175,   135,  -175,
    -175,  -175,   -34,  -174,  -173,  -175,  -175,  -175,  -169,  -175,
    -175
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    18,    19,    20,   173,   174,   118,   119,   120,
     294,   295,   121,   122,   193,   123,   286,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,   124,    88,
      89,    90,   146,   102,    91,    22,    23,    24,   139,   140,
      66,    53,    25,    26,    27,    28,    60,    29,   126,    31,
     176,   177,    32,    48,   104,   105,   106,   244,   245,   107,
      33,    34,   127,    56,    92,    93,    94,   212,   210,   128,
     129
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      87,   190,   232,   125,   239,   240,   241,   103,   246,    30,
     178,   179,   282,   108,   292,   242,   293,    69,    70,   142,
     167,   144,   145,   147,   205,   148,    30,    38,    72,   155,
     156,   157,   158,    54,   168,   143,   206,    61,    44,    69,
      70,     1,   262,   242,     2,     3,     4,     5,     6,     7,
      72,    74,    35,   300,   267,     8,    30,     9,  -115,    54,
     110,   243,    10,    75,   103,   164,   125,    61,   131,   180,
     108,   246,    37,    74,   263,   185,     1,   141,   270,     2,
       3,     4,     5,     6,     7,    75,   268,    36,    39,   243,
       8,   192,     9,    46,    11,    12,   196,    10,   197,   198,
     287,    40,   165,    13,    14,    15,   175,   167,   288,    16,
     209,   211,    51,    30,     2,     3,     4,     5,     6,     7,
     133,   168,   302,    47,    21,   234,    41,     9,   229,    11,
      12,   231,    49,   201,   209,    57,    62,   235,    13,    14,
      15,    21,   202,    50,    16,    52,    58,   133,   170,   248,
     136,   250,   134,   257,   135,   258,   251,    96,   259,   171,
     219,   220,   221,   222,    11,   265,    59,   260,     2,     3,
       4,     5,     6,     7,    14,    15,   172,   136,    67,    16,
      68,     9,    64,    65,   207,   175,   147,    55,   148,   190,
     292,   190,   293,   149,   150,    51,    63,     2,     3,     4,
       5,     6,     7,   153,   154,    69,    70,   208,   151,   152,
       9,   141,   159,   160,    95,    71,    72,   284,    11,   306,
     308,   213,   214,   278,   279,   280,   215,   216,    14,    15,
      73,   217,   218,    16,    97,   223,   224,    42,    43,    74,
     209,    98,   111,   132,   137,   161,   162,    11,   163,   166,
     169,    75,   125,   125,   125,   298,   125,    14,    15,   172,
     181,   184,    16,    99,     2,     3,     4,     5,     6,     7,
     186,   187,   188,   191,   194,   195,   100,     9,   204,   199,
     200,   233,    10,    99,     2,     3,     4,     5,     6,     7,
     203,   230,   236,   247,   249,   252,   100,     9,   254,   253,
     261,   264,    10,     2,     3,     4,     5,     6,     7,   255,
     269,   112,   272,   276,    11,   275,     9,   277,   101,   113,
     281,   273,    69,    70,    14,    15,   274,   285,   289,    16,
     291,   290,    71,    72,    11,   296,   297,    45,   182,   299,
     303,    69,    70,   266,    14,    15,   304,    73,   301,    16,
     305,    71,    72,    11,   283,   114,    74,   115,   225,   256,
     116,   226,   228,    14,    15,   227,    73,   109,   117,     2,
       3,     4,     5,     6,     7,    74,   130,   112,   183,   271,
       0,   238,     9,     0,     0,   113,     0,    75,    69,    70,
       0,     0,     2,     3,     4,     5,     6,     7,    71,    72,
       0,     0,     0,     0,     0,     9,     0,     0,     0,     0,
       0,     0,     0,    73,     0,     0,     0,     0,     0,    11,
       0,   114,    74,   189,     0,     0,   116,     0,     0,    14,
      15,     0,     0,     0,   117,     2,     3,     4,     5,     6,
       7,     0,    11,   112,     0,     0,     0,     0,     9,     0,
       0,   113,    14,    15,    69,    70,   138,    16,     2,     3,
       4,     5,     6,     7,    71,    72,     0,     0,     0,     0,
       0,     9,     0,     0,     0,     0,     0,     0,     0,    73,
       0,     0,     0,     0,     0,    11,     0,   114,    74,   307,
       0,     0,   116,     0,     0,    14,    15,     0,     0,     0,
     117,     2,     3,     4,     5,     6,     7,     0,    11,   112,
       0,     0,   237,     0,     9,     0,     0,   113,    14,    15,
      69,    70,     0,    16,     2,     3,     4,     5,     6,     7,
      71,    72,     0,     0,     0,     0,     0,     9,     0,     0,
       0,     0,     0,     0,     0,    73,     0,     0,     0,     0,
       0,    11,     0,   114,    74,   309,     0,     0,   116,     0,
       0,    14,    15,     0,     0,     0,   117,     2,     3,     4,
       5,     6,     7,     0,    11,   112,     0,     0,     0,     0,
       9,     0,     0,   113,    14,    15,    69,    70,     0,    16,
       2,     3,     4,     5,     6,     7,    71,    72,     0,     0,
       0,     0,     0,     9,     0,     0,     0,     0,     0,     0,
       0,    73,     0,     0,     0,     0,     0,    11,     0,   114,
      74,   310,     0,     0,   116,     0,     0,    14,    15,     0,
       0,     0,   117,     2,     3,     4,     5,     6,     7,     0,
      11,   112,     0,     0,     0,     0,     9,     0,     0,   113,
       0,     0,    69,    70,     0,    16,     0,     0,     0,     0,
       0,     0,    71,    72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,     0,     0,
       0,     0,     0,    11,     0,   114,    74,     0,     0,     0,
     116,     0,     0,    14,    15,     0,     0,     0,   117
};

static const yytype_int16 yycheck[] =
{
      37,   118,   171,    55,   178,   179,   180,    47,   181,     0,
      12,    13,    20,    47,    21,    25,    23,    25,    26,    71,
      47,    73,    74,    36,    48,    38,    17,    71,    36,    40,
      41,    42,    43,    24,    61,    72,    60,    28,     0,    25,
      26,     3,    30,    25,     6,     7,     8,     9,    10,    11,
      36,    59,    36,    60,    29,    17,    47,    19,    71,    50,
      51,    71,    24,    71,   104,    16,   118,    58,    59,    71,
     104,   244,    38,    59,    62,   112,     3,    68,    60,     6,
       7,     8,     9,    10,    11,    71,    61,    71,    71,    71,
      17,    31,    19,    29,    56,    57,   133,    24,   135,   136,
     274,    71,    53,    65,    66,    67,    97,    47,   277,    71,
     147,   148,     4,   104,     6,     7,     8,     9,    10,    11,
      31,    61,   296,    59,     0,    48,    27,    19,   165,    56,
      57,   168,    37,    39,   171,    37,    71,    60,    65,    66,
      67,    17,    48,    48,    71,    37,    48,    31,    37,   186,
      61,   188,    36,   205,    38,   207,   193,    36,    39,    48,
     155,   156,   157,   158,    56,    60,     4,    48,     6,     7,
       8,     9,    10,    11,    66,    67,    71,    61,    36,    71,
      38,    19,    68,    69,     4,   176,    36,    59,    38,   306,
      21,   308,    23,    32,    33,     4,    29,     6,     7,     8,
       9,    10,    11,    44,    45,    25,    26,    27,    34,    35,
      19,   202,    54,    55,    59,    35,    36,   269,    56,   304,
     305,   149,   150,   260,   261,   262,   151,   152,    66,    67,
      50,   153,   154,    71,    59,   159,   160,    14,    15,    59,
     277,    29,    71,    71,    37,    49,    51,    56,    15,    39,
      37,    71,   304,   305,   306,   292,   308,    66,    67,    71,
      59,    71,    71,     5,     6,     7,     8,     9,    10,    11,
      36,    71,    36,    29,    71,    71,    18,    19,    37,    71,
      71,    31,    24,     5,     6,     7,     8,     9,    10,    11,
      71,    71,    71,    29,    29,    39,    18,    19,    36,    62,
      30,    25,    24,     6,     7,     8,     9,    10,    11,    36,
      30,    14,    29,    36,    56,    29,    19,    36,    60,    22,
      25,    37,    25,    26,    66,    67,    37,    59,    62,    71,
      29,    62,    35,    36,    56,    64,    29,    17,    60,    30,
      30,    25,    26,   234,    66,    67,    59,    50,   294,    71,
      59,    35,    36,    56,   269,    58,    59,    60,   161,   202,
      63,   162,   164,    66,    67,   163,    50,    50,    71,     6,
       7,     8,     9,    10,    11,    59,    58,    14,   104,   244,
      -1,   176,    19,    -1,    -1,    22,    -1,    71,    25,    26,
      -1,    -1,     6,     7,     8,     9,    10,    11,    35,    36,
      -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,
      67,    -1,    -1,    -1,    71,     6,     7,     8,     9,    10,
      11,    -1,    56,    14,    -1,    -1,    -1,    -1,    19,    -1,
      -1,    22,    66,    67,    25,    26,    70,    71,     6,     7,
       8,     9,    10,    11,    35,    36,    -1,    -1,    -1,    -1,
      -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,    60,
      -1,    -1,    63,    -1,    -1,    66,    67,    -1,    -1,    -1,
      71,     6,     7,     8,     9,    10,    11,    -1,    56,    14,
      -1,    -1,    60,    -1,    19,    -1,    -1,    22,    66,    67,
      25,    26,    -1,    71,     6,     7,     8,     9,    10,    11,
      35,    36,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,
      -1,    66,    67,    -1,    -1,    -1,    71,     6,     7,     8,
       9,    10,    11,    -1,    56,    14,    -1,    -1,    -1,    -1,
      19,    -1,    -1,    22,    66,    67,    25,    26,    -1,    71,
       6,     7,     8,     9,    10,    11,    35,    36,    -1,    -1,
      -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    56,    -1,    58,
      59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,    -1,
      -1,    -1,    71,     6,     7,     8,     9,    10,    11,    -1,
      56,    14,    -1,    -1,    -1,    -1,    19,    -1,    -1,    22,
      -1,    -1,    25,    26,    -1,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    58,    59,    -1,    -1,    -1,
      63,    -1,    -1,    66,    67,    -1,    -1,    -1,    71
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,     8,     9,    10,    11,    17,    19,
      24,    56,    57,    65,    66,    67,    71,    73,    74,    75,
      76,   105,   107,   108,   109,   114,   115,   116,   117,   119,
     120,   121,   124,   132,   133,    36,    71,    38,    71,    71,
      71,    27,   119,   119,     0,    74,    29,    59,   125,    37,
      48,     4,    37,   113,   120,    59,   135,    37,    48,     4,
     118,   120,    71,    29,    68,    69,   112,    36,    38,    25,
      26,    35,    36,    50,    59,    71,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   106,   136,   137,   138,    59,    36,    59,    29,     5,
      18,    60,   105,   114,   126,   127,   128,   131,   134,   113,
     120,    71,    14,    22,    58,    60,    63,    71,    79,    80,
      81,    84,    85,    87,   100,   101,   120,   134,   141,   142,
     118,   120,    71,    31,    36,    38,    61,    37,    70,   110,
     111,   120,   101,   100,   101,   101,   104,    36,    38,    32,
      33,    34,    35,    44,    45,    40,    41,    42,    43,    54,
      55,    49,    51,    15,    16,    53,    39,    47,    61,    37,
      37,    48,    71,    77,    78,   120,   122,   123,    12,    13,
      71,    59,    60,   127,    71,   100,    36,    71,    36,    60,
      80,    29,    31,    86,    71,    71,   100,   100,   100,    71,
      71,    39,    48,    71,    37,    48,    60,     4,    27,   100,
     140,   100,   139,    89,    89,    90,    90,    91,    91,    92,
      92,    92,    92,    93,    93,    94,    95,    96,    97,   100,
      71,   100,   140,    31,    48,    60,    71,    60,   123,   135,
     135,   135,    25,    71,   129,   130,   136,    29,   100,    29,
     100,   100,    39,    62,    36,    36,   111,   101,   101,    39,
      48,    30,    30,    62,    25,    60,    78,    29,    61,    30,
      60,   130,    29,    37,    37,    29,    36,    36,   100,   100,
     100,    25,    20,    85,   101,    59,    88,   135,   140,    62,
      62,    29,    21,    23,    82,    83,    64,    29,   100,    30,
      60,    83,   135,    30,    59,    59,    79,    60,    79,    60,
      60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    72,    73,    73,    74,    74,    74,    74,    74,    74,
      75,    76,    76,    77,    77,    78,    78,    79,    79,    80,
      80,    80,    80,    80,    80,    80,    81,    82,    82,    83,
      83,    83,    84,    85,    86,    87,    88,    88,    89,    89,
      89,    90,    90,    90,    91,    91,    91,    92,    92,    92,
      93,    93,    93,    93,    93,    94,    94,    94,    95,    95,
      96,    96,    97,    97,    98,    98,    99,    99,   100,   101,
     101,   101,   101,   101,   102,   102,   102,   102,   102,   103,
     104,   104,   105,   106,   107,   107,   108,   108,   109,   109,
     109,   110,   110,   111,   111,   112,   112,   113,   113,   114,
     115,   116,   116,   117,   117,   117,   118,   118,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   120,   120,   120,
     121,   122,   122,   123,   123,   124,   124,   125,   125,   126,
     126,   127,   127,   127,   127,   128,   129,   129,   130,   130,
     130,   131,   131,   131,   132,   133,   133,   133,   134,   135,
     135,   136,   136,   137,   137,   138,   138,   138,   139,   139,
     140,   140,   140,   141,   142
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       3,     5,     6,     1,     3,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     7,     1,     2,     6,
       5,     5,     2,     4,     1,     5,     3,     1,     1,     2,
       2,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     5,     1,     1,
       4,     6,     1,     3,     1,     1,     1,     1,     3,     3,
       1,     3,     2,     1,     2,     2,     2,     3,     3,     6,
       6,     1,     3,     2,     2,     1,     1,     2,     3,     2,
       2,     2,     3,     3,     6,     3,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     2,     2,     1,
       5,     1,     2,     3,     6,     2,     2,     2,     3,     1,
       2,     1,     1,     1,     1,     4,     1,     2,     3,     4,
       2,     3,     3,     3,     1,     2,     5,     4,     1,     2,
       3,     2,     2,     2,     5,     3,     6,     3,     1,     3,
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
#line 190 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddModuleDef((yyval.pNode)); }
#line 1755 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 5:
#line 191 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddFunction((yyval.pNode)); }
#line 1761 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 6:
#line 192 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddImport((yyval.pNode)); }
#line 1767 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 193 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddTypeDef((yyval.pNode)); }
#line 1773 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 8:
#line 194 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddTypeDef((yyval.pNode)); }
#line 1779 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 195 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); pContext->AddGlobal((yyval.pNode)); }
#line 1785 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 199 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ImportStatementNode(pContext, (yyloc)); }
#line 1791 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 202 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<EnumDefinitionNode*>((yyval.pNode))->SetIdentifier((yyvsp[-3].symIndex)); }
#line 1797 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 203 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<EnumDefinitionNode*>((yyval.pNode))->SetIdentifier((yyvsp[-4].symIndex)); }
#line 1803 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 207 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new EnumDefinitionNode(pContext, (yyloc), (yyvsp[0]._EnumItem)); }
#line 1809 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 208 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<EnumDefinitionNode*>((yyval.pNode))->AddEnum((yyvsp[0]._EnumItem)); }
#line 1815 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 15:
#line 212 "VSharp.y" /* yacc.c:1661  */
    { (yyval._EnumItem) = EnumItem((yyvsp[0].symIndex)); }
#line 1821 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 213 "VSharp.y" /* yacc.c:1661  */
    { (yyval._EnumItem) = EnumItem((yyvsp[-2].symIndex), (yyvsp[0].constVal)); }
#line 1827 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 217 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 1833 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 218 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 1839 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 222 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1845 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 223 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1851 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 224 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1857 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 225 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1863 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 226 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1869 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 227 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1875 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 228 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1881 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 233 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<SwitchStatementNode*>((yyval.pNode))->SetTest((yyvsp[-4].pNode)); }
#line 1887 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 237 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new SwitchStatementNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 1893 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 238 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<SwitchStatementNode*>((yyval.pNode))->AddNode((yyvsp[0].pNode)); }
#line 1899 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 243 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new CaseStatementNode(pContext, (yyloc), (yyvsp[-4].pNode), (yyvsp[-1].pNode)); }
#line 1905 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 244 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new CaseStatementNode(pContext, (yyloc), (yyvsp[-3].pNode), nullptr); }
#line 1911 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 245 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new CaseStatementNode(pContext, (yyloc), nullptr, (yyvsp[-1].pNode)); }
#line 1917 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 249 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ExpressionStatementNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 1923 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 253 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new AssignmentNode(pContext, (yyloc), (yyvsp[-3].pNode), (yyvsp[-1].pNode)); }
#line 1929 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 262 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); dynamic_cast<IfStatementNode*>((yyval.pNode))->SetExpression((yyvsp[-2].pNode)); }
#line 1935 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 266 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IfStatementNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode)); }
#line 1941 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 267 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IfStatementNode(pContext, (yyloc), (yyvsp[0].pNode), nullptr); }
#line 1947 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 271 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1953 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 272 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new UnaryOperatorNode(pContext, (yyloc), (yyvsp[0].pNode), Operator::Negate); }
#line 1959 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 40:
#line 273 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new UnaryOperatorNode(pContext, (yyloc), (yyvsp[0].pNode), Operator::LogicalNot); }
#line 1965 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 41:
#line 277 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1971 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 42:
#line 278 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Multiply); }
#line 1977 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 279 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Divide); }
#line 1983 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 44:
#line 283 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 1989 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 284 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Add); }
#line 1995 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 285 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Subtract); }
#line 2001 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 289 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2007 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 48:
#line 290 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::ShiftLeft); }
#line 2013 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 291 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::ShiftRight); }
#line 2019 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 295 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2025 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 296 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LessThan); }
#line 2031 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 52:
#line 297 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::GreaterThan); }
#line 2037 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 298 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LessThanEqual); }
#line 2043 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 54:
#line 299 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::GreaterThanEqual); }
#line 2049 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 303 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2055 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 56:
#line 304 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::Equal); }
#line 2061 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 305 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::NotEqual); }
#line 2067 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 309 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2073 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 310 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::BitwiseXor); }
#line 2079 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 314 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2085 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 315 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::BitwiseOr); }
#line 2091 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 319 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2097 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 320 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LogicalAnd); }
#line 2103 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 324 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2109 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 325 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new OperatorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].pNode), Operator::LogicalOr); }
#line 2115 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 329 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2121 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 330 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TernaryExpressionNode(pContext, (yyloc), (yyvsp[-4].pNode), (yyvsp[-2].pNode), (yyvsp[0].pNode)); }
#line 2127 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 334 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2133 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 338 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2139 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 339 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IndexSelectionNode(pContext, (yyloc), (yyvsp[-3].pNode), (yyvsp[-1].pNode)); }
#line 2145 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 341 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new BitSelectionNode(pContext, (yyloc), (yyvsp[-5].pNode), (yyvsp[-3].pNode), (yyvsp[-1].pNode)); }
#line 2151 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 342 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2157 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 343 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FieldSelectionNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[0].symIndex)); }
#line 2163 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 347 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2169 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 348 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2175 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 349 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, (yyloc), (yyvsp[0].constVal)); }
#line 2181 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 350 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ConstantNode(pContext, (yyloc), (yyvsp[0].constVal)); }
#line 2187 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 351 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ParenNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2193 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 79:
#line 355 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new GlomExpressionNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2199 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 80:
#line 359 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 2205 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 81:
#line 360 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<ListNode*>((yyval.pNode))->AddNode((yyvsp[0].pNode)); }
#line 2211 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 82:
#line 364 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2217 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 83:
#line 368 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new IdentifierNode(pContext, (yyloc), (yyvsp[0].symIndex)); }
#line 2223 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 84:
#line 372 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2229 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 85:
#line 373 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2235 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 86:
#line 377 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<ModuleDefinitionNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 2241 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 87:
#line 378 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<ModuleDefinitionNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 2247 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 88:
#line 382 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleDefinitionNode(pContext, (yyloc), (yyvsp[-1].symIndex), nullptr, FunctionExpandType::None); }
#line 2253 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 89:
#line 383 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleDefinitionNode(pContext, (yyloc), (yyvsp[-4].symIndex), (yyvsp[-2].pNode), FunctionExpandType::None); }
#line 2259 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 90:
#line 384 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleDefinitionNode(pContext, (yyloc), (yyvsp[-1].symIndex), nullptr, (yyvsp[-3]._FunctionExpandType)); }
#line 2265 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 91:
#line 388 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 2271 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 92:
#line 389 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<ListNode*>((yyvsp[-2].pNode))->AddNode((yyvsp[0].pNode)); }
#line 2277 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 93:
#line 393 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new GenericParameterNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex)); }
#line 2283 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 94:
#line 394 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new GenericParameterNode(pContext, (yyloc), nullptr, (yyvsp[0].symIndex)); }
#line 2289 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 95:
#line 398 "VSharp.y" /* yacc.c:1661  */
    { (yyval._FunctionExpandType) = FunctionExpandType::StageBlocking; }
#line 2295 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 96:
#line 399 "VSharp.y" /* yacc.c:1661  */
    { (yyval._FunctionExpandType) = FunctionExpandType::StageNonblocking; }
#line 2301 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 97:
#line 403 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleParameterNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), false); }
#line 2307 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 98:
#line 404 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ModuleParameterNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), true); }
#line 2313 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 99:
#line 408 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->SetStatementList((yyvsp[0].pNode)); }
#line 2319 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 100:
#line 412 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2325 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 101:
#line 415 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 2331 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 102:
#line 416 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<FunctionDeclaratorNode*>((yyval.pNode))->AddParameter((yyvsp[0].pNode)); }
#line 2337 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 103:
#line 420 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionDeclaratorNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[-1].symIndex), nullptr); }
#line 2343 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 104:
#line 421 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionDeclaratorNode(pContext, (yyloc), (yyvsp[-5].pNode), (yyvsp[-4].symIndex), (yyvsp[-2].pNode)); }
#line 2349 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 105:
#line 422 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionDeclaratorNode(pContext, (yyloc), nullptr, (yyvsp[-1].symIndex), nullptr); }
#line 2355 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 106:
#line 426 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionParameterNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), false); }
#line 2361 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 107:
#line 427 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionParameterNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), true); }
#line 2367 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 108:
#line 431 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 64); }
#line 2373 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 109:
#line 432 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 32); }
#line 2379 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 110:
#line 433 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 16); }
#line 2385 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 111:
#line 434 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 8); }
#line 2391 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 112:
#line 435 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Void); }
#line 2397 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 113:
#line 436 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Clock); }
#line 2403 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 114:
#line 437 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Register, 1); }
#line 2409 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 115:
#line 438 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), TypeClass::Unknown, (yyvsp[0].symIndex)); }
#line 2415 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 116:
#line 439 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TypeNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2421 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 117:
#line 443 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); dynamic_cast<TypeNode*>((yyval.pNode))->SetModifier(TypeModifier::Wire); }
#line 2427 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 118:
#line 444 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); dynamic_cast<TypeNode*>((yyval.pNode))->SetModifier(TypeModifier::Const); }
#line 2433 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 119:
#line 445 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2439 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 120:
#line 449 "VSharp.y" /* yacc.c:1661  */
    {
	                                    							  (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<StructSpecifierNode*>((yyval.pNode))->SetName((yyvsp[-3].symIndex)); }
#line 2446 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 121:
#line 454 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructSpecifierNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 2452 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 122:
#line 455 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2458 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 123:
#line 459 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructDeclarationNode(pContext, (yyloc), (yyvsp[-2].pNode), (yyvsp[-1].symIndex)); }
#line 2464 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 124:
#line 461 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StructDeclarationNode(pContext, (yyloc), (yyvsp[-5].pNode), (yyvsp[-4].symIndex), (yyvsp[-2].constVal)); }
#line 2470 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 125:
#line 465 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2476 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 126:
#line 466 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); dynamic_cast<ModuleDefinitionNode*>((yyval.pNode))->SetStatementList((yyvsp[0].pNode)); }
#line 2482 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 127:
#line 470 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), nullptr); }
#line 2488 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 128:
#line 471 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2494 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 129:
#line 475 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 2500 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 130:
#line 476 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2506 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 131:
#line 480 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2512 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 132:
#line 481 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2518 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 133:
#line 482 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2524 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 134:
#line 483 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2530 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 135:
#line 487 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new DriveListDefinitionNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2536 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 136:
#line 491 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 2542 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 137:
#line 492 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2548 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 138:
#line 496 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new DriveDefinitionNode(pContext, (yyloc), (yyvsp[-2].constVal), (yyvsp[0].pNode)); }
#line 2554 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 139:
#line 497 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new DriveDefinitionNode(pContext, (yyloc), (yyvsp[-3].constVal), nullptr); }
#line 2560 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 140:
#line 498 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ExpressionStatementNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2566 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 141:
#line 502 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StateDeclaratorNode(pContext, (yyloc), (yyvsp[-1].symIndex), (yyvsp[0].pNode)); }
#line 2572 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 142:
#line 503 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StateDeclaratorNode(pContext, (yyloc), KnownStates::Initial, (yyvsp[0].pNode)); }
#line 2578 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 143:
#line 504 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new StateDeclaratorNode(pContext, (yyloc), KnownStates::Always, (yyvsp[0].pNode)); }
#line 2584 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 144:
#line 508 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2590 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 145:
#line 512 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new VariableDeclarationNode(pContext, (yyloc), (yyvsp[-1].pNode), (yyvsp[0].symIndex), nullptr, nullptr); }
#line 2596 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 146:
#line 514 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new VariableDeclarationNode(pContext, (yyloc), (yyvsp[-4].pNode), (yyvsp[-3].symIndex), (yyvsp[-1].pNode), nullptr); }
#line 2602 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 147:
#line 515 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new VariableDeclarationNode(pContext, (yyloc), (yyvsp[-3].pNode), (yyvsp[-2].symIndex), nullptr, (yyvsp[0].pNode)); }
#line 2608 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 148:
#line 519 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[0].pNode); }
#line 2614 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 149:
#line 523 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), nullptr); }
#line 2620 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 150:
#line 524 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2626 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 151:
#line 528 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2632 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 152:
#line 529 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-1].pNode); }
#line 2638 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 153:
#line 533 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-1].symIndex), nullptr, nullptr); }
#line 2644 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 154:
#line 534 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-4].symIndex), (yyvsp[-2].pNode), nullptr); }
#line 2650 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 155:
#line 538 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-2].symIndex), nullptr, (yyvsp[0].pNode)); }
#line 2656 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 156:
#line 540 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallNode(pContext, (yyloc), (yyvsp[-5].symIndex), (yyvsp[-3].pNode), (yyvsp[0].pNode)); }
#line 2662 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 157:
#line 541 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); (yyval.pNode)->AddNode((yyvsp[0].pNode)); }
#line 2668 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 158:
#line 545 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ListNode(pContext, (yyloc), (yyvsp[0].pNode)); }
#line 2674 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 159:
#line 546 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = (yyvsp[-2].pNode); dynamic_cast<ListNode*>((yyvsp[-2].pNode))->AddNode((yyvsp[0].pNode)); }
#line 2680 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 160:
#line 550 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallParamNode(pContext, (yyloc), false, (yyvsp[0].pNode)); }
#line 2686 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 161:
#line 551 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallParamNode(pContext, (yyloc), true, (yyvsp[0].pNode)); }
#line 2692 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 162:
#line 552 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new FunctionCallParamNode(pContext, (yyloc)); }
#line 2698 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 163:
#line 556 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new ReturnNode(pContext, (yyloc), (yyvsp[-1].pNode)); }
#line 2704 "VSharp.tab.c" /* yacc.c:1661  */
    break;

  case 164:
#line 559 "VSharp.y" /* yacc.c:1661  */
    { (yyval.pNode) = new TransitionNode(pContext, (yyloc), (yyvsp[-1].symIndex)); }
#line 2710 "VSharp.tab.c" /* yacc.c:1661  */
    break;


#line 2714 "VSharp.tab.c" /* yacc.c:1661  */
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
#line 562 "VSharp.y" /* yacc.c:1906  */

