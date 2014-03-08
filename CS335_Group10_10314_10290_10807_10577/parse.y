%debug
%{	
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
	
%}
%union{		//union declared to store the return value of tokens
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
}
//tokentypes for different tokens
%token <ival> INTEGERLITERAL
%token <lval> LONGLITERAL
%token <fval> FLOATLITERAL
%token <dval> DOUBLELITERAL

%token <sval> IDENT
%token <sval> STRINGLITERAL
%token <cval> CHARACTERLITERAL
%token PLUSPLUS PLUS MINUS MINUSMINUS ASTERISK DIVIDE PERCENT EQUALS PLUSEQUALS MINUSEQUALS ASTERISKEQUALS DIVIDEEQUALS PERCENTEQUALS ANDEQUALS OREQUALS CARETEQUALS LEFTSHIFTEQUALS RIGHTSHIFTEQUALS ANDAND OROR NOT EQUALSEQUALS LESSEQUALS GREATEQUALS NOTEQUALS GREATER LESS OR AND CARET RIGHTSHIFT LEFTSHIFT UNRIGHTSHIFT UNRIGHTSHIFTEQUALS TILDE QUESTION COLON
%token DOT SEMICOLON COMMA LEFTROUNDBRACE RIGHTROUNDBRACE LEFTCURLYBRACE RIGHTCURLYBRACE LEFTSQUAREBRACE RIGHTSQUAREBRACE 
%token BTRUE BFALSE NULLLITERAL PRINTINT PRINTSTRING PRINTFLOAT
%token ABSTRACT ASSERT BOOLEAN BREAK BYTE CASE CATCH CHAR CLASS CONST CONTINUE DEFAULT _DO DOUBLE ELSE ENUM EXTENDS FINAL FINALLY FLOAT _FOR _IF GOTO IMPLEMENTS IMPORT INSTANCEOF INT INTERFACE LONG NATIVE NEW PACKAGE PRIVATE PROTECTED PUBLIC RETURN SHORT STATIC STRICTFP SUPER SWITCH SYNCHRONIZED THIS THROW THROWS TRANSIENT TRY VOID VOLATILE _WHILE
%token ATTHERATE
%start Goal
%left PLUS MINUS
%left ASTERISK DIVIDE

%type <status> Goal
%type <attr> Literal
%type <attr> Type
%type <attr> PrimitiveType
%type <attr> NumericType
%type <attr> IntegralType
%type <attr> FloatingPointType
%type <attr> ReferenceType
%type <attr> ClassOrInterfaceType
%type <attr> ClassType
%type <attr> InterfaceType
%type <attr> ArrayType
%type <name> Name
%type <name> SimpleName
%type <name> QualifiedName

%type <status> CompilationUnit
//~ %type <status> ImportDeclarations
%type <status> TypeDeclarations
//~ %type <status> PackageDeclaration
//~ %type <status> ImportDeclaration
//~ %type <status> SingleTypeImportDeclaration
//~ %type <status> TypeImportOnDemandDeclaration
%type <status> TypeDeclaration
%type <ival> Modifiers
%type <ival> Modifier
%type <status> ClassDeclaration
%type <attr> Super
//~ %type <attr> Interfaces//Not implemented
//~ %type <attr> InterfaceTypeList//Not implemented
%type <status> ClassBody
%type <status> ClassBodyDeclarations
%type <status> ClassBodyDeclaration
%type <status> ClassMemberDeclaration
%type <status> FieldDeclaration
%type <dlist> VariableDeclarators
%type <dlist> VariableDeclarator
%type <attr> VariableDeclaratorId
%type <attr> VariableInitializer
%type <status> MethodDeclaration
%type <attr> MethodHeader
%type <attr> MethodDeclarator
%type <elist> FormalParameterList
%type <attr> FormalParameter
//~ %type <attr> Throws//Not implemented
//~ %type <attr> ClassTypeList//Not implemented
%type <status> MethodBody
//~ %type <attr> StaticInitializer//Not implemented
%type <status> ConstructorDeclaration
%type <attr> ConstructorDeclarator
%type <status> ConstructorBody
%type <status> ExplicitConstructorInvocation
//~ %type <attr> InterfaceDeclaration//Not implemented
//~ %type <attr> ExtendsInterfaces//Not implemented
//~ %type <attr> InterfaceBody//Not implemented
//~ %type <attr> InterfaceMemberDeclarations//Not implemented
//~ %type <attr> InterfaceMemberDeclaration//Not implemented
//~ %type <attr> ConstantDeclaration//Not implemented
//~ %type <attr> AbstractMethodDeclaration//Not implemented
%type <attr> ArrayInitializer
%type <elist> VariableInitializers
%type <status> Block
%type <status> BlockStatements
%type <status> BlockStatement
%type <status> LocalVariableDeclarationStatement
%type <status> LocalVariableDeclaration
%type <status> Statement

%type <status> StatementWithoutTrailingSubstatement
%type <status> EmptyStatement
%type <status> LabeledStatement

%type <status> ExpressionStatement
%type <attr> StatementExpression

%type <status> IfThenElseStatement

%type <status> SwitchStatement
%type <attr> SwitchBlock
%type <attr> SwitchBlockStatementGroups
%type <attr> SwitchBlockStatementGroup
%type <attr> SwitchLabels
%type <attr> SwitchLabel
%type <status> WhileStatement

%type <status> DoStatement
%type <splb> IF
%type <splb> FOR
%type <splb> DO
%type <splb> WHILE
%type <status> ForStatement

%type <status> ForInit
%type <status> ForUpdate
%type <attr> StatementExpressionList
%type <status> BreakStatement
%type <status> ContinueStatement
%type <status> ReturnStatement
//~ %type <status> ThrowStatement//Not implemented
//~ %type <status> SynchronizedStatement//Not implemented
//~ %type <status> TryStatement//Not implemented
//~ %type <attr> Catches//Not implemented
//~ %type <attr> CatchClause//Not implemented
//~ %type <attr> Finally//Not implemented
%type <attr> Primary
%type <attr> PrimaryNoNewArray
%type <attr> ClassInstanceCreationExpression
%type <elist> ArgumentList
%type <attr> ArrayCreationExpression
%type <pspvec> DimExprs
%type <ival> DimExpr
%type <pspvec> Dims
%type <attr> FieldAccess
%type <attr> MethodInvocation
%type <attr> ArrayAccess
%type <attr> PostfixExpression
%type <attr> PostIncrementExpression
%type <attr> PostDecrementExpression
%type <attr> UnaryExpression
%type <attr> PreIncrementExpression
%type <attr> PreDecrementExpression
%type <attr> UnaryExpressionNotPlusMinus
%type <attr> CastExpression
%type <attr> MultiplicativeExpression
%type <attr> AdditiveExpression
%type <attr> ShiftExpression
%type <attr> RelationalExpression
%type <attr> EqualityExpression
%type <attr> AndExpression
%type <attr> ExclusiveOrExpression
%type <attr> InclusiveOrExpression
%type <attr> ConditionalAndExpression
%type <attr> ConditionalOrExpression
%type <attr> ConditionalExpression
%type <attr> AssignmentExpression
%type <attr> Assignment
%type <attr> LeftHandSide
//%type <ival> AssignmentOperator
%type <attr> Expression
%type <attr> ConstantExpression
%type <sval> Identifier

%%
Goal:
	CompilationUnit		
		{	$$ = $1;
			printf("COMPILATION OVER: %d errors found\n", error_count);
			printf("\n\n");
			print();
			fclose(fp);
		}
;

Identifier:
	IDENT
		{
			$$ = strdup(yylval.sval);
		}
;
Literal:
	INTEGERLITERAL		
						{
							fprintf(fp, "subu $sp, $sp, 4 #INTEGERLITERAL\n");
							currentelement()->loc+=4;
							if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
							
							
							fprintf(fp, "li $t0, %d\n", $1);
							fprintf(fp, "sw $t0, 0($sp)\n");
							
							$$ = makePrimNode(string(), KLITERAL, TINT, vector<int>(), currentelement()->loc, ANONE, NULL);
							
						}
|	FLOATLITERAL
						{
							fprintf(fp, "subu $sp, $sp, 4 #FLOATLITERAL\n");
							currentelement()->loc+=4;
							if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
							fprintf(fp, "li.s $f0, %f\n", $1);
							fprintf(fp, "s.s $f0, ($sp)\n");
							
							$$ = makePrimNode(string(), KLITERAL, TFLOAT, vector<int>(), currentelement()->loc, ANONE, NULL);
							
						}
|	LONGLITERAL
						{
							printf("error at line %d: Long type not supported\n", line_number);
							ehere();
							int hi = (int)($1 >> 32);
							int lo = (int)($1 & ((1<<32) -1));
							fprintf(fp, "subu $sp, $sp, 8 #LONGLITERAL\n");
							currentelement()->loc+=8;
							if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
							fprintf(fp, "li $t0, %d\n", hi);
							fprintf(fp, "sw $t0, 0($sp)\n");
							fprintf(fp, "li $t0, %d\n", lo);
							fprintf(fp, "sw $t0, 4($sp)\n");
							
							$$ = makePrimNode(string(), KLITERAL, TLONG, vector<int>(), currentelement()->loc, ANONE, NULL);
							
						}
|	DOUBLELITERAL
						{
							printf("error at line %d: Double type not supported\n", line_number);
							ehere();
							fprintf(fp, "subu $sp, $sp, 8 #DOUBLELITERAL\n");
							currentelement()->loc+=8;
							if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
							fprintf(fp, "li.d $f0, %lf\n", $1);
							fprintf(fp, "sdc1 $f0, 0($sp)\n");
													
							$$ = makePrimNode(string(), KLITERAL, TDOUBLE, vector<int>(), currentelement()->loc, ANONE, NULL);
							
						}
|	BTRUE
						{
							
							fprintf(fp, "subu $sp, $sp, 4 #BTRUE\n");
							currentelement()->loc+=4;
							if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
							fprintf(fp, "li $t0, 1\n");
							fprintf(fp, "sw $t0, 0($sp)\n");
							
							$$ = makePrimNode(string(), KLITERAL, TBOOLEAN, vector<int>(), currentelement()->loc, ANONE, NULL);
							
						}
|	BFALSE
						{
							fprintf(fp, "subu $sp, $sp, 4 #BFALSE\n");
							currentelement()->loc+=4;
							if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
							fprintf(fp, "li $t0, 0\n");
							fprintf(fp, "sw $t0, 0($sp)\n");
							
							$$ = makePrimNode(string(), KLITERAL, TBOOLEAN, vector<int>(), currentelement()->loc, ANONE, NULL);
							
						}
|	CHARACTERLITERAL
						{
							fprintf(fp, "subu $sp, $sp, 4 #CHARACTERLITERAL\n");
							currentelement()->loc+=4;
							if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
							fprintf(fp, "li $t0, %d\n", $1);
							fprintf(fp, "sw $t0, 0($sp)\n");
							
							$$ = makePrimNode(string(), KLITERAL, TCHAR, vector<int>(), currentelement()->loc, ANONE, NULL);
							
						}
|	STRINGLITERAL
						{
							fprintf(fp, "\t.data #STRINGLITERAL\n");
							char* lab = newlabel();
							fprintf(fp, "%s:", lab);
							fprintf(fp, "\t.asciiz %s\n", $1);
							fprintf(fp, "\t.text\n");
							fprintf(fp, "subu $sp, $sp, 4\n");
							currentelement()->loc+=4;
							if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
							fprintf(fp, "la $t0, %s\n", lab);
							fprintf(fp, "sw $t0, 0($sp)\n");
							
							$$ = makePrimNode(string(), KLITERAL, TSTRING, vector<int>(), currentelement()->loc, ANONE, NULL);
							
						}
|	NULLLITERAL
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
;

Type:
	PrimitiveType
						{
							$$ = $1;
						}
|	ReferenceType
						{
							$$ = $1;
						}
;

PrimitiveType:
	NumericType			{
							$$ = $1;
						}
|	BOOLEAN				
						{
							$$ = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
						}
|	VOID				{
							$$ = makePrimNode(string(), KPRIMITIVE, TVOID, vector<int>(), NULL, ANONE, NULL);
						}
;

NumericType:
	IntegralType
						{
							$$ = $1;
						}
|	FloatingPointType
						{
							$$ = $1;
						}
;

IntegralType:
	BYTE				
						{
							$$ = makePrimNode(string(), KPRIMITIVE, TBYTE, vector<int>(), NULL, ANONE, NULL);
						}
|	SHORT
						{	
							$$ = makePrimNode(string(), KPRIMITIVE, TSHORT, vector<int>(), NULL, ANONE, NULL);
						}
|	INT
						{	
							$$ = makePrimNode(string(), KPRIMITIVE, TINT, vector<int>(), NULL, ANONE, NULL);
						}
|	LONG
						{	
							$$ = makePrimNode(string(), KPRIMITIVE, TLONG, vector<int>(), NULL, ANONE, NULL);
						}
|	CHAR
						{	
							$$ = makePrimNode(string(), KPRIMITIVE, TCHAR, vector<int>(), NULL, ANONE, NULL);
						}
;

FloatingPointType:
	FLOAT
						{	
							$$ = makePrimNode(string(), KPRIMITIVE, TFLOAT, vector<int>(), NULL, ANONE, NULL);
						}
|	DOUBLE
						{	
							$$ = makePrimNode(string(), KPRIMITIVE, TDOUBLE, vector<int>(), NULL, ANONE, NULL);
						}
;

ReferenceType:
	ClassOrInterfaceType
						{
							$$ = $1;
						}
|	ArrayType			{
							$$= $1;
						}
;

ClassOrInterfaceType:
	Name				
						{
							$$ = findtype(current, $1, KCLASS);
						}
;

ClassType:
	ClassOrInterfaceType
						{
							$$ = $1;
						}
;

InterfaceType:
	ClassOrInterfaceType
						{
							//Not implemented
						}
;

ArrayType:
	PrimitiveType LEFTSQUAREBRACE RIGHTSQUAREBRACE
						{
							$1->dimensions.push_back(0);
							$$ = $1;
						}
