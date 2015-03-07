/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "project.y"

#include <stdio.h>
#include "project.h"
#include <string>
#include <iostream>
#include "llvm/IR/Verifier.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

using namespace std;
using namespace llvm;

int yydebug=1;
int yylex();
void yyerror (char const *s) {}

program_node *root;

/* Line 371 of yacc.c  */
#line 89 "project.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "project.tab.h".  */
#ifndef YY_YY_PROJECT_TAB_H_INCLUDED
# define YY_YY_PROJECT_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BOOLEAN_ = 258,
     BREAK_ = 259,
     CALLOUT_ = 260,
     CLASS_ = 261,
     CONTINUE_ = 262,
     ELSE_ = 263,
     FALSE_ = 264,
     FOR_ = 265,
     IF_ = 266,
     INT_ = 267,
     RETURN_ = 268,
     TRUE_ = 269,
     VOID_ = 270,
     PROGRAM_ = 271,
     DIGIT_ = 272,
     ID_ = 273,
     HEX_DIGIT_ = 274,
     STRING_LITERAL = 275,
     CHAR_LITERAL = 276,
     LT_ = 277,
     GT_ = 278,
     LEQ_ = 279,
     GEQ_ = 280,
     EQ_ = 281,
     PLUS_EQ_ = 282,
     MINUS_EQ_ = 283,
     PLUS_ = 284,
     MINUS_ = 285,
     MULT_ = 286,
     DIV_ = 287,
     PERCENT_ = 288,
     EQEQ_ = 289,
     NEQ_ = 290,
     ANDAND_ = 291,
     OROR_ = 292,
     LOG_NOT_ = 293,
     ROUND_ = 294,
     LOC_ = 295,
     UN_MINUS_ = 296
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 23 "project.y"

	char *str;
	char *typ;
	char *bol;
	int inti;
	program_node *prognode;
	method_node *methodnode;
	list<method_node *> *methodnodelist;
	field_node *fieldnode;
	field *fld;
	list<field *> *fldlist;
	list<field_node *> *fieldnodelist;
	arg_node *argnode;
	list<arg_node *> *argnodelist;
	block_node *blocknode;
	variable_node *variablenode;
	list<variable_node *> *variablenodelist;
	id_node *idnode;
	list<id_node *> *idnodelist;
	statement_node *statementnode;
	list<statement_node *> *statementnodelist;
	literal_node *literalnode;
	expr_node *exprnode;
	list<expr_node *> *exprnodelist;
	else_block_node *elseblocknode;
	location_node *locationnode;
	method_call_node *methodcallnode;
	callout_arg_node *calloutargnode;
	list<callout_arg_node *> *calloutargnodelist;


