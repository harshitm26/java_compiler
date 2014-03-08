
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 2 "parse.y"
	
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "./lib.h"
	#define PDEBUG 0

	scope *current, *godscope;
	element* godelement;
	extern int nsymbols, line_number, label_count;
	extern struct symbol symtable[MAX_SYMBOLS];
	int error_count=0;	
	FILE* fp;
	extern "C"	//g++ compiler needs the definations declared[ not required by gcc]
	{
		int yyparse(void);
		int yylex(void);
		int yyerror(char* s){		//Print the error as it is on the stderr
			error_count++;
			fprintf(stderr, "%s at line %d\n",s, line_number);
		}
	}
	int ntabs=0;
	
	void indent(){
		int i=0;
		for(i=0; i<ntabs; i++) printf("%t");
	}
	void inctabs(){
		ntabs++;
	}
	void tdisp(char* str){
		indent();
		printf("%s\n", str);
		inctabs();
	}
	void disp(char* str){
		indent();
		printf("%s\n", str);
	}
	void edisp(char* str){
		indent();
		printf("ERROR AT LINE %d: %s\n", line_number, str);
	}
	


/* Line 189 of yacc.c  */
#line 121 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 1
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGERLITERAL = 258,
     LONGLITERAL = 259,
     FLOATLITERAL = 260,
     DOUBLELITERAL = 261,
     IDENT = 262,
     STRINGLITERAL = 263,
     CHARACTERLITERAL = 264,
     PLUSPLUS = 265,
     PLUS = 266,
     MINUS = 267,
     MINUSMINUS = 268,
     ASTERISK = 269,
     DIVIDE = 270,
     PERCENT = 271,
     EQUALS = 272,
     PLUSEQUALS = 273,
     MINUSEQUALS = 274,
     ASTERISKEQUALS = 275,
     DIVIDEEQUALS = 276,
     PERCENTEQUALS = 277,
     ANDEQUALS = 278,
     OREQUALS = 279,
     CARETEQUALS = 280,
     LEFTSHIFTEQUALS = 281,
     RIGHTSHIFTEQUALS = 282,
     ANDAND = 283,
     OROR = 284,
     NOT = 285,
     EQUALSEQUALS = 286,
     LESSEQUALS = 287,
     GREATEQUALS = 288,
     NOTEQUALS = 289,
     GREATER = 290,
     LESS = 291,
     OR = 292,
     AND = 293,
     CARET = 294,
     RIGHTSHIFT = 295,
     LEFTSHIFT = 296,
     UNRIGHTSHIFT = 297,
     UNRIGHTSHIFTEQUALS = 298,
     TILDE = 299,
     QUESTION = 300,
     COLON = 301,
     DOT = 302,
     SEMICOLON = 303,
     COMMA = 304,
     LEFTROUNDBRACE = 305,
     RIGHTROUNDBRACE = 306,
     LEFTCURLYBRACE = 307,
     RIGHTCURLYBRACE = 308,
     LEFTSQUAREBRACE = 309,
     RIGHTSQUAREBRACE = 310,
     BTRUE = 311,
     BFALSE = 312,
     NULLLITERAL = 313,
     PRINTINT = 314,
     PRINTSTRING = 315,
     PRINTFLOAT = 316,
     ABSTRACT = 317,
     ASSERT = 318,
     BOOLEAN = 319,
     BREAK = 320,
     BYTE = 321,
     CASE = 322,
     CATCH = 323,
     CHAR = 324,
     CLASS = 325,
     CONST = 326,
     CONTINUE = 327,
     DEFAULT = 328,
     _DO = 329,
     DOUBLE = 330,
     ELSE = 331,
     ENUM = 332,
     EXTENDS = 333,
     FINAL = 334,
     FINALLY = 335,
     FLOAT = 336,
     _FOR = 337,
     _IF = 338,
     GOTO = 339,
     IMPLEMENTS = 340,
     IMPORT = 341,
     INSTANCEOF = 342,
     INT = 343,
     INTERFACE = 344,
     LONG = 345,
     NATIVE = 346,
     NEW = 347,
     PACKAGE = 348,
     PRIVATE = 349,
     PROTECTED = 350,
     PUBLIC = 351,
     RETURN = 352,
     SHORT = 353,
     STATIC = 354,
     STRICTFP = 355,
     SUPER = 356,
     SWITCH = 357,
     SYNCHRONIZED = 358,
     THIS = 359,
     THROW = 360,
     THROWS = 361,
     TRANSIENT = 362,
     TRY = 363,
     VOID = 364,
     VOLATILE = 365,
     _WHILE = 366,
     ATTHERATE = 367
   };
#endif
/* Tokens.  */
#define INTEGERLITERAL 258
#define LONGLITERAL 259
#define FLOATLITERAL 260
#define DOUBLELITERAL 261
#define IDENT 262
#define STRINGLITERAL 263
#define CHARACTERLITERAL 264
#define PLUSPLUS 265
#define PLUS 266
#define MINUS 267
#define MINUSMINUS 268
#define ASTERISK 269
#define DIVIDE 270
#define PERCENT 271
#define EQUALS 272
#define PLUSEQUALS 273
#define MINUSEQUALS 274
#define ASTERISKEQUALS 275
#define DIVIDEEQUALS 276
#define PERCENTEQUALS 277
#define ANDEQUALS 278
#define OREQUALS 279
#define CARETEQUALS 280
#define LEFTSHIFTEQUALS 281
#define RIGHTSHIFTEQUALS 282
#define ANDAND 283
#define OROR 284
#define NOT 285
#define EQUALSEQUALS 286
#define LESSEQUALS 287
#define GREATEQUALS 288
#define NOTEQUALS 289
#define GREATER 290
#define LESS 291
#define OR 292
#define AND 293
#define CARET 294
#define RIGHTSHIFT 295
#define LEFTSHIFT 296
#define UNRIGHTSHIFT 297
#define UNRIGHTSHIFTEQUALS 298
#define TILDE 299
#define QUESTION 300
#define COLON 301
#define DOT 302
#define SEMICOLON 303
#define COMMA 304
#define LEFTROUNDBRACE 305
#define RIGHTROUNDBRACE 306
#define LEFTCURLYBRACE 307
#define RIGHTCURLYBRACE 308
#define LEFTSQUAREBRACE 309
#define RIGHTSQUAREBRACE 310
#define BTRUE 311
#define BFALSE 312
#define NULLLITERAL 313
#define PRINTINT 314
#define PRINTSTRING 315
#define PRINTFLOAT 316
#define ABSTRACT 317
#define ASSERT 318
#define BOOLEAN 319
#define BREAK 320
#define BYTE 321
#define CASE 322
#define CATCH 323
#define CHAR 324
#define CLASS 325
#define CONST 326
#define CONTINUE 327
#define DEFAULT 328
#define _DO 329
#define DOUBLE 330
#define ELSE 331
#define ENUM 332
#define EXTENDS 333
#define FINAL 334
#define FINALLY 335
#define FLOAT 336
#define _FOR 337
#define _IF 338
#define GOTO 339
#define IMPLEMENTS 340
#define IMPORT 341
#define INSTANCEOF 342
#define INT 343
#define INTERFACE 344
#define LONG 345
#define NATIVE 346
#define NEW 347
#define PACKAGE 348
#define PRIVATE 349
#define PROTECTED 350
#define PUBLIC 351
#define RETURN 352
#define SHORT 353
#define STATIC 354
#define STRICTFP 355
#define SUPER 356
#define SWITCH 357
#define SYNCHRONIZED 358
#define THIS 359
#define THROW 360
#define THROWS 361
#define TRANSIENT 362
#define TRY 363
#define VOID 364
#define VOLATILE 365
#define _WHILE 366
#define ATTHERATE 367




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 48 "parse.y"
		//union declared to store the return value of tokens
	int ival;
	long lval;
	float fval;
	double dval;
	//~ int index;
	char* sval;
	char cval;
	struct element* attr;
	struct namenode* name;
	bool status;
	struct listofelements* elist;
	struct listofdeclarators* dlist;
	struct spvec *pspvec;
	struct splab *splb;