|	Name LEFTSQUAREBRACE RIGHTSQUAREBRACE
						{
							element* qualifiedtype = findtype(current, $1);
							struct element* newnode = makeRefNode(string(), KCLASS, qualifiedtype, vector<int>(), NULL, ANONE, NULL, NULL, NULL);
							newnode->dimensions.push_back(0);
							$$ = newnode;
						}							
|	ArrayType LEFTSQUAREBRACE RIGHTSQUAREBRACE
						{
							$1->dimensions.push_back(0);
							$$ = $1;
						}
;

Name:
	SimpleName			
						{
							$$= $1;
						}
|	QualifiedName
						{
							$$= $1;
						}
;

SimpleName:
	Identifier
						{
							struct namenode * newnode = new namenode();
							newnode->name = string($1);
							newnode->next = NULL;
							$$ = newnode;
						}
;
QualifiedName:
	Name DOT Identifier
						{
							namenode* iterator = $1;
							while(iterator->next != NULL) iterator = iterator->next;
							struct namenode * newnode = new namenode();
							newnode->name = string($3);
							newnode->next = NULL;
							iterator->next = newnode;
							$$ = $1;
						}
;

CompilationUnit:
	PackageDeclaration ImportDeclarations TypeDeclarations	{	/*Not Implemented*/	}
|	PackageDeclaration ImportDeclarations					{	/*Not Implemented*/	}
|	PackageDeclaration 					  TypeDeclarations	{	/*Not Implemented*/	}
|	PackageDeclaration										{	/*Not Implemented*/	}
|					   ImportDeclarations TypeDeclarations	{	/*Not Implemented*/	}
|					   ImportDeclarations					{	/*Not Implemented*/	}
|										  TypeDeclarations	{	$$ = $1;	}
|															{	$$ = OKAY;	}
;

ImportDeclarations:		/*Not Implemented*/
	ImportDeclaration										
|	ImportDeclarations ImportDeclaration					

;

TypeDeclarations:
	TypeDeclaration
						{
							$$ = $1;
						}
|	TypeDeclarations TypeDeclaration
						{
							if($1==ERROR || $2==ERROR){
								here(2);
								$$ = ERROR;
								here(1);
							}
							else $$ = OKAY;
						}
;

PackageDeclaration:		/*Not Implemented*/
	PACKAGE Name SEMICOLON
;

ImportDeclaration:		/*Not Implemented*/
	SingleTypeImportDeclaration
|	TypeImportOnDemandDeclaration
;

SingleTypeImportDeclaration:			/*Not Implemented*/
	IMPORT Name SEMICOLON
;

TypeImportOnDemandDeclaration:					/*Not Implemented*/
	IMPORT Name DOT ASTERISK SEMICOLON
;

TypeDeclaration:
	ClassDeclaration
					{
						$$ = $1;
					}
|	InterfaceDeclaration	{	/*Not Implemented*/	}
|	SEMICOLON	
					{
						$$ = OKAY;
					}
;

Modifiers:
	Modifier
					{
						$$ = $1;
					}
|	Modifiers Modifier	{	/*	Not implemented	*/	}
;

Modifier:
	PUBLIC			{	$$ = yylval.ival;	}
|	PROTECTED		{	$$ = yylval.ival;	}
|	PRIVATE			{	$$ = yylval.ival;	}
|	STATIC			{	/* Not implemented	*/ 	}
|	ABSTRACT			{	/* Not implemented	*/ 	}
|	FINAL			{	/* Not implemented	*/ 	}
|	NATIVE			{	/* Not implemented	*/ 	}
|	SYNCHRONIZED			{	/* Not implemented	*/ 	}
|	TRANSIENT			{	/* Not implemented	*/ 	}
|	VOLATILE			{	/* Not implemented	*/ 	}
;
//19.7 till here

//	19.8.1
ClassDeclaration:
				 CLASS Identifier 	
	{

		if(alreadypresent($2)){
			printf("error at line #%d: %s already declared\n", line_number, $2);
			current->symtbl.erase(string($2));
			ehere(0);
		}	
		element* newelem = makeRefNode(string($2), KCLASS, NULL, vector<int>(), 0, APUBLIC, NULL, NULL, NULL);
		current->symtbl.insert({string($2), newelem});
		scope* newscope = createScope(string($2), current, newelem);
		newelem->desc = newscope;
		current = newscope;
	}
		   				 ClassBody	
	{
		revertscope();
		$$ = $4;
	}
|	CLASS Identifier Super	
	{
		if(alreadypresent($2)){
			printf("error at line #%d: %s already declared\n", line_number, $2);
			current->symtbl.erase(string($2));
			ehere(0);
		}	
										
		element* newelem = makeRefNode(string($2), KCLASS, NULL, vector<int>(), $3->loc, APUBLIC, NULL, $3, NULL);
		current->symtbl.insert({string($2), newelem});
		scope* newscope = createScope(string($2), current, newelem);
		newelem->desc = newscope;
		current = newscope;
		}
	ClassBody
		{
			//printsymtbl(current->symtbl);
			revertscope();
			
			$$ = $5;
		}										

|				 CLASS Identifier  		   Interfaces	 ClassBody	{	/* Not implemented	*/ 	}
|				 CLASS Identifier Super    Interfaces    ClassBody	{	/* Not implemented	*/ 	}
|	Modifiers    CLASS Identifier
	{
		accessmod mod;
		if($1==PUBLIC){
			mod = APUBLIC;
		}else if($1==PROTECTED){
			mod = APROTECTED;
		}else if($1==PRIVATE){
			mod = APRIVATE;
		}
		if(alreadypresent($3)){
			printf("error at line #%d: %s already declared\n", line_number, $3);
			current->symtbl.erase(string($3));
			ehere(0);
		}	
				
		element* newelem = makeRefNode(string($3), KCLASS, NULL, vector<int>(), 0, mod, NULL, NULL, NULL);
		current->symtbl.insert({string($3), newelem});
		scope* newscope = createScope(string($3), current, newelem);
		newelem->desc = newscope;
		current = newscope;
	}
					ClassBody	
	{
		revertscope();
		$$ = $5;
	}
|	Modifiers    CLASS Identifier Super
	{
		accessmod mod;
		if($1==PUBLIC){
			mod = APUBLIC;
		}else if($1==PROTECTED){
			mod = APROTECTED;
		}else if($1==PRIVATE){
			mod = APRIVATE;
		}
		if(alreadypresent($3)){
			printf("error at line #%d: %s already declared\n", line_number, $3);
			current->symtbl.erase(string($3));
			ehere(0);
		}
		element* newelem = makeRefNode(string($3), KCLASS, NULL, vector<int>(), $4->loc, mod, NULL, $4, NULL);
		current->symtbl.insert({string($3), newelem});
		scope* newscope = createScope(string($3), current, newelem);
		newelem->desc = newscope;
		current = newscope;
	}
 		   				 ClassBody
	{
		revertscope();
		$$ = $6;
	}
|	Modifiers    CLASS Identifier 		   Interfaces	 ClassBody	{	/* Not implemented	*/ 	}
|	Modifiers    CLASS Identifier Super	   Interfaces	 ClassBody	{	/* Not implemented	*/ 	}
;

Super:
	EXTENDS ClassType	{
							$$ = $2;
						}
;

Interfaces:				//Not Implemented
	IMPLEMENTS InterfaceTypeList
;

InterfaceTypeList:		//Not Implemented
	InterfaceType
|	InterfaceTypeList COMMA InterfaceType
;

ClassBody:
	LEFTCURLYBRACE RIGHTCURLYBRACE
		{
			$$ = OKAY;
		}
|	LEFTCURLYBRACE ClassBodyDeclarations RIGHTCURLYBRACE
		{
			$$ = $2;
		}
;

ClassBodyDeclarations:
	ClassBodyDeclaration
		{
			$$ = $1;
		}
|	ClassBodyDeclarations ClassBodyDeclaration
		{
			if($1==ERROR || $2 == ERROR){
				$$ = ERROR;
				here(2);
			}
			else $$= OKAY;
		}
;

ClassBodyDeclaration:
	ClassMemberDeclaration
		{
			$$ = $1;
		}
|	StaticInitializer	{$$ = OKAY;}	//Not implemented
|	ConstructorDeclaration
		{
			$$ = $1;
		}
;

ClassMemberDeclaration:
	FieldDeclaration	{$$ = $1;}
|	MethodDeclaration	{$$ = $1;}
|	ClassDeclaration
		{
			printf("error at line %d: nested classes not implemented\n", line_number);
			ehere();
			$$ = $1;
		}
;

// 19.8.2
FieldDeclaration:
			Type VariableDeclarators SEMICOLON
		{	
			bool ret = coercedlist( $2, $1);
			listofdeclarators* e = $2;
			while(e!=NULL){
				e->elem->kind = KVARIABLE;
				e->elem->mod = ANONE;
				
				currentelement()->loc += sizeofelement(e->elem);
				e->elem->loc = currentelement()->loc;
				fprintf(stderr, "FieldDeclaration %s loc=%d\n", e->elem->name.c_str(), currentelement()->loc);
				current->symtbl.insert({string(e->elem->name), e->elem});
				e=e->next;
			}
			$$ = ret;
		}
			
|	Modifiers Type VariableDeclarators SEMICOLON
		{
			accessmod mod;
			if($1==PUBLIC){
				mod = APUBLIC;
			}else if($1==PROTECTED){
				mod = APROTECTED;
			}else if($1==PRIVATE){
				mod = APRIVATE;
			}
			$2->mod = mod;
			bool ret = coercedlist( $3, $2);
			listofdeclarators* e = $3;
			while(e!=NULL){
				e->elem->kind = KVARIABLE;
				e->elem->mod = mod;
				currentelement()->loc += sizeofelement(e->elem);
				e->elem->loc = currentelement()->loc;
				fprintf(stderr, "FieldDeclaration %s loc=%d\n", e->elem->name.c_str(), currentelement()->loc);
				current->symtbl.insert({string(e->elem->name), e->elem});
				e=e->next;
			}
			$$ = ret;
		}
;

VariableDeclarators:
	VariableDeclarator
		{
			$$ = $1;
		}
|	VariableDeclarators COMMA VariableDeclarator
		{
			listofdeclarators* list = $1;
			while(list->next!=NULL) list = list->next;
			list->next = $3;
			$$ = $1;
		}
			
;

VariableDeclarator:
	VariableDeclaratorId
		{
			listofdeclarators* newlist= new listofdeclarators();
			newlist->elem = $1;
			newlist->equals = NULL;
			newlist->next = NULL;
			$$ = newlist;

		}
|	VariableDeclaratorId EQUALS VariableInitializer
		{
			if(!iscoercible($1, $3)){
				printf("error at line %d: incompatible types: \n",line_number);
				listofdeclarators* newlist= new listofdeclarators();
				newlist->elem = makeIllegalNode();
				newlist->equals = $3;
				newlist->next = NULL;
				$$ = newlist;
			}else{
				coerce($1, $3);
				listofdeclarators* newlist= new listofdeclarators();
				newlist->elem = $1;
				newlist->equals = $3;
				newlist->next = NULL;
				$$ = newlist;
				
			}
		}
;

VariableDeclaratorId:
	Identifier
		{
			element* newelem = makePrimNode(string($1), KUNKNOWN, TUNKNOWN, vector<int>(), NULL, ANONE, NULL);
			if(alreadypresent($1)){
				printf("error at line #%d: %s already declared\n", line_number, $1);
				current->symtbl.erase(string($1));
				current->symtbl.insert({string(newelem->name), newelem});
				ehere(0);
			}
			//current->symtbl.insert({string($1), newelem});
			$$ = newelem;
		}
|	VariableDeclaratorId LEFTSQUAREBRACE RIGHTSQUAREBRACE
		{
			$1 -> dimensions.push_back(0);
			$$ = $1;
		}
;

VariableInitializer:
	Expression
		{
			$$ = $1;
		}
|	ArrayInitializer
		{
			printf("error at line %d: Array initializers not implemented\n", line_number);
			$$ = $1;
		}
;


ArrayInitializer:
	LEFTCURLYBRACE VariableInitializers RIGHTCURLYBRACE
		{
			element* e = copyelement($2->elem);
			int i = 0;
			listofelements* it = $2;
			while(it!=NULL){
				it = it->next;
				i++;
			}
			e->dimensions.insert(e->dimensions.begin(), i);
			e->arguments = $2;
			$$ = e;
		}
|	LEFTCURLYBRACE 						COMMA RIGHTCURLYBRACE
		{
			$$ = NULL;
		}
|	LEFTCURLYBRACE							  RIGHTCURLYBRACE
		{
			$$ = NULL;
		}
;

VariableInitializers:
	VariableInitializer
		{
			listofelements* newlist = new listofelements();
			newlist ->elem = $1;
			newlist->next=NULL;
			$$ = newlist;
		}
|	VariableInitializers COMMA VariableInitializer
		{
			//if(equal($1->dimensions.begin() +1, $1->dimensions.end(), $3->dimensions.begin()))
			if(iscoercible($1->elem, $3) || iscoercible($3, $1->elem))
			{
				listofelements* e = $1;
				while(e->next!=NULL) e = e->next;
				listofelements* newelem = new listofelements();
				e->next=newelem;
				newelem ->elem = $3;
				newelem->next=NULL;
				$$ = $1;
			}else{
				printf("error at line #%d: incompatible types\n", line_number);
				listofelements* newlist = new listofelements();
				newlist ->elem = makeIllegalNode();
				newlist->next=NULL;
				$$ = newlist;
			}
		}
;





//19.8.3

MethodDeclaration:
	MethodHeader
	MethodBody
		{
			//if(strcmp("main", $1->name.c_str())==0){
				fprintf(fp, "jr $ra\n");
			//}
			revertscope();
			if($1 == NULL || $2 == ERROR){
				$$ = ERROR;
				here(3);
			}
			else $$ = OKAY;
		}
;

