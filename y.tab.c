/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "gocompiler.y"

        //Carlos Eduardo da Costa Jordão 2019221373
        //Guilherme Sousa de Oliveira e Cruz Junqueira 2019221958
                
        #include <stdlib.h>
        #include <stdio.h>
        #include <string.h>

        #include "y.tab.h"
        #include "struct.h"

        int yylex (void);
        extern void yyerror(char* s);
        extern Node * root;
        

#line 87 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    PACKAGE = 258,
    ID = 259,
    SEMICOLON = 260,
    VAR = 261,
    LPAR = 262,
    RPAR = 263,
    INT = 264,
    FLOAT32 = 265,
    BOOL = 266,
    STRING = 267,
    FUNC = 268,
    COMMA = 269,
    LBRACE = 270,
    RBRACE = 271,
    ASSIGN = 272,
    IF = 273,
    ELSE = 274,
    FOR = 275,
    RETURN = 276,
    PRINT = 277,
    STRLIT = 278,
    BLANKID = 279,
    PARSEINT = 280,
    CMDARGS = 281,
    LSQ = 282,
    RSQ = 283,
    OR = 284,
    AND = 285,
    LT = 286,
    GT = 287,
    EQ = 288,
    NE = 289,
    LE = 290,
    GE = 291,
    PLUS = 292,
    MINUS = 293,
    STAR = 294,
    DIV = 295,
    MOD = 296,
    NOT = 297,
    INTLIT = 298,
    REALLIT = 299,
    RESERVED = 300,
    UNARY = 301
  };
#endif
/* Tokens.  */
#define PACKAGE 258
#define ID 259
#define SEMICOLON 260
#define VAR 261
#define LPAR 262
#define RPAR 263
#define INT 264
#define FLOAT32 265
#define BOOL 266
#define STRING 267
#define FUNC 268
#define COMMA 269
#define LBRACE 270
#define RBRACE 271
#define ASSIGN 272
#define IF 273
#define ELSE 274
#define FOR 275
#define RETURN 276
#define PRINT 277
#define STRLIT 278
#define BLANKID 279
#define PARSEINT 280
#define CMDARGS 281
#define LSQ 282
#define RSQ 283
#define OR 284
#define AND 285
#define LT 286
#define GT 287
#define EQ 288
#define NE 289
#define LE 290
#define GE 291
#define PLUS 292
#define MINUS 293
#define STAR 294
#define DIV 295
#define MOD 296
#define NOT 297
#define INTLIT 298
#define REALLIT 299
#define RESERVED 300
#define UNARY 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "gocompiler.y"

        char* tkn;
        char* value;
        struct Node * node;

#line 237 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   323

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