/* Line 214 of yacc.c  */
#line 400 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 412 "y.tab.c"

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
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  37
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3742

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  113
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  174
/* YYNRULES -- Number of rules.  */
#define YYNRULES  380
/* YYNRULES -- Number of states.  */
#define YYNSTATES  629

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   367

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    41,    43,    45,    47,    49,    51,    53,    55,    57,
      59,    61,    63,    67,    71,    75,    77,    79,    81,    85,
      89,    92,    95,    97,   100,   102,   104,   105,   107,   110,
     112,   115,   119,   121,   123,   127,   133,   135,   137,   139,
     141,   144,   146,   148,   150,   152,   154,   156,   158,   160,
     162,   164,   165,   170,   171,   177,   182,   188,   189,   195,
     196,   203,   209,   216,   219,   222,   224,   228,   231,   235,
     237,   240,   242,   244,   246,   248,   250,   252,   256,   261,
     263,   267,   269,   273,   275,   279,   281,   283,   287,   291,
     294,   296,   300,   303,   306,   310,   311,   316,   317,   323,
     327,   329,   333,   336,   339,   341,   345,   347,   349,   352,
     353,   357,   358,   363,   367,   372,   373,   378,   379,   385,
     388,   392,   396,   401,   406,   412,   417,   423,   427,   432,
     437,   443,   446,   450,   453,   457,   459,   462,   464,   466,
     468,   471,   475,   478,   480,   483,   486,   488,   490,   493,
     496,   498,   500,   502,   504,   506,   508,   510,   512,   514,
     516,   518,   520,   522,   524,   526,   528,   530,   534,   537,
     539,   541,   543,   545,   547,   549,   551,   552,   553,   563,
     569,   574,   578,   582,   585,   587,   590,   593,   595,   598,
     602,   605,   606,   607,   615,   616,   617,   627,   628,   629,
     640,   641,   642,   643,   656,   657,   658,   659,   671,   672,
     673,   674,   685,   686,   687,   688,   700,   701,   702,   703,
     714,   715,   716,   717,   728,   729,   730,   731,   741,   743,
     745,   747,   749,   751,   753,   755,   757,   761,   765,   768,
     772,   775,   779,   782,   786,   789,   795,   799,   804,   808,
     810,   813,   819,   822,   824,   826,   828,   830,   834,   836,
     838,   840,   842,   847,   853,   855,   859,   864,   868,   873,
     877,   879,   882,   886,   889,   893,   897,   901,   906,   910,
     917,   923,   929,   936,   941,   946,   951,   956,   961,   963,
     965,   967,   969,   972,   975,   977,   979,   982,   985,   987,
     990,   993,   995,   998,  1001,  1003,  1009,  1014,  1019,  1025,
    1027,  1031,  1035,  1039,  1041,  1045,  1049,  1051,  1055,  1059,
    1063,  1065,  1069,  1073,  1077,  1081,  1085,  1087,  1091,  1095,
    1097,  1101,  1103,  1107,  1109,  1113,  1115,  1119,  1121,  1125,
    1127,  1133,  1135,  1137,  1141,  1143,  1145,  1147,  1149,  1151,
    1153,  1155,  1157,  1159,  1161,  1163,  1165,  1167,  1169,  1171,
    1173
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     114,     0,    -1,   130,    -1,     7,    -1,     3,    -1,     5,
      -1,     4,    -1,     6,    -1,    56,    -1,    57,    -1,     9,
      -1,     8,    -1,    58,    -1,   118,    -1,   122,    -1,   119,
      -1,    64,    -1,   109,    -1,   120,    -1,   121,    -1,    66,
      -1,    98,    -1,    88,    -1,    90,    -1,    69,    -1,    81,
      -1,    75,    -1,   123,    -1,   126,    -1,   127,    -1,   123,
      -1,   123,    -1,   118,    54,    55,    -1,   127,    54,    55,
      -1,   126,    54,    55,    -1,   128,    -1,   129,    -1,   115,
      -1,   127,    47,   115,    -1,   133,   131,   132,    -1,   133,
     131,    -1,   133,   132,    -1,   133,    -1,   131,   132,    -1,
     131,    -1,   132,    -1,    -1,   134,    -1,   131,   134,    -1,
     137,    -1,   132,   137,    -1,    93,   127,    48,    -1,   135,
      -1,   136,    -1,    86,   127,    48,    -1,    86,   127,    47,
      14,    48,    -1,   140,    -1,   178,    -1,    48,    -1,   139,
      -1,   138,   139,    -1,    96,    -1,    95,    -1,    94,    -1,
      99,    -1,    62,    -1,    79,    -1,    91,    -1,   103,    -1,
     107,    -1,   110,    -1,    -1,    70,   115,   141,   148,    -1,
      -1,    70,   115,   145,   142,   148,    -1,    70,   115,   146,
     148,    -1,    70,   115,   145,   146,   148,    -1,    -1,   138,
      70,   115,   143,   148,    -1,    -1,   138,    70,   115,   145,
     144,   148,    -1,   138,    70,   115,   146,   148,    -1,   138,
      70,   115,   145,   146,   148,    -1,    78,   124,    -1,    85,
     147,    -1,   125,    -1,   147,    49,   125,    -1,    52,    53,
      -1,    52,   149,    53,    -1,   150,    -1,   149,   150,    -1,
     151,    -1,   169,    -1,   170,    -1,   152,    -1,   159,    -1,
     140,    -1,   117,   153,    48,    -1,   138,   117,   153,    48,
      -1,   154,    -1,   153,    49,   154,    -1,   155,    -1,   155,
      17,   156,    -1,   115,    -1,   155,    54,    55,    -1,   285,
      -1,   157,    -1,    52,   158,    53,    -1,    52,    49,    53,
      -1,    52,    53,    -1,   156,    -1,   158,    49,   156,    -1,
     160,   168,    -1,   117,   161,    -1,   138,   117,   161,    -1,
      -1,   115,    50,   162,    51,    -1,    -1,   115,    50,   163,
     164,    51,    -1,   161,    54,    55,    -1,   165,    -1,   164,
      49,   165,    -1,   117,   155,    -1,   106,   167,    -1,   124,
      -1,   167,    49,   124,    -1,   185,    -1,    48,    -1,    99,
     185,    -1,    -1,   173,   171,   176,    -1,    -1,   138,   173,
     172,   176,    -1,   173,   166,   176,    -1,   138,   173,   166,
     176,    -1,    -1,   128,    50,   174,    51,    -1,    -1,   128,
      50,   175,   164,    51,    -1,    52,    53,    -1,    52,   177,
      53,    -1,    52,   186,    53,    -1,    52,   177,   186,    53,
      -1,   104,    50,    51,    48,    -1,   104,    50,   254,    51,
      48,    -1,   101,    50,    51,    48,    -1,   101,    50,   254,
      51,    48,    -1,    89,   115,   180,    -1,   138,    89,   115,
     180,    -1,    89,   115,   179,   180,    -1,   138,    89,   115,
     179,   180,    -1,    78,   125,    -1,   179,    49,   125,    -1,
      52,    53,    -1,    52,   181,    53,    -1,   182,    -1,   181,
     182,    -1,   183,    -1,   184,    -1,   152,    -1,   160,    48,
      -1,    52,   186,    53,    -1,    52,    53,    -1,   187,    -1,
     186,   187,    -1,     1,    48,    -1,   188,    -1,   190,    -1,
     189,    48,    -1,   117,   153,    -1,   191,    -1,   193,    -1,
     196,    -1,   205,    -1,   211,    -1,   185,    -1,   192,    -1,
     194,    -1,   199,    -1,   208,    -1,   242,    -1,   243,    -1,
     244,    -1,   246,    -1,   245,    -1,   247,    -1,    48,    -1,
     115,    46,   190,    -1,   195,    48,    -1,   282,    -1,   266,
      -1,   267,    -1,   263,    -1,   264,    -1,   260,    -1,   253,
      -1,    -1,    -1,   238,    50,   285,    51,   197,   190,    76,
     198,   190,    -1,   102,    50,   285,    51,   200,    -1,    52,
     201,   203,    53,    -1,    52,   201,    53,    -1,    52,   203,
      53,    -1,    52,    53,    -1,   202,    -1,   201,   202,    -1,
     203,   186,    -1,   204,    -1,   203,   204,    -1,    67,   286,
      46,    -1,    73,    46,    -1,    -1,    -1,   236,    50,   206,
     285,    51,   207,   190,    -1,    -1,    -1,   235,   209,   190,
     236,    50,   285,   210,    51,    48,    -1,    -1,    -1,   237,
      50,   239,    48,   212,   285,   213,    48,    51,   190,    -1,
      -1,    -1,    -1,   237,    50,   239,    48,   214,   285,   215,
      48,   240,    51,   216,   190,    -1,    -1,    -1,    -1,   237,
      50,   239,    48,   217,   218,    48,   240,    51,   219,   190,
      -1,    -1,    -1,    -1,   237,    50,   239,    48,   220,   221,
      48,    51,   222,   190,    -1,    -1,    -1,    -1,   237,    50,
      48,   223,   285,   224,    48,   240,    51,   225,   190,    -1,
      -1,    -1,    -1,   237,    50,    48,   226,   285,   227,    48,
      51,   228,   190,    -1,    -1,    -1,    -1,   237,    50,    48,
     229,   230,    48,   240,    51,   231,   190,    -1,    -1,    -1,
      -1,   237,    50,    48,   232,   233,    48,    51,   234,   190,
      -1,    74,    -1,   111,    -1,    82,    -1,    83,    -1,   241,
      -1,   189,    -1,   241,    -1,   195,    -1,   241,    49,   195,
      -1,    65,   115,    48,    -1,    65,    48,    -1,    72,   115,
      48,    -1,    72,    48,    -1,    97,   285,    48,    -1,    97,
      48,    -1,   105,   285,    48,    -1,   105,    48,    -1,   103,
      50,   285,    51,   185,    -1,   108,   185,   248,    -1,   108,
     185,   248,   250,    -1,   108,   185,   250,    -1,   249,    -1,
     248,   249,    -1,    68,    50,   165,    51,   185,    -1,    80,
     185,    -1,   252,    -1,   255,    -1,   116,    -1,   104,    -1,
      50,   285,    51,    -1,   253,    -1,   259,    -1,   260,    -1,
     261,    -1,    92,   124,    50,    51,    -1,    92,   124,    50,
     254,    51,    -1,   285,    -1,   254,    49,   285,    -1,    92,
     118,   256,   258,    -1,    92,   118,   256,    -1,    92,   123,
     256,   258,    -1,    92,   123,   256,    -1,   257,    -1,   256,
     257,    -1,    54,   285,    55,    -1,    54,    55,    -1,   258,
      54,    55,    -1,   251,    47,   115,    -1,   101,    47,   115,
      -1,   127,    50,   254,    51,    -1,   127,    50,    51,    -1,
     251,    47,   115,    50,   254,    51,    -1,   251,    47,   115,
      50,    51,    -1,   101,    47,   115,    50,    51,    -1,   101,
      47,   115,    50,   254,    51,    -1,    60,    50,   285,    51,
      -1,    59,    50,   285,    51,    -1,    61,    50,   285,    51,
      -1,   127,    54,   285,    55,    -1,   252,    54,   285,    55,
      -1,   251,    -1,   127,    -1,   263,    -1,   264,    -1,   262,
      10,    -1,   262,    13,    -1,   266,    -1,   267,    -1,    11,
     265,    -1,    12,   265,    -1,   268,    -1,    10,   265,    -1,
      13,   265,    -1,   262,    -1,    44,   265,    -1,    30,   265,
      -1,   269,    -1,    50,   118,   258,    51,   265,    -1,    50,
     118,    51,   265,    -1,    50,   285,    51,   268,    -1,    50,
     127,   258,    51,   268,    -1,   265,    -1,   270,    14,   265,
      -1,   270,    15,   265,    -1,   270,    16,   265,    -1,   270,
      -1,   271,    11,   270,    -1,   271,    12,   270,    -1,   271,
      -1,   272,    41,   271,    -1,   272,    40,   271,    -1,   272,
      42,   271,    -1,   272,    -1,   273,    36,   272,    -1,   273,
      35,   272,    -1,   273,    33,   272,    -1,   273,    32,   272,
      -1,   273,    87,   122,    -1,   273,    -1,   274,    31,   273,
      -1,   274,    34,   273,    -1,   274,    -1,   275,    38,   274,
      -1,   275,    -1,   276,    39,   275,    -1,   276,    -1,   277,
      37,   276,    -1,   277,    -1,   278,    28,   277,    -1,   278,
      -1,   279,    29,   278,    -1,   279,    -1,   279,    45,   285,
      46,   280,    -1,   280,    -1,   282,    -1,   283,   284,   281,
      -1,   127,    -1,   259,    -1,   261,    -1,    17,    -1,    20,
      -1,    21,    -1,    22,    -1,    18,    -1,    19,    -1,    26,
      -1,    27,    -1,    43,    -1,    23,    -1,    25,    -1,    24,
      -1,   281,    -1,   285,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   226,   226,   236,   242,   257,   270,   289,   304,   318,
     331,   344,   362,   378,   382,   389,   392,   396,   402,   406,
     413,   417,   421,   425,   429,   436,   440,   447,   451,   457,
     464,   471,   478,   483,   490,   498,   502,   509,   518,   531,
     532,   533,   534,   535,   536,   537,   538,   542,   543,   548,
     552,   564,   568,   569,   573,   577,   581,   585,   586,   593,
     597,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   617,   616,   636,   635,   657,   658,   660,   659,   687,
     686,   712,   713,   717,   723,   727,   728,   732,   736,   743,
     747,   758,   762,   763,   770,   771,   772,   782,   799,   826,
     830,   841,   850,   872,   884,   892,   896,   905,   918,   922,
     929,   936,   965,   981,   998,  1033,  1032,  1060,  1059,  1095,
    1099,  1106,  1119,  1137,  1141,  1142,  1146,  1150,  1157,  1162,
    1161,  1176,  1175,  1195,  1196,  1201,  1200,  1235,  1234,  1280,
    1284,  1292,  1301,  1312,  1316,  1338,  1342,  1370,  1371,  1372,
    1373,  1377,  1378,  1382,  1383,  1386,  1387,  1391,  1392,  1396,
    1400,  1406,  1410,  1417,  1421,  1430,  1434,  1438,  1445,  1452,
    1496,  1497,  1498,  1499,  1500,  1506,  1510,  1511,  1512,  1513,
    1514,  1515,  1516,  1517,  1518,  1519,  1523,  1527,  1532,  1547,
    1551,  1555,  1559,  1563,  1567,  1571,  1579,  1597,  1578,  1635,
    1672,  1688,  1692,  1696,  1703,  1704,  1723,  1730,  1731,  1750,
    1751,  1760,  1766,  1759,  1793,  1800,  1792,  1824,  1830,  1823,
    1853,  1858,  1867,  1852,  1879,  1884,  1889,  1878,  1902,  1907,
    1912,  1901,  1926,  1931,  1940,  1925,  1954,  1959,  1968,  1953,
    1981,  1986,  1991,  1980,  2004,  2009,  2014,  2003,  2028,  2032,
    2037,  2041,  2045,  2054,  2061,  2073,  2074,  2085,  2086,  2090,
    2091,  2095,  2127,  2148,  2149,  2153,  2157,  2158,  2159,  2163,
    2164,  2168,  2172,  2176,  2177,  2181,  2182,  2188,  2189,  2190,
    2191,  2195,  2202,  2260,  2340,  2347,  2360,  2368,  2396,  2404,
    2433,  2443,  2451,  2466,  2473,  2481,  2495,  2521,  2640,  2733,
    2859,  2955,  3060,  3191,  3199,  3207,  3222,  3313,  3399,  3400,
    3401,  3402,  3406,  3433,  3460,  3461,  3462,  3463,  3479,  3483,
    3502,  3520,  3521,  3535,  3554,  3558,  3569,  3578,  3587,  3602,
    3603,  3629,  3655,  3684,  3685,  3711,  3740,  3741,  3766,  3791,
    3819,  3823,  3854,  3885,  3916,  3947,  3963,  3967,  3998,  4032,
    4033,  4062,  4063,  4092,  4093,  4122,  4123,  4152,  4153,  4182,
    4183,  4221,  4222,  4226,  4250,  4254,  4258,  4265,  4266,  4267,
    4268,  4269,  4270,  4271,  4272,  4273,  4274,  4275,  4276,  4280,
    4284
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGERLITERAL", "LONGLITERAL",
  "FLOATLITERAL", "DOUBLELITERAL", "IDENT", "STRINGLITERAL",
  "CHARACTERLITERAL", "PLUSPLUS", "PLUS", "MINUS", "MINUSMINUS",
  "ASTERISK", "DIVIDE", "PERCENT", "EQUALS", "PLUSEQUALS", "MINUSEQUALS",
  "ASTERISKEQUALS", "DIVIDEEQUALS", "PERCENTEQUALS", "ANDEQUALS",
  "OREQUALS", "CARETEQUALS", "LEFTSHIFTEQUALS", "RIGHTSHIFTEQUALS",
  "ANDAND", "OROR", "NOT", "EQUALSEQUALS", "LESSEQUALS", "GREATEQUALS",
  "NOTEQUALS", "GREATER", "LESS", "OR", "AND", "CARET", "RIGHTSHIFT",
  "LEFTSHIFT", "UNRIGHTSHIFT", "UNRIGHTSHIFTEQUALS", "TILDE", "QUESTION",
  "COLON", "DOT", "SEMICOLON", "COMMA", "LEFTROUNDBRACE",
  "RIGHTROUNDBRACE", "LEFTCURLYBRACE", "RIGHTCURLYBRACE",
  "LEFTSQUAREBRACE", "RIGHTSQUAREBRACE", "BTRUE", "BFALSE", "NULLLITERAL",
  "PRINTINT", "PRINTSTRING", "PRINTFLOAT", "ABSTRACT", "ASSERT", "BOOLEAN",
  "BREAK", "BYTE", "CASE", "CATCH", "CHAR", "CLASS", "CONST", "CONTINUE",
  "DEFAULT", "_DO", "DOUBLE", "ELSE", "ENUM", "EXTENDS", "FINAL",
  "FINALLY", "FLOAT", "_FOR", "_IF", "GOTO", "IMPLEMENTS", "IMPORT",
  "INSTANCEOF", "INT", "INTERFACE", "LONG", "NATIVE", "NEW", "PACKAGE",
  "PRIVATE", "PROTECTED", "PUBLIC", "RETURN", "SHORT", "STATIC",
  "STRICTFP", "SUPER", "SWITCH", "SYNCHRONIZED", "THIS", "THROW", "THROWS",
  "TRANSIENT", "TRY", "VOID", "VOLATILE", "_WHILE", "ATTHERATE", "$accept",
  "Goal", "Identifier", "Literal", "Type", "PrimitiveType", "NumericType",
  "IntegralType", "FloatingPointType", "ReferenceType",
  "ClassOrInterfaceType", "ClassType", "InterfaceType", "ArrayType",
  "Name", "SimpleName", "QualifiedName", "CompilationUnit",
  "ImportDeclarations", "TypeDeclarations", "PackageDeclaration",
  "ImportDeclaration", "SingleTypeImportDeclaration",
  "TypeImportOnDemandDeclaration", "TypeDeclaration", "Modifiers",
  "Modifier", "ClassDeclaration", "$@1", "$@2", "$@3", "$@4", "Super",
  "Interfaces", "InterfaceTypeList", "ClassBody", "ClassBodyDeclarations",
  "ClassBodyDeclaration", "ClassMemberDeclaration", "FieldDeclaration",
  "VariableDeclarators", "VariableDeclarator", "VariableDeclaratorId",
  "VariableInitializer", "ArrayInitializer", "VariableInitializers",
  "MethodDeclaration", "MethodHeader", "MethodDeclarator", "$@5", "$@6",
  "FormalParameterList", "FormalParameter", "Throws", "ClassTypeList",
  "MethodBody", "StaticInitializer", "ConstructorDeclaration", "$@7",
  "$@8", "ConstructorDeclarator", "$@9", "$@10", "ConstructorBody",
  "ExplicitConstructorInvocation", "InterfaceDeclaration",
  "ExtendsInterfaces", "InterfaceBody", "InterfaceMemberDeclarations",
  "InterfaceMemberDeclaration", "ConstantDeclaration",
  "AbstractMethodDeclaration", "Block", "BlockStatements",
  "BlockStatement", "LocalVariableDeclarationStatement",
  "LocalVariableDeclaration", "Statement",
  "StatementWithoutTrailingSubstatement", "EmptyStatement",
  "LabeledStatement", "ExpressionStatement", "StatementExpression",
  "IfThenElseStatement", "$@11", "$@12", "SwitchStatement", "SwitchBlock",
  "SwitchBlockStatementGroups", "SwitchBlockStatementGroup",
  "SwitchLabels", "SwitchLabel", "WhileStatement", "$@13", "$@14",
  "DoStatement", "$@15", "$@16", "ForStatement", "$@17", "$@18", "$@19",
  "$@20", "$@21", "$@22", "$@23", "$@24", "$@25", "$@26", "$@27", "$@28",
  "$@29", "$@30", "$@31", "$@32", "$@33", "$@34", "$@35", "$@36", "$@37",
  "$@38", "$@39", "DO", "WHILE", "FOR", "IF", "ForInit", "ForUpdate",
  "StatementExpressionList", "BreakStatement", "ContinueStatement",
  "ReturnStatement", "ThrowStatement", "SynchronizedStatement",
  "TryStatement", "Catches", "CatchClause", "Finally", "Primary",
  "PrimaryNoNewArray", "ClassInstanceCreationExpression", "ArgumentList",
  "ArrayCreationExpression", "DimExprs", "DimExpr", "Dims", "FieldAccess",
  "MethodInvocation", "ArrayAccess", "PostfixExpression",
  "PostIncrementExpression", "PostDecrementExpression", "UnaryExpression",
  "PreIncrementExpression", "PreDecrementExpression",
  "UnaryExpressionNotPlusMinus", "CastExpression",
  "MultiplicativeExpression", "AdditiveExpression", "ShiftExpression",
  "RelationalExpression", "EqualityExpression", "AndExpression",
  "ExclusiveOrExpression", "InclusiveOrExpression",
  "ConditionalAndExpression", "ConditionalOrExpression",
  "ConditionalExpression", "AssignmentExpression", "Assignment",
  "LeftHandSide", "AssignmentOperator", "Expression", "ConstantExpression", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   113,   114,   115,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   117,   117,   118,   118,   118,   119,   119,
     120,   120,   120,   120,   120,   121,   121,   122,   122,   123,
     124,   125,   126,   126,   126,   127,   127,   128,   129,   130,
     130,   130,   130,   130,   130,   130,   130,   131,   131,   132,
     132,   133,   134,   134,   135,   136,   137,   137,   137,   138,
     138,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   141,   140,   142,   140,   140,   140,   143,   140,   144,
     140,   140,   140,   145,   146,   147,   147,   148,   148,   149,
     149,   150,   150,   150,   151,   151,   151,   152,   152,   153,
     153,   154,   154,   155,   155,   156,   156,   157,   157,   157,
     158,   158,   159,   160,   160,   162,   161,   163,   161,   161,
     164,   164,   165,   166,   167,   167,   168,   168,   169,   171,
     170,   172,   170,   170,   170,   174,   173,   175,   173,   176,
     176,   176,   176,   177,   177,   177,   177,   178,   178,   178,
     178,   179,   179,   180,   180,   181,   181,   182,   182,   183,
     184,   185,   185,   186,   186,   186,   187,   187,   188,   189,
     190,   190,   190,   190,   190,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   192,   193,   194,   195,
     195,   195,   195,   195,   195,   195,   197,   198,   196,   199,
     200,   200,   200,   200,   201,   201,   202,   203,   203,   204,
     204,   206,   207,   205,   209,   210,   208,   212,   213,   211,
     214,   215,   216,   211,   217,   218,   219,   211,   220,   221,
     222,   211,   223,   224,   225,   211,   226,   227,   228,   211,
     229,   230,   231,   211,   232,   233,   234,   211,   235,   236,
     237,   238,   239,   239,   240,   241,   241,   242,   242,   243,
     243,   244,   244,   245,   245,   246,   247,   247,   247,   248,
     248,   249,   250,   251,   251,   252,   252,   252,   252,   252,
     252,   252,   253,   253,   254,   254,   255,   255,   255,   255,
     256,   256,   257,   258,   258,   259,   259,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   261,   261,   262,   262,
     262,   262,   263,   264,   265,   265,   265,   265,   265,   266,
     267,   268,   268,   268,   268,   269,   269,   269,   269,   270,
     270,   270,   270,   271,   271,   271,   272,   272,   272,   272,
     273,   273,   273,   273,   273,   273,   274,   274,   274,   275,
     275,   276,   276,   277,   277,   278,   278,   279,   279,   280,
     280,   281,   281,   282,   283,   283,   283,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   285,
     286
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     1,     1,     1,     3,     3,
       2,     2,     1,     2,     1,     1,     0,     1,     2,     1,
       2,     3,     1,     1,     3,     5,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     0,     5,     4,     5,     0,     5,     0,
       6,     5,     6,     2,     2,     1,     3,     2,     3,     1,
       2,     1,     1,     1,     1,     1,     1,     3,     4,     1,
       3,     1,     3,     1,     3,     1,     1,     3,     3,     2,
       1,     3,     2,     2,     3,     0,     4,     0,     5,     3,
       1,     3,     2,     2,     1,     3,     1,     1,     2,     0,
       3,     0,     4,     3,     4,     0,     4,     0,     5,     2,
       3,     3,     4,     4,     5,     4,     5,     3,     4,     4,
       5,     2,     3,     2,     3,     1,     2,     1,     1,     1,
       2,     3,     2,     1,     2,     2,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     0,     0,     9,     5,
       4,     3,     3,     2,     1,     2,     2,     1,     2,     3,
       2,     0,     0,     7,     0,     0,     9,     0,     0,    10,
       0,     0,     0,    12,     0,     0,     0,    11,     0,     0,
       0,    10,     0,     0,     0,    11,     0,     0,     0,    10,
       0,     0,     0,    10,     0,     0,     0,     9,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     2,     3,
       2,     3,     2,     3,     2,     5,     3,     4,     3,     1,
       2,     5,     2,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     4,     5,     1,     3,     4,     3,     4,     3,
       1,     2,     3,     2,     3,     3,     3,     4,     3,     6,
       5,     5,     6,     4,     4,     4,     4,     4,     1,     1,
       1,     1,     2,     2,     1,     1,     2,     2,     1,     2,
       2,     1,     2,     2,     1,     5,     4,     4,     5,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
      46,    58,    65,     0,    66,     0,     0,    67,     0,    63,
      62,    61,    64,    68,    69,    70,     0,     2,    44,    45,
      42,    47,    52,    53,    49,     0,    59,    56,    57,     3,
      71,    37,     0,    35,    36,     0,     0,     1,    43,    48,
      50,    40,    41,     0,     0,    60,     0,     0,     0,    73,
       0,     0,    54,     0,     0,     0,   147,     0,    51,    39,
      77,     0,    30,    83,    29,    31,    85,    84,     0,    72,
       0,     0,    75,     0,    38,   153,    16,    20,    24,    26,
      25,    22,    23,    21,    17,     0,    13,    15,    18,    19,
      14,    27,    28,    29,     0,   159,     0,     0,   155,   157,
     158,   151,     0,   149,     0,    79,     0,     0,   148,     0,
      87,    64,    35,     0,    96,     0,    89,    91,    94,    95,
       0,    92,    93,   129,    74,    76,    55,   103,     0,    99,
     101,   113,     0,     0,     0,     0,   160,   154,   156,   152,
      78,     0,     0,    81,   150,    86,     0,   128,   137,   131,
      88,    90,   127,   112,   126,     0,     0,     0,   117,    97,
       0,     0,     0,     0,    32,    34,    33,     0,   114,    80,
      82,     0,     4,     6,     5,     7,    11,    10,     0,     0,
     186,     0,   162,     8,     9,    12,     0,     0,     0,     0,
       0,   248,   250,   251,     0,     0,     0,     0,     0,   276,
       0,     0,   249,    37,   275,     0,   364,   175,     0,   163,
     166,     0,   167,   170,   176,   171,   177,     0,   172,   178,
     173,   179,   174,   214,     0,     0,     0,   180,   181,   182,
     184,   183,   185,   308,   273,   278,   274,   279,   280,   281,
       0,   192,   193,   190,   191,   189,     0,     0,     0,     0,
       0,   124,   123,     0,   133,   130,     0,     0,   103,   100,
       0,     0,     0,     0,     0,     0,   309,   102,   106,   278,
     280,   321,   310,   311,   329,   314,   315,   318,   324,   333,
     336,   340,   346,   349,   351,   353,   355,   357,   359,   361,
     379,   362,   105,   104,   119,    98,   165,   309,   279,   281,
     319,   320,     0,     0,     0,     0,   258,     0,   260,     0,
       0,    30,     0,   262,     0,     0,     0,     0,   264,     0,
       0,     0,   169,     0,     0,   161,   164,   168,   188,     0,
     211,     0,     0,     0,     0,   312,   313,   367,   371,   372,
     368,   369,   370,   376,   378,   377,   373,   374,   375,     0,
     136,     0,     0,   120,   134,   132,     0,   139,     0,   276,
       0,     0,   116,     0,   316,   317,   323,   322,     0,   309,
       0,     0,   109,   110,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   277,     0,     0,
       0,   257,   259,     0,   287,   290,   289,     0,   261,   296,
       0,     0,   263,     0,     0,   266,   269,   268,   187,   298,
       0,   284,     0,     0,     0,   232,   253,   255,     0,   252,
       0,   295,     0,   363,   122,     0,   138,   125,     0,     0,
     140,     0,   141,   118,     0,     0,     0,     0,     0,   277,
     108,     0,   107,   330,   331,   332,   334,   335,   338,   337,
     339,   344,   343,   342,   341,     0,   345,   347,   348,   350,
     352,   354,   356,   358,     0,   304,   303,   305,     0,     0,
     291,   286,   288,   282,     0,     0,     0,     0,     0,   272,
     270,   267,     0,   297,   306,     0,     0,     0,     0,   241,
     245,   217,     0,   196,     0,   307,   121,     0,     0,     0,
       0,   142,   326,   293,     0,     0,     0,   327,   111,     0,
     292,   283,   301,     0,     0,   199,   265,     0,   285,     0,
     212,   233,   237,     0,     0,     0,     0,   225,   229,   256,
       0,   300,     0,   145,     0,   143,     0,   325,   294,   328,
     360,   302,   203,     0,     0,     0,   204,     0,   207,     0,
     215,     0,     0,     0,     0,     0,   218,   221,     0,     0,
       0,   299,   146,   144,   380,     0,   210,   201,   205,     0,
     202,   206,   208,   271,     0,   213,     0,     0,     0,   254,
     246,     0,     0,     0,     0,   197,   209,   200,     0,     0,
     238,   242,     0,     0,     0,     0,   230,     0,   216,   234,
       0,     0,   247,     0,     0,   226,     0,   198,     0,   239,
     243,   219,   222,     0,   231,   235,     0,   227,   223
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    16,    31,   204,   205,    86,    87,    88,    89,    90,
      91,    63,    66,    92,   266,    33,    34,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    48,    70,
     104,   141,    49,    50,    67,    69,   115,   116,   117,    95,
     128,   129,   130,   267,   268,   374,   119,    96,   131,   256,
     257,   352,   353,   156,   252,   153,   121,   122,   157,   250,
     123,   247,   248,   254,   360,    28,    55,    56,    97,    98,
      99,   100,   207,   581,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   540,   607,   219,   525,   555,   556,
     557,   558,   220,   424,   561,   221,   329,   584,   222,   535,
     591,   536,   592,   626,   537,   568,   623,   538,   569,   616,
     497,   562,   618,   498,   563,   610,   499,   533,   611,   500,
     534,   602,   223,   224,   225,   226,   428,   588,   589,   227,
     228,   229,   230,   231,   232,   415,   416,   417,   233,   234,
     269,   420,   236,   404,   405,   446,   237,   270,   239,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     246,   349,   421,   575
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -431
static const yytype_int16 yypact[] =
{
     193,  -431,  -431,    21,  -431,    21,    21,  -431,    21,  -431,
    -431,  -431,  -431,  -431,  -431,  -431,    37,  -431,   586,   657,
     586,  -431,  -431,  -431,  -431,    67,  -431,  -431,  -431,  -431,
     -46,  -431,   175,  -431,  -431,   -25,   275,  -431,   657,  -431,
    -431,   586,   657,    21,    21,  -431,    21,    21,    -9,   -33,
      -9,    95,  -431,  2598,    21,    87,  -431,    21,  -431,   657,
     -46,   -25,  -431,  -431,    61,  -431,  -431,    79,  1120,  -431,
      -9,    -9,  -431,   104,  -431,  -431,  -431,  -431,  -431,  -431,
    -431,  -431,  -431,  -431,  -431,    21,   130,  -431,  -431,  -431,
    -431,  -431,   138,   121,  2745,  -431,   128,  2647,  -431,  -431,
    -431,  -431,    21,  -431,    -9,   -33,    -9,    87,  -431,    21,
    -431,   195,   177,  2696,  -431,  2549,  -431,  -431,  -431,  -431,
     155,  -431,  -431,   148,  -431,  -431,  -431,   233,   165,  -431,
      71,   236,   242,   246,   252,    21,  -431,  -431,  -431,  -431,
    -431,    -9,    -9,  -431,  -431,  -431,  1543,  -431,   266,   148,
    -431,  -431,  -431,  -431,  -431,    21,   290,   290,   296,  -431,
      21,  2912,   297,   299,  -431,  -431,  -431,   190,   236,  -431,
    -431,   303,  -431,  -431,  -431,  -431,  -431,  -431,  3561,  3561,
    -431,  3561,  -431,  -431,  -431,  -431,   306,   309,   311,    15,
      16,  -431,  -431,  -431,     9,  2971,   315,   313,   316,  -431,
    3030,   195,  -431,   307,  -431,    21,   183,  -431,  1870,  -431,
    -431,   319,  -431,  -431,  -431,  -431,  -431,   321,  -431,  -431,
    -431,  -431,  -431,  -431,   318,   322,   323,  -431,  -431,  -431,
    -431,  -431,  -431,   324,   325,    96,  -431,   490,   200,  1214,
     191,   222,   243,  -431,  -431,  -431,  1328,   326,     9,   290,
     290,  -431,   327,  1652,  -431,  -431,   349,     9,  -431,  -431,
    3561,  3561,  3561,  3561,  2415,  2853,   847,  -431,  -431,  -431,
    -431,   191,  -431,  -431,  -431,  -431,  -431,  -431,  -431,   244,
     329,   264,    98,   239,   337,   339,   365,   376,     2,  -431,
    -431,  -431,  -431,  -431,  -431,  -431,  -431,    -5,  -431,  -431,
    -431,  -431,   355,  3561,  3561,  3561,  -431,   359,  -431,   361,
     356,   356,   362,  -431,   366,    21,  3561,  3561,  -431,   367,
     111,  2306,   364,  3089,  3148,  -431,  -431,  -431,  -431,  2306,
    -431,  2522,  3561,    21,  3561,  -431,  -431,  -431,  -431,  -431,
    -431,  -431,  -431,  -431,  -431,  -431,  -431,  -431,  -431,  3561,
    -431,    21,   226,  -431,  -431,  -431,    21,  -431,   224,   368,
    1761,  1979,  -431,   259,  -431,  -431,  -431,  -431,   227,   934,
     369,   363,  -431,  -431,   166,  3561,  3561,  3561,  3561,  3561,
    3561,  3561,  3561,  3561,  3561,  3561,  3561,  3561,     9,  3561,
    3561,  3561,  3561,  3561,  3561,  3561,  3561,  -431,   371,   372,
     373,  -431,  -431,  3561,   374,  -431,   374,  3207,  -431,   377,
     375,   379,  -431,   381,   195,   111,  -431,  -431,  -431,  -431,
     262,  -431,   378,   330,  3561,   386,  -431,  -431,   387,   388,
     385,   390,   391,  -431,   389,     9,  -431,  -431,  3266,  3325,
    -431,  2088,  -431,  -431,  3561,   397,   240,  3384,   248,  3579,
    -431,  2912,  -431,  -431,  -431,  -431,   244,   244,   329,   329,
     329,   264,   264,   264,   264,   130,  -431,    98,    98,   239,
     337,   339,   365,   376,   396,  -431,  -431,  -431,   400,  3384,
    -431,   403,   403,  -431,   265,  3443,   406,   195,     9,  -431,
    -431,  -431,  3561,  -431,  -431,   409,   412,  3561,  3561,  -431,
    -431,   416,  3638,  -431,  3502,  -431,  -431,   417,   278,   419,
     282,  -431,  -431,  -431,  3561,   405,  3579,  -431,  -431,  3561,
    -431,  -431,  -431,   283,   127,  -431,  -431,   418,  -431,  3561,
    -431,  -431,  -431,   420,   423,  3561,  3561,  -431,  -431,  -431,
    2306,  -431,   287,  -431,   426,  -431,   428,  -431,  -431,  -431,
    -431,  -431,  -431,  3561,   431,   153,  -431,  1317,  -431,   195,
    -431,  2306,   432,   434,  3638,   436,  -431,  -431,   435,   437,
     413,  -431,  -431,  -431,  -431,   442,  -431,  -431,  -431,  1434,
    -431,  2197,  -431,  -431,   439,  -431,  3638,   444,   445,   388,
    -431,   449,   450,  3638,   448,  -431,  -431,  -431,   452,   451,
    -431,  -431,  2306,   454,  3638,   468,  -431,  2306,  -431,  -431,
    2306,  2306,  -431,  2306,   471,  -431,  2306,  -431,  2306,  -431,
    -431,  -431,  -431,  2306,  -431,  -431,  2306,  -431,  -431
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -431,  -431,    -3,  -431,   -32,  -177,  -431,  -431,  -431,   105,
     -41,  -135,    46,  -431,     4,    56,  -431,  -431,   481,    26,
    -431,   124,  -431,  -431,   122,    52,   -17,   -44,  -431,  -431,
    -431,  -431,   443,   -31,  -431,   -15,  -431,   411,  -431,   -35,
    -120,   382,   173,  -263,  -431,  -431,  -431,    36,   392,  -431,
    -431,   277,  -409,   395,  -431,  -431,  -431,  -431,  -431,  -431,
     422,  -431,  -431,  -127,  -431,  -431,   475,     5,  -431,   455,
    -431,  -431,   -86,  -142,  -207,  -431,   201,   320,  -431,  -431,
    -431,  -431,  -324,  -431,  -431,  -431,  -431,  -431,  -431,   -16,
     -14,  -384,  -431,  -431,  -431,  -431,  -431,  -431,  -431,  -431,
    -431,  -431,  -431,  -431,  -431,  -431,  -431,  -431,  -431,  -431,
    -431,  -431,  -431,  -431,  -431,  -431,  -431,  -431,  -431,  -431,
    -431,  -431,  -431,   123,  -431,  -431,  -431,  -362,   216,  -431,
    -431,  -431,  -431,  -431,  -431,  -431,   133,   134,  -431,  -431,
    -132,  -369,  -431,   245,   -67,  -266,   894,   -36,   917,    90,
     209,   298,  -168,   383,   476,  -430,  -431,   -30,   -62,  -141,
     -45,   162,   163,   167,   168,   164,  -431,    44,   215,   527,
    -431,  -431,   715,  -431
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -367
static const yytype_int16 yytable[] =
{
      30,   326,   373,    35,   208,    62,    65,   427,    45,    32,
     300,   301,    36,    65,   235,   167,    29,   310,    71,   517,
     251,    85,    29,    29,   114,   147,   506,    53,    29,   106,
     255,   395,    46,   118,   154,    72,    85,    37,   484,    47,
      60,    61,    57,    68,    38,   323,    42,   396,    74,   375,
      64,    64,    47,    54,    74,   124,   125,    93,    64,   312,
     103,    65,   135,   306,   308,    85,   108,    59,    65,   508,
     510,   114,    93,    76,   142,    77,   235,    45,    78,   527,
     118,   135,   127,    85,    79,   322,   549,   368,   161,   140,
      80,   143,   364,   365,   366,   367,    45,    81,    93,    82,
     101,    93,    29,   448,   120,    94,    64,    83,    57,    73,
     238,   361,   144,    64,    62,   320,   523,    93,    84,    93,
     113,   235,   354,   355,   112,   162,   169,   170,   109,     2,
     384,   385,   127,   386,   387,   542,   102,    43,   481,    53,
     482,    40,    39,   203,  -195,  -195,     4,  -195,   139,    94,
     206,   120,   126,   311,   326,   145,    44,   258,     7,    64,
      40,     9,    10,    11,    40,    39,    12,   113,    57,   112,
      13,   112,   238,   582,    14,   134,   136,    15,   539,   413,
     552,    40,   297,   297,   132,   388,   307,   309,   518,   235,
     -29,   414,   133,  -309,   553,   582,  -309,   235,    64,   235,
     554,   335,   258,   152,   336,   203,   577,   146,   453,   454,
     455,   465,   206,   159,   160,   451,   351,   238,   441,   452,
     553,   437,    51,    52,   599,   351,   554,   148,   235,   235,
      57,   605,  -310,   323,   326,  -310,   240,   324,   295,   160,
     427,     1,   614,   461,   462,   463,   464,   146,  -194,  -194,
     203,  -194,    93,  -311,   155,     2,  -311,   206,   376,   377,
     378,    93,   427,     3,   297,   297,   297,   297,   369,   427,
     389,   315,     4,   390,   438,   435,   512,   436,   444,     5,
     427,   445,     6,   158,     7,   238,     8,     9,    10,    11,
     163,   514,    12,   238,   515,   238,    13,   164,   240,   516,
      14,   165,   515,    15,   381,   382,   383,   166,   435,   235,
     443,   492,   409,   493,   492,    62,   521,  -135,   203,   458,
     459,   460,    57,    58,   238,   238,   203,   492,   489,   544,
     431,   492,   492,   546,   551,   206,   492,   480,   571,   480,
     379,   380,   253,   240,   467,   468,   547,  -115,   258,   456,
     457,   296,   293,   321,   294,   241,   303,   203,   203,   304,
      64,   305,   315,   316,   206,   206,   317,   327,   330,   328,
     235,   333,   331,   332,   326,   391,   356,   350,   392,   334,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,    93,   297,   297,   297,   297,   297,   297,   297,
     362,   526,   393,   351,   394,   238,   397,   401,   235,   402,
     403,   240,   407,   160,   408,   412,   450,   241,   439,   240,
     449,   240,   475,   476,   477,   235,   486,   485,   479,   235,
     487,   488,   235,   494,  -240,   501,   503,   502,   203,    93,
     504,   202,   519,   162,   242,   206,   505,   235,   297,   235,
     240,   240,   513,   297,   235,   520,   351,   515,   524,   529,
     548,   235,   241,   530,  -224,   543,   238,   545,   564,   559,
     235,   565,   235,   583,   572,   235,   573,   576,   235,   235,
     586,   235,   587,   593,   235,   594,   235,   590,   596,   595,
     598,   235,    93,   466,   235,   600,   601,   603,   604,   606,
     608,    41,   609,   105,   238,   613,   242,  -365,  -365,  -365,
    -365,  -365,  -365,  -365,  -365,  -365,  -365,  -365,   297,   615,
     297,   238,   622,   297,   434,   238,   151,   168,   238,   243,
     241,   240,   426,  -365,   363,   149,   107,   203,   241,   578,
     241,   579,   259,   238,   249,   238,   495,   429,   490,   491,
     238,   242,   138,   469,   203,   470,   406,   238,   203,   473,
     471,   206,   472,   550,   433,     0,   238,     0,   238,   241,
     241,   238,     0,     0,   238,   238,   203,   238,   203,     0,
     238,     0,   238,   206,     0,   206,     0,   238,     0,     0,
     238,   243,   240,     0,     0,     0,     0,     0,     0,   203,
       0,     0,     0,     0,   203,     0,     0,   203,   203,     0,
     203,     0,     0,   203,     0,   203,     0,     0,     0,   242,
     203,     0,   244,   203,     0,     0,     0,   242,     0,   242,
     240,     0,     0,     0,     1,     0,   243,     0,     0,     0,
       0,   418,     0,     0,     0,     0,     0,   240,     2,   423,
     241,   240,     0,     0,   240,     0,     3,     0,   242,   242,
       0,     0,     0,     0,     0,     4,     0,     0,     0,   240,
       0,   240,     5,   245,     0,     6,   240,     7,     0,     0,
       9,    10,    11,   240,   244,    12,     0,     0,     0,    13,
       0,     0,   240,    14,   240,     0,    15,   240,     0,     0,
     240,   240,     0,   240,   243,     1,   240,     0,   240,     0,
       0,   241,   243,   240,   243,     0,   240,     0,     0,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     0,   244,
       0,     0,     0,     0,     0,   245,     4,     0,     0,   242,
       0,     0,     0,   243,   243,     0,     6,     0,     7,   241,
       0,     9,    10,    11,     0,     0,    12,     0,     0,     0,
      13,     0,     0,     0,    14,     0,   241,    15,     0,     0,
     241,     0,     0,   241,     0,     0,     0,     0,     0,     0,
     245,     0,     0,     0,     0,     0,     0,     0,   241,     0,
     241,     0,     0,     0,     0,   241,     0,   244,     0,     0,
     242,     0,   241,     0,     0,   244,     0,   244,     0,     0,
       0,   241,     0,   241,     0,     0,   241,     0,     0,   241,
     241,     0,   241,     0,   243,   241,     0,   241,     0,     0,
       0,     0,   241,     0,     0,   241,   244,   244,   242,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   245,     0,
       0,     0,     0,     0,     0,   242,   245,     0,   245,   242,
     570,     0,   242,     0,  -364,  -364,  -364,  -364,  -364,  -364,
    -364,  -364,  -364,  -364,  -364,     0,   292,   242,     0,   242,
       0,   585,     0,     0,   242,   243,     0,   245,   245,     0,
    -364,   242,     0,     0,    57,     0,   302,   323,     0,     0,
     242,   375,   242,     0,     0,   242,     0,     0,   242,   242,
     314,   242,     0,     0,   242,   319,   242,   244,     0,     0,
       0,   242,   612,   243,   242,     0,     0,   617,     0,     0,
     619,   620,     0,   621,     0,     0,   624,     0,   625,     0,
     243,     0,     0,   627,   243,     0,   628,   243,     0,     0,
       0,  -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364,
    -364,  -364,   243,     0,   243,     0,     0,     0,   245,   243,
       0,     0,     0,     0,     0,     0,   243,  -364,   244,   370,
     292,    57,     0,     0,   323,   243,     0,   243,   447,     0,
     243,     0,     0,   243,   243,     0,   243,     0,     0,   243,
       0,   243,     0,     0,     0,     0,   243,     0,     0,   243,
       0,     0,     0,     0,     0,     0,   244,     0,   398,   399,
     400,     0,     0,     0,     0,     0,     0,     0,     0,   245,
       0,   410,   411,   244,     0,     0,     0,   244,     0,   422,
     244,     0,     0,     0,     0,     0,     0,   430,     0,   432,
       0,     0,     0,     0,     0,   244,     0,   244,     0,     0,
       0,     0,   244,     0,     0,     0,     0,   245,     0,   244,
       0,     0,   298,   298,     0,     0,     0,     0,   244,     0,
     244,     0,     0,   244,   245,     0,   244,   244,   245,   244,
     422,   245,   244,     0,   244,   299,   299,     0,     0,   244,
       0,     0,   244,     0,     0,     0,   245,     0,   245,     0,
       0,   474,     0,   245,     0,     0,     0,     0,   478,     0,
     245,     0,     0,     0,     0,     0,     0,    29,     0,   245,
       0,   245,     0,     0,   245,     0,     0,   245,   245,   496,
     245,     0,     0,   245,     0,   245,     0,     0,     0,     0,
     245,     0,     0,   245,   298,   298,   298,   298,     0,     0,
       0,     0,   422,     0,     0,     0,   292,     0,     0,     0,
       0,     0,     0,   110,     0,     0,     0,   299,   299,   299,
     299,     0,     2,     0,    76,     0,    77,     0,     0,    78,
       3,     0,     0,     0,   478,    79,     0,     0,     0,     4,
       0,    80,     0,     0,     0,     0,     0,   528,    81,     0,
      82,     7,   531,   532,     9,    10,    11,     0,    83,   111,
       0,     0,     0,    13,     0,     0,     0,    14,     0,    84,
      15,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,     0,     0,   560,     0,     0,     0,     0,     0,
     566,   567,     0,     0,     0,     0,     0,  -366,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   574,     0,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,     0,   298,   298,   298,   298,   298,   298,   298,
       0,     0,     0,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,     0,   299,   299,   299,   299,
     299,   299,   299,     0,     0,     0,     0,     0,   171,     0,
     172,   173,   174,   175,    29,   176,   177,   178,     0,     0,
     179,     0,     0,     0,     0,     0,     0,     0,   298,     0,
       0,     0,     0,   298,     0,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,     0,     0,     0,     0,
       0,   299,     0,     0,     0,   180,   299,   181,     0,   146,
     580,   348,     0,   183,   184,   185,   186,   187,   188,     0,
       0,    76,   189,    77,   553,     0,    78,     0,     0,   190,
     554,   191,    79,     0,     0,     0,     0,     0,    80,   192,
     193,     0,     0,     0,     0,    81,     0,    82,   298,   194,
     298,     0,     0,   298,   195,    83,     0,     0,   196,   197,
     198,   199,   200,     0,     0,   201,    84,     0,   202,     0,
       0,   299,     0,   299,     0,   171,   299,   172,   173,   174,
     175,    29,   176,   177,   178,     0,     0,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   180,     0,   181,     0,   146,   597,     0,     0,
     183,   184,   185,   186,   187,   188,     0,     0,    76,   189,
      77,   553,     0,    78,     0,     0,   190,   554,   191,    79,
       0,     0,     0,     0,     0,    80,   192,   193,     0,     0,
       0,     0,    81,     0,    82,     0,   194,     0,     0,     0,
       0,   195,    83,     0,     0,   196,   197,   198,   199,   200,
       0,     0,   201,    84,   171,   202,   172,   173,   174,   175,
      29,   176,   177,   178,     0,     0,   179,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   180,     0,   181,     0,   146,   182,     0,     0,   183,
     184,   185,   186,   187,   188,     0,     0,    76,   189,    77,
       0,     0,    78,     0,     0,   190,     0,   191,    79,     0,
       0,     0,     0,     0,    80,   192,   193,     0,     0,     0,
       0,    81,     0,    82,     0,   194,     0,     0,     0,     0,
     195,    83,     0,     0,   196,   197,   198,   199,   200,     0,
       0,   201,    84,   171,   202,   172,   173,   174,   175,    29,
     176,   177,   178,     0,     0,   179,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     180,     0,   181,     0,   146,   357,     0,     0,   183,   184,
     185,   186,   187,   188,     0,     0,    76,   189,    77,     0,
       0,    78,     0,     0,   190,     0,   191,    79,     0,     0,
       0,     0,     0,    80,   192,   193,     0,     0,     0,     0,
      81,     0,    82,     0,   194,     0,     0,     0,     0,   195,
      83,     0,     0,   358,   197,   198,   359,   200,     0,     0,
     201,    84,   171,   202,   172,   173,   174,   175,    29,   176,
     177,   178,     0,     0,   179,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   180,
       0,   181,     0,   146,   440,     0,     0,   183,   184,   185,
     186,   187,   188,     0,     0,    76,   189,    77,     0,     0,
      78,     0,     0,   190,     0,   191,    79,     0,     0,     0,
       0,     0,    80,   192,   193,     0,     0,     0,     0,    81,
       0,    82,     0,   194,     0,     0,     0,     0,   195,    83,
       0,     0,   196,   197,   198,   199,   200,     0,     0,   201,
      84,     0,   202,   172,   173,   174,   175,    29,   176,   177,
     178,     0,     0,   179,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   180,     0,
     181,     0,   146,   325,     0,     0,   183,   184,   185,   186,
     187,   188,     0,     0,    76,   189,    77,     0,     0,    78,
       0,     0,   190,     0,   191,    79,     0,     0,     0,     0,
       0,    80,   192,   193,     0,     0,     0,     0,    81,     0,
      82,     0,   194,     0,     0,     0,     0,   195,    83,     0,
       0,   196,   197,   198,   199,   200,     0,     0,   201,    84,
       0,   202,   172,   173,   174,   175,    29,   176,   177,   178,
       0,     0,   179,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   180,     0,   181,
       0,   146,   442,     0,     0,   183,   184,   185,   186,   187,
     188,     0,     0,    76,   189,    77,     0,     0,    78,     0,
       0,   190,     0,   191,    79,     0,     0,     0,     0,     0,
      80,   192,   193,     0,     0,     0,     0,    81,     0,    82,
       0,   194,     0,     0,     0,     0,   195,    83,     0,     0,
     196,   197,   198,   199,   200,     0,     0,   201,    84,     0,
     202,   172,   173,   174,   175,    29,   176,   177,   178,     0,
       0,   179,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   180,     0,   181,     0,
     146,   511,     0,     0,   183,   184,   185,   186,   187,   188,
       0,     0,    76,   189,    77,     0,     0,    78,     0,     0,
     190,     0,   191,    79,     0,     0,     0,     0,     0,    80,
     192,   193,     0,     0,     0,     0,    81,     0,    82,     0,
     194,     0,     0,     0,     0,   195,    83,     0,     0,   196,
     197,   198,   199,   200,     0,     0,   201,    84,     0,   202,
     172,   173,   174,   175,    29,   176,   177,   178,     0,     0,
     179,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   180,     0,   181,     0,   146,
       0,     0,     0,   183,   184,   185,   186,   187,   188,     0,
       0,    76,   189,    77,     0,     0,    78,     0,     0,   190,
       0,   191,    79,     0,     0,     0,     0,     0,    80,   192,
     193,     0,     0,     0,     0,    81,     0,    82,     0,   194,
       0,     0,     0,     0,   195,    83,     0,     0,   196,   197,
     198,   199,   200,     0,     0,   201,    84,     0,   202,   172,
     173,   174,   175,    29,   176,   177,   178,     0,     0,   179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   180,     0,   181,     0,   146,     0,
       0,     0,   183,   184,   185,   186,   187,   188,     0,     0,
       0,   189,     0,     0,     0,     0,     0,     0,   190,     0,
     191,     0,     0,     0,     0,     0,     0,     0,   192,   193,
       0,     0,     0,     0,     0,     0,     0,     0,   194,     0,
       0,     0,     0,   195,     0,     0,     0,   196,   197,   198,
     199,   200,     0,     0,   201,     0,     0,   202,   172,   173,
     174,   175,    29,   176,   177,   178,   260,   261,   179,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   262,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   263,
       0,     0,     0,     0,     0,   264,     0,     0,     0,     0,
       0,   183,   184,   185,   186,   187,   188,     0,     0,    76,
       0,    77,     0,     0,    78,     0,     0,     0,     0,     0,
      79,     0,     0,     0,     0,     0,    80,     0,     0,     0,
       0,     0,     0,    81,     0,    82,     0,   194,     0,     0,
       0,     0,     0,    83,     0,     0,   196,     0,     0,   199,
       0,     0,     0,     0,    84,   172,   173,   174,   175,    29,
     176,   177,   178,     0,     0,   179,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    29,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     425,     0,   181,     0,     0,     0,     0,     0,   183,   184,
     185,   186,   187,   188,     0,     0,    76,     0,    77,     0,
       0,    78,     0,     0,     0,     0,     0,    79,     0,     0,
       0,     0,   150,    80,     0,    29,     0,     0,     0,     0,
      81,     2,    82,    76,   194,    77,     0,     0,    78,     3,
      83,     0,     0,   196,    79,     0,   199,     0,     4,     0,
      80,    84,     0,     0,     0,     0,     0,    81,     0,    82,
       7,     0,     0,     9,    10,    11,     0,    83,   111,     0,
       0,    75,    13,     0,    29,     0,    14,     0,    84,    15,
       2,     0,    76,     0,    77,     0,     0,    78,     0,     0,
       0,     0,     0,    79,     0,     0,     0,     4,     0,    80,
       0,     0,     0,     0,     0,     0,    81,     0,    82,     7,
       0,     0,     9,    10,    11,     0,    83,    12,     0,     0,
     137,    13,     0,    29,     0,    14,     0,    84,    15,     2,
       0,    76,     0,    77,     0,     0,    78,     0,     0,     0,
       0,     0,    79,     0,     0,     0,     4,     0,    80,     0,
       0,     0,     0,     0,     0,    81,     0,    82,     7,     0,
       0,     9,    10,    11,     0,    83,    12,     0,     0,     0,
      13,     0,    29,     0,    14,     0,    84,    15,     2,     0,
      76,     0,    77,     0,     0,    78,    43,     0,     0,     0,
       0,    79,     0,     0,     0,     4,     0,    80,     0,     0,
       0,     0,     0,     0,    81,     0,    82,     7,     0,     0,
       9,    10,    11,     0,    83,    12,     0,     0,     0,    13,
       0,     0,     0,    14,     0,    84,    15,     2,     0,    76,
       0,    77,     0,     0,    78,     0,     0,     0,     0,     0,
      79,     0,     0,     0,     4,     0,    80,     0,     0,     0,
       0,     0,     0,    81,     0,    82,     7,     0,     0,     9,
      10,    11,     0,    83,    12,     0,     0,     0,    13,     0,
       0,     0,    14,     0,    84,    15,   172,   173,   174,   175,
      29,   176,   177,   178,   260,   261,   179,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   262,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   263,     0,     0,
       0,     0,   371,   264,     0,   265,   372,     0,     0,   183,
     184,   185,   186,   187,   188,   172,   173,   174,   175,    29,
     176,   177,   178,   260,   261,   179,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   262,     0,     0,   194,     0,     0,     0,     0,
       0,     0,     0,     0,   196,     0,   263,   199,     0,     0,
       0,     0,   264,     0,   265,     0,     0,     0,   183,   184,
     185,   186,   187,   188,   172,   173,   174,   175,    29,   176,
     177,   178,   260,   261,   179,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   262,     0,     0,   194,     0,     0,     0,     0,     0,
       0,     0,     0,   196,     0,   263,   199,     0,     0,   313,
       0,   264,     0,     0,     0,     0,     0,   183,   184,   185,
     186,   187,   188,   172,   173,   174,   175,    29,   176,   177,
     178,   260,   261,   179,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     262,     0,     0,   194,     0,     0,     0,     0,     0,     0,
       0,     0,   196,     0,   263,   199,     0,     0,   318,     0,
     264,     0,     0,     0,     0,     0,   183,   184,   185,   186,
     187,   188,   172,   173,   174,   175,    29,   176,   177,   178,
     260,   261,   179,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   262,
       0,     0,   194,     0,     0,     0,     0,     0,     0,     0,
       0,   196,     0,   263,   199,     0,     0,     0,     0,   264,
     419,     0,     0,     0,     0,   183,   184,   185,   186,   187,
     188,   172,   173,   174,   175,    29,   176,   177,   178,   260,
     261,   179,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   262,     0,
       0,   194,     0,     0,     0,     0,     0,     0,     0,     0,
     196,     0,   263,   199,     0,     0,     0,     0,   264,     0,
       0,     0,     0,   166,   183,   184,   185,   186,   187,   188,
     172,   173,   174,   175,    29,   176,   177,   178,   260,   261,
     179,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   262,     0,     0,
     194,     0,     0,     0,     0,     0,     0,     0,     0,   196,
       0,   263,   199,     0,     0,     0,     0,   264,   483,     0,
       0,     0,     0,   183,   184,   185,   186,   187,   188,   172,
     173,   174,   175,    29,   176,   177,   178,   260,   261,   179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   262,     0,     0,   194,
       0,     0,     0,     0,     0,     0,     0,     0,   196,     0,
     263,   199,     0,     0,     0,     0,   264,   507,     0,     0,
       0,     0,   183,   184,   185,   186,   187,   188,   172,   173,
     174,   175,    29,   176,   177,   178,   260,   261,   179,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   262,     0,     0,   194,     0,
       0,     0,     0,     0,     0,     0,     0,   196,     0,   263,
     199,     0,     0,     0,     0,   264,   509,     0,     0,     0,
       0,   183,   184,   185,   186,   187,   188,   172,   173,   174,
     175,    29,   176,   177,   178,   260,   261,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   262,     0,     0,   194,     0,     0,
       0,     0,     0,     0,     0,     0,   196,     0,   263,   199,
       0,     0,     0,     0,   264,     0,     0,     0,     0,   513,
     183,   184,   185,   186,   187,   188,   172,   173,   174,   175,
      29,   176,   177,   178,   260,   261,   179,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   262,     0,     0,   194,     0,     0,     0,
       0,     0,     0,     0,     0,   196,     0,   263,   199,     0,
       0,     0,     0,   264,   522,     0,     0,     0,     0,   183,
     184,   185,   186,   187,   188,   172,   173,   174,   175,    29,
     176,   177,   178,   260,   261,   179,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   262,     0,     0,   194,     0,     0,     0,     0,
       0,     0,     0,     0,   196,     0,   263,   199,     0,     0,
       0,     0,   264,   541,     0,     0,     0,     0,   183,   184,
     185,   186,   187,   188,   172,   173,   174,   175,    29,   176,
     177,   178,   260,   261,   179,     0,     0,     0,     0,     0,
       0,     0,   172,   173,   174,   175,    29,   176,   177,     0,
       0,   262,     0,     0,   194,     0,     0,     0,     0,     0,
       0,     0,     0,   196,     0,   263,   199,     0,     0,   262,
       0,   264,     0,     0,     0,     0,     0,   183,   184,   185,
     186,   187,   188,   263,     0,     0,     0,     0,     0,   264,
       0,     0,     0,     0,     0,   183,   184,   185,   186,   187,
     188,   172,   173,   174,   175,    29,   176,   177,   178,     0,
       0,   179,     0,   194,     0,     0,     0,     0,     0,     0,
       0,     0,   196,     0,     0,   199,     0,     0,     0,     0,
       0,   194,     0,     0,     0,     0,     0,     0,     0,     0,
     196,     0,     0,   199,     0,     0,     0,     0,   181,     0,
       0,     0,     0,     0,   183,   184,   185,   186,   187,   188,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     194,     0,     0,     0,     0,     0,     0,     0,     0,   196,
       0,     0,   199
};

static const yytype_int16 yycheck[] =
{
       3,   208,   265,     6,   146,    46,    47,   331,    25,     5,
     178,   179,     8,    54,   146,   135,     7,   194,    49,   449,
     155,    53,     7,     7,    68,   111,   435,    52,     7,    60,
     157,    29,    78,    68,   120,    50,    68,     0,   407,    85,
      43,    44,    47,    52,    18,    50,    20,    45,    51,    54,
      46,    47,    85,    78,    57,    70,    71,    53,    54,   194,
      55,   102,    94,    48,    48,    97,    61,    41,   109,   438,
     439,   115,    68,    64,   105,    66,   208,    94,    69,   488,
     115,   113,    85,   115,    75,   205,   516,   264,    17,   104,
      81,   106,   260,   261,   262,   263,   113,    88,    94,    90,
      54,    97,     7,   369,    68,    53,   102,    98,    47,    14,
     146,   253,   107,   109,   155,   201,   485,   113,   109,   115,
      68,   253,   249,   250,    68,    54,   141,   142,    49,    62,
      32,    33,   135,    35,    36,   504,    49,    70,   404,    52,
     406,    19,    18,   146,    48,    49,    79,    51,   102,    97,
     146,   115,    48,   194,   361,   109,    89,   160,    91,   155,
      38,    94,    95,    96,    42,    41,    99,   115,    47,   113,
     103,   115,   208,   557,   107,    54,    48,   110,   502,    68,
      53,    59,   178,   179,    54,    87,   189,   190,   451,   321,
       7,    80,    54,    10,    67,   579,    13,   329,   194,   331,
      73,    10,   205,    48,    13,   208,    53,    52,   376,   377,
     378,   388,   208,    48,    49,    49,   248,   253,   360,    53,
      67,   356,    47,    48,   586,   257,    73,    50,   360,   361,
      47,   593,    10,    50,   441,    13,   146,    54,    48,    49,
     564,    48,   604,   384,   385,   386,   387,    52,    48,    49,
     253,    51,   248,    10,   106,    62,    13,   253,    14,    15,
      16,   257,   586,    70,   260,   261,   262,   263,   264,   593,
      31,    47,    79,    34,    50,    49,   444,    51,    51,    86,
     604,    54,    89,    50,    91,   321,    93,    94,    95,    96,
      54,    51,    99,   329,    54,   331,   103,    55,   208,    51,
     107,    55,    54,   110,    40,    41,    42,    55,    49,   441,
      51,    49,   315,    51,    49,   356,    51,    51,   321,   381,
     382,   383,    47,    48,   360,   361,   329,    49,   414,    51,
     333,    49,    49,    51,    51,   331,    49,   404,    51,   406,
      11,    12,    52,   253,   389,   390,   514,    51,   351,   379,
     380,    48,    55,    46,    55,   146,    50,   360,   361,    50,
     356,    50,    47,    50,   360,   361,    50,    48,    50,    48,
     502,    47,    50,    50,   581,    38,    49,    51,    39,    54,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
      51,   487,    37,   435,    28,   441,    51,    48,   540,    48,
      54,   321,    50,    49,    48,    48,    53,   208,    50,   329,
      51,   331,    51,    51,    51,   557,    51,    50,    54,   561,
      51,    50,   564,    55,    48,    48,    51,    49,   441,   435,
      50,   111,    46,    54,   146,   441,    55,   579,   444,   581,
     360,   361,    55,   449,   586,    55,   488,    54,    52,    50,
      55,   593,   253,    51,    48,    48,   502,    48,    48,    51,
     602,    48,   604,   559,    48,   607,    48,    46,   610,   611,
      48,   613,    48,    48,   616,    48,   618,    51,    46,    76,
      51,   623,   488,   388,   626,    51,    51,    48,    48,    51,
      48,    20,    51,    60,   540,    51,   208,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   514,    51,
     516,   557,    51,   519,   351,   561,   115,   135,   564,   146,
     321,   441,   331,    43,   257,   113,    61,   540,   329,   555,
     331,   555,   160,   579,   149,   581,   423,   331,   415,   415,
     586,   253,    97,   391,   557,   392,   311,   593,   561,   395,
     393,   557,   394,   519,   349,    -1,   602,    -1,   604,   360,
     361,   607,    -1,    -1,   610,   611,   579,   613,   581,    -1,
     616,    -1,   618,   579,    -1,   581,    -1,   623,    -1,    -1,
     626,   208,   502,    -1,    -1,    -1,    -1,    -1,    -1,   602,
      -1,    -1,    -1,    -1,   607,    -1,    -1,   610,   611,    -1,
     613,    -1,    -1,   616,    -1,   618,    -1,    -1,    -1,   321,
     623,    -1,   146,   626,    -1,    -1,    -1,   329,    -1,   331,
     540,    -1,    -1,    -1,    48,    -1,   253,    -1,    -1,    -1,
      -1,   321,    -1,    -1,    -1,    -1,    -1,   557,    62,   329,
     441,   561,    -1,    -1,   564,    -1,    70,    -1,   360,   361,
      -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,   579,
      -1,   581,    86,   146,    -1,    89,   586,    91,    -1,    -1,
      94,    95,    96,   593,   208,    99,    -1,    -1,    -1,   103,
      -1,    -1,   602,   107,   604,    -1,   110,   607,    -1,    -1,
     610,   611,    -1,   613,   321,    48,   616,    -1,   618,    -1,
      -1,   502,   329,   623,   331,    -1,   626,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,   253,
      -1,    -1,    -1,    -1,    -1,   208,    79,    -1,    -1,   441,
      -1,    -1,    -1,   360,   361,    -1,    89,    -1,    91,   540,
      -1,    94,    95,    96,    -1,    -1,    99,    -1,    -1,    -1,
     103,    -1,    -1,    -1,   107,    -1,   557,   110,    -1,    -1,
     561,    -1,    -1,   564,    -1,    -1,    -1,    -1,    -1,    -1,
     253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   579,    -1,
     581,    -1,    -1,    -1,    -1,   586,    -1,   321,    -1,    -1,
     502,    -1,   593,    -1,    -1,   329,    -1,   331,    -1,    -1,
      -1,   602,    -1,   604,    -1,    -1,   607,    -1,    -1,   610,
     611,    -1,   613,    -1,   441,   616,    -1,   618,    -1,    -1,
      -1,    -1,   623,    -1,    -1,   626,   360,   361,   540,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   321,    -1,
      -1,    -1,    -1,    -1,    -1,   557,   329,    -1,   331,   561,
     540,    -1,   564,    -1,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,   161,   579,    -1,   581,
      -1,   561,    -1,    -1,   586,   502,    -1,   360,   361,    -1,
      43,   593,    -1,    -1,    47,    -1,   181,    50,    -1,    -1,
     602,    54,   604,    -1,    -1,   607,    -1,    -1,   610,   611,
     195,   613,    -1,    -1,   616,   200,   618,   441,    -1,    -1,
      -1,   623,   602,   540,   626,    -1,    -1,   607,    -1,    -1,
     610,   611,    -1,   613,    -1,    -1,   616,    -1,   618,    -1,
     557,    -1,    -1,   623,   561,    -1,   626,   564,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,   579,    -1,   581,    -1,    -1,    -1,   441,   586,
      -1,    -1,    -1,    -1,    -1,    -1,   593,    43,   502,   264,
     265,    47,    -1,    -1,    50,   602,    -1,   604,    54,    -1,
     607,    -1,    -1,   610,   611,    -1,   613,    -1,    -1,   616,
      -1,   618,    -1,    -1,    -1,    -1,   623,    -1,    -1,   626,
      -1,    -1,    -1,    -1,    -1,    -1,   540,    -1,   303,   304,
     305,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   502,
      -1,   316,   317,   557,    -1,    -1,    -1,   561,    -1,   324,
     564,    -1,    -1,    -1,    -1,    -1,    -1,   332,    -1,   334,
      -1,    -1,    -1,    -1,    -1,   579,    -1,   581,    -1,    -1,
      -1,    -1,   586,    -1,    -1,    -1,    -1,   540,    -1,   593,
      -1,    -1,   178,   179,    -1,    -1,    -1,    -1,   602,    -1,
     604,    -1,    -1,   607,   557,    -1,   610,   611,   561,   613,
     375,   564,   616,    -1,   618,   178,   179,    -1,    -1,   623,
      -1,    -1,   626,    -1,    -1,    -1,   579,    -1,   581,    -1,
      -1,   396,    -1,   586,    -1,    -1,    -1,    -1,   403,    -1,
     593,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,   602,
      -1,   604,    -1,    -1,   607,    -1,    -1,   610,   611,   424,
     613,    -1,    -1,   616,    -1,   618,    -1,    -1,    -1,    -1,
     623,    -1,    -1,   626,   260,   261,   262,   263,    -1,    -1,
      -1,    -1,   447,    -1,    -1,    -1,   451,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,   260,   261,   262,
     263,    -1,    62,    -1,    64,    -1,    66,    -1,    -1,    69,
      70,    -1,    -1,    -1,   479,    75,    -1,    -1,    -1,    79,
      -1,    81,    -1,    -1,    -1,    -1,    -1,   492,    88,    -1,
      90,    91,   497,   498,    94,    95,    96,    -1,    98,    99,
      -1,    -1,    -1,   103,    -1,    -1,    -1,   107,    -1,   109,
     110,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,   529,    -1,    -1,    -1,    -1,    -1,
     535,   536,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   553,    -1,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,    -1,   389,   390,   391,   392,   393,   394,   395,
      -1,    -1,    -1,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,    -1,   389,   390,   391,   392,
     393,   394,   395,    -1,    -1,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,    -1,
      -1,    -1,    -1,   449,    -1,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,   444,    -1,    -1,    -1,    48,   449,    50,    -1,    52,
      53,    43,    -1,    56,    57,    58,    59,    60,    61,    -1,
      -1,    64,    65,    66,    67,    -1,    69,    -1,    -1,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    81,    82,
      83,    -1,    -1,    -1,    -1,    88,    -1,    90,   514,    92,
     516,    -1,    -1,   519,    97,    98,    -1,    -1,   101,   102,
     103,   104,   105,    -1,    -1,   108,   109,    -1,   111,    -1,
      -1,   514,    -1,   516,    -1,     1,   519,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    50,    -1,    52,    53,    -1,    -1,
      56,    57,    58,    59,    60,    61,    -1,    -1,    64,    65,
      66,    67,    -1,    69,    -1,    -1,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    81,    82,    83,    -1,    -1,
      -1,    -1,    88,    -1,    90,    -1,    92,    -1,    -1,    -1,
      -1,    97,    98,    -1,    -1,   101,   102,   103,   104,   105,
      -1,    -1,   108,   109,     1,   111,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    50,    -1,    52,    53,    -1,    -1,    56,
      57,    58,    59,    60,    61,    -1,    -1,    64,    65,    66,
      -1,    -1,    69,    -1,    -1,    72,    -1,    74,    75,    -1,
      -1,    -1,    -1,    -1,    81,    82,    83,    -1,    -1,    -1,
      -1,    88,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      97,    98,    -1,    -1,   101,   102,   103,   104,   105,    -1,
      -1,   108,   109,     1,   111,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    50,    -1,    52,    53,    -1,    -1,    56,    57,
      58,    59,    60,    61,    -1,    -1,    64,    65,    66,    -1,
      -1,    69,    -1,    -1,    72,    -1,    74,    75,    -1,    -1,
      -1,    -1,    -1,    81,    82,    83,    -1,    -1,    -1,    -1,
      88,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    97,
      98,    -1,    -1,   101,   102,   103,   104,   105,    -1,    -1,
     108,   109,     1,   111,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    50,    -1,    52,    53,    -1,    -1,    56,    57,    58,
      59,    60,    61,    -1,    -1,    64,    65,    66,    -1,    -1,
      69,    -1,    -1,    72,    -1,    74,    75,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    -1,    -1,    -1,    -1,    88,
      -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    97,    98,
      -1,    -1,   101,   102,   103,   104,   105,    -1,    -1,   108,
     109,    -1,   111,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,
      50,    -1,    52,    53,    -1,    -1,    56,    57,    58,    59,
      60,    61,    -1,    -1,    64,    65,    66,    -1,    -1,    69,
      -1,    -1,    72,    -1,    74,    75,    -1,    -1,    -1,    -1,
      -1,    81,    82,    83,    -1,    -1,    -1,    -1,    88,    -1,
      90,    -1,    92,    -1,    -1,    -1,    -1,    97,    98,    -1,
      -1,   101,   102,   103,   104,   105,    -1,    -1,   108,   109,
      -1,   111,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    50,
      -1,    52,    53,    -1,    -1,    56,    57,    58,    59,    60,
      61,    -1,    -1,    64,    65,    66,    -1,    -1,    69,    -1,
      -1,    72,    -1,    74,    75,    -1,    -1,    -1,    -1,    -1,
      81,    82,    83,    -1,    -1,    -1,    -1,    88,    -1,    90,
      -1,    92,    -1,    -1,    -1,    -1,    97,    98,    -1,    -1,
     101,   102,   103,   104,   105,    -1,    -1,   108,   109,    -1,
     111,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    50,    -1,
      52,    53,    -1,    -1,    56,    57,    58,    59,    60,    61,
      -1,    -1,    64,    65,    66,    -1,    -1,    69,    -1,    -1,
      72,    -1,    74,    75,    -1,    -1,    -1,    -1,    -1,    81,
      82,    83,    -1,    -1,    -1,    -1,    88,    -1,    90,    -1,
      92,    -1,    -1,    -1,    -1,    97,    98,    -1,    -1,   101,
     102,   103,   104,   105,    -1,    -1,   108,   109,    -1,   111,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    50,    -1,    52,
      -1,    -1,    -1,    56,    57,    58,    59,    60,    61,    -1,
      -1,    64,    65,    66,    -1,    -1,    69,    -1,    -1,    72,
      -1,    74,    75,    -1,    -1,    -1,    -1,    -1,    81,    82,
      83,    -1,    -1,    -1,    -1,    88,    -1,    90,    -1,    92,
      -1,    -1,    -1,    -1,    97,    98,    -1,    -1,   101,   102,
     103,   104,   105,    -1,    -1,   108,   109,    -1,   111,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    50,    -1,    52,    -1,
      -1,    -1,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    97,    -1,    -1,    -1,   101,   102,   103,
     104,   105,    -1,    -1,   108,    -1,    -1,   111,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    60,    61,    -1,    -1,    64,
      -1,    66,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    -1,    90,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    98,    -1,    -1,   101,    -1,    -1,   104,
      -1,    -1,    -1,    -1,   109,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    50,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    60,    61,    -1,    -1,    64,    -1,    66,    -1,
      -1,    69,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,
      -1,    -1,    53,    81,    -1,     7,    -1,    -1,    -1,    -1,
      88,    62,    90,    64,    92,    66,    -1,    -1,    69,    70,
      98,    -1,    -1,   101,    75,    -1,   104,    -1,    79,    -1,
      81,   109,    -1,    -1,    -1,    -1,    -1,    88,    -1,    90,
      91,    -1,    -1,    94,    95,    96,    -1,    98,    99,    -1,
      -1,    53,   103,    -1,     7,    -1,   107,    -1,   109,   110,
      62,    -1,    64,    -1,    66,    -1,    -1,    69,    -1,    -1,
      -1,    -1,    -1,    75,    -1,    -1,    -1,    79,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,    90,    91,
      -1,    -1,    94,    95,    96,    -1,    98,    99,    -1,    -1,
      53,   103,    -1,     7,    -1,   107,    -1,   109,   110,    62,
      -1,    64,    -1,    66,    -1,    -1,    69,    -1,    -1,    -1,
      -1,    -1,    75,    -1,    -1,    -1,    79,    -1,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    90,    91,    -1,
      -1,    94,    95,    96,    -1,    98,    99,    -1,    -1,    -1,
     103,    -1,     7,    -1,   107,    -1,   109,   110,    62,    -1,
      64,    -1,    66,    -1,    -1,    69,    70,    -1,    -1,    -1,
      -1,    75,    -1,    -1,    -1,    79,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    -1,    90,    91,    -1,    -1,
      94,    95,    96,    -1,    98,    99,    -1,    -1,    -1,   103,
      -1,    -1,    -1,   107,    -1,   109,   110,    62,    -1,    64,
      -1,    66,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    -1,    79,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    -1,    90,    91,    -1,    -1,    94,
      95,    96,    -1,    98,    99,    -1,    -1,    -1,   103,    -1,
      -1,    -1,   107,    -1,   109,   110,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    49,    50,    -1,    52,    53,    -1,    -1,    56,
      57,    58,    59,    60,    61,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    -1,    44,   104,    -1,    -1,
      -1,    -1,    50,    -1,    52,    -1,    -1,    -1,    56,    57,
      58,    59,    60,    61,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,    -1,    44,   104,    -1,    -1,    48,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    60,    61,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   101,    -1,    44,   104,    -1,    -1,    48,    -1,
      50,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      60,    61,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   101,    -1,    44,   104,    -1,    -1,    -1,    -1,    50,
      51,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,
      61,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    -1,    44,   104,    -1,    -1,    -1,    -1,    50,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,
      -1,    44,   104,    -1,    -1,    -1,    -1,    50,    51,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    60,    61,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,
      44,   104,    -1,    -1,    -1,    -1,    50,    51,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    60,    61,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    44,
     104,    -1,    -1,    -1,    -1,    50,    51,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    60,    61,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    44,   104,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,    -1,    44,   104,    -1,
      -1,    -1,    -1,    50,    51,    -1,    -1,    -1,    -1,    56,
      57,    58,    59,    60,    61,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    -1,    44,   104,    -1,    -1,
      -1,    -1,    50,    51,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    60,    61,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    30,    -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,    -1,    44,   104,    -1,    -1,    30,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    60,    61,    44,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,
      61,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    13,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   101,    -1,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    -1,    -1,   104,    -1,    -1,    -1,    -1,    50,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,
      -1,    -1,   104
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    48,    62,    70,    79,    86,    89,    91,    93,    94,
      95,    96,    99,   103,   107,   110,   114,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   178,     7,
     115,   115,   127,   128,   129,   115,   127,     0,   132,   134,
     137,   131,   132,    70,    89,   139,    78,    85,   141,   145,
     146,    47,    48,    52,    78,   179,   180,    47,    48,   132,
     115,   115,   123,   124,   127,   123,   125,   147,    52,   148,
     142,   146,   148,    14,   115,    53,    64,    66,    69,    75,
      81,    88,    90,    98,   109,   117,   118,   119,   120,   121,
     122,   123,   126,   127,   138,   152,   160,   181,   182,   183,
     184,   125,    49,   180,   143,   145,   146,   179,   180,    49,
      53,    99,   128,   138,   140,   149,   150,   151,   152,   159,
     160,   169,   170,   173,   148,   148,    48,   115,   153,   154,
     155,   161,    54,    54,    54,   117,    48,    53,   182,   125,
     148,   144,   146,   148,   180,   125,    52,   185,    50,   173,
      53,   150,    48,   168,   185,   106,   166,   171,    50,    48,
      49,    17,    54,    54,    55,    55,    55,   153,   161,   148,
     148,     1,     3,     4,     5,     6,     8,     9,    10,    13,
      48,    50,    53,    56,    57,    58,    59,    60,    61,    65,
      72,    74,    82,    83,    92,    97,   101,   102,   103,   104,
     105,   108,   111,   115,   116,   117,   127,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   199,
     205,   208,   211,   235,   236,   237,   238,   242,   243,   244,
     245,   246,   247,   251,   252,   253,   255,   259,   260,   261,
     262,   263,   264,   266,   267,   282,   283,   174,   175,   166,
     172,   124,   167,    52,   176,   176,   162,   163,   115,   154,
      11,    12,    30,    44,    50,    52,   127,   156,   157,   253,
     260,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   285,    55,    55,    48,    48,   127,   259,   261,
     265,   265,   285,    50,    50,    50,    48,   115,    48,   115,
     118,   123,   124,    48,   285,    47,    50,    50,    48,   285,
     185,    46,   153,    50,    54,    53,   187,    48,    48,   209,
      50,    50,    50,    47,    54,    10,    13,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    43,   284,
      51,   117,   164,   165,   176,   176,    49,    53,   101,   104,
     177,   186,    51,   164,   265,   265,   265,   265,   118,   127,
     285,    49,    53,   156,   158,    54,    14,    15,    16,    11,
      12,    40,    41,    42,    32,    33,    35,    36,    87,    31,
      34,    38,    39,    37,    28,    29,    45,    51,   285,   285,
     285,    48,    48,    54,   256,   257,   256,    50,    48,   115,
     285,   285,    48,    68,    80,   248,   249,   250,   190,    51,
     254,   285,   285,   190,   206,    48,   189,   195,   239,   241,
     285,   115,   285,   281,   155,    49,    51,   124,    50,    50,
      53,   186,    53,    51,    51,    54,   258,    54,   258,    51,
      53,    49,    53,   265,   265,   265,   270,   270,   271,   271,
     271,   272,   272,   272,   272,   118,   122,   273,   273,   274,
     275,   276,   277,   278,   285,    51,    51,    51,   285,    54,
     257,   258,   258,    51,   254,    50,    51,    51,    50,   185,
     249,   250,    49,    51,    55,   236,   285,   223,   226,   229,
     232,    48,    49,    51,    50,    55,   165,    51,   254,    51,
     254,    53,   265,    55,    51,    54,    51,   268,   156,    46,
      55,    51,    51,   254,    52,   200,   185,   165,   285,    50,
      51,   285,   285,   230,   233,   212,   214,   217,   220,   195,
     197,    51,   254,    48,    51,    48,    51,   265,    55,   268,
     280,    51,    53,    67,    73,   201,   202,   203,   204,    51,
     285,   207,   224,   227,    48,    48,   285,   285,   218,   221,
     190,    51,    48,    48,   285,   286,    46,    53,   202,   203,
      53,   186,   204,   185,   210,   190,    48,    48,   240,   241,
      51,   213,   215,    48,    48,    76,    46,    53,    51,   240,
      51,    51,   234,    48,    48,   240,    51,   198,    48,    51,
     228,   231,   190,    51,   240,    51,   222,   190,   225,   190,
     190,   190,    51,   219,   190,   190,   216,   190,   190
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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

/* Prevent warnings from -Wmissing-prototypes.  */
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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

/* Line 1455 of yacc.c  */
#line 227 "parse.y"
    {	(yyval.status) = (yyvsp[(1) - (1)].status);
			printf("COMPILATION OVER: %d errors found\n", error_count);
			printf("\n\n");
			print();
			fclose(fp);
		}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 237 "parse.y"
    {
			(yyval.sval) = strdup(yylval.sval);
		}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 243 "parse.y"
    {
							fprintf(fp, "subu $sp, $sp, 4 #INTEGERLITERAL\n");
							currentelement()->loc+=4;
							if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
							
							
							fprintf(fp, "li $t0, %d\n", (yyvsp[(1) - (1)].ival));
							fprintf(fp, "sw $t0, 0($sp)\n");
							
							(yyval.attr) = makePrimNode(string(), KLITERAL, TINT, vector<int>(), currentelement()->loc, ANONE, NULL);
							
						}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 258 "parse.y"
    {
							fprintf(fp, "subu $sp, $sp, 4 #FLOATLITERAL\n");
							currentelement()->loc+=4;
							if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
							fprintf(fp, "li.s $f0, %f\n", (yyvsp[(1) - (1)].fval));
							fprintf(fp, "s.s $f0, ($sp)\n");
							
							(yyval.attr) = makePrimNode(string(), KLITERAL, TFLOAT, vector<int>(), currentelement()->loc, ANONE, NULL);
							
						}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 271 "parse.y"
    {
							printf("error at line %d: Long type not supported\n", line_number);
							ehere();
							int hi = (int)((yyvsp[(1) - (1)].lval) >> 32);
							int lo = (int)((yyvsp[(1) - (1)].lval) & ((1<<32) -1));
							fprintf(fp, "subu $sp, $sp, 8 #LONGLITERAL\n");
							currentelement()->loc+=8;
							if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
							fprintf(fp, "li $t0, %d\n", hi);
							fprintf(fp, "sw $t0, 0($sp)\n");
							fprintf(fp, "li $t0, %d\n", lo);
							fprintf(fp, "sw $t0, 4($sp)\n");
							
							(yyval.attr) = makePrimNode(string(), KLITERAL, TLONG, vector<int>(), currentelement()->loc, ANONE, NULL);
							
						}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 290 "parse.y"
    {
							printf("error at line %d: Double type not supported\n", line_number);
							ehere();
							fprintf(fp, "subu $sp, $sp, 8 #DOUBLELITERAL\n");
							currentelement()->loc+=8;
							if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
							fprintf(fp, "li.d $f0, %lf\n", (yyvsp[(1) - (1)].dval));
							fprintf(fp, "sdc1 $f0, 0($sp)\n");
													
							(yyval.attr) = makePrimNode(string(), KLITERAL, TDOUBLE, vector<int>(), currentelement()->loc, ANONE, NULL);
							
						}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 305 "parse.y"
    {
							
							fprintf(fp, "subu $sp, $sp, 4 #BTRUE\n");
							currentelement()->loc+=4;
							if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
							fprintf(fp, "li $t0, 1\n");
							fprintf(fp, "sw $t0, 0($sp)\n");
							
							(yyval.attr) = makePrimNode(string(), KLITERAL, TBOOLEAN, vector<int>(), currentelement()->loc, ANONE, NULL);
							
						}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 319 "parse.y"
    {
							fprintf(fp, "subu $sp, $sp, 4 #BFALSE\n");
							currentelement()->loc+=4;
							if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
							fprintf(fp, "li $t0, 0\n");
							fprintf(fp, "sw $t0, 0($sp)\n");
							
							(yyval.attr) = makePrimNode(string(), KLITERAL, TBOOLEAN, vector<int>(), currentelement()->loc, ANONE, NULL);
							
						}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 332 "parse.y"
    {
							fprintf(fp, "subu $sp, $sp, 4 #CHARACTERLITERAL\n");
							currentelement()->loc+=4;
							if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
							fprintf(fp, "li $t0, %d\n", (yyvsp[(1) - (1)].cval));
							fprintf(fp, "sw $t0, 0($sp)\n");
							
							(yyval.attr) = makePrimNode(string(), KLITERAL, TCHAR, vector<int>(), currentelement()->loc, ANONE, NULL);
							
						}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 345 "parse.y"
    {
							fprintf(fp, "\t.data #STRINGLITERAL\n");
							char* lab = newlabel();
							fprintf(fp, "%s:", lab);
							fprintf(fp, "\t.asciiz %s\n", (yyvsp[(1) - (1)].sval));
							fprintf(fp, "\t.text\n");
							fprintf(fp, "subu $sp, $sp, 4\n");
							currentelement()->loc+=4;
							if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
							fprintf(fp, "la $t0, %s\n", lab);
							fprintf(fp, "sw $t0, 0($sp)\n");
							
							(yyval.attr) = makePrimNode(string(), KLITERAL, TSTRING, vector<int>(), currentelement()->loc, ANONE, NULL);
							
						}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 363 "parse.y"
    {
							fprintf(fp, "subu $sp, $sp, 4 #NULLLITERAL\n");
							currentelement()->loc+=4;
							if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
							fprintf(fp, "li $t0, 0\n");
							fprintf(fp, "sw $t0, 0($sp)\n");
							
							element* e = makePrimNode(string(), KLITERAL, TVOID, vector<int>(), currentelement()->loc, ANONE, NULL);
							e->amode = REFERENCE;
						}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 379 "parse.y"
    {
							(yyval.attr) = (yyvsp[(1) - (1)].attr);
						}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 383 "parse.y"
    {
							(yyval.attr) = (yyvsp[(1) - (1)].attr);
						}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 389 "parse.y"
    {
							(yyval.attr) = (yyvsp[(1) - (1)].attr);
						}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 393 "parse.y"
    {
							(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
						}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 396 "parse.y"
    {
							(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TVOID, vector<int>(), NULL, ANONE, NULL);
						}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 403 "parse.y"
    {
							(yyval.attr) = (yyvsp[(1) - (1)].attr);
						}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 407 "parse.y"
    {
							(yyval.attr) = (yyvsp[(1) - (1)].attr);
						}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 414 "parse.y"
    {
							(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TBYTE, vector<int>(), NULL, ANONE, NULL);
						}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 418 "parse.y"
    {	
							(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TSHORT, vector<int>(), NULL, ANONE, NULL);
						}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 422 "parse.y"
    {	
							(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TINT, vector<int>(), NULL, ANONE, NULL);
						}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 426 "parse.y"
    {	
							(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TLONG, vector<int>(), NULL, ANONE, NULL);
						}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 430 "parse.y"
    {	
							(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TCHAR, vector<int>(), NULL, ANONE, NULL);
						}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 437 "parse.y"
    {	
							(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TFLOAT, vector<int>(), NULL, ANONE, NULL);
						}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 441 "parse.y"
    {	
							(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TDOUBLE, vector<int>(), NULL, ANONE, NULL);
						}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 448 "parse.y"
    {
							(yyval.attr) = (yyvsp[(1) - (1)].attr);
						}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 451 "parse.y"
    {
							(yyval.attr)= (yyvsp[(1) - (1)].attr);
						}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 458 "parse.y"
    {
							(yyval.attr) = findtype(current, (yyvsp[(1) - (1)].name), KCLASS);
						}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 465 "parse.y"
    {
							(yyval.attr) = (yyvsp[(1) - (1)].attr);
						}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 472 "parse.y"
    {
							//Not implemented
						}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 479 "parse.y"
    {
							(yyvsp[(1) - (3)].attr)->dimensions.push_back(0);
							(yyval.attr) = (yyvsp[(1) - (3)].attr);
						}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 484 "parse.y"
    {
							element* qualifiedtype = findtype(current, (yyvsp[(1) - (3)].name));
							struct element* newnode = makeRefNode(string(), KCLASS, qualifiedtype, vector<int>(), NULL, ANONE, NULL, NULL, NULL);
							newnode->dimensions.push_back(0);
							(yyval.attr) = newnode;
						}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 491 "parse.y"
    {
							(yyvsp[(1) - (3)].attr)->dimensions.push_back(0);
							(yyval.attr) = (yyvsp[(1) - (3)].attr);
						}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 499 "parse.y"
    {
							(yyval.name)= (yyvsp[(1) - (1)].name);
						}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 503 "parse.y"
    {
							(yyval.name)= (yyvsp[(1) - (1)].name);
						}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 510 "parse.y"
    {
							struct namenode * newnode = new namenode();
							newnode->name = string((yyvsp[(1) - (1)].sval));
							newnode->next = NULL;
							(yyval.name) = newnode;
						}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 519 "parse.y"
    {
							namenode* iterator = (yyvsp[(1) - (3)].name);
							while(iterator->next != NULL) iterator = iterator->next;
							struct namenode * newnode = new namenode();
							newnode->name = string((yyvsp[(3) - (3)].sval));
							newnode->next = NULL;
							iterator->next = newnode;
							(yyval.name) = (yyvsp[(1) - (3)].name);
						}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 531 "parse.y"
    {	/*Not Implemented*/	}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 532 "parse.y"
    {	/*Not Implemented*/	}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 533 "parse.y"
    {	/*Not Implemented*/	}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 534 "parse.y"
    {	/*Not Implemented*/	}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 535 "parse.y"
    {	/*Not Implemented*/	}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 536 "parse.y"
    {	/*Not Implemented*/	}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 537 "parse.y"
    {	(yyval.status) = (yyvsp[(1) - (1)].status);	}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 538 "parse.y"
    {	(yyval.status) = OKAY;	}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 549 "parse.y"
    {
							(yyval.status) = (yyvsp[(1) - (1)].status);
						}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 553 "parse.y"
    {
							if((yyvsp[(1) - (2)].status)==ERROR || (yyvsp[(2) - (2)].status)==ERROR){
								here(2);
								(yyval.status) = ERROR;
								here(1);
							}
							else (yyval.status) = OKAY;
						}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 582 "parse.y"
    {
						(yyval.status) = (yyvsp[(1) - (1)].status);
					}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 585 "parse.y"
    {	/*Not Implemented*/	}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 587 "parse.y"
    {
						(yyval.status) = OKAY;
					}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 594 "parse.y"
    {
						(yyval.ival) = (yyvsp[(1) - (1)].ival);
					}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 597 "parse.y"
    {	/*	Not implemented	*/	}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 601 "parse.y"
    {	(yyval.ival) = yylval.ival;	}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 602 "parse.y"
    {	(yyval.ival) = yylval.ival;	}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 603 "parse.y"
    {	(yyval.ival) = yylval.ival;	}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 604 "parse.y"
    {	/* Not implemented	*/ 	}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 605 "parse.y"
    {	/* Not implemented	*/ 	}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 606 "parse.y"
    {	/* Not implemented	*/ 	}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 607 "parse.y"
    {	/* Not implemented	*/ 	}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 608 "parse.y"
    {	/* Not implemented	*/ 	}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 609 "parse.y"
    {	/* Not implemented	*/ 	}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 610 "parse.y"
    {	/* Not implemented	*/ 	}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 617 "parse.y"
    {

		if(alreadypresent((yyvsp[(2) - (2)].sval))){
			printf("error at line #%d: %s already declared\n", line_number, (yyvsp[(2) - (2)].sval));
			current->symtbl.erase(string((yyvsp[(2) - (2)].sval)));
			ehere(0);
		}	
		element* newelem = makeRefNode(string((yyvsp[(2) - (2)].sval)), KCLASS, NULL, vector<int>(), 0, APUBLIC, NULL, NULL, NULL);
		current->symtbl.insert({string((yyvsp[(2) - (2)].sval)), newelem});
		scope* newscope = createScope(string((yyvsp[(2) - (2)].sval)), current, newelem);
		newelem->desc = newscope;
		current = newscope;
	}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 631 "parse.y"
    {
		revertscope();
		(yyval.status) = (yyvsp[(4) - (4)].status);
	}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 636 "parse.y"
    {
		if(alreadypresent((yyvsp[(2) - (3)].sval))){
			printf("error at line #%d: %s already declared\n", line_number, (yyvsp[(2) - (3)].sval));
			current->symtbl.erase(string((yyvsp[(2) - (3)].sval)));
			ehere(0);
		}	
										
		element* newelem = makeRefNode(string((yyvsp[(2) - (3)].sval)), KCLASS, NULL, vector<int>(), (yyvsp[(3) - (3)].attr)->loc, APUBLIC, NULL, (yyvsp[(3) - (3)].attr), NULL);
		current->symtbl.insert({string((yyvsp[(2) - (3)].sval)), newelem});
		scope* newscope = createScope(string((yyvsp[(2) - (3)].sval)), current, newelem);
		newelem->desc = newscope;
		current = newscope;
		}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 650 "parse.y"
    {
			//printsymtbl(current->symtbl);
			revertscope();
			
			(yyval.status) = (yyvsp[(5) - (5)].status);
		}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 657 "parse.y"
    {	/* Not implemented	*/ 	}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 658 "parse.y"
    {	/* Not implemented	*/ 	}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 660 "parse.y"
    {
		accessmod mod;
		if((yyvsp[(1) - (3)].ival)==PUBLIC){
			mod = APUBLIC;
		}else if((yyvsp[(1) - (3)].ival)==PROTECTED){
			mod = APROTECTED;
		}else if((yyvsp[(1) - (3)].ival)==PRIVATE){
			mod = APRIVATE;
		}
		if(alreadypresent((yyvsp[(3) - (3)].sval))){
			printf("error at line #%d: %s already declared\n", line_number, (yyvsp[(3) - (3)].sval));
			current->symtbl.erase(string((yyvsp[(3) - (3)].sval)));
			ehere(0);
		}	
				
		element* newelem = makeRefNode(string((yyvsp[(3) - (3)].sval)), KCLASS, NULL, vector<int>(), 0, mod, NULL, NULL, NULL);
		current->symtbl.insert({string((yyvsp[(3) - (3)].sval)), newelem});
		scope* newscope = createScope(string((yyvsp[(3) - (3)].sval)), current, newelem);
		newelem->desc = newscope;
		current = newscope;
	}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 682 "parse.y"
    {
		revertscope();
		(yyval.status) = (yyvsp[(5) - (5)].status);
	}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 687 "parse.y"
    {
		accessmod mod;
		if((yyvsp[(1) - (4)].ival)==PUBLIC){
			mod = APUBLIC;
		}else if((yyvsp[(1) - (4)].ival)==PROTECTED){
			mod = APROTECTED;
		}else if((yyvsp[(1) - (4)].ival)==PRIVATE){
			mod = APRIVATE;
		}
		if(alreadypresent((yyvsp[(3) - (4)].sval))){
			printf("error at line #%d: %s already declared\n", line_number, (yyvsp[(3) - (4)].sval));
			current->symtbl.erase(string((yyvsp[(3) - (4)].sval)));
			ehere(0);
		}
		element* newelem = makeRefNode(string((yyvsp[(3) - (4)].sval)), KCLASS, NULL, vector<int>(), (yyvsp[(4) - (4)].attr)->loc, mod, NULL, (yyvsp[(4) - (4)].attr), NULL);
		current->symtbl.insert({string((yyvsp[(3) - (4)].sval)), newelem});
		scope* newscope = createScope(string((yyvsp[(3) - (4)].sval)), current, newelem);
		newelem->desc = newscope;
		current = newscope;
	}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 708 "parse.y"
    {
		revertscope();
		(yyval.status) = (yyvsp[(6) - (6)].status);
	}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 712 "parse.y"
    {	/* Not implemented	*/ 	}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 713 "parse.y"
    {	/* Not implemented	*/ 	}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 717 "parse.y"
    {
							(yyval.attr) = (yyvsp[(2) - (2)].attr);
						}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 733 "parse.y"
    {
			(yyval.status) = OKAY;
		}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 737 "parse.y"
    {
			(yyval.status) = (yyvsp[(2) - (3)].status);
		}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 744 "parse.y"
    {
			(yyval.status) = (yyvsp[(1) - (1)].status);
		}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 748 "parse.y"
    {
			if((yyvsp[(1) - (2)].status)==ERROR || (yyvsp[(2) - (2)].status) == ERROR){
				(yyval.status) = ERROR;
				here(2);
			}
			else (yyval.status)= OKAY;
		}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 759 "parse.y"
    {
			(yyval.status) = (yyvsp[(1) - (1)].status);
		}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 762 "parse.y"
    {(yyval.status) = OKAY;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 764 "parse.y"
    {
			(yyval.status) = (yyvsp[(1) - (1)].status);
		}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 770 "parse.y"
    {(yyval.status) = (yyvsp[(1) - (1)].status);}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 771 "parse.y"
    {(yyval.status) = (yyvsp[(1) - (1)].status);}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 773 "parse.y"
    {
			printf("error at line %d: nested classes not implemented\n", line_number);
			ehere();
			(yyval.status) = (yyvsp[(1) - (1)].status);
		}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 783 "parse.y"
    {	
			bool ret = coercedlist( (yyvsp[(2) - (3)].dlist), (yyvsp[(1) - (3)].attr));
			listofdeclarators* e = (yyvsp[(2) - (3)].dlist);
			while(e!=NULL){
				e->elem->kind = KVARIABLE;
				e->elem->mod = ANONE;
				
				currentelement()->loc += sizeofelement(e->elem);
				e->elem->loc = currentelement()->loc;
				fprintf(stderr, "FieldDeclaration %s loc=%d\n", e->elem->name.c_str(), currentelement()->loc);
				current->symtbl.insert({string(e->elem->name), e->elem});
				e=e->next;
			}
			(yyval.status) = ret;
		}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 800 "parse.y"
    {
			accessmod mod;
			if((yyvsp[(1) - (4)].ival)==PUBLIC){
				mod = APUBLIC;
			}else if((yyvsp[(1) - (4)].ival)==PROTECTED){
				mod = APROTECTED;
			}else if((yyvsp[(1) - (4)].ival)==PRIVATE){
				mod = APRIVATE;
			}
			(yyvsp[(2) - (4)].attr)->mod = mod;
			bool ret = coercedlist( (yyvsp[(3) - (4)].dlist), (yyvsp[(2) - (4)].attr));
			listofdeclarators* e = (yyvsp[(3) - (4)].dlist);
			while(e!=NULL){
				e->elem->kind = KVARIABLE;
				e->elem->mod = mod;
				currentelement()->loc += sizeofelement(e->elem);
				e->elem->loc = currentelement()->loc;
				fprintf(stderr, "FieldDeclaration %s loc=%d\n", e->elem->name.c_str(), currentelement()->loc);
				current->symtbl.insert({string(e->elem->name), e->elem});
				e=e->next;
			}
			(yyval.status) = ret;
		}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 827 "parse.y"
    {
			(yyval.dlist) = (yyvsp[(1) - (1)].dlist);
		}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 831 "parse.y"
    {
			listofdeclarators* list = (yyvsp[(1) - (3)].dlist);
			while(list->next!=NULL) list = list->next;
			list->next = (yyvsp[(3) - (3)].dlist);
			(yyval.dlist) = (yyvsp[(1) - (3)].dlist);
		}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 842 "parse.y"
    {
			listofdeclarators* newlist= new listofdeclarators();
			newlist->elem = (yyvsp[(1) - (1)].attr);
			newlist->equals = NULL;
			newlist->next = NULL;
			(yyval.dlist) = newlist;

		}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 851 "parse.y"
    {
			if(!iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				printf("error at line %d: incompatible types: \n",line_number);
				listofdeclarators* newlist= new listofdeclarators();
				newlist->elem = makeIllegalNode();
				newlist->equals = (yyvsp[(3) - (3)].attr);
				newlist->next = NULL;
				(yyval.dlist) = newlist;
			}else{
				coerce((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr));
				listofdeclarators* newlist= new listofdeclarators();
				newlist->elem = (yyvsp[(1) - (3)].attr);
				newlist->equals = (yyvsp[(3) - (3)].attr);
				newlist->next = NULL;
				(yyval.dlist) = newlist;
				
			}
		}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 873 "parse.y"
    {
			element* newelem = makePrimNode(string((yyvsp[(1) - (1)].sval)), KUNKNOWN, TUNKNOWN, vector<int>(), NULL, ANONE, NULL);
			if(alreadypresent((yyvsp[(1) - (1)].sval))){
				printf("error at line #%d: %s already declared\n", line_number, (yyvsp[(1) - (1)].sval));
				current->symtbl.erase(string((yyvsp[(1) - (1)].sval)));
				current->symtbl.insert({string(newelem->name), newelem});
				ehere(0);
			}
			//current->symtbl.insert({string($1), newelem});
			(yyval.attr) = newelem;
		}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 885 "parse.y"
    {
			(yyvsp[(1) - (3)].attr) -> dimensions.push_back(0);
			(yyval.attr) = (yyvsp[(1) - (3)].attr);
		}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 893 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 897 "parse.y"
    {
			printf("error at line %d: Array initializers not implemented\n", line_number);
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 906 "parse.y"
    {
			element* e = copyelement((yyvsp[(2) - (3)].elist)->elem);
			int i = 0;
			listofelements* it = (yyvsp[(2) - (3)].elist);
			while(it!=NULL){
				it = it->next;
				i++;
			}
			e->dimensions.insert(e->dimensions.begin(), i);
			e->arguments = (yyvsp[(2) - (3)].elist);
			(yyval.attr) = e;
		}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 919 "parse.y"
    {
			(yyval.attr) = NULL;
		}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 923 "parse.y"
    {
			(yyval.attr) = NULL;
		}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 930 "parse.y"
    {
			listofelements* newlist = new listofelements();
			newlist ->elem = (yyvsp[(1) - (1)].attr);
			newlist->next=NULL;
			(yyval.elist) = newlist;
		}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 937 "parse.y"
    {
			//if(equal($1->dimensions.begin() +1, $1->dimensions.end(), $3->dimensions.begin()))
			if(iscoercible((yyvsp[(1) - (3)].elist)->elem, (yyvsp[(3) - (3)].attr)) || iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].elist)->elem))
			{
				listofelements* e = (yyvsp[(1) - (3)].elist);
				while(e->next!=NULL) e = e->next;
				listofelements* newelem = new listofelements();
				e->next=newelem;
				newelem ->elem = (yyvsp[(3) - (3)].attr);
				newelem->next=NULL;
				(yyval.elist) = (yyvsp[(1) - (3)].elist);
			}else{
				printf("error at line #%d: incompatible types\n", line_number);
				listofelements* newlist = new listofelements();
				newlist ->elem = makeIllegalNode();
				newlist->next=NULL;
				(yyval.elist) = newlist;
			}
		}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 967 "parse.y"
    {
			//if(strcmp("main", $1->name.c_str())==0){
				fprintf(fp, "jr $ra\n");
			//}
			revertscope();
			if((yyvsp[(1) - (2)].attr) == NULL || (yyvsp[(2) - (2)].status) == ERROR){
				(yyval.status) = ERROR;
				here(3);
			}
			else (yyval.status) = OKAY;
		}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 982 "parse.y"
    {
			if((yyvsp[(1) - (2)].attr)->kind==KPRIMITIVE){
				(yyvsp[(2) - (2)].attr)->kind = KPRIMFUNCTION;
				(yyvsp[(2) - (2)].attr)->pdtype = (yyvsp[(1) - (2)].attr)->pdtype;
				(yyvsp[(2) - (2)].attr)->mod = APRIVATE;
				(yyval.attr) = (yyvsp[(2) - (2)].attr);
			}else if((yyvsp[(1) - (2)].attr)->kind==KCLASS){
				(yyvsp[(2) - (2)].attr)->kind = KREFFUNCTION;
				(yyvsp[(2) - (2)].attr)->rdtype = (yyvsp[(1) - (2)].attr)->rdtype;
				(yyvsp[(2) - (2)].attr)->mod = APRIVATE;
				(yyval.attr) = (yyvsp[(2) - (2)].attr);
			}else{
				printf("line #%d: fatal error\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}	
		}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 999 "parse.y"
    {
			accessmod mod;
			if((yyvsp[(1) - (3)].ival)==PUBLIC){
				mod = APUBLIC;
			}else if((yyvsp[(1) - (3)].ival)==PROTECTED){
				mod = APROTECTED;
			}else if((yyvsp[(1) - (3)].ival)==PRIVATE){
				mod = APRIVATE;
			}
			if((yyvsp[(2) - (3)].attr)->kind==KPRIMITIVE){
				(yyvsp[(3) - (3)].attr)->kind = KPRIMFUNCTION;
				(yyvsp[(3) - (3)].attr)->pdtype = (yyvsp[(2) - (3)].attr)->pdtype;
				(yyvsp[(3) - (3)].attr)->mod = mod;
				(yyval.attr) = (yyvsp[(3) - (3)].attr);
			}else if((yyvsp[(2) - (3)].attr)->kind==KCLASS){
				(yyvsp[(3) - (3)].attr)->kind = KREFFUNCTION;
				(yyvsp[(3) - (3)].attr)->rdtype = (yyvsp[(2) - (3)].attr)->rdtype;
				(yyvsp[(3) - (3)].attr)->mod = mod;
				(yyval.attr) = (yyvsp[(3) - (3)].attr);
			}else{
				printf("line #%d: fatal error\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1033 "parse.y"
    {	
			
			if(strcmp((yyvsp[(1) - (2)].sval), "main")==0){
				fprintf(fp, "main:\n");
				fprintf(fp, "move $fp, $sp\n");
				fprintf(fp, "subu $sp, $fp, 4\n");
			}
			fprintf(fp, "%s%s:\n", current->elem->name.c_str(), (yyvsp[(1) - (2)].sval));
			element* func = makePrimNode(string((yyvsp[(1) - (2)].sval)), KPRIMFUNCTION, TUNKNOWN, vector<int>(), 4, APUBLIC, NULL);
			
			scope* newscope = createScope(string((yyvsp[(1) - (2)].sval)), current, func);
			func->desc = newscope;
			if(alreadypresent((yyvsp[(1) - (2)].sval))){
				printf("error at line #%d: method %s already declared\n", line_number, (yyvsp[(1) - (2)].sval));
				current->symtbl.erase(string((yyvsp[(1) - (2)].sval)));
				ehere(0);
			}	
				
			if(PDEBUG) printf("%d inserting method %s in %s's table\n", line_number, (yyvsp[(1) - (2)].sval), current->lexeme.c_str());
			current->symtbl.insert({string((yyvsp[(1) - (2)].sval)), func});	
			current = newscope;	
		}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1056 "parse.y"
    {
			(yyval.attr) = currentelement();
		}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1060 "parse.y"
    {	
			if(strcmp((yyvsp[(1) - (2)].sval), "main")==0){
				fprintf(fp, "main:\n");
				fprintf(fp, "move $fp, $sp\n");
				fprintf(fp, "subu $sp, $fp, 4\n");
			}
			fprintf(fp, "%s%s:\n", current->elem->name.c_str(), (yyvsp[(1) - (2)].sval));
			
			element* func = makePrimNode(string((yyvsp[(1) - (2)].sval)), KPRIMFUNCTION, TUNKNOWN, vector<int>(), 4, APUBLIC, NULL);
			
			scope* newscope = createScope(string((yyvsp[(1) - (2)].sval)), current, func);
			func->desc = newscope;
			if(alreadypresent((yyvsp[(1) - (2)].sval))){
				printf("error at line #%d: method %s already declared\n", line_number, (yyvsp[(1) - (2)].sval));
				current->symtbl.erase(string((yyvsp[(1) - (2)].sval)));
				ehere(0);
			}	
				
			if(PDEBUG) printf("%d inserting method %s in %s's table\n", line_number, (yyvsp[(1) - (2)].sval), current->lexeme.c_str());
			current->symtbl.insert({string((yyvsp[(1) - (2)].sval)), func});	
			current = newscope;
		}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1083 "parse.y"
    {
			listofelements* param = (yyvsp[(4) - (5)].elist);
			while(param!=NULL){
				currentelement()->loc += sizeofelement(param->elem);
				param->elem->loc = currentelement()->loc;
				current->symtbl.insert({string(param->elem->name), param->elem});
				if(PDEBUG) printf("%d inserting %s in %s's argumentlist\n", line_number, param->elem->name.c_str(), current->lexeme.c_str());
				param= param->next;
			}
			currentelement()->arguments = (yyvsp[(4) - (5)].elist);
			(yyval.attr) = currentelement();
		}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1100 "parse.y"
    {
			listofelements* param = new listofelements();
			param->elem = (yyvsp[(1) - (1)].attr);
			param->next = NULL;
			(yyval.elist) = param;
		}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1107 "parse.y"
    {
			listofelements* param = new listofelements();
			param->elem = (yyvsp[(3) - (3)].attr);
			param->next = NULL;
			listofelements* list = (yyvsp[(1) - (3)].elist); 
			while(list->next != NULL) list = list->next;
			list->next = param;
			(yyval.elist) = (yyvsp[(1) - (3)].elist);
		}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1120 "parse.y"
    {
			if((yyvsp[(1) - (2)].attr)->kind==KPRIMITIVE){
				(yyvsp[(2) - (2)].attr)->kind = KVARIABLE;
				(yyvsp[(2) - (2)].attr)->pdtype = (yyvsp[(1) - (2)].attr)->pdtype;
				(yyval.attr) = (yyvsp[(2) - (2)].attr);
			}else if((yyvsp[(1) - (2)].attr)->kind==KCLASS){
				(yyvsp[(2) - (2)].attr)->kind = KOBJECT;
				(yyvsp[(2) - (2)].attr)->rdtype = (yyvsp[(1) - (2)].attr)->rdtype;
				(yyval.attr) = (yyvsp[(2) - (2)].attr);
			}else{
				printf("line #%d: fatal error\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}	
		}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1147 "parse.y"
    {
			(yyval.status) = (yyvsp[(1) - (1)].status);
		}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1151 "parse.y"
    {
			(yyval.status) = OKAY;
		}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1162 "parse.y"
    {
			fprintf(fp, "%s%s:\n", currentelement()->name.c_str(), currentelement()->name.c_str());
		}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 1166 "parse.y"
    {
			revertscope();
			fprintf(fp, "jr $ra\n #%s%s constructor end\n", currentelement()->name.c_str(), currentelement()->name.c_str());
			if((yyvsp[(1) - (3)].attr) == NULL || (yyvsp[(3) - (3)].status) == ERROR){
				(yyval.status) = ERROR;
				here(4);
			}
			else (yyval.status) = OKAY;
		}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1176 "parse.y"
    {
			if((yyvsp[(1) - (2)].ival)==PUBLIC){
				(yyvsp[(2) - (2)].attr)->mod = APUBLIC;
			}else if((yyvsp[(1) - (2)].ival)==PROTECTED){
				(yyvsp[(2) - (2)].attr)->mod = APROTECTED;
			}else if((yyvsp[(1) - (2)].ival)==PRIVATE){
				(yyvsp[(2) - (2)].attr)->mod = APRIVATE;
			}
			fprintf(fp, "%s%s:\n", currentelement()->name.c_str(), currentelement()->name.c_str());
		}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1187 "parse.y"
    {
			revertscope();
			fprintf(fp, "jr $ra\n #%s%s constructor end\n", currentelement()->name.c_str(), currentelement()->name.c_str());
			if((yyvsp[(2) - (4)].attr) == NULL || (yyvsp[(4) - (4)].status)==ERROR){
				(yyval.status) = ERROR;
				here(5);
			}else (yyval.status) = OKAY;
		}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1195 "parse.y"
    {(yyval.status) = OKAY;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1196 "parse.y"
    {(yyval.status) = OKAY;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1201 "parse.y"
    {	
			scope* s = current;
			while(s!=NULL && s->elem->kind!= KCLASS) s= s->parent;
			if(s==NULL){
				printf("error at line #%d: constructor must be declared inside a class\n");
				ehere(998);
				here(999);
			}else if((yyvsp[(1) - (2)].name)->name != s->lexeme){
				printf("error at line #%d: constructor name doesn't match class name\n");
				ehere(996);
				here(997);
			}
			element* func = makePrimNode((yyvsp[(1) - (2)].name)->name, KCONSTRUCTOR, TUNKNOWN, vector<int>(), 4, APUBLIC, NULL);
			
			scope* newscope = createScope(string((yyvsp[(1) - (2)].name)->name), current, func);
			func->desc = newscope;
			if(alreadypresent((yyvsp[(1) - (2)].name)->name)){
				printf("error at line #%d: method %s already declared\n", line_number, (yyvsp[(1) - (2)].name)->name.c_str());
				current->symtbl.erase(string((yyvsp[(1) - (2)].name)->name));
				ehere(0);
			}	
				
			if(PDEBUG) printf("%d inserting method %s in %s's table\n", line_number, (yyvsp[(1) - (2)].name)->name.c_str(), current->lexeme.c_str());
			current->symtbl.insert({string((yyvsp[(1) - (2)].name)->name), func});	
			current = newscope;	
			element* _this = makeRefNode(string("this"), KOBJECT, current->parent->elem, vector<int>(), 4, ANONE, NULL, NULL, NULL);
			_this->amode = REFERENCE;
			current->symtbl.insert({string(_this->name), _this});	
		}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1231 "parse.y"
    {
			(yyval.attr) = currentelement();
		}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1235 "parse.y"
    {	
			scope* s = current;
			while(s!=NULL && s->elem->kind!= KCLASS) s= s->parent;
			if(s==NULL){
				printf("error at line #%d: constructor must be declared inside a class\n");
				ehere(998);
				here(999);
			}else if((yyvsp[(1) - (2)].name)->name != s->lexeme){
				printf("error at line #%d: constructor name doesn't match class name\n");
				ehere(996);
				here(997);
			}			
			element* func = makePrimNode(string((yyvsp[(1) - (2)].name)->name), KCONSTRUCTOR, TUNKNOWN, vector<int>(), 4, APUBLIC, NULL);
			
			scope* newscope = createScope(string((yyvsp[(1) - (2)].name)->name), current, func);
			func->desc = newscope;
			if(alreadypresent((yyvsp[(1) - (2)].name)->name)){
				printf("error at line #%d: method %s already declared\n", line_number, (yyvsp[(1) - (2)].name)->name.c_str());
				current->symtbl.erase(string((yyvsp[(1) - (2)].name)->name));
				ehere(0);
			}	
				
			if(PDEBUG) printf("%d inserting method %s in %s's table\n", line_number, (yyvsp[(1) - (2)].name)->name.c_str(), current->lexeme.c_str());
			current->symtbl.insert({string((yyvsp[(1) - (2)].name)->name), func});	
			current = newscope;
			element* _this = makeRefNode(string("this"), KOBJECT, current->parent->elem, vector<int>(), 4, ANONE, NULL, NULL, NULL);
			_this->amode = REFERENCE;
			current->symtbl.insert({string(_this->name), _this});	
		}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1265 "parse.y"
    {
			listofelements* param = (yyvsp[(4) - (5)].elist);
			while(param!=NULL){
				currentelement()->loc += sizeofelement(param->elem);
				param->elem->loc = currentelement()->loc;
				current->symtbl.insert({string(param->elem->name), param->elem});
				if(PDEBUG) printf("%d inserting %s in %s's argumentlist\n", line_number, param->elem->name.c_str(), current->lexeme.c_str());
				param= param->next;
			}
			currentelement()->arguments = (yyvsp[(4) - (5)].elist);
			(yyval.attr) = currentelement();
		}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1281 "parse.y"
    {
			(yyval.status) = OKAY;
		}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1286 "parse.y"
    {
			if((yyvsp[(2) - (3)].status) == OKAY){
				(yyval.status) = OKAY;
			}else (yyval.status) = ERROR;
			here(6);
		}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1294 "parse.y"
    {
			if((yyvsp[(2) - (3)].status) == OKAY){
				(yyval.status) = OKAY;
			}else (yyval.status) = ERROR;
			here(7);
		}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1303 "parse.y"
    {
			if((yyvsp[(2) - (4)].status) == OKAY && (yyvsp[(3) - (4)].status)==OKAY){
				(yyval.status) = OKAY;
			}else (yyval.status) = ERROR;
			here(8);
		}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1313 "parse.y"
    {
			(yyval.status) = OKAY;
		}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1318 "parse.y"
    {
			symmap::iterator it = current->symtbl.find(current->lexeme);
			
			if(it == current->symtbl.end()){
				printf("error at line #%d:constructor doesn't exist\n", line_number);
				(yyval.status) = ERROR;
				ehere(9);
			}else{
				listofelements* arglist = it->second->arguments;
				if(iscoerciblelisttolist((yyvsp[(3) - (5)].elist), arglist)){
					(yyval.status) = OKAY;
				}else{
					printf("error at line #%d: wrong parameters passed\n", line_number);
					(yyval.status) = ERROR;
					ehere(10);
				}
			}

		}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1339 "parse.y"
    {
			(yyval.status) = OKAY;
		}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1343 "parse.y"
    {
			
			element* supelem = currentelement()->superclass;
			listofelements* arglist = NULL;
			symmap::iterator it = supelem->desc->symtbl.find(supelem->name);
			
			if(it == supelem->desc->symtbl.end()){
				printf("constructor not found #%d:\n", line_number);
				(yyval.status) = ERROR;
				ehere(11);
			}else{
				arglist = it->second->arguments;
				if(iscoerciblelisttolist((yyvsp[(3) - (5)].elist),arglist)){
					(yyval.status) = OKAY;
				}else{
					printf("error at line #%d: wrong parameters passed\n", line_number);
					(yyval.status) = ERROR;
					ehere(12);
				}
			}

		}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1407 "parse.y"
    {
			(yyval.status) = (yyvsp[(2) - (3)].status);
		}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1411 "parse.y"
    {
			(yyval.status) = OKAY;
		}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1418 "parse.y"
    {
			(yyval.status) = (yyvsp[(1) - (1)].status);
		}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1422 "parse.y"
    {
			if((yyvsp[(1) - (2)].status) == ERROR || (yyvsp[(2) - (2)].status) == ERROR){
				(yyval.status) = ERROR;
				here(13);
			}else{
				(yyval.status) = OKAY;
			}
		}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1430 "parse.y"
    { edisp("Block Statement error\n"); }
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1435 "parse.y"
    {
			(yyval.status) = (yyvsp[(1) - (1)].status);
		}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1439 "parse.y"
    {
			(yyval.status) = (yyvsp[(1) - (1)].status);
		}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 1446 "parse.y"
    {
			(yyval.status) = (yyvsp[(1) - (2)].status);
		}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 1453 "parse.y"
    {
			
			if(!iscoercibledlist((yyvsp[(2) - (2)].dlist), (yyvsp[(1) - (2)].attr))){
				printf("error at line# %d: incompatible types\n", line_number);
				ehere(14);
				(yyval.status) = ERROR;
				
			}else{
				bool ret = coercedlist((yyvsp[(2) - (2)].dlist), (yyvsp[(1) - (2)].attr));
				if((yyvsp[(1) - (2)].attr)->rdtype == NULL) here(1448);
				listofdeclarators* e = (yyvsp[(2) - (2)].dlist);
				
				while(e!=NULL){
					here(1403);
					if(e->elem == NULL) here(1453);
					if((yyvsp[(1) - (2)].attr)->kind==KCLASS) e->elem->kind =KOBJECT;
					else e->elem->kind = KVARIABLE;
					
					fprintf(fp, "subu $sp, $sp, %d #VariableDeclarator %s\n", sizeofelement(e->elem), e->elem->name.c_str());
					here(1456);
					currentelement()->loc += sizeofelement(e->elem);
					
					if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
					e->elem->loc = currentelement()->loc;
					if(e->equals != NULL){
						fprintf(fp, "lw $t0, -%d($fp)\n", e->equals->loc);
						fprintf(fp, "sw $t0, -%d($fp)\n", e->elem->loc);
					}
					
					current->symtbl.insert({string(e->elem->name), e->elem});
					fprintf(stderr, "inserting %s in the table for main\n", e->elem->name.c_str());
					e=e->next;
				}
				
				(yyval.status) = ret;
			}
		}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1496 "parse.y"
    {(yyval.status) = (yyvsp[(1) - (1)].status);}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1497 "parse.y"
    {(yyval.status) = (yyvsp[(1) - (1)].status);}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1498 "parse.y"
    {(yyval.status) = (yyvsp[(1) - (1)].status);}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1499 "parse.y"
    {(yyval.status) =(yyvsp[(1) - (1)].status);}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1500 "parse.y"
    {(yyval.status) =(yyvsp[(1) - (1)].status);}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1507 "parse.y"
    {
			(yyval.status) = (yyvsp[(1) - (1)].status);
		}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 1510 "parse.y"
    {(yyval.status) = (yyvsp[(1) - (1)].status);}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 1511 "parse.y"
    {(yyval.status) = (yyvsp[(1) - (1)].status);}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1512 "parse.y"
    {(yyval.status) =(yyvsp[(1) - (1)].status);}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1513 "parse.y"
    {(yyval.status) =(yyvsp[(1) - (1)].status);}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 1514 "parse.y"
    {(yyval.status) = (yyvsp[(1) - (1)].status);}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 1515 "parse.y"
    {(yyval.status) = (yyvsp[(1) - (1)].status);}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1516 "parse.y"
    {(yyval.status) = (yyvsp[(1) - (1)].status);}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 1517 "parse.y"
    {(yyval.status) = OKAY;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 1518 "parse.y"
    {(yyval.status) = OKAY;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 1519 "parse.y"
    {(yyval.status) = OKAY;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1523 "parse.y"
    {(yyval.status) = OKAY;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 1527 "parse.y"
    {(yyval.status) = (yyvsp[(3) - (3)].status);}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1533 "parse.y"
    {
			if((yyvsp[(1) - (2)].attr) == NULL) here(1480);
			if((yyvsp[(1) - (2)].attr)->kind != KILLEGAL){
				
				(yyval.status) = OKAY;
			}else{
				printf("line #%d: illegal expression statement\n", line_number);
				(yyval.status) = ERROR;
				ehere(15);
			}
		}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 1548 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1552 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 1556 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 1560 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1564 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1568 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1572 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 1579 "parse.y"
    {
			(yyvsp[(1) - (4)].splb)->label = string(newlabel());
			fprintf(fp, "subu $sp, $sp, 8  #IF-THEN-ELSE start\n", (yyvsp[(3) - (4)].attr)->loc);
			currentelement()->loc +=8;
			if(PDEBUG){
				fprintf(fp, "# loc = %d\n", currentelement()->loc);
			}
			fprintf(fp, "sw $s7, ($sp)\n", (yyvsp[(3) - (4)].attr)->loc);
			fprintf(fp, "sw $sp, 4($sp)\n", (yyvsp[(3) - (4)].attr)->loc);
			fprintf(fp, "move $s7, $sp\n", (yyvsp[(3) - (4)].attr)->loc);
			
			fprintf(fp, "lw $t0, -%d($fp)\n", (yyvsp[(3) - (4)].attr)->loc);
			fprintf(fp, "li $t1, 1\n", (yyvsp[(3) - (4)].attr)->loc);
			fprintf(fp, "bne $t0, $t1, %sfalse\n", (yyvsp[(1) - (4)].splb)->label.c_str());
			
			(yyvsp[(1) - (4)].splb)->sp1 = currentelement()->loc;
		}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1597 "parse.y"
    {
			(yyvsp[(1) - (7)].splb)->sp2 = currentelement()->loc;
			currentelement()->loc = (yyvsp[(1) - (7)].splb)->sp1;
			fprintf(fp, "j %snext\n", (yyvsp[(1) - (7)].splb)->label.c_str());
			fprintf(fp, "%sfalse:\n", (yyvsp[(1) - (7)].splb)->label.c_str());
		}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1604 "parse.y"
    {
			(yyvsp[(1) - (9)].splb)->sp3 = currentelement()->loc;
			int a = (yyvsp[(1) - (9)].splb)->sp2;
			int b = (yyvsp[(1) - (9)].splb)->sp3;
			int max = a>b?a:b;
			currentelement()->loc = max;
			fprintf(fp, "%snext: #IF-THEN-ELSE end a=%d b=%d\n", (yyvsp[(1) - (9)].splb)->label.c_str(), a, b);
			fprintf(fp, "lw $t0, 4($s7)\n");
			fprintf(fp, "subu $sp, $t0, %d\n", max - (yyvsp[(1) - (9)].splb)->sp1);
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "lw $t0, ($s7)\n");
			fprintf(fp, "move $s7, $t0\n");
			
			
			if((yyvsp[(3) - (9)].attr)->pdtype!=TBOOLEAN){
				printf("line #%d: expression must be boolean\n", line_number);
				(yyval.status) = ERROR;
				ehere(18);
			}else if((yyvsp[(6) - (9)].status)==ERROR || (yyvsp[(9) - (9)].status) ==ERROR){
				(yyval.status) = ERROR;
				here(19);
			}else{
				(yyval.status) = OKAY;
			}
		}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1636 "parse.y"
    {
			printf("error at line #%d: switch not implemented\n", line_number);
			ehere();
			if((yyvsp[(5) - (5)].attr)->kind == KILLEGAL){
				printf("error at line #%d: incompatible types used in switch block\n", line_number);
				(yyval.status) = ERROR;
				ehere(22);
			}else if((yyvsp[(3) - (5)].attr)->pdtype == (yyvsp[(5) - (5)].attr)->pdtype){
				if((yyvsp[(3) - (5)].attr)->pdtype==TUNKNOWN || (yyvsp[(3) - (5)].attr)->pdtype==TVOID){
					printf("error at line #%d: switch expression not allowed\n", line_number);
					(yyval.status) = ERROR;
					ehere(23);
				}else{
					(yyval.status) = OKAY;
				}
			}else if((yyvsp[(3) - (5)].attr)->pdtype == TWILDCARD){//garbage code
				if((yyvsp[(5) - (5)].attr)->pdtype==TUNKNOWN || (yyvsp[(5) - (5)].attr)->pdtype==TVOID){
					printf("error at line #%d: switch expression not allowed\n", line_number);
					(yyval.status) = ERROR;
					ehere(24);
				}else{
					(yyval.status) = OKAY;
				}
			}else if((yyvsp[(5) - (5)].attr)->pdtype == TWILDCARD){
				if((yyvsp[(3) - (5)].attr)->pdtype==TUNKNOWN || (yyvsp[(3) - (5)].attr)->pdtype==TVOID){
					printf("error at line #%d: switch expression not allowed\n", line_number);
					(yyval.status) = ERROR;
					ehere(25);
				}else{
					(yyval.status) = OKAY;
				}
			}
		}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1673 "parse.y"
    {
			if((yyvsp[(2) - (4)].attr)->kind == KILLEGAL){
				(yyval.attr)  = (yyvsp[(2) - (4)].attr);
			}else if((yyvsp[(3) - (4)].attr)->kind==KILLEGAL){
				(yyval.attr) = (yyvsp[(3) - (4)].attr);
			}else if((yyvsp[(2) - (4)].attr)->pdtype == (yyvsp[(3) - (4)].attr)->pdtype){
				(yyval.attr) = (yyvsp[(2) - (4)].attr);
			}else if((yyvsp[(3) - (4)].attr)->pdtype == TWILDCARD){
				(yyval.attr) = (yyvsp[(2) - (4)].attr);
			}else if((yyvsp[(2) - (4)].attr)->pdtype == TWILDCARD){
				(yyval.attr) = (yyvsp[(3) - (4)].attr);
			}else{
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1689 "parse.y"
    {
			(yyval.attr) = (yyvsp[(2) - (3)].attr);
		}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1693 "parse.y"
    {
			(yyval.attr) = (yyvsp[(2) - (3)].attr);
		}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 1697 "parse.y"
    {
			(yyval.attr) = makePrimNode(string(), KUNKNOWN, TWILDCARD, vector<int>(), NULL, ANONE, NULL);
		}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 1703 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1705 "parse.y"
    {
			if((yyvsp[(1) - (2)].attr)->kind==KILLEGAL){
				(yyval.attr) = (yyvsp[(1) - (2)].attr);
			}else if((yyvsp[(2) - (2)].attr)->kind==KILLEGAL){
				(yyval.attr) = (yyvsp[(2) - (2)].attr);
			}else if((yyvsp[(1) - (2)].attr)->pdtype == (yyvsp[(2) - (2)].attr)->pdtype){
				(yyval.attr) = (yyvsp[(1) - (2)].attr);
			}else if((yyvsp[(2) - (2)].attr)->pdtype == TWILDCARD){
				(yyval.attr) = (yyvsp[(1) - (2)].attr);
			}else if((yyvsp[(1) - (2)].attr)->pdtype == TWILDCARD){
				(yyval.attr) = (yyvsp[(2) - (2)].attr);
			}else{
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 1724 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (2)].attr);
		}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1730 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1732 "parse.y"
    {
			if((yyvsp[(1) - (2)].attr)->kind == KILLEGAL){
				(yyval.attr) = (yyvsp[(1) - (2)].attr);
			}else if((yyvsp[(2) - (2)].attr)->kind == KILLEGAL){
				(yyval.attr) = (yyvsp[(2) - (2)].attr);
			}else if((yyvsp[(1) - (2)].attr)->pdtype == (yyvsp[(2) - (2)].attr)->pdtype){
				(yyval.attr) = (yyvsp[(1) - (2)].attr);
			}else if((yyvsp[(2) - (2)].attr)->pdtype == TWILDCARD){
				(yyval.attr) = (yyvsp[(1) - (2)].attr);
			}else if((yyvsp[(1) - (2)].attr)->pdtype == TWILDCARD){
				(yyval.attr) = (yyvsp[(2) - (2)].attr);
			}else{
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1750 "parse.y"
    {(yyval.attr) = (yyvsp[(2) - (3)].attr);}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1752 "parse.y"
    {
			(yyval.attr) = makePrimNode(string(), KUNKNOWN, TWILDCARD, vector<int>(), NULL, ANONE, NULL);
		}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 1760 "parse.y"
    {
			(yyvsp[(1) - (2)].splb)->label = string(newlabel());
			(yyvsp[(1) - (2)].splb)->sp1 = currentelement()->loc;
			fprintf(fp, "%sloop: #WHILE start\n", (yyvsp[(1) - (2)].splb)->label.c_str());
		}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1766 "parse.y"
    {
			(yyvsp[(1) - (5)].splb)->sp2 = currentelement()->loc;
			fprintf(fp, "lw $t0, -%d($fp)\n", (yyvsp[(4) - (5)].attr)->loc);
			fprintf(fp, "li $t1, 1\n");
			fprintf(fp, "bne $t0, $t1, %snext\n", (yyvsp[(1) - (5)].splb)->label.c_str());
		}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1773 "parse.y"
    {
			(yyvsp[(1) - (7)].splb)->sp3 = currentelement()->loc;
			int diff = (yyvsp[(1) - (7)].splb)->sp3 - (yyvsp[(1) - (7)].splb)->sp1;
			fprintf(fp, "addu $sp, $sp, %d\n", diff);
			fprintf(fp, "j %sloop\n", (yyvsp[(1) - (7)].splb)->label.c_str());
			fprintf(fp, "%snext:\n", (yyvsp[(1) - (7)].splb)->label.c_str());
			fprintf(fp, "subu $sp, $sp, %d #WHILE end\n", (yyvsp[(1) - (7)].splb)->sp3 - (yyvsp[(1) - (7)].splb)->sp2);
			
			if((yyvsp[(4) - (7)].attr)->pdtype != TBOOLEAN){
				printf("line #%d: expression must be boolean\n", line_number);
				(yyval.status) = ERROR;
				ehere(26);
			}else{
				(yyval.status) = (yyvsp[(7) - (7)].status);
			}
		}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1793 "parse.y"
    {
			(yyvsp[(1) - (1)].splb)->label = string(newlabel());
			(yyvsp[(1) - (1)].splb)->sp1 = currentelement()->loc;
			fprintf(fp, "%sbody: #DO start\n", (yyvsp[(1) - (1)].splb)->label.c_str());
		}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1800 "parse.y"
    {
			(yyvsp[(1) - (6)].splb)->sp2 = currentelement()->loc;
			fprintf(fp, "lw $t0, -%d($fp)\n", (yyvsp[(6) - (6)].attr)->loc);
			fprintf(fp, "li $t1, 1\n");
			int diff = (yyvsp[(1) - (6)].splb)->sp2 - (yyvsp[(1) - (6)].splb)->sp1;
			fprintf(fp, "addu $sp, $sp, %d\n", diff);
			fprintf(fp, "beq $t0, $t1, %sbody\n", (yyvsp[(1) - (6)].splb)->label.c_str());
			fprintf(fp, "subu $sp, $sp, %d\n", diff);
			fprintf(fp, "%snext: #DO end\n", (yyvsp[(1) - (6)].splb)->label.c_str());
		}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1811 "parse.y"
    {
			if((yyvsp[(6) - (9)].attr)->pdtype != TBOOLEAN){
				printf("line #%d: expression must be boolean\n", line_number);
				(yyval.status) = ERROR;
				ehere(28);
			}else{
				(yyval.status) = (yyvsp[(3) - (9)].status);
			}
		}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1824 "parse.y"
    {
			(yyvsp[(1) - (4)].splb)->label = string(newlabel());
			fprintf(fp, "%sloop: #FOR start\n", (yyvsp[(1) - (4)].splb)->label.c_str());
			(yyvsp[(1) - (4)].splb)->sp1=currentelement()->loc;
		}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1830 "parse.y"
    {
			(yyvsp[(1) - (6)].splb)->sp2=currentelement()->loc;
			fprintf(fp, "lw $t0, -%d($fp)\n", (yyvsp[(6) - (6)].attr)->loc);
			fprintf(fp, "li $t1, 1\n");
			fprintf(fp, "bne $t0, $t1, %snext\n", (yyvsp[(1) - (6)].splb)->label.c_str());
		}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1838 "parse.y"
    {	
			
			(yyvsp[(1) - (10)].splb)->sp3=currentelement()->loc;
			
			int stackused = (yyvsp[(1) - (10)].splb)->sp3 - (yyvsp[(1) - (10)].splb)->sp1;
			fprintf(fp, "addu $sp, $sp, %d\n", stackused);
			fprintf(fp, "j %sloop\n", (yyvsp[(1) - (10)].splb)->label.c_str());
			
			fprintf(fp, "%snext:\n", (yyvsp[(1) - (10)].splb)->label.c_str());
			int adjustment = (yyvsp[(1) - (10)].splb)->sp3 - (yyvsp[(1) - (10)].splb)->sp2;
			fprintf(fp, "subu $sp, $sp, %d #FOR end\n", adjustment);
			(yyval.status) = (yyvsp[(3) - (10)].status) && (yyvsp[(10) - (10)].status) && ((yyvsp[(6) - (10)].attr)->pdtype !=TBOOLEAN);
		}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1853 "parse.y"
    {
			(yyvsp[(1) - (4)].splb)->label = string(newlabel());
			fprintf(fp, "%sloop: #FOR start\n", (yyvsp[(1) - (4)].splb)->label.c_str());
		}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 1858 "parse.y"
    {
			fprintf(fp, "lw $t0, -%d($fp)\n", (yyvsp[(6) - (6)].attr)->loc);
			fprintf(fp, "li $t1, 1\n");
			fprintf(fp, "beq $t0, $t1, 1\n");
			fprintf(fp, "j %snext\n", (yyvsp[(1) - (6)].splb)->label.c_str());
			fprintf(fp, "j %sbody\n", (yyvsp[(1) - (6)].splb)->label.c_str());
			fprintf(fp, "%supdate:\n", (yyvsp[(1) - (6)].splb)->label.c_str());
		}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 1867 "parse.y"
    {
			fprintf(fp, "j %sloop\n", (yyvsp[(1) - (10)].splb)->label.c_str());
			fprintf(fp, "%sbody:\n", (yyvsp[(1) - (10)].splb)->label.c_str());
		}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1872 "parse.y"
    {	
			fprintf(fp, "j %supdate\n", (yyvsp[(1) - (12)].splb)->label.c_str());
			fprintf(fp, "%snext: #FOR end\n");
			(yyval.status) = (yyvsp[(3) - (12)].status) && (yyvsp[(9) - (12)].status) && (yyvsp[(12) - (12)].status) && ((yyvsp[(6) - (12)].attr)->pdtype !=TBOOLEAN);
		}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1879 "parse.y"
    {
			(yyvsp[(1) - (4)].splb)->label = string(newlabel());
			fprintf(fp, "%sloop: #FOR start\n", (yyvsp[(1) - (4)].splb)->label.c_str());
		}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1884 "parse.y"
    {
			fprintf(fp, "j %sbody\n", (yyvsp[(1) - (5)].splb)->label.c_str());
			fprintf(fp, "%supdate:\n", (yyvsp[(1) - (5)].splb)->label.c_str());
		}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1889 "parse.y"
    {
			fprintf(fp, "j %sloop\n", (yyvsp[(1) - (9)].splb)->label.c_str());
			fprintf(fp, "%sbody:\n", (yyvsp[(1) - (9)].splb)->label.c_str());
		}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1894 "parse.y"
    {	
			fprintf(fp, "j %supdate\n", (yyvsp[(1) - (11)].splb)->label.c_str());
			fprintf(fp, "%snext: #FOR end\n");
			(yyval.status) = (yyvsp[(3) - (11)].status) && (yyvsp[(8) - (11)].status) && (yyvsp[(11) - (11)].status);
		}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1902 "parse.y"
    {
			(yyvsp[(1) - (4)].splb)->label = string(newlabel());
			fprintf(fp, "%sloop: #FOR start\n", (yyvsp[(1) - (4)].splb)->label.c_str());
		}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1907 "parse.y"
    {
			fprintf(fp, "j %sbody\n", (yyvsp[(1) - (5)].splb)->label.c_str());
			fprintf(fp, "%supdate:\n", (yyvsp[(1) - (5)].splb)->label.c_str());
		}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1912 "parse.y"
    {
			fprintf(fp, "j %sloop\n", (yyvsp[(1) - (8)].splb)->label.c_str());
			fprintf(fp, "%sbody:\n", (yyvsp[(1) - (8)].splb)->label.c_str());
		}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1917 "parse.y"
    {	
			fprintf(fp, "j %supdate\n", (yyvsp[(1) - (10)].splb)->label.c_str());
			fprintf(fp, "%snext: #FOR end\n");
			(yyval.status) = (yyvsp[(3) - (10)].status) && (yyvsp[(10) - (10)].status);
		}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1926 "parse.y"
    {
			(yyvsp[(1) - (3)].splb)->label = string(newlabel());
			fprintf(fp, "%sloop: #FOR start\n", (yyvsp[(1) - (3)].splb)->label.c_str());
		}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1931 "parse.y"
    {
			fprintf(fp, "lw $t0, -%d($fp)\n", (yyvsp[(5) - (5)].attr)->loc);
			fprintf(fp, "li $t1, 1\n");
			fprintf(fp, "beq $t0, $t1, 1\n");
			fprintf(fp, "j %snext\n", (yyvsp[(1) - (5)].splb)->label.c_str());
			fprintf(fp, "j %sbody\n", (yyvsp[(1) - (5)].splb)->label.c_str());
			fprintf(fp, "%supdate:\n", (yyvsp[(1) - (5)].splb)->label.c_str());
		}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1940 "parse.y"
    {
			fprintf(fp, "j %sloop\n", (yyvsp[(1) - (9)].splb)->label.c_str());
			fprintf(fp, "%sbody:\n", (yyvsp[(1) - (9)].splb)->label.c_str());
		}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1945 "parse.y"
    {	
			fprintf(fp, "j %supdate\n", (yyvsp[(1) - (11)].splb)->label.c_str());
			fprintf(fp, "%snext: #FOR end\n");
			(yyval.status) = (yyvsp[(8) - (11)].status) && (yyvsp[(11) - (11)].status) && ((yyvsp[(5) - (11)].attr)->pdtype !=TBOOLEAN);
		}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1954 "parse.y"
    {
			(yyvsp[(1) - (3)].splb)->label = string(newlabel());
			fprintf(fp, "%sloop: #FOR start\n", (yyvsp[(1) - (3)].splb)->label.c_str());
		}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1959 "parse.y"
    {
			fprintf(fp, "lw $t0, -%d($fp)\n", (yyvsp[(5) - (5)].attr)->loc);
			fprintf(fp, "li $t1, 1\n");
			fprintf(fp, "beq $t0, $t1, 1\n");
			fprintf(fp, "j %snext\n", (yyvsp[(1) - (5)].splb)->label.c_str());
			fprintf(fp, "j %sbody\n", (yyvsp[(1) - (5)].splb)->label.c_str());
			fprintf(fp, "%supdate:\n", (yyvsp[(1) - (5)].splb)->label.c_str());
		}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1968 "parse.y"
    {
			fprintf(fp, "j %sloop\n", (yyvsp[(1) - (8)].splb)->label.c_str());
			fprintf(fp, "%sbody:\n", (yyvsp[(1) - (8)].splb)->label.c_str());
		}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1973 "parse.y"
    {	
			fprintf(fp, "j %supdate\n", (yyvsp[(1) - (10)].splb)->label.c_str());
			fprintf(fp, "%snext: #FOR end\n");
			(yyval.status) = (yyvsp[(10) - (10)].status) && ((yyvsp[(5) - (10)].attr)->pdtype !=TBOOLEAN);
		}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1981 "parse.y"
    {
			(yyvsp[(1) - (3)].splb)->label = string(newlabel());
			fprintf(fp, "%sloop: #FOR start\n", (yyvsp[(1) - (3)].splb)->label.c_str());
		}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1986 "parse.y"
    {
			fprintf(fp, "j %sbody\n", (yyvsp[(1) - (4)].splb)->label.c_str());
			fprintf(fp, "%supdate:\n", (yyvsp[(1) - (4)].splb)->label.c_str());
		}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1991 "parse.y"
    {
			fprintf(fp, "j %sloop\n", (yyvsp[(1) - (8)].splb)->label.c_str());
			fprintf(fp, "%sbody:\n", (yyvsp[(1) - (8)].splb)->label.c_str());
		}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1996 "parse.y"
    {	
			fprintf(fp, "j %supdate\n", (yyvsp[(1) - (10)].splb)->label.c_str());
			fprintf(fp, "%snext: #FOR end\n");
			(yyval.status) = (yyvsp[(7) - (10)].status) && (yyvsp[(10) - (10)].status);
		}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 2004 "parse.y"
    {
			(yyvsp[(1) - (3)].splb)->label = string(newlabel());
			fprintf(fp, "%sloop: #FOR start\n", (yyvsp[(1) - (3)].splb)->label.c_str());
		}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 2009 "parse.y"
    {
			fprintf(fp, "j %sbody\n", (yyvsp[(1) - (4)].splb)->label.c_str());
			fprintf(fp, "%supdate:\n", (yyvsp[(1) - (4)].splb)->label.c_str());
		}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 2014 "parse.y"
    {
			fprintf(fp, "j %sloop\n", (yyvsp[(1) - (7)].splb)->label.c_str());
			fprintf(fp, "%sbody:\n", (yyvsp[(1) - (7)].splb)->label.c_str());
		}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 2019 "parse.y"
    {	
			fprintf(fp, "j %supdate\n", (yyvsp[(1) - (9)].splb)->label.c_str());
			fprintf(fp, "%snext: #FOR end\n");
			(yyval.status) = (yyvsp[(9) - (9)].status);
		}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 2028 "parse.y"
    {	(yyval.splb) = new splab();	}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 2032 "parse.y"
    {	(yyval.splb) = new splab();	}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 2037 "parse.y"
    {	(yyval.splb) = new splab();	}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 2041 "parse.y"
    {	(yyval.splb) = new splab();	}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 2046 "parse.y"
    {
			if((yyvsp[(1) - (1)].attr)->kind == KILLEGAL){
				(yyval.status) = ERROR;
				ehere(29);
			}else{
				(yyval.status) = OKAY;
			}
		}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 2055 "parse.y"
    {
			(yyval.status) = (yyvsp[(1) - (1)].status);
		}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 2062 "parse.y"
    {
			if((yyvsp[(1) - (1)].attr)->kind == KILLEGAL){
				(yyval.status) = ERROR;
				ehere(30);
			}else{
				(yyval.status) = OKAY;
			}
		}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 2073 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 2075 "parse.y"
    {
			if((yyvsp[(1) - (3)].attr)->kind==KILLEGAL || (yyvsp[(3) - (3)].attr)->kind ==KILLEGAL){
				(yyvsp[(1) - (3)].attr)->kind=KILLEGAL;
				ehere(34);
			}
			(yyval.attr) = (yyvsp[(1) - (3)].attr);
		}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 2085 "parse.y"
    {(yyval.status) = OKAY;}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 2086 "parse.y"
    {(yyval.status) = OKAY;}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 2090 "parse.y"
    {(yyval.status) = OKAY;}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 2091 "parse.y"
    {(yyval.status) = OKAY;}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 2096 "parse.y"
    {
			fprintf(fp, "subu $t0, $fp, %d #RETURN\n", (yyvsp[(2) - (3)].attr)->loc);
			fprintf(fp, "sw $t0, 0($fp)\n");
			fprintf(fp, "jr $ra\n");
			
			scope* scp = currentelement()->desc;
			while(scp != NULL && scp->elem->kind!=KPRIMFUNCTION && scp->elem->kind!=KREFFUNCTION) scp = scp->parent;
			if(scp == NULL){
				printf("error at line#%d: return statement must be inside a method\n", line_number);
				(yyval.status) = ERROR;
				ehere(31);
			}else if(scp->elem->kind == KPRIMFUNCTION){
				 if(!iscoercible((yyvsp[(2) - (3)].attr), makePrimNode(string(), KVARIABLE, scp->elem->pdtype, vector<int>(), NULL, ANONE, NULL))){
						ehere(212);
						printf("error at line#%d: return statement: incompatible types\n", line_number);
						(yyval.status) = ERROR;
					}else {(yyval.status)=OKAY;}
			}else if(scp->elem->kind == KREFFUNCTION){
				if(!iscoercible((yyvsp[(2) - (3)].attr), makeRefNode(string(), KOBJECT, scp->elem->rdtype, vector<int>(), NULL, ANONE, NULL, NULL, NULL))){
					printf("error at line#%d: return statement: incompatible types\n", line_number);
					ehere(1);
					(yyval.status) =ERROR;
				} else {(yyval.status)=OKAY;}
			}else{
				//printscopehierarchy();
				printf("error at line#%d: return statement must be inside a method\n", line_number);
				//printf("curelem->kind = %d\n", scp->elem->kind);
				(yyval.status) = ERROR;
				ehere(32);
			}
		}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 2128 "parse.y"
    {
			fprintf(fp, "jr $ra #RETURN\n");

			scope* s = current;
			while(s!=NULL && s->elem->kind != KPRIMFUNCTION) s= s->parent;
			if(s==NULL){
				printf("error at line#%d: return statement must be inside a method\n", line_number);
				(yyval.status) = ERROR;
				ehere(33);
			}else if(s->elem->pdtype == TVOID){
				(yyval.status) = OKAY;
			}else{
				printf("error at line#%d: incompatible return type\n", line_number);
				(yyval.status) = ERROR;
				ehere(33);
			}
		}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 2176 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 2177 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 2181 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 2183 "parse.y"
    {
		element* e = makeRefNode(string(), KOBJECT, current->parent->elem, vector<int>(), 4, ANONE, NULL, NULL, NULL);
		e->amode = REFERENCE;
		(yyval.attr) = e;
	}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 2188 "parse.y"
    {(yyval.attr) = (yyvsp[(2) - (3)].attr);}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 2189 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 2190 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 2192 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 2196 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 2203 "parse.y"
    {
			fprintf(fp, "li $a0, %d\n", sizeoftype((yyvsp[(2) - (4)].attr)));
			fprintf(fp, "li $v0, 9\n");
			fprintf(fp, "syscall\n");
			fprintf(fp, "addu $v0, $v0, %d\n", sizeoftype((yyvsp[(2) - (4)].attr)));
			fprintf(fp, "subu $sp, $sp, 4 #NEW %s\n", (yyvsp[(2) - (4)].attr)->name.c_str());
			currentelement()->loc += 4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			
			fprintf(fp, "sw $v0, ($sp)\n");
			
			
			fprintf(fp, "move $s0, $v0\n");
			
			fprintf(fp, "subu $sp, $sp, 4\n");
			fprintf(fp, "sw $fp, 0($sp)\n");
			
			fprintf(fp, "subu $sp, $sp, 4\n");
			fprintf(fp, "sw $ra, 0($sp)\n");
			
			fprintf(fp, "subu $sp, $sp, 8\n");
			fprintf(fp, "sw $s0, 0($sp)\n");
			
			fprintf(fp, "addu $fp, $sp, 4\n");
			fprintf(fp, "jal %s%s\n", (yyvsp[(2) - (4)].attr)->name.c_str(), (yyvsp[(2) - (4)].attr)->name.c_str());
			
			fprintf(fp, "addu $t0, $fp, 4\n");
			fprintf(fp, "lw $ra, 0($t0)\n");
			
			fprintf(fp, "addu $sp, $fp, 12\n");
			
			fprintf(fp, "addu $t0, $fp, 8\n");
			fprintf(fp, "lw $fp, 0($t0)\n");
			if((yyvsp[(2) - (4)].attr)==NULL){
				printf("error at line #%d: constructor not found in this scope\n", line_number);
				ehere(1951); here(1951);
				(yyval.attr) = makeIllegalNode();
			}else{
				symmap::iterator it =  (yyvsp[(2) - (4)].attr)->desc->symtbl.find((yyvsp[(2) - (4)].attr)->name);
				if(it == (yyvsp[(2) - (4)].attr)->desc->symtbl.end()){
					printf("error at line #%d: constructor not declared\n", line_number);
					ehere(1958); here(1958);
					(yyval.attr) = makeIllegalNode();					
				}else{
					element* constructor = it->second;
					if(!iscoerciblelisttolist(constructor->arguments, NULL)){
						printf("error at line#%d: unexpected arguments\n", line_number);
						(yyval.attr) =makeIllegalNode();
					}else{
						
						(yyval.attr) = makeRefNode(string(), KOBJECT, (yyvsp[(2) - (4)].attr), vector<int>(), currentelement()->loc, ANONE, NULL, NULL, NULL);
					}
				}
			}
		}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 2261 "parse.y"
    {
			if((yyvsp[(2) - (5)].attr)==NULL){
				printf("error at line #%d: constructor not found in this scope\n", line_number);
				ehere(1975); here(1975);
				(yyval.attr) = makeIllegalNode();
			}else{
				symmap::iterator it =  (yyvsp[(2) - (5)].attr)->desc->symtbl.find((yyvsp[(2) - (5)].attr)->name);
				if(it == (yyvsp[(2) - (5)].attr)->desc->symtbl.end()){
					printf("error at line #%d: constructor not declared\n", line_number);
					ehere(1958); here(1981);
					(yyval.attr) = makeIllegalNode();					
				}else{
					element* constructor = it->second;
					if(!iscoerciblelisttolist(constructor->arguments, (yyvsp[(4) - (5)].elist))){
						printf("error at line#%d: unexpected arguments\n", line_number);
						(yyval.attr) =makeIllegalNode();
					}else{
						here(1990);
						fprintf(fp, "li $a0, %d\n", sizeoftype((yyvsp[(2) - (5)].attr)));
						fprintf(fp, "li $v0, 9\n");
						fprintf(fp, "syscall\n");
						fprintf(fp, "addu $v0, $v0, %d\n", sizeoftype((yyvsp[(2) - (5)].attr)));
						fprintf(fp, "subu $sp, $sp, 4 #NEW %s\n", (yyvsp[(2) - (5)].attr)->name.c_str());
						currentelement()->loc += 4;
						if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
						fprintf(fp, "sw $v0, 0($sp)\n");
						
						
						fprintf(fp, "move $s0, $v0\n");//s0 has the address of allocated object
						
						fprintf(fp, "subu $sp, $sp, 4\n");
						fprintf(fp, "sw $fp, 0($sp)\n");
						
						fprintf(fp, "subu $sp, $sp, 4\n");
						fprintf(fp, "sw $ra, 0($sp)\n");
						
						fprintf(fp, "subu $sp, $sp, 8\n");
						fprintf(fp, "sw $s0, 0($sp)\n");
						
						fprintf(fp, "addu $s0, $sp, 4\n");//s0 has the value to which fp is to be set
						

					
						listofelements* e = (yyvsp[(4) - (5)].elist);
						while(e!=NULL){
							if(e->elem->kind == KVARIABLE || e->elem->kind==KPRIMITIVE || e->elem->kind==KLITERAL){
								fprintf(fp, "subu $sp, $sp, %d\n", sizeofelement((yyvsp[(4) - (5)].elist)->elem));
								fetchint0(e->elem);
								
								fprintf(fp, "sw $t0, 0($sp)\n");
							}else{
								fprintf(fp, "subu $sp, $sp, 4\n");
								fprintf(fp, "lw $t0, -%d($fp)\n", e->elem->loc);
								fprintf(fp, "sw $t0, 0($sp)\n");
							}
							e = e->next;
						}
						
						fprintf(fp, "move $fp, $s0\n");
						fprintf(fp, "jal %s%s\n", (yyvsp[(2) - (5)].attr)->name.c_str(), (yyvsp[(2) - (5)].attr)->name.c_str());
						
						fprintf(fp, "addu $t0, $fp, 4\n");
						fprintf(fp, "lw $ra, 0($t0)\n");
						
						fprintf(fp, "addu $sp, $fp, 12\n");
						
						fprintf(fp, "addu $t0, $fp, 8\n");
						fprintf(fp, "lw $fp, 0($t0)\n");

						(yyval.attr) = makeRefNode(string(), KOBJECT, (yyvsp[(2) - (5)].attr), vector<int>(), currentelement()->loc, ANONE, NULL, NULL, NULL);
					}
				}
			}
		}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 2341 "parse.y"
    {
			listofelements* list = new listofelements();
			list->elem = (yyvsp[(1) - (1)].attr);
			list->next = NULL;
			(yyval.elist) = list;
		}
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 2348 "parse.y"
    {
			listofelements* newnode = new listofelements();
			newnode->elem = (yyvsp[(3) - (3)].attr);
			newnode->next = NULL;
			listofelements * list = (yyvsp[(1) - (3)].elist);
			while(list->next != NULL) list = list->next;
			list->next = newnode;
			(yyval.elist) = (yyvsp[(1) - (3)].elist);
		}
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 2361 "parse.y"
    {
			printf("error at line number %d: Not implemented\n", line_number);
			ehere();
			vector<int> *vec1 = (yyvsp[(3) - (4)].pspvec)->pvec, *vec2 = (yyvsp[(4) - (4)].pspvec)->pvec;
			vec1->insert(vec1->end(), vec2->begin(), vec2->end());
			(yyval.attr) = makePrimNode(string(), KVARIABLE, (yyvsp[(2) - (4)].attr)->pdtype, *vec1, NULL, ANONE, NULL);
		}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 2369 "parse.y"
    {
			std::vector<int>::size_type sz = (*(yyvsp[(3) - (3)].pspvec)->pvec).size();
			fprintf(stderr, "size: %d\n", sz);
			fprintf(fp, "li $t0, 1\n");
			for(unsigned i=0; i<sz; i++){
				fprintf(stderr, "loc: %d\n", (*((yyvsp[(3) - (3)].pspvec)->pvec))[i]);
				fprintf(fp, "lw $t1, -%d($fp)\n", (*((yyvsp[(3) - (3)].pspvec)->pvec))[i]);
				fprintf(fp, "multu $t0, $t1\n");
				fprintf(fp, "mflo $t0\n");
			}
			fprintf(fp, "li $t1, %d\n", sizeoftype((yyvsp[(2) - (3)].attr)));
			fprintf(fp, "multu $t0, $t1\n");
			fprintf(fp, "mflo $t0\n");
			fprintf(fp, "move $a0, $t0\n");
			fprintf(fp, "li $v0, 9\n");
			fprintf(fp, "syscall\n");
			//fprintf(fp, "addu $v0, $v0, $t0\n");
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc += 4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
							
			fprintf(fp, "sw $v0, ($sp)\n");
			
			(yyval.attr) = makePrimNode(string(), KVARIABLE, (yyvsp[(2) - (3)].attr)->pdtype, *((yyvsp[(3) - (3)].pspvec)->pvec), currentelement()->loc, ANONE, NULL);
		}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 2397 "parse.y"
    {
			printf("error at line number %d: Not implemented\n", line_number);
			ehere();
			vector<int> *vec1 = (yyvsp[(3) - (4)].pspvec)->pvec, *vec2=(yyvsp[(4) - (4)].pspvec)->pvec;
			vec1->insert(vec1->end(), vec2->begin(), vec2->end());
			(yyval.attr) = makeRefNode(string(), KOBJECT, (yyvsp[(2) - (4)].attr)->rdtype, *vec1, NULL, ANONE, NULL, NULL, NULL);
		}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 2405 "parse.y"
    {
			std::vector<int>::size_type sz = (*(yyvsp[(3) - (3)].pspvec)->pvec).size();
			
			fprintf(fp, "li $t0, 1\n");
			for(unsigned i=0; i<sz; i++){
				fprintf(fp, "lw $t1, -%d($fp)\n", (*((yyvsp[(3) - (3)].pspvec)->pvec))[i]);
				fprintf(fp, "multu $t0, $t1\n");
				fprintf(fp, "mflo $t0\n");
			}
			fprintf(fp, "li $t1, %d\n", sizeoftype((yyvsp[(2) - (3)].attr)));
			fprintf(fp, "multu $t0, $t1\n");
			fprintf(fp, "mflo $t0\n");
			fprintf(fp, "move $a0, $t0\n");
			fprintf(fp, "li $v0, 9\n");
			fprintf(fp, "syscall\n");
			//fprintf(fp, "addu $v0, $v0, $t0\n");
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc += 4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "sw $v0, ($sp)\n");
			
			(yyval.attr) = makeRefNode(string(), KOBJECT, (yyvsp[(2) - (3)].attr)->rdtype, *(yyvsp[(3) - (3)].pspvec)->pvec, currentelement()->loc, ANONE, NULL, NULL, NULL);
		}
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 2434 "parse.y"
    {
			spvec* spv = (spvec*)malloc(sizeof(spvec));
			vector<int> * ptrvec = (vector<int>*)malloc(sizeof(vector<int>));
			ptrvec->push_back((yyvsp[(1) - (1)].ival));
			
			spv->pvec = ptrvec;
			fprintf(stderr, "vec[0]=%d\n", (*(spv->pvec))[0]);
			(yyval.pspvec) = spv; 
		}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 2444 "parse.y"
    {
			(*(yyvsp[(1) - (2)].pspvec)->pvec).push_back((yyvsp[(2) - (2)].ival));
		}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 2452 "parse.y"
    {
			if((yyvsp[(2) - (3)].attr)->kind != KVARIABLE && !iscoercible((yyvsp[(2) - (3)].attr), makePrimNode(string(), KPRIMITIVE, TINT, vector<int>(), NULL, ANONE, NULL))){
				printf("error at line #%d: expecting expressions convertible to int\n", line_number);
				ehere();
				here(2450);
				(yyval.ival) = 0;
			}else{
				fprintf(stderr, "$$ = $2->loc = %d\n", (yyvsp[(2) - (3)].attr)->loc);
				(yyval.ival) = (yyvsp[(2) - (3)].attr)->loc;
			}
		}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 2467 "parse.y"
    {
			vector<int> vec (1, 0);
			spvec* s = (spvec*)malloc(sizeof(spvec));
			s->pvec = &vec;
			(yyval.pspvec) = s; 
		}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 2474 "parse.y"
    {
			(yyvsp[(1) - (3)].pspvec)->pvec->push_back(0);
			(yyval.pspvec) = (yyvsp[(1) - (3)].pspvec);
		}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 2482 "parse.y"
    {
			if((yyvsp[(1) - (3)].attr)->kind != KOBJECT){
				printf("error at line #%d: %s not an object\n", line_number, (yyvsp[(1) - (3)].attr)->name.c_str());
				(yyval.attr) = makeIllegalNode();
			}else{
				symmap::iterator it = (yyvsp[(1) - (3)].attr)->rdtype->desc->symtbl.find((yyvsp[(3) - (3)].sval));
				namenode* node = new namenode();
				node->name = string((yyvsp[(3) - (3)].sval));
				node->next = NULL;
				element* obj = findobjectinthisorsuper((yyvsp[(1) - (3)].attr), node, false);
				(yyval.attr) = obj;
			}
		}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 2496 "parse.y"
    {
			namenode* node = new namenode();
			element* sup = current->parent->elem->superclass;
			element* elem = findtypeinthisorsuper(sup, node, false);
			if(elem==NULL){
				printf("line #%d: member doesn't exist\n");
				(yyval.attr) = makeIllegalNode();
			}else{
				fprintf(fp, "lw $t0, -4($fp) #SUPER.%s\n", (yyvsp[(3) - (3)].sval));
				fprintf(fp, "addiu $t0, $t0, %d\n", elem->loc);
				fprintf(fp, "subu $sp, $sp, 4\n");
				currentelement()->loc += 4;
				if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
				fprintf(fp, "sw $t0, 0($sp)\n");
				element* e = copyelement(elem);
				e->loc = currentelement()->loc;
				e->amode = REFERENCE;
				(yyval.attr) = e;
			}
		}
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 2522 "parse.y"
    {
			element* func = findobject(current, (yyvsp[(1) - (4)].name), KALL);

			//ASSERT(func->kind == KPRIMFUNCTION || func->kind == KREFFUNCTION);
			if(iscoerciblelisttolist((yyvsp[(3) - (4)].elist), func->arguments)){
				if(func->kind == KPRIMFUNCTION){
					fprintf(fp, "subu $sp, $sp, 4 #CALL %s\n", func->name.c_str());
					
					currentelement()->loc +=4;
					if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
					//~ if(func->pdtype==TDOUBLE || func->pdtype==TLONG){
						//~ fprintf(fp, "subu $sp, $sp, 4\n");
						//~ fprintf(fp, "move $t0, $sp\n");//making space for return value
						//~ currentelement()->loc +=4;
					//~ }
					(yyval.attr) = makePrimNode(string(), KVARIABLE, func->pdtype, vector<int>(), currentelement()->loc, ANONE, NULL);
					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $fp, ($sp)\n");//store $fp
					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $ra, ($sp)\n");//store $ra
					fprintf(fp, "subu $sp, $sp, 8\n");//set up call stack
					fprintf(fp, "lw $t1, -4($fp)\n");//getting access link
					fprintf(fp, "sw $t1, ($sp)\n");//storing access link
					fprintf(fp, "addu $s0, $sp, 4\n");
					
					listofelements* e = (yyvsp[(3) - (4)].elist);
					while(e!=NULL){
						if(e->elem->kind==KPRIMITIVE || e->elem->kind==KVARIABLE || e->elem->kind==KLITERAL){
							fprintf(fp, "subu $sp, $sp, 4\n");
							fetchint0(e->elem);
							fprintf(fp, "sw $t0, ($sp)\n", e->elem->loc);
						}else{
							fprintf(fp, "subu $sp, $sp, 4\n");
							fprintf(fp, "lw $t0, -%d($fp)\n", e->elem->loc);
							fprintf(fp, "sw $t0, ($sp)\n");
						}
						e=e->next;
					}
					fprintf(fp, "move $fp, $s0\n");
					fprintf(fp, "jal %s%s\n", func->desc->parent->elem->name.c_str(), func->name.c_str());
					if(func->pdtype!=TVOID){
						fprintf(fp, "lw $t0, 0($fp)\n");//store the return value in t0
						fprintf(fp, "lw $t0, 0($t0)\n");//store the return value in t0	
					}
					fprintf(fp, "addu $t1, $fp, 12\n");//$t1: address to caller's space for return value
					fprintf(fp, "sw $t0, 0($t1)\n");
					//~ if(func->pdtype==TDOUBLE || func->pdtype==TLONG){
						//~ fprintf(fp, "lw $t0, 4($fp)\n");//store the return value in t0
						//~ fprintf(fp, "addu $t1, $fp, 12\n");//$t1: address to caller's space for return value
						//~ fprintf(fp, "sw $t0, $t1\n");
					//~ }
					fprintf(fp, "addu $t0, $fp, 4\n");
					fprintf(fp, "lw $ra, 0($t0)\n");
					fprintf(fp, "addu $t0, $fp, 12\n");
					fprintf(fp, "move $sp, $t0\n");
					fprintf(fp, "addu $t0, $fp, 8\n");
					fprintf(fp, "lw $fp, 0($t0)\n");
				}else if(func->kind == KREFFUNCTION){
					fprintf(fp, "subu $sp, $sp, 4 #CALL %s\n", func->name.c_str());
					
					currentelement()->loc +=4;
					if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
					(yyval.attr) = makeRefNode(string(), KOBJECT, func->rdtype, vector<int>(), NULL, ANONE, NULL, NULL, NULL);

					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $fp, 0($sp)\n");//store $fp
					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $ra, 0($sp)\n");//store $ra
					fprintf(fp, "subu $sp, $sp, 8\n");//set up call stack
					fprintf(fp, "lw $t1, -4($fp)\n");//getting access link
					fprintf(fp, "sw $t1, 0($sp)\n");//storing access link
					fprintf(fp, "addu $s0, $sp, 4\n");
					
					listofelements* e = (yyvsp[(3) - (4)].elist);
					while(e!=NULL){
						if(e->elem->kind==KPRIMITIVE || e->elem->kind==KVARIABLE || e->elem->kind==KLITERAL){
							fprintf(fp, "subu $sp, $sp, 4\n");
							fetchint0(e->elem);
							fprintf(fp, "sw $t0, 0($sp)\n", e->elem->loc);
						}else{
							fprintf(fp, "subu $sp, $sp, 4\n");
							fprintf(fp, "lw $t0, -%d($fp)\n", e->elem->loc);
							fprintf(fp, "sw $t0, 0($sp)\n");
						}
						e=e->next;
					}
					fprintf(fp, "move $fp, $s0\n");
					fprintf(fp, "jal %s%s\n", func->desc->parent->elem->name.c_str(), func->name.c_str());
					if(func->pdtype!=TVOID){
						fprintf(fp, "lw $t0, 0($fp)\n");//store the return value in t0
						fprintf(fp, "lw $t0, 0($t0)\n");//store the return value in t0	
					}
					fprintf(fp, "addu $t1, $fp, 12\n");//$t1: address to caller's space for return value
					fprintf(fp, "sw $t0, 0($t1)\n");
					//~ if(func->pdtype==TDOUBLE || func->pdtype==TLONG){
						//~ fprintf(fp, "lw $t0, 4($fp)\n");//store the return value in t0
						//~ fprintf(fp, "addu $t1, $fp, 12\n");//$t1: address to caller's space for return value
						//~ fprintf(fp, "sw $t0, $t1\n");
					//~ }
					fprintf(fp, "addu $t0, $fp, 4\n");
					fprintf(fp, "lw $ra, 0($t0)\n");
					fprintf(fp, "addu $t0, $fp, 12\n");
					fprintf(fp, "move $sp, $t0\n");
					fprintf(fp, "addu $t0, $fp, 8\n");
					fprintf(fp, "lw $fp, 0($t0)\n");
				}else{
					printf("line #%d: not a function\n", line_number);
					(yyval.attr) = makeIllegalNode();
				}
			}else{
				printf("line #%d: imcompatible arguments\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 2641 "parse.y"
    {			
			
			element* func = findobject(current, (yyvsp[(1) - (3)].name), KALL);
			namenode* n = new namenode();
			n->name = (yyvsp[(1) - (3)].name)->name;
			n->next = NULL;
			element* obj = findobject(current, n , KALL);
			
				if(func->kind == KPRIMFUNCTION){
			
					fprintf(fp, "subu $sp, $sp, 4 #CALL %s\n", func->name.c_str());
					
					currentelement()->loc +=4;
					if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
					//~ if(func->pdtype==TDOUBLE || func->pdtype==TLONG){
						//~ fprintf(fp, "subu $sp, $sp, 4\n");
						//~ fprintf(fp, "move $t0, $sp\n");//making space for return value
						//~ currentelement()->loc +=4;
					//~ }
					(yyval.attr) = makePrimNode(string(), KVARIABLE, func->pdtype, vector<int>(), currentelement()->loc, ANONE, NULL);
					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $fp, ($sp)\n");//store $fp
					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $ra, ($sp)\n");//store $ra
					fprintf(fp, "subu $sp, $sp, 8\n");//set up call stack
					fprintf(fp, "lw $t1, -%d($fp)\n", obj->loc);//getting access link
					fprintf(fp, "sw $t1, ($sp)\n");//storing access link
					fprintf(fp, "addu $s0, $sp, 4\n");

					fprintf(fp, "move $fp, $s0\n");
					fprintf(fp, "jal %s%s\n", func->desc->parent->elem->name.c_str(), func->name.c_str());
					if(func->pdtype!=TVOID){
						fprintf(fp, "lw $t0, 0($fp)\n");//store the return value in t0
						fprintf(fp, "lw $t0, 0($t0)\n");//store the return value in t0	
					}
					fprintf(fp, "addu $t1, $fp, 12\n");//$t1: address to caller's space for return value
					fprintf(fp, "sw $t0, ($t1)\n");
					//~ if(func->pdtype==TDOUBLE || func->pdtype==TLONG){
						//~ fprintf(fp, "lw $t0, 4($fp)\n");//store the return value in t0
						//~ fprintf(fp, "addu $t1, $fp, 12\n");//$t1: address to caller's space for return value
						//~ fprintf(fp, "sw $t0, $t1\n");
					//~ }
					fprintf(fp, "addu $t0, $fp, 4\n");
					fprintf(fp, "lw $ra, ($t0)\n");
					fprintf(fp, "addu $t0, $fp, 12\n");
					fprintf(fp, "move $sp, $t0\n");
					fprintf(fp, "addu $t0, $fp, 8\n");
					fprintf(fp, "lw $fp, ($t0)\n");
				}else if(func->kind == KREFFUNCTION){
					fprintf(fp, "subu $sp, $sp, 4 #CALL %s\n", func->name.c_str());
					
					currentelement()->loc +=4;
					if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
					(yyval.attr) = makeRefNode(string(), KOBJECT, func->rdtype, vector<int>(), NULL, ANONE, NULL, NULL, NULL);

					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $fp, 0($sp)\n");//store $fp
					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $ra, ($sp)\n");//store $ra
					fprintf(fp, "subu $sp, $sp, 8\n");//set up call stack
					fprintf(fp, "lw $t1, -4($fp)\n");//getting access link
					fprintf(fp, "sw $t1, ($sp)\n");//storing access link
					fprintf(fp, "addu $s0, $sp, 4\n");

					fprintf(fp, "move $fp, $s0\n");
					fprintf(fp, "jal %s%s\n", func->desc->parent->elem->name.c_str(), func->name.c_str());
					if(func->pdtype!=TVOID){
						fprintf(fp, "lw $t0, 0($fp)\n");//store the return value in t0
						fprintf(fp, "lw $t0, 0($t0)\n");//store the return value in t0	
					}
					fprintf(fp, "addu $t1, $fp, 12\n");//$t1: address to caller's space for return value
					fprintf(fp, "sw $t0, ($t1)\n");
					//~ if(func->pdtype==TDOUBLE || func->pdtype==TLONG){
						//~ fprintf(fp, "lw $t0, 4($fp)\n");//store the return value in t0
						//~ fprintf(fp, "addu $t1, $fp, 12\n");//$t1: address to caller's space for return value
						//~ fprintf(fp, "sw $t0, $t1\n");
					//~ }
					fprintf(fp, "addu $t0, $fp, 4\n");
					fprintf(fp, "lw $ra, ($t0)\n");
					fprintf(fp, "addu $t0, $fp, 12\n");
					fprintf(fp, "move $sp, $t0\n");
					fprintf(fp, "addu $t0, $fp, 8\n");
					fprintf(fp, "lw $fp, ($t0)\n");
				}else{
					printf("line #%d: not a function\n", line_number);
					(yyval.attr) = makeIllegalNode();
				}
		}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 2734 "parse.y"
    {
			namenode* newnode = new namenode();
			newnode->name = string((yyvsp[(3) - (6)].sval));
			element* e = findtypeinthisorsuper((yyvsp[(1) - (6)].attr), newnode, true);
			if(e==NULL){
				printf("line #%d: method not found\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}else{
				element* func = e;
				if(!iscoerciblelist(func->arguments, NULL)){
					printf("line #%d: incompatible arguments\n", line_number);
					(yyval.attr) = makeIllegalNode();
				}else{
					if(func->kind == KPRIMFUNCTION){
					fprintf(fp, "subu $sp, $sp, 4 #CALL %s.%s\n", (yyvsp[(1) - (6)].attr)->name.c_str(), (yyvsp[(3) - (6)].sval));
					
					currentelement()->loc +=4;
					if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
					//~ if(func->pdtype==TDOUBLE || func->pdtype==TLONG){
						//~ fprintf(fp, "subu $sp, $sp, 4\n");
						//~ fprintf(fp, "move $t0, $sp\n");//making space for return value
						//~ currentelement()->loc +=4;
					//~ }
					(yyval.attr) = makePrimNode(string(), KVARIABLE, func->pdtype, vector<int>(), currentelement()->loc, ANONE, NULL);
					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $fp, ($sp)\n");//store $fp
					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $ra, ($sp)\n");//store $ra
					fprintf(fp, "subu $sp, $sp, 8\n");//set up call stack
					fprintf(fp, "lw $t1, -%d($fp)\n", (yyvsp[(1) - (6)].attr)->loc);//getting access link
					fprintf(fp, "sw $t1, ($sp)\n");//storing access link
					fprintf(fp, "addu $s0, $sp, 4\n");
					
					listofelements* e = (yyvsp[(5) - (6)].elist);
					while(e!=NULL){
						if(e->elem->kind==KPRIMITIVE || e->elem->kind==KVARIABLE || e->elem->kind==KLITERAL){
							fprintf(fp, "subu $sp, $sp, 4\n");
							fetchint0(e->elem);
							fprintf(fp, "sw $t0, ($sp)\n", e->elem->loc);
						}else{
							fprintf(fp, "subu $sp, $sp, 4\n");
							fprintf(fp, "lw $t0, -%d($fp)\n", e->elem->loc);
							fprintf(fp, "sw $t0, ($sp)\n");
						}
						e=e->next;
					}
					fprintf(fp, "move $fp, $s0\n");
					fprintf(fp, "jal %s%s\n", func->desc->parent->elem->name.c_str(), func->name.c_str());
					if(func->pdtype!=TVOID){
						fprintf(fp, "lw $t0, 0($fp)\n");//store the return value in t0
						fprintf(fp, "lw $t0, 0($t0)\n");//store the return value in t0	
					}
					fprintf(fp, "addu $t1, $fp, 12\n");//$t1: address to caller's space for return value
					fprintf(fp, "sw $t0, ($t1)\n");
					//~ if(func->pdtype==TDOUBLE || func->pdtype==TLONG){
						//~ fprintf(fp, "lw $t0, 4($fp)\n");//store the return value in t0
						//~ fprintf(fp, "addu $t1, $fp, 12\n");//$t1: address to caller's space for return value
						//~ fprintf(fp, "sw $t0, $t1\n");
					//~ }
					fprintf(fp, "addu $t0, $fp, 4\n");
					fprintf(fp, "lw $ra, ($t0)\n");
					fprintf(fp, "addu $t0, $fp, 12\n");
					fprintf(fp, "move $sp, $t0\n");
					fprintf(fp, "addu $t0, $fp, 8\n");
					fprintf(fp, "lw $fp, ($t0)\n");
				}else if(func->kind == KREFFUNCTION){
					fprintf(fp, "subu $sp, $sp, 4 #CALL %s.%s\n", (yyvsp[(1) - (6)].attr)->name.c_str(), (yyvsp[(3) - (6)].sval));
					
					currentelement()->loc +=4;
					if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
					(yyval.attr) = makeRefNode(string(), KOBJECT, func->rdtype, vector<int>(), NULL, ANONE, NULL, NULL, NULL);

					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $fp, ($sp)\n");//store $fp
					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $ra, ($sp)\n");//store $ra
					fprintf(fp, "subu $sp, $sp, 8\n");//set up call stack
					fprintf(fp, "lw $t1, -%d($fp)\n", (yyvsp[(1) - (6)].attr)->loc);//getting access link
					fprintf(fp, "sw $t1, ($sp)\n");//storing access link
					fprintf(fp, "addu $s0, $sp, 4\n");
					
					listofelements* e = (yyvsp[(5) - (6)].elist);
					while(e!=NULL){
						if(e->elem->kind==KPRIMITIVE || e->elem->kind==KVARIABLE || e->elem->kind==KLITERAL){
							fprintf(fp, "subu $sp, $sp, 4\n");
							fetchint0(e->elem);
							fprintf(fp, "sw $t0, ($sp)\n", e->elem->loc);
						}else{
							fprintf(fp, "subu $sp, $sp, 4\n");
							fprintf(fp, "lw $t0, -%d($fp)\n", e->elem->loc);
							fprintf(fp, "sw $t0, ($sp)\n");
						}
						e=e->next;
					}
					fprintf(fp, "move $fp, $s0\n");
					fprintf(fp, "jal %s%s\n", func->desc->parent->elem->name.c_str(), func->name.c_str());
					if(func->pdtype!=TVOID){
						fprintf(fp, "lw $t0, 0($fp)\n");//store the return value in t0
						fprintf(fp, "lw $t0, 0($t0)\n");//store the return value in t0	
					}
					fprintf(fp, "addu $t1, $fp, 12\n");//$t1: address to caller's space for return value
					fprintf(fp, "sw $t0, ($t1)\n");
					//~ if(func->pdtype==TDOUBLE || func->pdtype==TLONG){
						//~ fprintf(fp, "lw $t0, 4($fp)\n");//store the return value in t0
						//~ fprintf(fp, "addu $t1, $fp, 12\n");//$t1: address to caller's space for return value
						//~ fprintf(fp, "sw $t0, $t1\n");
					//~ }
					fprintf(fp, "addu $t0, $fp, 4\n");
					fprintf(fp, "lw $ra, ($t0)\n");
					fprintf(fp, "addu $t0, $fp, 12\n");
					fprintf(fp, "move $sp, $t0\n");
					fprintf(fp, "addu $t0, $fp, 8\n");
					fprintf(fp, "lw $fp, ($t0)\n");
					}else{
						printf("line #%d: not a function\n", line_number);
						(yyval.attr) = makeIllegalNode();
					}
				}
			}
		}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 2860 "parse.y"
    {
			namenode* newnode = new namenode();
			newnode->name = string((yyvsp[(3) - (5)].sval));
			element* e = findtypeinthisorsuper((yyvsp[(1) - (5)].attr), newnode, true);
			if(e==NULL){
				printf("line #%d: method not found\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}else{
				element* func = e;
				if(func->kind == KPRIMFUNCTION){
				fprintf(fp, "subu $sp, $sp, 4 #CALL %s.%s\n", (yyvsp[(1) - (5)].attr)->name.c_str(), (yyvsp[(3) - (5)].sval));
				
				currentelement()->loc +=4;
				if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
				//~ if(func->pdtype==TDOUBLE || func->pdtype==TLONG){
					//~ fprintf(fp, "subu $sp, $sp, 4\n");
					//~ fprintf(fp, "move $t0, $sp\n");//making space for return value
					//~ currentelement()->loc +=4;
				//~ }
				(yyval.attr) = makePrimNode(string(), KVARIABLE, func->pdtype, vector<int>(), currentelement()->loc, ANONE, NULL);
				fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
				fprintf(fp, "sw $fp, ($sp)\n");//store $fp
				fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
				fprintf(fp, "sw $ra, ($sp)\n");//store $ra
				fprintf(fp, "subu $sp, $sp, 8\n");//set up call stack
				fprintf(fp, "lw $t1, -4($fp)\n");//getting access link
				fprintf(fp, "sw $t1, 0($sp)\n");//storing access link
				fprintf(fp, "addu $s0, $sp, 4\n");
				

				fprintf(fp, "move $fp, $s0\n");
				fprintf(fp, "jal %s%s\n", func->desc->parent->elem->name.c_str(),  func->name.c_str());
				if(func->pdtype!=TVOID){
						fprintf(fp, "lw $t0, 0($fp)\n");//store the return value in t0
						fprintf(fp, "lw $t0, 0($t0)\n");//store the return value in t0	
					}
				fprintf(fp, "addu $t1, $fp, 12\n");//$t1: address to caller's space for return value
				fprintf(fp, "sw $t0, ($t1)\n");
				//~ if(func->pdtype==TDOUBLE || func->pdtype==TLONG){
					//~ fprintf(fp, "lw $t0, 4($fp)\n");//store the return value in t0
					//~ fprintf(fp, "addu $t1, $fp, 12\n");//$t1: address to caller's space for return value
					//~ fprintf(fp, "sw $t0, $t1\n");
				//~ }
				fprintf(fp, "addu $t0, $fp, 4\n");
				fprintf(fp, "lw $ra, ($t0)\n");
				fprintf(fp, "addu $t0, $fp, 12\n");
				fprintf(fp, "move $sp, $t0\n");
				fprintf(fp, "addu $t0, $fp, 8\n");
				fprintf(fp, "lw $fp, ($t0)\n");
			}else if(func->kind == KREFFUNCTION){
				fprintf(fp, "subu $sp, $sp, 4 #CALL %s.%s\n", (yyvsp[(1) - (5)].attr)->name.c_str(), (yyvsp[(3) - (5)].sval));
				
				currentelement()->loc +=4;
				if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
				(yyval.attr) = makeRefNode(string(), KOBJECT, func->rdtype, vector<int>(), NULL, ANONE, NULL, NULL, NULL);

				fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
				fprintf(fp, "sw $fp, ($sp)\n");//store $fp
				fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
				fprintf(fp, "sw $ra, ($sp)\n");//store $ra
				fprintf(fp, "subu $sp, $sp, 8\n");//set up call stack
				fprintf(fp, "lw $t1, -4($fp)\n");//getting access link
				fprintf(fp, "sw $t1, ($sp)\n");//storing access link
				fprintf(fp, "addu $s0, $sp, 4\n");
				
				fprintf(fp, "move $fp, $s0\n");
				fprintf(fp, "jal %s%s\n", func->desc->parent->elem->name.c_str(), func->name.c_str());
				if(func->pdtype!=TVOID){
						fprintf(fp, "lw $t0, 0($fp)\n");//store the return value in t0
						fprintf(fp, "lw $t0, 0($t0)\n");//store the return value in t0	
					}
				fprintf(fp, "addu $t1, $fp, 12\n");//$t1: address to caller's space for return value
				fprintf(fp, "sw $t0, ($t1)\n");
				//~ if(func->pdtype==TDOUBLE || func->pdtype==TLONG){
					//~ fprintf(fp, "lw $t0, 4($fp)\n");//store the return value in t0
					//~ fprintf(fp, "addu $t1, $fp, 12\n");//$t1: address to caller's space for return value
					//~ fprintf(fp, "sw $t0, $t1\n");
				//~ }
				fprintf(fp, "addu $t0, $fp, 4\n");
				fprintf(fp, "lw $ra, ($t0)\n");
				fprintf(fp, "addu $t0, $fp, 12\n");
				fprintf(fp, "move $sp, $t0\n");
				fprintf(fp, "addu $t0, $fp, 8\n");
				fprintf(fp, "lw $fp, ($t0)\n");
			}else{
				printf("line #%d: not a function\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
			
		}
	}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 2956 "parse.y"
    {
			scope* s = current;
			while(s->elem->kind != KCLASS) s = s->parent;
			element* sup = s->elem;
			namenode* newnode = new namenode();
			newnode->name = string((yyvsp[(3) - (5)].sval));
			element* e = findtypeinthisorsuper(sup, newnode, true);
			if(e==NULL){
				printf("line #%d: method %s not found\n", line_number, (yyvsp[(3) - (5)].sval));
				(yyval.attr) = makeIllegalNode();
			}else if((e->kind!=KPRIMFUNCTION && e->kind!=KREFFUNCTION)){
				printf("line #%d: %s not a method\n", line_number, (yyvsp[(3) - (5)].sval));
				(yyval.attr) = makeIllegalNode();
			}else{
				element* func = e;
				if(!iscoerciblelist(func->arguments, NULL)){
					printf("line #%d: incompatible arguments\n", line_number);
					(yyval.attr) = makeIllegalNode();
				}else{
				if(func->kind == KPRIMFUNCTION){
					fprintf(fp, "subu $sp, $sp, 4 #CALL SUPER.%s\n", (yyvsp[(3) - (5)].sval));
					
					currentelement()->loc +=4;
					if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
					//~ if(func->pdtype==TDOUBLE || func->pdtype==TLONG){
						//~ fprintf(fp, "subu $sp, $sp, 4\n");
						//~ fprintf(fp, "move $t0, $sp\n");//making space for return value
						//~ currentelement()->loc +=4;
					//~ }
					(yyval.attr) = makePrimNode(string(), KVARIABLE, func->pdtype, vector<int>(), currentelement()->loc, ANONE, NULL);
					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $fp, ($sp)\n");//store $fp
					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $ra, ($sp)\n");//store $ra
					fprintf(fp, "subu $sp, $sp, 8\n");//set up call stack
					fprintf(fp, "lw $t1, -4($fp)\n");//getting access link
					fprintf(fp, "sw $t1, ($sp)\n");//storing access link
					fprintf(fp, "addu $s0, $sp, 4\n");
					
					fprintf(fp, "move $fp, $s0\n");
					fprintf(fp, "jal %s%s\n", func->desc->parent->elem->name.c_str(), func->name.c_str());
					if(func->pdtype!=TVOID){
						fprintf(fp, "lw $t0, 0($fp)\n");//store the return value in t0
						fprintf(fp, "lw $t0, 0($t0)\n");//store the return value in t0	
					}
					fprintf(fp, "addu $t1, $fp, 12\n");//$t1: address to caller's space for return value
					fprintf(fp, "sw $t0, ($t1)\n");
					//~ if(func->pdtype==TDOUBLE || func->pdtype==TLONG){
						//~ fprintf(fp, "lw $t0, 4($fp)\n");//store the return value in t0
						//~ fprintf(fp, "addu $t1, $fp, 12\n");//$t1: address to caller's space for return value
						//~ fprintf(fp, "sw $t0, $t1\n");
					//~ }
					fprintf(fp, "addu $t0, $fp, 4\n");
					fprintf(fp, "lw $ra, ($t0)\n");
					fprintf(fp, "addu $t0, $fp, 12\n");
					fprintf(fp, "move $sp, $t0\n");
					fprintf(fp, "addu $t0, $fp, 8\n");
					fprintf(fp, "lw $fp, ($t0)\n");
				}else if(func->kind == KREFFUNCTION){
					fprintf(fp, "subu $sp, $sp, 4 #CALL SUPER.%s\n", (yyvsp[(3) - (5)].sval));
					
					currentelement()->loc +=4;
					if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
					(yyval.attr) = makeRefNode(string(), KOBJECT, func->rdtype, vector<int>(), NULL, ANONE, NULL, NULL, NULL);

					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $fp, ($sp)\n");//store $fp
					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $ra, ($sp)\n");//store $ra
					fprintf(fp, "subu $sp, $sp, 8\n");//set up call stack
					fprintf(fp, "lw $t1, -4($fp)\n");//getting access link
					fprintf(fp, "sw $t1, ($sp)\n");//storing access link
					fprintf(fp, "addu $s0, $sp, 4\n");
					
					fprintf(fp, "move $fp, $s0\n");
					fprintf(fp, "jal %s%s\n", func->desc->parent->elem->name.c_str(), func->name.c_str());
					if(func->pdtype!=TVOID){
						fprintf(fp, "lw $t0, 0($fp)\n");//store the return value in t0
						fprintf(fp, "lw $t0, 0($t0)\n");//store the return value in t0	
					}
					fprintf(fp, "addu $t1, $fp, 12\n");//$t1: address to caller's space for return value
					fprintf(fp, "sw $t0, ($t1)\n");
					//~ if(func->pdtype==TDOUBLE || func->pdtype==TLONG){
						//~ fprintf(fp, "lw $t0, 4($fp)\n");//store the return value in t0
						//~ fprintf(fp, "addu $t1, $fp, 12\n");//$t1: address to caller's space for return value
						//~ fprintf(fp, "sw $t0, $t1\n");
					//~ }
					fprintf(fp, "addu $t0, $fp, 4\n");
					fprintf(fp, "lw $ra, ($t0)\n");
					fprintf(fp, "addu $t0, $fp, 12\n");
					fprintf(fp, "move $sp, $t0\n");
					fprintf(fp, "addu $t0, $fp, 8\n");
					fprintf(fp, "lw $fp, ($t0)\n");
					}else{
						printf("line #%d: not a function\n", line_number);
						(yyval.attr) = makeIllegalNode();
					}
				}
			}
		}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 3061 "parse.y"
    {
			scope* s = current;
			while(s->elem->kind != KCLASS) s = s->parent;
			element* sup = s->elem;
			namenode* newnode = new namenode();
			newnode->name = string((yyvsp[(3) - (6)].sval));
			element* e = findtypeinthisorsuper(sup, newnode, true);
			if(e==NULL){
				printf("line #%d: method %s not found\n", line_number, (yyvsp[(3) - (6)].sval));
				(yyval.attr) = makeIllegalNode();
			}else if((e->kind!=KPRIMFUNCTION && e->kind!=KREFFUNCTION)){
				printf("line #%d: %s not a method\n", line_number, (yyvsp[(3) - (6)].sval));
				(yyval.attr) = makeIllegalNode();
			}else{
				element* func = e;
				if(!iscoerciblelisttolist(func->arguments, (yyvsp[(5) - (6)].elist))){
					printf("line #%d: incompatible arguments\n", line_number);
					(yyval.attr) = makeIllegalNode();
				}else{
					if(func->kind == KPRIMFUNCTION){
					fprintf(fp, "subu $sp, $sp, 4 #CALL SUPER.%s\n", (yyvsp[(3) - (6)].sval));
					
					currentelement()->loc +=4;
					if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
					//~ if(func->pdtype==TDOUBLE || func->pdtype==TLONG){
						//~ fprintf(fp, "subu $sp, $sp, 4\n");
						//~ fprintf(fp, "move $t0, $sp\n");//making space for return value
						//~ currentelement()->loc +=4;
					//~ }
					(yyval.attr) = makePrimNode(string(), KVARIABLE, func->pdtype, vector<int>(), currentelement()->loc, ANONE, NULL);
					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $fp, ($sp)\n");//store $fp
					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $ra, ($sp)\n");//store $ra
					fprintf(fp, "subu $sp, $sp, 8\n");//set up call stack
					fprintf(fp, "lw $t1, -4($fp)\n");//getting access link
					fprintf(fp, "sw $t1, ($sp)\n");//storing access link
					fprintf(fp, "addu $s0, $sp, 4\n");
					
					listofelements* e = (yyvsp[(5) - (6)].elist);
					while(e!=NULL){
						if(e->elem->kind==KPRIMITIVE || e->elem->kind==KVARIABLE || e->elem->kind==KLITERAL){
							fprintf(fp, "subu $sp, $sp, 4\n");
							fetchint0(e->elem);
							fprintf(fp, "sw $t0, ($sp)\n", e->elem->loc);
						}else{
							fprintf(fp, "subu $sp, $sp, 4\n");
							fprintf(fp, "lw $t0, -%d($fp)\n", e->elem->loc);
							fprintf(fp, "sw $t0, ($sp)\n");
						}
						e=e->next;
					}
					fprintf(fp, "move $fp, $s0\n");
					fprintf(fp, "jal %s%s\n", func->desc->parent->elem->name.c_str(), func->name.c_str());
					if(func->pdtype!=TVOID){
						fprintf(fp, "lw $t0, 0($fp)\n");//store the return value in t0
						fprintf(fp, "lw $t0, 0($t0)\n");//store the return value in t0	
					}
					fprintf(fp, "addu $t1, $fp, 12\n");//$t1: address to caller's space for return value
					fprintf(fp, "sw $t0, ($t1)\n");
					//~ if(func->pdtype==TDOUBLE || func->pdtype==TLONG){
						//~ fprintf(fp, "lw $t0, 4($fp)\n");//store the return value in t0
						//~ fprintf(fp, "addu $t1, $fp, 12\n");//$t1: address to caller's space for return value
						//~ fprintf(fp, "sw $t0, $t1\n");
					//~ }
					fprintf(fp, "addu $t0, $fp, 4\n");
					fprintf(fp, "lw $ra, ($t0)\n");
					fprintf(fp, "addu $t0, $fp, 12\n");
					fprintf(fp, "move $sp, $t0\n");
					fprintf(fp, "addu $t0, $fp, 8\n");
					fprintf(fp, "lw $fp, ($t0)\n");
				}else if(func->kind == KREFFUNCTION){
					fprintf(fp, "subu $sp, $sp, 4\n");
					
					currentelement()->loc +=4;
					if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
					(yyval.attr) = makeRefNode(string(), KOBJECT, func->rdtype, vector<int>(), NULL, ANONE, NULL, NULL, NULL);

					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $fp, ($sp)\n");//store $fp
					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $ra, ($sp)\n");//store $ra
					fprintf(fp, "subu $sp, $sp, 8\n");//set up call stack
					fprintf(fp, "lw $t1, -4($fp)\n");//getting access link
					fprintf(fp, "sw $t1, ($sp)\n");//storing access link
					fprintf(fp, "addu $s0, $sp, 4\n");
					
					listofelements* e = (yyvsp[(5) - (6)].elist);
					while(e!=NULL){
						if(e->elem->kind==KPRIMITIVE || e->elem->kind==KVARIABLE || e->elem->kind==KLITERAL){
							fprintf(fp, "subu $sp, $sp, 4\n");
							fetchint0(e->elem);
							fprintf(fp, "sw $t0, ($sp)\n", e->elem->loc);
						}else{
							fprintf(fp, "subu $sp, $sp, 4\n");
							fprintf(fp, "lw $t0, -%d($fp)\n", e->elem->loc);
							fprintf(fp, "sw $t0, ($sp)\n");
						}
						e=e->next;
					}
					fprintf(fp, "move $fp, $s0\n");
					fprintf(fp, "jal %s%s\n", func->desc->parent->elem->name.c_str(), func->name.c_str());
					if(func->pdtype!=TVOID){
						fprintf(fp, "lw $t0, 0($fp)\n");//store the return value in t0
						fprintf(fp, "lw $t0, 0($t0)\n");//store the return value in t0	
					}
					fprintf(fp, "addu $t1, $fp, 12\n");//$t1: address to caller's space for return value
					fprintf(fp, "sw $t0, ($t1)\n");
					//~ if(func->pdtype==TDOUBLE || func->pdtype==TLONG){
						//~ fprintf(fp, "lw $t0, 4($fp)\n");//store the return value in t0
						//~ fprintf(fp, "addu $t1, $fp, 12\n");//$t1: address to caller's space for return value
						//~ fprintf(fp, "sw $t0, $t1\n");
					//~ }
					fprintf(fp, "addu $t0, $fp, 4\n");
					fprintf(fp, "lw $ra, ($t0)\n");
					fprintf(fp, "addu $t0, $fp, 12\n");
					fprintf(fp, "move $sp, $t0\n");
					fprintf(fp, "addu $t0, $fp, 8\n");
					fprintf(fp, "lw $fp, ($t0)\n");
					}else{
						printf("line #%d: not a function\n", line_number);
						(yyval.attr) = makeIllegalNode();
					}
				}
			}
		}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 3192 "parse.y"
    {
			
			fprintf(fp, "lw $a0, -%d($fp)\n", (yyvsp[(3) - (4)].attr)->loc);
			fprintf(fp, "li $v0, 4\n");
			fprintf(fp, "syscall\n");
			(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TVOID, vector<int>(), 0, ANONE, NULL);
		}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 3200 "parse.y"
    {
			fetchint0((yyvsp[(3) - (4)].attr));
			fprintf(fp, "move $a0, $t0\n");
			fprintf(fp, "li $v0, 1\n");
			fprintf(fp, "syscall\n");
			(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TVOID, vector<int>(), 0, ANONE, NULL);
		}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 3208 "parse.y"
    {
			
			fprintf(fp, "lwc1 $f12, -%d($fp)\n", (yyvsp[(3) - (4)].attr)->loc);
			//fprintf(fp, "li.s $f12, 34.23\n");
			//fprintf(fp, "mov.s $f12, $f0\n");
			fprintf(fp, "li $v0, 2\n");
			fprintf(fp, "syscall\n");
			(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TVOID, vector<int>(), 0, ANONE, NULL);
		}
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 3223 "parse.y"
    {
			element* elem = findobject(current, (yyvsp[(1) - (4)].name), KALL);
			//ASSERT(elem->kind == KVARIABLE || elem->kind == KOBJECT);
			if(elem==NULL){
				printf("line #%d: array not accessible\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}else if(!iscoercible((yyvsp[(3) - (4)].attr), makePrimNode(string(), KPRIMITIVE, TINT, vector<int>(), NULL, ANONE, NULL))){
				printf("line #%d: expecting expression convertible to int\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}else{
				if(elem->kind == KVARIABLE){
					std::vector<int>::size_type sz = elem->dimensions.size();
					fprintf(fp, "li $s0, 1\n");
					for(unsigned i=1; i<sz; i++){
						fprintf(fp, "lw $t1, -%d($fp)\n", ((elem->dimensions))[i]);
						fprintf(fp, "multu $s0, $t1\n");
						fprintf(fp, "mflo $s0\n");
					}
					fprintf(fp, "li $t1, %d\n", sizeofelement(elem));
					fprintf(fp, "multu $s0, $t1\n");
					fprintf(fp, "mflo $s0\n");
					fetchint0((yyvsp[(3) - (4)].attr));//value of expression in t0
					
					fprintf(fp, "multu $s0, $t0\n");
					fprintf(fp, "mflo $s0\n");
					fprintf(fp, "lw $t0, -%d($fp)\n", elem->loc);
					fprintf(fp, "addu $t0, $t0, $s0\n");
					fprintf(fp, "subu $sp, $sp, 4\n");
					currentelement()->loc +=4;
					if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
					fprintf(fp, "sw $t0, ($sp)\n");
					
					vector<int>* vec = (vector<int>*)malloc(sizeof(vector<int>));
					vector<int> tail (elem->dimensions.begin()+1, elem->dimensions.end());
					(*vec).insert((*vec).end(), tail.begin(), tail.end());
					fprintf(stderr, "(*vec).size()=%d\n", (*vec).size());
					fprintf(stderr, "(elem->dimensions).size()=%d\n", (elem->dimensions).size());
					
					
					element* e = makePrimNode(string(), KVARIABLE, elem->pdtype, *vec, currentelement()->loc, ANONE, NULL);
					e->amode=REFERENCE;
					(yyval.attr) = e;
					
				}else if(elem->kind == KOBJECT){
					std::vector<int>::size_type sz = elem->dimensions.size();
					fprintf(fp, "li $s0, 1\n");
					for(unsigned i=1; i<sz; i++){
						fprintf(fp, "lw $t1, -%d($fp)\n", ((elem->dimensions))[i]);
						fprintf(fp, "multu $s0, $t1\n");
						fprintf(fp, "mflo $s0\n");
					}
					fprintf(fp, "li $t1, %d\n", sizeofelement(elem));
					fprintf(fp, "multu $s0, $t1\n");
					fprintf(fp, "mflo $s0\n");
					fetchint0((yyvsp[(3) - (4)].attr));
					
					fprintf(fp, "multu $s0, $t0\n");
					fprintf(fp, "mflo $s0\n");
					fprintf(fp, "lw $t0, -%d($fp)\n", elem->loc);
					fprintf(fp, "addu $t0, $t0, $s0\n");
					fprintf(fp, "subu $sp, $sp, 4\n");
					currentelement()->loc +=4;
					if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
					fprintf(fp, "sw $t0, 0($sp)\n");
					
					vector<int>* vec = (vector<int>*)malloc(sizeof(vector<int>));
					vector<int> tail (elem->dimensions.begin()+1, elem->dimensions.end());
					(*vec).insert((*vec).end(), tail.begin(), tail.end());
					fprintf(stderr, "(*vec).size()=%d\n", (*vec).size());
					fprintf(stderr, "(elem->dimensions).size()=%d\n", (elem->dimensions).size());
					
					
					element* e = makeRefNode(string(), KOBJECT, elem->rdtype, *vec, currentelement()->loc, ANONE, NULL, NULL, NULL);
					e->amode=REFERENCE;
					(yyval.attr) = e;
		
					
					
					
					
				}else{
					printf("line #%d: not a variable or an object\n", line_number);
					(yyval.attr) = makeIllegalNode();
				}
			}
		}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 3314 "parse.y"
    {
			element* elem = (yyvsp[(1) - (4)].attr);
			if(!iscoercible((yyvsp[(3) - (4)].attr), makePrimNode(string(), KPRIMITIVE, TINT, vector<int>(), NULL, ANONE, NULL))){
				printf("line #%d: expecting expression convertible to int\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}else{
				if(elem==NULL || elem->kind == KILLEGAL){
					printf("line #%d: object/variable not accessible\n", line_number);
					(yyval.attr) = makeIllegalNode();
				}else if(elem->kind == KVARIABLE){
					std::vector<int>::size_type sz = elem->dimensions.size();
					fprintf(fp, "li $s0, 1\n");
					for(unsigned i=1; i<sz; i++){
						fprintf(fp, "lw $t1, -%d($fp)\n", ((elem->dimensions))[i]);
						fprintf(fp, "multu $s0, $t1\n");
						fprintf(fp, "mflo $s0\n");
					}
					fprintf(fp, "li $t1, %d\n", sizeofelement(elem));
					fprintf(fp, "multu $s0, $t1\n");
					fprintf(fp, "mflo $s0\n");
					fetchint0((yyvsp[(3) - (4)].attr));
					
					fprintf(fp, "multu $s0, $t0\n");
					fprintf(fp, "mflo $s0\n");
					fprintf(fp, "lw $t0, -%d($fp)\n", elem->loc);
					fprintf(fp, "addu $t0, $t0, $s0\n");
					fprintf(fp, "subu $sp, $sp, 4\n");
					currentelement()->loc +=4;					
					if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
					fprintf(fp, "sw $t0, 0($sp)\n");
					
					vector<int>* vec = (vector<int>*)malloc(sizeof(vector<int>));
					vector<int> tail (elem->dimensions.begin()+1, elem->dimensions.end());
					(*vec).insert((*vec).end(), tail.begin(), tail.end());
					fprintf(stderr, "(*vec).size()=%d\n", (*vec).size());
					fprintf(stderr, "(elem->dimensions).size()=%d\n", (elem->dimensions).size());
					
					
					element* e = makePrimNode(string(), KVARIABLE, elem->pdtype, *vec, currentelement()->loc, ANONE, NULL);
					e->amode=REFERENCE;
					(yyval.attr) = e;					
					
				}else if(elem->kind == KOBJECT){
					std::vector<int>::size_type sz = elem->dimensions.size();
					fprintf(fp, "li $s0, 1\n");
					for(unsigned i=1; i<sz; i++){
						fprintf(fp, "lw $t1, -%d($fp)\n", ((elem->dimensions))[i]);
						fprintf(fp, "multu $s0, $t1\n");
						fprintf(fp, "mflo $s0\n");
					}
					fprintf(fp, "li $t1, %d\n", sizeofelement(elem));
					fprintf(fp, "multu $s0, $t1\n");
					fprintf(fp, "mflo $s0\n");
					fetchint0((yyvsp[(3) - (4)].attr));
					
					fprintf(fp, "multu $s0, $t0\n");
					fprintf(fp, "mflo $s0\n");
					fprintf(fp, "lw $t0, -%d($fp)\n", elem->loc);
					fprintf(fp, "addu $t0, $t0, $s0\n");
					fprintf(fp, "subu $sp, $sp, 4\n");
					currentelement()->loc +=4;
					if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
					fprintf(fp, "sw $t0, 0($sp)\n");
					
					vector<int>* vec = (vector<int>*)malloc(sizeof(vector<int>));
					vector<int> tail (elem->dimensions.begin()+1, elem->dimensions.end());
					(*vec).insert((*vec).end(), tail.begin(), tail.end());
					fprintf(stderr, "(*vec).size()=%d\n", (*vec).size());
					fprintf(stderr, "(elem->dimensions).size()=%d\n", (elem->dimensions).size());
					
					
					element* e = makeRefNode(string(), KOBJECT, elem->rdtype, *vec, currentelement()->loc, ANONE, NULL, NULL, NULL);
					e->amode=REFERENCE;
					(yyval.attr) = e;					
							
				}
			}
		}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 3399 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 3400 "parse.y"
    {(yyval.attr) = findobject(current, (yyvsp[(1) - (1)].name), KALL);}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 3401 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 3402 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 3407 "parse.y"
    {
			if((yyvsp[(1) - (2)].attr)->amode==DIRECT){
				fprintf(fp, "lw $s0, -%d($fp) #PostIncrementExpression\n", (yyvsp[(1) - (2)].attr)->loc);
				fprintf(fp, "move $t0, $s0\n");
				fprintf(fp, "addi $t0, $t0, 1\n");
				fprintf(fp, "sw $t0, -%d($fp)\n", (yyvsp[(1) - (2)].attr)->loc);
			}else{
				fprintf(fp, "lw $t1, -%d($fp) #PostIncrementExpression\n", (yyvsp[(1) - (2)].attr)->loc);
				fprintf(fp, "lw $s0, 0($t1)\n");
				fprintf(fp, "move $t0, $s0\n");
				fprintf(fp, "addi $t0, $t0, 1\n");
				fprintf(fp, "sw $t0, 0($t1)\n", (yyvsp[(1) - (2)].attr)->loc);				
			}
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "sw $s0, 0($sp)\n");
			element* e = copyelement((yyvsp[(1) - (2)].attr));
			e->loc = currentelement()->loc;
			(yyval.attr) = e;
		}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 3434 "parse.y"
    {
			if((yyvsp[(1) - (2)].attr)->amode==DIRECT){
				fprintf(fp, "lw $s0, -%d($fp) #PostDecrementExpression\n", (yyvsp[(1) - (2)].attr)->loc);
				fprintf(fp, "move $t0, $s0\n");
				fprintf(fp, "addi $t0, $t0, -1\n");
				fprintf(fp, "sw $t0, -%d($fp)\n", (yyvsp[(1) - (2)].attr)->loc);
			}else{
				fprintf(fp, "lw $t1, -%d($fp) #PostDecrementExpression\n", (yyvsp[(1) - (2)].attr)->loc);
				fprintf(fp, "lw $s0, 0($t1)\n");
				fprintf(fp, "move $t0, $s0\n");
				fprintf(fp, "addi $t0, $t0, -1\n");
				fprintf(fp, "sw $t0, 0($t1)\n", (yyvsp[(1) - (2)].attr)->loc);				
			}
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "sw $s0, 0($sp)\n");
			element* e = copyelement((yyvsp[(1) - (2)].attr));
			e->loc = currentelement()->loc;
			(yyval.attr) = e;
		}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 3460 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 315:

/* Line 1455 of yacc.c  */
#line 3461 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 316:

/* Line 1455 of yacc.c  */
#line 3462 "parse.y"
    {(yyval.attr) = (yyvsp[(2) - (2)].attr);}
    break;

  case 317:

/* Line 1455 of yacc.c  */
#line 3464 "parse.y"
    {
			fetchint0((yyvsp[(2) - (2)].attr));
			fprintf(fp, "li $t1, -1 #UnaryExpression\n");
			fprintf(fp, "mult $t0, $t1\n");
			fprintf(fp, "mflo $t0\n");
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "sw $t0, 0($sp)\n");
			element* e = copyelement((yyvsp[(2) - (2)].attr));
			e->loc = currentelement()->loc;
			(yyval.attr) = e;
		}
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 3479 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 3484 "parse.y"
    {
			if((yyvsp[(2) - (2)].attr)->amode==DIRECT){
				fprintf(fp, "lw $t0, -%d($fp) #PreIncrementExpression\n", (yyvsp[(2) - (2)].attr)->loc);
				
				fprintf(fp, "addi $t0, $t0, +1\n");
				fprintf(fp, "sw $t0, -%d($fp)\n", (yyvsp[(2) - (2)].attr)->loc);
			}else{
				fprintf(fp, "lw $t1, -%d($fp) #PreIncrementExpression\n", (yyvsp[(2) - (2)].attr)->loc);
				fprintf(fp, "lw $t0, 0($t1)\n");
				
				fprintf(fp, "addi $t0, $t0, +1\n");
				fprintf(fp, "sw $t0, 0($t1)\n", (yyvsp[(2) - (2)].attr)->loc);				
			}
			(yyval.attr) = (yyvsp[(2) - (2)].attr);
		}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 3503 "parse.y"
    {
			if((yyvsp[(2) - (2)].attr)->amode==DIRECT){
				fprintf(fp, "lw $t0, -%d($fp) #PreDecrementExpression\n", (yyvsp[(2) - (2)].attr)->loc);
				
				fprintf(fp, "addi $t0, $t0, -1\n");
				fprintf(fp, "sw $t0, -%d($fp)\n", (yyvsp[(2) - (2)].attr)->loc);
			}else{
				fprintf(fp, "lw $t1, -%d($fp) #PreDecrementExpression\n", (yyvsp[(2) - (2)].attr)->loc);
				fprintf(fp, "lw $t0, 0($t1)\n");
				
				fprintf(fp, "addi $t0, $t0, -1\n");
				fprintf(fp, "sw $t0, 0($t1)\n", (yyvsp[(2) - (2)].attr)->loc);				
			}
			(yyval.attr) = (yyvsp[(2) - (2)].attr);
		}
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 3520 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 3522 "parse.y"
    {
		fetchint0((yyvsp[(2) - (2)].attr));
		fprintf(fp, "xori $t0, $t0, -1 #UnaryExpressionNotPlusMinus\n");
		fprintf(fp, "subu $sp, $sp, 4\n");
		currentelement()->loc +=4;
		if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
		fprintf(fp, "sw $t0, 0($sp)\n");
		element* e = copyelement((yyvsp[(2) - (2)].attr));
		e->loc = currentelement()->loc;
		(yyval.attr) = e;
	}
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 3536 "parse.y"
    {
			if(!iscoercible((yyvsp[(2) - (2)].attr), makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL))){
				printf("line #%d: expected boolean expression after !\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}else{
				fetchint0((yyvsp[(2) - (2)].attr));
				fprintf(fp, "xori $t0, $t0, 1 #UnaryExpressionNotPlusMinus\n");
				fprintf(fp, "subu $sp, $sp, 4\n");
				currentelement()->loc +=4;
				if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
				fprintf(fp, "sw $t0, 0($sp)\n");
				element* e = copyelement((yyvsp[(2) - (2)].attr));
				e->loc = currentelement()->loc;
				(yyval.attr) = e;
			}
		}
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 3554 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 3559 "parse.y"
    {
			printf("error at line %d: Not implemented\n", line_number);
			(yyvsp[(2) - (5)].attr)->dimensions = *(yyvsp[(3) - (5)].pspvec)->pvec;
			if(iscoercible((yyvsp[(5) - (5)].attr), (yyvsp[(2) - (5)].attr))){
				(yyval.attr) = copyandcoerce((yyvsp[(5) - (5)].attr), (yyvsp[(2) - (5)].attr));
			}else{
				printf("line #%d: type not coercible\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 3570 "parse.y"
    {
			if(iscoercible((yyvsp[(4) - (4)].attr), (yyvsp[(2) - (4)].attr))){
				(yyval.attr) = coerce((yyvsp[(4) - (4)].attr), (yyvsp[(2) - (4)].attr));
			}else{
				printf("line #%d: type not coercible\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 3579 "parse.y"
    {
			if(iscoercible((yyvsp[(4) - (4)].attr), (yyvsp[(2) - (4)].attr))){
				(yyval.attr) = coerce((yyvsp[(4) - (4)].attr), (yyvsp[(2) - (4)].attr));
			}else{
				printf("line #%d: type not coercible\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 3588 "parse.y"
    {
			printf("error at line %d: Not implemented\n", line_number);
			element* type = findtype(current, (yyvsp[(2) - (5)].name));
			type->dimensions = *((yyvsp[(3) - (5)].pspvec)->pvec);
			if(iscoercible((yyvsp[(5) - (5)].attr), type)){
				(yyval.attr) = copyandcoerce((yyvsp[(5) - (5)].attr), type);
			}else{
				printf("line #%d: type not coercible\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 3602 "parse.y"
    { (yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 3604 "parse.y"
    {
			fetchint0((yyvsp[(1) - (3)].attr));
			fprintf(fp, "move $t1, $t0 #MultiplicativeExpression\n");
			fetchint0((yyvsp[(3) - (3)].attr));
			fprintf(fp, "mult $t1, $t0\n");
			fprintf(fp, "mflo $t0\n");
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "sw $t0, 0($sp)\n");
			
			element* e;
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				e = copyandcoerce((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr));
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				e = copyandcoerce((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr));
			}else{
				printf("line #%d: incompatible types\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
			e->loc = currentelement()->loc;
			(yyval.attr) = e;
		}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 3630 "parse.y"
    {
			fetchint0((yyvsp[(1) - (3)].attr));
			fprintf(fp, "move $t1, $t0 #MultiplicativeExpression\n");
			fetchint0((yyvsp[(3) - (3)].attr));
			fprintf(fp, "div $t1, $t0\n");
			fprintf(fp, "mflo $t0\n");
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "sw $t0, 0($sp)\n");
			
			element* e;
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				e = copyandcoerce((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr));
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				e = copyandcoerce((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr));
			}else{
				printf("line #%d: incompatible types\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
			e->loc = currentelement()->loc;
			(yyval.attr) = e;
		}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 3656 "parse.y"
    {
			fetchint0((yyvsp[(1) - (3)].attr));
			fprintf(fp, "move $t1, $t0 #MultiplicativeExpression\n");
			fetchint0((yyvsp[(3) - (3)].attr));
			fprintf(fp, "div $t1, $t0\n");
			fprintf(fp, "mfhi $t0\n");
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "sw $t0, 0($sp)\n");
			
			element* e;
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				e = copyandcoerce((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr));
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				e = copyandcoerce((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr));
			}else{
				printf("line #%d: incompatible types\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
			e->loc = currentelement()->loc;
			(yyval.attr) = e;
		}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 3684 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 3686 "parse.y"
    {
			fetchint0((yyvsp[(1) - (3)].attr));
			fprintf(fp, "move $t1, $t0 #MultiplicativeExpression\n");
			fetchint0((yyvsp[(3) - (3)].attr));
			fprintf(fp, "add $t0, $t1, $t0\n");
			
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "sw $t0, 0($sp)\n");
			
			element* e;
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				e = copyandcoerce((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr));
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				e = copyandcoerce((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr));
			}else{
				printf("line #%d: incompatible types\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
			e->loc = currentelement()->loc;
			(yyval.attr) = e;
		}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 3712 "parse.y"
    {
			fetchint0((yyvsp[(1) - (3)].attr));
			fprintf(fp, "move $t1, $t0 #MultiplicativeExpression\n");
			fetchint0((yyvsp[(3) - (3)].attr));
			fprintf(fp, "sub $t0, $t1, $t0\n");
			
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "sw $t0, 0($sp)\n");
			
			element* e;
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				e = copyandcoerce((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr));
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				e = copyandcoerce((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr));
			}else{
				printf("line #%d: incompatible types\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
			e->loc = currentelement()->loc;
			(yyval.attr) = e;
		}
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 3740 "parse.y"
    { (yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 3742 "parse.y"
    {
			if(!iscoercible((yyvsp[(1) - (3)].attr), makePrimNode(string(), KPRIMITIVE, TINT, vector<int>(), NULL, ANONE, NULL))){
				printf("line #%d: shift expression must be coercible to int\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}else if((yyvsp[(3) - (3)].attr)->kind != KPRIMITIVE || (yyvsp[(3) - (3)].attr)->pdtype!=TBYTE || (yyvsp[(3) - (3)].attr)->pdtype!=TCHAR || (yyvsp[(3) - (3)].attr)->pdtype!=TSHORT || (yyvsp[(3) - (3)].attr)->pdtype!=TINT || (yyvsp[(3) - (3)].attr)->pdtype!=TLONG){
				printf("line #%d: expression to be shifted must be primitive integral type\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}else{
				fetchint0((yyvsp[(1) - (3)].attr));
				fprintf(fp, "move $t1, $t0 #ShiftExpression\n");
				fetchint0((yyvsp[(3) - (3)].attr));
				fprintf(fp, "sllv $t0, $t0, $t1\n");
				fprintf(fp, "subu $sp, $sp, 4\n");
				currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
				fprintf(fp, "sw $t0, 0($sp)\n");
				element* e= copyelement((yyvsp[(1) - (3)].attr));
				e->loc = currentelement()->loc;
				(yyval.attr) = e;
			}
		}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 3767 "parse.y"
    {
			if(!iscoercible((yyvsp[(1) - (3)].attr), makePrimNode(string(), KPRIMITIVE, TINT, vector<int>(), NULL, ANONE, NULL))){
				printf("line #%d: shift expression must be coercible to int\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}else if((yyvsp[(3) - (3)].attr)->kind != KPRIMITIVE || (yyvsp[(3) - (3)].attr)->pdtype!=TBYTE || (yyvsp[(3) - (3)].attr)->pdtype!=TCHAR || (yyvsp[(3) - (3)].attr)->pdtype!=TSHORT || (yyvsp[(3) - (3)].attr)->pdtype!=TINT || (yyvsp[(3) - (3)].attr)->pdtype!=TLONG){
				printf("line #%d: expression to be shifted must be primitive integral type\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}else{
				fetchint0((yyvsp[(1) - (3)].attr));
				fprintf(fp, "move $t1, $t0 #ShiftExpression\n");
				fetchint0((yyvsp[(3) - (3)].attr));
				fprintf(fp, "srav $t0, $t0, $t1\n");
				fprintf(fp, "subu $sp, $sp, 4\n");
				currentelement()->loc +=4;
				if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
				fprintf(fp, "sw $t0, 0($sp)\n");
				element* e= copyelement((yyvsp[(1) - (3)].attr));
				e->loc = currentelement()->loc;
				(yyval.attr) = e;
			}
		}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 3792 "parse.y"
    {
			if(!iscoercible((yyvsp[(1) - (3)].attr), makePrimNode(string(), KPRIMITIVE, TINT, vector<int>(), NULL, ANONE, NULL))){
				printf("line #%d: shift expression must be coercible to int\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}else if((yyvsp[(3) - (3)].attr)->kind != KPRIMITIVE || (yyvsp[(3) - (3)].attr)->pdtype!=TBYTE || (yyvsp[(3) - (3)].attr)->pdtype!=TCHAR || (yyvsp[(3) - (3)].attr)->pdtype!=TSHORT || (yyvsp[(3) - (3)].attr)->pdtype!=TINT || (yyvsp[(3) - (3)].attr)->pdtype!=TLONG){
				printf("line #%d: expression to be shifted must be primitive integral type\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}else{
				fetchint0((yyvsp[(1) - (3)].attr));
				fprintf(fp, "move $t1, $t0 #ShiftExpression\n");
				fetchint0((yyvsp[(3) - (3)].attr));
				fprintf(fp, "srlv $t0, $t0, $t1\n");
				fprintf(fp, "subu $sp, $sp, 4\n");
				currentelement()->loc +=4;
				if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
				fprintf(fp, "sw $t0, 0($sp)\n");
				element* e= copyelement((yyvsp[(1) - (3)].attr));
				e->loc = currentelement()->loc;
				(yyval.attr) = e;
			}
		}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 3820 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 3824 "parse.y"
    {
			fetchint0((yyvsp[(1) - (3)].attr));
			fprintf(fp, "move $t1, $t0 #RelationalExpression\n");
			fetchint0((yyvsp[(3) - (3)].attr));
			char* lab = newlabel();
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "blt $t1, $t0, %strue\n", lab);
			fprintf(fp, "li $t2, 0\n");
			fprintf(fp, "j %snext\n", lab);
			fprintf(fp, "%strue:\n", lab);
			fprintf(fp, "li $t2, 1\n");
			fprintf(fp, "%snext:\n", lab);
			fprintf(fp, "sw $t2, 0($sp)\n");
			element* e;
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
				
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
			e->loc=currentelement()->loc;
			(yyval.attr) = e;
		}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 3855 "parse.y"
    {
			fetchint0((yyvsp[(1) - (3)].attr));
			fprintf(fp, "move $t1, $t0 #RelationalExpression\n");
			fetchint0((yyvsp[(3) - (3)].attr));
			char* lab = newlabel();
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "bgt $t1, $t0, %strue\n", lab);
			fprintf(fp, "li $t2, 0\n");
			fprintf(fp, "j %snext\n", lab);
			fprintf(fp, "%strue:\n", lab);
			fprintf(fp, "li $t2, 1\n");
			fprintf(fp, "%snext:\n", lab);
			fprintf(fp, "sw $t2, 0($sp)\n");
			element* e;
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
				
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
			e->loc=currentelement()->loc;
			(yyval.attr) = e;
		}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 3886 "parse.y"
    {
			fetchint0((yyvsp[(1) - (3)].attr));
			fprintf(fp, "move $t1, $t0 #RelationalExpression\n");
			fetchint0((yyvsp[(3) - (3)].attr));
			char* lab = newlabel();
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "bge $t1, $t0, %strue\n", lab);
			fprintf(fp, "li $t2, 0\n");
			fprintf(fp, "j %snext\n", lab);
			fprintf(fp, "%strue:\n", lab);
			fprintf(fp, "li $t2, 1\n");
			fprintf(fp, "%snext:\n", lab);
			fprintf(fp, "sw $t2, 0($sp)\n");
			element* e;
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
				
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
			e->loc=currentelement()->loc;
			(yyval.attr) = e;
		}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 3917 "parse.y"
    {
			fetchint0((yyvsp[(1) - (3)].attr));
			fprintf(fp, "move $t1, $t0 #RelationalExpression\n");
			fetchint0((yyvsp[(3) - (3)].attr));
			char* lab = newlabel();
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "ble $t1, $t0, %strue\n", lab);
			fprintf(fp, "li $t2, 0\n");
			fprintf(fp, "j %snext\n", lab);
			fprintf(fp, "%strue:\n", lab);
			fprintf(fp, "li $t2, 1\n");
			fprintf(fp, "%snext:\n", lab);
			fprintf(fp, "sw $t2, 0($sp)\n");
			element* e;
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
				
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
			e->loc=currentelement()->loc;
			(yyval.attr) = e;
		}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 3948 "parse.y"
    {
			fprintf(fp, "subu $sp, $sp, 4 #RelationalExpression\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			if((yyvsp[(1) - (3)].attr)->rdtype == (yyvsp[(3) - (3)].attr)) fprintf(fp, "li $t0, 1\n");
			else fprintf(fp, "li $t0, 0\n");
			fprintf(fp, "sw $t0, 0($sp)\n");
			(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), currentelement()->loc, ANONE, NULL);
			
		}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 3964 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 3968 "parse.y"
    {
			fetchint0((yyvsp[(1) - (3)].attr));
			fprintf(fp, "move $t1, $t0 #EqualityExpression\n");
			fetchint0((yyvsp[(3) - (3)].attr));
			char* lab = newlabel();
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "beq $t1, $t0, %strue\n", lab);
			fprintf(fp, "li $t2, 0\n");
			fprintf(fp, "j %snext\n", lab);
			fprintf(fp, "%strue:\n", lab);
			fprintf(fp, "li $t2, 1\n");
			fprintf(fp, "%snext:\n", lab);
			fprintf(fp, "sw $t2, 0($sp)\n");
			element* e;
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
				
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
			e->loc=currentelement()->loc;
			(yyval.attr) = e;
		}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 3999 "parse.y"
    {
			fetchint0((yyvsp[(1) - (3)].attr));
			fprintf(fp, "move $t1, $t0 #EqualityExpression\n");
			fetchint0((yyvsp[(3) - (3)].attr));
			char* lab = newlabel();
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "bne $t1, $t0, %strue\n", lab);
			fprintf(fp, "li $t2, 0\n");
			fprintf(fp, "j %snext\n", lab);
			fprintf(fp, "%strue:\n", lab);
			fprintf(fp, "li $t2, 1\n");
			fprintf(fp, "%snext:\n", lab);
			fprintf(fp, "sw $t2, 0($sp)\n");
			element* e;
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
				
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
			e->loc=currentelement()->loc;
			(yyval.attr) = e;
		}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 4032 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 350:

/* Line 1455 of yacc.c  */
#line 4034 "parse.y"
    {
			fetchint0((yyvsp[(1) - (3)].attr));
			fprintf(fp, "move $t1, $t0 #AndExpression\n");
			fetchint0((yyvsp[(3) - (3)].attr));
			fprintf(fp, "and $t0, $t1, $t0\n");
			
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "sw $t0, 0($sp)\n");
			
			element* e;
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				e = copyandcoerce((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr));
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				e = copyandcoerce((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr));
			}else{
				printf("line #%d: incompatible types\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
			e->loc = currentelement()->loc;
			(yyval.attr) = e;
		}
    break;

  case 351:

/* Line 1455 of yacc.c  */
#line 4062 "parse.y"
    { (yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 352:

/* Line 1455 of yacc.c  */
#line 4064 "parse.y"
    {
			fetchint0((yyvsp[(1) - (3)].attr));
			fprintf(fp, "move $t1, $t0 #ExclusiveOrExpression\n");
			fetchint0((yyvsp[(3) - (3)].attr));
			fprintf(fp, "xor $t0, $t1, $t0\n");
			
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "sw $t0, 0($sp)\n");
			
			element* e;
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				e = copyandcoerce((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr));
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				e = copyandcoerce((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr));
			}else{
				printf("line #%d: incompatible types\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
			e->loc = currentelement()->loc;
			(yyval.attr) = e;
		}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 4092 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 354:

/* Line 1455 of yacc.c  */
#line 4094 "parse.y"
    {
			fetchint0((yyvsp[(1) - (3)].attr));
			fprintf(fp, "move $t1, $t0 #InclusiveOrExpression\n");
			fetchint0((yyvsp[(3) - (3)].attr));
			fprintf(fp, "or $t0, $t1, $t0\n");
			
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "sw $t0, 0($sp)\n");
			
			element* e;
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				e = copyandcoerce((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr));
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				e = copyandcoerce((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr));
			}else{
				printf("line #%d: incompatible types\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
			e->loc = currentelement()->loc;
			(yyval.attr) = e;
		}
    break;

  case 355:

/* Line 1455 of yacc.c  */
#line 4122 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 356:

/* Line 1455 of yacc.c  */
#line 4124 "parse.y"
    {
			fetchint0((yyvsp[(1) - (3)].attr));
			fprintf(fp, "move $t1, $t0 #ConditionalAndExpression\n");
			fetchint0((yyvsp[(3) - (3)].attr));
			fprintf(fp, "and $t0, $t1, $t0\n");
			
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "sw $t0, 0($sp)\n");
			
			element * e;
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("error line #%d: types not comparable\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
			e->loc=currentelement()->loc;
			(yyval.attr) = e;
		}
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 4152 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 358:

/* Line 1455 of yacc.c  */
#line 4154 "parse.y"
    {
			fetchint0((yyvsp[(1) - (3)].attr));
			fprintf(fp, "move $t1, $t0 #ConditionalOrExpression\n");
			fetchint0((yyvsp[(3) - (3)].attr));
			fprintf(fp, "or $t0, $t1, $t0\n");
			
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "sw $t0, 0($sp)\n");
			
			element * e;
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("error line #%d: types not comparable\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
			e->loc=currentelement()->loc;
			(yyval.attr) = e;
		}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 4182 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 4184 "parse.y"
    {
			fprintf(fp, "subu $sp, $sp, 4 #ConditionalExpression\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			
			fetchint0((yyvsp[(1) - (5)].attr));
			fprintf(fp, "move $s0, $t0");
			fprintf(fp, "li $t1, 0\n");
			
			char* lab = newlabel();
			fprintf(fp, "bgt $s0, $t1, %strue\n", lab);
			fetchint0((yyvsp[(5) - (5)].attr));
			fprintf(fp, "move $t2, $t0\n");
			fprintf(fp, "j %snext\n", lab);
			fprintf(fp, "%strue:\n", lab);
			fetchint0((yyvsp[(3) - (5)].attr));
			fprintf(fp, "move $t2, $t0\n");
			fprintf(fp, "%snext:\n", lab);
			fprintf(fp, "sw $t2, 0($sp)\n");
			
			element* e;
			if(iscoercible((yyvsp[(3) - (5)].attr), (yyvsp[(5) - (5)].attr))){
				e = (yyvsp[(5) - (5)].attr);
			}else if(iscoercible((yyvsp[(5) - (5)].attr), (yyvsp[(3) - (5)].attr))){
				e = (yyvsp[(3) - (5)].attr);
			}else{
				printf("error at line #%d: types not comparable\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
			e->loc = currentelement()->loc;
			(yyval.attr) = e;
		}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 4221 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 4222 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 4227 "parse.y"
    {
			if((yyvsp[(1) - (3)].attr)->amode == REFERENCE || (yyvsp[(1) - (3)].attr)->kind==KOBJECT){
				fprintf(fp, "lw $s0, -%d($fp) #Assignment\n", (yyvsp[(1) - (3)].attr)->loc);
			}else{
				fprintf(fp, "subu $s0, $fp, %d  #Assignment\n", (yyvsp[(1) - (3)].attr)->loc);
			}
			if((yyvsp[(3) - (3)].attr)->amode == REFERENCE || (yyvsp[(3) - (3)].attr)->kind == KOBJECT){
				fprintf(fp, "lw $s1, -%d($fp)\n", (yyvsp[(3) - (3)].attr)->loc);
			}else{
				fprintf(fp, "subu $s1, $fp, %d\n", (yyvsp[(3) - (3)].attr)->loc);
			}
			fprintf(fp, "lw $t0, 0($s1)\n");
			fprintf(fp, "sw $t0, 0($s0)\n");
			if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				(yyval.attr) = coerce((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr));
			}else{
				printf("line #%d: incompatible assignment\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 4251 "parse.y"
    {
			(yyval.attr) = findobject(current, (yyvsp[(1) - (1)].name), KALL);
		}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 4255 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 4259 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 4280 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 4284 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;



/* Line 1455 of yacc.c  */
#line 8195 "y.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



/* Line 1675 of yacc.c  */
#line 4286 "parse.y"

int main()
{
	yydebug=1;

	label_count=0;
	current = new scope();
	current->lexeme = string("god");
	current->parent = NULL;
	current->symtbl = symmap();
	godscope = current;
	godelement = new element();
	godelement->name = string("god");
	godelement->superclass = NULL;
	godelement -> desc = godscope;
	current->elem = godelement;
	init();
	fp = fopen("compiled.asm", "w");
	fprintf(fp, "\t.text\n");
	fprintf(fp, "\t.globl main\n");
	yyparse();
	return 0;
}