MethodHeader:
				 Type MethodDeclarator
		{
			if($1->kind==KPRIMITIVE){
				$2->kind = KPRIMFUNCTION;
				$2->pdtype = $1->pdtype;
				$2->mod = APRIVATE;
				$$ = $2;
			}else if($1->kind==KCLASS){
				$2->kind = KREFFUNCTION;
				$2->rdtype = $1->rdtype;
				$2->mod = APRIVATE;
				$$ = $2;
			}else{
				printf("line #%d: fatal error\n", line_number);
				$$ = makeIllegalNode();
			}	
		}
|	Modifiers	 Type MethodDeclarator 
		{
			accessmod mod;
			if($1==PUBLIC){
				mod = APUBLIC;
			}else if($1==PROTECTED){
				mod = APROTECTED;
			}else if($1==PRIVATE){
				mod = APRIVATE;
			}
			if($2->kind==KPRIMITIVE){
				$3->kind = KPRIMFUNCTION;
				$3->pdtype = $2->pdtype;
				$3->mod = mod;
				$$ = $3;
			}else if($2->kind==KCLASS){
				$3->kind = KREFFUNCTION;
				$3->rdtype = $2->rdtype;
				$3->mod = mod;
				$$ = $3;
			}else{
				printf("line #%d: fatal error\n", line_number);
				$$ = makeIllegalNode();
			}
		}		
//~ |				 Type MethodDeclarator Throws
//~ |	Modifiers	 Type MethodDeclarator Throws
//~ |				 VOID MethodDeclarator 
//~ |	Modifiers	 VOID MethodDeclarator 
//~ |				 VOID MethodDeclarator Throws
//~ |	Modifiers	 VOID MethodDeclarator Throws
;

MethodDeclarator:
	Identifier LEFTROUNDBRACE
		{	
			
			if(strcmp($1, "main")==0){
				fprintf(fp, "main:\n");
				fprintf(fp, "move $fp, $sp\n");
				fprintf(fp, "subu $sp, $fp, 4\n");
			}
			fprintf(fp, "%s%s:\n", current->elem->name.c_str(), $1);
			element* func = makePrimNode(string($1), KPRIMFUNCTION, TUNKNOWN, vector<int>(), 4, APUBLIC, NULL);
			
			scope* newscope = createScope(string($1), current, func);
			func->desc = newscope;
			if(alreadypresent($1)){
				printf("error at line #%d: method %s already declared\n", line_number, $1);
				current->symtbl.erase(string($1));
				ehere(0);
			}	
				
			if(PDEBUG) printf("%d inserting method %s in %s's table\n", line_number, $1, current->lexeme.c_str());
			current->symtbl.insert({string($1), func});	
			current = newscope;	
		}
	 					  RIGHTROUNDBRACE
		{
			$$ = currentelement();
		}
|	Identifier LEFTROUNDBRACE 
		{	
			if(strcmp($1, "main")==0){
				fprintf(fp, "main:\n");
				fprintf(fp, "move $fp, $sp\n");
				fprintf(fp, "subu $sp, $fp, 4\n");
			}
			fprintf(fp, "%s%s:\n", current->elem->name.c_str(), $1);
			
			element* func = makePrimNode(string($1), KPRIMFUNCTION, TUNKNOWN, vector<int>(), 4, APUBLIC, NULL);
			
			scope* newscope = createScope(string($1), current, func);
			func->desc = newscope;
			if(alreadypresent($1)){
				printf("error at line #%d: method %s already declared\n", line_number, $1);
				current->symtbl.erase(string($1));
				ehere(0);
			}	
				
			if(PDEBUG) printf("%d inserting method %s in %s's table\n", line_number, $1, current->lexeme.c_str());
			current->symtbl.insert({string($1), func});	
			current = newscope;
		}	
	FormalParameterList RIGHTROUNDBRACE
		{
			listofelements* param = $4;
			while(param!=NULL){
				currentelement()->loc += sizeofelement(param->elem);
				param->elem->loc = currentelement()->loc;
				current->symtbl.insert({string(param->elem->name), param->elem});
				if(PDEBUG) printf("%d inserting %s in %s's argumentlist\n", line_number, param->elem->name.c_str(), current->lexeme.c_str());
				param= param->next;
			}
			currentelement()->arguments = $4;
			$$ = currentelement();
		}
|	MethodDeclarator LEFTSQUAREBRACE RIGHTSQUAREBRACE	//Not implemented
;

FormalParameterList:
	FormalParameter
		{
			listofelements* param = new listofelements();
			param->elem = $1;
			param->next = NULL;
			$$ = param;
		}
|	FormalParameterList COMMA FormalParameter
		{
			listofelements* param = new listofelements();
			param->elem = $3;
			param->next = NULL;
			listofelements* list = $1; 
			while(list->next != NULL) list = list->next;
			list->next = param;
			$$ = $1;
		}
;

FormalParameter:
	Type VariableDeclaratorId
		{
			if($1->kind==KPRIMITIVE){
				$2->kind = KVARIABLE;
				$2->pdtype = $1->pdtype;
				$$ = $2;
			}else if($1->kind==KCLASS){
				$2->kind = KOBJECT;
				$2->rdtype = $1->rdtype;
				$$ = $2;
			}else{
				printf("line #%d: fatal error\n", line_number);
				$$ = makeIllegalNode();
			}	
		}
;

Throws://Not implemented
	THROWS ClassTypeList
;

ClassTypeList://Not needed
	ClassType
|	ClassTypeList COMMA ClassType
;

MethodBody:
	Block
		{
			$$ = $1;
		}
|	SEMICOLON
		{
			$$ = OKAY;
		}
;

StaticInitializer://Not implemented
	STATIC Block
;

ConstructorDeclaration:
		      ConstructorDeclarator
		{
			fprintf(fp, "%s%s:\n", currentelement()->name.c_str(), currentelement()->name.c_str());
		}
		      ConstructorBody
		{
			revertscope();
			fprintf(fp, "jr $ra\n #%s%s constructor end\n", currentelement()->name.c_str(), currentelement()->name.c_str());
			if($1 == NULL || $3 == ERROR){
				$$ = ERROR;
				here(4);
			}
			else $$ = OKAY;
		}		
|	Modifiers ConstructorDeclarator
		{
			if($1==PUBLIC){
				$2->mod = APUBLIC;
			}else if($1==PROTECTED){
				$2->mod = APROTECTED;
			}else if($1==PRIVATE){
				$2->mod = APRIVATE;
			}
			fprintf(fp, "%s%s:\n", currentelement()->name.c_str(), currentelement()->name.c_str());
		}
			ConstructorBody
		{
			revertscope();
			fprintf(fp, "jr $ra\n #%s%s constructor end\n", currentelement()->name.c_str(), currentelement()->name.c_str());
			if($2 == NULL || $4==ERROR){
				$$ = ERROR;
				here(5);
			}else $$ = OKAY;
		}
|			  ConstructorDeclarator Throws ConstructorBody	{$$ = OKAY;}//Not implemented
|	Modifiers ConstructorDeclarator Throws ConstructorBody	{$$ = OKAY;}//Not implemented
;

ConstructorDeclarator:
	SimpleName LEFTROUNDBRACE
		{	
			scope* s = current;
			while(s!=NULL && s->elem->kind!= KCLASS) s= s->parent;
			if(s==NULL){
				printf("error at line #%d: constructor must be declared inside a class\n");
				ehere(998);
				here(999);
			}else if($1->name != s->lexeme){
				printf("error at line #%d: constructor name doesn't match class name\n");
				ehere(996);
				here(997);
			}
			element* func = makePrimNode($1->name, KCONSTRUCTOR, TUNKNOWN, vector<int>(), 4, APUBLIC, NULL);
			
			scope* newscope = createScope(string($1->name), current, func);
			func->desc = newscope;
			if(alreadypresent($1->name)){
				printf("error at line #%d: method %s already declared\n", line_number, $1->name.c_str());
				current->symtbl.erase(string($1->name));
				ehere(0);
			}	
				
			if(PDEBUG) printf("%d inserting method %s in %s's table\n", line_number, $1->name.c_str(), current->lexeme.c_str());
			current->symtbl.insert({string($1->name), func});	
			current = newscope;	
			element* _this = makeRefNode(string("this"), KOBJECT, current->parent->elem, vector<int>(), 4, ANONE, NULL, NULL, NULL);
			_this->amode = REFERENCE;
			current->symtbl.insert({string(_this->name), _this});	
		}			
	RIGHTROUNDBRACE
		{
			$$ = currentelement();
		}
|	SimpleName LEFTROUNDBRACE 
		{	
			scope* s = current;
			while(s!=NULL && s->elem->kind!= KCLASS) s= s->parent;
			if(s==NULL){
				printf("error at line #%d: constructor must be declared inside a class\n");
				ehere(998);
				here(999);
			}else if($1->name != s->lexeme){
				printf("error at line #%d: constructor name doesn't match class name\n");
				ehere(996);
				here(997);
			}			
			element* func = makePrimNode(string($1->name), KCONSTRUCTOR, TUNKNOWN, vector<int>(), 4, APUBLIC, NULL);
			
			scope* newscope = createScope(string($1->name), current, func);
			func->desc = newscope;
			if(alreadypresent($1->name)){
				printf("error at line #%d: method %s already declared\n", line_number, $1->name.c_str());
				current->symtbl.erase(string($1->name));
				ehere(0);
			}	
				
			if(PDEBUG) printf("%d inserting method %s in %s's table\n", line_number, $1->name.c_str(), current->lexeme.c_str());
			current->symtbl.insert({string($1->name), func});	
			current = newscope;
			element* _this = makeRefNode(string("this"), KOBJECT, current->parent->elem, vector<int>(), 4, ANONE, NULL, NULL, NULL);
			_this->amode = REFERENCE;
			current->symtbl.insert({string(_this->name), _this});	
		}		
	FormalParameterList RIGHTROUNDBRACE
		{
			listofelements* param = $4;
			while(param!=NULL){
				currentelement()->loc += sizeofelement(param->elem);
				param->elem->loc = currentelement()->loc;
				current->symtbl.insert({string(param->elem->name), param->elem});
				if(PDEBUG) printf("%d inserting %s in %s's argumentlist\n", line_number, param->elem->name.c_str(), current->lexeme.c_str());
				param= param->next;
			}
			currentelement()->arguments = $4;
			$$ = currentelement();
		}
;

ConstructorBody:
	LEFTCURLYBRACE RIGHTCURLYBRACE
		{
			$$ = OKAY;
		}
|	LEFTCURLYBRACE 
	ExplicitConstructorInvocation RIGHTCURLYBRACE
		{
			if($2 == OKAY){
				$$ = OKAY;
			}else $$ = ERROR;
			here(6);
		}
|	LEFTCURLYBRACE
	BlockStatements RIGHTCURLYBRACE
		{
			if($2 == OKAY){
				$$ = OKAY;
			}else $$ = ERROR;
			here(7);
		}
			
|	LEFTCURLYBRACE 
	ExplicitConstructorInvocation BlockStatements RIGHTCURLYBRACE
		{
			if($2 == OKAY && $3==OKAY){
				$$ = OKAY;
			}else $$ = ERROR;
			here(8);
		}
;

ExplicitConstructorInvocation:
	THIS LEFTROUNDBRACE RIGHTROUNDBRACE SEMICOLON
		{
			$$ = OKAY;
		}
|	THIS LEFTROUNDBRACE ArgumentList 
	RIGHTROUNDBRACE SEMICOLON
		{
			symmap::iterator it = current->symtbl.find(current->lexeme);
			
			if(it == current->symtbl.end()){
				printf("error at line #%d:constructor doesn't exist\n", line_number);
				$$ = ERROR;
				ehere(9);
			}else{
				listofelements* arglist = it->second->arguments;
				if(iscoerciblelisttolist($3, arglist)){
					$$ = OKAY;
				}else{
					printf("error at line #%d: wrong parameters passed\n", line_number);
					$$ = ERROR;
					ehere(10);
				}
			}

		}
	
|	SUPER LEFTROUNDBRACE RIGHTROUNDBRACE SEMICOLON
		{
			$$ = OKAY;
		}
|	SUPER LEFTROUNDBRACE ArgumentList RIGHTROUNDBRACE SEMICOLON
		{
			
			element* supelem = currentelement()->superclass;
			listofelements* arglist = NULL;
			symmap::iterator it = supelem->desc->symtbl.find(supelem->name);
			
			if(it == supelem->desc->symtbl.end()){
				printf("constructor not found #%d:\n", line_number);
				$$ = ERROR;
				ehere(11);
			}else{
				arglist = it->second->arguments;
				if(iscoerciblelisttolist($3,arglist)){
					$$ = OKAY;
				}else{
					printf("error at line #%d: wrong parameters passed\n", line_number);
					$$ = ERROR;
					ehere(12);
				}
			}

		}
;

//19.9

InterfaceDeclaration://Not implemented
			  INTERFACE Identifier 					 InterfaceBody
|	Modifiers INTERFACE Identifier 					 InterfaceBody
|			  INTERFACE Identifier ExtendsInterfaces InterfaceBody
|	Modifiers INTERFACE Identifier ExtendsInterfaces InterfaceBody
;

ExtendsInterfaces://Not implemented
	EXTENDS InterfaceType
|	ExtendsInterfaces COMMA InterfaceType
;

InterfaceBody://Not implemented
	LEFTCURLYBRACE RIGHTCURLYBRACE
|	LEFTCURLYBRACE InterfaceMemberDeclarations RIGHTCURLYBRACE
;
InterfaceMemberDeclarations://Not implemented
	InterfaceMemberDeclaration
|	InterfaceMemberDeclarations InterfaceMemberDeclaration
;

InterfaceMemberDeclaration://Not implemented
	ConstantDeclaration
|	AbstractMethodDeclaration
;

ConstantDeclaration://Not implemented
	FieldDeclaration
;

AbstractMethodDeclaration://Not implemented
	MethodHeader SEMICOLON
;

//19.9 ends here

Block:
	LEFTCURLYBRACE BlockStatements RIGHTCURLYBRACE
		{
			$$ = $2;
		}
|	LEFTCURLYBRACE 				   RIGHTCURLYBRACE
		{
			$$ = OKAY;
		}
;

BlockStatements:
	BlockStatement
		{
			$$ = $1;
		}
