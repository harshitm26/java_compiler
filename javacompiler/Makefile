all:
	clear
	clear
	flex tokenize.l
	yacc parse.y -Wall -k  --report=all -g -x -d -t
	g++ lex.yy.c y.tab.c lib.c -o lexer -pg -w -std=c++0x
	#~ xsltproc /usr/share/bison/xslt/xml2xhtml.xsl y.xml  >parse.html
	./lexer < ./test/1.java 1> ./test/1.txt 2> ./test/1.err
	./lexer < ./test/2.java 1> ./test/2.txt 2> ./test/2.err
	./lexer < ./test/3.java 1> ./test/3.txt 2> ./test/3.err
