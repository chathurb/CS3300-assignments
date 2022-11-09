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
#line 1 "A1.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex();
void yyerror(char *);
char* yytext;

char* concat(char* a, char* b)
{
    char* temp = (char*)malloc(strlen(a) + strlen(b) + 1);
    strcpy(temp,a);
    strcat(temp,b);
    return temp;
}

char* findAndReplace(char *str, char *pattern, char *replacement) {
    if (!str)
        return NULL;
    if (!pattern)
        pattern = "";
    int r = strlen(pattern);
    if (!replacement)
        replacement = "";
    int w = strlen(replacement);

    char *result;
    char *tmp;

    int count;
    char *ins = str;    

    for (count = 0; tmp = strstr(ins, pattern); ++count)
        ins = tmp + r;

    tmp = result = malloc(strlen(str) + (w - r) * count + 1);

    if (!result)
        return NULL;

    for(int i=0; i<count; i++) {
        ins = strstr(str, pattern);
        int f = ins - str;
        tmp = strncpy(tmp, str, f) + f;
        tmp = strcpy(tmp, replacement) + w;
        str += f + r;
    }
    strcpy(tmp, str);
    return result;
}

char** strSplit(char* str, const char d)
{
    int count = 0;
    char* tmp = str;
    char* last = 0;
    
    while (*tmp)
    {
        if (d == *tmp)
        {
            count++;
            last = tmp;
        }
        tmp++;
    }

    if(last < (str + strlen(str) - 1))
        count++;

    char** res = malloc(sizeof(char*) * (count + 1));

    char dstr[2];
    dstr[0] = d;
    dstr[1] = 0;

    if (res)
    {
        int i  = 0;
        char* token = strtok(str, dstr);

        while (token)
        {
            *(res + i) = strdup(token);
            token = strtok(0, dstr);
            i++;
        }
        *(res + i) = 0;
    }

    return res;
}

int noOfmacros = 0;
char* macrosArr[256];
char* macroPars[256];
char* macroBody[256];

void addMacro(char* name,char* body,char* params){
	macrosArr[noOfmacros] = (char*)malloc(strlen(name)+1);
	strcpy(macrosArr[noOfmacros],name);
    macroPars[noOfmacros] = (char*)malloc(strlen(params)+1);
	strcpy(macroPars[noOfmacros],params);
	macroBody[noOfmacros] = (char*)malloc(strlen(body)+1);
	strcpy(macroBody[noOfmacros],body);	
    noOfmacros++;
	return;
}

char* findMacroBody(char* m){
	for(int i=0;i<noOfmacros;i++)
    {
        if(strcmp(macrosArr[i],m))
            continue;
        else
            return macroBody[i];
    }
	char* e = (char*)malloc(2);
	strcpy(e,"");
	return e;
}

char* findMacroPars(char* m){
	for(int i=0;i<noOfmacros;i++)
    {
        if(strcmp(macrosArr[i],m))
            continue;
        else
            return macroPars[i];
    }
	char* e = (char*)malloc(2);
	strcpy(e,"");
	return e;
}


#line 208 "A1.tab.c"

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
    IDENTIFIER = 258,
    INTEGER = 259,
    DIV = 260,
    ASTERISK = 261,
    PLUS = 262,
    MINUS = 263,
    SEMCL = 264,
    COMMA = 265,
    NEG = 266,
    AND = 267,
    OR = 268,
    NEQ = 269,
    LEQ = 270,
    DOT = 271,
    OPBRC = 272,
    CLBRC = 273,
    OPPAR = 274,
    CLPAR = 275,
    OPBRK = 276,
    CLBRK = 277,
    KW_EQ = 278,
    KW_CLASS = 279,
    KW_PUBLIC = 280,
    KW_STATIC = 281,
    KW_VOID = 282,
    KW_MAIN = 283,
    KW_STRING = 284,
    PRINTSTM = 285,
    KW_EXTENDS = 286,
    KW_RETURN = 287,
    KW_INT = 288,
    KW_BOOLEAN = 289,
    KW_IF = 290,
    KW_ELSE = 291,
    KW_WHILE = 292,
    KW_THIS = 293,
    KW_NEW = 294,
    KW_LENGTH = 295,
    HDEF = 296,
    DEFS = 297,
    DEFS0 = 298,
    DEFS1 = 299,
    DEFS2 = 300,
    DEFE = 301,
    DEFE0 = 302,
    DEFE1 = 303,
    DEFE2 = 304,
    TRUE = 305,
    FALSE = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 139 "A1.y"

	char* str;

#line 313 "A1.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





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
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   377

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  268