|	BlockStatements BlockStatement
		{
			if($1 == ERROR || $2 == ERROR){
				$$ = ERROR;
				here(13);
			}else{
				$$ = OKAY;
			}
		}
|	error SEMICOLON { edisp("Block Statement error\n"); }		
;

BlockStatement:
	LocalVariableDeclarationStatement
		{
			$$ = $1;
		}
|	Statement
		{
			$$ = $1;
		}
;

LocalVariableDeclarationStatement:
	LocalVariableDeclaration SEMICOLON
		{
			$$ = $1;
		}
;

LocalVariableDeclaration:
	Type VariableDeclarators
		{
			
			if(!iscoercibledlist($2, $1)){
				printf("error at line# %d: incompatible types\n", line_number);
				ehere(14);
				$$ = ERROR;
				
			}else{
				bool ret = coercedlist($2, $1);
				if($1->rdtype == NULL) here(1448);
				listofdeclarators* e = $2;
				
				while(e!=NULL){
					here(1403);
					if(e->elem == NULL) here(1453);
					if($1->kind==KCLASS) e->elem->kind =KOBJECT;
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
				
				$$ = ret;
			}
		}

;

Statement:
	StatementWithoutTrailingSubstatement	{$$ = $1;}
|	LabeledStatement	{$$ = $1;}
|	IfThenElseStatement	{$$ = $1;}
|		WhileStatement	{$$ =$1;}
|		ForStatement	{$$ =$1;}
;



StatementWithoutTrailingSubstatement:
	Block
		{
			$$ = $1;
		}
|	EmptyStatement	{$$ = $1;}
|	ExpressionStatement	{$$ = $1;}
|	SwitchStatement	{$$ =$1;}
|	DoStatement	{$$ =$1;}
|	BreakStatement	{$$ = $1;}
|	ContinueStatement	{$$ = $1;}
|	ReturnStatement	{$$ = $1;}
|	SynchronizedStatement	{$$ = OKAY;}
|	ThrowStatement	{$$ = OKAY;}
|	TryStatement	{$$ = OKAY;}
;

EmptyStatement:
	SEMICOLON	{$$ = OKAY;}
;

LabeledStatement:
	Identifier COLON Statement	{$$ = $3;}
;


ExpressionStatement:
	StatementExpression SEMICOLON
		{
			if($1 == NULL) here(1480);
			if($1->kind != KILLEGAL){
				
				$$ = OKAY;
			}else{
				printf("line #%d: illegal expression statement\n", line_number);
				$$ = ERROR;
				ehere(15);
			}
		}
;

StatementExpression:
	Assignment
		{
			$$ = $1;
		}	
|	PreIncrementExpression
		{
			$$ = $1;
		}	
|	PreDecrementExpression
		{
			$$ = $1;
		}	
|	PostIncrementExpression
		{
			$$ = $1;
		}	
|	PostDecrementExpression
		{
			$$ = $1;
		}	
|	MethodInvocation
		{
			$$ = $1;
		}	
|	ClassInstanceCreationExpression
		{
			$$ = $1;
		}	
;

IfThenElseStatement:
	IF LEFTROUNDBRACE Expression RIGHTROUNDBRACE
		{
			$1->label = string(newlabel());
			fprintf(fp, "subu $sp, $sp, 8  #IF-THEN-ELSE start\n", $3->loc);
			currentelement()->loc +=8;
			if(PDEBUG){
				fprintf(fp, "# loc = %d\n", currentelement()->loc);
			}
			fprintf(fp, "sw $s7, ($sp)\n", $3->loc);
			fprintf(fp, "sw $sp, 4($sp)\n", $3->loc);
			fprintf(fp, "move $s7, $sp\n", $3->loc);
			
			fprintf(fp, "lw $t0, -%d($fp)\n", $3->loc);
			fprintf(fp, "li $t1, 1\n", $3->loc);
			fprintf(fp, "bne $t0, $t1, %sfalse\n", $1->label.c_str());
			
			$1->sp1 = currentelement()->loc;
		}
	Statement ELSE
		{
			$1->sp2 = currentelement()->loc;
			currentelement()->loc = $1->sp1;
			fprintf(fp, "j %snext\n", $1->label.c_str());
			fprintf(fp, "%sfalse:\n", $1->label.c_str());
		}
	Statement
		{
			$1->sp3 = currentelement()->loc;
			int a = $1->sp2;
			int b = $1->sp3;
			int max = a>b?a:b;
			currentelement()->loc = max;
			fprintf(fp, "%snext: #IF-THEN-ELSE end a=%d b=%d\n", $1->label.c_str(), a, b);
			fprintf(fp, "lw $t0, 4($s7)\n");
			fprintf(fp, "subu $sp, $t0, %d\n", max - $1->sp1);
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "lw $t0, ($s7)\n");
			fprintf(fp, "move $s7, $t0\n");
			
			
			if($3->pdtype!=TBOOLEAN){
				printf("line #%d: expression must be boolean\n", line_number);
				$$ = ERROR;
				ehere(18);
			}else if($6==ERROR || $9 ==ERROR){
				$$ = ERROR;
				here(19);
			}else{
				$$ = OKAY;
			}
		}
;


SwitchStatement:
	SWITCH LEFTROUNDBRACE Expression RIGHTROUNDBRACE SwitchBlock
		{
			printf("error at line #%d: switch not implemented\n", line_number);
			ehere();
			if($5->kind == KILLEGAL){
				printf("error at line #%d: incompatible types used in switch block\n", line_number);
				$$ = ERROR;
				ehere(22);
			}else if($3->pdtype == $5->pdtype){
				if($3->pdtype==TUNKNOWN || $3->pdtype==TVOID){
					printf("error at line #%d: switch expression not allowed\n", line_number);
					$$ = ERROR;
					ehere(23);
				}else{
					$$ = OKAY;
				}
			}else if($3->pdtype == TWILDCARD){//garbage code
				if($5->pdtype==TUNKNOWN || $5->pdtype==TVOID){
					printf("error at line #%d: switch expression not allowed\n", line_number);
					$$ = ERROR;
					ehere(24);
				}else{
					$$ = OKAY;
				}
			}else if($5->pdtype == TWILDCARD){
				if($3->pdtype==TUNKNOWN || $3->pdtype==TVOID){
					printf("error at line #%d: switch expression not allowed\n", line_number);
					$$ = ERROR;
					ehere(25);
				}else{
					$$ = OKAY;
				}
			}
		}
;

SwitchBlock:
	LEFTCURLYBRACE SwitchBlockStatementGroups SwitchLabels RIGHTCURLYBRACE
		{
			if($2->kind == KILLEGAL){
				$$  = $2;
			}else if($3->kind==KILLEGAL){
				$$ = $3;
			}else if($2->pdtype == $3->pdtype){
				$$ = $2;
			}else if($3->pdtype == TWILDCARD){
				$$ = $2;
			}else if($2->pdtype == TWILDCARD){
				$$ = $3;
			}else{
				$$ = makeIllegalNode();
			}
		}
|	LEFTCURLYBRACE SwitchBlockStatementGroups 			   RIGHTCURLYBRACE
		{
			$$ = $2;
		}
|	LEFTCURLYBRACE 							  SwitchLabels RIGHTCURLYBRACE
		{
			$$ = $2;
		}
|	LEFTCURLYBRACE 							 			   RIGHTCURLYBRACE
		{
			$$ = makePrimNode(string(), KUNKNOWN, TWILDCARD, vector<int>(), NULL, ANONE, NULL);
		}
;

SwitchBlockStatementGroups:
	SwitchBlockStatementGroup	{$$ = $1;}
|	SwitchBlockStatementGroups SwitchBlockStatementGroup
		{
			if($1->kind==KILLEGAL){
				$$ = $1;
			}else if($2->kind==KILLEGAL){
				$$ = $2;
			}else if($1->pdtype == $2->pdtype){
				$$ = $1;
			}else if($2->pdtype == TWILDCARD){
				$$ = $1;
			}else if($1->pdtype == TWILDCARD){
				$$ = $2;
			}else{
				$$ = makeIllegalNode();
			}
		}
;

SwitchBlockStatementGroup:
	SwitchLabels BlockStatements
		{
			$$ = $1;
		}
;

SwitchLabels:
	SwitchLabel	{$$ = $1;}
|	SwitchLabels SwitchLabel
		{
			if($1->kind == KILLEGAL){
				$$ = $1;
			}else if($2->kind == KILLEGAL){
				$$ = $2;
			}else if($1->pdtype == $2->pdtype){
				$$ = $1;
			}else if($2->pdtype == TWILDCARD){
				$$ = $1;
			}else if($1->pdtype == TWILDCARD){
				$$ = $2;
			}else{
				$$ = makeIllegalNode();
			}
		}
;

SwitchLabel:
	CASE ConstantExpression COLON	{$$ = $2;}
|	DEFAULT COLON
		{
			$$ = makePrimNode(string(), KUNKNOWN, TWILDCARD, vector<int>(), NULL, ANONE, NULL);
		}
			
;

WhileStatement:
	WHILE LEFTROUNDBRACE 
		{
			$1->label = string(newlabel());
			$1->sp1 = currentelement()->loc;
			fprintf(fp, "%sloop: #WHILE start\n", $1->label.c_str());
		}
	Expression RIGHTROUNDBRACE 
		{
			$1->sp2 = currentelement()->loc;
			fprintf(fp, "lw $t0, -%d($fp)\n", $4->loc);
			fprintf(fp, "li $t1, 1\n");
			fprintf(fp, "bne $t0, $t1, %snext\n", $1->label.c_str());
		}
	Statement
		{
			$1->sp3 = currentelement()->loc;
			int diff = $1->sp3 - $1->sp1;
			fprintf(fp, "addu $sp, $sp, %d\n", diff);
			fprintf(fp, "j %sloop\n", $1->label.c_str());
			fprintf(fp, "%snext:\n", $1->label.c_str());
			fprintf(fp, "subu $sp, $sp, %d #WHILE end\n", $1->sp3 - $1->sp2);
			
			if($4->pdtype != TBOOLEAN){
				printf("line #%d: expression must be boolean\n", line_number);
				$$ = ERROR;
				ehere(26);
			}else{
				$$ = $7;
			}
		}
;

DoStatement:
	DO
		{
			$1->label = string(newlabel());
			$1->sp1 = currentelement()->loc;
			fprintf(fp, "%sbody: #DO start\n", $1->label.c_str());
		}
	Statement
	WHILE LEFTROUNDBRACE Expression 
		{
			$1->sp2 = currentelement()->loc;
			fprintf(fp, "lw $t0, -%d($fp)\n", $6->loc);
			fprintf(fp, "li $t1, 1\n");
			int diff = $1->sp2 - $1->sp1;
			fprintf(fp, "addu $sp, $sp, %d\n", diff);
			fprintf(fp, "beq $t0, $t1, %sbody\n", $1->label.c_str());
			fprintf(fp, "subu $sp, $sp, %d\n", diff);
			fprintf(fp, "%snext: #DO end\n", $1->label.c_str());
		}
	RIGHTROUNDBRACE SEMICOLON
		{
			if($6->pdtype != TBOOLEAN){
				printf("line #%d: expression must be boolean\n", line_number);
				$$ = ERROR;
				ehere(28);
			}else{
				$$ = $3;
			}
		}
;

ForStatement:
	FOR LEFTROUNDBRACE ForInit SEMICOLON 
		{
			$1->label = string(newlabel());
			fprintf(fp, "%sloop: #FOR start\n", $1->label.c_str());
			$1->sp1=currentelement()->loc;
		}
	Expression 
		{
			$1->sp2=currentelement()->loc;
			fprintf(fp, "lw $t0, -%d($fp)\n", $6->loc);
			fprintf(fp, "li $t1, 1\n");
			fprintf(fp, "bne $t0, $t1, %snext\n", $1->label.c_str());
		}
	SEMICOLON RIGHTROUNDBRACE 
	Statement
		{	
			
			$1->sp3=currentelement()->loc;
			
			int stackused = $1->sp3 - $1->sp1;
			fprintf(fp, "addu $sp, $sp, %d\n", stackused);
			fprintf(fp, "j %sloop\n", $1->label.c_str());
			
			fprintf(fp, "%snext:\n", $1->label.c_str());
			int adjustment = $1->sp3 - $1->sp2;
			fprintf(fp, "subu $sp, $sp, %d #FOR end\n", adjustment);
			$$ = $3 && $10 && ($6->pdtype !=TBOOLEAN);
		}
|
	FOR LEFTROUNDBRACE ForInit SEMICOLON 
		{
			$1->label = string(newlabel());
			fprintf(fp, "%sloop: #FOR start\n", $1->label.c_str());
		}
	Expression 
		{
			fprintf(fp, "lw $t0, -%d($fp)\n", $6->loc);
			fprintf(fp, "li $t1, 1\n");
			fprintf(fp, "beq $t0, $t1, 1\n");
			fprintf(fp, "j %snext\n", $1->label.c_str());
			fprintf(fp, "j %sbody\n", $1->label.c_str());
			fprintf(fp, "%supdate:\n", $1->label.c_str());
		}
	SEMICOLON ForUpdate RIGHTROUNDBRACE 
		{
			fprintf(fp, "j %sloop\n", $1->label.c_str());
			fprintf(fp, "%sbody:\n", $1->label.c_str());
		}
	Statement
		{	
			fprintf(fp, "j %supdate\n", $1->label.c_str());
			fprintf(fp, "%snext: #FOR end\n");
			$$ = $3 && $9 && $12 && ($6->pdtype !=TBOOLEAN);
		}
|
	FOR LEFTROUNDBRACE ForInit SEMICOLON 
		{
			$1->label = string(newlabel());
			fprintf(fp, "%sloop: #FOR start\n", $1->label.c_str());
		}

		{
			fprintf(fp, "j %sbody\n", $1->label.c_str());
			fprintf(fp, "%supdate:\n", $1->label.c_str());
		}
	SEMICOLON ForUpdate RIGHTROUNDBRACE 
		{
			fprintf(fp, "j %sloop\n", $1->label.c_str());
			fprintf(fp, "%sbody:\n", $1->label.c_str());
		}
	Statement
		{	
			fprintf(fp, "j %supdate\n", $1->label.c_str());
			fprintf(fp, "%snext: #FOR end\n");
			$$ = $3 && $8 && $11;
		}

