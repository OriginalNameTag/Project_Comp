all:
	flex gocompiler.l
	clang-7 lex.yy.c -o gocompiler
	rm lex.yy.c