#define YYUNDEFTOK  2
#define YYMAXUTOK   306


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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   159,   159,   160,   161,   162,   165,   169,   170,   171,
     172,   173,   174,   175,   176,   179,   180,   183,   184,   187,
     189,   191,   193,   195,   197,   201,   202,   205,   206,   209,
     210,   211,   212,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   225,   227,   250,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   266,   268,   291,
     292,   294,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   330,   331,   334,   336,   338,   339,   340,   341,   345,
     347,   348,   351,   352,   355,   358,   361,   362,   366,   367,
     370,   371
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "INTEGER", "DIV",
  "ASTERISK", "PLUS", "MINUS", "SEMCL", "COMMA", "NEG", "AND", "OR", "NEQ",
  "LEQ", "DOT", "OPBRC", "CLBRC", "OPPAR", "CLPAR", "OPBRK", "CLBRK",
  "KW_EQ", "KW_CLASS", "KW_PUBLIC", "KW_STATIC", "KW_VOID", "KW_MAIN",
  "KW_STRING", "PRINTSTM", "KW_EXTENDS", "KW_RETURN", "KW_INT",
  "KW_BOOLEAN", "KW_IF", "KW_ELSE", "KW_WHILE", "KW_THIS", "KW_NEW",
  "KW_LENGTH", "HDEF", "DEFS", "DEFS0", "DEFS1", "DEFS2", "DEFE", "DEFE0",
  "DEFE1", "DEFE2", "TRUE", "FALSE", "$accept", "goal", "mainClass",
  "typeDeclaration", "typeDecList", "methodDecList", "methodDeclaration",
  "statementList", "methodArgList", "type", "statement", "expression",
  "primaryExpression", "macroDef", "macroDefStmt", "macroDefExpr",
  "macroArgList", "identifier", "integer", "macroExprList", "macroDefList",
  "typeDefList", YY_NULLPTR
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
     305,   306
};
# endif

#define YYPACT_NINF (-163)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     119,    20,    20,    20,    20,    20,    20,    20,    35,    17,
     103,  -163,  -163,    42,  -163,    58,    50,    59,    64,    67,
      70,    80,  -163,    20,    17,  -163,  -163,    17,    56,    20,
      81,    20,    20,    82,    20,     7,  -163,  -163,    79,   105,
     101,    99,   105,   111,   116,    62,    20,   117,    20,   133,
      76,   138,   134,    53,   140,  -163,    29,   139,  -163,     9,
     146,   143,    20,  -163,   155,   150,   105,   157,   210,  -163,
     165,   170,   171,   173,    20,   298,    93,   232,   174,  -163,
      53,    53,  -163,    26,  -163,  -163,   172,   331,   175,  -163,
      53,    20,   176,  -163,   178,  -163,  -163,   188,   252,   180,
    -163,   257,  -163,   182,    53,    53,    53,  -163,   192,  -163,
     137,    53,    53,  -163,   184,    53,  -163,   183,   187,   196,
    -163,    53,    53,    53,    53,    53,    53,    53,    53,    11,
      53,   166,   199,   202,  -163,  -163,    29,  -163,    52,   206,
     197,  -163,   207,  -163,   211,   213,   214,  -163,   227,     5,
     215,   230,  -163,   228,  -163,    53,   231,  -163,  -163,  -163,
    -163,  -163,  -163,  -163,  -163,  -163,  -163,   238,   236,  -163,
       6,  -163,    51,  -163,  -163,   234,  -163,   240,  -163,   250,
     298,   298,  -163,    53,   254,   251,   253,  -163,  -163,   256,
    -163,   203,  -163,  -163,   263,   267,    20,  -163,   266,  -163,
     260,  -163,   294,  -163,   296,    53,  -163,  -163,    32,  -163,
     265,    48,    20,   298,  -163,  -163,   303,  -163,   287,    53,
     282,    29,   300,   302,   304,  -163,  -163,  -163,   316,    53,
      20,   276,   309,   310,   311,   321,   324,    53,   308,   286,
     312,  -163,   323,  -163,   339,    53,    53,   317,   332,  -163,
     335,   341,   353,    53,    53,  -163,   346,   347,   357,   348,
    -163,  -163,   349,   360,  -163,   352,   354,  -163
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
      89,    72,    71,     0,    84,     0,     0,     0,     0,     0,
       0,     0,     1,     0,    91,     4,    88,     3,     0,     0,
       0,     0,     0,     0,     0,     0,    90,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     0,    29,    30,     0,
       0,    17,     0,    32,     0,     0,    82,     0,     0,    75,
       0,     0,     0,     0,     0,    25,    32,     0,     0,    85,
       0,     0,    66,     0,    63,    64,     0,    55,    65,    62,
       0,     0,     0,     9,     0,     8,    18,     0,     0,     0,
      83,     0,    33,     0,     0,     0,     0,    76,     0,    26,
       0,     0,     0,    77,     0,     0,    69,     0,     0,     0,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    31,    10,    15,    11,     0,     0,
       0,    73,     0,    34,     0,     0,     0,    44,     0,     0,
       0,     0,    78,     0,    70,     0,     0,    48,    65,    47,
      45,    46,    49,    50,    51,    52,    54,     0,     0,    59,
       0,    81,     0,    16,    13,     0,    12,     0,    74,     0,
       0,     0,    41,     0,     0,     0,     0,    36,    79,     0,
      68,     0,    53,    60,     0,     0,     0,    14,     0,    35,
      38,    40,    86,    42,     0,     0,    67,    56,     0,    61,
       0,     0,     0,     0,    87,    43,     0,    57,     0,     0,
       0,     0,     0,     0,     0,    39,    37,    58,     0,     0,
       0,     0,     0,     0,     0,     0,    27,     0,     0,     0,
       0,    19,     0,    28,     0,     0,     0,     0,     0,    20,
       0,     0,     0,     0,     0,    21,     0,     0,     0,     0,
      22,    23,     0,     0,    24,     0,     0,     6
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -163,  -163,   358,  -163,   -86,   -50,  -163,   -58,   141,   -38,
    -160,    27,   233,  -163,  -163,  -163,   -29,    -1,  -163,  -162,
     363,    12
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,     9,    24,    59,    60,    61,    73,   223,    74,
      75,    86,    87,    10,    11,    12,    49,    88,    89,   185,
      13,    25
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      15,    16,    17,    18,    19,    20,    21,    62,   194,    94,
     103,    96,   138,    52,    14,   183,   183,   109,    91,   114,
     200,   201,    35,    14,    45,   184,   193,    93,    39,    14,
      41,    42,    14,    44,    56,    22,    36,   100,    46,    37,
     214,    23,   183,   142,    63,    64,   218,    66,   139,    76,
     173,   166,   217,   225,    14,    63,    14,    79,   221,   118,
      62,    97,    57,    58,    80,    14,     1,    76,   222,    29,
     174,   195,    81,   108,    76,    28,    76,    56,    30,    14,
      55,    38,   119,    31,    57,    58,    32,    56,   175,    33,
     133,    82,    83,    68,    69,    57,    58,    63,    62,    34,
      76,    40,    43,    84,    85,    47,    70,   116,   117,    57,
      58,    71,   110,    72,   111,    48,   112,   132,    50,    51,
     158,   158,   158,   158,   158,   158,   158,   158,   167,   158,
      53,   144,   145,   146,   196,    63,    54,   149,   150,   151,
      14,    79,   153,     1,    65,     2,     3,     4,    80,     5,
       6,     7,   220,    67,    78,    77,    81,   148,   170,    90,
      92,     2,     3,     4,    95,     5,     6,     7,    56,    14,
      79,    63,    98,   238,   101,    82,    83,    80,    99,    76,
      76,   247,   189,   230,   104,    81,   169,    84,    85,   105,
     106,   107,   120,   115,   131,   211,   135,   136,   134,   140,
     143,   147,   152,   154,    82,    83,    14,    79,   155,    76,
     202,   224,    76,    14,    80,   156,    84,    85,   208,   171,
      63,   172,    81,   207,   176,   178,   177,    68,   102,   236,
      76,   179,   216,   180,   181,    14,   182,   186,    76,   187,
      70,    82,    83,    57,    58,    71,   228,    72,   188,    68,
     113,   190,   197,    84,    85,    14,   235,   191,   192,   199,
      14,   198,    70,   203,   244,    57,    58,    71,    14,    72,
     137,   204,   251,   252,    68,   141,   205,    56,   206,    14,
     258,   259,    68,   209,   210,    57,    58,    70,   212,    14,
      57,    58,    71,    68,    72,    70,   213,   219,    57,    58,
      71,    14,    72,    68,   183,   215,    70,   227,   237,    57,
      58,    71,   226,    72,   229,    68,    70,   231,   246,    57,
      58,    71,   232,    72,   233,   234,   239,   240,    70,   241,
     242,    57,    58,    71,   221,    72,   121,   122,   123,   124,
     245,   249,   248,   125,   126,   127,   128,   129,   250,   253,
     256,   254,   130,   255,   157,   159,   160,   161,   162,   163,
     164,   165,   257,   168,   260,   261,   262,   264,   263,   265,
     266,    27,   267,    26,     0,     0,     0,   243
};