|
	FOR LEFTROUNDBRACE ForInit SEMICOLON 
		{
			$1->label = string(newlabel());
			fprintf(fp, "%sloop: #FOR start\n", $1->label.c_str());
		}
	
		{
			fprintf(fp, "j %sbody\n", $1->label.c_str());
			fprintf(fp, "%supdate:\n", $1->label.c_str());
		}
	SEMICOLON RIGHTROUNDBRACE 
		{
			fprintf(fp, "j %sloop\n", $1->label.c_str());
			fprintf(fp, "%sbody:\n", $1->label.c_str());
		}
	Statement
		{	
			fprintf(fp, "j %supdate\n", $1->label.c_str());
			fprintf(fp, "%snext: #FOR end\n");
			$$ = $3 && $10;
		}


|
	FOR LEFTROUNDBRACE SEMICOLON 
		{
			$1->label = string(newlabel());
			fprintf(fp, "%sloop: #FOR start\n", $1->label.c_str());
		}
	Expression 
		{
			fprintf(fp, "lw $t0, -%d($fp)\n", $5->loc);
			fprintf(fp, "li $t1, 1\n");
			fprintf(fp, "beq $t0, $t1, 1\n");
			fprintf(fp, "j %snext\n", $1->label.c_str());
			fprintf(fp, "j %sbody\n", $1->label.c_str());
			fprintf(fp, "%supdate:\n", $1->label.c_str());
		}
	SEMICOLON ForUpdate RIGHTROUNDBRACE 
		{
			fprintf(fp, "j %sloop\n", $1->label.c_str());
			fprintf(fp, "%sbody:\n", $1->label.c_str());
		}
	Statement
		{	
			fprintf(fp, "j %supdate\n", $1->label.c_str());
			fprintf(fp, "%snext: #FOR end\n");
			$$ = $8 && $11 && ($5->pdtype !=TBOOLEAN);
		}


|
	FOR LEFTROUNDBRACE SEMICOLON 
		{
			$1->label = string(newlabel());
			fprintf(fp, "%sloop: #FOR start\n", $1->label.c_str());
		}
	Expression 
		{
			fprintf(fp, "lw $t0, -%d($fp)\n", $5->loc);
			fprintf(fp, "li $t1, 1\n");
			fprintf(fp, "beq $t0, $t1, 1\n");
			fprintf(fp, "j %snext\n", $1->label.c_str());
			fprintf(fp, "j %sbody\n", $1->label.c_str());
			fprintf(fp, "%supdate:\n", $1->label.c_str());
		}
	SEMICOLON RIGHTROUNDBRACE 
		{
			fprintf(fp, "j %sloop\n", $1->label.c_str());
			fprintf(fp, "%sbody:\n", $1->label.c_str());
		}
	Statement
		{	
			fprintf(fp, "j %supdate\n", $1->label.c_str());
			fprintf(fp, "%snext: #FOR end\n");
			$$ = $10 && ($5->pdtype !=TBOOLEAN);
		}

|
	FOR LEFTROUNDBRACE SEMICOLON 
		{
			$1->label = string(newlabel());
			fprintf(fp, "%sloop: #FOR start\n", $1->label.c_str());
		}
	
		{
			fprintf(fp, "j %sbody\n", $1->label.c_str());
			fprintf(fp, "%supdate:\n", $1->label.c_str());
		}
	SEMICOLON ForUpdate RIGHTROUNDBRACE 
		{
			fprintf(fp, "j %sloop\n", $1->label.c_str());
			fprintf(fp, "%sbody:\n", $1->label.c_str());
		}
	Statement
		{	
			fprintf(fp, "j %supdate\n", $1->label.c_str());
			fprintf(fp, "%snext: #FOR end\n");
			$$ = $7 && $10;
		}

|
	FOR LEFTROUNDBRACE SEMICOLON 
		{
			$1->label = string(newlabel());
			fprintf(fp, "%sloop: #FOR start\n", $1->label.c_str());
		}
	
		{
			fprintf(fp, "j %sbody\n", $1->label.c_str());
			fprintf(fp, "%supdate:\n", $1->label.c_str());
		}
	SEMICOLON RIGHTROUNDBRACE 
		{
			fprintf(fp, "j %sloop\n", $1->label.c_str());
			fprintf(fp, "%sbody:\n", $1->label.c_str());
		}
	Statement
		{	
			fprintf(fp, "j %supdate\n", $1->label.c_str());
			fprintf(fp, "%snext: #FOR end\n");
			$$ = $9;
		}

;

DO:
	_DO	{	$$ = new splab();	}
;

WHILE:
	_WHILE	{	$$ = new splab();	}
;


FOR:
	_FOR	{	$$ = new splab();	}
;

IF:
	_IF	{	$$ = new splab();	}
;

ForInit:
	StatementExpressionList
		{
			if($1->kind == KILLEGAL){
				$$ = ERROR;
				ehere(29);
			}else{
				$$ = OKAY;
			}
		}
|	LocalVariableDeclaration
		{
			$$ = $1;
		}
;

ForUpdate:
	StatementExpressionList
		{
			if($1->kind == KILLEGAL){
				$$ = ERROR;
				ehere(30);
			}else{
				$$ = OKAY;
			}
		}
;

StatementExpressionList:
	StatementExpression	{$$ = $1;}
|	StatementExpressionList COMMA StatementExpression
		{
			if($1->kind==KILLEGAL || $3->kind ==KILLEGAL){
				$1->kind=KILLEGAL;
				ehere(34);
			}
			$$ = $1;
		}
;

BreakStatement:
	BREAK Identifier SEMICOLON	{$$ = OKAY;}
|	BREAK 			 SEMICOLON	{$$ = OKAY;}
;

ContinueStatement:
	CONTINUE Identifier SEMICOLON	{$$ = OKAY;}
|	CONTINUE 			SEMICOLON	{$$ = OKAY;}
;

ReturnStatement:
	RETURN Expression SEMICOLON
		{
			fprintf(fp, "subu $t0, $fp, %d #RETURN\n", $2->loc);
			fprintf(fp, "sw $t0, 0($fp)\n");
			fprintf(fp, "jr $ra\n");
			
			scope* scp = currentelement()->desc;
			while(scp != NULL && scp->elem->kind!=KPRIMFUNCTION && scp->elem->kind!=KREFFUNCTION) scp = scp->parent;
			if(scp == NULL){
				printf("error at line#%d: return statement must be inside a method\n", line_number);
				$$ = ERROR;
				ehere(31);
			}else if(scp->elem->kind == KPRIMFUNCTION){
				 if(!iscoercible($2, makePrimNode(string(), KVARIABLE, scp->elem->pdtype, vector<int>(), NULL, ANONE, NULL))){
						ehere(212);
						printf("error at line#%d: return statement: incompatible types\n", line_number);
						$$ = ERROR;
					}else {$$=OKAY;}
			}else if(scp->elem->kind == KREFFUNCTION){
				if(!iscoercible($2, makeRefNode(string(), KOBJECT, scp->elem->rdtype, vector<int>(), NULL, ANONE, NULL, NULL, NULL))){
					printf("error at line#%d: return statement: incompatible types\n", line_number);
					ehere(1);
					$$ =ERROR;
				} else {$$=OKAY;}
			}else{
				//printscopehierarchy();
				printf("error at line#%d: return statement must be inside a method\n", line_number);
				//printf("curelem->kind = %d\n", scp->elem->kind);
				$$ = ERROR;
				ehere(32);
			}
		}
|	RETURN  		  SEMICOLON
		{
			fprintf(fp, "jr $ra #RETURN\n");

			scope* s = current;
			while(s!=NULL && s->elem->kind != KPRIMFUNCTION) s= s->parent;
			if(s==NULL){
				printf("error at line#%d: return statement must be inside a method\n", line_number);
				$$ = ERROR;
				ehere(33);
			}else if(s->elem->pdtype == TVOID){
				$$ = OKAY;
			}else{
				printf("error at line#%d: incompatible return type\n", line_number);
				$$ = ERROR;
				ehere(33);
			}
		}
;

ThrowStatement://Not implemented
	THROW Expression SEMICOLON
|	THROW 		 	 SEMICOLON
;

SynchronizedStatement://Not implemented
	SYNCHRONIZED LEFTROUNDBRACE Expression RIGHTROUNDBRACE Block
;

TryStatement://Not implemented
	TRY Block Catches
|	TRY Block Catches Finally
|	TRY Block 		  Finally
;

Catches://Not implemented
	CatchClause
|	Catches CatchClause
;

CatchClause://Not implemented
	CATCH LEFTROUNDBRACE FormalParameter RIGHTROUNDBRACE Block
;

Finally://Not implemented
	FINALLY Block
;
//19.12
Primary:
	PrimaryNoNewArray	{$$ = $1;}
|	ArrayCreationExpression	{$$ = $1;}
;

PrimaryNoNewArray:
	Literal	{$$ = $1;}
|	THIS
	{
		element* e = makeRefNode(string(), KOBJECT, current->parent->elem, vector<int>(), 4, ANONE, NULL, NULL, NULL);
		e->amode = REFERENCE;
		$$ = e;
	}
|	LEFTROUNDBRACE Expression RIGHTROUNDBRACE	{$$ = $2;}
|	ClassInstanceCreationExpression	{$$ = $1;}
|	FieldAccess	{$$ = $1;}
|	MethodInvocation
		{
			$$ = $1;
		}
|	ArrayAccess
		{
			$$ = $1;
		}
;

ClassInstanceCreationExpression:
	NEW ClassType LEFTROUNDBRACE RIGHTROUNDBRACE
		{
			fprintf(fp, "li $a0, %d\n", sizeoftype($2));
			fprintf(fp, "li $v0, 9\n");
			fprintf(fp, "syscall\n");
			fprintf(fp, "addu $v0, $v0, %d\n", sizeoftype($2));
			fprintf(fp, "subu $sp, $sp, 4 #NEW %s\n", $2->name.c_str());
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
			fprintf(fp, "jal %s%s\n", $2->name.c_str(), $2->name.c_str());
			
			fprintf(fp, "addu $t0, $fp, 4\n");
			fprintf(fp, "lw $ra, 0($t0)\n");
			
			fprintf(fp, "addu $sp, $fp, 12\n");
			
			fprintf(fp, "addu $t0, $fp, 8\n");
			fprintf(fp, "lw $fp, 0($t0)\n");
			if($2==NULL){
				printf("error at line #%d: constructor not found in this scope\n", line_number);
				ehere(1951); here(1951);
				$$ = makeIllegalNode();
			}else{
				symmap::iterator it =  $2->desc->symtbl.find($2->name);
				if(it == $2->desc->symtbl.end()){
					printf("error at line #%d: constructor not declared\n", line_number);
					ehere(1958); here(1958);
					$$ = makeIllegalNode();					
				}else{
					element* constructor = it->second;
					if(!iscoerciblelisttolist(constructor->arguments, NULL)){
						printf("error at line#%d: unexpected arguments\n", line_number);
						$$ =makeIllegalNode();
					}else{
						
						$$ = makeRefNode(string(), KOBJECT, $2, vector<int>(), currentelement()->loc, ANONE, NULL, NULL, NULL);
					}
				}
			}
		}
