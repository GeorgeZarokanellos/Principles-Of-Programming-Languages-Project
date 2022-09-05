all:	test

lex.yy.c:	lexer.l parser.tab.h
	flex lexer.l

test:	lex.yy.c parser.tab.c parser.tab.h
	gcc -o parser parser.tab.c lex.yy.c

parser.tab.c parser.tab.h:	parser.y
	bison -v -d parser.y