static const yytype_int16 yycheck[] =
{
       1,     2,     3,     4,     5,     6,     7,    45,   170,    59,
      68,    61,    98,    42,     3,    10,    10,    75,    56,    77,
     180,   181,    23,     3,    17,    20,    20,    18,    29,     3,
      31,    32,     3,    34,    25,     0,    24,    66,    31,    27,
     202,    24,    10,   101,    45,    46,   208,    48,    98,    50,
     136,    40,    20,   213,     3,    56,     3,     4,    10,    33,
      98,    62,    33,    34,    11,     3,    24,    68,    20,    19,
      18,    20,    19,    74,    75,    17,    77,    25,    19,     3,
      18,    25,    83,    19,    33,    34,    19,    25,   138,    19,
      91,    38,    39,    17,    18,    33,    34,    98,   136,    19,
     101,    20,    20,    50,    51,    26,    30,    80,    81,    33,
      34,    35,    19,    37,    21,    10,    23,    90,    17,    20,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      19,   104,   105,   106,   172,   136,    20,   110,   111,   112,
       3,     4,   115,    24,    27,    42,    43,    44,    11,    46,
      47,    48,   210,    20,    20,    17,    19,    20,   131,    19,
      21,    42,    43,    44,    18,    46,    47,    48,    25,     3,
       4,   172,    17,   231,    17,    38,    39,    11,    28,   180,
     181,   239,   155,   221,    19,    19,    20,    50,    51,    19,
      19,    18,    20,    19,    19,   196,    18,     9,    22,    19,
      18,     9,    18,    20,    38,    39,     3,     4,    21,   210,
     183,   212,   213,     3,    11,    19,    50,    51,   191,    20,
     221,    19,    19,    20,    18,    18,    29,    17,    18,   230,
     231,    20,   205,    20,    20,     3,     9,    22,   239,     9,
      30,    38,    39,    33,    34,    35,   219,    37,    20,    17,
      18,    20,    18,    50,    51,     3,   229,    19,    22,     9,
       3,    21,    30,     9,   237,    33,    34,    35,     3,    37,
      18,    20,   245,   246,    17,    18,    23,    25,    22,     3,
     253,   254,    17,    20,    17,    33,    34,    30,    22,     3,
      33,    34,    35,    17,    37,    30,    36,    32,    33,    34,
      35,     3,    37,    17,    10,     9,    30,    20,    32,    33,
      34,    35,     9,    37,    32,    17,    30,    17,    32,    33,
      34,    35,    20,    37,    20,     9,    17,    17,    30,    18,
       9,    33,    34,    35,    10,    37,     5,     6,     7,     8,
      32,    18,    30,    12,    13,    14,    15,    16,     9,    32,
       9,    19,    21,    18,   121,   122,   123,   124,   125,   126,
     127,   128,     9,   130,    18,    18,     9,    18,    20,     9,
      18,    13,    18,    10,    -1,    -1,    -1,   236
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    24,    42,    43,    44,    46,    47,    48,    53,    54,
      65,    66,    67,    72,     3,    69,    69,    69,    69,    69,
      69,    69,     0,    24,    55,    73,    72,    54,    17,    19,
      19,    19,    19,    19,    19,    69,    73,    73,    25,    69,
      20,    69,    69,    20,    69,    17,    31,    26,    10,    68,
      17,    20,    68,    19,    20,    18,    25,    33,    34,    56,
      57,    58,    61,    69,    69,    27,    69,    20,    17,    18,
      30,    35,    37,    59,    61,    62,    69,    17,    20,     4,
      11,    19,    38,    39,    50,    51,    63,    64,    69,    70,
      19,    61,    21,    18,    57,    18,    57,    69,    17,    28,
      68,    17,    18,    59,    19,    19,    19,    18,    69,    59,
      19,    21,    23,    18,    59,    19,    63,    63,    33,    69,
      20,     5,     6,     7,     8,    12,    13,    14,    15,    16,
      21,    19,    63,    69,    22,    18,     9,    18,    56,    57,
      19,    18,    59,    18,    63,    63,    63,     9,    20,    63,
      63,    63,    18,    63,    20,    21,    19,    64,    69,    64,
      64,    64,    64,    64,    64,    64,    40,    69,    64,    20,
      63,    20,    19,    56,    18,    57,    18,    29,    18,    20,
      20,    20,     9,    10,    20,    71,    22,     9,    20,    63,
      20,    19,    22,    20,    71,    20,    61,    18,    21,     9,
      62,    62,    63,     9,    20,    23,    22,    20,    63,    20,
      17,    69,    22,    36,    71,     9,    63,    20,    71,    32,
      59,    10,    20,    60,    69,    62,     9,    20,    63,    32,
      61,    17,    20,    20,     9,    63,    69,    32,    59,    17,
      17,    18,     9,    60,    63,    32,    32,    59,    30,    18,
       9,    63,    63,    32,    19,    18,     9,     9,    63,    63,
      18,    18,     9,    20,    18,     9,    18,    18
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    53,    53,    53,    54,    55,    55,    55,
      55,    55,    55,    55,    55,    56,    56,    57,    57,    58,
      58,    58,    58,    58,    58,    59,    59,    60,    60,    61,
      61,    61,    61,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    65,    65,    66,    66,    66,    66,    66,    66,    67,
      67,    67,    68,    68,    69,    70,    71,    71,    72,    72,
      73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     3,    21,     4,     5,     5,
       6,     6,     7,     7,     8,     3,     4,     1,     2,    10,
      11,    12,    13,    13,    14,     1,     2,     3,     4,     1,
       1,     3,     1,     2,     3,     5,     4,     7,     5,     7,
       5,     4,     5,     6,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     3,     1,     5,     6,     7,     3,
       4,     5,     1,     1,     1,     1,     1,     5,     4,     2,
       3,     1,     1,     8,     9,     6,     7,     7,     8,     9,
       7,     8,     2,     3,     1,     1,     2,     3,     2,     1,
       2,     1
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
#line 159 "A1.y"
                {sprintf((yyval.str),"%s\n",(yyvsp[0].str)); printf("%s\n",(yyval.str));}
#line 1679 "A1.tab.c"
    break;

  case 3:
#line 160 "A1.y"
                                       {sprintf((yyval.str),"%s\n",(yyvsp[0].str)); printf("%s\n",(yyval.str));}
#line 1685 "A1.tab.c"
    break;

  case 4:
#line 161 "A1.y"
                                      {sprintf((yyval.str),"%s %s\n",(yyvsp[-1].str),(yyvsp[0].str)); printf("%s\n",(yyval.str));}
#line 1691 "A1.tab.c"
    break;

  case 5:
#line 162 "A1.y"
                                                        {sprintf((yyval.str),"%s %s\n",(yyvsp[-1].str),(yyvsp[0].str)); printf("%s\n",(yyval.str));}
#line 1697 "A1.tab.c"
    break;

  case 6:
#line 166 "A1.y"
            {sprintf((yyval.str),"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",(yyvsp[-20].str),(yyvsp[-19].str),(yyvsp[-18].str),(yyvsp[-17].str),(yyvsp[-16].str),(yyvsp[-15].str),(yyvsp[-14].str),(yyvsp[-13].str),(yyvsp[-12].str),(yyvsp[-11].str),(yyvsp[-10].str),(yyvsp[-9].str),(yyvsp[-8].str),(yyvsp[-7].str),(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1703 "A1.tab.c"
    break;

  case 7:
#line 169 "A1.y"
                                                 {sprintf((yyval.str),"%s %s %s %s",(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1709 "A1.tab.c"
    break;

  case 8:
#line 170 "A1.y"
                                                                       {sprintf((yyval.str),"%s %s %s %s %s",(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1715 "A1.tab.c"
    break;

  case 9:
#line 171 "A1.y"
                                                                      {sprintf((yyval.str),"%s %s %s %s %s",(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1721 "A1.tab.c"
    break;

  case 10:
#line 172 "A1.y"
                                                                                        {sprintf((yyval.str),"%s %s %s %s %s %s",(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1727 "A1.tab.c"
    break;

  case 11:
#line 173 "A1.y"
                                                                                {sprintf((yyval.str),"%s %s %s %s %s %s",(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1733 "A1.tab.c"
    break;

  case 12:
#line 174 "A1.y"
                                                                                                {sprintf((yyval.str),"%s %s %s %s %s %s %s",(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1739 "A1.tab.c"
    break;

  case 13:
#line 175 "A1.y"
                                                                                                {sprintf((yyval.str),"%s %s %s %s %s %s %s",(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1745 "A1.tab.c"
    break;

  case 14:
#line 176 "A1.y"
                                                                                                        {sprintf((yyval.str),"%s %s %s %s %s %s %s %s",(yyvsp[-7].str),(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1751 "A1.tab.c"
    break;

  case 15:
#line 179 "A1.y"
                                        {sprintf((yyval.str),"%s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1757 "A1.tab.c"
    break;

  case 16:
#line 180 "A1.y"
                                                        {sprintf((yyval.str),"%s %s %s %s",(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1763 "A1.tab.c"
    break;

  case 17:
#line 183 "A1.y"
                                        {sprintf((yyval.str),"%s",(yyvsp[0].str));}
#line 1769 "A1.tab.c"
    break;

  case 18:
#line 184 "A1.y"
                                                {sprintf((yyval.str),"%s %s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 1775 "A1.tab.c"
    break;

  case 19:
#line 188 "A1.y"
                    {sprintf((yyval.str),"%s %s %s %s %s %s %s %s %s %s",(yyvsp[-9].str),(yyvsp[-8].str),(yyvsp[-7].str),(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1781 "A1.tab.c"
    break;

  case 20:
#line 190 "A1.y"
        {sprintf((yyval.str),"%s %s %s %s %s %s %s %s %s %s %s",(yyvsp[-10].str),(yyvsp[-9].str),(yyvsp[-8].str),(yyvsp[-7].str),(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1787 "A1.tab.c"
    break;

  case 21:
#line 192 "A1.y"
        {sprintf((yyval.str),"%s %s %s %s %s %s %s %s %s %s %s %s",(yyvsp[-11].str),(yyvsp[-10].str),(yyvsp[-9].str),(yyvsp[-8].str),(yyvsp[-7].str),(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1793 "A1.tab.c"
    break;

  case 22:
#line 194 "A1.y"
        {sprintf((yyval.str),"%s %s %s %s %s %s %s %s %s %s %s %s %s",(yyvsp[-12].str),(yyvsp[-11].str),(yyvsp[-10].str),(yyvsp[-9].str),(yyvsp[-8].str),(yyvsp[-7].str),(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1799 "A1.tab.c"
    break;

  case 23:
#line 196 "A1.y"
        {sprintf((yyval.str),"%s %s %s %s %s %s %s %s %s %s %s %s %s",(yyvsp[-12].str),(yyvsp[-11].str),(yyvsp[-10].str),(yyvsp[-9].str),(yyvsp[-8].str),(yyvsp[-7].str),(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1805 "A1.tab.c"
    break;

  case 24:
#line 198 "A1.y"
        {sprintf((yyval.str),"%s %s %s %s %s %s %s %s %s %s %s %s %s %s",(yyvsp[-13].str),(yyvsp[-12].str),(yyvsp[-11].str),(yyvsp[-10].str),(yyvsp[-9].str),(yyvsp[-8].str),(yyvsp[-7].str),(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1811 "A1.tab.c"
    break;

  case 25:
#line 201 "A1.y"
                                {sprintf((yyval.str),"%s",(yyvsp[0].str));}
#line 1817 "A1.tab.c"
    break;

  case 26:
#line 202 "A1.y"
                                        {sprintf((yyval.str),"%s %s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 1823 "A1.tab.c"
    break;

  case 27:
#line 205 "A1.y"
                                                {sprintf((yyval.str),"%s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1829 "A1.tab.c"
    break;

  case 28:
#line 206 "A1.y"
                                                        {sprintf((yyval.str),"%s %s %s %s",(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1835 "A1.tab.c"
    break;

  case 29:
#line 209 "A1.y"
               {sprintf((yyval.str),"%s",(yyvsp[0].str));}
#line 1841 "A1.tab.c"
    break;

  case 30:
#line 210 "A1.y"
                                {sprintf((yyval.str),"%s",(yyvsp[0].str));}
#line 1847 "A1.tab.c"
    break;

  case 31:
#line 211 "A1.y"
                                        {sprintf((yyval.str),"%s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1853 "A1.tab.c"
    break;

  case 32:
#line 212 "A1.y"
                                {sprintf((yyval.str),"%s",(yyvsp[0].str));}
#line 1859 "A1.tab.c"
    break;

  case 33:
#line 215 "A1.y"
                        {sprintf((yyval.str),"%s %s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 1865 "A1.tab.c"
    break;

  case 34:
#line 216 "A1.y"
                                                {sprintf((yyval.str),"%s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1871 "A1.tab.c"
    break;

  case 35:
#line 217 "A1.y"
                                                        {sprintf((yyval.str),"%s %s %s %s %s",(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1877 "A1.tab.c"
    break;

  case 36:
#line 218 "A1.y"
                                                        {sprintf((yyval.str),"%s %s %s %s",(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1883 "A1.tab.c"
    break;

  case 37:
#line 219 "A1.y"
                                                                                {sprintf((yyval.str),"%s %s %s %s %s %s %s",(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1889 "A1.tab.c"
    break;

  case 38:
#line 220 "A1.y"
                                                        {sprintf((yyval.str),"%s %s %s %s %s",(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1895 "A1.tab.c"
    break;

  case 39:
#line 221 "A1.y"
                                                                                {sprintf((yyval.str),"%s %s %s %s %s %s %s",(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1901 "A1.tab.c"
    break;

  case 40:
#line 222 "A1.y"
                                                                {sprintf((yyval.str),"%s %s %s %s %s",(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1907 "A1.tab.c"
    break;

  case 41:
#line 224 "A1.y"
    {if(strcmp(findMacroBody((yyvsp[-3].str)),"")!=0){sprintf((yyval.str),"%s",findMacroBody((yyvsp[-3].str)));} else{sprintf((yyval.str),"%s %s %s %s",(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}}
#line 1913 "A1.tab.c"
    break;

  case 42:
#line 226 "A1.y"
    {if(strcmp(findMacroBody((yyvsp[-4].str)),"")!=0){sprintf((yyval.str),"%s",findAndReplace(findMacroBody((yyvsp[-4].str)),findMacroPars((yyvsp[-4].str)),(yyvsp[-2].str)));}else{sprintf((yyval.str),"%s %s %s %s %s",(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}}
#line 1919 "A1.tab.c"
    break;

  case 43:
#line 227 "A1.y"
                                                                        {
		char* stmt = (char*)malloc(1024);
		strcpy(stmt,findMacroBody((yyvsp[-5].str)));
        if(strcmp(stmt,"")!=0){
			char** tmptks = strSplit(concat((yyvsp[-3].str), (yyvsp[-2].str)),',');
			char** partks = strSplit(findMacroPars((yyvsp[-5].str)),',');
			
			if (partks)
			{
				int i;
				for (i = 0; *(partks + i); i++)
				{
				    strcpy(stmt,findAndReplace(stmt,*(partks + i),*(tmptks + i)));
				    free(*(partks + i));
				    free(*(tmptks + i));
				}
			}
            free(partks);
			free(tmptks);
			sprintf((yyval.str),"%s",stmt);
            free(stmt);
		}
		else{sprintf((yyval.str),"%s %s %s %s %s %s",(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}}
#line 1947 "A1.tab.c"
    break;

  case 44:
#line 250 "A1.y"
                                        {sprintf((yyval.str),"%s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1953 "A1.tab.c"
    break;

  case 45:
#line 253 "A1.y"
                                                        {sprintf((yyval.str),"%s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1959 "A1.tab.c"
    break;

  case 46:
#line 254 "A1.y"
                                                                {sprintf((yyval.str),"%s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1965 "A1.tab.c"
    break;

  case 47:
#line 255 "A1.y"
                                                                        {sprintf((yyval.str),"%s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1971 "A1.tab.c"
    break;

  case 48:
#line 256 "A1.y"
                                                                {sprintf((yyval.str),"%s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1977 "A1.tab.c"
    break;

  case 49:
#line 257 "A1.y"
                                                        {sprintf((yyval.str),"%s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1983 "A1.tab.c"
    break;

  case 50:
#line 258 "A1.y"
                                                        {sprintf((yyval.str),"%s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1989 "A1.tab.c"
    break;

  case 51:
#line 259 "A1.y"
                                                        {sprintf((yyval.str),"%s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 1995 "A1.tab.c"
    break;

  case 52:
#line 260 "A1.y"
                                                        {sprintf((yyval.str),"%s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 2001 "A1.tab.c"
    break;

  case 53:
#line 261 "A1.y"
                                                                {sprintf((yyval.str),"%s %s %s %s",(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 2007 "A1.tab.c"
    break;

  case 54:
#line 262 "A1.y"
                                                        {sprintf((yyval.str),"%s %s %s",(yyvsp[-2].str),(yyvsp[-1].str), (yyvsp[0].str));}
#line 2013 "A1.tab.c"
    break;

  case 55:
#line 263 "A1.y"
                                                {sprintf((yyval.str),"%s",(yyvsp[0].str));}
#line 2019 "A1.tab.c"
    break;

  case 56:
#line 265 "A1.y"
    {if(strcmp(findMacroBody((yyvsp[-2].str)),"")!=0){sprintf((yyval.str),"%s %s %s %s %s",(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-1].str),findMacroBody((yyvsp[-2].str)),(yyvsp[0].str));}else{sprintf((yyval.str),"%s %s %s %s %s",(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}}
#line 2025 "A1.tab.c"
    break;

  case 57:
#line 267 "A1.y"
    {if(strcmp(findMacroBody((yyvsp[-3].str)),"")!=0){sprintf((yyval.str),"%s %s %s %s %s",(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-2].str),findAndReplace(findMacroBody((yyvsp[-3].str)),findMacroPars((yyvsp[-3].str)),(yyvsp[-1].str)),(yyvsp[0].str));}else{sprintf((yyval.str),"%s %s %s %s %s %s",(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}}
#line 2031 "A1.tab.c"
    break;

  case 58:
#line 268 "A1.y"
                                                                                          {
		char* stmt = (char*)malloc(1024);
		strcpy(stmt,findMacroBody((yyvsp[-6].str)));
        if(strcmp(stmt,"")!=0){
			char** tmptks = strSplit(concat((yyvsp[-2].str), (yyvsp[-1].str)),',');
			char** partks = strSplit(findMacroPars((yyvsp[-6].str)),',');
			
			if (partks)
			{
				int i;
				for (i = 0; *(partks + i); i++)
				{
				    strcpy(stmt,findAndReplace(stmt,*(partks + i),*(tmptks + i)));
				    free(*(partks + i));
				    free(*(tmptks + i));
				}
			}
            free(partks);
			free(tmptks);
			sprintf((yyval.str),"%s %s %s %s %s",(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-3].str),stmt,(yyvsp[0].str));
            free(stmt);
		}
		else{sprintf((yyval.str),"%s %s %s %s %s %s %s",(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}}
#line 2059 "A1.tab.c"
    break;

  case 59:
#line 291 "A1.y"
                                        {if(strcmp(findMacroBody((yyvsp[-2].str)),"")!=0){sprintf((yyval.str),"%s %s %s",(yyvsp[-1].str),findMacroBody((yyvsp[-2].str)),(yyvsp[0].str));}else{sprintf((yyval.str),"%s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}}
#line 2065 "A1.tab.c"
    break;

  case 60:
#line 293 "A1.y"
    {if(strcmp(findMacroBody((yyvsp[-3].str)),"")!=0){sprintf((yyval.str),"%s %s %s",(yyvsp[-2].str),findAndReplace(findMacroBody((yyvsp[-3].str)),findMacroPars((yyvsp[-3].str)),(yyvsp[-1].str)),(yyvsp[0].str));}else{sprintf((yyval.str),"%s %s %s %s",(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}}
#line 2071 "A1.tab.c"
    break;

  case 61:
#line 294 "A1.y"
                                                                 {
		char* stmt = (char*)malloc(1024);
		strcpy(stmt,findMacroBody((yyvsp[-4].str)));
        if(strcmp(stmt,"")!=0){
			char** tmptks = strSplit(concat((yyvsp[-2].str), (yyvsp[-1].str)),',');
			char** partks = strSplit(findMacroPars((yyvsp[-4].str)),',');
			
			if (partks)
			{
				int i;
				for (i = 0; *(partks + i); i++)
				{
				    strcpy(stmt,findAndReplace(stmt,*(partks + i),*(tmptks + i)));
				    free(*(partks + i));
				    free(*(tmptks + i));
				}
			}
            free(partks);
            free(tmptks);
			sprintf((yyval.str),"%s %s %s",(yyvsp[-3].str),stmt,(yyvsp[0].str));
            free(stmt);
		}
		else{sprintf((yyval.str),"%s %s %s %s %s",(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}}
#line 2099 "A1.tab.c"
    break;

  case 62:
#line 319 "A1.y"
                                {sprintf((yyval.str),"%s",(yyvsp[0].str));}
#line 2105 "A1.tab.c"
    break;

  case 63:
#line 320 "A1.y"
                                {sprintf((yyval.str),"%s",(yyvsp[0].str));}
#line 2111 "A1.tab.c"
    break;

  case 64:
#line 321 "A1.y"
                                {sprintf((yyval.str),"%s",(yyvsp[0].str));}
#line 2117 "A1.tab.c"
    break;

  case 65:
#line 322 "A1.y"
                                        {sprintf((yyval.str),"%s",(yyvsp[0].str));}
#line 2123 "A1.tab.c"
    break;

  case 66:
#line 323 "A1.y"
                                {sprintf((yyval.str),"%s",(yyvsp[0].str));}
#line 2129 "A1.tab.c"
    break;

  case 67:
#line 324 "A1.y"
                                                                 {sprintf((yyval.str),"%s %s %s %s %s",(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 2135 "A1.tab.c"
    break;

  case 68:
#line 325 "A1.y"
                                                         {sprintf((yyval.str),"%s %s %s %s",(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 2141 "A1.tab.c"
    break;

  case 69:
#line 326 "A1.y"
                                                 {sprintf((yyval.str),"%s %s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 2147 "A1.tab.c"
    break;

  case 70:
#line 327 "A1.y"
                                                 {sprintf((yyval.str),"%s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 2153 "A1.tab.c"
    break;

  case 71:
#line 330 "A1.y"
                        {sprintf((yyval.str),"%s",(yyvsp[0].str));}
#line 2159 "A1.tab.c"
    break;

  case 72:
#line 331 "A1.y"
                                        {sprintf((yyval.str),"%s",(yyvsp[0].str));}
#line 2165 "A1.tab.c"
    break;

  case 73:
#line 335 "A1.y"
        {char* temp=concat((yyvsp[-4].str), (yyvsp[-3].str));addMacro((yyvsp[-6].str),"",temp);free(temp);sprintf((yyval.str),"%s %s %s %s %s %s %s %s",(yyvsp[-7].str),(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 2171 "A1.tab.c"
    break;

  case 74:
#line 337 "A1.y"
        {char* temp=concat((yyvsp[-5].str), (yyvsp[-4].str));addMacro((yyvsp[-7].str),(yyvsp[-1].str),temp);free(temp);sprintf((yyval.str),"%s %s %s %s %s %s %s %s %s",(yyvsp[-8].str),(yyvsp[-7].str),(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 2177 "A1.tab.c"
    break;

  case 75:
#line 338 "A1.y"
                                                        {addMacro((yyvsp[-4].str),"",""); sprintf((yyval.str),"%s %s %s %s %s %s",(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 2183 "A1.tab.c"
    break;

  case 76:
#line 339 "A1.y"
                                                                                {addMacro((yyvsp[-5].str),(yyvsp[-1].str),""); sprintf((yyval.str),"%s %s %s %s %s %s %s",(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 2189 "A1.tab.c"
    break;

  case 77:
#line 340 "A1.y"
                                                                                {addMacro((yyvsp[-5].str),"",(yyvsp[-3].str)); sprintf((yyval.str),"%s %s %s %s %s %s %s",(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 2195 "A1.tab.c"
    break;

  case 78:
#line 341 "A1.y"
                                                                                                {addMacro((yyvsp[-6].str),(yyvsp[-1].str),(yyvsp[-4].str)); sprintf((yyval.str),"%s %s %s %s %s %s %s %s",(yyvsp[-7].str),(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 2201 "A1.tab.c"
    break;

  case 79:
#line 346 "A1.y"
        {char* temp=concat((yyvsp[-5].str), (yyvsp[-4].str));addMacro((yyvsp[-7].str),(yyvsp[-1].str),temp);free(temp);sprintf((yyval.str),"%s %s %s %s %s %s %s %s %s",(yyvsp[-8].str),(yyvsp[-7].str),(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 2207 "A1.tab.c"
    break;

  case 80:
#line 347 "A1.y"
                                                                {addMacro((yyvsp[-5].str),(yyvsp[-1].str),""); sprintf((yyval.str),"%s %s %s %s %s %s %s",(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 2213 "A1.tab.c"
    break;

  case 81:
#line 348 "A1.y"
                                                                                        {addMacro((yyvsp[-6].str),(yyvsp[-1].str),(yyvsp[-4].str)); sprintf((yyval.str),"%s %s %s %s %s %s %s %s",(yyvsp[-7].str),(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 2219 "A1.tab.c"
    break;

  case 82:
#line 351 "A1.y"
                                {sprintf((yyval.str),"%s %s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 2225 "A1.tab.c"
    break;

  case 83:
#line 352 "A1.y"
                                                {sprintf((yyval.str),"%s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 2231 "A1.tab.c"
    break;

  case 84:
#line 355 "A1.y"
                        {sprintf((yyval.str),"%s",(yyvsp[0].str));}
#line 2237 "A1.tab.c"
    break;

  case 85:
#line 358 "A1.y"
                    {sprintf((yyval.str),"%s",(yyvsp[0].str));}
#line 2243 "A1.tab.c"
    break;

  case 86:
#line 361 "A1.y"
                                {sprintf((yyval.str),"%s %s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 2249 "A1.tab.c"
    break;

  case 87:
#line 362 "A1.y"
                                                {sprintf((yyval.str),"%s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 2255 "A1.tab.c"
    break;

  case 88:
#line 366 "A1.y"
                                        {sprintf((yyval.str),"%s %s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 2261 "A1.tab.c"
    break;

  case 89:
#line 367 "A1.y"
                            {sprintf((yyval.str),"%s",(yyvsp[0].str));}
#line 2267 "A1.tab.c"
    break;

  case 90:
#line 370 "A1.y"
                                                {sprintf((yyval.str),"%s %s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 2273 "A1.tab.c"
    break;

  case 91:
#line 371 "A1.y"
                                        {sprintf((yyval.str),"%s",(yyvsp[0].str));}
#line 2279 "A1.tab.c"
    break;


#line 2283 "A1.tab.c"

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
#line 374 "A1.y"



void yyerror(char *str){
    printf("parse failed: %s\n", yytext);
}

int main() {
    yyparse();
    return 0;
}

#include "lex.yy.c"
