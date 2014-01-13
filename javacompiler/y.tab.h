
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

/* Line 1676 of yacc.c  */
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



/* Line 1676 of yacc.c  */
#line 287 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


