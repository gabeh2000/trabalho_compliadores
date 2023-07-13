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
#line 1 "nico.y"

  /* Aqui, pode-se inserir qualquer codigo C necessario ah compilacao
   * final do parser. Sera copiado tal como esta no inicio do y.tab.c
   * gerado por Yacc.
   */
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <assert.h>
	#include "node.h"
	#include "symbol_table.h"
	#include "lista.h"
	#define YYDEBUG 1

	#define CHAR_TYPE 0
	#define INT_TYPE 1
	#define FLOAT_TYPE 2

	#define CHAR_SIZE 1
	#define INT_SIZE 4
	#define FLOAT_SIZE 8



	extern int yyerror(const char* msg ); 
	extern int yylex();

	extern Node * syntax_tree;
	extern symbol_t symbol_table;
	
	int v_size = 0;
	int t_size_now = 0;
	int t_size = 0;
	int max_t_size = 0;
	int v_desloc = 0;
	int reg = 0;
	int file_num = 0;
	entry_t *new_entry(char *lx){
        entry_t *new_entry = (entry_t *)malloc(sizeof(entry_t));
        new_entry->name = strdup(lx);
        new_entry->desloc = v_desloc;
        new_entry->size = v_size;
        v_desloc += new_entry->size;
        return new_entry;
    }

    void atrib(char *lx){
		//print_table(symbol_table);
		if(lookup(symbol_table,lx)){
			printf("entrou no if\n");
			return;
		}
        if (insert(&symbol_table, new_entry(lx)) != 0){
            printf("Symbol table atrib ERROR:%s\n", lx);
			free_table(&symbol_table);
            exit(0);
        }
    }

	char *rx(int desloc){
		char *t = malloc(sizeof(char)*2);
		sprintf(t, "%03d(RX)", desloc);
		return t;
	}

	char *sp(char *id){
		entry_t* aux = lookup(symbol_table, id);
		
		if(aux != NULL){       
			char *t = malloc(sizeof(char)*2);
			sprintf(t, "%03d(SP)", aux->desloc);
			return t;
		}
		else{			
			printf("UNDEFINED: %s \n", id);
			exit(0);
		}
	}


#line 151 "y.tab.c"

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
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MIN = 258,
    PLUS = 259,
    AST = 260,
    BAR = 261,
    AND = 262,
    OR = 263,
    NOT = 264,
    TEXT = 265,
    SEMICOLON = 266,
    INC = 267,
    DEC = 268,
    COMA = 269,
    ATRIB = 270,
    COLON = 271,
    PERIOD = 272,
    BRAKCLOSE = 273,
    BRAKOPN = 274,
    PARCLOSE = 275,
    PAROPN = 276,
    KOPN = 277,
    KCLOSE = 278,
    INT = 279,
    DOUBLE = 280,
    FLOAT = 281,
    CHAR = 282,
    QUOTE = 283,
    DQUOTE = 284,
    LE = 285,
    GE = 286,
    EQ = 287,
    NE = 288,
    IF = 289,
    THEN = 290,
    ELSE = 291,
    WHILE = 292,
    FOR = 293,
    CLASS = 294,
    PUBLIC = 295,
    PRIVATE = 296,
    PROTECTED = 297,
    VOID = 298,
    NUL = 299,
    CONST = 300,
    STATIC = 301,
    LESS = 302,
    GREAT = 303,
    STRING = 304,
    PRINT = 305,
    TRUE_ = 306,
    FALSE_ = 307,
    IDF = 308,
    INT_LIT = 309,
    F_LIT = 310
  };
#endif
/* Tokens.  */
#define MIN 258
#define PLUS 259
#define AST 260
#define BAR 261
#define AND 262
#define OR 263
#define NOT 264
#define TEXT 265
#define SEMICOLON 266
#define INC 267
#define DEC 268
#define COMA 269
#define ATRIB 270
#define COLON 271
#define PERIOD 272
#define BRAKCLOSE 273
#define BRAKOPN 274
#define PARCLOSE 275
#define PAROPN 276
#define KOPN 277
#define KCLOSE 278
#define INT 279
#define DOUBLE 280
#define FLOAT 281
#define CHAR 282
#define QUOTE 283
#define DQUOTE 284
#define LE 285
#define GE 286
#define EQ 287
#define NE 288
#define IF 289
#define THEN 290
#define ELSE 291
#define WHILE 292
#define FOR 293
#define CLASS 294
#define PUBLIC 295
#define PRIVATE 296
#define PROTECTED 297
#define VOID 298
#define NUL 299
#define CONST 300
#define STATIC 301
#define LESS 302
#define GREAT 303
#define STRING 304
#define PRINT 305
#define TRUE_ 306
#define FALSE_ 307
#define IDF 308
#define INT_LIT 309
#define F_LIT 310

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 90 "nico.y"

	char* cadeia;
	struct _node * no;

#line 318 "y.tab.c"

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


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
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
typedef yytype_int8 yy_state_t;

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
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
#define YYFINAL  26
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   127

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  107

#define YYUNDEFTOK  2
#define YYMAXUTOK   310


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   180,   180,   187,   188,   195,   203,   218,   228,   236,
     238,   240,   244,   245,   246,   247,   248,   249,   260,   268,
     277,   285,   309,   339,   357,   362,   374,   416,   419,   451,
     463,   473,   482,   491,   493,   496,   497,   508,   515,   521,
     528,   530,   532,   534,   536,   538,   543,   547,   565,   580,
     595,   610
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MIN", "PLUS", "AST", "BAR", "AND", "OR",
  "NOT", "TEXT", "SEMICOLON", "INC", "DEC", "COMA", "ATRIB", "COLON",
  "PERIOD", "BRAKCLOSE", "BRAKOPN", "PARCLOSE", "PAROPN", "KOPN", "KCLOSE",
  "INT", "DOUBLE", "FLOAT", "CHAR", "QUOTE", "DQUOTE", "LE", "GE", "EQ",
  "NE", "IF", "THEN", "ELSE", "WHILE", "FOR", "CLASS", "PUBLIC", "PRIVATE",
  "PROTECTED", "VOID", "NUL", "CONST", "STATIC", "LESS", "GREAT", "STRING",
  "PRINT", "TRUE_", "FALSE_", "IDF", "INT_LIT", "F_LIT", "$accept", "code",
  "comando", "declaracoes", "declaracao", "tipo", "acoes", "for", "while",
  "if", "ifelse", "print", "texto", "att", "expressao", "and_or", "expr",
  "AUX_idf_val", "comparador", "calc", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310
};
# endif

