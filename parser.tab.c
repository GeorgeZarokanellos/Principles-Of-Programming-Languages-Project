/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <string.h>
#define EXIT_FAILURE    -1   
void yyerror(const char *s);
void gameCatLimit(int counter);
void validateGameId(int val);
void listIntegerCountLimit(int counter);
void listIntegerInterval(int val);
void countAllElements();
void countActiveElements();
void winningNElements();
void bonusElements();
void counterChecker();
extern FILE *yyin;
extern FILE *yyout;
extern int yylex();
extern int lineno;                        //line counter
extern int value;                         //stores the value of last read integer
extern int listflag;                      //1 when reading a "list" 
extern int prizeCatflag;                  //1 when reading a "prizeCategories"
extern int contentflag;                   //1 when reading a "content"
int token_numbers[2][10];                 //an array of tokens we expect to read in no particular order
int minDistFlg = 0;                       //1 when reading "minimumDistributed"
int prCatCntr=0;                          //counts json objects in "prizeCategories"
int errors = 0;                           //counts errors encountered
int intArrCounter = 0;                    //counts integers in an array


#line 101 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* T_EOF  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_U_INT = 3,                    /* "Unsigned Integer"  */
  YYSYMBOL_T_U_FLOAT = 4,                  /* "Unsigned Float"  */
  YYSYMBOL_T_GAMEID = 5,                   /* "GameID"  */
  YYSYMBOL_T_FLOAT = 6,                    /* "Float"  */
  YYSYMBOL_T_JSON_STRING = 7,              /* "JSON String"  */
  YYSYMBOL_T_BOOLEAN = 8,                  /* "Boolean"  */
  YYSYMBOL_T_JSON_ARRAY = 9,               /* "JSON Array"  */
  YYSYMBOL_T_L_BRACE = 10,                 /* "Left Brace ({)"  */
  YYSYMBOL_T_R_BRACE = 11,                 /* "Right Brace (})"  */
  YYSYMBOL_T_L_BRACKET = 12,               /* "Left Bracket ([)"  */
  YYSYMBOL_T_R_BRACKET = 13,               /* "Right Bracket (])"  */
  YYSYMBOL_T_DOT = 14,                     /* "Dot (.)"  */
  YYSYMBOL_T_QUOTATIONS = 15,              /* "Quotations"  */
  YYSYMBOL_T_ASSIGNMENT = 16,              /* "Assignment (:)"  */
  YYSYMBOL_T_COMMA = 17,                   /* "Comma (,)"  */
  YYSYMBOL_T_U_INT_ARRAY = 18,             /* "Unsigned Integer Array"  */
  YYSYMBOL_T_LAST = 19,                    /* "Last"  */
  YYSYMBOL_T_ACTIVE = 20,                  /* "Active"  */
  YYSYMBOL_T_DRAWID = 21,                  /* "DrawID"  */
  YYSYMBOL_T_DRAWTIME = 22,                /* "Draw Time"  */
  YYSYMBOL_T_VISUALDRAW = 23,              /* "Visual Draw"  */
  YYSYMBOL_T_PRICEPOINTS = 24,             /* "Price Points"  */
  YYSYMBOL_T_AMOUNT = 25,                  /* "Amount"  */
  YYSYMBOL_T_WINNINGNUMBERS = 26,          /* "Winning Numbers"  */
  YYSYMBOL_T_LIST = 27,                    /* "List"  */
  YYSYMBOL_T_BONUS = 28,                   /* "Bonus"  */
  YYSYMBOL_T_PRIZECATEGORIES = 29,         /* "Prize Categories"  */
  YYSYMBOL_T_ID = 30,                      /* "ID"  */
  YYSYMBOL_T_DIVIDENT = 31,                /* "Divident"  */
  YYSYMBOL_T_WINNERS = 32,                 /* "Winners"  */
  YYSYMBOL_T_DISTRIBUTED = 33,             /* "Distributed"  */
  YYSYMBOL_T_JACKPOT = 34,                 /* "Jackpot"  */
  YYSYMBOL_T_FIXED = 35,                   /* "Fixed"  */
  YYSYMBOL_T_CATEGORYTYPE = 36,            /* "Category Type"  */
  YYSYMBOL_T_GAMETYPE = 37,                /* "Game Type"  */
  YYSYMBOL_T_MINIMUMDISTRIBUTED = 38,      /* "Minimum Distributed"  */
  YYSYMBOL_T_WAGERSTATISTICS = 39,         /* "Wager Statistics"  */
  YYSYMBOL_T_COLUMNS = 40,                 /* "Columns"  */
  YYSYMBOL_T_WAGERS = 41,                  /* "Wagers"  */
  YYSYMBOL_T_SORT = 42,                    /* "Sort"  */
  YYSYMBOL_T_DIRECTION = 43,               /* "Direction"  */
  YYSYMBOL_T_NUMBEROFELEMEMENTS = 44,      /* "Number of Elements"  */
  YYSYMBOL_T_TOTALELEMENTS = 45,           /* "Total Elements"  */
  YYSYMBOL_T_TOTALPAGES = 46,              /* "Total Pages"  */
  YYSYMBOL_T_DRAWBREAK = 47,               /* "Draw Break"  */
  YYSYMBOL_T_STATUS = 48,                  /* "Status"  */
  YYSYMBOL_T_CONTENT = 49,                 /* "Content"  */
  YYSYMBOL_T_ADDON = 50,                   /* "Addon"  */
  YYSYMBOL_T_PROPERTY = 51,                /* "Property"  */
  YYSYMBOL_T_IGNORE_CASE = 52,             /* "Ignore Case"  */
  YYSYMBOL_T_NULL_HANDLING = 53,           /* "Null Handling"  */
  YYSYMBOL_T_DESCENDING = 54,              /* "Descending"  */
  YYSYMBOL_T_ASCENDING = 55,               /* "Ascending"  */
  YYSYMBOL_T_FIRST = 56,                   /* "First"  */
  YYSYMBOL_T_SIZE = 57,                    /* "Size"  */
  YYSYMBOL_T_NUMBER = 58,                  /* "Number"  */
  YYSYMBOL_T_SIGN = 59,                    /* "sign"  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_program = 61,                   /* program  */
  YYSYMBOL_last_scope = 62,                /* last_scope  */
  YYSYMBOL_last = 63,                      /* last  */
  YYSYMBOL_order = 64,                     /* order  */
  YYSYMBOL_active = 65,                    /* active  */
  YYSYMBOL_active_scope = 66,              /* active_scope  */
  YYSYMBOL_wager_objects = 67,             /* wager_objects  */
  YYSYMBOL_columns = 68,                   /* columns  */
  YYSYMBOL_wagers = 69,                    /* wagers  */
  YYSYMBOL_add_on = 70,                    /* add_on  */
  YYSYMBOL_price_points = 71,              /* price_points  */
  YYSYMBOL_list = 72,                      /* list  */
  YYSYMBOL_bonus = 73,                     /* bonus  */
  YYSYMBOL_winning_numbers = 74,           /* winning_numbers  */
  YYSYMBOL_u_int_array = 75,               /* u_int_array  */
  YYSYMBOL_u_int_scope = 76,               /* u_int_scope  */
  YYSYMBOL_json_string = 77,               /* json_string  */
  YYSYMBOL_json_array = 78,                /* json_array  */
  YYSYMBOL_json_arr_scope = 79,            /* json_arr_scope  */
  YYSYMBOL_json_object = 80,               /* json_object  */
  YYSYMBOL_json_obj_scope = 81,            /* json_obj_scope  */
  YYSYMBOL_content_scope = 82,             /* content_scope  */
  YYSYMBOL_content = 83,                   /* content  */
  YYSYMBOL_total_pages = 84,               /* total_pages  */
  YYSYMBOL_total_elements = 85,            /* total_elements  */
  YYSYMBOL_number_of_elements = 86,        /* number_of_elements  */
  YYSYMBOL_sort = 87,                      /* sort  */
  YYSYMBOL_expr = 88,                      /* expr  */
  YYSYMBOL_first = 89,                     /* first  */
  YYSYMBOL_size = 90,                      /* size  */
  YYSYMBOL_number = 91                     /* number  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int16 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   306

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  297

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   314


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    97,    97,    98,    99,   102,   103,   104,   108,   109,
     110,   113,   114,   118,   119,   122,   122,   123,   124,   127,
     128,   131,   132,   135,   136,   139,   139,   140,   144,   145,
     148,   149,   152,   153,   156,   157,   160,   161,   164,   165,
     166,   169,   170,   171,   174,   175,   178,   179,   180,   183,
     184,   187,   188,   189,   192,   193,   194,   197,   200,   201,
     204,   205,   209,   210,   213,   214,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   245,   246,   249,   250,   253,   254
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "T_EOF", "error", "\"invalid token\"", "\"Unsigned Integer\"",
  "\"Unsigned Float\"", "\"GameID\"", "\"Float\"", "\"JSON String\"",
  "\"Boolean\"", "\"JSON Array\"", "\"Left Brace ({)\"",
  "\"Right Brace (})\"", "\"Left Bracket ([)\"", "\"Right Bracket (])\"",
  "\"Dot (.)\"", "\"Quotations\"", "\"Assignment (:)\"", "\"Comma (,)\"",
  "\"Unsigned Integer Array\"", "\"Last\"", "\"Active\"", "\"DrawID\"",
  "\"Draw Time\"", "\"Visual Draw\"", "\"Price Points\"", "\"Amount\"",
  "\"Winning Numbers\"", "\"List\"", "\"Bonus\"", "\"Prize Categories\"",
  "\"ID\"", "\"Divident\"", "\"Winners\"", "\"Distributed\"",
  "\"Jackpot\"", "\"Fixed\"", "\"Category Type\"", "\"Game Type\"",
  "\"Minimum Distributed\"", "\"Wager Statistics\"", "\"Columns\"",
  "\"Wagers\"", "\"Sort\"", "\"Direction\"", "\"Number of Elements\"",
  "\"Total Elements\"", "\"Total Pages\"", "\"Draw Break\"", "\"Status\"",
  "\"Content\"", "\"Addon\"", "\"Property\"", "\"Ignore Case\"",
  "\"Null Handling\"", "\"Descending\"", "\"Ascending\"", "\"First\"",
  "\"Size\"", "\"Number\"", "\"sign\"", "$accept", "program", "last_scope",
  "last", "order", "active", "active_scope", "wager_objects", "columns",
  "wagers", "add_on", "price_points", "list", "bonus", "winning_numbers",
  "u_int_array", "u_int_scope", "json_string", "json_array",
  "json_arr_scope", "json_object", "json_obj_scope", "content_scope",
  "content", "total_pages", "total_elements", "number_of_elements", "sort",
  "expr", "first", "size", "number", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-164)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-56)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,  -164,     8,    11,    -3,   -12,    24,    48,    46,  -164,
      80,    83,     9,  -164,    63,   100,   109,  -164,   113,   123,
    -164,    93,   118,    28,   124,   122,  -164,   125,    64,  -164,
      65,   107,   126,   127,  -164,    96,   121,  -164,    -4,   133,
       4,  -164,    65,    41,   132,   136,   144,   134,    67,   135,
     137,   138,   139,   140,   141,   142,   143,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,  -164,    65,    65,   166,    44,   107,
     107,  -164,     1,  -164,   162,  -164,   129,   163,   165,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,  -164,  -164,  -164,    65,    65,  -164,  -164,
     196,    45,   205,    69,   206,   207,   208,   209,   108,   112,
       2,   210,   211,   213,   214,   215,   216,   218,    70,   219,
     204,    70,   221,    70,    70,   217,    70,   220,   222,  -164,
    -164,  -164,     1,     1,  -164,  -164,   115,   200,  -164,  -164,
    -164,  -164,  -164,   164,  -164,  -164,    82,  -164,  -164,   107,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,    92,
    -164,  -164,    85,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,   212,    86,   197,  -164,   199,   223,   224,
      56,   226,   227,   228,   111,   225,   229,   231,  -164,   191,
     232,   233,   235,    87,  -164,   107,   107,  -164,  -164,   236,
    -164,    88,   240,   237,    89,   238,   239,  -164,   201,   242,
    -164,  -164,   241,  -164,   193,   243,  -164,   245,  -164,   202,
     246,   234,    95,   244,  -164,   253,   247,    66,     2,   249,
      90,   254,  -164,   263,  -164,   251,  -164,   252,  -164,   194,
    -164,  -164,   255,  -164,   230,   256,  -164,    59,   257,    95,
     266,   259,   264,   260,    91,   263,   263,  -164,  -164,  -164,
     261,  -164,   262,  -164,   248,  -164,  -164,  -164,   267,   273,
     265,   268,  -164,   269,  -164,   279,  -164
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     4,     0,     0,    10,     0,     0,     0,     0,     1,
       0,     0,     0,     3,     0,     0,     0,    14,     0,     0,
      59,     0,     0,     0,     0,     0,     2,     0,     0,     9,
       0,     0,     0,     0,    61,     0,     0,    91,     0,     0,
       0,    50,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     0,     0,     0,     0,     0,
       0,    57,     0,    58,     0,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     5,    49,     0,     0,    56,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      51,    13,     0,     0,    60,    63,     0,     0,    66,    67,
      68,    71,    29,     0,    72,    35,     0,    73,    45,     0,
      74,    76,    77,    78,    79,    80,    81,    82,    43,     0,
      83,    84,     0,    85,    70,    69,    86,    87,    88,    89,
      90,    18,    16,     0,     0,     0,    31,     0,     0,     0,
       0,     0,     0,    20,     0,     0,     0,     0,    65,     0,
       0,     0,     0,     0,    44,     0,     0,    41,    42,     0,
      75,     0,     0,     0,     0,     0,     0,    33,     0,     0,
      48,    46,     0,    24,     0,     0,    62,     0,    93,     0,
       0,     0,     0,     0,    34,     0,     0,     0,     0,     0,
       0,     0,    37,     0,    30,     0,    21,     0,    27,     0,
      19,    64,     0,    95,     0,     0,    28,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,    32,    23,
       0,    92,     0,    97,     0,    11,    40,    38,     0,     0,
       0,     0,    94,     0,    26,     0,    96
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -164,  -164,    18,   250,  -164,  -164,   -38,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,   -87,  -156,   -20,   -17,   -88,
    -163,    13,    52,  -164,  -164,  -164,  -164,  -164,   -42,  -164,
    -164,  -164
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     3,    39,     6,     7,    19,   120,   205,   206,   235,
     260,   164,   198,   229,   167,   254,   268,   180,   170,   199,
      43,    77,    44,     8,    22,    36,   157,   210,    40,   240,
     265,   285
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      78,    49,    37,   168,     1,    75,   200,    10,   -12,     4,
      17,     9,   -15,     2,   169,    -6,    38,    50,    51,    52,
      53,    76,    54,     5,    18,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    29,    11,    30,    66,
     121,    12,    79,    67,    68,   116,   152,    69,    70,    71,
      72,    73,   200,   200,   -55,   -52,   -17,   215,    80,    13,
     275,   117,   153,    14,    20,    34,    37,   258,    85,   -47,
     155,   178,   -39,   216,    78,    78,   276,   -25,    21,    35,
      38,   259,    86,   196,   156,   179,   203,   208,   227,   233,
     238,   263,   283,   113,   114,    15,   252,   197,    16,   201,
     204,   209,   228,   234,   239,   264,   284,   253,    41,   162,
     121,   121,   202,   165,   191,   192,    23,    42,   163,   286,
     287,   183,   166,   185,   186,    24,   188,   230,   231,   149,
     150,   118,   119,    25,    26,    28,    31,    32,    48,    27,
      33,    47,    45,    46,    74,    81,    82,    83,    10,    84,
      88,   219,    89,    90,    91,    92,    93,    94,    95,   193,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   115,   122,   195,
     123,   124,   278,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   151,   154,   158,
     159,   160,   161,   171,   182,   172,   173,   194,   174,   175,
     176,   177,   211,   181,   184,   187,   212,   207,   189,   243,
     190,   261,     0,   223,   246,     0,   220,   214,   251,     0,
     213,   217,   218,   236,   271,   -22,   221,   222,   225,   224,
     226,   232,   237,   244,   241,   242,   256,   245,   249,   255,
     247,   248,   257,   250,   262,   266,   267,   269,   270,   279,
     277,   272,   281,   274,   280,   282,   292,   288,   289,   291,
     293,   294,   296,     0,     0,   295,     0,   273,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    87,     0,
       0,     0,     0,     0,     0,     0,   290
};

static const yytype_int16 yycheck[] =
{
      42,     5,     1,     1,     1,     1,   169,    19,    11,     1,
       1,     0,    11,    10,    12,    11,    15,    21,    22,    23,
      24,    17,    26,    15,    15,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,     8,    49,    10,    43,
      82,    17,     1,    47,    48,     1,     1,    51,    52,    53,
      54,    55,   215,   216,    13,    11,    11,     1,    17,    11,
       1,    17,    17,    17,     1,     1,     1,     1,     1,    13,
       1,     1,    13,    17,   116,   117,    17,    11,    15,    15,
      15,    15,    15,     1,    15,    15,     1,     1,     1,     1,
       1,     1,     1,    75,    76,    15,     1,    15,    15,     7,
      15,    15,    15,    15,    15,    15,    15,    12,     1,     1,
     152,   153,    20,     1,   152,   153,    16,    10,    10,   275,
     276,   141,    10,   143,   144,    16,   146,   215,   216,   116,
     117,    79,    80,    20,    11,    17,    12,    15,    17,    46,
      15,    45,    16,    16,    11,    13,    10,     3,    19,    15,
      15,    40,    15,    15,    15,    15,    15,    15,    15,    44,
      15,    15,    15,    15,    15,    15,    15,    15,    15,    15,
      15,    15,    15,    15,    15,    15,    15,    11,    16,    15,
      17,    16,   269,    16,    16,    16,    16,    16,    16,    16,
      16,    16,    16,    16,    16,    16,    16,    16,    16,    16,
      16,    16,    16,    16,    16,    16,    16,    11,     3,     3,
       3,     3,     3,     3,    10,     4,     3,    17,     4,     4,
       4,     3,    25,     4,     3,     8,    27,    15,     8,    28,
       8,   248,    -1,    42,    41,    -1,    11,    13,     4,    -1,
      17,    15,    15,     3,    50,    17,    17,    16,    15,    17,
      15,    15,    15,    11,    16,    16,     3,    16,    56,    15,
      17,    16,    15,    17,    15,    11,     3,    16,    16,     3,
      13,    16,     8,    17,    15,    15,     3,    16,    16,    12,
      15,    13,     3,    -1,    -1,    16,    -1,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    10,    61,     1,    15,    63,    64,    83,     0,
      19,    49,    17,    11,    17,    15,    15,     1,    15,    65,
       1,    15,    84,    16,    16,    20,    11,    46,    17,     8,
      10,    12,    15,    15,     1,    15,    85,     1,    15,    62,
      88,     1,    10,    80,    82,    16,    16,    45,    17,     5,
      21,    22,    23,    24,    26,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    43,    47,    48,    51,
      52,    53,    54,    55,    11,     1,    17,    81,    88,     1,
      17,    13,    10,     3,    15,     1,    15,    63,    15,    15,
      15,    15,    15,    15,    15,    15,    15,    15,    15,    15,
      15,    15,    15,    15,    15,    15,    15,    15,    15,    15,
      15,    15,    15,    62,    62,    11,     1,    17,    82,    82,
      66,    88,    16,    17,    16,    16,    16,    16,    16,    16,
      16,    16,    16,    16,    16,    16,    16,    16,    16,    16,
      16,    16,    16,    16,    16,    16,    16,    16,    16,    81,
      81,    11,     1,    17,     3,     1,    15,    86,     3,     3,
       3,     3,     1,    10,    71,     1,    10,    74,     1,    12,
      78,     3,     4,     3,     4,     4,     4,     3,     1,    15,
      77,     4,    10,    77,     3,    77,    77,     8,    77,     8,
       8,    66,    66,    44,    17,    15,     1,    15,    72,    79,
      80,     7,    20,     1,    15,    67,    68,    15,     1,    15,
      87,    25,    27,    17,    13,     1,    17,    15,    15,    40,
      11,    17,    16,    42,    17,    15,    15,     1,    15,    73,
      79,    79,    15,     1,    15,    69,     3,    15,     1,    15,
      89,    16,    16,    28,    11,    16,    41,    17,    16,    56,
      17,     4,     1,    12,    75,    15,     3,    15,     1,    15,
      70,    78,    15,     1,    15,    90,    11,     3,    76,    16,
      16,    50,    16,    57,    17,     1,    17,    13,    75,     3,
      15,     8,    15,     1,    15,    91,    76,    76,    16,    16,
      58,    12,     3,    15,    13,    16,     3
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    61,    61,    62,    62,    62,    63,    63,
      63,    64,    64,    65,    65,    66,    66,    66,    66,    67,
      67,    68,    68,    69,    69,    70,    70,    70,    71,    71,
      72,    72,    73,    73,    74,    74,    75,    75,    76,    76,
      76,    77,    77,    77,    78,    78,    79,    79,    79,    80,
      80,    81,    81,    81,    82,    82,    82,    83,    84,    84,
      85,    85,    86,    86,    87,    87,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    89,    89,    90,    90,    91,    91
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     3,     1,     3,     1,     3,     7,     5,
       1,    17,     1,     7,     1,     0,     3,     1,     3,     5,
       1,     5,     1,     5,     1,     0,     6,     1,     7,     1,
       5,     1,     5,     1,     5,     1,     3,     1,     3,     1,
       3,     3,     3,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     1,     3,     3,     1,     3,     7,     5,     1,
       5,     1,     5,     1,     5,     1,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     7,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     1,     5,     1,     5,     1,     5,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= T_EOF)
    {
      yychar = T_EOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 8: /* last: "Quotations" "Last" "Quotations" "Assignment (:)" "Left Brace ({)" last_scope "Right Brace (})"  */
