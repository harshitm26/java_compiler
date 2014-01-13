
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
	extern int nsymbols, line_number;
	extern struct symbol symtable[MAX_SYMBOLS];
	int error_count=0;	
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
#line 119 "y.tab.c"

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
     ABSTRACT = 314,
     ASSERT = 315,
     BOOLEAN = 316,
     BREAK = 317,
     BYTE = 318,
     CASE = 319,
     CATCH = 320,
     CHAR = 321,
     CLASS = 322,
     CONST = 323,
     CONTINUE = 324,
     DEFAULT = 325,
     DO = 326,
     DOUBLE = 327,
     ELSE = 328,
     ENUM = 329,
     EXTENDS = 330,
     FINAL = 331,
     FINALLY = 332,
     FLOAT = 333,
     FOR = 334,
     IF = 335,
     GOTO = 336,
     IMPLEMENTS = 337,
     IMPORT = 338,
     INSTANCEOF = 339,
     INT = 340,
     INTERFACE = 341,
     LONG = 342,
     NATIVE = 343,
     NEW = 344,
     PACKAGE = 345,
     PRIVATE = 346,
     PROTECTED = 347,
     PUBLIC = 348,
     RETURN = 349,
     SHORT = 350,
     STATIC = 351,
     STRICTFP = 352,
     SUPER = 353,
     SWITCH = 354,
     SYNCHRONIZED = 355,
     THIS = 356,
     THROW = 357,
     THROWS = 358,
     TRANSIENT = 359,
     TRY = 360,
     VOID = 361,
     VOLATILE = 362,
     WHILE = 363,
     ATTHERATE = 364
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
#define ABSTRACT 314
#define ASSERT 315
#define BOOLEAN 316
#define BREAK 317
#define BYTE 318
#define CASE 319
#define CATCH 320
#define CHAR 321
#define CLASS 322
#define CONST 323
#define CONTINUE 324
#define DEFAULT 325
#define DO 326
#define DOUBLE 327
#define ELSE 328
#define ENUM 329
#define EXTENDS 330
#define FINAL 331
#define FINALLY 332
#define FLOAT 333
#define FOR 334
#define IF 335
#define GOTO 336
#define IMPLEMENTS 337
#define IMPORT 338
#define INSTANCEOF 339
#define INT 340
#define INTERFACE 341
#define LONG 342
#define NATIVE 343
#define NEW 344
#define PACKAGE 345
#define PRIVATE 346
#define PROTECTED 347
#define PUBLIC 348
#define RETURN 349
#define SHORT 350
#define STATIC 351
#define STRICTFP 352
#define SUPER 353
#define SWITCH 354
#define SYNCHRONIZED 355
#define THIS 356
#define THROW 357
#define THROWS 358
#define TRANSIENT 359
#define TRY 360
#define VOID 361
#define VOLATILE 362
#define WHILE 363
#define ATTHERATE 364




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 46 "parse.y"
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
	struct listofelements* list;
	struct spvec *pspvec;



