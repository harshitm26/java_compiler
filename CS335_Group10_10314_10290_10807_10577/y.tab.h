
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
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



/* Line 1676 of yacc.c  */
#line 295 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