#line 108 "parser.y"
                                                                                                            {countAllElements();}
#line 1641 "parser.tab.c"
    break;

  case 13: /* active: "Quotations" "Active" "Quotations" "Assignment (:)" "Left Brace ({)" active_scope "Right Brace (})"  */
#line 118 "parser.y"
                                                                                                            {countActiveElements();}
#line 1647 "parser.tab.c"
    break;

  case 30: /* list: "Quotations" "List" "Quotations" "Assignment (:)" u_int_array  */
#line 148 "parser.y"
                                                                                    {counterChecker(intArrCounter, 5);intArrCounter=0;listflag=0;}
#line 1653 "parser.tab.c"
    break;

  case 32: /* bonus: "Quotations" "Bonus" "Quotations" "Assignment (:)" u_int_array  */
#line 152 "parser.y"
                                                                                     {counterChecker(intArrCounter, 1);intArrCounter=0;}
#line 1659 "parser.tab.c"
    break;

  case 38: /* u_int_scope: "Unsigned Integer" "Comma (,)" u_int_scope  */
#line 164 "parser.y"
                                                                        {intArrCounter++;}
#line 1665 "parser.tab.c"
    break;

  case 39: /* u_int_scope: "Unsigned Integer"  */
#line 165 "parser.y"
                                                                        {intArrCounter++;}
