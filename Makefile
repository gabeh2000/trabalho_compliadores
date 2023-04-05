CC      = gcc
LDFLAGS = -g

all: main 

main: lex.yy.c
	$(CC) $(LDFLAGS) -o meu_compilador main.c lex.yy.c -lfl

lex.yy.c: scanner.l tokens.h
	flex scanner.l

clean:
	rm -f *.o lex.yy.?