#define YYPACT_NINF (-21)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      67,   -21,   -21,   -21,   -17,     8,    39,    40,    -6,    64,
     -21,    67,    58,    18,    67,   -21,   -21,   -21,   -21,   -21,
     -21,     1,     1,   -19,    13,   -15,   -21,   -21,   -21,    -6,
     -21,   -21,     1,     1,   -21,   -21,   -21,   -21,   -21,    60,
     -21,   -21,    15,    95,    59,    63,   -21,   -21,    55,   -15,
     105,   -21,    99,    11,   -21,   -21,    54,     1,   -15,   -15,
     -15,   -15,   -21,   -21,   -21,   -21,   -21,   -21,   -15,    57,
       1,     1,    70,    92,   -21,   -21,    67,    25,    30,    30,
     -21,   -21,   105,    67,    17,    19,   -21,    76,    77,    33,
      33,    78,   -21,    93,    96,    68,   100,   101,    67,    67,
      67,    98,   102,   103,   -21,   -21,   -21
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     9,    10,    11,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     0,     3,    12,    13,    14,    15,    16,
      17,     0,     0,     0,     0,     0,     1,     4,     6,     7,
       8,     5,     0,     0,    31,    32,    37,    38,    39,     0,
      27,    46,    35,     0,     0,     0,    24,    25,     0,     0,
      26,    29,     0,    35,    33,    34,     0,     0,     0,     0,
       0,     0,    45,    44,    42,    43,    41,    40,     0,     0,
       0,     0,     0,     0,    30,    51,     3,    28,    48,    47,
      49,    50,    36,     3,     0,     0,    23,     0,     0,     0,
       0,    21,    20,     0,     0,     0,     0,     0,     3,     3,
       3,     0,     0,     0,    22,    19,    18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -21,   -21,   -11,   -21,   104,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,   -12,   -20,   -21,   -21,   -21,   -21,    24
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    48,    20,    39,    57,    40,    41,    68,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      27,    30,    43,    31,    21,     1,    49,     2,     3,    25,
      32,    45,    51,    52,    58,    59,    60,    61,    58,    59,
      60,    61,    33,    46,    54,    55,    54,    55,    89,    22,
      90,    75,    54,    55,     8,    60,    61,    77,    36,    37,
      38,    62,    63,    64,    65,    62,    63,    64,    65,    50,
      84,    85,    34,    35,    36,    37,    38,    53,    66,    67,
      23,    24,    66,    67,    26,    87,    47,    54,    55,    28,
      70,    29,    88,    73,    71,    72,    76,    93,    94,    83,
      56,    86,    78,    79,    80,    81,     8,   101,   102,   103,
      98,     1,    82,     2,     3,    58,    59,    60,    61,    91,
      92,     4,    54,    55,     5,     6,    54,    55,    58,    59,
      60,    61,    75,    96,    95,    69,    97,     7,     0,    74,
       8,   104,    99,   100,     0,   105,   106,    44
};