#line 1671 "parser.tab.c"
    break;

  case 49: /* json_object: "Left Brace ({)" json_obj_scope "Right Brace (})"  */
#line 183 "parser.y"
                                                                              {if(prizeCatflag==0 && contentflag==1)countAllElements();if(prizeCatflag==1)prCatCntr++;if(minDistFlg!=0){printf("Unexpected amount of \"minimumDistributed\" before line: %d\n", lineno);errors++;}minDistFlg=0;}
#line 1677 "parser.tab.c"
    break;

  case 57: /* content: "Quotations" "Content" "Quotations" "Assignment (:)" "Left Bracket ([)" content_scope "Right Bracket (])"  */
#line 197 "parser.y"
                                                                                                               {contentflag=0;}
#line 1683 "parser.tab.c"
    break;

  case 66: /* expr: "Quotations" "GameID" "Quotations" "Assignment (:)" "Unsigned Integer"  */
#line 217 "parser.y"
                                                                                                {validateGameId(value);}
#line 1689 "parser.tab.c"
    break;

  case 74: /* expr: "Quotations" "Prize Categories" "Quotations" "Assignment (:)" json_array  */
#line 225 "parser.y"
                                                                                                      {gameCatLimit(prCatCntr);prCatCntr=0;prizeCatflag=0;}
