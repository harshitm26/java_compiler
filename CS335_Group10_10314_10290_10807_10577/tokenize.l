%{

#include <limits.h>
#include "y.tab.h"
#include <math.h>
#include "./tokenize.h"
#include <stdio.h>
#include <stdlib.h>
#define DEBUG 0							//prints all lexical phase information
#define SHOWTOKENS 0
extern "C"								//g++ compiler needs the defination declared[ not required by gcc]
{
	int yylex(void);
}

struct symbol symtable[MAX_SYMBOLS];	//initializing the symbol table
int nsymbols = 0;						//for finding the column number
int line_number =1;						//initializing the line number for error recovery
char buff[128];							//for creating strings for comparison
char* remove_underscores(char* str);	//function to remove underscores from str
void padzeroes(char* str, int n);		//function to pad n zeroes before string str
int count_newlines(char* text);			//to count number of lines in comments [text is comment]
int lookup(char* name);					//returns the index of name in symbol table
int insert(char* s);					//insert s in symbol table and returns the index

/*____________________________________________________________________________________________________*/
%}
		
	/*____________THE NAMES ARE SELF EXPLANATORY_______________________*/
	
		
	/*UNICODEINPUTCHARACTER {UNICODEESCAPE}|{RAWINPUTCHARACTER}
	UNICODEESCAPE \\{UNICODEMARKER}{HEXDIGIT}{4}
	UNICODEMARKER u+
	RAWINPUTCHARACTER |\n
	/*HEXDIGIT [0-9a-fA-F]*/	
LINETERMINATOR \n|\r|\n\r|\r\n

INPUTCHARACTER [^\r\n]

	/*INPUT {INPUTELEMENTS}? | {SUB}?
	SUB <<EOF>>
	INPUTELEMENTS {INPUTELEMENT}+
	INPUTELEMENT {WHITESPACE}|{COMMENT}|{TOKEN}*/
TOKEN {IDENTIFIER}|{KEYWORD}|{LITERAL}|{SEPARATOR}|{OPERATOR}
WHITESPACE [ \t\f]|{LINETERMINATOR}
COMMENT {TRADITIONALCOMMENT}|{ENDOFLINECOMMENT}
TRADITIONALCOMMENT \/\*{COMMENTTAIL}
ENDOFLINECOMMENT \/\/{CHARACTERSINLINE}?
	/*COMMENTTAIL \*{COMMENTTAILSTAR}|{NOTSTAR}{COMMENTTAIL}
		COMMENTTAILSTAR \/|\*{COMMENTTAILSTAR}|{NOTSTARNOTSLASH}{COMMENTTAIL}*/
COMMENTTAIL	{NOTSTAR}*"*"{COMMENTTAILSTAR}
COMMENTTAILSTAR ({NOTSTARNOTSLASH}{NOTSTAR}*"*"|"*")*\/
NOTSTAR [^\*]
NOTSTARNOTSLASH [^\*\/]
CHARACTERSINLINE {INPUTCHARACTER}+

	/*IDENTIFIER {IDENTIFIERCHARS}{-}({KEYWORD}|{BOOLEANLITERAL}|{NULLLITERAL})*/
KEYWORD abstract|assert|boolean|break|byte|case|catch|char|class|const|continue|default|do|double|else|enum|extends|final|finally|float|for|if|goto|implements|import|instanceof|int|interface|long|native|new|package|private|protected|public|return|short|static|strictfp|super|switch|synchronized|this|throw|throws|transient|try|void|volatile|while|printstring|printint|printfloat

IDENT {IDENTIFIERCHARS}
IDENTIFIERCHARS {JAVALETTER}{JAVALETTERORDIGIT}*
JAVALETTER [a-zA-Z_\$]
JAVALETTERORDIGIT {JAVALETTER}|[0-9]

LITERAL {INTEGERLITERAL}|{FLOATINGPOINTLITERAL}|{BOOLEANLITERAL}|{CHARACTERLITERAL}|{STRINGLITERAL}|{NULLLITERAL}|{LONGLITERAL}|{DOUBLELITERAL}|{SHORTLITERAL}

	//long and integer literals have been seperated in defination
LONGLITERAL {DECIMALLONGLITERAL}|{HEXLONGLITERAL}|{OCTALLONGLITERAL}|{BINARYLONGLITERAL}

DECIMALLONGLITERAL {DECIMALNUMERAL}{LONGTYPESUFFIX}
HEXLONGLITERAL {HEXNUMERAL}{LONGTYPESUFFIX}
OCTALLONGLITERAL {OCTALNUMERAL}{LONGTYPESUFFIX}
BINARYLONGLITERAL {BINARYNUMERAL}{LONGTYPESUFFIX}
LONGTYPESUFFIX l|L


INTEGERLITERAL {DECIMALINTEGERLITERAL}|{HEXINTEGERLITERAL}|{OCTALINTEGERLITERAL}|{BINARYINTEGERLITERAL}
DECIMALINTEGERLITERAL {DECIMALNUMERAL}
HEXINTEGERLITERAL {HEXNUMERAL}
OCTALINTEGERLITERAL {OCTALNUMERAL}
BINARYINTEGERLITERAL {BINARYNUMERAL}



DECIMALNUMERAL 0|{NONZERODIGIT}{DIGITS}?|{NONZERODIGIT}{UNDERSCORES}{DIGITS}
DIGITS {DIGIT}|{DIGIT}{DIGITSANDUNDERSCORES}?{DIGIT}
DIGIT 0|{NONZERODIGIT}
NONZERODIGIT [1-9]
DIGITSANDUNDERSCORES {DIGITORUNDERSCORE}+
DIGITORUNDERSCORE {DIGIT}|_
UNDERSCORES _+