|	NEW ClassType LEFTROUNDBRACE ArgumentList RIGHTROUNDBRACE
		{
			if($2==NULL){
				printf("error at line #%d: constructor not found in this scope\n", line_number);
				ehere(1975); here(1975);
				$$ = makeIllegalNode();
			}else{
				symmap::iterator it =  $2->desc->symtbl.find($2->name);
				if(it == $2->desc->symtbl.end()){
					printf("error at line #%d: constructor not declared\n", line_number);
					ehere(1958); here(1981);
					$$ = makeIllegalNode();					
				}else{
					element* constructor = it->second;
					if(!iscoerciblelisttolist(constructor->arguments, $4)){
						printf("error at line#%d: unexpected arguments\n", line_number);
						$$ =makeIllegalNode();
					}else{
						here(1990);
						fprintf(fp, "li $a0, %d\n", sizeoftype($2));
						fprintf(fp, "li $v0, 9\n");
						fprintf(fp, "syscall\n");
						fprintf(fp, "addu $v0, $v0, %d\n", sizeoftype($2));
						fprintf(fp, "subu $sp, $sp, 4 #NEW %s\n", $2->name.c_str());
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
						

					
						listofelements* e = $4;
						while(e!=NULL){
							if(e->elem->kind == KVARIABLE || e->elem->kind==KPRIMITIVE || e->elem->kind==KLITERAL){
								fprintf(fp, "subu $sp, $sp, %d\n", sizeofelement($4->elem));
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
						fprintf(fp, "jal %s%s\n", $2->name.c_str(), $2->name.c_str());
						
						fprintf(fp, "addu $t0, $fp, 4\n");
						fprintf(fp, "lw $ra, 0($t0)\n");
						
						fprintf(fp, "addu $sp, $fp, 12\n");
						
						fprintf(fp, "addu $t0, $fp, 8\n");
						fprintf(fp, "lw $fp, 0($t0)\n");

						$$ = makeRefNode(string(), KOBJECT, $2, vector<int>(), currentelement()->loc, ANONE, NULL, NULL, NULL);
					}
				}
			}
		}
;

ArgumentList:
	Expression
		{
			listofelements* list = new listofelements();
			list->elem = $1;
			list->next = NULL;
			$$ = list;
		}
|	ArgumentList COMMA Expression
		{
			listofelements* newnode = new listofelements();
			newnode->elem = $3;
			newnode->next = NULL;
			listofelements * list = $1;
			while(list->next != NULL) list = list->next;
			list->next = newnode;
			$$ = $1;
		}
;

ArrayCreationExpression:
	NEW PrimitiveType DimExprs Dims
		{
			printf("error at line number %d: Not implemented\n", line_number);
			ehere();
			vector<int> *vec1 = $3->pvec, *vec2 = $4->pvec;
			vec1->insert(vec1->end(), vec2->begin(), vec2->end());
			$$ = makePrimNode(string(), KVARIABLE, $2->pdtype, *vec1, NULL, ANONE, NULL);
		}
|	NEW PrimitiveType DimExprs
		{
			std::vector<int>::size_type sz = (*$3->pvec).size();
			fprintf(stderr, "size: %d\n", sz);
			fprintf(fp, "li $t0, 1\n");
			for(unsigned i=0; i<sz; i++){
				fprintf(stderr, "loc: %d\n", (*($3->pvec))[i]);
				fprintf(fp, "lw $t1, -%d($fp)\n", (*($3->pvec))[i]);
				fprintf(fp, "multu $t0, $t1\n");
				fprintf(fp, "mflo $t0\n");
			}
			fprintf(fp, "li $t1, %d\n", sizeoftype($2));
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
			
			$$ = makePrimNode(string(), KVARIABLE, $2->pdtype, *($3->pvec), currentelement()->loc, ANONE, NULL);
		}
|	NEW ClassOrInterfaceType DimExprs Dims
		{
			printf("error at line number %d: Not implemented\n", line_number);
			ehere();
			vector<int> *vec1 = $3->pvec, *vec2=$4->pvec;
			vec1->insert(vec1->end(), vec2->begin(), vec2->end());
			$$ = makeRefNode(string(), KOBJECT, $2->rdtype, *vec1, NULL, ANONE, NULL, NULL, NULL);
		}
|	NEW ClassOrInterfaceType DimExprs
		{
			std::vector<int>::size_type sz = (*$3->pvec).size();
			
			fprintf(fp, "li $t0, 1\n");
			for(unsigned i=0; i<sz; i++){
				fprintf(fp, "lw $t1, -%d($fp)\n", (*($3->pvec))[i]);
				fprintf(fp, "multu $t0, $t1\n");
				fprintf(fp, "mflo $t0\n");
			}
			fprintf(fp, "li $t1, %d\n", sizeoftype($2));
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
			
			$$ = makeRefNode(string(), KOBJECT, $2->rdtype, *$3->pvec, currentelement()->loc, ANONE, NULL, NULL, NULL);
		}
;

DimExprs:
	DimExpr
		{
			spvec* spv = (spvec*)malloc(sizeof(spvec));
			vector<int> * ptrvec = (vector<int>*)malloc(sizeof(vector<int>));
			ptrvec->push_back($1);
			
			spv->pvec = ptrvec;
			fprintf(stderr, "vec[0]=%d\n", (*(spv->pvec))[0]);
			$$ = spv; 
		}
|	DimExprs DimExpr
		{
			(*$1->pvec).push_back($2);
		}
;


DimExpr:
	LEFTSQUAREBRACE Expression RIGHTSQUAREBRACE
		{
			if($2->kind != KVARIABLE && !iscoercible($2, makePrimNode(string(), KPRIMITIVE, TINT, vector<int>(), NULL, ANONE, NULL))){
				printf("error at line #%d: expecting expressions convertible to int\n", line_number);
				ehere();
				here(2450);
				$$ = 0;
			}else{
				fprintf(stderr, "$$ = $2->loc = %d\n", $2->loc);
				$$ = $2->loc;
			}
		}
;

Dims:
	LEFTSQUAREBRACE RIGHTSQUAREBRACE
		{
			vector<int> vec (1, 0);
			spvec* s = (spvec*)malloc(sizeof(spvec));
			s->pvec = &vec;
			$$ = s; 
		}
|	Dims LEFTSQUAREBRACE RIGHTSQUAREBRACE
		{
			$1->pvec->push_back(0);
			$$ = $1;
		}
;

FieldAccess:
	Primary DOT Identifier
		{
			if($1->kind != KOBJECT){
				printf("error at line #%d: %s not an object\n", line_number, $1->name.c_str());
				$$ = makeIllegalNode();
			}else{
				symmap::iterator it = $1->rdtype->desc->symtbl.find($3);
				namenode* node = new namenode();
				node->name = string($3);
				node->next = NULL;
				element* obj = findobjectinthisorsuper($1, node, false);
				$$ = obj;
			}
		}
|	SUPER DOT Identifier
		{
			namenode* node = new namenode();
			element* sup = current->parent->elem->superclass;
			element* elem = findtypeinthisorsuper(sup, node, false);
			if(elem==NULL){
				printf("line #%d: member doesn't exist\n");
				$$ = makeIllegalNode();
			}else{
				fprintf(fp, "lw $t0, -4($fp) #SUPER.%s\n", $3);
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
				$$ = e;
			}
		}
;

MethodInvocation:
	Name LEFTROUNDBRACE ArgumentList RIGHTROUNDBRACE
		{
			element* func = findobject(current, $1, KALL);

			//ASSERT(func->kind == KPRIMFUNCTION || func->kind == KREFFUNCTION);
			if(iscoerciblelisttolist($3, func->arguments)){
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
					$$ = makePrimNode(string(), KVARIABLE, func->pdtype, vector<int>(), currentelement()->loc, ANONE, NULL);
					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $fp, ($sp)\n");//store $fp
					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $ra, ($sp)\n");//store $ra
					fprintf(fp, "subu $sp, $sp, 8\n");//set up call stack
					fprintf(fp, "lw $t1, -4($fp)\n");//getting access link
					fprintf(fp, "sw $t1, ($sp)\n");//storing access link
					fprintf(fp, "addu $s0, $sp, 4\n");
					
					listofelements* e = $3;
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
					$$ = makeRefNode(string(), KOBJECT, func->rdtype, vector<int>(), NULL, ANONE, NULL, NULL, NULL);

					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $fp, 0($sp)\n");//store $fp
					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $ra, 0($sp)\n");//store $ra
					fprintf(fp, "subu $sp, $sp, 8\n");//set up call stack
					fprintf(fp, "lw $t1, -4($fp)\n");//getting access link
					fprintf(fp, "sw $t1, 0($sp)\n");//storing access link
					fprintf(fp, "addu $s0, $sp, 4\n");
					
					listofelements* e = $3;
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
					$$ = makeIllegalNode();
				}
			}else{
				printf("line #%d: imcompatible arguments\n", line_number);
				$$ = makeIllegalNode();
			}
		}			
|	Name LEFTROUNDBRACE RIGHTROUNDBRACE
		{			
			
			element* func = findobject(current, $1, KALL);
			namenode* n = new namenode();
			n->name = $1->name;
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
					$$ = makePrimNode(string(), KVARIABLE, func->pdtype, vector<int>(), currentelement()->loc, ANONE, NULL);
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
					$$ = makeRefNode(string(), KOBJECT, func->rdtype, vector<int>(), NULL, ANONE, NULL, NULL, NULL);

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
					$$ = makeIllegalNode();
				}
		}	
|	Primary DOT Identifier LEFTROUNDBRACE ArgumentList RIGHTROUNDBRACE
		{
			namenode* newnode = new namenode();
			newnode->name = string($3);
			element* e = findtypeinthisorsuper($1, newnode, true);
			if(e==NULL){
				printf("line #%d: method not found\n", line_number);
				$$ = makeIllegalNode();
			}else{
				element* func = e;
				if(!iscoerciblelist(func->arguments, NULL)){
					printf("line #%d: incompatible arguments\n", line_number);
					$$ = makeIllegalNode();
				}else{
					if(func->kind == KPRIMFUNCTION){
					fprintf(fp, "subu $sp, $sp, 4 #CALL %s.%s\n", $1->name.c_str(), $3);
					
					currentelement()->loc +=4;
					if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
					//~ if(func->pdtype==TDOUBLE || func->pdtype==TLONG){
						//~ fprintf(fp, "subu $sp, $sp, 4\n");
						//~ fprintf(fp, "move $t0, $sp\n");//making space for return value
						//~ currentelement()->loc +=4;
					//~ }
					$$ = makePrimNode(string(), KVARIABLE, func->pdtype, vector<int>(), currentelement()->loc, ANONE, NULL);
					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $fp, ($sp)\n");//store $fp
					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $ra, ($sp)\n");//store $ra
					fprintf(fp, "subu $sp, $sp, 8\n");//set up call stack
					fprintf(fp, "lw $t1, -%d($fp)\n", $1->loc);//getting access link
					fprintf(fp, "sw $t1, ($sp)\n");//storing access link
					fprintf(fp, "addu $s0, $sp, 4\n");
					
					listofelements* e = $5;
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
					fprintf(fp, "subu $sp, $sp, 4 #CALL %s.%s\n", $1->name.c_str(), $3);
					
					currentelement()->loc +=4;
					if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
					$$ = makeRefNode(string(), KOBJECT, func->rdtype, vector<int>(), NULL, ANONE, NULL, NULL, NULL);

					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $fp, ($sp)\n");//store $fp
					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $ra, ($sp)\n");//store $ra
					fprintf(fp, "subu $sp, $sp, 8\n");//set up call stack
					fprintf(fp, "lw $t1, -%d($fp)\n", $1->loc);//getting access link
					fprintf(fp, "sw $t1, ($sp)\n");//storing access link
					fprintf(fp, "addu $s0, $sp, 4\n");
					
					listofelements* e = $5;
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
						$$ = makeIllegalNode();
					}
				}
			}
		}
						
|	Primary DOT Identifier LEFTROUNDBRACE RIGHTROUNDBRACE
		{
			namenode* newnode = new namenode();
			newnode->name = string($3);
			element* e = findtypeinthisorsuper($1, newnode, true);
			if(e==NULL){
				printf("line #%d: method not found\n", line_number);
				$$ = makeIllegalNode();
			}else{
				element* func = e;
				if(func->kind == KPRIMFUNCTION){
				fprintf(fp, "subu $sp, $sp, 4 #CALL %s.%s\n", $1->name.c_str(), $3);
				
				currentelement()->loc +=4;
				if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
				//~ if(func->pdtype==TDOUBLE || func->pdtype==TLONG){
					//~ fprintf(fp, "subu $sp, $sp, 4\n");
					//~ fprintf(fp, "move $t0, $sp\n");//making space for return value
					//~ currentelement()->loc +=4;
				//~ }
				$$ = makePrimNode(string(), KVARIABLE, func->pdtype, vector<int>(), currentelement()->loc, ANONE, NULL);
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
				fprintf(fp, "subu $sp, $sp, 4 #CALL %s.%s\n", $1->name.c_str(), $3);
				
				currentelement()->loc +=4;
				if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
				$$ = makeRefNode(string(), KOBJECT, func->rdtype, vector<int>(), NULL, ANONE, NULL, NULL, NULL);

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
				$$ = makeIllegalNode();
			}
			
		}
	}
|	SUPER DOT Identifier LEFTROUNDBRACE RIGHTROUNDBRACE
		{
			scope* s = current;
			while(s->elem->kind != KCLASS) s = s->parent;
			element* sup = s->elem;
			namenode* newnode = new namenode();
			newnode->name = string($3);
			element* e = findtypeinthisorsuper(sup, newnode, true);
			if(e==NULL){
				printf("line #%d: method %s not found\n", line_number, $3);
				$$ = makeIllegalNode();
			}else if((e->kind!=KPRIMFUNCTION && e->kind!=KREFFUNCTION)){
				printf("line #%d: %s not a method\n", line_number, $3);
				$$ = makeIllegalNode();
			}else{
				element* func = e;
				if(!iscoerciblelist(func->arguments, NULL)){
					printf("line #%d: incompatible arguments\n", line_number);
					$$ = makeIllegalNode();
				}else{
				if(func->kind == KPRIMFUNCTION){
					fprintf(fp, "subu $sp, $sp, 4 #CALL SUPER.%s\n", $3);
					
					currentelement()->loc +=4;
					if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
					//~ if(func->pdtype==TDOUBLE || func->pdtype==TLONG){
						//~ fprintf(fp, "subu $sp, $sp, 4\n");
						//~ fprintf(fp, "move $t0, $sp\n");//making space for return value
						//~ currentelement()->loc +=4;
					//~ }
					$$ = makePrimNode(string(), KVARIABLE, func->pdtype, vector<int>(), currentelement()->loc, ANONE, NULL);
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
					fprintf(fp, "subu $sp, $sp, 4 #CALL SUPER.%s\n", $3);
					
					currentelement()->loc +=4;
					if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
					$$ = makeRefNode(string(), KOBJECT, func->rdtype, vector<int>(), NULL, ANONE, NULL, NULL, NULL);

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
						$$ = makeIllegalNode();
					}
				}
			}
		}
|	SUPER DOT Identifier LEFTROUNDBRACE ArgumentList RIGHTROUNDBRACE
		{
			scope* s = current;
			while(s->elem->kind != KCLASS) s = s->parent;
			element* sup = s->elem;
			namenode* newnode = new namenode();
			newnode->name = string($3);
			element* e = findtypeinthisorsuper(sup, newnode, true);
			if(e==NULL){
				printf("line #%d: method %s not found\n", line_number, $3);
				$$ = makeIllegalNode();
			}else if((e->kind!=KPRIMFUNCTION && e->kind!=KREFFUNCTION)){
				printf("line #%d: %s not a method\n", line_number, $3);
				$$ = makeIllegalNode();
			}else{
				element* func = e;
				if(!iscoerciblelisttolist(func->arguments, $5)){
					printf("line #%d: incompatible arguments\n", line_number);
					$$ = makeIllegalNode();
				}else{
					if(func->kind == KPRIMFUNCTION){
					fprintf(fp, "subu $sp, $sp, 4 #CALL SUPER.%s\n", $3);
					
					currentelement()->loc +=4;
					if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
					//~ if(func->pdtype==TDOUBLE || func->pdtype==TLONG){
						//~ fprintf(fp, "subu $sp, $sp, 4\n");
						//~ fprintf(fp, "move $t0, $sp\n");//making space for return value
						//~ currentelement()->loc +=4;
					//~ }
					$$ = makePrimNode(string(), KVARIABLE, func->pdtype, vector<int>(), currentelement()->loc, ANONE, NULL);
					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $fp, ($sp)\n");//store $fp
					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $ra, ($sp)\n");//store $ra
					fprintf(fp, "subu $sp, $sp, 8\n");//set up call stack
					fprintf(fp, "lw $t1, -4($fp)\n");//getting access link
					fprintf(fp, "sw $t1, ($sp)\n");//storing access link
					fprintf(fp, "addu $s0, $sp, 4\n");
					
					listofelements* e = $5;
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
					$$ = makeRefNode(string(), KOBJECT, func->rdtype, vector<int>(), NULL, ANONE, NULL, NULL, NULL);

					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $fp, ($sp)\n");//store $fp
					fprintf(fp, "subu $sp, $sp, 4\n");//set up call stack
					fprintf(fp, "sw $ra, ($sp)\n");//store $ra
					fprintf(fp, "subu $sp, $sp, 8\n");//set up call stack
					fprintf(fp, "lw $t1, -4($fp)\n");//getting access link
					fprintf(fp, "sw $t1, ($sp)\n");//storing access link
					fprintf(fp, "addu $s0, $sp, 4\n");
					
					listofelements* e = $5;
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
						$$ = makeIllegalNode();
					}
				}
			}
		}