/* Line 214 of yacc.c  */
#line 390 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 402 "y.tab.c"

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
#define YYLAST   4223

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  110
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  175
/* YYNRULES -- Number of rules.  */
#define YYNRULES  391
/* YYNRULES -- Number of states.  */
#define YYNSTATES  661

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   364

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
     105,   106,   107,   108,   109
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
     263,   267,   269,   273,   275,   279,   281,   283,   286,   289,
     293,   294,   299,   300,   306,   310,   312,   316,   319,   322,
     324,   328,   330,   332,   335,   338,   339,   344,   348,   353,
     354,   359,   360,   366,   369,   373,   377,   382,   387,   393,
     398,   404,   408,   413,   418,   424,   427,   431,   434,   438,
     440,   443,   445,   447,   449,   452,   457,   461,   465,   468,
     470,   474,   475,   476,   482,   485,   487,   490,   492,   494,
     497,   499,   502,   504,   506,   508,   510,   512,   514,   516,
     518,   520,   522,   524,   526,   528,   530,   532,   534,   536,
     538,   540,   542,   544,   546,   548,   552,   556,   559,   561,
     563,   565,   567,   569,   571,   573,   574,   581,   582,   583,
     584,   595,   596,   597,   598,   609,   615,   620,   624,   628,
     631,   633,   636,   639,   641,   644,   648,   651,   652,   659,
     660,   667,   668,   669,   679,   680,   691,   692,   702,   703,
     713,   714,   723,   724,   734,   735,   744,   745,   754,   755,
     763,   764,   775,   776,   786,   787,   797,   798,   807,   808,
     818,   819,   828,   829,   838,   839,   847,   849,   851,   853,
     855,   859,   863,   866,   870,   873,   877,   880,   884,   887,
     893,   897,   902,   906,   908,   911,   917,   920,   922,   924,
     926,   928,   932,   934,   936,   938,   940,   945,   951,   953,
     957,   962,   966,   971,   975,   977,   980,   984,   987,   991,
     995,   999,  1004,  1008,  1014,  1021,  1027,  1034,  1039,  1044,
    1046,  1048,  1050,  1052,  1055,  1058,  1060,  1062,  1065,  1068,
    1070,  1073,  1076,  1078,  1081,  1084,  1086,  1092,  1097,  1102,
    1108,  1110,  1114,  1118,  1122,  1124,  1128,  1132,  1134,  1138,
    1142,  1146,  1148,  1152,  1156,  1160,  1164,  1168,  1170,  1174,
    1178,  1180,  1184,  1186,  1190,  1192,  1196,  1198,  1202,  1204,
    1208,  1210,  1216,  1218,  1220,  1224,  1226,  1228,  1230,  1232,
    1234,  1236,  1238,  1240,  1242,  1244,  1246,  1248,  1250,  1252,
    1254,  1256
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     111,     0,    -1,   127,    -1,     7,    -1,     3,    -1,     5,
      -1,     4,    -1,     6,    -1,    56,    -1,    57,    -1,     9,
      -1,     8,    -1,    58,    -1,   115,    -1,   119,    -1,   116,
      -1,    61,    -1,   106,    -1,   117,    -1,   118,    -1,    63,
      -1,    95,    -1,    85,    -1,    87,    -1,    66,    -1,    78,
      -1,    72,    -1,   120,    -1,   123,    -1,   124,    -1,   120,
      -1,   120,    -1,   115,    54,    55,    -1,   124,    54,    55,
      -1,   123,    54,    55,    -1,   125,    -1,   126,    -1,   112,
      -1,   124,    47,   112,    -1,   130,   128,   129,    -1,   130,
     128,    -1,   130,   129,    -1,   130,    -1,   128,   129,    -1,
     128,    -1,   129,    -1,    -1,   131,    -1,   128,   131,    -1,
     134,    -1,   129,   134,    -1,    90,   124,    48,    -1,   132,
      -1,   133,    -1,    83,   124,    48,    -1,    83,   124,    47,
      14,    48,    -1,   137,    -1,   172,    -1,    48,    -1,   136,
      -1,   135,   136,    -1,    93,    -1,    92,    -1,    91,    -1,
      96,    -1,    59,    -1,    76,    -1,    88,    -1,   100,    -1,
     104,    -1,   107,    -1,    -1,    67,   112,   138,   145,    -1,
      -1,    67,   112,   142,   139,   145,    -1,    67,   112,   143,
     145,    -1,    67,   112,   142,   143,   145,    -1,    -1,   135,
      67,   112,   140,   145,    -1,    -1,   135,    67,   112,   142,
     141,   145,    -1,   135,    67,   112,   143,   145,    -1,   135,
      67,   112,   142,   143,   145,    -1,    75,   121,    -1,    82,
     144,    -1,   122,    -1,   144,    49,   122,    -1,    52,    53,
      -1,    52,   146,    53,    -1,   147,    -1,   146,   147,    -1,
     148,    -1,   164,    -1,   165,    -1,   149,    -1,   154,    -1,
     137,    -1,   114,   150,    48,    -1,   135,   114,   150,    48,
      -1,   151,    -1,   150,    49,   151,    -1,   152,    -1,   152,
      17,   153,    -1,   112,    -1,   152,    54,    55,    -1,   283,
      -1,   179,    -1,   155,   163,    -1,   114,   156,    -1,   135,
     114,   156,    -1,    -1,   112,    50,   157,    51,    -1,    -1,
     112,    50,   158,   159,    51,    -1,   156,    54,    55,    -1,
     160,    -1,   159,    49,   160,    -1,   114,   152,    -1,   103,
     162,    -1,   121,    -1,   162,    49,   121,    -1,   181,    -1,
      48,    -1,    96,   181,    -1,   167,   170,    -1,    -1,   135,
     167,   166,   170,    -1,   167,   161,   170,    -1,   135,   167,
     161,   170,    -1,    -1,   125,    50,   168,    51,    -1,    -1,
     125,    50,   169,   159,    51,    -1,    52,    53,    -1,    52,
     171,    53,    -1,    52,   184,    53,    -1,    52,   171,   184,
      53,    -1,   101,    50,    51,    48,    -1,   101,    50,   252,
      51,    48,    -1,    98,    50,    51,    48,    -1,    98,    50,
     252,    51,    48,    -1,    86,   112,   174,    -1,   135,    86,
     112,   174,    -1,    86,   112,   173,   174,    -1,   135,    86,
     112,   173,   174,    -1,    75,   122,    -1,   173,    49,   122,
      -1,    52,    53,    -1,    52,   175,    53,    -1,   176,    -1,
     175,   176,    -1,   177,    -1,   178,    -1,   149,    -1,   155,
      48,    -1,    52,   180,    49,    53,    -1,    52,   180,    53,
      -1,    52,    49,    53,    -1,    52,    53,    -1,   153,    -1,
     180,    49,   153,    -1,    -1,    -1,    52,   182,   184,   183,
      53,    -1,    52,    53,    -1,   185,    -1,   184,   185,    -1,
     186,    -1,   188,    -1,   187,    48,    -1,   137,    -1,   114,
     150,    -1,   190,    -1,   192,    -1,   196,    -1,   198,    -1,
     212,    -1,   219,    -1,   190,    -1,   193,    -1,   202,    -1,
     214,    -1,   228,    -1,   181,    -1,   191,    -1,   194,    -1,
     206,    -1,   216,    -1,   240,    -1,   241,    -1,   242,    -1,
     244,    -1,   243,    -1,   245,    -1,    48,    -1,   112,    46,
     188,    -1,   112,    46,   189,    -1,   195,    48,    -1,   280,
      -1,   264,    -1,   265,    -1,   261,    -1,   262,    -1,   258,
      -1,   251,    -1,    -1,    80,    50,   283,    51,   197,   188,
      -1,    -1,    -1,    -1,    80,    50,   283,    51,   199,   189,
     200,    73,   201,   188,    -1,    -1,    -1,    -1,    80,    50,
     283,    51,   203,   189,   204,    73,   205,   189,    -1,    99,
      50,   283,    51,   207,    -1,    52,   208,   210,    53,    -1,
      52,   208,    53,    -1,    52,   210,    53,    -1,    52,    53,
      -1,   209,    -1,   208,   209,    -1,   210,   184,    -1,   211,
      -1,   210,   211,    -1,    64,   284,    46,    -1,    70,    46,
      -1,    -1,   108,    50,   283,    51,   213,   188,    -1,    -1,
     108,    50,   283,    51,   215,   189,    -1,    -1,    -1,    71,
     217,   188,   218,   108,    50,   283,    51,    48,    -1,    -1,
      79,    50,   237,    48,   283,    48,   238,    51,   220,   188,
      -1,    -1,    79,    50,   237,    48,   283,    48,    51,   221,
     188,    -1,    -1,    79,    50,   237,    48,    48,   238,    51,
     222,   188,    -1,    -1,    79,    50,   237,    48,    48,    51,
     223,   188,    -1,    -1,    79,    50,    48,   283,    48,   238,
      51,   224,   188,    -1,    -1,    79,    50,    48,   283,    48,
      51,   225,   188,    -1,    -1,    79,    50,    48,    48,   238,
      51,   226,   188,    -1,    -1,    79,    50,    48,    48,    51,
     227,   188,    -1,    -1,    79,    50,   237,    48,   283,    48,
     238,    51,   229,   189,    -1,    -1,    79,    50,   237,    48,
     283,    48,    51,   230,   189,    -1,    -1,    79,    50,   237,
      48,    48,   238,    51,   231,   189,    -1,    -1,    79,    50,
     237,    48,    48,    51,   232,   189,    -1,    -1,    79,    50,
      48,   283,    48,   238,    51,   233,   189,    -1,    -1,    79,
      50,    48,   283,    48,    51,   234,   189,    -1,    -1,    79,
      50,    48,    48,   238,    51,   235,   189,    -1,    -1,    79,
      50,    48,    48,    51,   236,   189,    -1,   239,    -1,   187,
      -1,   239,    -1,   195,    -1,   239,    49,   195,    -1,    62,
     112,    48,    -1,    62,    48,    -1,    69,   112,    48,    -1,
      69,    48,    -1,    94,   283,    48,    -1,    94,    48,    -1,
     102,   283,    48,    -1,   102,    48,    -1,   100,    50,   283,
      51,   181,    -1,   105,   181,   246,    -1,   105,   181,   246,
     248,    -1,   105,   181,   248,    -1,   247,    -1,   246,   247,
      -1,    65,    50,   160,    51,   181,    -1,    77,   181,    -1,
     250,    -1,   253,    -1,   113,    -1,   101,    -1,    50,   283,
      51,    -1,   251,    -1,   257,    -1,   258,    -1,   259,    -1,
      89,   121,    50,    51,    -1,    89,   121,    50,   252,    51,
      -1,   283,    -1,   252,    49,   283,    -1,    89,   115,   254,
     256,    -1,    89,   115,   254,    -1,    89,   120,   254,   256,
      -1,    89,   120,   254,    -1,   255,    -1,   254,   255,    -1,
      54,   283,    55,    -1,    54,    55,    -1,   256,    54,    55,
      -1,   249,    47,   112,    -1,    98,    47,   112,    -1,   124,
      50,   252,    51,    -1,   124,    50,    51,    -1,   249,    47,
     112,    50,    51,    -1,   249,    47,   112,    50,   252,    51,
      -1,    98,    47,   112,    50,    51,    -1,    98,    47,   112,
      50,   252,    51,    -1,   124,    54,   283,    55,    -1,   250,
      54,   283,    55,    -1,   249,    -1,   124,    -1,   261,    -1,
     262,    -1,   260,    10,    -1,   260,    13,    -1,   264,    -1,
     265,    -1,    11,   263,    -1,    12,   263,    -1,   266,    -1,
      10,   263,    -1,    13,   263,    -1,   260,    -1,    44,   263,
      -1,    30,   263,    -1,   267,    -1,    50,   115,   256,    51,
     263,    -1,    50,   115,    51,   263,    -1,    50,   283,    51,
     266,    -1,    50,   124,   256,    51,   266,    -1,   263,    -1,
     268,    14,   263,    -1,   268,    15,   263,    -1,   268,    16,
     263,    -1,   268,    -1,   269,    11,   268,    -1,   269,    12,
     268,    -1,   269,    -1,   270,    41,   269,    -1,   270,    40,
     269,    -1,   270,    42,   269,    -1,   270,    -1,   271,    36,
     270,    -1,   271,    35,   270,    -1,   271,    33,   270,    -1,
     271,    32,   270,    -1,   271,    84,   119,    -1,   271,    -1,
     272,    31,   271,    -1,   272,    34,   271,    -1,   272,    -1,
     273,    38,   272,    -1,   273,    -1,   274,    39,   273,    -1,
     274,    -1,   275,    37,   274,    -1,   275,    -1,   276,    28,
     275,    -1,   276,    -1,   277,    29,   276,    -1,   277,    -1,
     277,    45,   283,    46,   278,    -1,   278,    -1,   280,    -1,
     281,   282,   279,    -1,   124,    -1,   257,    -1,   259,    -1,
      17,    -1,    20,    -1,    21,    -1,    22,    -1,    18,    -1,
      19,    -1,    26,    -1,    27,    -1,    43,    -1,    23,    -1,
      25,    -1,    24,    -1,   279,    -1,   283,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   218,   218,   226,   232,   238,   244,   250,   256,   262,
     268,   274,   279,   290,   294,   301,   304,   308,   314,   318,
     325,   329,   333,   337,   341,   348,   352,   359,   363,   369,
     376,   383,   390,   395,   402,   410,   414,   421,   430,   443,
     444,   445,   446,   447,   448,   449,   450,   454,   455,   460,
     464,   476,   480,   481,   485,   489,   493,   497,   498,   505,
     509,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   529,   528,   548,   547,   569,   570,   572,   571,   599,
     598,   624,   625,   629,   635,   639,   640,   644,   648,   655,
     659,   670,   674,   675,   682,   683,   684,   692,   703,   725,
     732,   746,   750,   762,   773,   781,   785,   794,   807,   824,
     859,   858,   879,   878,   905,   909,   916,   929,   947,   951,
     952,   956,   960,   967,   971,   982,   981,   999,  1000,  1005,
    1004,  1036,  1035,  1076,  1080,  1088,  1097,  1108,  1112,  1134,
    1138,  1166,  1167,  1168,  1169,  1173,  1174,  1178,  1179,  1182,
    1183,  1187,  1188,  1192,  1196,  1202,  1206,  1210,  1214,  1221,
    1227,  1241,  1245,  1240,  1252,  1259,  1263,  1275,  1279,  1286,
    1290,  1297,  1319,  1320,  1321,  1322,  1323,  1324,  1328,  1329,
    1330,  1331,  1332,  1337,  1341,  1342,  1343,  1344,  1345,  1346,
    1347,  1348,  1349,  1350,  1354,  1358,  1362,  1366,  1379,  1383,
    1387,  1391,  1395,  1399,  1403,  1411,  1410,  1432,  1436,  1440,
    1431,  1461,  1465,  1469,  1460,  1489,  1524,  1540,  1544,  1548,
    1555,  1556,  1575,  1582,  1583,  1602,  1603,  1612,  1611,  1632,
    1631,  1650,  1654,  1649,  1671,  1670,  1679,  1678,  1688,  1687,
    1697,  1696,  1706,  1705,  1715,  1714,  1724,  1723,  1733,  1732,
    1747,  1746,  1755,  1754,  1764,  1763,  1773,  1772,  1782,  1781,
    1791,  1790,  1800,  1799,  1809,  1808,  1820,  1829,  1836,  1848,
    1849,  1860,  1861,  1865,  1866,  1870,  1898,  1917,  1918,  1922,
    1926,  1927,  1928,  1932,  1933,  1937,  1941,  1945,  1946,  1950,
    1951,  1952,  1953,  1954,  1955,  1959,  1966,  1990,  2017,  2024,
    2037,  2043,  2047,  2053,  2060,  2067,  2075,  2085,  2092,  2100,
    2115,  2129,  2147,  2165,  2191,  2216,  2247,  2282,  2305,  2327,
    2328,  2329,  2330,  2334,  2338,  2342,  2343,  2344,  2345,  2346,
    2350,  2354,  2357,  2358,  2359,  2368,  2372,  2382,  2391,  2400,
    2414,  2415,  2426,  2437,  2451,  2452,  2463,  2477,  2478,  2491,
    2504,  2520,  2524,  2535,  2546,  2557,  2568,  2575,  2579,  2590,
    2604,  2605,  2619,  2620,  2634,  2635,  2649,  2650,  2664,  2665,
    2679,  2680,  2694,  2695,  2699,  2711,  2715,  2719,  2726,  2727,
    2728,  2729,  2730,  2731,  2732,  2733,  2734,  2735,  2736,  2737,
    2741,  2745
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
  "ABSTRACT", "ASSERT", "BOOLEAN", "BREAK", "BYTE", "CASE", "CATCH",
  "CHAR", "CLASS", "CONST", "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE",
  "ENUM", "EXTENDS", "FINAL", "FINALLY", "FLOAT", "FOR", "IF", "GOTO",
  "IMPLEMENTS", "IMPORT", "INSTANCEOF", "INT", "INTERFACE", "LONG",
  "NATIVE", "NEW", "PACKAGE", "PRIVATE", "PROTECTED", "PUBLIC", "RETURN",
  "SHORT", "STATIC", "STRICTFP", "SUPER", "SWITCH", "SYNCHRONIZED", "THIS",
  "THROW", "THROWS", "TRANSIENT", "TRY", "VOID", "VOLATILE", "WHILE",
  "ATTHERATE", "$accept", "Goal", "Identifier", "Literal", "Type",
  "PrimitiveType", "NumericType", "IntegralType", "FloatingPointType",
  "ReferenceType", "ClassOrInterfaceType", "ClassType", "InterfaceType",
  "ArrayType", "Name", "SimpleName", "QualifiedName", "CompilationUnit",
  "ImportDeclarations", "TypeDeclarations", "PackageDeclaration",
  "ImportDeclaration", "SingleTypeImportDeclaration",
  "TypeImportOnDemandDeclaration", "TypeDeclaration", "Modifiers",
  "Modifier", "ClassDeclaration", "$@1", "$@2", "$@3", "$@4", "Super",
  "Interfaces", "InterfaceTypeList", "ClassBody", "ClassBodyDeclarations",
  "ClassBodyDeclaration", "ClassMemberDeclaration", "FieldDeclaration",
  "VariableDeclarators", "VariableDeclarator", "VariableDeclaratorId",
  "VariableInitializer", "MethodDeclaration", "MethodHeader",
  "MethodDeclarator", "$@5", "$@6", "FormalParameterList",
  "FormalParameter", "Throws", "ClassTypeList", "MethodBody",
  "StaticInitializer", "ConstructorDeclaration", "$@7",
  "ConstructorDeclarator", "$@8", "$@9", "ConstructorBody",
  "ExplicitConstructorInvocation", "InterfaceDeclaration",
  "ExtendsInterfaces", "InterfaceBody", "InterfaceMemberDeclarations",
  "InterfaceMemberDeclaration", "ConstantDeclaration",
  "AbstractMethodDeclaration", "ArrayInitializer", "VariableInitializers",
  "Block", "$@10", "$@11", "BlockStatements", "BlockStatement",
  "LocalVariableDeclarationStatement", "LocalVariableDeclaration",
  "Statement", "StatementNoShortIf",
  "StatementWithoutTrailingSubstatement", "EmptyStatement",
  "LabeledStatement", "LabeledStatementNoShortIf", "ExpressionStatement",
  "StatementExpression", "IfThenStatement", "$@12", "IfThenElseStatement",
  "$@13", "$@14", "$@15", "IfThenElseStatementNoShortIf", "$@16", "$@17",
  "$@18", "SwitchStatement", "SwitchBlock", "SwitchBlockStatementGroups",
  "SwitchBlockStatementGroup", "SwitchLabels", "SwitchLabel",
  "WhileStatement", "$@19", "WhileStatementNoShortIf", "$@20",
  "DoStatement", "$@21", "$@22", "ForStatement", "$@23", "$@24", "$@25",
  "$@26", "$@27", "$@28", "$@29", "$@30", "ForStatementNoShortIf", "$@31",
  "$@32", "$@33", "$@34", "$@35", "$@36", "$@37", "$@38", "ForInit",
  "ForUpdate", "StatementExpressionList", "BreakStatement",
  "ContinueStatement", "ReturnStatement", "ThrowStatement",
  "SynchronizedStatement", "TryStatement", "Catches", "CatchClause",
  "Finally", "Primary", "PrimaryNoNewArray",
  "ClassInstanceCreationExpression", "ArgumentList",
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
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   110,   111,   112,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   114,   114,   115,   115,   115,   116,   116,
     117,   117,   117,   117,   117,   118,   118,   119,   119,   120,
     121,   122,   123,   123,   123,   124,   124,   125,   126,   127,
     127,   127,   127,   127,   127,   127,   127,   128,   128,   129,
     129,   130,   131,   131,   132,   133,   134,   134,   134,   135,
     135,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   138,   137,   139,   137,   137,   137,   140,   137,   141,
     137,   137,   137,   142,   143,   144,   144,   145,   145,   146,
     146,   147,   147,   147,   148,   148,   148,   149,   149,   150,
     150,   151,   151,   152,   152,   153,   153,   154,   155,   155,
     157,   156,   158,   156,   156,   159,   159,   160,   161,   162,
     162,   163,   163,   164,   165,   166,   165,   165,   165,   168,
     167,   169,   167,   170,   170,   170,   170,   171,   171,   171,
     171,   172,   172,   172,   172,   173,   173,   174,   174,   175,
     175,   176,   176,   177,   178,   179,   179,   179,   179,   180,
     180,   182,   183,   181,   181,   184,   184,   185,   185,   186,
     186,   187,   188,   188,   188,   188,   188,   188,   189,   189,
     189,   189,   189,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   191,   192,   193,   194,   195,   195,
     195,   195,   195,   195,   195,   197,   196,   199,   200,   201,
     198,   203,   204,   205,   202,   206,   207,   207,   207,   207,
     208,   208,   209,   210,   210,   211,   211,   213,   212,   215,
     214,   217,   218,   216,   220,   219,   221,   219,   222,   219,
     223,   219,   224,   219,   225,   219,   226,   219,   227,   219,
     229,   228,   230,   228,   231,   228,   232,   228,   233,   228,
     234,   228,   235,   228,   236,   228,   237,   237,   238,   239,
     239,   240,   240,   241,   241,   242,   242,   243,   243,   244,
     245,   245,   245,   246,   246,   247,   248,   249,   249,   250,
     250,   250,   250,   250,   250,   250,   251,   251,   252,   252,
     253,   253,   253,   253,   254,   254,   255,   256,   256,   257,
     257,   258,   258,   258,   258,   258,   258,   259,   259,   260,
     260,   260,   260,   261,   262,   263,   263,   263,   263,   263,
     264,   265,   266,   266,   266,   266,   267,   267,   267,   267,
     268,   268,   268,   268,   269,   269,   269,   270,   270,   270,
     270,   271,   271,   271,   271,   271,   271,   272,   272,   272,
     273,   273,   274,   274,   275,   275,   276,   276,   277,   277,
     278,   278,   279,   279,   280,   281,   281,   281,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     283,   284
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
       3,     1,     3,     1,     3,     1,     1,     2,     2,     3,
       0,     4,     0,     5,     3,     1,     3,     2,     2,     1,
       3,     1,     1,     2,     2,     0,     4,     3,     4,     0,
       4,     0,     5,     2,     3,     3,     4,     4,     5,     4,
       5,     3,     4,     4,     5,     2,     3,     2,     3,     1,
       2,     1,     1,     1,     2,     4,     3,     3,     2,     1,
       3,     0,     0,     5,     2,     1,     2,     1,     1,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     0,     6,     0,     0,     0,
      10,     0,     0,     0,    10,     5,     4,     3,     3,     2,
       1,     2,     2,     1,     2,     3,     2,     0,     6,     0,
       6,     0,     0,     9,     0,    10,     0,     9,     0,     9,
       0,     8,     0,     9,     0,     8,     0,     8,     0,     7,
       0,    10,     0,     9,     0,     9,     0,     8,     0,     9,
       0,     8,     0,     8,     0,     7,     1,     1,     1,     1,
       3,     3,     2,     3,     2,     3,     2,     3,     2,     5,
       3,     4,     3,     1,     2,     5,     2,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     4,     5,     1,     3,
       4,     3,     4,     3,     1,     2,     3,     2,     3,     3,
       3,     4,     3,     5,     6,     5,     6,     4,     4,     1,
       1,     1,     1,     2,     2,     1,     1,     2,     2,     1,
       2,     2,     1,     2,     2,     1,     5,     4,     4,     5,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     3,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
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
       0,     0,    54,     0,     0,     0,   141,     0,    51,    39,
      77,     0,    30,    83,    29,    31,    85,    84,     0,    72,
       0,     0,    75,     0,    38,   147,    16,    20,    24,    26,
      25,    22,    23,    21,    17,     0,    13,    15,    18,    19,
      14,    27,    28,    29,     0,   153,     0,     0,   149,   151,
     152,   145,     0,   143,     0,    79,     0,     0,   142,     0,
      87,    64,    35,     0,    96,     0,    89,    91,    94,    95,
       0,    92,    93,     0,    74,    76,    55,   103,     0,    99,
     101,   108,     0,     0,     0,     0,   154,   148,   150,   146,
      78,     0,     0,    81,   144,    86,   161,   123,   131,   125,
      88,    90,   122,   107,   121,     0,     0,     0,   124,   112,
      97,     0,     0,     0,     0,    32,    34,    33,     0,   109,
      80,    82,   164,     0,     0,     0,     0,     0,     4,     6,
       5,     7,    11,    10,     0,     0,   194,     0,   133,     8,
       9,    12,     0,     0,   231,     0,     0,     0,     0,     0,
       0,    68,   290,     0,     0,     0,    37,   289,     0,   375,
       0,   170,     0,   183,     0,   165,   167,     0,   168,   172,
     184,   173,   185,     0,   174,   175,   186,   176,   187,   177,
     188,   189,   190,   192,   191,   193,   319,   287,   292,   288,
     293,   294,   295,     0,   201,   202,   199,   200,   198,     0,
     119,   118,   127,     0,     0,   103,   100,     0,     0,     0,
       0,     0,     0,     0,   290,   320,   102,   106,   292,   294,
     332,   321,   322,   340,   325,   326,   329,   335,   344,   347,
     351,   357,   360,   362,   364,   366,   368,   370,   372,   390,
     373,   105,   104,   114,    98,   162,   130,     0,     0,   115,
     128,   126,   320,   293,   295,   330,   331,     0,   272,     0,
     274,     0,     0,     0,     0,     0,    30,     0,   276,     0,
       0,     0,     0,     0,     0,   278,     0,     0,     0,     0,
     171,     0,     0,   134,     0,   135,   166,   169,   197,     0,
       0,   323,   324,   378,   382,   383,   379,   380,   381,   387,
     389,   388,   384,   385,   386,     0,     0,   111,     0,   327,
     328,   334,   333,     0,   320,     0,     0,   158,   159,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   117,     0,   132,   291,   271,   273,     0,
     232,     0,   267,   269,     0,   266,     0,     0,   301,   304,
     303,     0,   275,   310,     0,     0,   298,     0,     0,     0,
       0,   277,     0,     0,   280,   283,   282,     0,   195,   312,
       0,     0,   136,   309,     0,   374,   120,   113,     0,     0,
       0,     0,     0,   291,   157,     0,   156,   341,   342,   343,
     345,   346,   349,   348,   350,   355,   354,   353,   352,     0,
     356,   358,   359,   361,   363,   365,   367,   369,     0,   163,
     116,     0,     0,     0,     0,     0,   205,     0,     0,   305,
     300,   302,   296,     0,     0,   139,     0,     0,     0,     0,
     137,     0,     0,   286,   284,   281,   227,   311,   317,     0,
     318,   337,   307,     0,     0,     0,   338,   155,   160,     0,
       0,   248,     0,   268,     0,     0,     0,   270,     0,     0,
     306,   297,   315,     0,   299,   140,     0,   215,   279,   138,
       0,     0,   313,     0,   336,   308,   339,   371,     0,     0,
     246,   244,     0,   240,     0,     0,   206,     0,     0,     0,
      37,   208,   178,   179,   180,   181,   182,   316,   219,     0,
       0,     0,   220,     0,   223,     0,   228,   314,     0,   249,
       0,     0,   242,     0,   238,   236,     0,     0,     0,     0,
       0,     0,   391,     0,   226,   217,   221,     0,   218,   222,
     224,   285,     0,   247,   245,     0,   241,     0,     0,   234,
       0,     0,     0,     0,   196,   209,   225,   216,   233,   243,
     239,   237,     0,     0,     0,     0,   211,   229,     0,   235,
     264,     0,     0,     0,     0,     0,     0,   210,     0,   262,
     260,     0,   256,     0,     0,   212,   230,   265,     0,     0,
     258,     0,   254,   252,     0,     0,   263,   261,     0,   257,
       0,     0,   250,   213,   259,   255,   253,     0,     0,   251,
     214
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    16,    31,   207,   208,    86,    87,    88,    89,    90,
      91,    63,    66,    92,   265,    33,    34,    17,    18,    19,
      20,    21,    22,    23,    24,   210,    26,   211,    48,    70,
     104,   141,    49,    50,    67,    69,   115,   116,   117,    95,
     128,   129,   130,   266,   119,    96,   131,   253,   254,   298,
     299,   157,   251,   153,   121,   122,   177,   123,   174,   175,
     158,   212,    28,    55,    56,    97,    98,    99,   100,   267,
     369,   213,   173,   392,   589,   215,   216,   217,   218,   551,
     219,   220,   221,   553,   222,   223,   224,   518,   225,   519,
     581,   618,   554,   625,   645,   658,   226,   527,   561,   562,
     563,   564,   227,   531,   555,   626,   228,   312,   471,   229,
     612,   598,   597,   573,   595,   571,   570,   539,   556,   657,
     651,   650,   641,   648,   639,   638,   628,   404,   512,   513,
     230,   231,   232,   233,   234,   235,   424,   425,   426,   236,
     237,   268,   415,   239,   408,   409,   440,   240,   269,   242,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     248,   249,   355,   416,   583
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -527
static const yytype_int16 yypact[] =
{
    1012,  -527,  -527,    68,  -527,    68,    68,  -527,    68,  -527,
    -527,  -527,  -527,  -527,  -527,  -527,   104,  -527,   483,  1573,
     483,  -527,  -527,  -527,  -527,  2867,  -527,  -527,  -527,  -527,
      30,  -527,   135,  -527,  -527,    45,   201,  -527,  1573,  -527,
    -527,   483,  1573,    68,    68,  -527,    68,    68,    63,    66,
      63,   120,  -527,  3166,    68,    14,  -527,    68,  -527,  1573,
      30,    45,  -527,  -527,   112,  -527,  -527,   128,  3068,  -527,
      63,    63,  -527,   152,  -527,  -527,  -527,  -527,  -527,  -527,
    -527,  -527,  -527,  -527,  -527,    68,   170,  -527,  -527,  -527,
    -527,  -527,   182,    93,  3257,  -527,   158,  3215,  -527,  -527,
    -527,  -527,    68,  -527,    63,    66,    63,    14,  -527,    68,
    -527,   203,   193,  1744,  -527,  3117,  -527,  -527,  -527,  -527,
     132,  -527,  -527,   -24,  -527,  -527,  -527,   241,   297,  -527,
      15,   214,   223,   240,   253,    68,  -527,  -527,  -527,  -527,
    -527,    63,    63,  -527,  -527,  -527,   245,  -527,   273,   246,
    -527,  -527,  -527,  -527,  -527,  2198,    68,   277,  -527,   303,
    -527,    68,  1232,   302,   306,  -527,  -527,  -527,   299,   214,
    -527,  -527,  -527,  2622,   314,   290,   277,   277,  -527,  -527,
    -527,  -527,  -527,  -527,  3865,  3865,  -527,  3865,  -527,  -527,
    -527,  -527,    28,    32,  -527,   316,   317,   290,  1921,    95,
     321,   323,   324,  3362,   203,   328,   326,  -527,    68,    96,
     386,  -527,  2304,  -527,  2410,  -527,  -527,   334,  -527,  -527,
    -527,  -527,  -527,   336,  -527,  -527,  -527,  -527,  -527,  -527,
    -527,  -527,  -527,  -527,  -527,  -527,   339,   333,   218,  -527,
     641,   225,   812,   162,   191,   208,  -527,  -527,  -527,  1152,
    -527,   340,  -527,   337,   290,  -527,  -527,  3865,  3865,  3865,
    3865,  2912,  2840,   344,  -527,  2089,  -527,  -527,  -527,  -527,
     162,  -527,  -527,  -527,  -527,  -527,  -527,  -527,   266,   327,
     243,    23,   194,   354,   355,   356,   367,    90,  -527,  -527,
    -527,  -527,  -527,  -527,  -527,  2622,  -527,    68,   142,  -527,
    -527,  -527,    79,  -527,  -527,  -527,  -527,   346,  -527,   351,
    -527,   352,  2728,  3016,  3865,   348,   348,   353,  -527,   357,
      68,  3373,  3865,  3865,  3429,  -527,   358,   -12,  3865,  2728,
     359,  3485,  3496,  -527,  2516,  -527,  -527,  -527,  -527,    68,
    3865,  -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,
    -527,  -527,  -527,  -527,  -527,  3865,    68,  -527,   226,  -527,
    -527,  -527,  -527,   183,  2195,   360,   381,  -527,  -527,   139,
    3865,  3865,  3865,  3865,  3865,  3865,  3865,  3865,  3865,  3865,
    3865,  3865,  3865,   290,  3865,  3865,  3865,  3865,  3865,  3865,
    3865,  3865,   382,   350,   290,  -527,  -527,  -527,  -527,   323,
    -527,  3552,  -527,  -527,   361,   363,   387,  3865,   385,  -527,
     385,  3608,  -527,   393,   362,   237,  -527,   396,   397,   401,
     256,  -527,   394,   203,   -12,  -527,  -527,   403,  -527,  -527,
     263,   402,  -527,   406,   404,  -527,  -527,  -527,  3865,   405,
     199,  3619,   210,   903,  -527,  1697,  -527,  -527,  -527,  -527,
     266,   266,   327,   327,   327,   243,   243,   243,   243,   170,
    -527,    23,    23,   194,   354,   355,   356,   367,   412,  -527,
    -527,   365,   593,   413,  3675,  4122,  -527,   408,  3619,  -527,
     398,   398,  -527,   274,  3731,  -527,  3865,   420,   417,   203,
    -527,   422,   290,  -527,  -527,  -527,  -527,  -527,  -527,  3742,
    -527,  -527,  -527,  3865,   416,   903,  -527,  -527,  -527,  3865,
     425,  -527,   430,   363,  1488,  3921,   428,  -527,  2728,  2806,
    -527,  -527,  -527,   279,  -527,  -527,   176,  -527,  -527,  -527,
     432,  2728,  -527,   283,  -527,  -527,  -527,  -527,  3865,  2728,
    -527,  -527,   438,  -527,   440,  3932,  -527,   442,   444,   445,
     450,  -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,  3865,
     451,   177,  -527,  1986,  -527,   203,  -527,  -527,   447,  -527,
    2728,  2728,  -527,  2728,  -527,  -527,   449,  3041,  3865,  3865,
    2806,   429,  -527,   455,  -527,  -527,  -527,  2092,  -527,  2622,
    -527,  -527,   456,  -527,  -527,  2728,  -527,  2728,  2728,  -527,
    3798,   458,   452,   457,  -527,  -527,  -527,  -527,  -527,  -527,
    -527,  -527,  2728,  3988,   459,  3854,  -527,  -527,  2728,  -527,
    -527,   460,  3999,  4055,   461,  2806,  2806,  -527,  2806,  -527,
    -527,   462,  -527,   466,  4066,  -527,  -527,  -527,  2806,  2806,
    -527,  2806,  -527,  -527,   467,   437,  -527,  -527,  2806,  -527,
    2806,  2806,  -527,  -527,  -527,  -527,  -527,  2806,  2806,  -527,
    -527
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -527,  -527,    -3,  -527,   -51,  -188,  -527,  -527,  -527,    24,
     -35,  -140,   -18,  -527,    42,   -45,  -527,  -527,   492,   153,
    -527,    31,  -527,  -527,   122,   446,   -11,   322,  -527,  -527,
    -527,  -527,   464,   -27,  -527,   -19,  -527,   407,  -527,   -23,
    -115,   364,   222,  -249,  -527,     3,   391,  -527,  -527,   267,
    -376,   371,  -527,  -527,  -527,  -527,  -527,   414,  -527,  -527,
     -46,  -527,  -527,   468,   -17,  -527,   433,  -527,  -527,  -527,
    -527,  -110,  -527,  -527,  -131,  -209,  -527,  -306,  -308,  -472,
    -406,  -527,  -527,  -527,  -527,  -307,  -527,  -527,  -527,  -527,
    -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,   -29,
     -28,  -526,  -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,
    -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,
    -527,  -527,  -527,  -527,  -527,  -527,  -527,   -42,  -485,  -305,
    -527,  -527,  -527,  -527,  -527,  -527,  -527,   113,   114,  -527,
    -527,   138,  -297,  -527,   230,   -75,  -247,  1499,   228,  1532,
     400,   568,   740,  -159,   830,   985,  -428,  -527,   -16,   -58,
    -122,   -15,   163,   157,   151,   159,   164,  -527,    43,   198,
    1247,  -527,  -527,  1323,  -527
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -378
static const yytype_int16 yytable[] =
{
      30,   147,    85,    35,   400,   336,   403,   402,   405,   315,
     154,    62,    65,   368,    45,   506,   250,    85,   470,    65,
     168,   428,    71,   112,   214,   305,   306,   420,   155,   542,
     544,    72,   162,   106,   430,    29,   101,   590,   103,    29,
      60,    61,   295,   135,   108,   118,    85,    32,    74,    39,
      36,   124,   125,   422,    74,   379,   380,   317,   381,   382,
     576,   590,   135,   102,    85,   423,    53,    65,   112,   163,
     112,   120,    39,   363,    65,    29,   308,   536,   142,   156,
     310,   334,   127,    45,   139,   140,   336,   143,    64,    64,
     144,   145,   118,   330,   327,    93,    64,    53,   359,   360,
     361,   362,    45,   -29,    37,    46,  -320,   383,   604,  -320,
      93,   252,    47,   552,   483,    68,   530,   442,   120,   390,
      54,    62,   170,   171,   297,   336,    57,    29,   621,   331,
     300,   301,   127,   370,    73,   391,    93,   631,   633,    93,
      57,    40,   320,    57,    64,   321,   331,   134,    47,   644,
     332,    64,   206,   635,   636,    93,   637,    93,   255,    57,
      40,   480,   316,   481,    40,   403,   646,   647,   517,   649,
     206,    38,   341,    42,   552,   342,   654,   109,   655,   656,
     152,    40,    51,    52,   146,   659,   660,   523,   445,   309,
     311,   394,   446,   395,    59,   459,   508,   209,    64,    45,
     126,  -321,   533,   297,  -321,   255,   136,   403,   403,   206,
     546,   206,   447,   448,   449,   209,   436,    93,  -322,   552,
     552,  -322,   552,   566,   132,   384,   302,   302,   385,   558,
     585,   569,   552,   552,   438,   552,   133,   439,   403,    64,
     559,   559,   552,   148,   552,   552,   560,   560,    57,    58,
     503,   552,   552,   504,   209,   146,   209,   455,   456,   457,
     458,   505,   593,   594,   504,   596,  -204,  -204,   164,  -204,
     403,   402,   405,  -203,  -203,   394,  -203,   437,   165,   501,
     371,   372,   373,   376,   377,   378,   486,   609,   487,   610,
     611,   159,   206,   238,   255,   166,    93,    29,   172,   302,
     302,   302,   302,   364,   619,   486,   403,   491,   167,   206,
     627,   238,   486,   493,   497,   403,   403,   413,   452,   453,
     454,    62,    27,   486,  -129,   521,   206,   403,   486,   155,
     557,   206,   486,   479,   567,   479,   433,   209,   374,   375,
      27,    27,    27,   297,   534,   160,   161,   294,   161,   156,
     238,    76,   238,    77,  -110,   209,    78,   292,   450,   451,
      27,   293,    79,    27,    27,   296,   313,   314,    80,   461,
     462,   322,   329,   323,   324,    81,   209,    82,   328,   528,
     336,    27,   337,   241,   338,    83,   339,   340,   357,   356,
     114,   320,   386,   388,   387,   389,    84,   396,    64,   397,
     398,   241,   407,   411,   163,   412,   421,   460,   161,   474,
     485,   443,   475,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,    93,   302,   302,   302,   302,
     302,   302,   302,   238,   444,   469,    93,   114,   476,   478,
     241,   297,   241,   484,   492,     2,    25,   488,   489,   490,
     238,   238,   504,    43,   496,   591,   499,   498,   509,   500,
     502,   514,     4,   520,    25,    25,    25,   238,   525,   526,
     529,   535,   238,   510,     7,   538,   545,     9,    10,    11,
     302,   540,    12,   565,    25,   302,    13,    25,    25,   572,
      14,   574,   577,    15,   578,   579,   580,   584,   592,    94,
     599,   606,   605,   616,   608,    25,   615,   622,   617,   634,
     653,   629,    41,   640,   113,   206,   550,   642,   652,   393,
     176,   358,   151,   241,   105,   256,   169,   149,   206,   107,
     138,     1,   586,   587,    93,   601,   206,   494,   495,   465,
     241,   241,     2,    94,   464,   302,   410,   302,   466,   463,
       3,   302,   537,   435,   467,   243,     0,   241,     0,     4,
     206,   113,   241,     0,     0,     0,     5,   206,   206,     6,
     206,     7,     0,   243,     9,    10,    11,   550,     0,    12,
       0,     0,     0,    13,   206,     0,   206,    14,     0,     0,
      15,     0,   206,     0,   206,   206,   178,   179,   180,   181,
      29,   182,   183,   184,     0,   209,   185,     0,     0,   206,
     238,     0,   243,   238,   243,   206,     0,     0,     0,   209,
       0,     0,   550,   550,     0,   550,     0,     0,     0,   209,
       0,   209,     0,     0,     0,   550,   550,     0,   550,     0,
       0,     0,     0,   187,   511,   550,     0,   550,   550,   189,
     190,   191,   238,   238,   550,   550,   238,   238,  -376,  -376,
    -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,   238,
       0,     0,     0,     0,     0,     0,     0,   238,     0,     0,
       0,     0,   197,   238,  -376,     0,     0,     0,     0,     0,
       0,   263,     0,     0,   264,   243,     0,     0,     0,     0,
     241,   238,     0,   241,     0,     0,     0,     0,   238,   238,
       0,   238,   243,   243,     0,   238,     0,     0,   238,     0,
       0,     0,     0,   244,     0,   238,     0,   238,     0,   243,
       0,     0,     0,   238,   243,   238,   238,     0,     0,     0,
       0,   244,   241,   241,     0,     0,   241,   241,     0,     0,
     238,   238,     0,     0,     0,     0,   238,     0,     0,   241,
     238,   238,     0,   238,   238,     0,   238,   241,     0,     0,
       0,     0,   238,   241,     0,     0,   238,   238,     0,   238,
     244,     0,   244,     0,     0,     0,   238,     0,   238,   238,
       0,   241,     0,     0,     0,   238,   238,     0,   241,   241,
       0,   241,     0,     0,     0,   241,     0,     0,   241,     0,
       0,     0,     0,     0,     0,   241,     0,   241,     0,     0,
       0,     0,     0,   241,     0,   241,   241,     0,     0,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
     241,   241,     0,     0,     0,     0,   241,     0,     0,     0,
     241,   241,     0,   241,   241,  -377,   241,     0,     0,     0,
       0,     0,   241,   244,     0,     0,   241,   241,     0,   241,
       0,     0,   243,     0,     0,   243,   241,     0,   241,   241,
     244,   244,     0,     0,     0,   241,   241,     0,     0,     0,
       0,     0,     0,     0,     0,   245,     0,   244,     0,     0,
       0,     0,   244,     0,     0,     0,   178,   179,   180,   181,
      29,   182,   183,   245,   243,   243,     0,     0,   243,   243,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   243,     0,   259,     0,     0,     0,     0,     0,   243,
       0,     0,     0,     0,     0,   243,     0,   260,     0,     0,
       0,     0,   245,   261,   245,     0,     0,     0,     0,   189,
     190,   191,     0,   243,     0,     0,     0,     0,     0,     0,
     243,   243,     0,   243,     0,     0,     0,   243,     0,     0,
     243,     0,     0,     0,     0,   246,     0,   243,     0,   243,
       0,     0,   197,     0,     0,   243,     0,   243,   243,     0,
       0,   263,     0,   246,   264,     0,     0,     0,     0,     0,
       0,     0,   243,   243,     0,     0,     0,     0,   243,     0,
       0,     0,   243,   243,     0,   243,   243,     0,   243,     0,
       0,     0,     0,     0,   243,   245,     0,     0,   243,   243,
     244,   243,   246,   244,   246,     0,     0,     0,   243,     0,
     243,   243,   245,   245,     0,     0,     0,   243,   243,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,   245,
       0,     2,     0,     0,   245,     0,     0,     0,     0,     3,
       0,     0,   244,   244,     0,     0,   244,   244,     4,     0,
       0,     0,     0,     0,     0,     5,     0,     0,     6,   244,
       7,     0,     8,     9,    10,    11,     0,   244,    12,     0,
       0,     0,    13,   244,     0,     0,    14,     0,     0,    15,
       0,     0,     0,     0,     0,   246,     0,     0,     0,     0,
       0,   244,     0,     0,     0,     0,     0,     0,   244,   244,
     247,   244,   246,   246,     0,   244,     0,     0,   244,     0,
       0,     0,     0,     0,     0,   244,     0,   244,   247,   246,
       0,     0,     0,   244,   246,   244,   244,     0,     0,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     244,   244,     0,     0,     0,     0,   244,     0,     0,     0,
     244,   244,     0,   244,   244,   354,   244,   247,     0,   247,
       0,     0,   244,     0,     0,     0,   244,   244,     0,   244,
       0,     0,   245,     0,     0,   245,   244,     0,   244,   244,
       0,     0,     0,     0,     0,   244,   244,     0,     0,     0,
       0,     0,     0,     0,     0,   178,   179,   180,   181,    29,
     182,   183,   184,   257,   258,   185,     0,     0,     0,     0,
       0,     0,     0,     0,   245,   245,     0,     0,   245,   245,
       0,     0,   259,     0,     0,     0,     0,     0,     0,     0,
       0,   245,     0,     0,     0,     0,   260,     0,     0,   245,
     247,     0,   261,     0,   262,   245,     0,     0,   189,   190,
     191,     0,     0,     0,     0,     0,     0,   247,   247,     0,
       0,     0,   246,   245,     0,   246,     0,     0,     0,     0,
     245,   245,     0,   245,   247,     0,     0,   245,     0,   247,
     245,   197,     0,     0,     0,     0,     0,   245,     0,   245,
     263,     0,     0,   264,     0,   245,     0,   245,   245,     0,
       0,     0,     0,     0,   246,   246,     0,     0,   246,   246,
       0,     0,   245,   245,     0,     0,     0,     0,   245,     0,
       0,   246,   245,   245,     0,   245,   245,     0,   245,   246,
       0,     0,     0,     0,   245,   246,     0,     0,   245,   245,
       0,   245,     0,     0,     0,     0,     0,     0,   245,     0,
     245,   245,     0,   246,     0,     0,     0,   245,   245,     0,
     246,   246,     0,   246,     0,     0,     0,   246,     0,   290,
     246,     0,     0,     0,     0,     0,     0,   246,     0,   246,
       0,     0,     0,     0,     0,   246,     0,   246,   246,     0,
       0,     0,     0,     0,   290,     0,     0,     0,     0,     0,
       0,     0,   246,   246,     0,   290,     0,     0,   246,     0,
     290,     0,   246,   246,     0,   246,   246,   247,   246,     0,
     247,     0,     0,     0,   246,     0,     0,     0,   246,   246,
       0,   246,     0,     0,     0,     0,     0,     0,   246,     0,
     246,   246,     0,     0,     0,   291,     0,   246,   246,     0,
       0,   178,   179,   180,   181,    29,   182,   183,   184,   247,
     247,   185,     0,   247,   247,     0,     0,     0,   290,   290,
     307,     0,     0,     0,     0,     0,   247,     0,     0,     0,
       0,   319,     0,     0,   247,     0,   326,     0,     0,     0,
     247,     0,     0,     0,     0,     0,     0,     0,   187,   541,
       0,     0,     0,     0,   189,   190,   191,     0,   247,     0,
       0,     0,     0,     0,     0,   247,   247,     0,   247,     0,
       0,   290,   247,     0,     0,   247,     0,     0,   290,   290,
     290,   290,   247,     0,   247,   290,     0,   197,   290,   290,
     247,     0,   247,   247,   365,   291,   263,   290,     0,   264,
       0,     0,     0,     0,     0,     0,     0,   247,   247,     0,
       0,     0,   290,   247,     0,     0,     0,   247,   247,     0,
     247,   247,     0,   247,     0,     0,     0,   290,     0,   247,
       0,     1,     0,   247,   247,     0,   247,     0,     0,     0,
       0,     0,     2,   247,     0,   247,   247,   406,   290,     0,
       3,     0,   247,   247,     0,   417,   418,     0,   290,     4,
       0,   427,     0,     0,   290,   431,     0,     0,   290,     6,
       0,     7,     0,   434,     9,    10,    11,     0,     0,    12,
       0,     0,     0,    13,     0,     0,     0,    14,     0,     0,
      15,     0,     0,   303,   303,     0,     0,     0,   290,     0,
       0,     0,   290,   431,     0,     0,     0,     0,     0,     0,
     178,   179,   180,   181,    29,   182,   183,   184,   257,   258,
     185,     0,     0,     0,   468,     0,   304,   304,     0,     0,
       0,   290,     0,     0,   473,   290,     0,   259,     0,     0,
     477,   290,     0,   290,     0,     0,     0,     0,     0,     0,
       0,   260,     0,     0,     0,     0,   290,   261,     0,   262,
     507,    29,     0,   189,   190,   191,   303,   303,   303,   303,
       0,     0,     0,     0,   431,     0,     0,     0,   291,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   290,   197,     0,     0,   304,
     304,   304,   304,     0,     0,   263,     0,   516,   264,     0,
       0,   477,     0,     2,     0,    76,   290,    77,     0,   524,
      78,    43,     0,     0,     0,     0,    79,     0,     0,     0,
       4,     0,    80,     0,     0,   290,   290,     0,     0,    81,
       0,    82,     7,     0,     0,     9,    10,    11,     0,    83,
      12,     0,     0,     0,    13,     0,     0,   290,    14,     0,
      84,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   568,   290,     0,     0,     0,     0,     0,     0,     0,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   582,   303,   303,   303,   303,   303,   303,   303,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   602,   603,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,     0,   304,   304,   304,   304,
     304,   304,   304,   614,   178,   179,   180,   181,    29,   182,
     183,   184,   257,   258,   185,     0,     0,   303,   624,     0,
       0,     0,   303,     0,     0,     0,     0,     0,     0,     0,
       0,   259,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   260,     0,     0,     0,   318,
     304,   261,     0,     0,     0,   304,     0,   189,   190,   191,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   178,
     179,   180,   181,    29,   182,   183,   184,     0,     0,   185,
       0,     0,   303,     0,   303,     0,     0,     0,   303,     0,
     197,     0,     0,     0,     0,     0,     0,     0,     0,   263,
       0,     0,   264,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   186,   304,   187,   304,   146,   588,
       0,   304,   189,   190,   191,     2,     0,    76,   192,    77,
     559,     0,    78,     3,     0,   193,   560,   194,    79,     0,
       0,     0,     4,     0,    80,   195,   196,     0,     0,     0,
       0,    81,     0,    82,     7,   197,     0,     9,    10,    11,
     198,    83,    12,     0,   263,   200,   201,   264,   203,     0,
      14,   204,    84,    15,   205,   178,   179,   180,   181,    29,
     182,   183,   184,     0,     0,   185,  -375,  -375,  -375,  -375,
    -375,  -375,  -375,  -375,  -375,  -375,  -375,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -375,     0,     0,     0,    57,     0,     0,   331,
     186,     0,   187,   370,   146,   607,     0,     0,   189,   190,
     191,     2,     0,    76,   192,    77,   559,     0,    78,     3,
       0,   193,   560,   194,    79,     0,     0,     0,     4,     0,
      80,   195,   196,     0,     0,     0,     0,    81,     0,    82,
       7,   197,     0,     9,    10,    11,   198,    83,    12,     0,
     263,   200,   201,   264,   203,     0,    14,   204,    84,    15,
     205,   178,   179,   180,   181,    29,   182,   183,   184,     0,
       0,   185,  -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,
    -375,  -375,  -375,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -375,     0,
       0,     0,    57,     0,     0,   331,   186,     0,   187,   441,
     146,   188,     0,     0,   189,   190,   191,     2,     0,    76,
     192,    77,     0,     0,    78,     3,     0,   193,     0,   194,
      79,     0,     0,     0,     4,     0,    80,   195,   196,     0,
       0,     0,     0,    81,     0,    82,     7,   197,     0,     9,
      10,    11,   198,    83,    12,     0,   199,   200,   201,   202,
     203,     0,    14,   204,    84,    15,   205,   178,   179,   180,
     181,    29,   182,   183,   184,     0,     0,   185,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   186,     0,   187,     0,   146,   333,     0,     0,
     189,   190,   191,     2,     0,    76,   192,    77,     0,     0,
      78,     3,     0,   193,     0,   194,    79,     0,     0,     0,
       4,     0,    80,   195,   196,     0,     0,     0,     0,    81,
       0,    82,     7,   197,     0,     9,    10,    11,   198,    83,
      12,     0,   263,   200,   201,   264,   203,     0,    14,   204,
      84,    15,   205,   178,   179,   180,   181,    29,   182,   183,
     184,     0,     0,   185,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   186,     0,
     187,     0,   146,   335,     0,     0,   189,   190,   191,     2,
       0,    76,   192,    77,     0,     0,    78,     3,     0,   193,
       0,   194,    79,     0,     0,     0,     4,     0,    80,   195,
     196,     0,     0,     0,     0,    81,     0,    82,     7,   197,
       0,     9,    10,    11,   198,    83,    12,     0,   263,   200,
     201,   264,   203,     0,    14,   204,    84,    15,   205,   178,
     179,   180,   181,    29,   182,   183,   184,     0,     0,   185,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   186,     0,   187,     0,   146,   432,
       0,     0,   189,   190,   191,     2,     0,    76,   192,    77,
       0,     0,    78,     3,     0,   193,     0,   194,    79,     0,
       0,     0,     4,     0,    80,   195,   196,     0,     0,     0,
       0,    81,     0,    82,     7,   197,     0,     9,    10,    11,
     198,    83,    12,     0,   263,   200,   201,   264,   203,     0,
      14,   204,    84,    15,   205,   178,   179,   180,   181,    29,
     182,   183,   184,     0,     0,   185,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     186,     0,   187,     0,   146,     0,     0,     0,   189,   190,
     191,     2,     0,    76,   192,    77,     0,     0,    78,     3,
       0,   193,     0,   194,    79,     0,     0,     0,     4,     0,
      80,   195,   196,     0,     0,     0,     0,    81,     0,    82,
       7,   197,     0,     9,    10,    11,   198,    83,    12,     0,
     263,   200,   201,   264,   203,     0,    14,   204,    84,    15,
     205,   178,   179,   180,   181,    29,   182,   183,   184,     0,
       0,   185,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   186,     0,   187,     0,
     146,     0,     0,     0,   189,   190,   191,     0,     0,     0,
     192,     0,     0,     0,     0,     0,     0,   193,     0,   194,
       0,     0,     0,     0,     0,     0,     0,   195,   196,   178,
     179,   180,   181,    29,   182,   183,   184,   197,     0,   185,
       0,     0,   198,     0,     0,     0,   263,   200,   399,   264,
     203,     0,     0,   204,     0,     0,   205,     0,     0,     0,
       0,     0,     0,   178,   179,   180,   181,    29,   182,   183,
     184,   257,   258,   185,   186,     0,   187,     0,   146,     0,
       0,     0,   189,   190,   191,     0,     0,     0,   192,     0,
     259,     0,     0,     0,     0,   193,     0,   194,     0,     0,
       0,     0,     0,     0,   260,   547,   548,     0,     0,   366,
     261,     0,   262,   367,     0,   197,   189,   190,   191,     0,
     198,     0,     0,     0,   263,   200,   399,   264,   203,     0,
       0,   204,     0,     0,   549,   178,   179,   180,   181,    29,
     182,   183,   184,   257,   258,   185,     2,     0,     0,   197,
       0,     0,     0,     0,    43,     0,     0,     0,   263,     0,
       0,   264,   259,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,     0,     7,   260,     0,     9,    10,
      11,     0,   261,    12,     0,     0,     0,    13,   189,   190,
     191,    14,     0,    76,    15,    77,     0,     0,    78,     0,
       0,     0,     0,     0,    79,     0,     0,     0,     0,     0,
      80,     0,     0,     0,     0,     0,     0,    81,     0,    82,
       0,   197,     0,     0,     0,     0,     0,    83,     0,     0,
     263,     0,     0,   264,     0,     0,     0,     0,    84,   178,
     179,   180,   181,    29,   182,   183,   184,     0,     0,   185,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   178,   179,   180,   181,    29,   182,
     183,   184,     0,     0,   185,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   401,     0,   187,     0,     0,     0,
       0,     0,   189,   190,   191,    29,     0,    76,     0,    77,
       0,     0,    78,     0,     0,     0,     0,     0,    79,   600,
       0,   187,     0,     0,    80,     0,     0,   189,   190,   191,
       0,    81,    76,    82,    77,   197,     0,    78,     0,     0,
       0,    83,     0,    79,   263,     0,     0,   264,     0,    80,
       0,   110,    84,     0,    29,     0,    81,     2,    82,    76,
     197,    77,     0,     0,    78,     3,    83,     0,     0,   263,
      79,     0,   264,     0,     4,     0,    80,    84,     0,     0,
       0,     0,     0,    81,     0,    82,     7,     0,     0,     9,
      10,    11,     0,    83,   111,     0,     0,     0,    13,     0,
     150,     0,    14,    29,    84,    15,     2,     0,    76,     0,
      77,     0,     0,    78,     3,     0,     0,     0,     0,    79,
       0,     0,     0,     4,     0,    80,     0,     0,     0,     0,
       0,     0,    81,     0,    82,     7,     0,     0,     9,    10,
      11,     0,    83,   111,     0,     0,     0,    13,     0,    75,
       0,    14,    29,    84,    15,     2,     0,    76,     0,    77,
       0,     0,    78,     0,     0,     0,     0,     0,    79,     0,
       0,     0,     4,     0,    80,     0,     0,     0,     0,     0,
       0,    81,     0,    82,     7,     0,     0,     9,    10,    11,
       0,    83,    12,     0,    29,     0,    13,     0,   137,     0,
      14,     0,    84,    15,     2,     0,    76,     0,    77,     0,
       0,    78,     0,     0,     0,     0,     0,    79,     0,     0,
       0,     4,     0,    80,     0,     0,     0,     0,     0,     0,
      81,     0,    82,     7,     0,     0,     9,    10,    11,     0,
      83,    12,     0,     0,     0,    13,     2,     0,    76,    14,
      77,    84,    15,    78,     0,     0,     0,     0,     0,    79,
       0,     0,     0,     4,     0,    80,     0,     0,     0,     0,
       0,     0,    81,     0,    82,     7,     0,     0,     9,    10,
      11,     0,    83,    12,     0,     0,     0,    13,     0,     0,
       0,    14,     0,    84,    15,   178,   179,   180,   181,    29,
     182,   183,   184,   257,   258,   185,   178,   179,   180,   181,
      29,   182,   183,   184,   257,   258,   185,     0,     0,     0,
       0,     0,   259,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,     0,     0,   260,     0,     0,     0,
     325,     0,   261,     0,     0,     0,     0,   260,   189,   190,
     191,     0,     0,   261,   414,     0,     0,     0,     0,   189,
     190,   191,   178,   179,   180,   181,    29,   182,   183,   184,
     257,   258,   185,     0,     0,     0,     0,     0,     0,     0,
       0,   197,     0,     0,     0,     0,     0,     0,     0,   259,
     263,     0,   197,   264,     0,     0,     0,     0,     0,     0,
       0,   263,     0,   260,   264,     0,     0,     0,     0,   261,
     419,     0,     0,     0,     0,   189,   190,   191,   178,   179,
     180,   181,    29,   182,   183,   184,   257,   258,   185,   178,
     179,   180,   181,    29,   182,   183,   184,   257,   258,   185,
       0,     0,     0,     0,     0,   259,     0,     0,   197,     0,
       0,     0,     0,     0,     0,     0,   259,   263,     0,   260,
     264,     0,     0,     0,     0,   261,   429,     0,     0,     0,
     260,   189,   190,   191,     0,     0,   261,     0,     0,     0,
       0,   167,   189,   190,   191,   178,   179,   180,   181,    29,
     182,   183,   184,   257,   258,   185,     0,     0,     0,     0,
       0,     0,     0,     0,   197,     0,     0,     0,     0,     0,
       0,     0,   259,   263,     0,   197,   264,     0,     0,     0,
       0,     0,     0,     0,   263,     0,   260,   264,     0,     0,
     472,     0,   261,     0,     0,     0,     0,     0,   189,   190,
     191,   178,   179,   180,   181,    29,   182,   183,   184,   257,
     258,   185,   178,   179,   180,   181,    29,   182,   183,   184,
     257,   258,   185,     0,     0,     0,     0,     0,   259,     0,
       0,   197,     0,     0,     0,     0,     0,     0,     0,   259,
     263,     0,   260,   264,     0,     0,     0,     0,   261,   482,
       0,     0,     0,   260,   189,   190,   191,     0,     0,   261,
       0,     0,     0,     0,   502,   189,   190,   191,   178,   179,
     180,   181,    29,   182,   183,   184,   257,   258,   185,     0,
       0,     0,     0,     0,     0,     0,     0,   197,     0,     0,
       0,     0,     0,     0,     0,   259,   263,     0,   197,   264,
       0,     0,     0,     0,     0,     0,     0,   263,     0,   260,
     264,     0,     0,   515,     0,   261,     0,     0,     0,     0,
       0,   189,   190,   191,   178,   179,   180,   181,    29,   182,
     183,   184,   257,   258,   185,   178,   179,   180,   181,    29,
     182,   183,   184,   257,   258,   185,     0,     0,     0,     0,
       0,   259,     0,     0,   197,     0,     0,     0,     0,     0,
       0,     0,   259,   263,     0,   260,   264,     0,     0,     0,
       0,   261,   522,     0,     0,     0,   260,   189,   190,   191,
       0,     0,   261,   532,     0,     0,     0,     0,   189,   190,
     191,   178,   179,   180,   181,    29,   182,   183,   184,   257,
     258,   185,     0,     0,     0,     0,     0,     0,     0,     0,
     197,     0,     0,     0,     0,     0,     0,     0,   259,   263,
       0,   197,   264,     0,     0,     0,     0,     0,     0,     0,
     263,     0,   260,   264,     0,     0,   613,     0,   261,     0,
       0,     0,     0,     0,   189,   190,   191,   178,   179,   180,
     181,    29,   182,   183,   184,   257,   258,   185,   178,   179,
     180,   181,    29,   182,   183,   184,   257,   258,   185,     0,
       0,     0,     0,     0,   259,     0,     0,   197,     0,     0,
       0,     0,     0,     0,     0,   259,   263,     0,   260,   264,
       0,     0,   623,     0,   261,     0,     0,     0,     0,   260,
     189,   190,   191,     0,     0,   261,     0,     0,     0,     0,
       0,   189,   190,   191,   178,   179,   180,   181,    29,   182,
     183,   184,     0,     0,   185,   178,   179,   180,   181,    29,
     182,   183,   184,   197,     0,   185,     0,     0,     0,     0,
       0,     0,   263,     0,   197,   264,     0,     0,     0,     0,
       0,     0,     0,   263,     0,     0,   264,     0,     0,     0,
       0,   187,   543,     0,     0,     0,     0,   189,   190,   191,
       0,     0,   187,   575,     0,     0,     0,     0,   189,   190,
     191,   178,   179,   180,   181,    29,   182,   183,   184,     0,
       0,   185,   178,   179,   180,   181,    29,   182,   183,   184,
     197,     0,   185,     0,     0,     0,     0,     0,     0,   263,
       0,   197,   264,     0,     0,     0,     0,     0,     0,     0,
     263,     0,     0,   264,     0,     0,     0,     0,   187,   620,
       0,     0,     0,     0,   189,   190,   191,     0,     0,   187,
     630,     0,     0,     0,     0,   189,   190,   191,   178,   179,
     180,   181,    29,   182,   183,   184,     0,     0,   185,   178,
     179,   180,   181,    29,   182,   183,   184,   197,     0,   185,
       0,     0,     0,     0,     0,     0,   263,     0,   197,   264,
       0,     0,     0,     0,     0,     0,     0,   263,     0,     0,
     264,     0,     0,     0,     0,   187,   632,     0,     0,     0,
       0,   189,   190,   191,     0,     0,   187,   643,     0,     0,
       0,     0,   189,   190,   191,   178,   179,   180,   181,    29,
     182,   183,   184,     0,     0,   185,     0,     0,     0,     0,
       0,     0,     0,     0,   197,     0,     0,     0,     0,     0,
       0,     0,     0,   263,     0,   197,   264,     0,     0,     0,
       0,     0,     0,     0,   263,     0,     0,   264,     0,     0,
       0,     0,   187,     0,     0,     0,     0,     0,   189,   190,
     191,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   197,     0,     0,     0,     0,     0,     0,     0,     0,
     263,     0,     0,   264
};

static const yytype_int16 yycheck[] =
{
       3,   111,    53,     6,   312,   214,   313,   313,   313,   197,
     120,    46,    47,   262,    25,   443,   156,    68,   394,    54,
     135,   329,    49,    68,   155,   184,   185,   324,    52,   514,
     515,    50,    17,    60,   331,     7,    54,   563,    55,     7,
      43,    44,   173,    94,    61,    68,    97,     5,    51,    18,
       8,    70,    71,    65,    57,    32,    33,   197,    35,    36,
     545,   587,   113,    49,   115,    77,    52,   102,   113,    54,
     115,    68,    41,   261,   109,     7,    48,   505,   105,   103,
      48,   212,    85,    94,   102,   104,   295,   106,    46,    47,
     107,   109,   115,   208,   204,    53,    54,    52,   257,   258,
     259,   260,   113,     7,     0,    75,    10,    84,   580,    13,
      68,   157,    82,   519,   411,    52,   492,   364,   115,    29,
      75,   156,   141,   142,   175,   334,    47,     7,   613,    50,
     176,   177,   135,    54,    14,    45,    94,   622,   623,    97,
      47,    19,    47,    47,   102,    50,    50,    54,    82,   634,
      54,   109,   155,   625,   626,   113,   628,   115,   161,    47,
      38,   408,   197,   410,    42,   472,   638,   639,   475,   641,
     173,    18,    10,    20,   580,    13,   648,    49,   650,   651,
      48,    59,    47,    48,    52,   657,   658,   484,    49,   192,
     193,    49,    53,    51,    41,   383,   445,   155,   156,   210,
      48,    10,   499,   254,    13,   208,    48,   514,   515,   212,
     518,   214,   371,   372,   373,   173,   356,   175,    10,   625,
     626,    13,   628,   531,    54,    31,   184,   185,    34,    53,
      53,   539,   638,   639,    51,   641,    54,    54,   545,   197,
      64,    64,   648,    50,   650,   651,    70,    70,    47,    48,
      51,   657,   658,    54,   212,    52,   214,   379,   380,   381,
     382,    51,   570,   571,    54,   573,    48,    49,    54,    51,
     577,   577,   577,    48,    49,    49,    51,    51,    55,   438,
      14,    15,    16,    40,    41,    42,    49,   595,    51,   597,
     598,    50,   295,   155,   297,    55,   254,     7,    53,   257,
     258,   259,   260,   261,   612,    49,   613,    51,    55,   312,
     618,   173,    49,   423,    51,   622,   623,   320,   376,   377,
     378,   356,     0,    49,    51,    51,   329,   634,    49,    52,
      51,   334,    49,   408,    51,   410,   339,   295,    11,    12,
      18,    19,    20,   394,   503,    48,    49,    48,    49,   103,
     212,    61,   214,    63,    51,   313,    66,    55,   374,   375,
      38,    55,    72,    41,    42,    51,    50,    50,    78,   384,
     385,    50,    46,    50,    50,    85,   334,    87,    50,   489,
     589,    59,    48,   155,    48,    95,    47,    54,    51,    49,
      68,    47,    38,    37,    39,    28,   106,    51,   356,    48,
      48,   173,    54,    50,    54,    48,    48,   383,    49,    48,
      48,    51,    49,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   295,    53,    53,   394,   115,    51,    54,
     212,   492,   214,    50,    50,    59,     0,    51,    51,    48,
     312,   313,    54,    67,    51,   565,    50,    55,    46,    55,
      55,    48,    76,    55,    18,    19,    20,   329,    48,    52,
      48,    55,   334,   108,    88,    50,    48,    91,    92,    93,
     438,    51,    96,    51,    38,   443,   100,    41,    42,    51,
     104,    51,    50,   107,    50,    50,    46,    46,    51,    53,
      51,    46,    73,    51,    48,    59,    48,    48,    51,    48,
      73,    51,    20,    51,    68,   518,   519,    51,    51,   297,
     149,   254,   115,   295,    60,   161,   135,   113,   531,    61,
      97,    48,   561,   561,   492,   577,   539,   424,   424,   388,
     312,   313,    59,    97,   387,   503,   316,   505,   389,   386,
      67,   509,   509,   355,   390,   155,    -1,   329,    -1,    76,
     563,   115,   334,    -1,    -1,    -1,    83,   570,   571,    86,
     573,    88,    -1,   173,    91,    92,    93,   580,    -1,    96,
      -1,    -1,    -1,   100,   587,    -1,   589,   104,    -1,    -1,
     107,    -1,   595,    -1,   597,   598,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,   563,    13,    -1,    -1,   612,
     472,    -1,   212,   475,   214,   618,    -1,    -1,    -1,   577,
      -1,    -1,   625,   626,    -1,   628,    -1,    -1,    -1,   587,
      -1,   589,    -1,    -1,    -1,   638,   639,    -1,   641,    -1,
      -1,    -1,    -1,    50,    51,   648,    -1,   650,   651,    56,
      57,    58,   514,   515,   657,   658,   518,   519,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   531,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   539,    -1,    -1,
      -1,    -1,    89,   545,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    -1,    -1,   101,   295,    -1,    -1,    -1,    -1,
     472,   563,    -1,   475,    -1,    -1,    -1,    -1,   570,   571,
      -1,   573,   312,   313,    -1,   577,    -1,    -1,   580,    -1,
      -1,    -1,    -1,   155,    -1,   587,    -1,   589,    -1,   329,
      -1,    -1,    -1,   595,   334,   597,   598,    -1,    -1,    -1,
      -1,   173,   514,   515,    -1,    -1,   518,   519,    -1,    -1,
     612,   613,    -1,    -1,    -1,    -1,   618,    -1,    -1,   531,
     622,   623,    -1,   625,   626,    -1,   628,   539,    -1,    -1,
      -1,    -1,   634,   545,    -1,    -1,   638,   639,    -1,   641,
     212,    -1,   214,    -1,    -1,    -1,   648,    -1,   650,   651,
      -1,   563,    -1,    -1,    -1,   657,   658,    -1,   570,   571,
      -1,   573,    -1,    -1,    -1,   577,    -1,    -1,   580,    -1,
      -1,    -1,    -1,    -1,    -1,   587,    -1,   589,    -1,    -1,
      -1,    -1,    -1,   595,    -1,   597,   598,    -1,    -1,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
     612,   613,    -1,    -1,    -1,    -1,   618,    -1,    -1,    -1,
     622,   623,    -1,   625,   626,    43,   628,    -1,    -1,    -1,
      -1,    -1,   634,   295,    -1,    -1,   638,   639,    -1,   641,
      -1,    -1,   472,    -1,    -1,   475,   648,    -1,   650,   651,
     312,   313,    -1,    -1,    -1,   657,   658,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   155,    -1,   329,    -1,    -1,
      -1,    -1,   334,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,   173,   514,   515,    -1,    -1,   518,   519,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   531,    -1,    30,    -1,    -1,    -1,    -1,    -1,   539,
      -1,    -1,    -1,    -1,    -1,   545,    -1,    44,    -1,    -1,
      -1,    -1,   212,    50,   214,    -1,    -1,    -1,    -1,    56,
      57,    58,    -1,   563,    -1,    -1,    -1,    -1,    -1,    -1,
     570,   571,    -1,   573,    -1,    -1,    -1,   577,    -1,    -1,
     580,    -1,    -1,    -1,    -1,   155,    -1,   587,    -1,   589,
      -1,    -1,    89,    -1,    -1,   595,    -1,   597,   598,    -1,
      -1,    98,    -1,   173,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   612,   613,    -1,    -1,    -1,    -1,   618,    -1,
      -1,    -1,   622,   623,    -1,   625,   626,    -1,   628,    -1,
      -1,    -1,    -1,    -1,   634,   295,    -1,    -1,   638,   639,
     472,   641,   212,   475,   214,    -1,    -1,    -1,   648,    -1,
     650,   651,   312,   313,    -1,    -1,    -1,   657,   658,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   329,
      -1,    59,    -1,    -1,   334,    -1,    -1,    -1,    -1,    67,
      -1,    -1,   514,   515,    -1,    -1,   518,   519,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,    86,   531,
      88,    -1,    90,    91,    92,    93,    -1,   539,    96,    -1,
      -1,    -1,   100,   545,    -1,    -1,   104,    -1,    -1,   107,
      -1,    -1,    -1,    -1,    -1,   295,    -1,    -1,    -1,    -1,
      -1,   563,    -1,    -1,    -1,    -1,    -1,    -1,   570,   571,
     155,   573,   312,   313,    -1,   577,    -1,    -1,   580,    -1,
      -1,    -1,    -1,    -1,    -1,   587,    -1,   589,   173,   329,
      -1,    -1,    -1,   595,   334,   597,   598,    -1,    -1,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
     612,   613,    -1,    -1,    -1,    -1,   618,    -1,    -1,    -1,
     622,   623,    -1,   625,   626,    43,   628,   212,    -1,   214,
      -1,    -1,   634,    -1,    -1,    -1,   638,   639,    -1,   641,
      -1,    -1,   472,    -1,    -1,   475,   648,    -1,   650,   651,
      -1,    -1,    -1,    -1,    -1,   657,   658,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   514,   515,    -1,    -1,   518,   519,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   531,    -1,    -1,    -1,    -1,    44,    -1,    -1,   539,
     295,    -1,    50,    -1,    52,   545,    -1,    -1,    56,    57,
      58,    -1,    -1,    -1,    -1,    -1,    -1,   312,   313,    -1,
      -1,    -1,   472,   563,    -1,   475,    -1,    -1,    -1,    -1,
     570,   571,    -1,   573,   329,    -1,    -1,   577,    -1,   334,
     580,    89,    -1,    -1,    -1,    -1,    -1,   587,    -1,   589,
      98,    -1,    -1,   101,    -1,   595,    -1,   597,   598,    -1,
      -1,    -1,    -1,    -1,   514,   515,    -1,    -1,   518,   519,
      -1,    -1,   612,   613,    -1,    -1,    -1,    -1,   618,    -1,
      -1,   531,   622,   623,    -1,   625,   626,    -1,   628,   539,
      -1,    -1,    -1,    -1,   634,   545,    -1,    -1,   638,   639,
      -1,   641,    -1,    -1,    -1,    -1,    -1,    -1,   648,    -1,
     650,   651,    -1,   563,    -1,    -1,    -1,   657,   658,    -1,
     570,   571,    -1,   573,    -1,    -1,    -1,   577,    -1,   162,
     580,    -1,    -1,    -1,    -1,    -1,    -1,   587,    -1,   589,
      -1,    -1,    -1,    -1,    -1,   595,    -1,   597,   598,    -1,
      -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   612,   613,    -1,   198,    -1,    -1,   618,    -1,
     203,    -1,   622,   623,    -1,   625,   626,   472,   628,    -1,
     475,    -1,    -1,    -1,   634,    -1,    -1,    -1,   638,   639,
      -1,   641,    -1,    -1,    -1,    -1,    -1,    -1,   648,    -1,
     650,   651,    -1,    -1,    -1,   162,    -1,   657,   658,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,   514,
     515,    13,    -1,   518,   519,    -1,    -1,    -1,   261,   262,
     187,    -1,    -1,    -1,    -1,    -1,   531,    -1,    -1,    -1,
      -1,   198,    -1,    -1,   539,    -1,   203,    -1,    -1,    -1,
     545,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      -1,    -1,    -1,    -1,    56,    57,    58,    -1,   563,    -1,
      -1,    -1,    -1,    -1,    -1,   570,   571,    -1,   573,    -1,
      -1,   314,   577,    -1,    -1,   580,    -1,    -1,   321,   322,
     323,   324,   587,    -1,   589,   328,    -1,    89,   331,   332,
     595,    -1,   597,   598,   261,   262,    98,   340,    -1,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   612,   613,    -1,
      -1,    -1,   355,   618,    -1,    -1,    -1,   622,   623,    -1,
     625,   626,    -1,   628,    -1,    -1,    -1,   370,    -1,   634,
      -1,    48,    -1,   638,   639,    -1,   641,    -1,    -1,    -1,
      -1,    -1,    59,   648,    -1,   650,   651,   314,   391,    -1,
      67,    -1,   657,   658,    -1,   322,   323,    -1,   401,    76,
      -1,   328,    -1,    -1,   407,   332,    -1,    -1,   411,    86,
      -1,    88,    -1,   340,    91,    92,    93,    -1,    -1,    96,
      -1,    -1,    -1,   100,    -1,    -1,    -1,   104,    -1,    -1,
     107,    -1,    -1,   184,   185,    -1,    -1,    -1,   441,    -1,
      -1,    -1,   445,   370,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,    -1,   391,    -1,   184,   185,    -1,    -1,
      -1,   474,    -1,    -1,   401,   478,    -1,    30,    -1,    -1,
     407,   484,    -1,   486,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    -1,   499,    50,    -1,    52,
      53,     7,    -1,    56,    57,    58,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   441,    -1,    -1,    -1,   445,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   538,    89,    -1,    -1,   257,
     258,   259,   260,    -1,    -1,    98,    -1,   474,   101,    -1,
      -1,   478,    -1,    59,    -1,    61,   559,    63,    -1,   486,
      66,    67,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,
      76,    -1,    78,    -1,    -1,   578,   579,    -1,    -1,    85,
      -1,    87,    88,    -1,    -1,    91,    92,    93,    -1,    95,
      96,    -1,    -1,    -1,   100,    -1,    -1,   600,   104,    -1,
     106,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   538,   615,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   559,   384,   385,   386,   387,   388,   389,   390,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   578,   579,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,    -1,   384,   385,   386,   387,
     388,   389,   390,   600,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,   438,   615,    -1,
      -1,    -1,   443,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    48,
     438,    50,    -1,    -1,    -1,   443,    -1,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    13,
      -1,    -1,   503,    -1,   505,    -1,    -1,    -1,   509,    -1,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,   503,    50,   505,    52,    53,
      -1,   509,    56,    57,    58,    59,    -1,    61,    62,    63,
      64,    -1,    66,    67,    -1,    69,    70,    71,    72,    -1,
      -1,    -1,    76,    -1,    78,    79,    80,    -1,    -1,    -1,
      -1,    85,    -1,    87,    88,    89,    -1,    91,    92,    93,
      94,    95,    96,    -1,    98,    99,   100,   101,   102,    -1,
     104,   105,   106,   107,   108,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    -1,    13,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    47,    -1,    -1,    50,
      48,    -1,    50,    54,    52,    53,    -1,    -1,    56,    57,
      58,    59,    -1,    61,    62,    63,    64,    -1,    66,    67,
      -1,    69,    70,    71,    72,    -1,    -1,    -1,    76,    -1,
      78,    79,    80,    -1,    -1,    -1,    -1,    85,    -1,    87,
      88,    89,    -1,    91,    92,    93,    94,    95,    96,    -1,
      98,    99,   100,   101,   102,    -1,   104,   105,   106,   107,
     108,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    13,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    -1,    47,    -1,    -1,    50,    48,    -1,    50,    54,
      52,    53,    -1,    -1,    56,    57,    58,    59,    -1,    61,
      62,    63,    -1,    -1,    66,    67,    -1,    69,    -1,    71,
      72,    -1,    -1,    -1,    76,    -1,    78,    79,    80,    -1,
      -1,    -1,    -1,    85,    -1,    87,    88,    89,    -1,    91,
      92,    93,    94,    95,    96,    -1,    98,    99,   100,   101,
     102,    -1,   104,   105,   106,   107,   108,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    50,    -1,    52,    53,    -1,    -1,
      56,    57,    58,    59,    -1,    61,    62,    63,    -1,    -1,
      66,    67,    -1,    69,    -1,    71,    72,    -1,    -1,    -1,
      76,    -1,    78,    79,    80,    -1,    -1,    -1,    -1,    85,
      -1,    87,    88,    89,    -1,    91,    92,    93,    94,    95,
      96,    -1,    98,    99,   100,   101,   102,    -1,   104,   105,
     106,   107,   108,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,
      50,    -1,    52,    53,    -1,    -1,    56,    57,    58,    59,
      -1,    61,    62,    63,    -1,    -1,    66,    67,    -1,    69,
      -1,    71,    72,    -1,    -1,    -1,    76,    -1,    78,    79,
      80,    -1,    -1,    -1,    -1,    85,    -1,    87,    88,    89,
      -1,    91,    92,    93,    94,    95,    96,    -1,    98,    99,
     100,   101,   102,    -1,   104,   105,   106,   107,   108,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    50,    -1,    52,    53,
      -1,    -1,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    -1,    66,    67,    -1,    69,    -1,    71,    72,    -1,
      -1,    -1,    76,    -1,    78,    79,    80,    -1,    -1,    -1,
      -1,    85,    -1,    87,    88,    89,    -1,    91,    92,    93,
      94,    95,    96,    -1,    98,    99,   100,   101,   102,    -1,
     104,   105,   106,   107,   108,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    50,    -1,    52,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    -1,    66,    67,
      -1,    69,    -1,    71,    72,    -1,    -1,    -1,    76,    -1,
      78,    79,    80,    -1,    -1,    -1,    -1,    85,    -1,    87,
      88,    89,    -1,    91,    92,    93,    94,    95,    96,    -1,
      98,    99,   100,   101,   102,    -1,   104,   105,   106,   107,
     108,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    50,    -1,
      52,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    80,     3,
       4,     5,     6,     7,     8,     9,    10,    89,    -1,    13,
      -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,    -1,    -1,   105,    -1,    -1,   108,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    48,    -1,    50,    -1,    52,    -1,
      -1,    -1,    56,    57,    58,    -1,    -1,    -1,    62,    -1,
      30,    -1,    -1,    -1,    -1,    69,    -1,    71,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    79,    80,    -1,    -1,    49,
      50,    -1,    52,    53,    -1,    89,    56,    57,    58,    -1,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,    -1,
      -1,   105,    -1,    -1,   108,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    59,    -1,    -1,    89,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    98,    -1,
      -1,   101,    30,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    -1,    88,    44,    -1,    91,    92,
      93,    -1,    50,    96,    -1,    -1,    -1,   100,    56,    57,
      58,   104,    -1,    61,   107,    63,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    87,
      -1,    89,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,
      98,    -1,    -1,   101,    -1,    -1,    -1,    -1,   106,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,     7,    -1,    61,    -1,    63,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    72,    48,
      -1,    50,    -1,    -1,    78,    -1,    -1,    56,    57,    58,
      -1,    85,    61,    87,    63,    89,    -1,    66,    -1,    -1,
      -1,    95,    -1,    72,    98,    -1,    -1,   101,    -1,    78,
      -1,    53,   106,    -1,     7,    -1,    85,    59,    87,    61,
      89,    63,    -1,    -1,    66,    67,    95,    -1,    -1,    98,
      72,    -1,   101,    -1,    76,    -1,    78,   106,    -1,    -1,
      -1,    -1,    -1,    85,    -1,    87,    88,    -1,    -1,    91,
      92,    93,    -1,    95,    96,    -1,    -1,    -1,   100,    -1,
      53,    -1,   104,     7,   106,   107,    59,    -1,    61,    -1,
      63,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    -1,    76,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    -1,    87,    88,    -1,    -1,    91,    92,
      93,    -1,    95,    96,    -1,    -1,    -1,   100,    -1,    53,
      -1,   104,     7,   106,   107,    59,    -1,    61,    -1,    63,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    76,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    87,    88,    -1,    -1,    91,    92,    93,
      -1,    95,    96,    -1,     7,    -1,   100,    -1,    53,    -1,
     104,    -1,   106,   107,    59,    -1,    61,    -1,    63,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    76,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    -1,    87,    88,    -1,    -1,    91,    92,    93,    -1,
      95,    96,    -1,    -1,    -1,   100,    59,    -1,    61,   104,
      63,   106,   107,    66,    -1,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    -1,    76,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    -1,    87,    88,    -1,    -1,    91,    92,
      93,    -1,    95,    96,    -1,    -1,    -1,   100,    -1,    -1,
      -1,   104,    -1,   106,   107,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    44,    -1,    -1,    -1,
      48,    -1,    50,    -1,    -1,    -1,    -1,    44,    56,    57,
      58,    -1,    -1,    50,    51,    -1,    -1,    -1,    -1,    56,
      57,    58,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      98,    -1,    89,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    -1,    44,   101,    -1,    -1,    -1,    -1,    50,
      51,    -1,    -1,    -1,    -1,    56,    57,    58,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    98,    -1,    44,
     101,    -1,    -1,    -1,    -1,    50,    51,    -1,    -1,    -1,
      44,    56,    57,    58,    -1,    -1,    50,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    98,    -1,    89,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    -1,    44,   101,    -1,    -1,
      48,    -1,    50,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      98,    -1,    44,   101,    -1,    -1,    -1,    -1,    50,    51,
      -1,    -1,    -1,    44,    56,    57,    58,    -1,    -1,    50,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    98,    -1,    89,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    44,
     101,    -1,    -1,    48,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    98,    -1,    44,   101,    -1,    -1,    -1,
      -1,    50,    51,    -1,    -1,    -1,    44,    56,    57,    58,
      -1,    -1,    50,    51,    -1,    -1,    -1,    -1,    56,    57,
      58,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    98,
      -1,    89,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      98,    -1,    44,   101,    -1,    -1,    48,    -1,    50,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    98,    -1,    44,   101,
      -1,    -1,    48,    -1,    50,    -1,    -1,    -1,    -1,    44,
      56,    57,    58,    -1,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    13,     3,     4,     5,     6,     7,
       8,     9,    10,    89,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    89,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    -1,    -1,   101,    -1,    -1,    -1,
      -1,    50,    51,    -1,    -1,    -1,    -1,    56,    57,    58,
      -1,    -1,    50,    51,    -1,    -1,    -1,    -1,    56,    57,
      58,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    13,     3,     4,     5,     6,     7,     8,     9,    10,
      89,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      -1,    89,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      98,    -1,    -1,   101,    -1,    -1,    -1,    -1,    50,    51,
      -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,    50,
      51,    -1,    -1,    -1,    -1,    56,    57,    58,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    -1,    13,     3,
       4,     5,     6,     7,     8,     9,    10,    89,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    89,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,
     101,    -1,    -1,    -1,    -1,    50,    51,    -1,    -1,    -1,
      -1,    56,    57,    58,    -1,    -1,    50,    51,    -1,    -1,
      -1,    -1,    56,    57,    58,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    -1,    89,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    -1,    -1,   101,    -1,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      98,    -1,    -1,   101
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    48,    59,    67,    76,    83,    86,    88,    90,    91,
      92,    93,    96,   100,   104,   107,   111,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   172,     7,
     112,   112,   124,   125,   126,   112,   124,     0,   129,   131,
     134,   128,   129,    67,    86,   136,    75,    82,   138,   142,
     143,    47,    48,    52,    75,   173,   174,    47,    48,   129,
     112,   112,   120,   121,   124,   120,   122,   144,    52,   145,
     139,   143,   145,    14,   112,    53,    61,    63,    66,    72,
      78,    85,    87,    95,   106,   114,   115,   116,   117,   118,
     119,   120,   123,   124,   135,   149,   155,   175,   176,   177,
     178,   122,    49,   174,   140,   142,   143,   173,   174,    49,
      53,    96,   125,   135,   137,   146,   147,   148,   149,   154,
     155,   164,   165,   167,   145,   145,    48,   112,   150,   151,
     152,   156,    54,    54,    54,   114,    48,    53,   176,   122,
     145,   141,   143,   145,   174,   122,    52,   181,    50,   167,
      53,   147,    48,   163,   181,    52,   103,   161,   170,    50,
      48,    49,    17,    54,    54,    55,    55,    55,   150,   156,
     145,   145,    53,   182,   168,   169,   161,   166,     3,     4,
       5,     6,     8,     9,    10,    13,    48,    50,    53,    56,
      57,    58,    62,    69,    71,    79,    80,    89,    94,    98,
      99,   100,   101,   102,   105,   108,   112,   113,   114,   124,
     135,   137,   171,   181,   184,   185,   186,   187,   188,   190,
     191,   192,   194,   195,   196,   198,   206,   212,   216,   219,
     240,   241,   242,   243,   244,   245,   249,   250,   251,   253,
     257,   258,   259,   260,   261,   262,   264,   265,   280,   281,
     121,   162,   170,   157,   158,   112,   151,    11,    12,    30,
      44,    50,    52,    98,   101,   124,   153,   179,   251,   258,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   283,    55,    55,    48,   184,    51,   114,   159,   160,
     170,   170,   124,   257,   259,   263,   263,   283,    48,   112,
      48,   112,   217,    50,    50,   115,   120,   121,    48,   283,
      47,    50,    50,    50,    50,    48,   283,   181,    50,    46,
     150,    50,    54,    53,   184,    53,   185,    48,    48,    47,
      54,    10,    13,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    43,   282,    49,    51,   159,   263,
     263,   263,   263,   115,   124,   283,    49,    53,   153,   180,
      54,    14,    15,    16,    11,    12,    40,    41,    42,    32,
      33,    35,    36,    84,    31,    34,    38,    39,    37,    28,
      29,    45,   183,   152,    49,    51,    51,    48,    48,   100,
     188,    48,   187,   195,   237,   239,   283,    54,   254,   255,
     254,    50,    48,   112,    51,   252,   283,   283,   283,    51,
     252,    48,    65,    77,   246,   247,   248,   283,   188,    51,
     252,   283,    53,   112,   283,   279,   121,    51,    51,    54,
     256,    54,   256,    51,    53,    49,    53,   263,   263,   263,
     268,   268,   269,   269,   269,   270,   270,   270,   270,   115,
     119,   271,   271,   272,   273,   274,   275,   276,   283,    53,
     160,   218,    48,   283,    48,    49,    51,   283,    54,   255,
     256,   256,    51,   252,    50,    48,    49,    51,    51,    51,
      48,    51,    50,   181,   247,   248,    51,    51,    55,    50,
      55,   263,    55,    51,    54,    51,   266,    53,   153,    46,
     108,    51,   238,   239,    48,    48,   283,   195,   197,   199,
      55,    51,    51,   252,   283,    48,    52,   207,   181,    48,
     160,   213,    51,   252,   263,    55,   266,   278,    50,   227,
      51,    51,   238,    51,   238,    48,   188,    79,    80,   108,
     112,   189,   190,   193,   202,   214,   228,    51,    53,    64,
      70,   208,   209,   210,   211,    51,   188,    51,   283,   188,
     226,   225,    51,   223,    51,    51,   238,    50,    50,    50,
      46,   200,   283,   284,    46,    53,   209,   210,    53,   184,
     211,   181,    51,   188,   188,   224,   188,   222,   221,    51,
      48,   237,   283,   283,   189,    73,    46,    53,    48,   188,
     188,   188,   220,    48,   283,    48,    51,    51,   201,   188,
      51,   238,    48,    48,   283,   203,   215,   188,   236,    51,
      51,   238,    51,   238,    48,   189,   189,   189,   235,   234,
      51,   232,    51,    51,   238,   204,   189,   189,   233,   189,
     231,   230,    51,    73,   189,   189,   189,   229,   205,   189,
     189
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
#line 218 "parse.y"
    {	(yyval.status) = (yyvsp[(1) - (1)].status);
							printf("COMPILATION OVER: %d errors found\n", error_count);
							printf("\n\n");
							print();
						}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 227 "parse.y"
    {
			(yyval.sval) = strdup(yylval.sval);
		}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 233 "parse.y"
    {
							int* loc = (int*)malloc(sizeof(int));
							*loc = (yyvsp[(1) - (1)].ival);
							(yyval.attr) = makePrimNode(string(), KLITERAL, TINT, vector<int>(), loc, ANONE, NULL);
						}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 239 "parse.y"
    {
							float* loc = (float*)malloc(sizeof(float));
							*loc = (yyvsp[(1) - (1)].fval);
							(yyval.attr) = makePrimNode(string(), KLITERAL, TFLOAT, vector<int>(), loc, ANONE, NULL);
						}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 245 "parse.y"
    {
							long* loc = (long*)malloc(sizeof(long));
							*loc = (yyvsp[(1) - (1)].lval);
							(yyval.attr) = makePrimNode(string(), KLITERAL, TLONG, vector<int>(), loc, ANONE, NULL);
						}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 251 "parse.y"
    {
							double* loc = (double*)malloc(sizeof(double));
							*loc = (yyvsp[(1) - (1)].dval);
							(yyval.attr) = makePrimNode(string(), KLITERAL, TDOUBLE, vector<int>(), loc, ANONE, NULL);
						}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 257 "parse.y"
    {
							bool* loc = (bool*)malloc(sizeof(bool));
							*loc = true;
							(yyval.attr) = makePrimNode(string(), KLITERAL, TBOOLEAN, vector<int>(), loc, ANONE, NULL);
						}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 263 "parse.y"
    {
							bool* loc = (bool*)malloc(sizeof(bool));
							*loc = false;
							(yyval.attr) = makePrimNode(string(), KLITERAL, TBOOLEAN, vector<int>(), loc, ANONE, NULL);
						}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 269 "parse.y"
    {
							char* loc = (char*)malloc(sizeof(char));
							*loc = (yyvsp[(1) - (1)].cval);
							(yyval.attr) = makePrimNode(string(), KLITERAL, TCHAR, vector<int>(), loc, ANONE, NULL);
						}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 275 "parse.y"
    {
							string str = string((yyvsp[(1) - (1)].sval));
							(yyval.attr) = makePrimNode(string(), KLITERAL, TSTRING, vector<int>(), &str, ANONE, NULL);
						}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 280 "parse.y"
    {
							int** loc = (int**)malloc(sizeof(int));
							*loc = 0;
							(yyval.attr) = makePrimNode(string(), KLITERAL, TVOID, vector<int>(), loc, ANONE, NULL);
							(yyval.attr)->dimensions.push_back(1);
							
						}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 291 "parse.y"
    {
							(yyval.attr) = (yyvsp[(1) - (1)].attr);
						}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 295 "parse.y"
    {
							(yyval.attr) = (yyvsp[(1) - (1)].attr);
						}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 301 "parse.y"
    {
							(yyval.attr) = (yyvsp[(1) - (1)].attr);
						}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 305 "parse.y"
    {
							(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
						}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 308 "parse.y"
    {
							(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TVOID, vector<int>(), NULL, ANONE, NULL);
						}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 315 "parse.y"
    {
							(yyval.attr) = (yyvsp[(1) - (1)].attr);
						}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 319 "parse.y"
    {
							(yyval.attr) = (yyvsp[(1) - (1)].attr);
						}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 326 "parse.y"
    {
							(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TBYTE, vector<int>(), NULL, ANONE, NULL);
						}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 330 "parse.y"
    {	
							(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TSHORT, vector<int>(), NULL, ANONE, NULL);
						}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 334 "parse.y"
    {	
							(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TINT, vector<int>(), NULL, ANONE, NULL);
						}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 338 "parse.y"
    {	
							(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TLONG, vector<int>(), NULL, ANONE, NULL);
						}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 342 "parse.y"
    {	
							(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TCHAR, vector<int>(), NULL, ANONE, NULL);
						}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 349 "parse.y"
    {	
							(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TFLOAT, vector<int>(), NULL, ANONE, NULL);
						}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 353 "parse.y"
    {	
							(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TDOUBLE, vector<int>(), NULL, ANONE, NULL);
						}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 360 "parse.y"
    {
							(yyval.attr) = (yyvsp[(1) - (1)].attr);
						}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 363 "parse.y"
    {
							(yyval.attr)= (yyvsp[(1) - (1)].attr);
						}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 370 "parse.y"
    {
							(yyval.attr) = findtype(current, (yyvsp[(1) - (1)].name), KCLASS);
						}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 377 "parse.y"
    {
							(yyval.attr) = (yyvsp[(1) - (1)].attr);
						}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 384 "parse.y"
    {
							//Not implemented
						}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 391 "parse.y"
    {
							(yyvsp[(1) - (3)].attr)->dimensions.push_back(0);
							(yyval.attr) = (yyvsp[(1) - (3)].attr);
						}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 396 "parse.y"
    {
							element* qualifiedtype = findtype(current, (yyvsp[(1) - (3)].name));
							struct element* newnode = makeRefNode(string(), KCLASS, qualifiedtype, vector<int>(), NULL, ANONE, NULL, NULL, NULL);
							newnode->dimensions.push_back(0);
							(yyval.attr) = newnode;
						}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 403 "parse.y"
    {
							(yyvsp[(1) - (3)].attr)->dimensions.push_back(0);
							(yyval.attr) = (yyvsp[(1) - (3)].attr);
						}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 411 "parse.y"
    {
							(yyval.name)= (yyvsp[(1) - (1)].name);
						}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 415 "parse.y"
    {
							(yyval.name)= (yyvsp[(1) - (1)].name);
						}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 422 "parse.y"
    {
							struct namenode * newnode = new namenode();
							newnode->name = string((yyvsp[(1) - (1)].sval));
							newnode->next = NULL;
							(yyval.name) = newnode;
						}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 431 "parse.y"
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
#line 443 "parse.y"
    {	/*Not Implemented*/	}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 444 "parse.y"
    {	/*Not Implemented*/	}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 445 "parse.y"
    {	/*Not Implemented*/	}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 446 "parse.y"
    {	/*Not Implemented*/	}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 447 "parse.y"
    {	/*Not Implemented*/	}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 448 "parse.y"
    {	/*Not Implemented*/	}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 449 "parse.y"
    {	(yyval.status) = (yyvsp[(1) - (1)].status);	}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 450 "parse.y"
    {	(yyval.status) = OKAY;	}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 461 "parse.y"
    {
							(yyval.status) = (yyvsp[(1) - (1)].status);
						}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 465 "parse.y"
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
#line 494 "parse.y"
    {
						(yyval.status) = (yyvsp[(1) - (1)].status);
					}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 497 "parse.y"
    {	/*Not Implemented*/	}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 499 "parse.y"
    {
						(yyval.status) = OKAY;
					}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 506 "parse.y"
    {
						(yyval.ival) = (yyvsp[(1) - (1)].ival);
					}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 509 "parse.y"
    {	/*	Not implemented	*/	}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 513 "parse.y"
    {	(yyval.ival) = yylval.ival;	}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 514 "parse.y"
    {	(yyval.ival) = yylval.ival;	}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 515 "parse.y"
    {	(yyval.ival) = yylval.ival;	}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 516 "parse.y"
    {	/* Not implemented	*/ 	}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 517 "parse.y"
    {	/* Not implemented	*/ 	}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 518 "parse.y"
    {	/* Not implemented	*/ 	}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 519 "parse.y"
    {	/* Not implemented	*/ 	}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 520 "parse.y"
    {	/* Not implemented	*/ 	}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 521 "parse.y"
    {	/* Not implemented	*/ 	}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 522 "parse.y"
    {	/* Not implemented	*/ 	}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 529 "parse.y"
    {

		if(alreadypresent((yyvsp[(2) - (2)].sval))){
			printf("error at line #%d: %s already declared\n", line_number, (yyvsp[(2) - (2)].sval));
			current->symtbl.erase(string((yyvsp[(2) - (2)].sval)));
			ehere(0);
		}	
		element* newelem = makeRefNode(string((yyvsp[(2) - (2)].sval)), KCLASS, NULL, vector<int>(), NULL, APUBLIC, NULL, NULL, NULL);
		current->symtbl.insert({string((yyvsp[(2) - (2)].sval)), newelem});
		scope* newscope = createScope(string((yyvsp[(2) - (2)].sval)), current, newelem);
		newelem->desc = newscope;
		current = newscope;
	}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 543 "parse.y"
    {
		revertscope();
		(yyval.status) = (yyvsp[(4) - (4)].status);
	}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 548 "parse.y"
    {
		if(alreadypresent((yyvsp[(2) - (3)].sval))){
			printf("error at line #%d: %s already declared\n", line_number, (yyvsp[(2) - (3)].sval));
			current->symtbl.erase(string((yyvsp[(2) - (3)].sval)));
			ehere(0);
		}	
										
		element* newelem = makeRefNode(string((yyvsp[(2) - (3)].sval)), KCLASS, NULL, vector<int>(), NULL, APUBLIC, NULL, (yyvsp[(3) - (3)].attr), NULL);
		current->symtbl.insert({string((yyvsp[(2) - (3)].sval)), newelem});
		scope* newscope = createScope(string((yyvsp[(2) - (3)].sval)), current, newelem);
		newelem->desc = newscope;
		current = newscope;
		}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 562 "parse.y"
    {
			printsymtbl(current->symtbl);
			revertscope();
			
			(yyval.status) = (yyvsp[(5) - (5)].status);
		}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 569 "parse.y"
    {	/* Not implemented	*/ 	}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 570 "parse.y"
    {	/* Not implemented	*/ 	}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 572 "parse.y"
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
				
		element* newelem = makeRefNode(string((yyvsp[(3) - (3)].sval)), KCLASS, NULL, vector<int>(), NULL, mod, NULL, NULL, NULL);
		current->symtbl.insert({string((yyvsp[(3) - (3)].sval)), newelem});
		scope* newscope = createScope(string((yyvsp[(3) - (3)].sval)), current, newelem);
		newelem->desc = newscope;
		current = newscope;
	}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 594 "parse.y"
    {
		revertscope();
		(yyval.status) = (yyvsp[(5) - (5)].status);
	}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 599 "parse.y"
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
		element* newelem = makeRefNode(string((yyvsp[(3) - (4)].sval)), KCLASS, NULL, vector<int>(), NULL, mod, NULL, (yyvsp[(4) - (4)].attr), NULL);
		current->symtbl.insert({string((yyvsp[(3) - (4)].sval)), newelem});
		scope* newscope = createScope(string((yyvsp[(3) - (4)].sval)), current, newelem);
		newelem->desc = newscope;
		current = newscope;
	}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 620 "parse.y"
    {
		revertscope();
		(yyval.status) = (yyvsp[(6) - (6)].status);
	}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 624 "parse.y"
    {	/* Not implemented	*/ 	}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 625 "parse.y"
    {	/* Not implemented	*/ 	}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 629 "parse.y"
    {
							(yyval.attr) = (yyvsp[(2) - (2)].attr);
						}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 645 "parse.y"
    {
			(yyval.status) = OKAY;
		}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 649 "parse.y"
    {
			(yyval.status) = (yyvsp[(2) - (3)].status);
		}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 656 "parse.y"
    {
			(yyval.status) = (yyvsp[(1) - (1)].status);
		}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 660 "parse.y"
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
#line 671 "parse.y"
    {
			(yyval.status) = (yyvsp[(1) - (1)].status);
		}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 674 "parse.y"
    {(yyval.status) = OKAY;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 676 "parse.y"
    {
			(yyval.status) = (yyvsp[(1) - (1)].status);
		}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 682 "parse.y"
    {(yyval.status) = (yyvsp[(1) - (1)].status);}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 683 "parse.y"
    {(yyval.status) = (yyvsp[(1) - (1)].status);}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 685 "parse.y"
    {
			(yyval.status) = (yyvsp[(1) - (1)].status);
		}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 693 "parse.y"
    {	
			bool ret = coercelist( (yyvsp[(2) - (3)].list), (yyvsp[(1) - (3)].attr));
			listofelements* e = (yyvsp[(2) - (3)].list);
			while(e!=NULL){
				e->elem->kind = KVARIABLE;
				e=e->next;
			}
			(yyval.status) = ret;
		}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 704 "parse.y"
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
			bool ret = coercelist( (yyvsp[(3) - (4)].list), (yyvsp[(2) - (4)].attr));
			listofelements* e = (yyvsp[(3) - (4)].list);
			while(e!=NULL){
				e->elem->kind = KVARIABLE;
				e=e->next;
			}
			(yyval.status) = ret;
		}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 726 "parse.y"
    {
			listofelements* newlist= new listofelements();
			newlist->elem = (yyvsp[(1) - (1)].attr);
			newlist->next = NULL;
			(yyval.list) = newlist;
		}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 733 "parse.y"
    {
			listofelements* list = (yyvsp[(1) - (3)].list);
			while(list->next!=NULL) list = list->next;
			listofelements* newdeclaration= new listofelements();
			newdeclaration->elem = (yyvsp[(3) - (3)].attr);
			newdeclaration->next = NULL;
			list->next = newdeclaration;
			(yyval.list) = (yyvsp[(1) - (3)].list);
		}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 747 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 751 "parse.y"
    {
			if(!iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				printf("line #%d: incompatible types: \n",line_number);
				(yyval.attr) = makeIllegalNode();
			}else{
				(yyval.attr) = coerce((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr));
			}
		}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 763 "parse.y"
    {
			element* newelem = makePrimNode(string((yyvsp[(1) - (1)].sval)), KUNKNOWN, TUNKNOWN, vector<int>(), NULL, ANONE, NULL);
			if(alreadypresent((yyvsp[(1) - (1)].sval))){
				printf("error at line #%d: %s already declared\n", line_number, (yyvsp[(1) - (1)].sval));
				current->symtbl.erase(string((yyvsp[(1) - (1)].sval)));
				ehere(0);
			}
			current->symtbl.insert({string((yyvsp[(1) - (1)].sval)), newelem});
			(yyval.attr) = newelem;
		}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 774 "parse.y"
    {
			(yyvsp[(1) - (3)].attr) -> dimensions.push_back(0);
			(yyval.attr) = (yyvsp[(1) - (3)].attr);
		}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 782 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 786 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 796 "parse.y"
    {
			revertscope();
			if((yyvsp[(1) - (2)].attr) == NULL || (yyvsp[(2) - (2)].status) == ERROR){
				(yyval.status) = ERROR;
				here(3);
			}
			else (yyval.status) = OKAY;
		}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 808 "parse.y"
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

  case 109:

/* Line 1455 of yacc.c  */
#line 825 "parse.y"
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

  case 110:

/* Line 1455 of yacc.c  */
#line 859 "parse.y"
    {	
			element* func = makePrimNode(string((yyvsp[(1) - (2)].sval)), KPRIMFUNCTION, TUNKNOWN, vector<int>(), NULL, APUBLIC, NULL);
			
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

  case 111:

/* Line 1455 of yacc.c  */
#line 875 "parse.y"
    {
			(yyval.attr) = currentelement();
		}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 879 "parse.y"
    {	
			element* func = makePrimNode(string((yyvsp[(1) - (2)].sval)), KPRIMFUNCTION, TUNKNOWN, vector<int>(), NULL, APUBLIC, NULL);
			
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

  case 113:

/* Line 1455 of yacc.c  */
#line 895 "parse.y"
    {
			listofelements* param = (yyvsp[(4) - (5)].list);
			while(param!=NULL){
				current->symtbl.insert({string(param->elem->name), param->elem});
				if(PDEBUG) printf("%d inserting %s in %s's argumentlist\n", line_number, param->elem->name.c_str(), current->lexeme.c_str());
				param= param->next;
			}
			currentelement()->arguments = (yyvsp[(4) - (5)].list);
			(yyval.attr) = currentelement();
		}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 910 "parse.y"
    {
			listofelements* param = new listofelements();
			param->elem = (yyvsp[(1) - (1)].attr);
			param->next = NULL;
			(yyval.list) = param;
		}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 917 "parse.y"
    {
			listofelements* param = new listofelements();
			param->elem = (yyvsp[(3) - (3)].attr);
			param->next = NULL;
			listofelements* list = (yyvsp[(1) - (3)].list); 
			while(list->next != NULL) list = list->next;
			list->next = param;
			(yyval.list) = (yyvsp[(1) - (3)].list);
		}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 930 "parse.y"
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

  case 121:

/* Line 1455 of yacc.c  */
#line 957 "parse.y"
    {
			(yyval.status) = (yyvsp[(1) - (1)].status);
		}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 961 "parse.y"
    {
			(yyval.status) = OKAY;
		}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 973 "parse.y"
    {
			revertscope();
			if((yyvsp[(1) - (2)].attr) == NULL || (yyvsp[(2) - (2)].status) == ERROR){
				(yyval.status) = ERROR;
				here(4);
			}
			else (yyval.status) = OKAY;
		}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 982 "parse.y"
    {
			if((yyvsp[(1) - (2)].ival)==PUBLIC){
				(yyvsp[(2) - (2)].attr)->mod = APUBLIC;
			}else if((yyvsp[(1) - (2)].ival)==PROTECTED){
				(yyvsp[(2) - (2)].attr)->mod = APROTECTED;
			}else if((yyvsp[(1) - (2)].ival)==PRIVATE){
				(yyvsp[(2) - (2)].attr)->mod = APRIVATE;
			}
		}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 992 "parse.y"
    {
			revertscope();
			if((yyvsp[(2) - (4)].attr) == NULL || (yyvsp[(4) - (4)].status)==ERROR){
				(yyval.status) = ERROR;
				here(5);
			}else (yyval.status) = OKAY;
		}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 999 "parse.y"
    {(yyval.status) = OKAY;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1000 "parse.y"
    {(yyval.status) = OKAY;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1005 "parse.y"
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
			element* func = makePrimNode((yyvsp[(1) - (2)].name)->name, KCONSTRUCTOR, TUNKNOWN, vector<int>(), NULL, APUBLIC, NULL);
			
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
		}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 1032 "parse.y"
    {
			(yyval.attr) = currentelement();
		}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1036 "parse.y"
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
			element* func = makePrimNode(string((yyvsp[(1) - (2)].name)->name), KCONSTRUCTOR, TUNKNOWN, vector<int>(), NULL, APUBLIC, NULL);
			
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
		}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1063 "parse.y"
    {
			listofelements* param = (yyvsp[(4) - (5)].list);
			while(param!=NULL){
				current->symtbl.insert({string(param->elem->name), param->elem});
				if(PDEBUG) printf("%d inserting %s in %s's argumentlist\n", line_number, param->elem->name.c_str(), current->lexeme.c_str());
				param= param->next;
			}
			currentelement()->arguments = (yyvsp[(4) - (5)].list);
			(yyval.attr) = currentelement();
		}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1077 "parse.y"
    {
			(yyval.status) = OKAY;
		}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1082 "parse.y"
    {
			if((yyvsp[(2) - (3)].status) == OKAY){
				(yyval.status) = OKAY;
			}else (yyval.status) = ERROR;
			here(6);
		}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1090 "parse.y"
    {
			if((yyvsp[(2) - (3)].status) == OKAY){
				(yyval.status) = OKAY;
			}else (yyval.status) = ERROR;
			here(7);
		}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1099 "parse.y"
    {
			if((yyvsp[(2) - (4)].status) == OKAY && (yyvsp[(3) - (4)].status)==OKAY){
				(yyval.status) = OKAY;
			}else (yyval.status) = ERROR;
			here(8);
		}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1109 "parse.y"
    {
			(yyval.status) = OKAY;
		}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1114 "parse.y"
    {
			symmap::iterator it = current->symtbl.find(current->lexeme);
			
			if(it == current->symtbl.end()){
				printf("error at line #%d:constructor doesn't exist\n", line_number);
				(yyval.status) = ERROR;
				ehere(9);
			}else{
				listofelements* arglist = it->second->arguments;
				if(iscoerciblelisttolist((yyvsp[(3) - (5)].list), arglist)){
					(yyval.status) = OKAY;
				}else{
					printf("error at line #%d: wrong parameters passed\n", line_number);
					(yyval.status) = ERROR;
					ehere(10);
				}
			}

		}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1135 "parse.y"
    {
			(yyval.status) = OKAY;
		}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1139 "parse.y"
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
				if(iscoerciblelisttolist((yyvsp[(3) - (5)].list),arglist)){
					(yyval.status) = OKAY;
				}else{
					printf("error at line #%d: wrong parameters passed\n", line_number);
					(yyval.status) = ERROR;
					ehere(12);
				}
			}

		}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1203 "parse.y"
    {
			(yyval.attr) = (yyvsp[(2) - (4)].attr);
		}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1207 "parse.y"
    {
			(yyval.attr) = (yyvsp[(2) - (3)].attr);
		}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1211 "parse.y"
    {
			(yyval.attr) = NULL;
		}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1215 "parse.y"
    {
			(yyval.attr) = NULL;
		}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1222 "parse.y"
    {
			element* newelem = copyelement((yyvsp[(1) - (1)].attr));
			newelem->dimensions.insert(newelem->dimensions.begin(), 1);
			(yyval.attr) = newelem;
		}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1228 "parse.y"
    {
			if(equal((yyvsp[(1) - (3)].attr)->dimensions.begin() +1, (yyvsp[(1) - (3)].attr)->dimensions.end(), (yyvsp[(3) - (3)].attr)->dimensions.begin())){
				(yyvsp[(1) - (3)].attr)->dimensions.front() += 1;
				(yyval.attr) = (yyvsp[(1) - (3)].attr);
			}else{
				printf("error at line #%d: incompatible types\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1241 "parse.y"
    {
			makeblockscope();
		}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1245 "parse.y"
    {
			revertscope();
		}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1249 "parse.y"
    {
			(yyval.status) = (yyvsp[(3) - (5)].status);
		}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1253 "parse.y"
    {
			(yyval.status) = OKAY;
		}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1260 "parse.y"
    {
			(yyval.status) = (yyvsp[(1) - (1)].status);
		}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1264 "parse.y"
    {
			if((yyvsp[(1) - (2)].status) == ERROR || (yyvsp[(2) - (2)].status) == ERROR){
				(yyval.status) = ERROR;
				here(13);
			}else{
				(yyval.status) = OKAY;
			}
		}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1276 "parse.y"
    {
			(yyval.status) = (yyvsp[(1) - (1)].status);
		}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 1280 "parse.y"
    {
			(yyval.status) = (yyvsp[(1) - (1)].status);
		}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 1287 "parse.y"
    {
			(yyval.status) = (yyvsp[(1) - (2)].status);
		}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1291 "parse.y"
    {
			(yyval.status) = (yyvsp[(1) - (1)].status);
		}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1298 "parse.y"
    {
			
			if(!iscoerciblelist((yyvsp[(2) - (2)].list), (yyvsp[(1) - (2)].attr))){
				printf("line# %d: incompatible types\n", line_number);
				ehere(14);
				(yyval.status) = ERROR;
				
			}else{
				bool ret = coercelist((yyvsp[(2) - (2)].list), (yyvsp[(1) - (2)].attr));
				listofelements* e = (yyvsp[(2) - (2)].list);
				while(e!=NULL){
					e->elem->kind = KVARIABLE;
					e=e->next;
				}
				(yyval.status) = ret;
			}
		}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1319 "parse.y"
    {(yyval.status) = (yyvsp[(1) - (1)].status);}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1320 "parse.y"
    {(yyval.status) = (yyvsp[(1) - (1)].status);}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1321 "parse.y"
    {(yyval.status) = (yyvsp[(1) - (1)].status);}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1322 "parse.y"
    {(yyval.status) = (yyvsp[(1) - (1)].status);}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 1323 "parse.y"
    {(yyval.status) =(yyvsp[(1) - (1)].status);}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 1324 "parse.y"
    {(yyval.status) =(yyvsp[(1) - (1)].status);}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1328 "parse.y"
    {(yyval.status) = (yyvsp[(1) - (1)].status);}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1329 "parse.y"
    {(yyval.status) = (yyvsp[(1) - (1)].status);}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 1330 "parse.y"
    {(yyval.status) = (yyvsp[(1) - (1)].status);}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 1331 "parse.y"
    {(yyval.status) =(yyvsp[(1) - (1)].status);}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1332 "parse.y"
    {(yyval.status) =(yyvsp[(1) - (1)].status);}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 1338 "parse.y"
    {
			(yyval.status) = (yyvsp[(1) - (1)].status);
		}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 1341 "parse.y"
    {(yyval.status) = (yyvsp[(1) - (1)].status);}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 1342 "parse.y"
    {(yyval.status) = (yyvsp[(1) - (1)].status);}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1343 "parse.y"
    {(yyval.status) =(yyvsp[(1) - (1)].status);}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 1344 "parse.y"
    {(yyval.status) =(yyvsp[(1) - (1)].status);}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1345 "parse.y"
    {(yyval.status) = (yyvsp[(1) - (1)].status);}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 1346 "parse.y"
    {(yyval.status) = (yyvsp[(1) - (1)].status);}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1347 "parse.y"
    {(yyval.status) = (yyvsp[(1) - (1)].status);}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 1348 "parse.y"
    {(yyval.status) = OKAY;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 1349 "parse.y"
    {(yyval.status) = OKAY;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1350 "parse.y"
    {(yyval.status) = OKAY;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1354 "parse.y"
    {(yyval.status) = OKAY;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1358 "parse.y"
    {(yyval.status) = (yyvsp[(3) - (3)].status);}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 1362 "parse.y"
    {(yyval.status) = (yyvsp[(3) - (3)].status);}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1367 "parse.y"
    {
			if((yyvsp[(1) - (2)].attr)->kind != KILLEGAL){
				(yyval.status) = OKAY;
			}else{
				printf("line #%d: illegal expression statement\n", line_number);
				(yyval.status) = ERROR;
				ehere(15);
			}
		}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1380 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1384 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1388 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1392 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1396 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 1400 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 1404 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1411 "parse.y"
    {
			makeblockscope();
		}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 1415 "parse.y"
    {
			revertscope();
			if((yyvsp[(3) - (6)].attr)->pdtype!=TBOOLEAN){
				printf("line #%d: expression must be boolean\n", line_number);
				(yyval.status) = ERROR;
				ehere(16);
			}else if((yyvsp[(6) - (6)].status)==ERROR){
				(yyval.status) = ERROR;
				here(17);
			}else{
				(yyval.status) = OKAY;
			}
		}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1432 "parse.y"
    {
			makeblockscope();
		}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1436 "parse.y"
    {
			revertscope();
		}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1440 "parse.y"
    {
			makeblockscope();
		}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1444 "parse.y"
    {
			revertscope();
			if((yyvsp[(3) - (10)].attr)->pdtype!=TBOOLEAN){
				printf("line #%d: expression must be boolean\n", line_number);
				(yyval.status) = ERROR;
				ehere(18);
			}else if((yyvsp[(6) - (10)].status)==ERROR || (yyvsp[(10) - (10)].status) ==ERROR){
				(yyval.status) = ERROR;
				here(19);
			}else{
				(yyval.status) = OKAY;
			}
		}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 1461 "parse.y"
    {
			makeblockscope();
		}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1465 "parse.y"
    {
			revertscope();
		}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1469 "parse.y"
    {
			makeblockscope();
		}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1473 "parse.y"
    {
			revertscope();
			if((yyvsp[(3) - (10)].attr)->pdtype!=TBOOLEAN){
				printf("line #%d: expression must be boolean\n", line_number);
				(yyval.status) = ERROR;
				ehere(20);
			}else if((yyvsp[(6) - (10)].status)==ERROR || (yyvsp[(10) - (10)].status)==ERROR){
				(yyval.status) = ERROR;
				here(21);
			}else{
				(yyval.status) = OKAY;
			}
		}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1490 "parse.y"
    {
			if((yyvsp[(5) - (5)].attr)->kind == KILLEGAL){
				printf("line #%d: incompatible types used in switch block\n", line_number);
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

  case 216:

/* Line 1455 of yacc.c  */
#line 1525 "parse.y"
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

  case 217:

/* Line 1455 of yacc.c  */
#line 1541 "parse.y"
    {
			(yyval.attr) = (yyvsp[(2) - (3)].attr);
		}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1545 "parse.y"
    {
			(yyval.attr) = (yyvsp[(2) - (3)].attr);
		}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1549 "parse.y"
    {
			(yyval.attr) = makePrimNode(string(), KUNKNOWN, TWILDCARD, vector<int>(), NULL, ANONE, NULL);
		}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1555 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 1557 "parse.y"
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

  case 222:

/* Line 1455 of yacc.c  */
#line 1576 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (2)].attr);
		}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1582 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1584 "parse.y"
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

  case 225:

/* Line 1455 of yacc.c  */
#line 1602 "parse.y"
    {(yyval.attr) = (yyvsp[(2) - (3)].attr);}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1604 "parse.y"
    {
			(yyval.attr) = makePrimNode(string(), KUNKNOWN, TWILDCARD, vector<int>(), NULL, ANONE, NULL);
		}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1612 "parse.y"
    {
			makeblockscope();
		}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1616 "parse.y"
    {
			//printscopehierarchy();
			
			revertscope();
			if((yyvsp[(3) - (6)].attr)->pdtype != TBOOLEAN){
				printf("line #%d: expression must be boolean\n", line_number);
				(yyval.status) = ERROR;
				ehere(26);
			}else{
				(yyval.status) = (yyvsp[(6) - (6)].status);
			}
		}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1632 "parse.y"
    {
			makeblockscope();
		}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1636 "parse.y"
    {
			revertscope();
			if((yyvsp[(3) - (6)].attr)->pdtype != TBOOLEAN){
				printf("line #%d: expression must be boolean\n", line_number);
				(yyval.status) = ERROR;
				ehere(27);
			}else{
				(yyval.status) = (yyvsp[(6) - (6)].status);
			}
		}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1650 "parse.y"
    {
			makeblockscope();
		}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1654 "parse.y"
    {
			revertscope();
		}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1658 "parse.y"
    {
			if((yyvsp[(7) - (9)].attr)->pdtype != TBOOLEAN){
				printf("line #%d: expression must be boolean\n", line_number);
				(yyval.status) = ERROR;
				ehere(28);
			}else{
				(yyval.status) = (yyvsp[(3) - (9)].status);
			}
		}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1671 "parse.y"
    {
			makeblockscope();
		}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1675 "parse.y"
    {	revertscope();
			(yyval.status) = (yyvsp[(3) - (10)].status) && (yyvsp[(7) - (10)].status) && (yyvsp[(10) - (10)].status) && ((yyvsp[(5) - (10)].attr)->pdtype !=TBOOLEAN);
		}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1679 "parse.y"
    {
			makeblockscope();
		}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1683 "parse.y"
    {	
			revertscope();
			(yyval.status) = (yyvsp[(3) - (9)].status) && (yyvsp[(9) - (9)].status) && ((yyvsp[(5) - (9)].attr)->pdtype !=TBOOLEAN);
		}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1688 "parse.y"
    {
			makeblockscope();
		}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1692 "parse.y"
    {	
			revertscope();
			(yyval.status) = (yyvsp[(3) - (9)].status) && (yyvsp[(6) - (9)].status) && (yyvsp[(9) - (9)].status);	
		}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1697 "parse.y"
    {
			makeblockscope();
		}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1701 "parse.y"
    {	
			revertscope();
			(yyval.status) = (yyvsp[(3) - (8)].status) && (yyvsp[(8) - (8)].status);
		}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1706 "parse.y"
    {
			makeblockscope();
		}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1710 "parse.y"
    {	
			revertscope();
			(yyval.status) = (yyvsp[(6) - (9)].status) && (yyvsp[(9) - (9)].status) && ((yyvsp[(4) - (9)].attr)->pdtype !=TBOOLEAN);
		}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1715 "parse.y"
    {
			makeblockscope();
		}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1719 "parse.y"
    {	
			revertscope();
			(yyval.status) = (yyvsp[(8) - (8)].status) && ((yyvsp[(4) - (8)].attr)->pdtype !=TBOOLEAN);
		}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1724 "parse.y"
    {
			makeblockscope();
		}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1728 "parse.y"
    {	
			revertscope();
			(yyval.status) = (yyvsp[(5) - (8)].status) && (yyvsp[(8) - (8)].status);	
		}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1733 "parse.y"
    {
			makeblockscope();
		}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1737 "parse.y"
    {
			revertscope();
			(yyval.status) = (yyvsp[(7) - (7)].status);	
		}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1747 "parse.y"
    {
			makeblockscope();
		}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 1751 "parse.y"
    {	revertscope();
			(yyval.status) = (yyvsp[(3) - (10)].status) && (yyvsp[(7) - (10)].status) && (yyvsp[(10) - (10)].status) && ((yyvsp[(5) - (10)].attr)->pdtype !=TBOOLEAN);
		}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1755 "parse.y"
    {
			makeblockscope();
		}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1759 "parse.y"
    {	
			revertscope();
			(yyval.status) = (yyvsp[(3) - (9)].status) && (yyvsp[(9) - (9)].status) && ((yyvsp[(5) - (9)].attr)->pdtype !=TBOOLEAN);
		}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1764 "parse.y"
    {
			makeblockscope();
		}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1768 "parse.y"
    {	
			revertscope();
			(yyval.status) = (yyvsp[(3) - (9)].status) && (yyvsp[(6) - (9)].status) && (yyvsp[(9) - (9)].status);	
		}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1773 "parse.y"
    {
			makeblockscope();
		}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1777 "parse.y"
    {	
			revertscope();
			(yyval.status) = (yyvsp[(3) - (8)].status) && (yyvsp[(8) - (8)].status);
		}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1782 "parse.y"
    {
			makeblockscope();
		}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1786 "parse.y"
    {	
			revertscope();
			(yyval.status) = (yyvsp[(6) - (9)].status) && (yyvsp[(9) - (9)].status) && ((yyvsp[(4) - (9)].attr)->pdtype !=TBOOLEAN);
		}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1791 "parse.y"
    {
			makeblockscope();
		}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1795 "parse.y"
    {	
			revertscope();
			(yyval.status) = (yyvsp[(8) - (8)].status) && ((yyvsp[(4) - (8)].attr)->pdtype !=TBOOLEAN);
		}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1800 "parse.y"
    {
			makeblockscope();
		}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1804 "parse.y"
    {	
			revertscope();
			(yyval.status) = (yyvsp[(5) - (8)].status) && (yyvsp[(8) - (8)].status);	
		}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1809 "parse.y"
    {
			makeblockscope();
		}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1813 "parse.y"
    {
			revertscope();
			(yyval.status) = (yyvsp[(7) - (7)].status);	
		}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1821 "parse.y"
    {
			if((yyvsp[(1) - (1)].attr)->kind == KILLEGAL){
				(yyval.status) = ERROR;
				ehere(29);
			}else{
				(yyval.status) = OKAY;
			}
		}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1830 "parse.y"
    {
			(yyval.status) = (yyvsp[(1) - (1)].status);
		}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1837 "parse.y"
    {
			if((yyvsp[(1) - (1)].attr)->kind == KILLEGAL){
				(yyval.status) = ERROR;
				ehere(30);
			}else{
				(yyval.status) = OKAY;
			}
		}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1848 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1850 "parse.y"
    {
			if((yyvsp[(1) - (3)].attr)->kind==KILLEGAL || (yyvsp[(3) - (3)].attr)->kind ==KILLEGAL){
				(yyvsp[(1) - (3)].attr)->kind=KILLEGAL;
				ehere(34);
			}
			(yyval.attr) = (yyvsp[(1) - (3)].attr);
		}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1860 "parse.y"
    {(yyval.status) = OKAY;}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1861 "parse.y"
    {(yyval.status) = OKAY;}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1865 "parse.y"
    {(yyval.status) = OKAY;}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1866 "parse.y"
    {(yyval.status) = OKAY;}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1871 "parse.y"
    {
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

  case 276:

/* Line 1455 of yacc.c  */
#line 1899 "parse.y"
    {
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

  case 287:

/* Line 1455 of yacc.c  */
#line 1945 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1946 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1950 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 1951 "parse.y"
    {(yyval.attr) = currentelement();}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1952 "parse.y"
    {(yyval.attr) = (yyvsp[(2) - (3)].attr);}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1953 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 1954 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1956 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 1960 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 1967 "parse.y"
    {
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
						here(1966);
						(yyval.attr) = makeRefNode(string(), KOBJECT, (yyvsp[(2) - (4)].attr), vector<int>(), NULL, ANONE, NULL, NULL, NULL);
					}
				}
			}
		}
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 1991 "parse.y"
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
					if(!iscoerciblelisttolist(constructor->arguments, (yyvsp[(4) - (5)].list))){
						printf("error at line#%d: unexpected arguments\n", line_number);
						(yyval.attr) =makeIllegalNode();
					}else{
						here(1990);
						(yyval.attr) = makeRefNode(string(), KOBJECT, (yyvsp[(2) - (5)].attr), vector<int>(), NULL, ANONE, NULL, NULL, NULL);
					}
				}
			}
		}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 2018 "parse.y"
    {
			listofelements* list = new listofelements();
			list->elem = (yyvsp[(1) - (1)].attr);
			list->next = NULL;
			(yyval.list) = list;
		}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 2025 "parse.y"
    {
			listofelements* newnode = new listofelements();
			newnode->elem = (yyvsp[(3) - (3)].attr);
			newnode->next = NULL;
			listofelements * list = (yyvsp[(1) - (3)].list);
			while(list->next != NULL) list = list->next;
			list->next = newnode;
			(yyval.list) = (yyvsp[(1) - (3)].list);
		}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 2038 "parse.y"
    {
			vector<int> *vec1 = (yyvsp[(3) - (4)].pspvec)->pvec, *vec2 = (yyvsp[(4) - (4)].pspvec)->pvec;
			vec1->insert(vec1->end(), vec2->begin(), vec2->end());
			(yyval.attr) = makePrimNode(string(), KVARIABLE, (yyvsp[(2) - (4)].attr)->pdtype, *vec1, NULL, ANONE, NULL);
		}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 2044 "parse.y"
    {
			(yyval.attr) = makePrimNode(string(), KVARIABLE, (yyvsp[(2) - (3)].attr)->pdtype, *((yyvsp[(3) - (3)].pspvec)->pvec), NULL, ANONE, NULL);
		}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 2048 "parse.y"
    {
			vector<int> *vec1 = (yyvsp[(3) - (4)].pspvec)->pvec, *vec2=(yyvsp[(4) - (4)].pspvec)->pvec;
			vec1->insert(vec1->end(), vec2->begin(), vec2->end());
			(yyval.attr) = makeRefNode(string(), KOBJECT, (yyvsp[(2) - (4)].attr)->rdtype, *vec1, NULL, ANONE, NULL, NULL, NULL);
		}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 2054 "parse.y"
    {
			(yyval.attr) = makeRefNode(string(), KOBJECT, (yyvsp[(2) - (3)].attr)->rdtype, *(yyvsp[(3) - (3)].pspvec)->pvec, NULL, ANONE, NULL, NULL, NULL);
		}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 2061 "parse.y"
    {
			spvec* spv = (spvec*)malloc(sizeof(spvec));
			vector<int> vec (1, 0);
			spv->pvec = &vec;
			(yyval.pspvec) = spv; 
		}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 2068 "parse.y"
    {
			(*(yyvsp[(1) - (2)].pspvec)->pvec).push_back(0);
		}
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 2076 "parse.y"
    {
			if((yyvsp[(2) - (3)].attr)->kind != KVARIABLE && !iscoercible((yyvsp[(2) - (3)].attr), makePrimNode(string(), KPRIMITIVE, TINT, vector<int>(), NULL, ANONE, NULL))){
				printf("error at line #%d: expecting expressions convertible to int\n", line_number);
				ehere();
			}
		}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 2086 "parse.y"
    {
			vector<int> vec (1, 0);
			spvec* s = (spvec*)malloc(sizeof(spvec));
			s->pvec = &vec;
			(yyval.pspvec) = s; 
		}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 2093 "parse.y"
    {
			(yyvsp[(1) - (3)].pspvec)->pvec->push_back(0);
			(yyval.pspvec) = (yyvsp[(1) - (3)].pspvec);
		}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 2101 "parse.y"
    {
			if((yyvsp[(1) - (3)].attr)->desc == NULL){
				printf("error at line #%d: invalid access\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}else{
				symmap::iterator it = (yyvsp[(1) - (3)].attr)->desc->symtbl.find((yyvsp[(3) - (3)].sval));
				if(it == (yyvsp[(1) - (3)].attr)->desc->symtbl.end()){
					printf("line #%d: member doesn't exist\n");
					(yyval.attr) = makeIllegalNode();
				}else{
					(yyval.attr) = it->second;
				}
			}
		}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 2116 "parse.y"
    {
			element* sup = currentelement()->superclass;
			symmap::iterator it = sup->desc->symtbl.find((yyvsp[(3) - (3)].sval));
			if(it == sup->desc->symtbl.end()){
				printf("line #%d: member doesn't exist\n");
				(yyval.attr) = makeIllegalNode();
			}else{
				(yyval.attr) = it->second;
			}
		}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 2130 "parse.y"
    {
			element* func = findtype(current, (yyvsp[(1) - (4)].name));
			//ASSERT(func->kind == KPRIMFUNCTION || func->kind == KREFFUNCTION);
			if(iscoerciblelisttolist((yyvsp[(3) - (4)].list), func->arguments)){
				if(func->kind == KPRIMFUNCTION){
					(yyval.attr) = makePrimNode(string(), KVARIABLE, func->pdtype, vector<int>(), NULL, ANONE, NULL);
				}else if(func->kind == KREFFUNCTION){
					(yyval.attr) = makeRefNode(string(), KOBJECT, func->rdtype, vector<int>(), NULL, ANONE, NULL, NULL, NULL);
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

  case 312:

/* Line 1455 of yacc.c  */
#line 2148 "parse.y"
    {
			element* func = findtype(current, (yyvsp[(1) - (3)].name));
			//assert(func->kind == KPRIMFUNCTION || func->kind == KREFFUNCTION);
			if(iscoerciblelist(func->arguments, NULL)){
				if(func->kind == KPRIMFUNCTION){
					(yyval.attr) = makePrimNode(string(), KVARIABLE, func->pdtype, vector<int>(), NULL, ANONE, NULL);
				}else if(func->kind == KREFFUNCTION){
					(yyval.attr) = makeRefNode(string(), KOBJECT, func->rdtype, vector<int>(), NULL, ANONE, NULL, NULL, NULL);
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

  case 313:

/* Line 1455 of yacc.c  */
#line 2166 "parse.y"
    {
			namenode* newnode = new namenode();
			newnode->name = string((yyvsp[(3) - (5)].sval));
			element* e = findtypeinthisorsuper((yyvsp[(1) - (5)].attr), newnode, true);
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
						(yyval.attr) = makePrimNode(string(), KVARIABLE, func->pdtype, vector<int>(), NULL, ANONE, NULL);
					}else if(func->kind == KREFFUNCTION){
						(yyval.attr) = makeRefNode(string(), KOBJECT, func->rdtype, vector<int>(), NULL, ANONE, NULL, NULL, NULL);
					}else{
						printf("line #%d: not a function\n", line_number);
						(yyval.attr) = makeIllegalNode();
					}
				}
			}
		}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 2192 "parse.y"
    {
			namenode* newnode = new namenode();
			newnode->name = string((yyvsp[(3) - (6)].sval));
			element* e = findtypeinthisorsuper((yyvsp[(1) - (6)].attr), newnode, true);
			if(e==NULL){
				printf("line #%d: method not found\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}else{
				element* func = e;
				if(!iscoerciblelisttolist((yyvsp[(5) - (6)].list), func->arguments)){
					printf("line #%d: incompatible arguments\n", line_number);
					(yyval.attr) = makeIllegalNode();
				}else{
					if(func->kind == KPRIMFUNCTION){
						(yyval.attr) = makePrimNode(string(), KVARIABLE, func->pdtype, vector<int>(), NULL, ANONE, NULL);
					}else if(func->kind == KREFFUNCTION){
						(yyval.attr) = makeRefNode(string(), KOBJECT, func->rdtype, vector<int>(), NULL, ANONE, NULL, NULL, NULL);
					}else{
						printf("line #%d: not a function\n", line_number);
						(yyval.attr) = makeIllegalNode();
					}
				}
			}
		}
    break;

  case 315:

/* Line 1455 of yacc.c  */
#line 2217 "parse.y"
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
						(yyval.attr) = makePrimNode(string(), KVARIABLE, func->pdtype, vector<int>(), NULL, ANONE, NULL);
					}else if(func->kind == KREFFUNCTION){
						(yyval.attr) = makeRefNode(string(), KOBJECT, func->rdtype, vector<int>(), NULL, ANONE, NULL, NULL, NULL);
					}else{
						printf("line #%d: not a function\n", line_number);
						(yyval.attr) = makeIllegalNode();
					}
				}
			}
		}
    break;

  case 316:

/* Line 1455 of yacc.c  */
#line 2248 "parse.y"
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
				if(!iscoerciblelisttolist(func->arguments, (yyvsp[(5) - (6)].list))){
					printf("line #%d: incompatible arguments\n", line_number);
					(yyval.attr) = makeIllegalNode();
				}else{
					if(func->kind == KPRIMFUNCTION){
						(yyval.attr) = makePrimNode(string(), KVARIABLE, func->pdtype, vector<int>(), NULL, ANONE, NULL);
					}else if(func->kind == KREFFUNCTION){
						(yyval.attr) = makeRefNode(string(), KOBJECT, func->rdtype, vector<int>(), NULL, ANONE, NULL, NULL, NULL);
					}else{
						printf("line #%d: not a function\n", line_number);
						(yyval.attr) = makeIllegalNode();
					}
				}
			}
		}
    break;

  case 317:

/* Line 1455 of yacc.c  */
#line 2283 "parse.y"
    {
			element* elem = findtype(current, (yyvsp[(1) - (4)].name));
			//ASSERT(elem->kind == KVARIABLE || elem->kind == KOBJECT);
			if(elem==NULL){
				printf("line #%d: array not accessible\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}else if(!iscoercible((yyvsp[(3) - (4)].attr), makePrimNode(string(), KPRIMITIVE, TINT, vector<int>(), NULL, ANONE, NULL))){
				printf("line #%d: expecting expression convertible to int\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}else{
				if(elem->kind == KVARIABLE){
					vector<int> vec (elem->dimensions.begin()+1, elem->dimensions.end());
					(yyval.attr) = makePrimNode(string(), KPRIMITIVE, elem->pdtype, vec, NULL, ANONE, NULL);
				}else if(elem->kind == KOBJECT){
					vector<int> vec (elem->dimensions.begin()+1, elem->dimensions.end());
					(yyval.attr) = makeRefNode(string(), KOBJECT, elem->rdtype, vec, NULL, ANONE, NULL, NULL, NULL);
				}else{
					printf("line #%d: not a variable or an object\n", line_number);
					(yyval.attr) = makeIllegalNode();
				}
			}
		}
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 2306 "parse.y"
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
					vector<int> vec (elem->dimensions.begin()+1, elem->dimensions.end());
					(yyval.attr) = makePrimNode(string(), KPRIMITIVE, elem->pdtype, vec, NULL, ANONE, NULL);
				}else if(elem->kind == KOBJECT){
					vector<int> vec (elem->dimensions.begin()+1, elem->dimensions.end());
					(yyval.attr) = makeRefNode(string(), KOBJECT, elem->rdtype, vec, NULL, ANONE, NULL, NULL, NULL);
				}
			}
		}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 2327 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 2328 "parse.y"
    {(yyval.attr) = findtype(current, (yyvsp[(1) - (1)].name));}
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 2329 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 2330 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 2334 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (2)].attr);}
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 2338 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (2)].attr);}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 2342 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 2343 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 2344 "parse.y"
    {(yyval.attr) = (yyvsp[(2) - (2)].attr);}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 2345 "parse.y"
    {(yyval.attr) = (yyvsp[(2) - (2)].attr);}
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 2346 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 2350 "parse.y"
    {(yyval.attr) = (yyvsp[(2) - (2)].attr);}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 2354 "parse.y"
    {(yyval.attr) = (yyvsp[(2) - (2)].attr);}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 2357 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 2358 "parse.y"
    {(yyval.attr) = (yyvsp[(2) - (2)].attr);}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 2360 "parse.y"
    {
			if(!iscoercible((yyvsp[(2) - (2)].attr), makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL))){
				printf("line #%d: expected boolean expression after !\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}else{
				(yyval.attr) = (yyvsp[(2) - (2)].attr);
			}
		}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 2368 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 2373 "parse.y"
    {
			(yyvsp[(2) - (5)].attr)->dimensions = *(yyvsp[(3) - (5)].pspvec)->pvec;
			if(iscoercible((yyvsp[(5) - (5)].attr), (yyvsp[(2) - (5)].attr))){
				(yyval.attr) = copyandcoerce((yyvsp[(5) - (5)].attr), (yyvsp[(2) - (5)].attr));
			}else{
				printf("line #%d: type not coercible\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 2383 "parse.y"
    {
			if(iscoercible((yyvsp[(4) - (4)].attr), (yyvsp[(2) - (4)].attr))){
				(yyval.attr) = copyandcoerce((yyvsp[(4) - (4)].attr), (yyvsp[(2) - (4)].attr));
			}else{
				printf("line #%d: type not coercible\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 2392 "parse.y"
    {
			if(iscoercible((yyvsp[(4) - (4)].attr), (yyvsp[(2) - (4)].attr))){
				(yyval.attr) = copyandcoerce((yyvsp[(4) - (4)].attr), (yyvsp[(2) - (4)].attr));
			}else{
				printf("line #%d: type not coercible\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 2401 "parse.y"
    {
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

  case 340:

/* Line 1455 of yacc.c  */
#line 2414 "parse.y"
    { (yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 2416 "parse.y"
    {
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				(yyval.attr) = copyandcoerce((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr));
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				(yyval.attr) = copyandcoerce((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr));
			}else{
				printf("line #%d: incompatible types\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 2427 "parse.y"
    {
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				(yyval.attr) = copyandcoerce((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr));
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				(yyval.attr) = copyandcoerce((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr));
			}else{
				printf("line #%d: incompatible types\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 2438 "parse.y"
    {
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				(yyval.attr) = copyandcoerce((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr));
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				(yyval.attr) = copyandcoerce((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr));
			}else{
				printf("line #%d: incompatible types\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 2451 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 2453 "parse.y"
    {
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				(yyval.attr) = copyandcoerce((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr));
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				(yyval.attr) = copyandcoerce((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr));
			}else{
				printf("line #%d: incompatible types\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 2464 "parse.y"
    {
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				(yyval.attr) = copyandcoerce((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr));
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				(yyval.attr) = copyandcoerce((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr));
			}else{
				printf("line #%d: incompatible types\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 2477 "parse.y"
    { (yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 2479 "parse.y"
    {
			if(!iscoercible((yyvsp[(1) - (3)].attr), makePrimNode(string(), KPRIMITIVE, TINT, vector<int>(), NULL, ANONE, NULL))){
				printf("line #%d: shift expression must be coercible to int\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}else if((yyvsp[(3) - (3)].attr)->kind != KPRIMITIVE || (yyvsp[(3) - (3)].attr)->pdtype!=TBYTE || (yyvsp[(3) - (3)].attr)->pdtype!=TCHAR || (yyvsp[(3) - (3)].attr)->pdtype!=TSHORT || (yyvsp[(3) - (3)].attr)->pdtype!=TINT || (yyvsp[(3) - (3)].attr)->pdtype!=TLONG){
				printf("line #%d: expression to be shifted must be primitive integral type\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}else{
				(yyval.attr) = (yyvsp[(1) - (3)].attr);
			}
		}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 2492 "parse.y"
    {
			if(!iscoercible((yyvsp[(1) - (3)].attr), makePrimNode(string(), KPRIMITIVE, TINT, vector<int>(), NULL, ANONE, NULL))){
				printf("line #%d: shift expression must be coercible to int\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}else if((yyvsp[(3) - (3)].attr)->kind != KPRIMITIVE || (yyvsp[(3) - (3)].attr)->pdtype!=TBYTE || (yyvsp[(3) - (3)].attr)->pdtype!=TCHAR || (yyvsp[(3) - (3)].attr)->pdtype!=TSHORT || (yyvsp[(3) - (3)].attr)->pdtype!=TINT || (yyvsp[(3) - (3)].attr)->pdtype!=TLONG){
				printf("line #%d: expression to be shifted must be primitive integral type\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}else{
				(yyval.attr) = (yyvsp[(1) - (3)].attr);
			}
		}
    break;

  case 350:

/* Line 1455 of yacc.c  */
#line 2505 "parse.y"
    {
			if(!iscoercible((yyvsp[(1) - (3)].attr), makePrimNode(string(), KPRIMITIVE, TINT, vector<int>(), NULL, ANONE, NULL))){
				printf("line #%d: shift expression must be coercible to int\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}else if((yyvsp[(3) - (3)].attr)->kind != KPRIMITIVE || (yyvsp[(3) - (3)].attr)->pdtype!=TBYTE || (yyvsp[(3) - (3)].attr)->pdtype!=TCHAR || (yyvsp[(3) - (3)].attr)->pdtype!=TSHORT || (yyvsp[(3) - (3)].attr)->pdtype!=TINT || (yyvsp[(3) - (3)].attr)->pdtype!=TLONG){
				printf("line #%d: expression to be shifted must be primitive integral type\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}else{
				(yyval.attr) = (yyvsp[(1) - (3)].attr);
			}
		}
    break;

  case 351:

/* Line 1455 of yacc.c  */
#line 2521 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 352:

/* Line 1455 of yacc.c  */
#line 2525 "parse.y"
    {
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 2536 "parse.y"
    {
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 354:

/* Line 1455 of yacc.c  */
#line 2547 "parse.y"
    {
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 355:

/* Line 1455 of yacc.c  */
#line 2558 "parse.y"
    {
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 356:

/* Line 1455 of yacc.c  */
#line 2569 "parse.y"
    {
			(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
		}
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 2576 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 358:

/* Line 1455 of yacc.c  */
#line 2580 "parse.y"
    {
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 2591 "parse.y"
    {
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 2604 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 2606 "parse.y"
    {
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				(yyval.attr) = (yyvsp[(3) - (3)].attr);
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				(yyval.attr) = (yyvsp[(3) - (3)].attr);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 2619 "parse.y"
    { (yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 2621 "parse.y"
    {
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				(yyval.attr) = (yyvsp[(3) - (3)].attr);
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				(yyval.attr) = (yyvsp[(1) - (3)].attr);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 2634 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 2636 "parse.y"
    {
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				(yyval.attr) = (yyvsp[(3) - (3)].attr);
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				(yyval.attr) = (yyvsp[(1) - (3)].attr);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 2649 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 2651 "parse.y"
    {
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 2664 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 2666 "parse.y"
    {
			if(iscoercible((yyvsp[(1) - (3)].attr), (yyvsp[(3) - (3)].attr))){
				(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				(yyval.attr) = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 2679 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 371:

/* Line 1455 of yacc.c  */
#line 2681 "parse.y"
    {
			if(iscoercible((yyvsp[(3) - (5)].attr), (yyvsp[(5) - (5)].attr))){
				(yyval.attr) = (yyvsp[(5) - (5)].attr);
			}else if(iscoercible((yyvsp[(5) - (5)].attr), (yyvsp[(3) - (5)].attr))){
				(yyval.attr) = (yyvsp[(3) - (5)].attr);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 372:

/* Line 1455 of yacc.c  */
#line 2694 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 373:

/* Line 1455 of yacc.c  */
#line 2695 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 374:

/* Line 1455 of yacc.c  */
#line 2700 "parse.y"
    {
			if(iscoercible((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr))){
				(yyval.attr) = coerce((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].attr));
			}else{
				printf("line #%d: incompatible assignment\n", line_number);
				(yyval.attr) = makeIllegalNode();
			}
		}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 2712 "parse.y"
    {
			(yyval.attr) = findtype(current, (yyvsp[(1) - (1)].name));
		}
    break;

  case 376:

/* Line 1455 of yacc.c  */
#line 2716 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 377:

/* Line 1455 of yacc.c  */
#line 2720 "parse.y"
    {
			(yyval.attr) = (yyvsp[(1) - (1)].attr);
		}
    break;

  case 390:

/* Line 1455 of yacc.c  */
#line 2741 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 2745 "parse.y"
    {(yyval.attr) = (yyvsp[(1) - (1)].attr);}
    break;



/* Line 1455 of yacc.c  */
#line 6858 "y.tab.c"
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
#line 2747 "parse.y"

int main()
{
	yydebug=1;
	//~ printf("started\n");
	if(PDEBUG){
		printf("main()");
	}
	//~ current = (scope*)malloc(sizeof(scope));

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
	//current->symtbl.insert({string("god"), godelement});
	
	init();

	yyparse();
	//~ printf("\n\nPRINTING THE SYMBOL TABLE\n");
	//~ int i;
	//~ for(i=0; i<nsymbols; i++){				//prints the symbol table
	//~ printf("SYMBOL: %s %d\n", symtable[i].name, symtable[i].type);
	//~ }  
	return 0;
}