HEXNUMERAL 0(x|X){HEXDIGITS}
HEXDIGITS {HEXDIGIT}|{HEXDIGIT}{HEXDIGITSANDUNDERSCORES}?{HEXDIGIT}
HEXDIGIT [0-9a-fA-F]
HEXDIGITSANDUNDERSCORES ({HEXDIGIT}|_)+

OCTALNUMERAL 0{UNDERSCORES}?{OCTALDIGITS}
OCTALDIGITS {OCTALDIGIT}|{OCTALDIGIT}{OCTALDIGITSANDUNDERSCORES}?{OCTALDIGIT}
OCTALDIGIT [0-7]
OCTALDIGITSANDUNDERSCORES ({OCTALDIGIT}|_)+

BINARYNUMERAL 0(b|B){BINARYDIGITS}
BINARYDIGITS {BINARYDIGIT}|{BINARYDIGIT}{BINARYDIGITSANDUNDERSCORES}?{BINARYDIGIT}
BINARYDIGIT 0|1
BINARYDIGITSANDUNDERSCORES ({BINARYDIGIT}|_)+

REALLITERAL {FLOATLITERAL}|{DOUBLELITERAL}


FLOATLITERAL {DECIMALFLOATLITERAL}|{HEXADECIMALFLOATLITERAL}

DECIMALFLOATLITERAL {DIGITS}\.{DIGITS}?{EXPONENTPART}?{FLOATTYPESUFFIX}|\.{DIGITS}{EXPONENTPART}?{FLOATTYPESUFFIX}|{DIGITS}{EXPONENTPART}{FLOATTYPESUFFIX}|{DIGITS}{EXPONENTPART}?{FLOATTYPESUFFIX}
EXPONENTPART {EXPONENTINDICATOR}{SIGNEDINTEGER}
EXPONENTINDICATOR e|E
SIGNEDINTEGER [+-]?{DIGITS}
FLOATTYPESUFFIX f|F

HEXADECIMALFLOATLITERAL {HEXSIGNIFICAND}{BINARYEXPONENT}{FLOATTYPESUFFIX}?
HEXSIGNIFICAND {HEXNUMERAL}\.?|0(x|X){HEXDIGITS}?\.{HEXDIGITS}
BINARYEXPONENT (p|P){SIGNEDINTEGER}

DOUBLELITERAL {DECIMALDOUBLELITERAL}|{HEXADECIMALDOUBLELITERAL}

DECIMALDOUBLELITERAL {DIGITS}\.{DIGITS}?{EXPONENTPART}?{DOUBLETYPESUFFIX}?|\.{DIGITS}{EXPONENTPART}?{DOUBLETYPESUFFIX}?|{DIGITS}{EXPONENTPART}{DOUBLETYPESUFFIX}?|{DIGITS}{EXPONENTPART}?{DOUBLETYPESUFFIX}
		/* EXPONENTPART {EXPONENTINDICATOR}{SIGNEDINTEGER}
		EXPONENTINDICATOR e|E
		SIGNEDINTEGER [+-]?{DIGITS}*/
DOUBLETYPESUFFIX d|D

HEXADECIMALDOUBLELITERAL {HEXADECIMALFLOATLITERAL}{DOUBLETYPESUFFIX}


BOOLEANLITERAL true|false

CHARACTERLITERAL "'"{SINGLECHARACTER}"'"|"'"{ESCAPESEQUENCE}"'"
SINGLECHARACTER [^\n\r"'"\\]


STRINGLITERAL "\""{STRINGCHARACTERS}?"\""
STRINGCHARACTERS {STRINGCHARACTER}+
STRINGCHARACTER [^\r\n"\""\\]|{ESCAPESEQUENCE}

ESCAPESEQUENCE \\b|\\t|\\n|\\f|\\r|\\"\""|\\"'"|\\\\|{OCTALESCAPE}
OCTALESCAPE \\{OCTALDIGIT}|\\{OCTALDIGIT}{2}|\\{ZEROTOTHREE}{OCTALDIGIT}{2}
	/*OCTALDIGIT [0-7]*/
ZEROTOTHREE [0-3]
NULLLITERAL null
SEPARATOR \(|\)|\{|\}|\[|\]|";"|","|\.

ARITHMETIC_OPERATORS "++"|"+"|"-"|"--"|\*|"/"|"%"|"="|"+="|"-="|"*="|"/="|"%="|"&="|"|="|"^="|"<<="|">>="
LOGICAL_OPERATORS "&&"|"||"|"!"
RELATIONAL_OPERATORS "=="|"<="|">="|"!="|">"|"<"
BINARY_OPERATORS "|"|"&"|"^"|">>"|"<<"|">>>"|"~"
TERNARY_QUESTION "?"
TERNARY_COLON ":"
OPERATOR {ARITHMETIC_OPERATORS}|{LOGICAL_OPERATORS}|{BINARY_OPERATORS}|{RELATIONAL_OPERATORS}|{TERNARY_QUESTION}|{TERNARY_COLON}


%%
	/*_______________NOTE: Tokens have been printed as detected________*/
	/*{UNICODEINPUTCHARACTER}		{printf("UNICODECHARACTER %s\n", yytext);}*/
	
{LINETERMINATOR}	{	//whenever encounter a line terminator increase line_number [for error reporting]
						line_number+=1;
						//~ printf("increasing line number\n");
					}
	
{COMMENT}			{	//if comment itself spans many lines then increase line_number accordingly 
						
						line_number+=count_newlines(yytext);
						if(SHOWTOKENS) printf("COMMENT FOUND, <%s>\n", yytext);
					}