static const yytype_int8 yycheck[] =
{
      11,    13,    22,    14,    21,    24,    21,    26,    27,    15,
       9,    23,    32,    33,     3,     4,     5,     6,     3,     4,
       5,     6,    21,    10,     7,     8,     7,     8,    11,    21,
      11,    20,     7,     8,    53,     5,     6,    57,    53,    54,
      55,    30,    31,    32,    33,    30,    31,    32,    33,    25,
      70,    71,    51,    52,    53,    54,    55,    33,    47,    48,
      21,    21,    47,    48,     0,    76,    53,     7,     8,    11,
      11,    53,    83,    49,    11,    20,    22,    89,    90,    22,
      20,    11,    58,    59,    60,    61,    53,    98,    99,   100,
      22,    24,    68,    26,    27,     3,     4,     5,     6,    23,
      23,    34,     7,     8,    37,    38,     7,     8,     3,     4,
       5,     6,    20,    20,    36,    20,    20,    50,    -1,    20,
      53,    23,    22,    22,    -1,    23,    23,    23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    24,    26,    27,    34,    37,    38,    50,    53,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      69,    21,    21,    21,    21,    15,     0,    58,    11,    53,
      69,    58,     9,    21,    51,    52,    53,    54,    55,    70,
      72,    73,    75,    70,    60,    69,    10,    53,    68,    21,
      75,    70,    70,    75,     7,     8,    20,    71,     3,     4,
       5,     6,    30,    31,    32,    33,    47,    48,    74,    20,
      11,    11,    20,    75,    20,    20,    22,    70,    75,    75,
      75,    75,    75,    22,    70,    70,    11,    58,    58,    11,
      11,    23,    23,    69,    69,    36,    20,    20,    22,    22,
      22,    58,    58,    58,    23,    23,    23
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    58,    58,    59,    60,    60,    61,
      61,    61,    62,    62,    62,    62,    62,    62,    63,    63,
      64,    65,    66,    67,    68,    68,    69,    70,    70,    70,
      70,    70,    70,    71,    71,    72,    72,    73,    73,    73,
      74,    74,    74,    74,    74,    74,    75,    75,    75,    75,
      75,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,    11,    11,
       7,     7,    11,     5,     1,     1,     3,     1,     3,     2,
       3,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3
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
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
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
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 180 "nico.y"
             { (yyval.no) = create_node((yylsp[0]).first_line, 0, "Root", (yyvsp[0].no), NULL); syntax_tree = (yyval.no); cat_tac(&((yyval.no)->code),  &((yyvsp[0].no)->code)); 
		/*char *t = malloc(sizeof(char)*12);
		sprintf(t, "lista%d.txt", file_num++);
		FILE* file = fopen(t, "w");
    	print_tac(file, $$->code);*/
}
#line 1687 "y.tab.c"
    break;

  case 3:
#line 187 "nico.y"
                                       { (yyval.no) = create_node(1, 0, "Vazio", NULL); }
#line 1693 "y.tab.c"
    break;

  case 4:
#line 188 "nico.y"
                     { (yyval.no) = create_node((yylsp[-1]).first_line, code_node, NULL, (yyvsp[-1].no), (yyvsp[0].no), NULL);  
	cat_tac(&((yyval.no)->code),  &((yyvsp[-1].no)->code)); cat_tac(&((yyval.no)->code),  &((yyvsp[0].no)->code));
		/*char *t = malloc(sizeof(char)*12);
		sprintf(t, "lista%d.txt", file_num++);
		FILE* file = fopen(t, "w");
    	print_tac(file, $$->code);*/
		}
#line 1705 "y.tab.c"
    break;

  case 5:
#line 195 "nico.y"
               { (yyval.no) = create_node((yylsp[-1]).first_line, code_node, NULL, (yyvsp[-1].no),(yyvsp[0].no), NULL); 
	cat_tac(&((yyval.no)->code),  &((yyvsp[-1].no)->code));cat_tac(&((yyval.no)->code),  &((yyvsp[0].no)->code)); 
		/*char *t = malloc(sizeof(char)*12);
		sprintf(t, "lista%d.txt", file_num++);
		FILE* file = fopen(t, "w");
    	print_tac(file, $$->code);*/
}
#line 1717 "y.tab.c"
    break;

  case 6:
#line 203 "nico.y"
                                  { 
	Node *no_SEMICOLON = create_node((yylsp[-1]).first_line, pontoevirgula_node,  (yyvsp[0].cadeia), NULL);

	(yyval.no) = create_node((yylsp[-1]).first_line, declaracoes_node, NULL, (yyvsp[-1].no), no_SEMICOLON, NULL);
	cat_tac(&((yyval.no)->code),  &((yyvsp[-1].no)->code));
	
		/*char *t = malloc(sizeof(char)*12);
		sprintf(t, "lista%d.txt", file_num++);
		FILE* file = fopen(t, "w");
    	print_tac(file, $$->code);*/
	
	}
#line 1734 "y.tab.c"
    break;

  case 7:
#line 218 "nico.y"
                     { Node *no_IDF = create_node((yylsp[-1]).first_line, declaracao_node, (yyvsp[0].cadeia), NULL);
(yyval.no) = create_node((yylsp[-1]).first_line, declaracao_node, NULL, (yyvsp[-1].no), no_IDF, NULL);
 		atrib((yyvsp[0].cadeia));
		Tac* tac_vazio = create_inst_tac("","","","");
		append_inst_tac(&((yyval.no)->code),tac_vazio);
 		/*char *t = malloc(sizeof(char)*12);
		sprintf(t, "lista%d.txt", file_num++);
		FILE* file = fopen(t, "w");
    	print_tac(file, $$->code);*/
 }
#line 1749 "y.tab.c"
    break;

  case 8:
#line 228 "nico.y"
           {(yyval.no) = create_node((yylsp[-1]).first_line, declaracao_node, NULL, (yyvsp[-1].no), (yyvsp[0].no), NULL); cat_tac(&((yyval.no)->code),  &((yyvsp[0].no)->code));

		/*char *t = malloc(sizeof(char)*12);
		sprintf(t, "lista%d.txt", file_num++);
		FILE* file = fopen(t, "w");
    	print_tac(file, $$->code);*/
}
#line 1761 "y.tab.c"
    break;

  case 9:
#line 236 "nico.y"
          {
	(yyval.no) = create_node((yylsp[0]).first_line, int_node, (yyvsp[0].cadeia), NULL); v_size=INT_SIZE; }
#line 1768 "y.tab.c"
    break;

  case 10:
#line 238 "nico.y"
        {
	(yyval.no) = create_node((yylsp[0]).first_line, float_node, (yyvsp[0].cadeia), NULL);v_size=FLOAT_SIZE;}
#line 1775 "y.tab.c"
    break;

  case 11:
#line 240 "nico.y"
       {
	(yyval.no) = create_node((yylsp[0]).first_line, char_node, (yyvsp[0].cadeia), NULL);v_size=CHAR_SIZE;}
#line 1782 "y.tab.c"
    break;

  case 12:
#line 244 "nico.y"
           {(yyval.no) = create_node((yylsp[0]).first_line, for_node, NULL, (yyvsp[0].no), NULL);}
#line 1788 "y.tab.c"
    break;

  case 13:
#line 245 "nico.y"
        {(yyval.no) = create_node((yylsp[0]).first_line, while_node, NULL, (yyvsp[0].no), NULL);}
#line 1794 "y.tab.c"
    break;

  case 14:
#line 246 "nico.y"
     {(yyval.no) = create_node((yylsp[0]).first_line, if_node, NULL, (yyvsp[0].no), NULL);}
#line 1800 "y.tab.c"
    break;

  case 15:
#line 247 "nico.y"
         {(yyval.no) = create_node((yylsp[0]).first_line, else_node, NULL, (yyvsp[0].no), NULL);}
#line 1806 "y.tab.c"
    break;

  case 16:
#line 248 "nico.y"
        {(yyval.no) = create_node((yylsp[0]).first_line, print_node, NULL, (yyvsp[0].no), NULL);cat_tac(&((yyval.no)->code),  &((yyvsp[0].no)->code));}
#line 1812 "y.tab.c"
    break;

  case 17:
#line 249 "nico.y"
      {(yyval.no) = create_node((yylsp[0]).first_line, atribuicao_node, NULL, (yyvsp[0].no), NULL); cat_tac(&((yyval.no)->code),  &((yyvsp[0].no)->code));
		//printa uma lista de tac pra cada operação aritmética
		/*char *t = malloc(sizeof(char)*12);
		sprintf(t, "lista%d.txt", file_num++);
		FILE* file = fopen(t, "w");
    	print_tac(file, $$->code);
		fclose(file);*/
}
#line 1825 "y.tab.c"
    break;

  case 18:
#line 260 "nico.y"
                                                                                   {
	Node *no_FOR = create_node((yylsp[-10]).first_line, forlex_node, (yyvsp[-10].cadeia), NULL);
	Node *no_PAROPN = create_node((yylsp[-10]).first_line, abrepar_node,  (yyvsp[-9].cadeia), NULL);
	Node *no_SEMICOLON = create_node((yylsp[-10]).first_line, pontoevirgula_node,  (yyvsp[-7].cadeia), NULL);
	Node *no_PARCLOSE = create_node((yylsp[-10]).first_line, fechapar_node,  (yyvsp[-3].cadeia), NULL);
	Node *no_KOPN = create_node((yylsp[-10]).first_line, abrechaves_node,  (yyvsp[-2].cadeia), NULL);
	Node *no_KCLOSE = create_node((yylsp[-10]).first_line, fechachaves_node, (yyvsp[0].cadeia), NULL);
	(yyval.no) = create_node((yylsp[-10]).first_line, forlex_node, NULL, no_FOR, no_PAROPN, (yyvsp[-8].no), no_SEMICOLON,(yyvsp[-6].no), no_SEMICOLON, (yyvsp[-4].no), no_PARCLOSE, no_KOPN, (yyvsp[-1].no), no_KCLOSE, NULL);}
#line 1838 "y.tab.c"
    break;

  case 19:
#line 268 "nico.y"
                                                                                       {
	Node *no_FOR = create_node((yylsp[-10]).first_line, forlex_node, (yyvsp[-10].cadeia), NULL);
	Node *no_PAROPN = create_node((yylsp[-10]).first_line, abrepar_node,  (yyvsp[-9].cadeia), NULL);
	Node *no_SEMICOLON = create_node((yylsp[-10]).first_line, pontoevirgula_node,  (yyvsp[-7].cadeia), NULL);
	Node *no_PARCLOSE = create_node((yylsp[-10]).first_line, fechapar_node,  (yyvsp[-3].cadeia), NULL);
	Node *no_KOPN = create_node((yylsp[-10]).first_line, abrechaves_node,  (yyvsp[-2].cadeia), NULL);
	Node *no_KCLOSE = create_node((yylsp[-10]).first_line, fechachaves_node, (yyvsp[0].cadeia), NULL);
	(yyval.no) = create_node((yylsp[-10]).first_line, forlex_node, NULL, no_FOR, no_PAROPN, (yyvsp[-8].no), no_SEMICOLON,(yyvsp[-6].no), no_SEMICOLON, (yyvsp[-4].no), no_PARCLOSE, no_KOPN, (yyvsp[-1].no), no_KCLOSE, NULL);}
#line 1851 "y.tab.c"
    break;

  case 20:
#line 277 "nico.y"
                                                           {
	Node *no_WHILE = create_node((yylsp[-6]).first_line, whilelex_node, (yyvsp[-6].cadeia), NULL);
	Node *no_PAROPN = create_node((yylsp[-6]).first_line, abrepar_node,  (yyvsp[-5].cadeia), NULL);
	Node *no_PARCLOSE = create_node((yylsp[-6]).first_line, fechapar_node,  (yyvsp[-3].cadeia), NULL);
	Node *no_KOPN = create_node((yylsp[-6]).first_line, abrechaves_node,  (yyvsp[-2].cadeia), NULL);
	Node *no_KCLOSE = create_node((yylsp[-6]).first_line, fechachaves_node, (yyvsp[0].cadeia), NULL);
	(yyval.no) = create_node((yylsp[-6]).first_line, whilelex_node, NULL, no_WHILE, no_PAROPN, (yyvsp[-4].no), no_PARCLOSE, no_KOPN,(yyvsp[-1].no), no_KCLOSE, NULL);}
#line 1863 "y.tab.c"
    break;

  case 21:
#line 285 "nico.y"
                                                     {
	Node *no_IF = create_node((yylsp[-6]).first_line, iflex_node, (yyvsp[-6].cadeia), NULL);
	Node *no_PAROPN = create_node((yylsp[-6]).first_line, abrepar_node,  (yyvsp[-5].cadeia), NULL);
	Node *no_PARCLOSE = create_node((yylsp[-6]).first_line, fechapar_node,  (yyvsp[-3].cadeia), NULL);
	Node *no_KOPN = create_node((yylsp[-6]).first_line, abrechaves_node,  (yyvsp[-2].cadeia), NULL);
	Node *no_KCLOSE = create_node((yylsp[-6]).first_line, fechachaves_node, (yyvsp[0].cadeia), NULL);
	(yyval.no) = create_node((yylsp[-6]).first_line, iflex_node, NULL, no_IF, no_PAROPN, (yyvsp[-4].no), no_PARCLOSE,no_KOPN,(yyvsp[-1].no),no_KCLOSE, NULL);

	(yyvsp[-4].no)->t = strdup("novo_rot");
	(yyvsp[-4].no)->f = strdup((yyval.no)->f);

	(yyvsp[-1].no)->f= strdup((yyval.no)->f);

	Tac* new_true= create_inst_tac((yyvsp[-4].no)->t,"",":","");
	Tac* new_false = create_inst_tac((yyval.no)->f,"",":","");

	append_inst_tac(&((yyvsp[-1].no)->code),new_false);
	append_inst_tac(&((yyvsp[-4].no)->code),new_true);

	cat_tac(&((yyvsp[-4].no)->code),&((yyvsp[-1].no)->code));
	cat_tac(&((yyval.no)->code),&((yyvsp[-4].no)->code));
	
	}
#line 1891 "y.tab.c"
    break;

  case 22:
#line 309 "nico.y"
                                                                                  {
	Node *no_IF = create_node((yylsp[-10]).first_line, iflex_node, (yyvsp[-10].cadeia), NULL);
	Node *no_ELSE = create_node((yylsp[-10]).first_line, elselex_node, (yyvsp[-3].cadeia), NULL);
	Node *no_KOPN = create_node((yylsp[-10]).first_line, abrechaves_node,  (yyvsp[-6].cadeia), NULL);
	Node *no_KCLOSE = create_node((yylsp[-10]).first_line, fechachaves_node, (yyvsp[-4].cadeia), NULL);
	Node *no_PAROPN = create_node((yylsp[-10]).first_line, abrepar_node,  (yyvsp[-9].cadeia), NULL);
	Node *no_PARCLOSE = create_node((yylsp[-10]).first_line, fechapar_node,  (yyvsp[-7].cadeia), NULL);
	(yyval.no) = create_node((yylsp[-10]).first_line, elselex_node, NULL, no_IF, no_PAROPN, (yyvsp[-8].no), no_PARCLOSE,no_KOPN,(yyvsp[-5].no),no_KCLOSE,no_ELSE, no_KOPN, (yyvsp[-1].no),no_KCLOSE, NULL); 
	(yyvsp[-8].no)->t = strdup("novo_rot");
	(yyvsp[-8].no)->f = strdup("novo_rot");

	(yyvsp[-5].no)->f = strdup((yyval.no)->f);
	(yyvsp[-1].no)->f = strdup((yyval.no)->f);

	Tac* new_true= create_inst_tac((yyvsp[-8].no)->t,"",":","");
	Tac* new_goto= create_inst_tac("","","goto",(yyval.no)->f);
	Tac* new_false= create_inst_tac((yyvsp[-8].no)->f,"",":","");
	Tac* new_next= create_inst_tac((yyval.no)->f,"",":","");

	append_inst_tac(&((yyvsp[-1].no)->code), new_next);
	append_inst_tac(&((yyvsp[-5].no)->code), new_goto);
	append_inst_tac(&((yyvsp[-5].no)->code), new_false);
	append_inst_tac(&((yyvsp[-8].no)->code), new_true);

	cat_tac(&((yyvsp[-5].no)->code),&((yyvsp[-1].no)->code));
	cat_tac(&((yyvsp[-8].no)->code),&((yyvsp[-5].no)->code));
	cat_tac(&((yyval.no)->code),&((yyvsp[-8].no)->code));

	}
#line 1925 "y.tab.c"
    break;

  case 23:
#line 339 "nico.y"
                                             {
	
	Node *no_PRINT = create_node((yylsp[-4]).first_line, print_lex_node, (yyvsp[-4].cadeia), NULL);
	Node *no_PAROPN = create_node((yylsp[-4]).first_line, abrepar_node, (yyvsp[-3].cadeia), NULL);
	Node *no_PARCLOSE = create_node((yylsp[-4]).first_line, fechapar_node,  (yyvsp[-1].cadeia), NULL);
	Node *no_SEMICOLON = create_node((yylsp[-4]).first_line, pontoevirgula_node,  (yyvsp[0].cadeia), NULL);

	(yyval.no) = create_node((yylsp[-4]).first_line, print_lex_node, NULL, no_PRINT, no_PAROPN, (yyvsp[-2].no), no_PARCLOSE,no_SEMICOLON, NULL);
	
	Tac* new_tac = create_inst_tac(sp((yyvsp[-2].no)->lexeme),"","PRINT","");
	//printf("\n\n Tac dentro do att %s := %s \n",sp($1),$3->lexeme);

 	cat_tac(&((yyval.no)->code), &((yyvsp[-2].no)->code));

 	append_inst_tac(&((yyval.no)->code),new_tac);

	}
#line 1947 "y.tab.c"
    break;

  case 24:
#line 357 "nico.y"
           {(yyval.no) = create_node((yylsp[0]).first_line, text_lex_node, (yyvsp[0].cadeia), NULL); 
	Tac* tac_vazio = create_inst_tac("","","","");
	t_size_now = CHAR_SIZE;
	append_inst_tac(&((yyval.no)->code),tac_vazio);}
#line 1956 "y.tab.c"
    break;

  case 25:
#line 362 "nico.y"
   {
	(yyval.no) = create_node((yylsp[0]).first_line, idf_node, (yyvsp[0].cadeia), NULL); 
	Tac* tac_vazio = create_inst_tac("","","","");
	entry_t* aux = lookup(symbol_table,(yyvsp[0].cadeia));
	t_size_now = aux->size;
	append_inst_tac(&((yyval.no)->code),tac_vazio);
}
#line 1968 "y.tab.c"
    break;

  case 26:
#line 374 "nico.y"
                    {
	Node *no_IDF = create_node((yylsp[-2]).first_line, idf_node, (yyvsp[-2].cadeia), NULL);
	Node *no_ATRIB = create_node((yylsp[-2]).first_line, atribuicao_node,  (yyvsp[-1].cadeia), NULL);
	
	(yyval.no) = create_node((yylsp[-2]).first_line, atribuicaolex_node, NULL, no_IDF, no_ATRIB, (yyvsp[0].no), NULL);
	
	atrib((yyvsp[-2].cadeia));
	
	/*
	Anotação pra raciocinar como utilizar o lista.h aqui pra fazer um código TAC decente
	
	a gente quer gerar algo como: 000:000(Rx) := 000(SP) := 0
	isso seria o equivalente a: int i = 0;
	vou precisar pegar a posição da variável na symbol table
	pra criar uma instrução tac temos a função: Tac* create_inst_tac(const char* res, const char* arg1,const char* op, const char* arg2)
	então, pra gerar o tac de int i = 0 eu teria que passar create_inst_tac(i,0,NULL,NULL)
	pra algo como i = 2 + 3 seria create_inst_tac(i,2,+,3)
	mas o certo seria algo como create_inst_tac("000(SP)","2","+","3")
	ok, com isso a gente tem uma noção do que tem que fazer, quando for um terminal a gente tem que transformar ele em um SP caso seja um IDF
	caso a operação seja com mais de dois argumentos precisaremos de guardar alguns resultados em um RX, aka temporário

	Blz, com isso tirado do caminho, falta definirmos como vamos usar o resto das funções do lista.h
	Nossa lista está dentro do nosso nodo
	Então, toda a vez que a gente gerar um tac temos que colocá-lo dentro de um node tac com o append_inst_tac
	Também é preciso concatenar as listas de tacs, considerando que cada uma delas está dentro de um nodo, com o cat_tac
	
	*/
	Tac* new_tac = create_inst_tac(sp((yyvsp[-2].cadeia)),(yyvsp[0].no)->lexeme,"atribuicao","");
	printf("\n\n Tac dentro do att %s := %s \n",sp((yyvsp[-2].cadeia)),(yyvsp[0].no)->lexeme);

 	cat_tac(&((yyval.no)->code), &((yyvsp[0].no)->code));

 	append_inst_tac(&((yyval.no)->code),new_tac);
	t_size = 0;

	/*char *t = malloc(sizeof(char)*12);
		sprintf(t, "lista%d.txt", file_num++);
		FILE* file = fopen(t, "w");
    	print_tac(file, $$->code);*/
}
#line 2013 "y.tab.c"
    break;

  case 27:
#line 416 "nico.y"
                {(yyval.no) = create_node((yylsp[0]).first_line, expr_node, NULL, (yyvsp[0].no), NULL);
				cat_tac(&((yyval.no)->code), &((yyvsp[0].no)->code));
}
#line 2021 "y.tab.c"
    break;

  case 28:
#line 419 "nico.y"
                             {(yyval.no) = create_node((yylsp[-2]).first_line, expr_node, NULL, (yyvsp[-2].no), (yyvsp[-1].no), (yyvsp[0].no), NULL);

	if(strcmp((yyvsp[-1].no)->lexeme,"or")==0){
		(yyvsp[-2].no)->t=strdup((yyval.no)->t);
		//↓ esse a gente vai ter que colocar algo descente dps
		(yyvsp[-2].no)->f = strdup("novo_rot");

		(yyvsp[0].no)->t=strdup((yyval.no)->t);
		(yyvsp[0].no)->f=strdup((yyvsp[-2].no)->f);

		Tac* new_tac_lab = create_inst_tac("","","goto",(yyvsp[-2].no)->f);
		/*Tac* new_tac = create_inst_tac($$->lexeme,$1->lexeme,$2->lexeme,$3->lexeme);
		t_size_now = CHAR_SIZE;
		t_size+=t_size_now;*/
		
		append_inst_tac(&((yyvsp[-2].no)->code),new_tac_lab);
		cat_tac( &((yyvsp[-2].no)->code),&((yyvsp[0].no)->code) );
		cat_tac( &((yyval.no)->code),&((yyvsp[-2].no)->code) );
		//append_inst_tac(&($$->code),new_tac);
	}
	else{
		(yyvsp[-2].no)->f=strdup((yyval.no)->f);
		//↓ esse a gente vai ter que colocar algo descente dps
		(yyvsp[-2].no)->f = strdup("novo_rot");
		
		Tac* new_tac_lab = create_inst_tac("","","goto",(yyvsp[-2].no)->t);
		append_inst_tac(&((yyvsp[-2].no)->code),new_tac_lab);
		cat_tac( &((yyvsp[-2].no)->code),&((yyvsp[0].no)->code) );
		cat_tac( &((yyval.no)->code),&((yyvsp[-2].no)->code) );
	}

}
#line 2058 "y.tab.c"
    break;

  case 29:
#line 451 "nico.y"
               {
	Node* no_NOT = create_node((yylsp[-1]).first_line, idf_node, (yyvsp[-1].cadeia), NULL);
	(yyval.no) = create_node((yylsp[-1]).first_line, expr_node, NULL, no_NOT,(yyvsp[0].no), NULL);
	(yyvsp[0].no)->t=strdup((yyval.no)->f);
	(yyvsp[0].no)->f=strdup((yyval.no)->t);
	cat_tac( &((yyval.no)->code),&((yyvsp[0].no)->code) );
	/*cat_tac( &($$->code),&($2->code) );
	Tac* new_tac = create_inst_tac($$->lexeme,$2->lexeme,"not","");
	t_size_now = CHAR_SIZE;
	t_size+=t_size_now;
	append_inst_tac(&($$->code), new_tac);*/
}
#line 2075 "y.tab.c"
    break;

  case 30:
#line 463 "nico.y"
                            { Node *no_PAROPN = create_node((yylsp[-2]).first_line, abrepar_node,  (yyvsp[-2].cadeia), NULL);
	Node *no_PARCLOSE = create_node((yylsp[-2]).first_line, fechapar_node,  (yyvsp[0].cadeia), NULL);
	(yyval.no) = create_node((yylsp[-2]).first_line, expr_node, NULL, no_PAROPN, (yyvsp[-1].no), no_PARCLOSE, NULL);
	
	(yyval.no)->t= strdup((yyvsp[-1].no)->t);
	(yyval.no)->f= strdup((yyvsp[-1].no)->f);

	cat_tac( &((yyval.no)->code),&((yyvsp[-1].no)->code) );

}
#line 2090 "y.tab.c"
    break;

  case 31:
#line 473 "nico.y"
       {(yyval.no) = create_node((yylsp[0]).first_line, lvalue_node, NULL, NULL);

	Tac* tac_vazio = create_inst_tac("","","goto",(yyval.no)->t);
	append_inst_tac(&((yyval.no)->code),tac_vazio);
	/*Tac* tac_vazio = create_inst_tac($$->lexeme,"1","","");
	t_size_now = CHAR_SIZE;
	t_size+=t_size_now;
	append_inst_tac(&($$->code),tac_vazio);*/
}
#line 2104 "y.tab.c"
    break;

  case 32:
#line 482 "nico.y"
        {(yyval.no) = create_node((yylsp[0]).first_line, lvalue_node, rx(t_size), NULL);
	Tac* tac_vazio = create_inst_tac("","","goto",(yyval.no)->f);
	append_inst_tac(&((yyval.no)->code),tac_vazio);
	/*Tac* tac_vazio = create_inst_tac($$->lexeme,"0","","");
	t_size_now = CHAR_SIZE;
	t_size+=t_size_now;
	append_inst_tac(&($$->code),tac_vazio);*/
}
#line 2117 "y.tab.c"
    break;

  case 33:
#line 491 "nico.y"
            {
(yyval.no) = create_node((yylsp[0]).first_line, and_node, (yyvsp[0].cadeia), NULL);}
#line 2124 "y.tab.c"
    break;

  case 34:
#line 493 "nico.y"
     {
	(yyval.no) = create_node((yylsp[0]).first_line, or_node, (yyvsp[0].cadeia), NULL);}
#line 2131 "y.tab.c"
    break;

  case 35:
#line 496 "nico.y"
         {(yyval.no) = create_node((yylsp[0]).first_line, aux_node, NULL, (yyvsp[0].no), NULL);}
#line 2137 "y.tab.c"
    break;

  case 36:
#line 497 "nico.y"
                       {(yyval.no) = create_node((yylsp[-2]).first_line, aux_node, NULL, (yyvsp[-2].no), (yyvsp[-1].no), (yyvsp[0].no), NULL);
	Tac* tac_true = create_inst_tac((yyval.no)->t,(yyvsp[-2].no)->lexeme,(yyvsp[-1].no)->lexeme,(yyvsp[0].no)->lexeme);
	Tac* tac_false = create_inst_tac("","","goto",(yyval.no)->f);
	append_inst_tac(&((yyvsp[-1].no)->code),tac_true);
	append_inst_tac(&((yyvsp[-1].no)->code),tac_false);
	cat_tac( &((yyvsp[-2].no)->code),&((yyvsp[-1].no)->code) );
	cat_tac( &((yyval.no)->code),&((yyvsp[-2].no)->code) );

}
#line 2151 "y.tab.c"
    break;

  case 37:
#line 508 "nico.y"
                 {
	(yyval.no) = create_node((yylsp[0]).first_line, idf_node, (yyvsp[0].cadeia), NULL); 
	Tac* tac_vazio = create_inst_tac("","","","");
	entry_t* aux = lookup(symbol_table,(yyvsp[0].cadeia));
	t_size_now = aux->size;
	append_inst_tac(&((yyval.no)->code),tac_vazio);
	}
#line 2163 "y.tab.c"
    break;

  case 38:
#line 515 "nico.y"
          {
	(yyval.no) = create_node((yylsp[0]).first_line, lvalue_node, (yyvsp[0].cadeia), NULL);
	Tac* tac_vazio = create_inst_tac("","","","");
	t_size_now = INT_SIZE;

	append_inst_tac(&((yyval.no)->code),tac_vazio);	}
#line 2174 "y.tab.c"
    break;

  case 39:
#line 521 "nico.y"
        {
	(yyval.no) = create_node((yylsp[0]).first_line, lvalue_node, (yyvsp[0].cadeia), NULL);
	Tac* tac_vazio = create_inst_tac("","","","");
	t_size_now = FLOAT_SIZE;
	append_inst_tac(&((yyval.no)->code),tac_vazio);	}
#line 2184 "y.tab.c"
    break;

  case 40:
#line 528 "nico.y"
                  {
	(yyval.no) = create_node((yylsp[0]).first_line, maior_node, (yyvsp[0].cadeia), NULL);}
#line 2191 "y.tab.c"
    break;

  case 41:
#line 530 "nico.y"
        {
	(yyval.no) = create_node((yylsp[0]).first_line, menor_node, (yyvsp[0].cadeia),NULL);}
#line 2198 "y.tab.c"
    break;

  case 42:
#line 532 "nico.y"
     {
	(yyval.no) = create_node((yylsp[0]).first_line, igual_node, (yyvsp[0].cadeia), NULL);}
#line 2205 "y.tab.c"
    break;

  case 43:
#line 534 "nico.y"
     {
	(yyval.no) = create_node((yylsp[0]).first_line, diferente_node, (yyvsp[0].cadeia), NULL);}
#line 2212 "y.tab.c"
    break;

  case 44:
#line 536 "nico.y"
     {
	(yyval.no) = create_node((yylsp[0]).first_line, maiorigual_node, (yyvsp[0].cadeia), NULL);}
#line 2219 "y.tab.c"
    break;

  case 45:
#line 538 "nico.y"
     {
	(yyval.no) = create_node((yylsp[0]).first_line, menorigual_node, (yyvsp[0].cadeia), NULL);}
#line 2226 "y.tab.c"
    break;

  case 46:
#line 543 "nico.y"
            {(yyval.no) = create_node((yylsp[0]).first_line, lvalue_node, NULL, (yyvsp[0].no), NULL);
	(yyval.no)->lexeme= strdup((yyvsp[0].no)->lexeme);
	cat_tac(&((yyval.no)->code),&((yyvsp[0].no)->code));
}
#line 2235 "y.tab.c"
    break;

  case 47:
#line 547 "nico.y"
                       {
	Node *no_PLUS = create_node((yylsp[-2]).first_line, soma_node, (yyvsp[-1].cadeia), NULL);
	(yyval.no) = create_node((yylsp[-2]).first_line, soma_node, rx(t_size), (yyvsp[-2].no), no_PLUS, (yyvsp[0].no), NULL);
	t_size+=t_size_now;
	Tac* new_tac = create_inst_tac((yyval.no)->lexeme,(yyvsp[-2].no)->lexeme,(yyvsp[-1].cadeia),(yyvsp[0].no)->lexeme);

	printf("\n\n Tac dentro do calc %s := %s %s %s \n",(yyval.no)->lexeme,(yyvsp[-2].no)->lexeme,(yyvsp[-1].cadeia),(yyvsp[0].no)->lexeme);

 	cat_tac(&((yyval.no)->code), &((yyvsp[-2].no)->code));

 	cat_tac(&((yyval.no)->code), &((yyvsp[0].no)->code));

 	append_inst_tac(&((yyval.no)->code),new_tac); 
	/*char *t = malloc(sizeof(char)*12);
		sprintf(t, "lista%d.txt", file_num++);
		FILE* file = fopen(t, "w");
    	print_tac(file, $$->code);*/
	}
#line 2258 "y.tab.c"
    break;

  case 48:
#line 565 "nico.y"
                      {
	Node *no_MIN = create_node((yylsp[-2]).first_line, sub_node, (yyvsp[-1].cadeia), NULL);
	(yyval.no) = create_node((yylsp[-2]).first_line, sub_node, rx(t_size), (yyvsp[-2].no), no_MIN, (yyvsp[0].no), NULL);
	
	t_size+=t_size_now;
	Tac* new_tac = create_inst_tac((yyval.no)->lexeme,(yyvsp[-2].no)->lexeme,(yyvsp[-1].cadeia),(yyvsp[0].no)->lexeme);

	printf("\n\n Tac dentro do calc %s := %s %s %s \n",(yyval.no)->lexeme,(yyvsp[-2].no)->lexeme,(yyvsp[-1].cadeia),(yyvsp[0].no)->lexeme);

 	cat_tac(&((yyval.no)->code), &((yyvsp[-2].no)->code));

 	cat_tac(&((yyval.no)->code), &((yyvsp[0].no)->code));

 	append_inst_tac(&((yyval.no)->code),new_tac);
	}
#line 2278 "y.tab.c"
    break;

  case 49:
#line 580 "nico.y"
                      {
	Node *no_MULTI = create_node((yylsp[-2]).first_line, multi_node, (yyvsp[-1].cadeia), NULL);
	(yyval.no) = create_node((yylsp[-2]).first_line, multi_node, rx(t_size), (yyvsp[-2].no), no_MULTI, (yyvsp[0].no), NULL);

	t_size+=t_size_now;
	Tac* new_tac = create_inst_tac((yyval.no)->lexeme,(yyvsp[-2].no)->lexeme,(yyvsp[-1].cadeia),(yyvsp[0].no)->lexeme);

	printf("\n\n Tac dentro do calc %s := %s %s %s \n",(yyval.no)->lexeme,(yyvsp[-2].no)->lexeme,(yyvsp[-1].cadeia),(yyvsp[0].no)->lexeme);

 	cat_tac(&((yyval.no)->code), &((yyvsp[-2].no)->code));

 	cat_tac(&((yyval.no)->code), &((yyvsp[0].no)->code));

 	append_inst_tac(&((yyval.no)->code),new_tac);
	}
#line 2298 "y.tab.c"
    break;

  case 50:
#line 595 "nico.y"
                      {
	Node *no_BAR = create_node((yylsp[-2]).first_line, div_node, (yyvsp[-1].cadeia), NULL);
	(yyval.no) = create_node((yylsp[-2]).first_line, div_node, rx(t_size), (yyvsp[-2].no), no_BAR, (yyvsp[0].no), NULL);

	t_size+=t_size_now;
	Tac* new_tac = create_inst_tac((yyval.no)->lexeme,(yyvsp[-2].no)->lexeme,(yyvsp[-1].cadeia),(yyvsp[0].no)->lexeme);

	printf("\n\n Tac dentro do calc %s := %s %s %s \n",(yyval.no)->lexeme,(yyvsp[-2].no)->lexeme,(yyvsp[-1].cadeia),(yyvsp[0].no)->lexeme);

 	cat_tac(&((yyval.no)->code), &((yyvsp[-2].no)->code));

 	cat_tac(&((yyval.no)->code), &((yyvsp[0].no)->code));

 	append_inst_tac(&((yyval.no)->code),new_tac);
	}
#line 2318 "y.tab.c"
    break;

  case 51:
#line 610 "nico.y"
                             {
	Node *no_PAROPN = create_node((yylsp[-2]).first_line, abrepar_node,  (yyvsp[-2].cadeia), NULL);
	Node *no_PARCLOSE = create_node((yylsp[-2]).first_line, fechapar_node,  (yyvsp[0].cadeia), NULL);
	(yyval.no) = create_node((yylsp[-2]).first_line, calc_node, NULL, no_PAROPN, (yyvsp[-1].no), no_PARCLOSE, NULL);
	(yyval.no)->lexeme= strdup((yyvsp[-1].no)->lexeme);
	cat_tac(&((yyval.no)->code),&((yyvsp[-1].no)->code));
	}
#line 2330 "y.tab.c"
    break;


#line 2334 "y.tab.c"

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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
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
#line 621 "nico.y"

 /* A partir daqui, insere-se qlqer codigo C necessario.
  */
