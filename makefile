all:
	flex gocompiler.l
	clang-7 lex.yy.c -o gocompiler
	rm lex.yy.c

	yacc  gocompiler.y
	clang-7 yacc.yy.c -d gocompiler
	rm yacc.yy.c