{WHITESPACE}		{	if(DEBUG){
							printf("WHITESPACE, ");
							if(!strcmp(yytext, " ")) printf("<space>");
							else if(!strcmp(yytext,"\t")) printf("<tab>"); 
							else if(!strcmp(yytext,"\f")) printf("<formfeed>"); 
							else if(!strcmp(yytext,"\n")) printf("<newline>"); 
							else if(!strcmp(yytext,"\r")) printf("<linefeed>"); 
							else printf("<error>");
							printf("\n");
						}
					}
			
{KEYWORD}			{	//prints the keyword found and returns RESERVED to parser
						if(SHOWTOKENS) printf("<KEYWORD, %s>\n", yytext);
						//~ yylval.index = lookup(yytext);
						if(DEBUG) printf("KEYWORD,<%s>\n", yytext);
						
						if(!strcmp("abstract", yytext)){
							if(SHOWTOKENS) printf("ABSTRACT FOUND\n");
							return ABSTRACT;
						}
						else if(!strcmp("assert", yytext)){
							return ASSERT;
						}
						else if(!strcmp("boolean", yytext)){
							return BOOLEAN;
						}
						else if(!strcmp("break", yytext)){
							return BREAK;
						}
						else if(!strcmp("byte", yytext)){
							return BYTE;
						}
						else if(!strcmp("case", yytext)){
							return CASE;
						}
						else if(!strcmp("catch", yytext)){
							return CATCH;
						}
						else if(!strcmp("char", yytext)){
							return CHAR;
						}
						else if(!strcmp("class", yytext)){
							return CLASS;
						}
						else if(!strcmp("const", yytext)){
							return CONST;
						}
						else if(!strcmp("continue", yytext)){
							return CONTINUE;
						}
						else if(!strcmp("default", yytext)){
							return DEFAULT;
						}
						else if(!strcmp("do", yytext)){
							return _DO;
						}
						else if(!strcmp("double", yytext)){
							return DOUBLE;
						}
						else if(!strcmp("else", yytext)){
							return ELSE;
						}
						else if(!strcmp("enum", yytext)){
							return ENUM;
						}
						else if(!strcmp("extends", yytext)){
							return EXTENDS;
						}
						else if(!strcmp("final", yytext)){
							return FINAL;
						}
						else if(!strcmp("finally", yytext)){
							return FINALLY;
						}
						else if(!strcmp("float", yytext)){
							return FLOAT;
						}
						else if(!strcmp("for", yytext)){
							return _FOR;
						}
						else if(!strcmp("if", yytext)){
							return _IF;
						}
						else if(!strcmp("goto", yytext)){
							return GOTO;
						}
						else if(!strcmp("implements", yytext)){
							return IMPLEMENTS;
						}
						else if(!strcmp("import", yytext)){
							return IMPORT;
						}
						else if(!strcmp("instanceof", yytext)){
							return INSTANCEOF;
						}
						else if(!strcmp("int", yytext)){
							return INT;
						}
						else if(!strcmp("interface", yytext)){
							return INTERFACE;
						}
						else if(!strcmp("long", yytext)){
							return LONG;
						}
						else if(!strcmp("native", yytext)){
							return NATIVE;
						}
						else if(!strcmp("new", yytext)){
							return NEW;
						}
						else if(!strcmp("package", yytext)){
							return PACKAGE;
						}
						else if(!strcmp("private", yytext)){
							return PRIVATE;
						}
						else if(!strcmp("protected", yytext)){
							return PROTECTED;
						}
						else if(!strcmp("public", yytext)){
							return PUBLIC;
						}
						else if(!strcmp("return", yytext)){
							return RETURN;
						}
						else if(!strcmp("short", yytext)){
							return SHORT;
						}
						else if(!strcmp("static", yytext)){
							return STATIC;
						}
						else if(!strcmp("strictfp", yytext)){
							return STRICTFP;
						}
						else if(!strcmp("super", yytext)){
							return SUPER;
						}
						else if(!strcmp("switch", yytext)){
							return SWITCH;
						}
						else if(!strcmp("synchronized", yytext)){
							return SYNCHRONIZED;
						}
						else if(!strcmp("this", yytext)){
							return THIS;
						}
						else if(!strcmp("throw", yytext)){
							return THROW;
						}
						else if(!strcmp("throws", yytext)){
							return THROWS;
						}
						else if(!strcmp("transient", yytext)){
							return TRANSIENT;
						}
						else if(!strcmp("try", yytext)){
							return TRY;
						}
						else if(!strcmp("void", yytext)){
							return VOID;
						}
						else if(!strcmp("volatile", yytext)){
							return VOLATILE;
						}
						else if(!strcmp("while", yytext)){
							return _WHILE;
						}
						else if(!strcmp("printstring", yytext)){
							return PRINTSTRING;
						}
						else if(!strcmp("printint", yytext)){
							return PRINTINT;
						}else if(!strcmp("printfloat", yytext)){
							return PRINTFLOAT;
						}else{
							if(SHOWTOKENS) printf("BIG PROBLEM1\n");
						}
					}
	