|	PRINTSTRING LEFTROUNDBRACE Expression RIGHTROUNDBRACE
		{
			
			fprintf(fp, "lw $a0, -%d($fp)\n", $3->loc);
			fprintf(fp, "li $v0, 4\n");
			fprintf(fp, "syscall\n");
			$$ = makePrimNode(string(), KPRIMITIVE, TVOID, vector<int>(), 0, ANONE, NULL);
		}
|	PRINTINT LEFTROUNDBRACE Expression RIGHTROUNDBRACE
		{
			fetchint0($3);
			fprintf(fp, "move $a0, $t0\n");
			fprintf(fp, "li $v0, 1\n");
			fprintf(fp, "syscall\n");
			$$ = makePrimNode(string(), KPRIMITIVE, TVOID, vector<int>(), 0, ANONE, NULL);
		}
|	PRINTFLOAT LEFTROUNDBRACE Expression RIGHTROUNDBRACE
		{
			
			fprintf(fp, "lwc1 $f12, -%d($fp)\n", $3->loc);
			//fprintf(fp, "li.s $f12, 34.23\n");
			//fprintf(fp, "mov.s $f12, $f0\n");
			fprintf(fp, "li $v0, 2\n");
			fprintf(fp, "syscall\n");
			$$ = makePrimNode(string(), KPRIMITIVE, TVOID, vector<int>(), 0, ANONE, NULL);
		}


;

ArrayAccess:
	Name LEFTSQUAREBRACE Expression RIGHTSQUAREBRACE
		{
			element* elem = findobject(current, $1, KALL);
			//ASSERT(elem->kind == KVARIABLE || elem->kind == KOBJECT);
			if(elem==NULL){
				printf("line #%d: array not accessible\n", line_number);
				$$ = makeIllegalNode();
			}else if(!iscoercible($3, makePrimNode(string(), KPRIMITIVE, TINT, vector<int>(), NULL, ANONE, NULL))){
				printf("line #%d: expecting expression convertible to int\n", line_number);
				$$ = makeIllegalNode();
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
					fetchint0($3);//value of expression in t0
					
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
					$$ = e;
					
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
					fetchint0($3);
					
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
					$$ = e;
		
					
					
					
					
				}else{
					printf("line #%d: not a variable or an object\n", line_number);
					$$ = makeIllegalNode();
				}
			}
		}
|	PrimaryNoNewArray LEFTSQUAREBRACE Expression RIGHTSQUAREBRACE
		{
			element* elem = $1;
			if(!iscoercible($3, makePrimNode(string(), KPRIMITIVE, TINT, vector<int>(), NULL, ANONE, NULL))){
				printf("line #%d: expecting expression convertible to int\n", line_number);
				$$ = makeIllegalNode();
			}else{
				if(elem==NULL || elem->kind == KILLEGAL){
					printf("line #%d: object/variable not accessible\n", line_number);
					$$ = makeIllegalNode();
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
					fetchint0($3);
					
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
					$$ = e;					
					
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
					fetchint0($3);
					
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
					$$ = e;					
							
				}
			}
		}
;

PostfixExpression:
	Primary	{$$ = $1;}
|	Name	{$$ = findobject(current, $1, KALL);}
|	PostIncrementExpression	{$$ = $1;}
|	PostDecrementExpression	{$$ = $1;}
;

PostIncrementExpression:
	PostfixExpression PLUSPLUS 
		{
			if($1->amode==DIRECT){
				fprintf(fp, "lw $s0, -%d($fp) #PostIncrementExpression\n", $1->loc);
				fprintf(fp, "move $t0, $s0\n");
				fprintf(fp, "addi $t0, $t0, 1\n");
				fprintf(fp, "sw $t0, -%d($fp)\n", $1->loc);
			}else{
				fprintf(fp, "lw $t1, -%d($fp) #PostIncrementExpression\n", $1->loc);
				fprintf(fp, "lw $s0, 0($t1)\n");
				fprintf(fp, "move $t0, $s0\n");
				fprintf(fp, "addi $t0, $t0, 1\n");
				fprintf(fp, "sw $t0, 0($t1)\n", $1->loc);				
			}
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "sw $s0, 0($sp)\n");
			element* e = copyelement($1);
			e->loc = currentelement()->loc;
			$$ = e;
		}
;

PostDecrementExpression:
	PostfixExpression MINUSMINUS
		{
			if($1->amode==DIRECT){
				fprintf(fp, "lw $s0, -%d($fp) #PostDecrementExpression\n", $1->loc);
				fprintf(fp, "move $t0, $s0\n");
				fprintf(fp, "addi $t0, $t0, -1\n");
				fprintf(fp, "sw $t0, -%d($fp)\n", $1->loc);
			}else{
				fprintf(fp, "lw $t1, -%d($fp) #PostDecrementExpression\n", $1->loc);
				fprintf(fp, "lw $s0, 0($t1)\n");
				fprintf(fp, "move $t0, $s0\n");
				fprintf(fp, "addi $t0, $t0, -1\n");
				fprintf(fp, "sw $t0, 0($t1)\n", $1->loc);				
			}
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "sw $s0, 0($sp)\n");
			element* e = copyelement($1);
			e->loc = currentelement()->loc;
			$$ = e;
		}
;

UnaryExpression:
	PreIncrementExpression	{$$ = $1;}
|	PreDecrementExpression	{$$ = $1;}
|	PLUS  UnaryExpression	{$$ = $2;}
|	MINUS  UnaryExpression
		{
			fetchint0($2);
			fprintf(fp, "li $t1, -1 #UnaryExpression\n");
			fprintf(fp, "mult $t0, $t1\n");
			fprintf(fp, "mflo $t0\n");
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "sw $t0, 0($sp)\n");
			element* e = copyelement($2);
			e->loc = currentelement()->loc;
			$$ = e;
		}
|	UnaryExpressionNotPlusMinus	{$$ = $1;}
;

PreIncrementExpression:
	PLUSPLUS  UnaryExpression
		{
			if($2->amode==DIRECT){
				fprintf(fp, "lw $t0, -%d($fp) #PreIncrementExpression\n", $2->loc);
				
				fprintf(fp, "addi $t0, $t0, +1\n");
				fprintf(fp, "sw $t0, -%d($fp)\n", $2->loc);
			}else{
				fprintf(fp, "lw $t1, -%d($fp) #PreIncrementExpression\n", $2->loc);
				fprintf(fp, "lw $t0, 0($t1)\n");
				
				fprintf(fp, "addi $t0, $t0, +1\n");
				fprintf(fp, "sw $t0, 0($t1)\n", $2->loc);				
			}
			$$ = $2;
		}
;

PreDecrementExpression:
	MINUSMINUS UnaryExpression
		{
			if($2->amode==DIRECT){
				fprintf(fp, "lw $t0, -%d($fp) #PreDecrementExpression\n", $2->loc);
				
				fprintf(fp, "addi $t0, $t0, -1\n");
				fprintf(fp, "sw $t0, -%d($fp)\n", $2->loc);
			}else{
				fprintf(fp, "lw $t1, -%d($fp) #PreDecrementExpression\n", $2->loc);
				fprintf(fp, "lw $t0, 0($t1)\n");
				
				fprintf(fp, "addi $t0, $t0, -1\n");
				fprintf(fp, "sw $t0, 0($t1)\n", $2->loc);				
			}
			$$ = $2;
		}
;
UnaryExpressionNotPlusMinus:
	PostfixExpression	{$$ = $1;}
|	TILDE UnaryExpression
	{
		fetchint0($2);
		fprintf(fp, "xori $t0, $t0, -1 #UnaryExpressionNotPlusMinus\n");
		fprintf(fp, "subu $sp, $sp, 4\n");
		currentelement()->loc +=4;
		if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
		fprintf(fp, "sw $t0, 0($sp)\n");
		element* e = copyelement($2);
		e->loc = currentelement()->loc;
		$$ = e;
	} 
|	NOT UnaryExpression
		{
			if(!iscoercible($2, makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL))){
				printf("line #%d: expected boolean expression after !\n", line_number);
				$$ = makeIllegalNode();
			}else{
				fetchint0($2);
				fprintf(fp, "xori $t0, $t0, 1 #UnaryExpressionNotPlusMinus\n");
				fprintf(fp, "subu $sp, $sp, 4\n");
				currentelement()->loc +=4;
				if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
				fprintf(fp, "sw $t0, 0($sp)\n");
				element* e = copyelement($2);
				e->loc = currentelement()->loc;
				$$ = e;
			}
		}
|	CastExpression	{$$ = $1;}
;

CastExpression:
	LEFTROUNDBRACE PrimitiveType Dims RIGHTROUNDBRACE UnaryExpression
		{
			printf("error at line %d: Not implemented\n", line_number);
			$2->dimensions = *$3->pvec;
			if(iscoercible($5, $2)){
				$$ = copyandcoerce($5, $2);
			}else{
				printf("line #%d: type not coercible\n", line_number);
				$$ = makeIllegalNode();
			}
		}	
|	LEFTROUNDBRACE PrimitiveType RIGHTROUNDBRACE UnaryExpression
		{
			if(iscoercible($4, $2)){
				$$ = coerce($4, $2);
			}else{
				printf("line #%d: type not coercible\n", line_number);
				$$ = makeIllegalNode();
			}
		}	
|	LEFTROUNDBRACE Expression RIGHTROUNDBRACE UnaryExpressionNotPlusMinus
		{
			if(iscoercible($4, $2)){
				$$ = coerce($4, $2);
			}else{
				printf("line #%d: type not coercible\n", line_number);
				$$ = makeIllegalNode();
			}
		}	
|	LEFTROUNDBRACE Name Dims RIGHTROUNDBRACE UnaryExpressionNotPlusMinus
		{
			printf("error at line %d: Not implemented\n", line_number);
			element* type = findtype(current, $2);
			type->dimensions = *($3->pvec);
			if(iscoercible($5, type)){
				$$ = copyandcoerce($5, type);
			}else{
				printf("line #%d: type not coercible\n", line_number);
				$$ = makeIllegalNode();
			}
		}	
;

MultiplicativeExpression:
	UnaryExpression	{ $$ = $1;}
|	MultiplicativeExpression ASTERISK  UnaryExpression
		{
			fetchint0($1);
			fprintf(fp, "move $t1, $t0 #MultiplicativeExpression\n");
			fetchint0($3);
			fprintf(fp, "mult $t1, $t0\n");
			fprintf(fp, "mflo $t0\n");
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "sw $t0, 0($sp)\n");
			
			element* e;
			if(iscoercible($1, $3)){
				e = copyandcoerce($1, $3);
			}else if(iscoercible($3, $1)){
				e = copyandcoerce($3, $1);
			}else{
				printf("line #%d: incompatible types\n", line_number);
				$$ = makeIllegalNode();
			}
			e->loc = currentelement()->loc;
			$$ = e;
		}
|	MultiplicativeExpression DIVIDE  UnaryExpression
		{
			fetchint0($1);
			fprintf(fp, "move $t1, $t0 #MultiplicativeExpression\n");
			fetchint0($3);
			fprintf(fp, "div $t1, $t0\n");
			fprintf(fp, "mflo $t0\n");
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "sw $t0, 0($sp)\n");
			
			element* e;
			if(iscoercible($1, $3)){
				e = copyandcoerce($1, $3);
			}else if(iscoercible($3, $1)){
				e = copyandcoerce($3, $1);
			}else{
				printf("line #%d: incompatible types\n", line_number);
				$$ = makeIllegalNode();
			}
			e->loc = currentelement()->loc;
			$$ = e;
		}
|	MultiplicativeExpression PERCENT  UnaryExpression
		{
			fetchint0($1);
			fprintf(fp, "move $t1, $t0 #MultiplicativeExpression\n");
			fetchint0($3);
			fprintf(fp, "div $t1, $t0\n");
			fprintf(fp, "mfhi $t0\n");
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "sw $t0, 0($sp)\n");
			
			element* e;
			if(iscoercible($1, $3)){
				e = copyandcoerce($1, $3);
			}else if(iscoercible($3, $1)){
				e = copyandcoerce($3, $1);
			}else{
				printf("line #%d: incompatible types\n", line_number);
				$$ = makeIllegalNode();
			}
			e->loc = currentelement()->loc;
			$$ = e;
		}
;

AdditiveExpression:
	MultiplicativeExpression	{$$ = $1;}
|	AdditiveExpression PLUS  MultiplicativeExpression
		{
			fetchint0($1);
			fprintf(fp, "move $t1, $t0 #MultiplicativeExpression\n");
			fetchint0($3);
			fprintf(fp, "add $t0, $t1, $t0\n");
			
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "sw $t0, 0($sp)\n");
			
			element* e;
			if(iscoercible($1, $3)){
				e = copyandcoerce($1, $3);
			}else if(iscoercible($3, $1)){
				e = copyandcoerce($3, $1);
			}else{
				printf("line #%d: incompatible types\n", line_number);
				$$ = makeIllegalNode();
			}
			e->loc = currentelement()->loc;
			$$ = e;
		}