#line 1695 "parser.tab.c"
    break;

  case 76: /* expr: "Quotations" "ID" "Quotations" "Assignment (:)" "Unsigned Integer"  */
#line 227 "parser.y"
                                                                                                      {if(value < 1 || value > 9){errors++; printf("Expected a value from 1-8 got %d near line %d\n", value, lineno);} else if(value == 1) minDistFlg++;}
#line 1701 "parser.tab.c"
    break;

  case 82: /* expr: "Quotations" "Category Type" "Quotations" "Assignment (:)" "Unsigned Integer"  */
#line 233 "parser.y"
                                                                                                      {if(value != 0 && value != 1){errors++; printf("Expected 0 or 1 got %d near line %d\n", value, lineno);}}
#line 1707 "parser.tab.c"
    break;

  case 84: /* expr: "Quotations" "Minimum Distributed" "Quotations" "Assignment (:)" "Unsigned Float"  */
#line 235 "parser.y"
                                                                                                      {minDistFlg--;}
#line 1713 "parser.tab.c"
    break;


#line 1717 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= T_EOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == T_EOF)
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 257 "parser.y"

// count # of tokens in last, active and content 
int token_numbers[2][10]={T_GAMEID, T_DRAWID, T_DRAWTIME, T_STATUS, T_DRAWBREAK, T_VISUALDRAW, T_PRICEPOINTS, T_PRIZECATEGORIES, T_WAGERSTATISTICS, T_WINNINGNUMBERS};