{SEPARATOR}			{	//prints the separator found and returns the corresponding separator to parser
						
						if(DEBUG) printf("SEPARATOR,<%s>\n", yytext);
						switch(yytext[0]){
							case('.'): if(SHOWTOKENS) printf("<DOT>\n"); return DOT;
							case(';'): if(SHOWTOKENS) printf("<SEMICOLON>\n"); return SEMICOLON;
							case(','): if(SHOWTOKENS) printf("<COMMA>\n"); return COMMA;
							case('('): if(SHOWTOKENS) printf("<LEFTROUNDBRACE>\n"); return LEFTROUNDBRACE;
							case(')'): if(SHOWTOKENS) printf("<RIGHTROUNDBRACE>\n"); return RIGHTROUNDBRACE;
							case('{'): if(SHOWTOKENS) printf("<LEFTCURLYBRACE>\n"); return LEFTCURLYBRACE;
							case('}'): if(SHOWTOKENS) printf("<RIGHTCURLYBRACE>\n"); return RIGHTCURLYBRACE;
							case('['): if(SHOWTOKENS) printf("<LEFTSQUAREBRACE>\n"); return LEFTSQUAREBRACE;
							case(']'): if(SHOWTOKENS) printf("<RIGHTSQUAREBRACE>\n"); return RIGHTSQUAREBRACE;
							default: ; break;
						}
					}
	
{DECIMALDOUBLELITERAL}	{	//prints the DECIMALDOUBLELITERAL and returns DECIMALDOUBLELITERAL to parser
							if(DEBUG) printf("DECIMALDOUBLELITERAL, <%s>\n", yytext);
							//remove underscores and store yytext in ptr
							char* ptr = remove_underscores(yytext);
							//convert the literal to type double using strtod and reports error: [+-]HUGE_VAL if value too large (positive or negative) and throws error if out of range
							double temp = strtod(ptr, NULL);	
							if(temp != HUGE_VAL && temp != -HUGE_VAL && temp!=0.0){
								yylval.dval = temp;
								if(SHOWTOKENS) printf("<DECIMALDOUBLELITERAL, %lf>\n", yylval.dval); 
								return DOUBLELITERAL;
							}
							else printf("LINE #%d: VALUE TOO LARGE FOR DOUBLE\n", line_number);
						}
{HEXADECIMALDOUBLELITERAL}	{//prints the HEXADECIMALDOUBLELITERAL and returns HEXADECIMALDOUBLELITERAL to parser
							if(DEBUG) printf("HEXADECIMALDOUBLELITERAL, <%s>\n", yytext);
							//removes underscores and store yytext in ptr
							char* ptr = remove_underscores(yytext);
							//convert the literal to type double using strtod and reports error: [+-]HUGE_VAL if value too large (positive or negative) and throws error if out of range
							double temp = strtod(ptr, NULL);
							if(temp != HUGE_VAL && temp != -HUGE_VAL && temp!=0.0){
								yylval.dval = temp;
								if(SHOWTOKENS) printf("<HEXADECIMALDOUBLELITERAL, %xlf>\n", yylval.dval); 
								return DOUBLELITERAL;
							}
							else printf("LINE #%d: VALUE TOO LARGE FOR DOUBLE\n", line_number);
						}
{DECIMALFLOATLITERAL}	{//prints the DECIMALFLOATLITERAL and returns DECIMALFLOATLITERAL to parser
							if(DEBUG) printf("DECIMALFLOATLITERAL, <%s>\n", yytext);
							//removes underscores and store yytext in ptr
							char* ptr = remove_underscores(yytext);
							//convert the literal to type double using strtof and reports error: [+-]HUGE_VAL if value too large (positive or negative) and throws error if out of range
							float temp = strtof(ptr, NULL);
							if(temp != HUGE_VAL && temp != -HUGE_VAL && temp!=0.0){
								yylval.fval = temp;
								if(SHOWTOKENS) printf("<DECIMALFLOATLITERAL, %f>\n", yylval.fval); 
								return FLOATLITERAL;
							}
							else printf("LINE #%d: VALUE TOO LARGE FOR FLOAT\n", line_number);
						}
{HEXADECIMALFLOATLITERAL}	{// prints the HEXADECIMALFLOATLITERAL and returns HEXADECIMALFLOATLITERAL to parser
							if(DEBUG) printf("HEXADECIMALFLOATLITERAL, <%s>\n", yytext);
							//removes underscores and store yytext in ptr
							char* ptr = remove_underscores(yytext);
							//convert the literal to type double using strtof and reports error: [+-]HUGE_VAL if value too large (positive or negative) and throws error if out of range
							float temp = strtof(ptr, NULL);
							if(temp != HUGE_VAL && temp != -HUGE_VAL && temp!=0.0){
								yylval.fval = temp;
								if(SHOWTOKENS) printf("<HEXADECIMALFLOATLITERAL, %xf>\n", yylval.fval); 
								return FLOATLITERAL;
							}
							else printf("LINE #%d: VALUE TOO LARGE FOR FLOAT\n", line_number);
						}
-9_*2_*2_*3_*3_*7_*2_*0_*3_*6_*8_*5_*4_*7_*7_*5_*8_*0_*8l	{
							//seperately detect the smallest negative number as this is not detected as DECIMALLONGLITERAL in rule below; and retuns DECIMALLONGLITERAL to parser
							yylval.lval = 1<<63;
							if(SHOWTOKENS) printf("<DECIMALLONGLITERAL, %ld>\n", yylval.lval); 
							if(DEBUG) printf("DECIMALLONGLITERAL,<%s>\n", yytext);
							return LONGLITERAL;
						}

