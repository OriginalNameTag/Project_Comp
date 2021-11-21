all:
	flex gocompiler.l
	yacc -d gocompiler.y
	clang-7 *.c -o gocompiler -g