void yyerror(const char *s) {
      errors++;
      printf("%s line: %d\n", s, lineno);
}									

void validateGameId(int val){
      //if value of gameId is not invalid
      if(val!=1100 && val!=1110 && val!=2100 && val!=2101 && val!=5103 && val!=5104 && val!=5106)
            {
                  printf("Invalid gameId: %d near line: %d\n\n", val, lineno);
                  errors++;
            }
}

//validates that "gameCategory" contains 8 json objects
void gameCatLimit(int counter){
      if(counter != 8 ){
            errors++;
            printf("\n\nExpected 8 JSON objects in prizeCategories found: %d, near line: %d\n",prCatCntr,lineno);  
      }

}

//integers in "list" must be in [1,45]
void listIntegerInterval(int val){
      if(!(val >= 1 && val <= 45) ){
            errors++;
            printf("\n\nExpected wait what an integer in [1, 45] found: %d, near line: %d\n", val, lineno);  
      }
}

//counts elements in "last" for last_result and in "content" for range_result
void countAllElements(){
      for(int i=0; i<10; i++){
            //contains each token specified in token_numbers[0][0:9] once
            if(token_numbers[1][i] != 1){
                  errors++;
                  printf("Found %d %s expected 1 before line: %d\n", token_numbers[1][i], yytname[YYTRANSLATE(token_numbers[0][i])], lineno);
            }
            //reset array
            token_numbers[1][i]=0;
      }
}