{DECIMALLONGLITERAL}	{	//prints the DECIMALLONGLITERAL and returns DECIMALLONGLITERAL to parser	
							if(DEBUG) printf("DECIMALLONGLITERAL,<%s>\n", yytext);
							//removes underscores and store yytext in ptr
							char* ptr = remove_underscores(yytext);
							//write the longest DECIMALLONGLITERAL to array buff [for comparsion]
							sprintf(buff, "%ld", LONG_MAX);
							int diff=strlen(buff)-strlen(ptr);
							//pads the smaller of LONG_MAX and ptr with appropriate number of zeroes before the smaller string to make both the strings of equal length so they can be compared easily using strcmp
							if(diff>0) padzeroes(ptr,diff);
							else padzeroes(buff,-diff);
							if(strcmp(buff, ptr)<0){	//compares the litreal for range checking and throws error if out of range
							if(SHOWTOKENS) 	printf("LINE #%d: VALUE TOO LARGE FOR LONG\n", line_number);
							}
							//converts the literal using strtol and gives the value to parser
							yylval.lval=strtol(ptr, NULL, 10);
							if(SHOWTOKENS) printf("<DECIMALLONGLITERAL, %ld>\n", yylval.lval); 
							return LONGLITERAL;							
						}		
[+-]?0x8_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0l	{
							//seperately detect the smallest negative OR largest postive hexadecimal long  number as this is not detected as HEXLONGLITERAL in rule below; and retuns HEXLONGLITERAL to parser
							yylval.lval = 1<<63;
							if(SHOWTOKENS) printf("<DECIMALLONGLITERAL, %xld>\n", yylval.lval); 
							if(DEBUG) printf("HEXLONGLITERAL,<%s>\n", yytext);
							return LONGLITERAL;
						}
{HEXLONGLITERAL}		{	//prints the HEXLONGLITERAL and returns HEXLONGLITERAL to parser	
							if(DEBUG) printf("HEXLONGLITERAL,<%s>\n", yytext);
							//remove underscores from literal
							char* ptr = remove_underscores(yytext);
							//increment pointer to adjuct for '0x'
							ptr+= 2 ;
							//write the longest HEXLONGLITERAL to array buff [for comparsion]
							sprintf(buff, "%lx", LONG_MAX);
							//pads the smaller of LONG_MAX and ptr with appropriate number of zeroes before the smaller string to make both the strings of equal length so they can be compared easily using strcmp
							int diff=strlen(buff)-strlen(ptr);
							if(diff>0) padzeroes(ptr,diff);
							else padzeroes(buff,-diff);
							if(strcmp(buff, ptr)<0){  //compares the litreal for range checking and throws error if out of range
							if(SHOWTOKENS) 	printf("LINE #%d: VALUE TOO LARGE FOR LONG\n", line_number);
							}
							//converts the literal using strtol and gives the value to parser		
							long temp = strtol(ptr, NULL, 16);
							yylval.lval=temp;
							if(SHOWTOKENS) printf("<HEXLONGLITERAL, %xld>\n", yylval.lval); 
							return LONGLITERAL;
						}	
[+-]?01_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0	{
								//seperately detect the smallest negative OR larges postive octal long  number as this is not detected as OCTALLONGLITERAL in rule below; and retuns OCTALLONGLITERAL to parser
								yylval.lval = 1<<63;
								if(SHOWTOKENS) printf("<OCTALLONGLITERAL, %old>\n", yylval.lval); 
								if(DEBUG) printf("OCTALLONGLITERAL,<%s>\n", yytext);
								return LONGLITERAL;
							}
{OCTALLONGLITERAL}		{	//prints the OCTALLONGLITERAL and returns OCTALLONGLITERAL to parser
							if(DEBUG) printf("OCTALLONGLITERAL,<%s>\n", yytext);
							//remove underscores from literal
							char* ptr = remove_underscores(yytext);
							//increment pointer to adjuct for '0'
							ptr++ ;
							//write the longest OCTALLONGLITERAL to array buff [for comparsion]
							sprintf(buff, "%lo", LONG_MAX);
							//pads the smaller of LONG_MAX and ptr with appropriate number of zeroes before the smaller string to make both the strings of equal length so they can be compared easily using strcmp
							int diff=strlen(buff)-strlen(ptr);
							if(diff>0) padzeroes(ptr,diff);
							else padzeroes(buff,-diff);
							if(strcmp(buff, ptr)<0){//compares the litreal for range checking and throws error if out of range
								if(SHOWTOKENS) printf("LINE #%d: VALUE TOO LARGE FOR LONG\n", line_number);
							}
							//converts the literal using strtol and gives the value to parser	
							long temp = strtol(ptr, NULL, 8);
							yylval.lval=temp;
							if(SHOWTOKENS) printf("<OCTALLONGLITERAL, %ld>\n", yylval.lval); 
							return LONGLITERAL;
						}	
[+-]?1_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0	{
							//seperately detect the smallest negative OR largest postive binary long  number as this is not detected as BINARYLONGLITERAL in rule below; and retuns BINARYLONGLITERAL to parser
							yylval.lval = 1<<63;
							if(SHOWTOKENS) printf("<BINARYLONGLITERAL, %ld>\n", yylval.lval); 
							if(DEBUG) printf("BINARYLONGLITERAL,<%s>\n", yytext);
							return LONGLITERAL;
						}
{BINARYLONGLITERAL}		{	//prints the BINARYLONGLITERAL and returns BINARYLONGLITERAL to parser
							if(DEBUG) printf("BINARYLONGLITERAL,<%s>\n", yytext);
							//remove underscores from literal
							char* ptr = remove_underscores(yytext);
							//increment pointer to adjuct for '0b'
							ptr+=2 ;
							//keep incrementing the pointer position till all zeroes at the beginning of literal are escaped
							while(*ptr=='0') ptr++;
							//check the length of binary literal for out of range check and throw error if out of range
							if(strlen(ptr)>64){
								printf("LINE #%d: VALUE TOO LARGE FOR LONG\n", line_number);
							}
							//converts the literal using strtol and gives the value to parser	
							long temp = strtol(ptr, NULL, 2);
							yylval.lval=temp;
							if(SHOWTOKENS) printf("<BINARYLONGLITERAL, %ld>\n", yylval.lval); 
							return LONGLITERAL;
						}	