#define YYUNDEFTOK  2
#define YYMAXUTOK   301


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    42,    42,    48,    49,    50,    53,    54,    55,    56,
      61,    62,    66,    74,    83,    87,   100,   112,   124,   137,
     144,   153,   156,   159,   160,   161,   162,   167,   168,   173,
     181,   190,   200,   207,   213,   218,   220,   222,   229,   230,
     233,   234,   237,   243,   247,   251,   254,   259,   261,   264,
     269,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PACKAGE", "ID", "SEMICOLON", "VAR",
  "LPAR", "RPAR", "INT", "FLOAT32", "BOOL", "STRING", "FUNC", "COMMA",
  "LBRACE", "RBRACE", "ASSIGN", "IF", "ELSE", "FOR", "RETURN", "PRINT",
  "STRLIT", "BLANKID", "PARSEINT", "CMDARGS", "LSQ", "RSQ", "OR", "AND",
  "LT", "GT", "EQ", "NE", "LE", "GE", "PLUS", "MINUS", "STAR", "DIV",
  "MOD", "NOT", "INTLIT", "REALLIT", "RESERVED", "UNARY", "$accept",
  "Program", "Declarations", "Type", "VarDeclaration", "VarSpec",
  "VarSpecHelper", "FuncDeclaration", "Parameters", "ParametersHelper",
  "FuncBody", "VarsAndStatements", "Statement", "ExprHelper",
  "PrintHelper", "StatementHelper", "ParseArgs", "FuncInvocation",
  "FuncInvocationHelper", "Expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF (-68)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,    15,     9,    16,   -68,   -68,     7,    31,    29,    52,
      55,   -68,    30,   -68,    63,   -68,   -68,   243,    66,    22,
     -68,   -68,   -68,   -68,    69,   -68,    68,    89,   213,    71,
     -68,   -68,   -68,   -68,    72,   -68,   213,    67,   187,   -68,
      72,   -68,    79,   -68,    75,   -68,   -68,   -68,    90,    -1,
      90,    77,    85,    86,   -68,   -68,   -68,    89,    21,    88,
      90,   195,    98,    65,    90,    90,    90,   -68,   -68,   -68,
     133,   -68,   146,   -68,   263,    81,   -68,   -68,   -68,   105,
     -68,   263,   103,   263,   -68,    91,   113,   106,   -68,   -68,
     -68,   -68,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,   217,   -68,   -68,   114,   263,
     -68,    54,   101,   -68,   -68,   -68,   225,   119,   274,   279,
     279,   279,   279,   279,   279,   282,   282,   -68,   -68,   -68,
     -68,   247,   -68,   -68,    90,   122,   111,   -68,   263,   163,
     116,   167,   -68,    73,   255,   162,   250,   -68,   189,   190,
     -68,   -68
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     5,     2,     0,     0,     0,
       0,    14,     0,    10,     0,     3,     4,     0,     0,     0,
       6,     7,     8,     9,     0,    12,     0,     0,     0,     0,
      13,    11,    21,    26,     0,    18,     0,    19,     0,    16,
       0,    17,     0,    27,     0,    25,    43,    22,     0,     0,
      39,     0,     0,     0,    36,    35,    15,     0,     0,     0,
       0,     0,    69,     0,     0,     0,     0,    67,    68,    70,
       0,    43,     0,    34,    38,     0,    23,    24,    20,     0,
      47,    50,     0,    28,    29,     0,     0,     0,    66,    65,
      64,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    43,    41,     0,    40,
      48,     0,     0,    42,    72,    71,     0,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      33,     0,    37,    46,     0,     0,    30,    32,    49,     0,
       0,     0,    43,     0,     0,     0,     0,    31,     0,     0,
      45,    44
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -68,   -68,   -68,     4,   157,   188,   -68,   -68,   -68,   -68,
     -29,   -68,   166,   -68,   -68,   -67,   -68,   -38,   -68,   -48
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     6,    25,     9,    13,    17,    10,    29,    37,
      35,    38,    85,    73,   108,    61,    54,    69,   111,    70
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      55,    72,    74,    62,   105,    39,    63,    41,     1,     4,
      81,    56,    83,     7,    71,    87,    88,    89,    90,     3,
       8,     5,    79,    55,   116,    62,    27,   109,    63,    80,
      28,    32,    34,    14,    11,    11,    64,    65,    12,   131,
      40,    66,    67,    68,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,    15,    64,    65,
      16,    78,   133,    66,    67,    68,    86,    55,   134,    62,
      19,    26,    63,    30,   145,   144,    31,    62,    55,    36,
      63,    42,    58,    57,    75,    62,   138,    33,    63,    59,
      76,    77,    60,    55,    62,   146,   113,    63,    20,    21,
      22,    23,    64,    65,   107,    58,    55,    66,    67,    68,
      64,    65,    82,   110,   115,    66,    67,    68,    64,    65,
     112,   114,   132,    66,    67,    68,   135,    64,    65,   139,
     140,   142,    66,    67,    68,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    91,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   106,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    43,   141,
     148,    44,    45,     7,   143,    52,    43,   150,   151,    44,
      18,     0,    46,    47,    53,    48,     0,    49,    50,    51,
      46,    84,     0,    48,     0,    49,    50,    51,    43,     0,
       0,    44,    20,    21,    22,    23,    43,     0,    33,    44,
       0,     0,    46,   130,     0,    48,     0,    49,    50,    51,
      46,   136,     0,    48,     0,    49,    50,    51,    43,     0,
       0,    44,    20,    21,    22,    23,    43,    24,     0,    44,
       0,     0,    46,   137,     0,    48,     0,    49,    50,    51,
      46,   147,     0,    48,     0,    49,    50,    51,   149,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   100,   101,   102,   103,
     104,   102,   103,   104
};