//counts elements in "active" for file last_result
void countActiveElements(){
      for(int i=0; i<9; i++){
            //contains each token specified in token_numbers[0][0:8] once 
            if(token_numbers[1][i] != 1){
                  errors++;
                  printf("Found %d %s expected 1 in \"active\" before line: %d\n", token_numbers[1][i], yytname[YYTRANSLATE(token_numbers[0][i])], lineno);
            }
            //reset array
            token_numbers[1][i] = 0;
      }
      //does not contain "winningNumbers"
      if(token_numbers[1][9] != 0){
            errors++;
            printf("Found %d %s expected 0 in \"active\" before line: %d\n", token_numbers[1][9], yytname[YYTRANSLATE(token_numbers[0][9])], lineno);
            //reset array
            token_numbers[1][9] = 0;
      }
}

//validates # of entries in an array
void counterChecker(int counter, int limit)
{
      //counter: # integers read
      //limit: # expected integers in an array
      if(counter != limit){
            printf("Found %d integers expected %d before line: %d\n", counter, limit, lineno);
            errors++;
      }
}

int main ( int argc, char **argv  ) 
{
      ++argv; --argc;
      if ( argc > 0 )
            yyin = fopen( argv[0], "r" );
      else
            yyin = stdin;
      yyout = fopen ( "output", "w" );	
      yyparse (); 
      fclose(yyout);
      fclose(yyin);   
      if(errors == 0)
            printf("\n\nParsing successful \n\n");
      else
            printf("\n\nParsing failed due to %d errors \n\n", errors);

      return 0;
}   