-2_*1_*4_*7_*4_*8_*3_*6_*4_*8				{
							//seperately detect the smallest negative OR larges postive decimal integer  number as this is not detected as DECIMALINTEGERLITERAL in rule below; and retuns DECIMALINTEGERLITERAL to parser
							yylval.ival = 1<<31;
							if(SHOWTOKENS) printf("<DECIMALINTEGERLITERAL, %d>\n", yylval.ival); 
							if(DEBUG) printf("DECIMALINTEGERLITERAL,<%s>\n", yytext);
							return INTEGERLITERAL;
						}
{DECIMALINTEGERLITERAL}	{	//prints the DECIMALINTEGERLITERAL and returns DECIMALINTEGERLITERAL to parser
							if(DEBUG) printf("DECIMALINTEGERLITERAL,<%s>\n", yytext);
							//remove underscores from literal
							char* ptr = remove_underscores(yytext);
							//write the longes DECIMALINTEGERLITERAL to array buff [for comparsion]
							sprintf(buff, "%d", INT_MAX);
							//pads the smaller of INT_MAX and ptr with appropriate number of zeroes before the smaller string to make both the strings of equal length so they can be compared easily using strcmp
							int diff=strlen(buff)-strlen(ptr);
							if(diff>0) padzeroes(ptr,diff);
							else padzeroes(buff,-diff);
							if(strcmp(buff, ptr)<0){//compares the litreal for range checking and throw error if out of range
								printf("LINE #%d: VALUE TOO LARGE FOR INT\n", line_number);
							}
							//converts the literal using atoi and gives the value to parser
							yylval.ival=atoi(ptr);
							if(SHOWTOKENS) printf("<DECIMALINTEGERLITERAL, %d>\n", yylval.ival); 
							return INTEGERLITERAL;
						}
[+-]?0x8_*0_*0_*0_*0_*0_*0_*0			{
							//seperately detect the smallest negative OR larges postive hexadecimal integer  number as this is not detected as HEXINTEGERLITERAL in rule below; and retuns HEXINTEGERLITERAL to parser
							yylval.ival = 1<<31;
							if(SHOWTOKENS) printf("<HEXINTEGERLITERAL, %x>\n", yylval.ival); 
							if(DEBUG) printf("HEXINTEGERLITERAL,<%s>\n", yytext);
							return INTEGERLITERAL;
						}
{HEXINTEGERLITERAL}		{	//prints the HEXINTEGERLITERAL and returns HEXINTEGERLITERAL to parser
							if(DEBUG) printf("HEXINTEGERLITERAL,<%s>\n", yytext);
							//remove underscores from literal
							char* ptr = remove_underscores(yytext);
							//increment pointer to adjust for '0x'
							ptr+= 2 ;
							//write the longes HEXINTEGERLITERAL to array buff [for comparsion]
							sprintf(buff, "%x", INT_MAX);
							int diff=strlen(buff)-strlen(ptr);
							//pads the smaller of INT_MAX and ptr with appropriate number of zeroes before the smaller string to make both the strings of equal length so they can be compared easily using strcmp
							if(diff>0) padzeroes(ptr,diff);
							else padzeroes(buff,-diff);
							if(strcmp(buff, ptr)<0){//compares the litreal for range checking and throw error if out of range
								if(SHOWTOKENS) printf("LINE #%d: VALUE TOO LARGE FOR INT\n", line_number);
							}
							long temp = strtol(ptr, NULL, 16);
							//converts the literal using strtol and gives the value to parser
							yylval.ival=(int)temp;
							if(SHOWTOKENS) printf("<HEXINTEGERLITERAL, %x>\n", yylval.ival); 
							return INTEGERLITERAL;
						}		

[+-]?02_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0		{
							//seperately detect the smallest negative OR larges postive octal integer number as this is not detected as OCTALINTEGERLITERAL in rule below; and retuns OCTALINTEGERLITERAL to parser
							yylval.ival = 1<<31;
							if(SHOWTOKENS) printf("<OCTALINTEGERLITERAL, %o>\n", yylval.ival); 
							if(DEBUG) printf("OCTALINTEGERLITERAL,<%s>\n", yytext);
							return INTEGERLITERAL;
						}
{OCTALINTEGERLITERAL}	{	//prints the OCTALINTEGERLITERAL and returns OCTALINTEGERLITERAL to parser
							if(DEBUG) printf("OCTALINTEGERLITERAL,<%s>\n", yytext);
							//remove underscores from literal
							char* ptr = remove_underscores(yytext);
							//increment pointer to adjust for '0'
							ptr++ ;
							//write the longes OCTALINTEGERLITERAL to array buff [for comparsion]
							sprintf(buff, "%o", INT_MAX);
							//pads the smaller of INT_MAX and ptr with appropriate number of zeroes before the smaller string to make both the strings of equal length so they can be compared easily using strcmp
							int diff=strlen(buff)-strlen(ptr);
							if(diff>0) padzeroes(ptr,diff);
							else padzeroes(buff,-diff);
							if(strcmp(buff, ptr)<0){//compares the litreal for range checking and throw error if out of range
								if(SHOWTOKENS) printf("LINE #%d: VALUE TOO LARGE FOR INT\n", line_number);
							}
							long temp = strtol(ptr, NULL, 8);
							//converts the literal using strtol and gives the value to parser
							yylval.ival=(int)temp;
							if(SHOWTOKENS) printf("<OCTALINTEGERLITERAL, %o>\n", yylval.ival); 
							return INTEGERLITERAL;
						}			
	
