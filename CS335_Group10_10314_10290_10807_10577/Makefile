all:	

	flex tokenize.l
	#~ yacc parse.y -Wall -k  --report=all -g -x -d -t
	yacc parse.y -Wnone -k  --report=all -g -x -d -t
	g++ lex.yy.c y.tab.c lib.c -o compiler -pg -w -std=c++0x
	#~ xsltproc /usr/share/bison/xslt/xml2xhtml.xsl y.xml  >parse.html
	
.PHONY: compile
compile:
	#~ ./compiler < ./test/1.java 1> ./test/1.txt 2> ./test/1.err
	#~ ./compiler < ./test/2.java 1> ./test/2.txt 2> ./test/2.err
	#~ ./compiler < ./test/3.java 1> ./test/3.txt 2> ./test/3.err
	./compiler < ./test/4.java 1> ./test/4.txt 2> ./test/4.err
	cp compiled.asm ./test/4.asm
	./compiler < ./test/5.java 1> ./test/5.txt 2> ./test/5.err
	cp compiled.asm ./test/5.asm
	./compiler < ./test/6.java 1> ./test/6.txt 2> ./test/6.err
	cp compiled.asm ./test/6.asm
	./compiler < ./test/7.java 1> ./test/7.txt 2> ./test/7.err
	cp compiled.asm ./test/7.asm
	./compiler < ./test/8.java 1> ./test/8.txt 2> ./test/8.err
	cp compiled.asm ./test/8.asm

run4:
	spim load "./test/4.asm"
run5:
	spim load "./test/5.asm"
run6:
	spim load "./test/6.asm"
run7:
	spim load "./test/7.asm"
run8:
	spim load "./test/8.asm"

.PHONY: error
error:
	./compiler < ./error/1.java 1> ./error/1.txt 2> ./error/1.err
	./compiler < ./error/2.java 1> ./error/2.txt 2> ./error/2.err
	./compiler < ./error/3.java 1> ./error/3.txt 2> ./error/3.err
	