static const yytype_int16 yycheck[] =
{
      38,    49,    50,     4,    71,    34,     7,    36,     3,     0,
      58,    40,    60,     6,    15,    63,    64,    65,    66,     4,
      13,     5,     1,    61,    91,     4,     4,    75,     7,     8,
       8,    27,    28,     4,     4,     4,    37,    38,     7,   106,
      36,    42,    43,    44,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,     5,    37,    38,
       5,    57,     8,    42,    43,    44,     1,   105,    14,     4,
       7,     5,     7,     4,     1,   142,     8,     4,   116,     8,
       7,    14,     7,     4,     7,     4,   134,    15,     7,    14,
       5,     5,    17,   131,     4,   143,     5,     7,     9,    10,
      11,    12,    37,    38,    23,     7,   144,    42,    43,    44,
      37,    38,    24,     8,     8,    42,    43,    44,    37,    38,
      17,     8,     8,    42,    43,    44,    25,    37,    38,     7,
      19,    15,    42,    43,    44,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    15,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    15,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     1,    26,
      28,     4,     5,     6,    27,    38,     1,     8,     8,     4,
      12,    -1,    15,    16,    38,    18,    -1,    20,    21,    22,
      15,    16,    -1,    18,    -1,    20,    21,    22,     1,    -1,
      -1,     4,     9,    10,    11,    12,     1,    -1,    15,     4,
      -1,    -1,    15,    16,    -1,    18,    -1,    20,    21,    22,
      15,    16,    -1,    18,    -1,    20,    21,    22,     1,    -1,
      -1,     4,     9,    10,    11,    12,     1,    14,    -1,     4,
      -1,    -1,    15,    16,    -1,    18,    -1,    20,    21,    22,
      15,    16,    -1,    18,    -1,    20,    21,    22,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    37,    38,    39,    40,
      41,    39,    40,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    48,     4,     0,     5,    49,     6,    13,    51,
      54,     4,     7,    52,     4,     5,     5,    53,    52,     7,
       9,    10,    11,    12,    14,    50,     5,     4,     8,    55,
       4,     8,    50,    15,    50,    57,     8,    56,    58,    57,
      50,    57,    14,     1,     4,     5,    15,    16,    18,    20,
      21,    22,    51,    59,    63,    64,    57,     4,     7,    14,
      17,    62,     4,     7,    37,    38,    42,    43,    44,    64,
      66,    15,    66,    60,    66,     7,     5,     5,    50,     1,
       8,    66,    24,    66,    16,    59,     1,    66,    66,    66,
      66,    15,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    62,    15,    23,    61,    66,
       8,    65,    17,     5,     8,     8,    62,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      16,    62,     8,     8,    14,    25,    16,    16,    66,     7,
      19,    26,    15,    27,    62,     1,    66,    16,    28,    28,
       8,     8
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    49,    50,    50,    50,    50,
      51,    51,    52,    53,    53,    54,    54,    54,    54,    55,
      56,    56,    57,    58,    58,    58,    58,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    60,    60,
      61,    61,    62,    62,    63,    63,    64,    64,    64,    65,
      65,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     3,     0,     1,     1,     1,     1,
       2,     5,     3,     3,     0,     7,     6,     6,     5,     3,
       4,     0,     3,     3,     3,     2,     0,     1,     3,     3,
       5,     9,     5,     4,     2,     1,     1,     4,     1,     0,
       1,     1,     3,     0,    11,    11,     5,     3,     4,     3,
       0,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     1,     1,     1,
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

#define YYBACKUP(Token, Value)                                    \
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
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
      yychar = yylex ();
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 42 "gocompiler.y"
                                                        {(yyval.node) = root = create_node("Program", NULL); if((yyvsp[0].node)!=NULL) add_son(root, (yyvsp[0].node));                           //done
                                                        //printf("root was created\n");
                                                        }
#line 1551 "y.tab.c"
    break;

  case 3:
#line 48 "gocompiler.y"
                                                        {if((yyvsp[-2].node)==NULL){(yyval.node) = (yyvsp[-1].node);} else {add_sibling((yyvsp[-2].node),(yyvsp[-1].node)); (yyval.node) = (yyvsp[-2].node);}}
#line 1557 "y.tab.c"
    break;

  case 4:
#line 49 "gocompiler.y"
                                                        {if((yyvsp[-2].node)==NULL){(yyval.node) = (yyvsp[-1].node);} else {add_sibling((yyvsp[-2].node),(yyvsp[-1].node)); (yyval.node) = (yyvsp[-2].node);}}
#line 1563 "y.tab.c"
    break;

  case 5:
#line 50 "gocompiler.y"
                                                        {(yyval.node) = NULL;}
#line 1569 "y.tab.c"
    break;

  case 6:
#line 53 "gocompiler.y"
                                                        {(yyval.node) = create_node("Int", NULL);}
#line 1575 "y.tab.c"
    break;

  case 7:
#line 54 "gocompiler.y"
                                                        {(yyval.node) = create_node("Float32", NULL);}
#line 1581 "y.tab.c"
    break;

  case 8:
#line 55 "gocompiler.y"
                                                        {(yyval.node) = create_node("Bool", NULL);}
#line 1587 "y.tab.c"
    break;

  case 9:
#line 56 "gocompiler.y"
                                                        {(yyval.node) = create_node("String", NULL);}
#line 1593 "y.tab.c"
    break;

  case 10:
#line 61 "gocompiler.y"
                                                        {(yyval.node) = (yyvsp[0].node);}
#line 1599 "y.tab.c"
    break;

  case 11:
#line 62 "gocompiler.y"
                                                        {(yyval.node) = (yyvsp[-2].node);}
#line 1605 "y.tab.c"
    break;

  case 12:
#line 66 "gocompiler.y"
                                                        {(yyval.node)=create_node("VarDecl", NULL);
                                                        add_son((yyval.node), (yyvsp[0].node));
                                                        add_sibling((yyvsp[0].node), create_node("Id", (yyvsp[-2].tkn)));
                                                        add_sibling((yyval.node),(yyvsp[-1].node));
                                                        save_type((yyval.node), (yyvsp[0].node));
                                                        }
#line 1616 "y.tab.c"
    break;

  case 13:
#line 74 "gocompiler.y"
                                                        {Node* var = create_node("VarDecl", NULL);
                                                        add_son(var,create_node("Id", (yyvsp[0].tkn)));
                                                        if ((yyvsp[-2].node) != NULL) {
                                                                (yyval.node) = (yyvsp[-2].node);
                                                                add_sibling((yyval.node),var);
                                                        } else (yyval.node) = var;
                                                        }
#line 1628 "y.tab.c"
    break;

  case 14:
#line 83 "gocompiler.y"
                                                        {(yyval.node) = NULL;}
#line 1634 "y.tab.c"
    break;

  case 15:
#line 87 "gocompiler.y"
                                                        {(yyval.node) = create_node("FuncDecl", NULL);                                                 //done
                                                        Node * header = create_node("FuncHeader", NULL);
                                                        add_son((yyval.node), header);
                                                        Node * id =  create_node("Id", (yyvsp[-5].tkn));
                                                        add_son(header, id);
                                                        add_son(header, (yyvsp[-1].node));
                                                        Node * parametros = create_node("FuncParams", NULL);
                                                        add_son(header,parametros);
                                                        add_son(parametros, (yyvsp[-3].node));
                                                        Node * funcbody = create_node("FuncBody", NULL);
                                                        add_son(funcbody, (yyvsp[0].node));
                                                        add_son((yyval.node), funcbody);}
#line 1651 "y.tab.c"
    break;

  case 16:
#line 100 "gocompiler.y"
                                                        {(yyval.node) = create_node("FuncDecl", NULL);
                                                        Node * header = create_node("FuncHeader", NULL);
                                                        add_son((yyval.node), header);
                                                        Node * id =  create_node("Id", (yyvsp[-4].tkn));
                                                        add_son(header, id);
                                                        add_son(header, (yyvsp[-1].node));
                                                        Node * parametros = create_node("FuncParams", NULL);
                                                        add_son(header,parametros);
                                                        Node * funcbody = create_node("FuncBody", NULL);
                                                        add_son(funcbody, (yyvsp[0].node));
                                                        add_son((yyval.node), funcbody);}
#line 1667 "y.tab.c"
    break;

  case 17:
#line 112 "gocompiler.y"
                                                        {(yyval.node) = create_node("FuncDecl", NULL);
                                                        Node * header= create_node("FuncHeader", NULL);
                                                        add_son((yyval.node), header);
                                                        Node * id =  create_node("Id", (yyvsp[-4].tkn));
                                                        add_son(header, id);
                                                        Node * parametros = create_node("FuncParams", NULL);
                                                        add_son(header,parametros);
                                                        add_son(parametros, (yyvsp[-2].node));
                                                        Node * funcbody = create_node("FuncBody", NULL);
                                                        add_son(funcbody, (yyvsp[0].node));
                                                        add_son((yyval.node), funcbody);}
#line 1683 "y.tab.c"
    break;

  case 18:
#line 124 "gocompiler.y"
                                                        {(yyval.node) = create_node("FuncDecl", NULL);
                                                        Node * header= create_node("FuncHeader", NULL);
                                                        add_son((yyval.node), header);
                                                        Node * id =  create_node("Id", (yyvsp[-3].tkn));
                                                        add_son(header, id);
                                                        Node * parametros = create_node("FuncParams", NULL);
                                                        add_son(header,parametros);
                                                        Node * funcbody = create_node("FuncBody", NULL);
                                                        add_son(funcbody, (yyvsp[0].node));
                                                        add_son((yyval.node), funcbody);
                                                        }
#line 1699 "y.tab.c"
    break;

  case 19:
#line 137 "gocompiler.y"
                                                        {(yyval.node) = create_node("ParamDecl", NULL);
                                                        add_sibling((yyval.node), (yyvsp[0].node));
                                                        add_son((yyval.node), (yyvsp[-1].node));
                                                        add_son((yyval.node), create_node("Id", (yyvsp[-2].tkn)));
                                                        }
#line 1709 "y.tab.c"
    break;

  case 20:
#line 144 "gocompiler.y"
                                                        {Node* param = create_node("ParamDecl", NULL);
                                                        add_son(param, (yyvsp[0].node));
                                                        add_son(param, create_node("Id", (yyvsp[-1].tkn)));                                          
                                                        if ((yyvsp[-3].node) == NULL) (yyval.node) = param;
                                                        else {
                                                                (yyval.node) = (yyvsp[-3].node);
                                                                add_sibling((yyvsp[-3].node), param);
                                                        }
                                                        }
#line 1723 "y.tab.c"
    break;

  case 21:
#line 153 "gocompiler.y"
                                                        {(yyval.node) = NULL;}
#line 1729 "y.tab.c"
    break;

  case 22:
#line 156 "gocompiler.y"
                                                        {(yyval.node) = (yyvsp[-1].node);}
#line 1735 "y.tab.c"
    break;

  case 23:
#line 159 "gocompiler.y"
                                                        {if((yyvsp[-2].node)!=NULL){(yyval.node) = (yyvsp[-2].node); add_sibling((yyval.node), (yyvsp[-1].node));} else ((yyval.node) = (yyvsp[-1].node));}
#line 1741 "y.tab.c"
    break;

  case 24:
#line 160 "gocompiler.y"
                                                        {if((yyvsp[-2].node)!=NULL){(yyval.node) = (yyvsp[-2].node); add_sibling((yyval.node), (yyvsp[-1].node));} else ((yyval.node) = (yyvsp[-1].node));}
#line 1747 "y.tab.c"
    break;

  case 25:
#line 161 "gocompiler.y"
                                                        {(yyval.node) = (yyvsp[-1].node);}
#line 1753 "y.tab.c"
    break;

  case 26:
#line 162 "gocompiler.y"
                                                        {(yyval.node) = NULL;}
#line 1759 "y.tab.c"
    break;

  case 27:
#line 167 "gocompiler.y"
                                                        {(yyval.node)=NULL;}
#line 1765 "y.tab.c"
    break;

  case 28:
#line 168 "gocompiler.y"
                                                         {
                                                        (yyval.node) = create_node("Assign", NULL);
                                                        add_son((yyval.node), create_node("Id", (yyvsp[-2].tkn)));
                                                        add_son((yyval.node), (yyvsp[0].node));
                                                        }
#line 1775 "y.tab.c"
    break;

  case 29:
#line 173 "gocompiler.y"
                                                        {if((yyvsp[-1].node) != NULL && (yyvsp[-1].node) -> sibling != NULL){
                                                        Node * block  = create_node("Block", NULL);
                                                        add_son(block, (yyvsp[-1].node));
                                                        (yyval.node) = block;
        }                                               else{(yyval.node) = (yyvsp[-1].node);};
                                                        
                                                        }
#line 1787 "y.tab.c"
    break;

  case 30:
#line 181 "gocompiler.y"
                                                        {
                                                        (yyval.node) = create_node("If", NULL);
                                                        add_son((yyval.node), (yyvsp[-3].node));
                                                        Node* ifblock = create_node("Block", NULL);
                                                        add_son((yyval.node), ifblock);
                                                        add_son(ifblock, (yyvsp[-1].node));
                                                        Node* elseblock = create_node("Block", NULL);
                                                        add_son((yyval.node), elseblock);
                                                        }
#line 1801 "y.tab.c"
    break;

  case 31:
#line 190 "gocompiler.y"
                                                                                        {
                                                                                        (yyval.node) = create_node("If", NULL);
                                                                                        add_son((yyval.node), (yyvsp[-7].node));
                                                                                        Node* ifblock = create_node("Block", NULL);
                                                                                        add_son((yyval.node), ifblock);
                                                                                        add_son(ifblock, (yyvsp[-5].node));
                                                                                        Node* elseblock = create_node("Block", NULL);
                                                                                        add_son((yyval.node), elseblock);
                                                                                        add_son(elseblock, (yyvsp[-1].node));
                                                                                        }
#line 1816 "y.tab.c"
    break;

  case 32:
#line 200 "gocompiler.y"
                                                        {
                                                        (yyval.node) = create_node("For", NULL);
                                                        add_son((yyval.node), (yyvsp[-3].node));
                                                        Node *block = create_node("Block", NULL);
                                                        add_son((yyval.node), block);
                                                        add_son(block, (yyvsp[-1].node));
                                                        }
#line 1828 "y.tab.c"
    break;

  case 33:
#line 207 "gocompiler.y"
                                                        {
                                                        (yyval.node)= create_node("For", NULL);
                                                        Node * block = create_node("Block", NULL);
                                                        add_son((yyval.node), block);
                                                        add_son(block, (yyvsp[-1].node));
                                                        }
#line 1839 "y.tab.c"
    break;

  case 34:
#line 213 "gocompiler.y"
                                                        {
                                                        (yyval.node) = create_node("Return", NULL);
                                                        if((yyvsp[0].node) != NULL){add_son((yyval.node), (yyvsp[0].node));}
                                                        }
#line 1848 "y.tab.c"
    break;

  case 35:
#line 218 "gocompiler.y"
                                                        {(yyval.node) = (yyvsp[0].node);}
#line 1854 "y.tab.c"
    break;

  case 36:
#line 220 "gocompiler.y"
                                                        {(yyval.node) = (yyvsp[0].node);}
#line 1860 "y.tab.c"
    break;

  case 37:
#line 222 "gocompiler.y"
                                                        {(yyval.node) =  create_node("Print", NULL);
                                                        add_son((yyval.node),(yyvsp[-1].node));
                                                        }
#line 1868 "y.tab.c"
    break;

  case 38:
#line 229 "gocompiler.y"
                                                        {(yyval.node)=(yyvsp[0].node);}
#line 1874 "y.tab.c"
    break;

  case 39:
#line 230 "gocompiler.y"
                                                        {(yyval.node)=NULL;}
#line 1880 "y.tab.c"
    break;

  case 40:
#line 233 "gocompiler.y"
                                                        {(yyval.node)=(yyvsp[0].node);}
#line 1886 "y.tab.c"
    break;

  case 41:
#line 234 "gocompiler.y"
                                                        {(yyval.node) = create_node("StrLit", (yyvsp[0].tkn));}
#line 1892 "y.tab.c"
    break;

  case 42:
#line 237 "gocompiler.y"
                                                        {
                                                        if((yyvsp[-2].node) == NULL) (yyval.node) = (yyvsp[-1].node);
                                                        else if((yyvsp[-1].node) == NULL) (yyval.node) = (yyvsp[-2].node);
                                                        else {(yyval.node) = (yyvsp[-2].node); 
                                                        add_sibling((yyval.node), (yyvsp[-1].node));}
                                                        }
#line 1903 "y.tab.c"
    break;

  case 43:
#line 243 "gocompiler.y"
                                                        {(yyval.node) = NULL;}
#line 1909 "y.tab.c"
    break;

  case 44:
#line 247 "gocompiler.y"
                                                                                {(yyval.node) = create_node("ParseArgs", NULL);
                                                                                add_son((yyval.node), create_node("Id", (yyvsp[-10].tkn)));
                                                                                add_son((yyval.node), (yyvsp[-2].node)); 
                                                                                }
#line 1918 "y.tab.c"
    break;

  case 45:
#line 251 "gocompiler.y"
                                                                                 {(yyval.node)= NULL;}
#line 1924 "y.tab.c"
    break;

  case 46:
#line 254 "gocompiler.y"
                                                        {(yyval.node) = create_node("Call", NULL);
                                                        add_son((yyval.node), create_node("Id", (yyvsp[-4].tkn)));
                                                        add_son((yyval.node), (yyvsp[-2].node));
                                                        add_son((yyval.node), (yyvsp[-1].node));
                                                        }
#line 1934 "y.tab.c"
    break;

  case 47:
#line 259 "gocompiler.y"
                                                        {(yyval.node) = create_node("Call", NULL);
                                                        add_son((yyval.node), create_node("Id", (yyvsp[-2].tkn)));}
#line 1941 "y.tab.c"
    break;

  case 48:
#line 261 "gocompiler.y"
                                                        {(yyval.node)= NULL;}
#line 1947 "y.tab.c"
    break;

  case 49:
#line 264 "gocompiler.y"
                                                        {                                                                                            //todd
                                                        if((yyvsp[-2].node) == NULL) (yyval.node) = (yyvsp[0].node);
                                                        else if((yyvsp[0].node) == NULL) (yyval.node) = (yyvsp[-2].node);
                                                        else (yyval.node) = add_sibling((yyvsp[-2].node), (yyvsp[0].node));
                                                        }
#line 1957 "y.tab.c"
    break;

  case 50:
#line 269 "gocompiler.y"
                                                        {(yyval.node) = NULL;}
#line 1963 "y.tab.c"
    break;

  case 51:
#line 272 "gocompiler.y"
                                                        {(yyval.node) = create_node("Or",NULL);  add_son((yyval.node), (yyvsp[-2].node)); add_son((yyval.node), (yyvsp[0].node));}
#line 1969 "y.tab.c"
    break;

  case 52:
#line 273 "gocompiler.y"
                                                        {(yyval.node) = create_node("And",NULL); add_son((yyval.node), (yyvsp[-2].node)); add_son((yyval.node), (yyvsp[0].node));}
#line 1975 "y.tab.c"
    break;

  case 53:
#line 274 "gocompiler.y"
                                                        {(yyval.node) = create_node("Lt",NULL);  add_son((yyval.node), (yyvsp[-2].node)); add_son((yyval.node), (yyvsp[0].node));}
#line 1981 "y.tab.c"
    break;

  case 54:
#line 275 "gocompiler.y"
                                                        {(yyval.node) = create_node("Gt",NULL);  add_son((yyval.node), (yyvsp[-2].node)); add_son((yyval.node), (yyvsp[0].node));}
#line 1987 "y.tab.c"
    break;

  case 55:
#line 276 "gocompiler.y"
                                                        {(yyval.node) = create_node("Eq",NULL);  add_son((yyval.node), (yyvsp[-2].node)); add_son((yyval.node), (yyvsp[0].node));}
#line 1993 "y.tab.c"
    break;

  case 56:
#line 277 "gocompiler.y"
                                                        {(yyval.node) = create_node("Ne",NULL);  add_son((yyval.node), (yyvsp[-2].node)); add_son((yyval.node), (yyvsp[0].node));}
#line 1999 "y.tab.c"
    break;

  case 57:
#line 278 "gocompiler.y"
                                                        {(yyval.node) = create_node("Le",NULL);  add_son((yyval.node), (yyvsp[-2].node)); add_son((yyval.node), (yyvsp[0].node));}
#line 2005 "y.tab.c"
    break;

  case 58:
#line 279 "gocompiler.y"
                                                        {(yyval.node) = create_node("Ge",NULL);  add_son((yyval.node), (yyvsp[-2].node)); add_son((yyval.node), (yyvsp[0].node));}
#line 2011 "y.tab.c"
    break;

  case 59:
#line 280 "gocompiler.y"
                                                        {(yyval.node) = create_node("Add",NULL); add_son((yyval.node), (yyvsp[-2].node)); add_son((yyval.node), (yyvsp[0].node));}
#line 2017 "y.tab.c"
    break;

  case 60:
#line 281 "gocompiler.y"
                                                        {(yyval.node) = create_node("Sub",NULL); add_son((yyval.node), (yyvsp[-2].node)); add_son((yyval.node), (yyvsp[0].node));}
#line 2023 "y.tab.c"
    break;

  case 61:
#line 282 "gocompiler.y"
                                                        {(yyval.node) = create_node("Mul",NULL); add_son((yyval.node), (yyvsp[-2].node)); add_son((yyval.node), (yyvsp[0].node));}
#line 2029 "y.tab.c"
    break;

  case 62:
#line 283 "gocompiler.y"
                                                        {(yyval.node) = create_node("Div",NULL); add_son((yyval.node), (yyvsp[-2].node)); add_son((yyval.node), (yyvsp[0].node));}
#line 2035 "y.tab.c"
    break;

  case 63:
#line 284 "gocompiler.y"
                                                        {(yyval.node) = create_node("Mod",NULL); add_son((yyval.node), (yyvsp[-2].node)); add_son((yyval.node), (yyvsp[0].node));}
#line 2041 "y.tab.c"
    break;

  case 64:
#line 285 "gocompiler.y"
                                                        {(yyval.node) = create_node("Not",NULL); add_son((yyval.node), (yyvsp[0].node));}
#line 2047 "y.tab.c"
    break;

  case 65:
#line 286 "gocompiler.y"
                                                        {(yyval.node) = create_node("Minus",NULL); add_son((yyval.node), (yyvsp[0].node));}
#line 2053 "y.tab.c"
    break;

  case 66:
#line 287 "gocompiler.y"
                                                        {(yyval.node) = create_node("Plus",NULL);  add_son((yyval.node), (yyvsp[0].node));}
#line 2059 "y.tab.c"
    break;

  case 67:
#line 288 "gocompiler.y"
                                                        {(yyval.node) = create_node("IntLit", (yyvsp[0].tkn));}
#line 2065 "y.tab.c"
    break;

  case 68:
#line 289 "gocompiler.y"
                                                        {(yyval.node) = create_node("RealLit", (yyvsp[0].tkn));}
#line 2071 "y.tab.c"
    break;

  case 69:
#line 290 "gocompiler.y"
                                                        {(yyval.node) = create_node("Id", (yyvsp[0].tkn));}
#line 2077 "y.tab.c"
    break;

  case 70:
#line 291 "gocompiler.y"
                                                        {(yyval.node) = (yyvsp[0].node);}
#line 2083 "y.tab.c"
    break;

  case 71:
#line 292 "gocompiler.y"
                                                        {(yyval.node) = (yyvsp[-1].node);}
#line 2089 "y.tab.c"
    break;

  case 72:
#line 293 "gocompiler.y"
                                                        {(yyval.node)=NULL;}
#line 2095 "y.tab.c"
    break;


#line 2099 "y.tab.c"

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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
#line 296 "gocompiler.y"
