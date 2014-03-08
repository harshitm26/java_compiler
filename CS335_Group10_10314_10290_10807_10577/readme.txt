Compiler for Java
Group 10
Jeetesh 10314, Harshit 10290, Vinit 10807, Rajiv 10577

files
1. tokenize.h, tokenize.l
2. parse.y
3. lib.c, lib.h

functionality test files
	./test/n.java where 4<=n<=8
	Compiler output: ./test/n.txt where 4<=n<=8
	Assembly code: ./test/n.asm where 4<=n<=8
	Error Debuggin code: ./test/n.err where 4<=n<=8

error recovery test files
	./error/n.java where 1<=n<=3
	Compiler output: ./error/n.txt where 1<=n<=3
	Assembly code: ./error/n.asm where 1<=n<=3
	Error Debuggin code: ./error/n.err where 1<=n<=3
	
How to run? (Please browse through the Makefile)
> make 
> make compile
> make error
> make runi [where 4<=i<=8]