/* Line 387 of yacc.c  */
#line 205 "project.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_PROJECT_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 233 "project.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   314

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNRULES -- Number of states.  */
#define YYNSTATES  157

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,     2,    47,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    10,    13,    14,    17,    20,    26,    30,
      37,    40,    41,    48,    55,    57,    58,    61,    66,    71,
      74,    75,    78,    81,    85,    88,    89,    94,    97,   104,
     112,   116,   119,   122,   124,   127,   128,   130,   131,   133,
     135,   137,   139,   144,   149,   155,   158,   159,   161,   165,
     167,   169,   171,   175,   177,   178,   180,   182,   184,   188,
     192,   196,   200,   204,   208,   212,   216,   220,   224,   228,
     232,   236,   239,   242,   246,   248,   250,   252,   254,   256,
     258,   260,   262
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,     6,    16,    42,    51,    54,    43,    -1,
      51,    52,    -1,    -1,    78,    53,    -1,    18,    44,    -1,
      18,    45,    77,    46,    44,    -1,    18,    47,    53,    -1,
      18,    45,    77,    46,    47,    53,    -1,    55,    54,    -1,
      -1,    78,    18,    39,    56,    48,    58,    -1,    15,    18,
      39,    56,    48,    58,    -1,    57,    -1,    -1,    78,    18,
      -1,    78,    18,    47,    57,    -1,    42,    59,    62,    43,
      -1,    60,    59,    -1,    -1,    78,    61,    -1,    18,    44,
      -1,    18,    47,    61,    -1,    63,    62,    -1,    -1,    67,
      66,    74,    44,    -1,    68,    44,    -1,    11,    39,    74,
      48,    58,    64,    -1,    10,    18,    26,    74,    47,    74,
      58,    -1,    13,    65,    44,    -1,     4,    44,    -1,     7,
      44,    -1,    58,    -1,     8,    58,    -1,    -1,    74,    -1,
      -1,    26,    -1,    27,    -1,    28,    -1,    18,    -1,    18,
      45,    74,    46,    -1,    18,    39,    73,    48,    -1,     5,
      39,    20,    69,    48,    -1,    47,    70,    -1,    -1,    71,
      -1,    70,    47,    71,    -1,    74,    -1,    20,    -1,    74,
      -1,    74,    47,    72,    -1,    72,    -1,    -1,    67,    -1,
      68,    -1,    75,    -1,    74,    29,    74,    -1,    74,    30,
      74,    -1,    74,    31,    74,    -1,    74,    32,    74,    -1,
      74,    33,    74,    -1,    74,    22,    74,    -1,    74,    23,
      74,    -1,    74,    25,    74,    -1,    74,    24,    74,    -1,
      74,    34,    74,    -1,    74,    35,    74,    -1,    74,    36,
      74,    -1,    74,    37,    74,    -1,    30,    74,    -1,    38,
      74,    -1,    39,    74,    48,    -1,    77,    -1,    21,    -1,
      76,    -1,    14,    -1,     9,    -1,    17,    -1,    19,    -1,
      12,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   148,   148,   151,   152,   155,   158,   162,   166,   169,
     174,   175,   178,   179,   182,   183,   186,   190,   195,   198,
     199,   202,   205,   209,   214,   215,   218,   219,   220,   221,
     222,   223,   224,   225,   228,   230,   234,   235,   238,   239,
     240,   243,   244,   247,   249,   253,   255,   259,   264,   270,
     272,   276,   281,   287,   289,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   314,   315,   316,   319,   320,   323,
     324,   327,   328
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOOLEAN_", "BREAK_", "CALLOUT_",
  "CLASS_", "CONTINUE_", "ELSE_", "FALSE_", "FOR_", "IF_", "INT_",
  "RETURN_", "TRUE_", "VOID_", "PROGRAM_", "DIGIT_", "ID_", "HEX_DIGIT_",
  "STRING_LITERAL", "CHAR_LITERAL", "LT_", "GT_", "LEQ_", "GEQ_", "EQ_",
  "PLUS_EQ_", "MINUS_EQ_", "PLUS_", "MINUS_", "MULT_", "DIV_", "PERCENT_",
  "EQEQ_", "NEQ_", "ANDAND_", "OROR_", "LOG_NOT_", "ROUND_", "LOC_",
  "UN_MINUS_", "'{'", "'}'", "';'", "'['", "']'", "','", "')'", "$accept",
  "program", "field_", "field_decl", "new_field_decl", "method_",
  "method_decl", "multi_type_id", "multi_type_id2", "block", "var_",
  "var_decl", "var_decl_", "statement_", "statement_decl", "else_block",
  "expr_", "assign_op", "location", "method_call", "callout_arg_sq",
  "callout_arg_", "callout_arg", "expr_plus", "expr_sq", "expr", "literal",
  "bool_literal", "int_literal", "type", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   123,   125,    59,    91,    93,    44,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    53,    53,    53,    53,
      54,    54,    55,    55,    56,    56,    57,    57,    58,    59,
      59,    60,    61,    61,    62,    62,    63,    63,    63,    63,
      63,    63,    63,    63,    64,    64,    65,    65,    66,    66,
      66,    67,    67,    68,    68,    69,    69,    70,    70,    71,
      71,    72,    72,    73,    73,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    75,    75,    75,    76,    76,    77,
      77,    78,    78
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     2,     0,     2,     2,     5,     3,     6,
       2,     0,     6,     6,     1,     0,     2,     4,     4,     2,
       0,     2,     2,     3,     2,     0,     4,     2,     6,     7,
       3,     2,     2,     1,     2,     0,     1,     0,     1,     1,
       1,     1,     4,     4,     5,     2,     0,     1,     3,     1,
       1,     1,     3,     1,     0,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,    11,    82,    81,     0,
       3,     0,    11,     0,     0,     2,    10,     0,     0,     5,
      15,     0,    15,     6,     0,     0,     0,    14,     0,     0,
      79,    80,     0,     0,     8,     0,    16,     0,     0,    20,
      13,     0,    12,     7,     0,    25,    20,     0,    17,     9,
       0,     0,     0,     0,     0,    37,    41,    33,     0,    25,
       0,     0,    19,     0,    21,    31,     0,    32,     0,     0,
      78,    77,    75,     0,     0,     0,     0,    55,    56,    36,
      57,    76,    74,    54,     0,    18,    24,    38,    39,    40,
       0,    27,    22,     0,    46,     0,     0,    71,    72,     0,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,     0,    51,     0,     0,    23,
       0,     0,     0,     0,    73,    63,    64,    66,    65,    58,
      59,    60,    61,    62,    67,    68,    69,    70,    43,     0,
      42,    26,    50,    45,    47,    49,    44,     0,    35,    52,
       0,     0,     0,    28,    48,    29,    34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,    10,    19,    11,    12,    26,    27,    57,
      45,    46,    64,    58,    59,   153,    76,    90,    77,    78,
     121,   143,   144,   114,   115,   116,    80,    81,    82,    28
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -55
static const yytype_int16 yypact[] =
{
       5,    -8,    18,   -18,   -55,   -55,     2,   -55,   -55,    11,
     -55,   -10,     2,    27,     3,   -55,   -55,    28,    40,   -55,
       4,    25,     4,   -55,    43,    49,    30,   -55,    65,    44,
     -55,   -55,    26,    24,   -55,    57,    51,    57,    -9,     4,
     -55,     4,   -55,   -55,    49,    21,     4,    82,   -55,   -55,
      59,    63,    60,    87,    68,    92,   -33,   -55,    69,    21,
      54,    64,   -55,    -4,   -55,   -55,    94,   -55,    89,    92,
     -55,   -55,   -55,    92,    92,    92,    74,   -55,   -55,   231,
     -55,   -55,   -55,    92,    92,   -55,   -55,   -55,   -55,   -55,
      92,   -55,   -55,    82,    72,    92,   103,   -55,   -55,   123,
     -55,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,   -55,    73,   143,   181,   199,   -55,
      56,    75,   162,    57,   -55,   281,   281,   281,   281,    58,
      58,   -55,   -55,   -55,   276,   276,   262,   247,   -55,    92,
     -55,   -55,   -55,    77,   -55,   231,   -55,    92,   112,   -55,
      56,   215,    57,   -55,   -55,   -55,   -55
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -55,   -55,   -55,   -55,   -22,   117,   -55,   119,   101,   -35,
      97,   -55,    70,    85,   -55,   -55,   -55,   -55,   -36,   -32,
     -55,   -55,    -1,    22,   -55,   -54,   -55,   -55,   126,    -2
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      40,    79,    42,    34,    13,     7,    83,     7,     3,    60,
      17,     1,    84,    61,     8,    96,     8,     9,     4,    97,
      98,    99,    49,    60,     5,    50,    51,    61,    52,    14,
     117,    53,    54,    15,    55,    43,   118,    47,    44,    56,
      92,   122,    20,    93,    47,    18,    21,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      30,    51,    31,    39,    22,    70,   145,    33,    23,    24,
      71,    25,    38,    30,    56,    31,   142,    72,    35,    22,
      87,    88,    89,    36,    23,    24,    73,    25,   148,   107,
     108,   109,    37,   151,    74,    75,   145,    51,    41,    39,
      63,    70,    66,    65,    67,    68,    71,    69,    91,    30,
      56,    31,    85,    72,    94,    95,   155,   156,   100,   120,
     152,   138,    73,   146,   150,   101,   102,   103,   104,    16,
      74,    75,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    29,    48,    62,    86,   101,   102,   103,   104,   154,
      32,   123,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   149,     0,   119,     0,   101,   102,   103,   104,     0,
       0,   124,   105,   106,   107,   108,   109,   110,   111,   112,
     113,     0,     0,     0,   101,   102,   103,   104,     0,     0,
     139,   105,   106,   107,   108,   109,   110,   111,   112,   113,
       0,     0,     0,   101,   102,   103,   104,     0,     0,   147,
     105,   106,   107,   108,   109,   110,   111,   112,   113,     0,
       0,   101,   102,   103,   104,     0,     0,   140,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   101,   102,   103,
     104,     0,     0,   141,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   101,   102,   103,   104,    39,     0,     0,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   101,
     102,   103,   104,     0,     0,     0,   105,   106,   107,   108,
     109,   110,   111,   112,   101,   102,   103,   104,     0,     0,
       0,   105,   106,   107,   108,   109,   110,   111,   101,   102,
     103,   104,     0,     0,     0,   105,   106,   107,   108,   109,
     105,   106,   107,   108,   109
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-55)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      35,    55,    37,    25,     6,     3,    39,     3,    16,    45,
      12,     6,    45,    45,    12,    69,    12,    15,     0,    73,
      74,    75,    44,    59,    42,     4,     5,    59,     7,    18,
      84,    10,    11,    43,    13,    44,    90,    39,    47,    18,
      44,    95,    39,    47,    46,    18,    18,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      17,     5,    19,    42,    39,     9,   120,    18,    44,    45,
      14,    47,    46,    17,    18,    19,    20,    21,    48,    39,
      26,    27,    28,    18,    44,    45,    30,    47,   123,    31,
      32,    33,    48,   147,    38,    39,   150,     5,    47,    42,
      18,     9,    39,    44,    44,    18,    14,    39,    44,    17,
      18,    19,    43,    21,    20,    26,   151,   152,    44,    47,
       8,    48,    30,    48,    47,    22,    23,    24,    25,    12,
      38,    39,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    22,    41,    46,    59,    22,    23,    24,    25,   150,
      24,    48,    29,    30,    31,    32,    33,    34,    35,    36,
      37,   139,    -1,    93,    -1,    22,    23,    24,    25,    -1,
      -1,    48,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    22,    23,    24,    25,    -1,    -1,
      47,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    22,    23,    24,    25,    -1,    -1,    47,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    22,    23,    24,    25,    -1,    -1,    46,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    22,    23,    24,
      25,    -1,    -1,    44,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    22,    23,    24,    25,    42,    -1,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    22,
      23,    24,    25,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    22,    23,    24,    25,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    22,    23,
      24,    25,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      29,    30,    31,    32,    33
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    50,    16,     0,    42,    51,     3,    12,    15,
      52,    54,    55,    78,    18,    43,    54,    78,    18,    53,
      39,    18,    39,    44,    45,    47,    56,    57,    78,    56,
      17,    19,    77,    18,    53,    48,    18,    48,    46,    42,
      58,    47,    58,    44,    47,    59,    60,    78,    57,    53,
       4,     5,     7,    10,    11,    13,    18,    58,    62,    63,
      67,    68,    59,    18,    61,    44,    39,    44,    18,    39,
       9,    14,    21,    30,    38,    39,    65,    67,    68,    74,
      75,    76,    77,    39,    45,    43,    62,    26,    27,    28,
      66,    44,    44,    47,    20,    26,    74,    74,    74,    74,
      44,    22,    23,    24,    25,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    72,    73,    74,    74,    74,    61,
      47,    69,    74,    48,    48,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    48,    47,
      46,    44,    20,    70,    71,    74,    48,    47,    58,    72,
      47,    74,     8,    64,    71,    58,    58
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
      yychar = YYLEX;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 148 "project.y"
    { (yyval.prognode) = new program_node((yyvsp[(4) - (6)].fldlist),(yyvsp[(5) - (6)].methodnodelist)); root = (yyval.prognode);/*arguments*/ }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 151 "project.y"
    { (yyval.fldlist) = (yyvsp[(1) - (2)].fldlist); (yyvsp[(1) - (2)].fldlist)->push_front((yyvsp[(2) - (2)].fld)); }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 152 "project.y"
    { (yyval.fldlist) = new list<field *>(); }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 155 "project.y"
    { (yyval.fld) = new field((yyvsp[(1) - (2)].typ), (yyvsp[(2) - (2)].fieldnodelist)); /*need to send data*/}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 158 "project.y"
    { field_node_single *s = new field_node_single((yyvsp[(1) - (2)].str));
											  list<field_node *> *b = new list<field_node *>();
											  b->push_front(s);
											  (yyval.fieldnodelist) = b; }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 162 "project.y"
    { field_node_array *s = new field_node_array((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].inti));
											  list<field_node *> *b = new list<field_node *>();
											  b->push_front(s);
											  (yyval.fieldnodelist) = b; }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 166 "project.y"
    { field_node_single *n = new field_node_single((yyvsp[(1) - (3)].str));
											  (yyvsp[(3) - (3)].fieldnodelist)->push_front(n);
											  (yyval.fieldnodelist) = (yyvsp[(3) - (3)].fieldnodelist); }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 169 "project.y"
    { field_node_array *m = new field_node_array((yyvsp[(1) - (6)].str), (yyvsp[(3) - (6)].inti));
											  (yyvsp[(6) - (6)].fieldnodelist)->push_front(m);
											  (yyval.fieldnodelist) = (yyvsp[(6) - (6)].fieldnodelist); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 174 "project.y"
    { (yyval.methodnodelist) = (yyvsp[(2) - (2)].methodnodelist); (yyvsp[(2) - (2)].methodnodelist)->push_front((yyvsp[(1) - (2)].methodnode)); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 175 "project.y"
    { (yyval.methodnodelist) = new list<method_node *>(); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 178 "project.y"
    { (yyval.methodnode) = new method_node((yyvsp[(1) - (6)].typ),(yyvsp[(2) - (6)].str),(yyvsp[(4) - (6)].argnodelist),(yyvsp[(6) - (6)].blocknode)); /* arguments */ }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 179 "project.y"
    { (yyval.methodnode) = new method_node((yyvsp[(1) - (6)].typ),(yyvsp[(2) - (6)].str),(yyvsp[(4) - (6)].argnodelist),(yyvsp[(6) - (6)].blocknode)); /* arguments */ }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 182 "project.y"
    { (yyval.argnodelist) = (yyvsp[(1) - (1)].argnodelist);}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 183 "project.y"
    { (yyval.argnodelist) = new list<arg_node *>();}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 186 "project.y"
    { arg_node *a = new arg_node((yyvsp[(1) - (2)].typ),(yyvsp[(2) - (2)].str));
											  list<arg_node *> *l = new list<arg_node *>(); /*send type and id ar arg*/
											  l->push_front(a);
											  (yyval.argnodelist) = l; }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 190 "project.y"
    { arg_node *b = new arg_node((yyvsp[(1) - (4)].typ),(yyvsp[(2) - (4)].str));
											  (yyvsp[(4) - (4)].argnodelist)->push_front(b);
											  (yyval.argnodelist) = (yyvsp[(4) - (4)].argnodelist); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 195 "project.y"
    { (yyval.blocknode) = new block_node((yyvsp[(2) - (4)].variablenodelist),(yyvsp[(3) - (4)].statementnodelist)); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 198 "project.y"
    { (yyval.variablenodelist) = (yyvsp[(2) - (2)].variablenodelist); (yyvsp[(2) - (2)].variablenodelist)->push_front((yyvsp[(1) - (2)].variablenode)); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 199 "project.y"
    { (yyval.variablenodelist) = new list<variable_node *>(); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 202 "project.y"
    { (yyval.variablenode) = new variable_node((yyvsp[(1) - (2)].typ), (yyvsp[(2) - (2)].idnodelist)); /* send $1 and $2*/ }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 205 "project.y"
    { id_node *i = new id_node((yyvsp[(1) - (2)].str));
											  list<id_node *> *c = new list<id_node *>(); 
											  c->push_front(i);
											  (yyval.idnodelist) = c; }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 209 "project.y"
    { id_node *d = new id_node((yyvsp[(1) - (3)].str));
											  (yyvsp[(3) - (3)].idnodelist)->push_front(d);
											  (yyval.idnodelist) = (yyvsp[(3) - (3)].idnodelist); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 214 "project.y"
    { (yyval.statementnodelist) = (yyvsp[(2) - (2)].statementnodelist); (yyvsp[(2) - (2)].statementnodelist)->push_back((yyvsp[(1) - (2)].statementnode)); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 215 "project.y"
    { (yyval.statementnodelist) = new list<statement_node *>(); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 218 "project.y"
    { (yyval.statementnode) = new assign_stmt((yyvsp[(1) - (4)].locationnode),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].exprnode)); /*send arguments*/}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 219 "project.y"
    { (yyval.statementnode) = new method_call_stmt((yyvsp[(1) - (2)].methodcallnode));/* send arguments*/}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 220 "project.y"
    { (yyval.statementnode) = new if_else_stmt((yyvsp[(3) - (6)].exprnode),(yyvsp[(5) - (6)].blocknode),(yyvsp[(6) - (6)].elseblocknode)); /*send arguments*/}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 221 "project.y"
    { (yyval.statementnode) = new for_stmt((yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].exprnode),(yyvsp[(6) - (7)].exprnode),(yyvsp[(7) - (7)].blocknode)); /*send arguments*/}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 222 "project.y"
    { (yyval.statementnode) = new return_stmt((yyvsp[(2) - (3)].exprnode)); /*send arguments*/}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 223 "project.y"
    { (yyval.statementnode) = new break_stmt(); /*send arguments*/}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 224 "project.y"
    { (yyval.statementnode) = new continue_stmt(); /*send arguments*/}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 225 "project.y"
    { (yyval.statementnode) = (yyvsp[(1) - (1)].blocknode); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 228 "project.y"
    { (yyval.elseblocknode) = new else_block_node_1((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].blocknode));
											}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 230 "project.y"
    { (yyval.elseblocknode) = new else_block_node_2();
											}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 234 "project.y"
    { (yyval.exprnode) = (yyvsp[(1) - (1)].exprnode);}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 235 "project.y"
    { (yyval.exprnode) = new dummy_node();}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 238 "project.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 239 "project.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 240 "project.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 243 "project.y"
    { (yyval.locationnode) = new location_node_single((yyvsp[(1) - (1)].str));}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 244 "project.y"
    { (yyval.locationnode) = new location_node_expr((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].exprnode));}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 247 "project.y"
    { (yyval.methodcallnode) = new method_call_node_1((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].exprnodelist)); 
											}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 249 "project.y"
    { (yyval.methodcallnode) = new method_call_node_2((yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].calloutargnodelist)); 
											}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 253 "project.y"
    { (yyval.calloutargnodelist) = (yyvsp[(2) - (2)].calloutargnodelist); 
											}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 255 "project.y"
    { (yyval.calloutargnodelist) = new list<callout_arg_node *>(); 
											}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 259 "project.y"
    {// callout_arg_node *f = new callout_arg_node();
											  list<callout_arg_node *> *g = new list<callout_arg_node *>();
											  g->push_front((yyvsp[(1) - (1)].calloutargnode));
											  (yyval.calloutargnodelist) = g; 
											}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 264 "project.y"
    {// callout_arg_node *h = new callout_arg_node();
											  (yyvsp[(1) - (3)].calloutargnodelist)->push_front((yyvsp[(3) - (3)].calloutargnode));
											  (yyval.calloutargnodelist) = (yyvsp[(1) - (3)].calloutargnodelist);
											}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 270 "project.y"
    { (yyval.calloutargnode) = new callout_expr_arg_node((yyvsp[(1) - (1)].exprnode)); 
											}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 272 "project.y"
    { (yyval.calloutargnode) = new callout_strlit_arg_node((yyvsp[(1) - (1)].str)); 
											}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 276 "project.y"
    { 
											  list<expr_node *> *u = new list<expr_node *>();
											  u->push_front((yyvsp[(1) - (1)].exprnode));
											  (yyval.exprnodelist) = u; 
											}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 281 "project.y"
    {/* expr_node *r = new expr_node();*/
											  (yyvsp[(3) - (3)].exprnodelist)->push_front((yyvsp[(1) - (3)].exprnode));
											  (yyval.exprnodelist) = (yyvsp[(3) - (3)].exprnodelist);
											}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 287 "project.y"
    { (yyval.exprnodelist) = (yyvsp[(1) - (1)].exprnodelist);
											}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 289 "project.y"
    { (yyval.exprnodelist) = new list<expr_node *>(); 
											}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 293 "project.y"
    { (yyval.exprnode) = (yyvsp[(1) - (1)].locationnode); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 294 "project.y"
    { (yyval.exprnode) = new method_call_expr((yyvsp[(1) - (1)].methodcallnode)); }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 295 "project.y"
    { (yyval.exprnode) = (yyvsp[(1) - (1)].literalnode); }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 296 "project.y"
    { (yyval.exprnode) = new plus_node((yyvsp[(1) - (3)].exprnode),(yyvsp[(3) - (3)].exprnode)); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 297 "project.y"
    { (yyval.exprnode) = new minus_node((yyvsp[(1) - (3)].exprnode), (yyvsp[(3) - (3)].exprnode)); }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 298 "project.y"
    { (yyval.exprnode) = new mult_node((yyvsp[(1) - (3)].exprnode), (yyvsp[(3) - (3)].exprnode)) ; }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 299 "project.y"
    { (yyval.exprnode) = new div_node((yyvsp[(1) - (3)].exprnode), (yyvsp[(3) - (3)].exprnode)); }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 300 "project.y"
    { (yyval.exprnode) = new percent_node((yyvsp[(1) - (3)].exprnode), (yyvsp[(3) - (3)].exprnode)); }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 301 "project.y"
    { (yyval.exprnode) = new less_node((yyvsp[(1) - (3)].exprnode), (yyvsp[(3) - (3)].exprnode)); }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 302 "project.y"
    { (yyval.exprnode) = new greater_node((yyvsp[(1) - (3)].exprnode), (yyvsp[(3) - (3)].exprnode)); }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 303 "project.y"
    { (yyval.exprnode) = new geq_node((yyvsp[(1) - (3)].exprnode), (yyvsp[(3) - (3)].exprnode)); }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 304 "project.y"
    { (yyval.exprnode) = new leq_node((yyvsp[(1) - (3)].exprnode), (yyvsp[(3) - (3)].exprnode)); }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 305 "project.y"
    { (yyval.exprnode) = new eqeq_node((yyvsp[(1) - (3)].exprnode), (yyvsp[(3) - (3)].exprnode)); }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 306 "project.y"
    { (yyval.exprnode) = new neq_node((yyvsp[(1) - (3)].exprnode), (yyvsp[(3) - (3)].exprnode)); }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 307 "project.y"
    { (yyval.exprnode) = new andand_node((yyvsp[(1) - (3)].exprnode), (yyvsp[(3) - (3)].exprnode)); }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 308 "project.y"
    { (yyval.exprnode) = new oror_node((yyvsp[(1) - (3)].exprnode), (yyvsp[(3) - (3)].exprnode)); }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 309 "project.y"
    { (yyval.exprnode) = new uminus_node((yyvsp[(2) - (2)].exprnode)); }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 310 "project.y"
    { (yyval.exprnode) = new lognot_node((yyvsp[(2) - (2)].exprnode)); }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 311 "project.y"
    { (yyval.exprnode) = new paren_node((yyvsp[(2) - (3)].exprnode)); }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 314 "project.y"
    {(yyval.literalnode) = new int_literal_node((yyvsp[(1) - (1)].inti));}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 315 "project.y"
    {(yyval.literalnode) = new char_literal_node((yyvsp[(1) - (1)].str));}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 316 "project.y"
    {(yyval.literalnode) = new bool_literal_node((yyvsp[(1) - (1)].bol));}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 319 "project.y"
    {(yyval.bol) = (yyvsp[(1) - (1)].bol);}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 320 "project.y"
    {(yyval.bol) = (yyvsp[(1) - (1)].bol);}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 323 "project.y"
    { (yyval.inti) = (yyvsp[(1) - (1)].inti);}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 324 "project.y"
    { (yyval.inti) = (yyvsp[(1) - (1)].inti);}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 327 "project.y"
    { (yyval.typ) = (yyvsp[(1) - (1)].typ);}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 328 "project.y"
    { (yyval.typ) = (yyvsp[(1) - (1)].typ);}
    break;


/* Line 1792 of yacc.c  */
#line 2126 "project.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
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
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
		      yytoken, &yylval);
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 331 "project.y"


int main()
{
		int a = yyparse();

//        if(a==0)
//                printf("Syntactically Correct\n");
//        else
//                printf("Syntactically Incorrect\n");
	root->print_();

		LLVMContext &Context = getGlobalContext();
		TheModule = new Module("Decaf Compiler", Context);
        return 0;
}

