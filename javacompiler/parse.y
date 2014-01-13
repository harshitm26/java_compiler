%debug
%{	
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
	struct listofelements* list;
	struct spvec *pspvec;
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
%token BTRUE BFALSE NULLLITERAL
%token ABSTRACT ASSERT BOOLEAN BREAK BYTE CASE CATCH CHAR CLASS CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM EXTENDS FINAL FINALLY FLOAT FOR IF GOTO IMPLEMENTS IMPORT INSTANCEOF INT INTERFACE LONG NATIVE NEW PACKAGE PRIVATE PROTECTED PUBLIC RETURN SHORT STATIC STRICTFP SUPER SWITCH SYNCHRONIZED THIS THROW THROWS TRANSIENT TRY VOID VOLATILE WHILE
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
%type <list> VariableDeclarators
%type <attr> VariableDeclarator
%type <attr> VariableDeclaratorId
%type <attr> VariableInitializer
%type <status> MethodDeclaration
%type <attr> MethodHeader
%type <attr> MethodDeclarator
%type <list> FormalParameterList
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
%type <attr> VariableInitializers
%type <status> Block
%type <status> BlockStatements
%type <status> BlockStatement
%type <status> LocalVariableDeclarationStatement
%type <status> LocalVariableDeclaration
%type <status> Statement
%type <status> StatementNoShortIf
%type <status> StatementWithoutTrailingSubstatement
%type <status> EmptyStatement
%type <status> LabeledStatement
%type <status> LabeledStatementNoShortIf
%type <status> ExpressionStatement
%type <attr> StatementExpression
%type <status> IfThenStatement
%type <status> IfThenElseStatement
%type <status> IfThenElseStatementNoShortIf
%type <status> SwitchStatement
%type <attr> SwitchBlock
%type <attr> SwitchBlockStatementGroups
%type <attr> SwitchBlockStatementGroup
%type <attr> SwitchLabels
%type <attr> SwitchLabel
%type <status> WhileStatement
%type <status> WhileStatementNoShortIf
%type <status> DoStatement
%type <status> ForStatement
%type <status> ForStatementNoShortIf
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
%type <list> ArgumentList
%type <attr> ArrayCreationExpression
%type <pspvec> DimExprs
//%type <attr> DimExpr
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
	CompilationUnit		{	$$ = $1;
							printf("COMPILATION OVER: %d errors found\n", error_count);
							printf("\n\n");
							print();
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
							int* loc = (int*)malloc(sizeof(int));
							*loc = $1;
							$$ = makePrimNode(string(), KLITERAL, TINT, vector<int>(), loc, ANONE, NULL);
						}
|	FLOATLITERAL
						{
							float* loc = (float*)malloc(sizeof(float));
							*loc = $1;
							$$ = makePrimNode(string(), KLITERAL, TFLOAT, vector<int>(), loc, ANONE, NULL);
						}
|	LONGLITERAL
						{
							long* loc = (long*)malloc(sizeof(long));
							*loc = $1;
							$$ = makePrimNode(string(), KLITERAL, TLONG, vector<int>(), loc, ANONE, NULL);
						}
|	DOUBLELITERAL
						{
							double* loc = (double*)malloc(sizeof(double));
							*loc = $1;
							$$ = makePrimNode(string(), KLITERAL, TDOUBLE, vector<int>(), loc, ANONE, NULL);
						}
|	BTRUE
						{
							bool* loc = (bool*)malloc(sizeof(bool));
							*loc = true;
							$$ = makePrimNode(string(), KLITERAL, TBOOLEAN, vector<int>(), loc, ANONE, NULL);
						}
|	BFALSE
						{
							bool* loc = (bool*)malloc(sizeof(bool));
							*loc = false;
							$$ = makePrimNode(string(), KLITERAL, TBOOLEAN, vector<int>(), loc, ANONE, NULL);
						}
|	CHARACTERLITERAL
						{
							char* loc = (char*)malloc(sizeof(char));
							*loc = $1;
							$$ = makePrimNode(string(), KLITERAL, TCHAR, vector<int>(), loc, ANONE, NULL);
						}
|	STRINGLITERAL
						{
							string str = string($1);
							$$ = makePrimNode(string(), KLITERAL, TSTRING, vector<int>(), &str, ANONE, NULL);
						}
|	NULLLITERAL
						{
							int** loc = (int**)malloc(sizeof(int));
							*loc = 0;
							$$ = makePrimNode(string(), KLITERAL, TVOID, vector<int>(), loc, ANONE, NULL);
							$$->dimensions.push_back(1);
							
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
		element* newelem = makeRefNode(string($2), KCLASS, NULL, vector<int>(), NULL, APUBLIC, NULL, NULL, NULL);
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
										
		element* newelem = makeRefNode(string($2), KCLASS, NULL, vector<int>(), NULL, APUBLIC, NULL, $3, NULL);
		current->symtbl.insert({string($2), newelem});
		scope* newscope = createScope(string($2), current, newelem);
		newelem->desc = newscope;
		current = newscope;
		}
	ClassBody
		{
			printsymtbl(current->symtbl);
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
				
		element* newelem = makeRefNode(string($3), KCLASS, NULL, vector<int>(), NULL, mod, NULL, NULL, NULL);
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
		element* newelem = makeRefNode(string($3), KCLASS, NULL, vector<int>(), NULL, mod, NULL, $4, NULL);
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
			$$ = $1;
		}
;

// 19.8.2
FieldDeclaration:
			Type VariableDeclarators SEMICOLON
		{	
			bool ret = coercelist( $2, $1);
			listofelements* e = $2;
			while(e!=NULL){
				e->elem->kind = KVARIABLE;
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
			bool ret = coercelist( $3, $2);
			listofelements* e = $3;
			while(e!=NULL){
				e->elem->kind = KVARIABLE;
				e=e->next;
			}
			$$ = ret;
		}
;

VariableDeclarators:
	VariableDeclarator
		{
			listofelements* newlist= new listofelements();
			newlist->elem = $1;
			newlist->next = NULL;
			$$ = newlist;
		}
|	VariableDeclarators COMMA VariableDeclarator
		{
			listofelements* list = $1;
			while(list->next!=NULL) list = list->next;
			listofelements* newdeclaration= new listofelements();
			newdeclaration->elem = $3;
			newdeclaration->next = NULL;
			list->next = newdeclaration;
			$$ = $1;
		}
			
;

VariableDeclarator:
	VariableDeclaratorId
		{
			$$ = $1;
		}
|	VariableDeclaratorId EQUALS VariableInitializer
		{
			if(!iscoercible($1, $3)){
				printf("line #%d: incompatible types: \n",line_number);
				$$ = makeIllegalNode();
			}else{
				$$ = coerce($1, $3);
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
				ehere(0);
			}
			current->symtbl.insert({string($1), newelem});
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
			$$ = $1;
		}
;

//19.8.3

MethodDeclaration:
	MethodHeader
	MethodBody
		{
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
			element* func = makePrimNode(string($1), KPRIMFUNCTION, TUNKNOWN, vector<int>(), NULL, APUBLIC, NULL);
			
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
			element* func = makePrimNode(string($1), KPRIMFUNCTION, TUNKNOWN, vector<int>(), NULL, APUBLIC, NULL);
			
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
		      ConstructorBody
		{
			revertscope();
			if($1 == NULL || $2 == ERROR){
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
		}
			ConstructorBody
		{
			revertscope();
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
			element* func = makePrimNode($1->name, KCONSTRUCTOR, TUNKNOWN, vector<int>(), NULL, APUBLIC, NULL);
			
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
			element* func = makePrimNode(string($1->name), KCONSTRUCTOR, TUNKNOWN, vector<int>(), NULL, APUBLIC, NULL);
			
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
		}		
	FormalParameterList RIGHTROUNDBRACE
		{
			listofelements* param = $4;
			while(param!=NULL){
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

ArrayInitializer:
	LEFTCURLYBRACE VariableInitializers COMMA RIGHTCURLYBRACE
		{
			$$ = $2;
		}
|	LEFTCURLYBRACE VariableInitializers 	  RIGHTCURLYBRACE
		{
			$$ = $2;
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
			element* newelem = copyelement($1);
			newelem->dimensions.insert(newelem->dimensions.begin(), 1);
			$$ = newelem;
		}
|	VariableInitializers COMMA VariableInitializer
		{
			if(equal($1->dimensions.begin() +1, $1->dimensions.end(), $3->dimensions.begin())){
				$1->dimensions.front() += 1;
				$$ = $1;
			}else{
				printf("error at line #%d: incompatible types\n", line_number);
				$$ = makeIllegalNode();
			}
		}
;

Block:
	LEFTCURLYBRACE 
		{
			makeblockscope();
		}
		BlockStatements 
		{
			revertscope();
		}
		RIGHTCURLYBRACE
		{
			$$ = $3;
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
|	ClassDeclaration
		{
			$$ = $1;
		}
;

LocalVariableDeclaration:
	Type VariableDeclarators
		{
			
			if(!iscoerciblelist($2, $1)){
				printf("line# %d: incompatible types\n", line_number);
				ehere(14);
				$$ = ERROR;
				
			}else{
				bool ret = coercelist($2, $1);
				listofelements* e = $2;
				while(e!=NULL){
					e->elem->kind = KVARIABLE;
					e=e->next;
				}
				$$ = ret;
			}
		}

;

Statement:
	StatementWithoutTrailingSubstatement	{$$ = $1;}
|	LabeledStatement	{$$ = $1;}
|	IfThenStatement	{$$ = $1;}
|	IfThenElseStatement	{$$ = $1;}
|		WhileStatement	{$$ =$1;}
|		ForStatement	{$$ =$1;}
;

StatementNoShortIf:
	StatementWithoutTrailingSubstatement	{$$ = $1;}
|	LabeledStatementNoShortIf	{$$ = $1;}
|	IfThenElseStatementNoShortIf	{$$ = $1;}
|	WhileStatementNoShortIf	{$$ =$1;}
|	ForStatementNoShortIf	{$$ =$1;}

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

LabeledStatementNoShortIf:
	Identifier COLON StatementNoShortIf	{$$ = $3;}
;

ExpressionStatement:
	StatementExpression SEMICOLON
		{
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

IfThenStatement:
	IF LEFTROUNDBRACE Expression RIGHTROUNDBRACE 
		{
			makeblockscope();
		}
	Statement
		{
			revertscope();
			if($3->pdtype!=TBOOLEAN){
				printf("line #%d: expression must be boolean\n", line_number);
				$$ = ERROR;
				ehere(16);
			}else if($6==ERROR){
				$$ = ERROR;
				here(17);
			}else{
				$$ = OKAY;
			}
		}
;

IfThenElseStatement:
	IF LEFTROUNDBRACE Expression RIGHTROUNDBRACE
		{
			makeblockscope();
		}
	StatementNoShortIf 
		{
			revertscope();
		}
	ELSE 
		{
			makeblockscope();
		}	
	Statement
		{
			revertscope();
			if($3->pdtype!=TBOOLEAN){
				printf("line #%d: expression must be boolean\n", line_number);
				$$ = ERROR;
				ehere(18);
			}else if($6==ERROR || $10 ==ERROR){
				$$ = ERROR;
				here(19);
			}else{
				$$ = OKAY;
			}
		}
;

IfThenElseStatementNoShortIf:
	IF LEFTROUNDBRACE Expression RIGHTROUNDBRACE 
		{
			makeblockscope();
		}
	StatementNoShortIf
		{
			revertscope();
		}
	 ELSE 
		{
			makeblockscope();
		}
	 StatementNoShortIf
	 	{
			revertscope();
			if($3->pdtype!=TBOOLEAN){
				printf("line #%d: expression must be boolean\n", line_number);
				$$ = ERROR;
				ehere(20);
			}else if($6==ERROR || $10==ERROR){
				$$ = ERROR;
				here(21);
			}else{
				$$ = OKAY;
			}
		}
;

SwitchStatement:
	SWITCH LEFTROUNDBRACE Expression RIGHTROUNDBRACE SwitchBlock
		{
			if($5->kind == KILLEGAL){
				printf("line #%d: incompatible types used in switch block\n", line_number);
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
	WHILE LEFTROUNDBRACE Expression RIGHTROUNDBRACE 
		{
			makeblockscope();
		}
	Statement
		{
			//printscopehierarchy();
			
			revertscope();
			if($3->pdtype != TBOOLEAN){
				printf("line #%d: expression must be boolean\n", line_number);
				$$ = ERROR;
				ehere(26);
			}else{
				$$ = $6;
			}
		}
;

WhileStatementNoShortIf:
	WHILE LEFTROUNDBRACE Expression RIGHTROUNDBRACE 
		{
			makeblockscope();
		}
	StatementNoShortIf
		{
			revertscope();
			if($3->pdtype != TBOOLEAN){
				printf("line #%d: expression must be boolean\n", line_number);
				$$ = ERROR;
				ehere(27);
			}else{
				$$ = $6;
			}
		}
;

DoStatement:
	DO
		{
			makeblockscope();
		}
	Statement
		{
			revertscope();
		}
	WHILE LEFTROUNDBRACE Expression RIGHTROUNDBRACE SEMICOLON
		{
			if($7->pdtype != TBOOLEAN){
				printf("line #%d: expression must be boolean\n", line_number);
				$$ = ERROR;
				ehere(28);
			}else{
				$$ = $3;
			}
		}
;

ForStatement:
	FOR LEFTROUNDBRACE ForInit SEMICOLON Expression SEMICOLON ForUpdate RIGHTROUNDBRACE 
		{
			makeblockscope();
		}
	Statement
		{	revertscope();
			$$ = $3 && $7 && $10 && ($5->pdtype !=TBOOLEAN);
		}
|	FOR LEFTROUNDBRACE ForInit SEMICOLON Expression SEMICOLON 			RIGHTROUNDBRACE 
		{
			makeblockscope();
		}
	Statement
		{	
			revertscope();
			$$ = $3 && $9 && ($5->pdtype !=TBOOLEAN);
		}
|	FOR LEFTROUNDBRACE ForInit SEMICOLON 			SEMICOLON ForUpdate RIGHTROUNDBRACE 
		{
			makeblockscope();
		}
Statement
		{	
			revertscope();
			$$ = $3 && $6 && $9;	
		}
|	FOR LEFTROUNDBRACE ForInit SEMICOLON 			SEMICOLON 			RIGHTROUNDBRACE 
		{
			makeblockscope();
		}
Statement
		{	
			revertscope();
			$$ = $3 && $8;
		}
|	FOR LEFTROUNDBRACE 		   SEMICOLON Expression SEMICOLON ForUpdate RIGHTROUNDBRACE 
		{
			makeblockscope();
		}
Statement
		{	
			revertscope();
			$$ = $6 && $9 && ($4->pdtype !=TBOOLEAN);
		}
|	FOR LEFTROUNDBRACE 		   SEMICOLON Expression SEMICOLON 			RIGHTROUNDBRACE 
		{
			makeblockscope();
		}
Statement
		{	
			revertscope();
			$$ = $8 && ($4->pdtype !=TBOOLEAN);
		}
|	FOR LEFTROUNDBRACE 		   SEMICOLON 			SEMICOLON ForUpdate RIGHTROUNDBRACE 
		{
			makeblockscope();
		}
Statement
		{	
			revertscope();
			$$ = $5 && $8;	
		}
|	FOR LEFTROUNDBRACE 		   SEMICOLON 			SEMICOLON 			RIGHTROUNDBRACE 
		{
			makeblockscope();
		}
Statement
		{
			revertscope();
			$$ = $7;	
		}
;



ForStatementNoShortIf:
	FOR LEFTROUNDBRACE ForInit SEMICOLON Expression SEMICOLON ForUpdate RIGHTROUNDBRACE 
		{
			makeblockscope();
		}
	StatementNoShortIf
		{	revertscope();
			$$ = $3 && $7 && $10 && ($5->pdtype !=TBOOLEAN);
		}
|	FOR LEFTROUNDBRACE ForInit SEMICOLON Expression SEMICOLON 			RIGHTROUNDBRACE 
		{
			makeblockscope();
		}
	StatementNoShortIf
		{	
			revertscope();
			$$ = $3 && $9 && ($5->pdtype !=TBOOLEAN);
		}
|	FOR LEFTROUNDBRACE ForInit SEMICOLON 			SEMICOLON ForUpdate RIGHTROUNDBRACE 
		{
			makeblockscope();
		}
StatementNoShortIf
		{	
			revertscope();
			$$ = $3 && $6 && $9;	
		}
|	FOR LEFTROUNDBRACE ForInit SEMICOLON 			SEMICOLON 			RIGHTROUNDBRACE 
		{
			makeblockscope();
		}
StatementNoShortIf
		{	
			revertscope();
			$$ = $3 && $8;
		}
|	FOR LEFTROUNDBRACE 		   SEMICOLON Expression SEMICOLON ForUpdate RIGHTROUNDBRACE 
		{
			makeblockscope();
		}
StatementNoShortIf
		{	
			revertscope();
			$$ = $6 && $9 && ($4->pdtype !=TBOOLEAN);
		}
|	FOR LEFTROUNDBRACE 		   SEMICOLON Expression SEMICOLON 			RIGHTROUNDBRACE 
		{
			makeblockscope();
		}
StatementNoShortIf
		{	
			revertscope();
			$$ = $8 && ($4->pdtype !=TBOOLEAN);
		}
|	FOR LEFTROUNDBRACE 		   SEMICOLON 			SEMICOLON ForUpdate RIGHTROUNDBRACE 
		{
			makeblockscope();
		}
StatementNoShortIf
		{	
			revertscope();
			$$ = $5 && $8;	
		}
|	FOR LEFTROUNDBRACE 		   SEMICOLON 			SEMICOLON 			RIGHTROUNDBRACE 
		{
			makeblockscope();
		}
StatementNoShortIf
		{
			revertscope();
			$$ = $7;	
		}
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
|	THIS	{$$ = currentelement();}
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
						here(1966);
						$$ = makeRefNode(string(), KOBJECT, $2, vector<int>(), NULL, ANONE, NULL, NULL, NULL);
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
						$$ = makeRefNode(string(), KOBJECT, $2, vector<int>(), NULL, ANONE, NULL, NULL, NULL);
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
			vector<int> *vec1 = $3->pvec, *vec2 = $4->pvec;
			vec1->insert(vec1->end(), vec2->begin(), vec2->end());
			$$ = makePrimNode(string(), KVARIABLE, $2->pdtype, *vec1, NULL, ANONE, NULL);
		}
|	NEW PrimitiveType DimExprs
		{
			$$ = makePrimNode(string(), KVARIABLE, $2->pdtype, *($3->pvec), NULL, ANONE, NULL);
		}
|	NEW ClassOrInterfaceType DimExprs Dims
		{
			vector<int> *vec1 = $3->pvec, *vec2=$4->pvec;
			vec1->insert(vec1->end(), vec2->begin(), vec2->end());
			$$ = makeRefNode(string(), KOBJECT, $2->rdtype, *vec1, NULL, ANONE, NULL, NULL, NULL);
		}
|	NEW ClassOrInterfaceType DimExprs
		{
			$$ = makeRefNode(string(), KOBJECT, $2->rdtype, *$3->pvec, NULL, ANONE, NULL, NULL, NULL);
		}
;

DimExprs:
	DimExpr
		{
			spvec* spv = (spvec*)malloc(sizeof(spvec));
			vector<int> vec (1, 0);
			spv->pvec = &vec;
			$$ = spv; 
		}
|	DimExprs DimExpr
		{
			(*$1->pvec).push_back(0);
		}
;


DimExpr:
	LEFTSQUAREBRACE Expression RIGHTSQUAREBRACE
		{
			if($2->kind != KVARIABLE && !iscoercible($2, makePrimNode(string(), KPRIMITIVE, TINT, vector<int>(), NULL, ANONE, NULL))){
				printf("error at line #%d: expecting expressions convertible to int\n", line_number);
				ehere();
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
			if($1->desc == NULL){
				printf("error at line #%d: invalid access\n", line_number);
				$$ = makeIllegalNode();
			}else{
				symmap::iterator it = $1->desc->symtbl.find($3);
				if(it == $1->desc->symtbl.end()){
					printf("line #%d: member doesn't exist\n");
					$$ = makeIllegalNode();
				}else{
					$$ = it->second;
				}
			}
		}
|	SUPER DOT Identifier
		{
			element* sup = currentelement()->superclass;
			symmap::iterator it = sup->desc->symtbl.find($3);
			if(it == sup->desc->symtbl.end()){
				printf("line #%d: member doesn't exist\n");
				$$ = makeIllegalNode();
			}else{
				$$ = it->second;
			}
		}
;

MethodInvocation:
	Name LEFTROUNDBRACE ArgumentList RIGHTROUNDBRACE
		{
			element* func = findtype(current, $1);
			//ASSERT(func->kind == KPRIMFUNCTION || func->kind == KREFFUNCTION);
			if(iscoerciblelisttolist($3, func->arguments)){
				if(func->kind == KPRIMFUNCTION){
					$$ = makePrimNode(string(), KVARIABLE, func->pdtype, vector<int>(), NULL, ANONE, NULL);
				}else if(func->kind == KREFFUNCTION){
					$$ = makeRefNode(string(), KOBJECT, func->rdtype, vector<int>(), NULL, ANONE, NULL, NULL, NULL);
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
			element* func = findtype(current, $1);
			//assert(func->kind == KPRIMFUNCTION || func->kind == KREFFUNCTION);
			if(iscoerciblelist(func->arguments, NULL)){
				if(func->kind == KPRIMFUNCTION){
					$$ = makePrimNode(string(), KVARIABLE, func->pdtype, vector<int>(), NULL, ANONE, NULL);
				}else if(func->kind == KREFFUNCTION){
					$$ = makeRefNode(string(), KOBJECT, func->rdtype, vector<int>(), NULL, ANONE, NULL, NULL, NULL);
				}else{
					printf("line #%d: not a function\n", line_number);
					$$ = makeIllegalNode();
				}
			}else{
				printf("line #%d: imcompatible arguments\n", line_number);
				$$ = makeIllegalNode();
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
				if(!iscoerciblelist(func->arguments, NULL)){
					printf("line #%d: incompatible arguments\n", line_number);
					$$ = makeIllegalNode();
				}else{
					if(func->kind == KPRIMFUNCTION){
						$$ = makePrimNode(string(), KVARIABLE, func->pdtype, vector<int>(), NULL, ANONE, NULL);
					}else if(func->kind == KREFFUNCTION){
						$$ = makeRefNode(string(), KOBJECT, func->rdtype, vector<int>(), NULL, ANONE, NULL, NULL, NULL);
					}else{
						printf("line #%d: not a function\n", line_number);
						$$ = makeIllegalNode();
					}
				}
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
				if(!iscoerciblelisttolist($5, func->arguments)){
					printf("line #%d: incompatible arguments\n", line_number);
					$$ = makeIllegalNode();
				}else{
					if(func->kind == KPRIMFUNCTION){
						$$ = makePrimNode(string(), KVARIABLE, func->pdtype, vector<int>(), NULL, ANONE, NULL);
					}else if(func->kind == KREFFUNCTION){
						$$ = makeRefNode(string(), KOBJECT, func->rdtype, vector<int>(), NULL, ANONE, NULL, NULL, NULL);
					}else{
						printf("line #%d: not a function\n", line_number);
						$$ = makeIllegalNode();
					}
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
						$$ = makePrimNode(string(), KVARIABLE, func->pdtype, vector<int>(), NULL, ANONE, NULL);
					}else if(func->kind == KREFFUNCTION){
						$$ = makeRefNode(string(), KOBJECT, func->rdtype, vector<int>(), NULL, ANONE, NULL, NULL, NULL);
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
						$$ = makePrimNode(string(), KVARIABLE, func->pdtype, vector<int>(), NULL, ANONE, NULL);
					}else if(func->kind == KREFFUNCTION){
						$$ = makeRefNode(string(), KOBJECT, func->rdtype, vector<int>(), NULL, ANONE, NULL, NULL, NULL);
					}else{
						printf("line #%d: not a function\n", line_number);
						$$ = makeIllegalNode();
					}
				}
			}
		}

;

ArrayAccess:
	Name LEFTSQUAREBRACE Expression RIGHTSQUAREBRACE
		{
			element* elem = findtype(current, $1);
			//ASSERT(elem->kind == KVARIABLE || elem->kind == KOBJECT);
			if(elem==NULL){
				printf("line #%d: array not accessible\n", line_number);
				$$ = makeIllegalNode();
			}else if(!iscoercible($3, makePrimNode(string(), KPRIMITIVE, TINT, vector<int>(), NULL, ANONE, NULL))){
				printf("line #%d: expecting expression convertible to int\n", line_number);
				$$ = makeIllegalNode();
			}else{
				if(elem->kind == KVARIABLE){
					vector<int> vec (elem->dimensions.begin()+1, elem->dimensions.end());
					$$ = makePrimNode(string(), KPRIMITIVE, elem->pdtype, vec, NULL, ANONE, NULL);
				}else if(elem->kind == KOBJECT){
					vector<int> vec (elem->dimensions.begin()+1, elem->dimensions.end());
					$$ = makeRefNode(string(), KOBJECT, elem->rdtype, vec, NULL, ANONE, NULL, NULL, NULL);
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
					vector<int> vec (elem->dimensions.begin()+1, elem->dimensions.end());
					$$ = makePrimNode(string(), KPRIMITIVE, elem->pdtype, vec, NULL, ANONE, NULL);
				}else if(elem->kind == KOBJECT){
					vector<int> vec (elem->dimensions.begin()+1, elem->dimensions.end());
					$$ = makeRefNode(string(), KOBJECT, elem->rdtype, vec, NULL, ANONE, NULL, NULL, NULL);
				}
			}
		}
;

PostfixExpression:
	Primary	{$$ = $1;}
|	Name	{$$ = findtype(current, $1);}
|	PostIncrementExpression	{$$ = $1;}
|	PostDecrementExpression	{$$ = $1;}
;

PostIncrementExpression:
	PostfixExpression PLUSPLUS 	{$$ = $1;}
;

PostDecrementExpression:
	PostfixExpression MINUSMINUS	{$$ = $1;}
;

UnaryExpression:
	PreIncrementExpression	{$$ = $1;}
|	PreDecrementExpression	{$$ = $1;}
|	PLUS  UnaryExpression	{$$ = $2;}
|	MINUS  UnaryExpression	{$$ = $2;}
|	UnaryExpressionNotPlusMinus	{$$ = $1;}
;

PreIncrementExpression:
	PLUSPLUS  UnaryExpression	{$$ = $2;}
;

PreDecrementExpression:
	MINUSMINUS UnaryExpression	{$$ = $2;}
;
UnaryExpressionNotPlusMinus:
	PostfixExpression	{$$ = $1;}
|	TILDE UnaryExpression	{$$ = $2;}
|	NOT UnaryExpression
		{
			if(!iscoercible($2, makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL))){
				printf("line #%d: expected boolean expression after !\n", line_number);
				$$ = makeIllegalNode();
			}else{
				$$ = $2;
			}
		}
|	CastExpression	{$$ = $1;}
;

CastExpression:
	LEFTROUNDBRACE PrimitiveType Dims RIGHTROUNDBRACE UnaryExpression
		{
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
				$$ = copyandcoerce($4, $2);
			}else{
				printf("line #%d: type not coercible\n", line_number);
				$$ = makeIllegalNode();
			}
		}	
|	LEFTROUNDBRACE Expression RIGHTROUNDBRACE UnaryExpressionNotPlusMinus
		{
			if(iscoercible($4, $2)){
				$$ = copyandcoerce($4, $2);
			}else{
				printf("line #%d: type not coercible\n", line_number);
				$$ = makeIllegalNode();
			}
		}	
|	LEFTROUNDBRACE Name Dims RIGHTROUNDBRACE UnaryExpressionNotPlusMinus
		{
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
			if(iscoercible($1, $3)){
				$$ = copyandcoerce($1, $3);
			}else if(iscoercible($3, $1)){
				$$ = copyandcoerce($3, $1);
			}else{
				printf("line #%d: incompatible types\n", line_number);
				$$ = makeIllegalNode();
			}
		}
|	MultiplicativeExpression DIVIDE  UnaryExpression
		{
			if(iscoercible($1, $3)){
				$$ = copyandcoerce($1, $3);
			}else if(iscoercible($3, $1)){
				$$ = copyandcoerce($3, $1);
			}else{
				printf("line #%d: incompatible types\n", line_number);
				$$ = makeIllegalNode();
			}
		}
|	MultiplicativeExpression PERCENT  UnaryExpression
		{
			if(iscoercible($1, $3)){
				$$ = copyandcoerce($1, $3);
			}else if(iscoercible($3, $1)){
				$$ = copyandcoerce($3, $1);
			}else{
				printf("line #%d: incompatible types\n", line_number);
				$$ = makeIllegalNode();
			}
		}
;

AdditiveExpression:
	MultiplicativeExpression	{$$ = $1;}
|	AdditiveExpression PLUS  MultiplicativeExpression
		{
			if(iscoercible($1, $3)){
				$$ = copyandcoerce($1, $3);
			}else if(iscoercible($3, $1)){
				$$ = copyandcoerce($3, $1);
			}else{
				printf("line #%d: incompatible types\n", line_number);
				$$ = makeIllegalNode();
			}
		}
|	AdditiveExpression MINUS  MultiplicativeExpression
		{
			if(iscoercible($1, $3)){
				$$ = copyandcoerce($1, $3);
			}else if(iscoercible($3, $1)){
				$$ = copyandcoerce($3, $1);
			}else{
				printf("line #%d: incompatible types\n", line_number);
				$$ = makeIllegalNode();
			}
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
				$$ = $1;
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
				$$ = $1;
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
				$$ = $1;
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
			if(iscoercible($1, $3)){
				$$ = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else if(iscoercible($3, $1)){
				$$ = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				$$ = makeIllegalNode();
			}
		}
|	RelationalExpression GREATER ShiftExpression
		{
			if(iscoercible($1, $3)){
				$$ = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else if(iscoercible($3, $1)){
				$$ = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				$$ = makeIllegalNode();
			}
		}
|	RelationalExpression GREATEQUALS ShiftExpression
		{
			if(iscoercible($1, $3)){
				$$ = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else if(iscoercible($3, $1)){
				$$ = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				$$ = makeIllegalNode();
			}
		}
|	RelationalExpression LESSEQUALS ShiftExpression
		{
			if(iscoercible($1, $3)){
				$$ = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else if(iscoercible($3, $1)){
				$$ = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				$$ = makeIllegalNode();
			}
		}
|	RelationalExpression INSTANCEOF  ReferenceType
		{
			$$ = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
		}
;

EqualityExpression:
	RelationalExpression
		{
			$$ = $1;
		}
|	EqualityExpression EQUALSEQUALS  RelationalExpression
		{
			if(iscoercible($1, $3)){
				$$ = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else if(iscoercible($3, $1)){
				$$ = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				$$ = makeIllegalNode();
			}
		}
|	EqualityExpression NOTEQUALS RelationalExpression
		{
			if(iscoercible($1, $3)){
				$$ = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else if(iscoercible($3, $1)){
				$$ = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				$$ = makeIllegalNode();
			}
		}
;

AndExpression:
	EqualityExpression	{$$ = $1;}
|	AndExpression AND EqualityExpression
		{
			if(iscoercible($1, $3)){
				$$ = $3;
			}else if(iscoercible($3, $1)){
				$$ = $3;
			}else{
				printf("line #%d: types not comparable\n", line_number);
				$$ = makeIllegalNode();
			}
		}
;

ExclusiveOrExpression:
	AndExpression	{ $$ = $1;}
|	ExclusiveOrExpression CARET AndExpression
		{
			if(iscoercible($1, $3)){
				$$ = $3;
			}else if(iscoercible($3, $1)){
				$$ = $1;
			}else{
				printf("line #%d: types not comparable\n", line_number);
				$$ = makeIllegalNode();
			}
		}
;

InclusiveOrExpression:
	ExclusiveOrExpression	{$$ = $1;}
|	InclusiveOrExpression OR ExclusiveOrExpression
		{
			if(iscoercible($1, $3)){
				$$ = $3;
			}else if(iscoercible($3, $1)){
				$$ = $1;
			}else{
				printf("line #%d: types not comparable\n", line_number);
				$$ = makeIllegalNode();
			}
		}
;

ConditionalAndExpression:
	InclusiveOrExpression	{$$ = $1;}
|	ConditionalAndExpression ANDAND InclusiveOrExpression
		{
			if(iscoercible($1, $3)){
				$$ = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else if(iscoercible($3, $1)){
				$$ = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				$$ = makeIllegalNode();
			}
		}
;

ConditionalOrExpression:
	ConditionalAndExpression	{$$ = $1;}
|	ConditionalOrExpression OROR ConditionalAndExpression
		{
			if(iscoercible($1, $3)){
				$$ = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else if(iscoercible($3, $1)){
				$$ = makePrimNode(string(), KPRIMITIVE, TBOOLEAN, vector<int>(), NULL, ANONE, NULL);
			}else{
				printf("line #%d: types not comparable\n", line_number);
				$$ = makeIllegalNode();
			}
		}
;

ConditionalExpression:
	ConditionalOrExpression	{$$ = $1;}
|	ConditionalOrExpression QUESTION Expression COLON ConditionalExpression
		{
			if(iscoercible($3, $5)){
				$$ = $5;
			}else if(iscoercible($5, $3)){
				$$ = $3;
			}else{
				printf("line #%d: types not comparable\n", line_number);
				$$ = makeIllegalNode();
			}
		}
;

AssignmentExpression:
	ConditionalExpression	{$$ = $1;}
|	Assignment	{$$ = $1;}
;

Assignment:
	LeftHandSide AssignmentOperator AssignmentExpression
		{
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
			$$ = findtype(current, $1);
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