|	AdditiveExpression MINUS  MultiplicativeExpression
		{
			fetchint0($1);
			fprintf(fp, "move $t1, $t0 #MultiplicativeExpression\n");
			fetchint0($3);
			fprintf(fp, "sub $t0, $t1, $t0\n");
			
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "sw $t0, 0($sp)\n");
			
			element* e;
			if(iscoercible($1, $3)){
				e = copyandcoerce($1, $3);
			}else if(iscoercible($3, $1)){
				e = copyandcoerce($3, $1);
			}else{
				printf("line #%d: incompatible types\n", line_number);
				$$ = makeIllegalNode();
			}
			e->loc = currentelement()->loc;
			$$ = e;
		}
;

ShiftExpression:
	AdditiveExpression	{ $$ = $1;}
|	ShiftExpression LEFTSHIFT AdditiveExpression
		{
			if(!iscoercible($1, makePrimNode(string(), KPRIMITIVE, TINT, vector<int>(), NULL, ANONE, NULL))){
				printf("line #%d: shift expression must be coercible to int\n", line_number);
				$$ = makeIllegalNode();
			}else if($3->kind != KPRIMITIVE || $3->pdtype!=TBYTE || $3->pdtype!=TCHAR || $3->pdtype!=TSHORT || $3->pdtype!=TINT || $3->pdtype!=TLONG){
				printf("line #%d: expression to be shifted must be primitive integral type\n", line_number);
				$$ = makeIllegalNode();
			}else{
				fetchint0($1);
				fprintf(fp, "move $t1, $t0 #ShiftExpression\n");
				fetchint0($3);
				fprintf(fp, "sllv $t0, $t0, $t1\n");
				fprintf(fp, "subu $sp, $sp, 4\n");
				currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
				fprintf(fp, "sw $t0, 0($sp)\n");
				element* e= copyelement($1);
				e->loc = currentelement()->loc;
				$$ = e;
			}
		}
				
|	ShiftExpression RIGHTSHIFT AdditiveExpression
		{
			if(!iscoercible($1, makePrimNode(string(), KPRIMITIVE, TINT, vector<int>(), NULL, ANONE, NULL))){
				printf("line #%d: shift expression must be coercible to int\n", line_number);
				$$ = makeIllegalNode();
			}else if($3->kind != KPRIMITIVE || $3->pdtype!=TBYTE || $3->pdtype!=TCHAR || $3->pdtype!=TSHORT || $3->pdtype!=TINT || $3->pdtype!=TLONG){
				printf("line #%d: expression to be shifted must be primitive integral type\n", line_number);
				$$ = makeIllegalNode();
			}else{
				fetchint0($1);
				fprintf(fp, "move $t1, $t0 #ShiftExpression\n");
				fetchint0($3);
				fprintf(fp, "srav $t0, $t0, $t1\n");
				fprintf(fp, "subu $sp, $sp, 4\n");
				currentelement()->loc +=4;
				if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
				fprintf(fp, "sw $t0, 0($sp)\n");
				element* e= copyelement($1);
				e->loc = currentelement()->loc;
				$$ = e;
			}
		}
		
|	ShiftExpression UNRIGHTSHIFT AdditiveExpression
		{
			if(!iscoercible($1, makePrimNode(string(), KPRIMITIVE, TINT, vector<int>(), NULL, ANONE, NULL))){
				printf("line #%d: shift expression must be coercible to int\n", line_number);
				$$ = makeIllegalNode();
			}else if($3->kind != KPRIMITIVE || $3->pdtype!=TBYTE || $3->pdtype!=TCHAR || $3->pdtype!=TSHORT || $3->pdtype!=TINT || $3->pdtype!=TLONG){
				printf("line #%d: expression to be shifted must be primitive integral type\n", line_number);
				$$ = makeIllegalNode();
			}else{
				fetchint0($1);
				fprintf(fp, "move $t1, $t0 #ShiftExpression\n");
				fetchint0($3);
				fprintf(fp, "srlv $t0, $t0, $t1\n");
				fprintf(fp, "subu $sp, $sp, 4\n");
				currentelement()->loc +=4;
				if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
				fprintf(fp, "sw $t0, 0($sp)\n");
				element* e= copyelement($1);
				e->loc = currentelement()->loc;
				$$ = e;
			}
		}
		
;

RelationalExpression:
	ShiftExpression
		{
			$$ = $1;
		}
|	RelationalExpression LESS ShiftExpression
		{
			fetchint0($1);
			fprintf(fp, "move $t1, $t0 #RelationalExpression\n");
			fetchint0($3);
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
			if(iscoercible($1, $3)){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
				
			}else if(iscoercible($3, $1)){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				$$ = makeIllegalNode();
			}
			e->loc=currentelement()->loc;
			$$ = e;
		}
|	RelationalExpression GREATER ShiftExpression
		{
			fetchint0($1);
			fprintf(fp, "move $t1, $t0 #RelationalExpression\n");
			fetchint0($3);
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
			if(iscoercible($1, $3)){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
				
			}else if(iscoercible($3, $1)){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				$$ = makeIllegalNode();
			}
			e->loc=currentelement()->loc;
			$$ = e;
		}
|	RelationalExpression GREATEQUALS ShiftExpression
		{
			fetchint0($1);
			fprintf(fp, "move $t1, $t0 #RelationalExpression\n");
			fetchint0($3);
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
			if(iscoercible($1, $3)){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
				
			}else if(iscoercible($3, $1)){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				$$ = makeIllegalNode();
			}
			e->loc=currentelement()->loc;
			$$ = e;
		}
|	RelationalExpression LESSEQUALS ShiftExpression
		{
			fetchint0($1);
			fprintf(fp, "move $t1, $t0 #RelationalExpression\n");
			fetchint0($3);
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
			if(iscoercible($1, $3)){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
				
			}else if(iscoercible($3, $1)){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				$$ = makeIllegalNode();
			}
			e->loc=currentelement()->loc;
			$$ = e;
		}
|	RelationalExpression INSTANCEOF  ReferenceType
		{
			fprintf(fp, "subu $sp, $sp, 4 #RelationalExpression\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			if($1->rdtype == $3) fprintf(fp, "li $t0, 1\n");
			else fprintf(fp, "li $t0, 0\n");
			fprintf(fp, "sw $t0, 0($sp)\n");
			$$ = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), currentelement()->loc, ANONE, NULL);
			
		}
;

EqualityExpression:
	RelationalExpression
		{
			$$ = $1;
		}
|	EqualityExpression EQUALSEQUALS  RelationalExpression
		{
			fetchint0($1);
			fprintf(fp, "move $t1, $t0 #EqualityExpression\n");
			fetchint0($3);
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
			if(iscoercible($1, $3)){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
				
			}else if(iscoercible($3, $1)){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				$$ = makeIllegalNode();
			}
			e->loc=currentelement()->loc;
			$$ = e;
		}
|	EqualityExpression NOTEQUALS RelationalExpression
		{
			fetchint0($1);
			fprintf(fp, "move $t1, $t0 #EqualityExpression\n");
			fetchint0($3);
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
			if(iscoercible($1, $3)){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
				
			}else if(iscoercible($3, $1)){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				$$ = makeIllegalNode();
			}
			e->loc=currentelement()->loc;
			$$ = e;
		}
;

AndExpression:
	EqualityExpression	{$$ = $1;}
|	AndExpression AND EqualityExpression
		{
			fetchint0($1);
			fprintf(fp, "move $t1, $t0 #AndExpression\n");
			fetchint0($3);
			fprintf(fp, "and $t0, $t1, $t0\n");
			
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "sw $t0, 0($sp)\n");
			
			element* e;
			if(iscoercible($1, $3)){
				e = copyandcoerce($1, $3);
			}else if(iscoercible($3, $1)){
				e = copyandcoerce($3, $1);
			}else{
				printf("line #%d: incompatible types\n", line_number);
				$$ = makeIllegalNode();
			}
			e->loc = currentelement()->loc;
			$$ = e;
		}
;

ExclusiveOrExpression:
	AndExpression	{ $$ = $1;}
|	ExclusiveOrExpression CARET AndExpression
		{
			fetchint0($1);
			fprintf(fp, "move $t1, $t0 #ExclusiveOrExpression\n");
			fetchint0($3);
			fprintf(fp, "xor $t0, $t1, $t0\n");
			
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "sw $t0, 0($sp)\n");
			
			element* e;
			if(iscoercible($1, $3)){
				e = copyandcoerce($1, $3);
			}else if(iscoercible($3, $1)){
				e = copyandcoerce($3, $1);
			}else{
				printf("line #%d: incompatible types\n", line_number);
				$$ = makeIllegalNode();
			}
			e->loc = currentelement()->loc;
			$$ = e;
		}
;

InclusiveOrExpression:
	ExclusiveOrExpression	{$$ = $1;}
|	InclusiveOrExpression OR ExclusiveOrExpression
		{
			fetchint0($1);
			fprintf(fp, "move $t1, $t0 #InclusiveOrExpression\n");
			fetchint0($3);
			fprintf(fp, "or $t0, $t1, $t0\n");
			
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "sw $t0, 0($sp)\n");
			
			element* e;
			if(iscoercible($1, $3)){
				e = copyandcoerce($1, $3);
			}else if(iscoercible($3, $1)){
				e = copyandcoerce($3, $1);
			}else{
				printf("line #%d: incompatible types\n", line_number);
				$$ = makeIllegalNode();
			}
			e->loc = currentelement()->loc;
			$$ = e;
		}
;

ConditionalAndExpression:
	InclusiveOrExpression	{$$ = $1;}
|	ConditionalAndExpression ANDAND InclusiveOrExpression
		{
			fetchint0($1);
			fprintf(fp, "move $t1, $t0 #ConditionalAndExpression\n");
			fetchint0($3);
			fprintf(fp, "and $t0, $t1, $t0\n");
			
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "sw $t0, 0($sp)\n");
			
			element * e;
			if(iscoercible($1, $3)){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else if(iscoercible($3, $1)){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("error line #%d: types not comparable\n", line_number);
				$$ = makeIllegalNode();
			}
			e->loc=currentelement()->loc;
			$$ = e;
		}
;

ConditionalOrExpression:
	ConditionalAndExpression	{$$ = $1;}
|	ConditionalOrExpression OROR ConditionalAndExpression
		{
			fetchint0($1);
			fprintf(fp, "move $t1, $t0 #ConditionalOrExpression\n");
			fetchint0($3);
			fprintf(fp, "or $t0, $t1, $t0\n");
			
			fprintf(fp, "subu $sp, $sp, 4\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			fprintf(fp, "sw $t0, 0($sp)\n");
			
			element * e;
			if(iscoercible($1, $3)){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else if(iscoercible($3, $1)){
				e = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("error line #%d: types not comparable\n", line_number);
				$$ = makeIllegalNode();
			}
			e->loc=currentelement()->loc;
			$$ = e;
		}
;

ConditionalExpression:
	ConditionalOrExpression	{$$ = $1;}
|	ConditionalOrExpression QUESTION Expression COLON ConditionalExpression
		{
			fprintf(fp, "subu $sp, $sp, 4 #ConditionalExpression\n");
			currentelement()->loc +=4;
			if(PDEBUG){
								fprintf(fp, "# loc = %d\n", currentelement()->loc);
							}
			
			fetchint0($1);
			fprintf(fp, "move $s0, $t0");
			fprintf(fp, "li $t1, 0\n");
			
			char* lab = newlabel();
			fprintf(fp, "bgt $s0, $t1, %strue\n", lab);
			fetchint0($5);
			fprintf(fp, "move $t2, $t0\n");
			fprintf(fp, "j %snext\n", lab);
			fprintf(fp, "%strue:\n", lab);
			fetchint0($3);
			fprintf(fp, "move $t2, $t0\n");
			fprintf(fp, "%snext:\n", lab);
			fprintf(fp, "sw $t2, 0($sp)\n");
			
			element* e;
			if(iscoercible($3, $5)){
				e = $5;
			}else if(iscoercible($5, $3)){
				e = $3;
			}else{
				printf("error at line #%d: types not comparable\n", line_number);
				$$ = makeIllegalNode();
			}
			e->loc = currentelement()->loc;
			$$ = e;
		}
;

AssignmentExpression:
	ConditionalExpression	{$$ = $1;}
|	Assignment	{$$ = $1;}
;

Assignment:
	LeftHandSide AssignmentOperator AssignmentExpression
		{
			if($1->amode == REFERENCE || $1->kind==KOBJECT){
				fprintf(fp, "lw $s0, -%d($fp) #Assignment\n", $1->loc);
			}else{
				fprintf(fp, "subu $s0, $fp, %d  #Assignment\n", $1->loc);
			}
			if($3->amode == REFERENCE || $3->kind == KOBJECT){
				fprintf(fp, "lw $s1, -%d($fp)\n", $3->loc);
			}else{
				fprintf(fp, "subu $s1, $fp, %d\n", $3->loc);
			}
			fprintf(fp, "lw $t0, 0($s1)\n");
			fprintf(fp, "sw $t0, 0($s0)\n");
			if(iscoercible($3, $1)){
				$$ = coerce($3, $1);
			}else{
				printf("line #%d: incompatible assignment\n", line_number);
				$$ = makeIllegalNode();
			}
		}
;

LeftHandSide:
	Name
		{
			$$ = findobject(current, $1, KALL);
		}
|	FieldAccess
		{
			$$ = $1;
		}
|	ArrayAccess
		{
			$$ = $1;
		}
;

AssignmentOperator:
	EQUALS
|	ASTERISKEQUALS
|	DIVIDEEQUALS
|	PERCENTEQUALS
|	PLUSEQUALS
|	MINUSEQUALS
|	LEFTSHIFTEQUALS
|	RIGHTSHIFTEQUALS
|	UNRIGHTSHIFTEQUALS
|	ANDEQUALS
|	CARETEQUALS
|	OREQUALS
;

Expression:
	AssignmentExpression	{$$ = $1;}
;

ConstantExpression:
	Expression	{$$ = $1;}
;
%%
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