[+-]?1_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0_*0	{
							//seperately detect the smallest negative OR larges postive binry integer number as this is not detected as BINARYINTEGERLITERAL in rule below; and retuns BINARYINTEGERLITERAL to parser
							yylval.ival = 1<<31;
							if(SHOWTOKENS) printf("<BINARYINTEGERLITERAL, %d>\n", yylval.ival); 
							if(DEBUG) printf("BINARYINTEGERLITERAL,<%s>\n", yytext);
							return INTEGERLITERAL;
						}
{BINARYINTEGERLITERAL}	{	//prints the OCTALINTEGERLITERAL and returns OCTALINTEGERLITERAL to parser
							if(DEBUG) printf("BINARYINTEGERLITERAL,<%s>\n", yytext);
							//remove underscores from literal
							char* ptr = remove_underscores(yytext);
							//increment pointer to adjust for '0b'
							ptr+=2 ;
							//increase pointer position till all zeroes in beginning are escaped
							while(*ptr=='0') ptr++;
							//range checking of binaryintegerliteral by checking length of string and throw error if out of range
							if(strlen(ptr)>32){
								if(SHOWTOKENS) printf("LINE #%d: VALUE TOO LARGE FOR INT\n", line_number);
							}
							long temp = strtol(ptr, NULL, 2);
							yylval.ival=(int)temp;
							if(SHOWTOKENS) printf("<BINARYINTEGERLITERAL, %d>\n", yylval.ival); 
							return INTEGERLITERAL;
						}	
{OPERATOR}			{	//prints the OPERATOR and returns the corresponding OPERATOR to parser
						if(DEBUG) printf("OPERATOR,<%s>\n", yytext);
						if(!strcmp("++", yytext)){
							if(SHOWTOKENS) printf("<PLUSPLUS>\n"); 
							return PLUSPLUS;
						}else if(!strcmp("+", yytext)){
							if(SHOWTOKENS) printf("<PLUS>\n"); 
							return PLUS;
						}else if(!strcmp("-", yytext)){
							if(SHOWTOKENS) printf("<MINUS>\n"); 
							return MINUS;
						}else if(!strcmp("--", yytext)){
							if(SHOWTOKENS) printf("<MINUSMINUS>\n"); 
							return MINUSMINUS;
						}else if(!strcmp("*", yytext)){
							if(SHOWTOKENS) printf("<ASTERISK>\n"); 
							return ASTERISK;
						}else if(!strcmp("/", yytext)){
							if(SHOWTOKENS) printf("<DIVIDE>\n"); 
							return DIVIDE;
						}else if(!strcmp("%", yytext)){
							if(SHOWTOKENS) printf("<PERCENT>\n"); 
							return PERCENT;
						}else if(!strcmp("=", yytext)){
							if(SHOWTOKENS) printf("<EQUALS>\n"); 
							return EQUALS;
						}else if(!strcmp("+=", yytext)){
							if(SHOWTOKENS) printf("<PLUSEQUALS>\n"); 
							return PLUSEQUALS;
						}else if(!strcmp("-=", yytext)){
							if(SHOWTOKENS) printf("<MINUSEQUALS>\n"); 
							return MINUSEQUALS;
						}else if(!strcmp("*=", yytext)){
							if(SHOWTOKENS) printf("<ASTERISKEQUALS>\n"); 
							return ASTERISKEQUALS;
						}else if(!strcmp("/=", yytext)){
							if(SHOWTOKENS) printf("<DIVIDEEQUALS>\n"); 
							return DIVIDEEQUALS;
						}else if(!strcmp("%=", yytext)){
							if(SHOWTOKENS) printf("<PERCENTEQUALS>\n"); 
							return PERCENTEQUALS;
						}else if(!strcmp("&=", yytext)){
							if(SHOWTOKENS) printf("<ANDEQUALS>\n"); 
							return ANDEQUALS;
						}else if(!strcmp("|=", yytext)){
							if(SHOWTOKENS) printf("<OREQUALS>\n"); 
							return OREQUALS;
						}else if(!strcmp("^=", yytext)){
							if(SHOWTOKENS) printf("<CARETEQUALS>\n"); 
							return CARETEQUALS;
						}else if(!strcmp("<<=", yytext)){
							if(SHOWTOKENS) printf("<LEFTSHIFTEQUALS>\n"); 
							return LEFTSHIFTEQUALS;
						}else if(!strcmp(">>=", yytext)){
							if(SHOWTOKENS) printf("<RIGHTSHIFTEQUALS>\n"); 
							return RIGHTSHIFTEQUALS;
						}else if(!strcmp("&&", yytext)){
							if(SHOWTOKENS) printf("<ANDAND>\n"); 
							return ANDAND;
						}else if(!strcmp("||", yytext)){
							if(SHOWTOKENS) printf("<OROR>\n"); 
							return OROR;
						}else if(!strcmp("!", yytext)){
							if(SHOWTOKENS) printf("<NOT>\n"); 
							return NOT;
						}else if(!strcmp("==", yytext)){
							if(SHOWTOKENS) printf("<EQUALSEQUALS>\n"); 
							return EQUALSEQUALS;
						}else if(!strcmp("<=", yytext)){
							if(SHOWTOKENS) printf("<LESSEQUALS>\n"); 
							return LESSEQUALS;
						}else if(!strcmp(">=", yytext)){
							if(SHOWTOKENS) printf("<GREATEQUALS>\n"); 
							return GREATEQUALS;
						}else if(!strcmp("!=", yytext)){
							if(SHOWTOKENS) printf("<NOTEQUALS>\n"); 
							return NOTEQUALS;
						}else if(!strcmp(">", yytext)){
							if(SHOWTOKENS) printf("<GREATER>\n"); 
							return GREATER;
						}else if(!strcmp("<", yytext)){
							if(SHOWTOKENS) printf("<LESS>\n"); 
							return LESS;
						}else if(!strcmp("|", yytext)){
							if(SHOWTOKENS) printf("<OR>\n"); 
							return OR;
						}else if(!strcmp("&", yytext)){
							if(SHOWTOKENS) printf("<AND>\n"); 
							return AND;
						}else if(!strcmp("^", yytext)){
							if(SHOWTOKENS) printf("<CARET>\n"); 
							return CARET;
						}else if(!strcmp(">>", yytext)){
							if(SHOWTOKENS) printf("<RIGHTSHIFT>\n"); 
							return RIGHTSHIFT;
						}else if(!strcmp("<<", yytext)){
							if(SHOWTOKENS) printf("<LEFTSHIFT>\n"); 
							return LEFTSHIFT;
						}else if(!strcmp(">>>", yytext)){
							if(SHOWTOKENS) printf("<UNRIGHTSHIFT>\n"); 
							return UNRIGHTSHIFT;
						}else if(!strcmp(">>>=", yytext)){
							if(SHOWTOKENS) printf("<UNRIGHTSHIFTEQUALS>\n"); 
							return UNRIGHTSHIFT;
						}else if(!strcmp("~", yytext)){
							if(SHOWTOKENS) printf("<TILDE>\n"); 
							return TILDE;
						}else if(!strcmp("?", yytext)){
							if(SHOWTOKENS) printf("<QUESTION>\n"); 
							return QUESTION;
						}else if(!strcmp(":", yytext)){
							if(SHOWTOKENS) printf("<COLON>\n"); 
							return COLON;
						}
						
					}
{BOOLEANLITERAL}	{	//prints and returns the corresponding boolean literal
						if(!strcmp(yytext, "true")){
							if(SHOWTOKENS) printf("<BTRUE>\n");
							return BTRUE;
						}
						else{
							if(SHOWTOKENS) printf("<BFALSE>\n");
							return BFALSE;
						}
					}
{CHARACTERLITERAL}	{	//prints and returns the correspondding characterliteral
						if(!strcmp("\\b", yytext)){
							yylval.cval = '\b';
						}else if(!strcmp("\\t", yytext)){
							yylval.cval = '\t';
						}else if(!strcmp("\\n", yytext)){
							yylval.cval = '\n';
						}else if(!strcmp("\\f", yytext)){
							yylval.cval = '\f';
						}else if(!strcmp("\\r", yytext)){
							yylval.cval = '\r';
						}else if(!strcmp("\\\"", yytext)){
							yylval.cval = '\"';
						}else if(!strcmp("\\'", yytext)){
							yylval.cval = '\'';
						}else if(!strcmp("\\\\", yytext)){
							yylval.cval = '\\';
						}else{
							char code = (char)strtol(yytext+1, NULL, 8);
							yylval.cval = code;
						}
						if(SHOWTOKENS) printf("<CHARACTERLITERAL, %c>\n", yylval.cval);
						return CHARACTERLITERAL;
					}
{NULLLITERAL}		{	//prints and returns the NULLLITERAL
						if(SHOWTOKENS) printf("<NULLLITERAL>\n");
						return NULLLITERAL;
					}	
{STRINGLITERAL}		{	//prints and returns the STRINGLITERAL to parser. The corresponding value of STRINGLITERAL is also stored
						yylval.sval = strdup(yytext);
						if(SHOWTOKENS) printf("<STRINGLITERAL, %s>\n", yytext);
						return STRINGLITERAL;
					}
{IDENT}		{	//prints and returns the corresponding IDENTIFIER to parser
						yylval.sval = strdup(yytext);
						if(SHOWTOKENS) printf("<IDENTIFIER, %s>\n", yytext);
						return IDENT;
					}
