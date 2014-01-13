The command for building the semantic analyser and automatically feeding the test files testN.java is:
$ make
[Output is produced in the files outputN.txt where N is 1 to 5]

Summary of Phase 4

1. Each grammar symbol has been assigned attributes using "struct element". Various members of this struct are assigned values as more and more information is gathered during parsing.

struct element{
	string name;	//name of the symbol
	kindof kind;	//kind viz class, primitive, variable, object, method, constructor
	primdtype pdtype;	//primitive type viz. int, char, byte etc
	struct element* rdtype;	//reference type
	vector<int> dimensions;	//array related information
	void* loc;	//memory location of this object
	accessmod mod;	//modifier viz. public, private, protected
	scope* desc;	//used if this element is class or method or constructor or block
	struct element* superclass;	//inheritance related information
	struct listofelements* arguments;	//arguments, if this is a function
};


2. "struct scope" is meant to keep scope related details

struct scope{
	string lexeme;	//name of the scope
	struct scope* parent;	//parent scope
	element* elem;	//element that points to this scope
	symmap symtbl;	//symbol table of this scope [implemented as hash table using unordered_map container of the C++ STL library]
};

2. The topmost scope of the program has been called 'godscope'. The parent of godscope is NULL. The corresponding element of godscope is named 'godelement'.

3. We have used a hierarchical tree structure of the scopes to enforce the scoping rules. A symbol table is created for each scope.

4. We have tried to implement all the type coercion rules as per the Java-version-7 Specifications (page 110 Chapter 5 conversions and promotions).
	
5. Type coercions has been implemented in the following arthmetic operators: add, subtract, multiply, divide and the assignment operator. The coerced types are of the forms: byte, short, int, long, float, double. The rules of coercions are used in accordance with the Java manual.  

6. Also type coercion has been implemented in methods. The return value of functions must be coercible to the return type of the method. The arguments passed to the function must be coercible to the formal parameters declared.
  
7. Inheritance is single (no multiple inheritance) and multilevel

8. As per the scoping rules of java, multiple declarations of the same variable in the same scope are not allowed in the grammar. Error is reported in all such cases. 

9. But, variables with same names are allowed in different scopes.

10. All methods and constructors related errors like incompatible return types, arguments, redeclarations, constructor name not matching class' name etc have been reported

11. All privacy attributes are respected while accessing class members and error reported if violations occur.

[[Error Handling]]
Whenever there is type error appropriate error messages have been printed.
(a) Checked for the types of left and right hand side of the assignment operator, if the assignment operation is not viable in accordance with the rules then an error message is displayed.
(b) Error message is displayed when the arguement in the while, if, do while. for operation is not found to be boolean.
(c) Checked for the errors in function and array declarations.
(d) Checked for the type mismatch in arthmetic and logical operators.

[[Disambiguation]]
Disambiguating the overloaded operators:- The disambiguation of the overloaded operators such as real+int, float*long, double%int is taken care of while performing various arthematic operators.

[[Test Cases]]
Each test case except test4.java has some errors. All the errors are reported in each case.

Group 10 Members:
Harshit 10290
Jeetesh 10314
Rajiv 10577
Vinit 10807
 