@					{	
						if(SHOWTOKENS) printf("<ATTHERATE>\n");
						return ATTHERATE;
					}

%%
#ifndef yywrap
int yywrap(){return 1;}							/* No need to open another file */
#endif

//lookup searches the symbol table for string name and returns the index. If string is not found in symboltable then -1 is returned. 
int lookup(char * name){	
	int i;
	for(i=0; i<nsymbols; i++){
		if(!strcmp(symtable[i].name, yytext)) return i;
	}
	return -1;
}

//insert inserts the string s into symbol talbe and returns the index. 
int insert(char* s){
	int ind = nsymbols;
	symtable[ind].name = strdup(s);
	nsymbols++;
	return ind;
}

//remove_underscores removes underscores from string str and returns the pointer to the new string thus formed. 
char* remove_underscores(char* str){
	//printf("removing underscores\n");
	int j=0;
	while(*str!='\0'){
		if(*str!='_') buff[j++]=*str;
		str++;
	}
	buff[j]='\0';
	return strdup(buff);
	//printf("removed underscores: %s\n", str);	
}
	
	
//padzeroes adds n number of zeroes before the string str
void padzeroes(char* str, int n){
	if(n==0) return;
	char* s = (char*)malloc(sizeof(char)*(strlen(str)+1+n));
	int i;
	for(i=0; i<n; i++){
		s[i]='0';
	}
	strcpy(s+i, str);
	strcpy(str,s);
}

//count_newlines counts and retunrs the number of times '\n' is found in string text.
int count_newlines(char* text){
	int s=0;
	while(*text!='\0'){
		if(*text=='\n'){
			s++;
			//printf("increasing line number\n");
		}
		text ++;
	}
	return s;
}

//called in the beginning; init adds all the keywords into symbol table by default 
int init(){

	return 0;
}
