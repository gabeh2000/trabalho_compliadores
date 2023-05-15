CC      = gcc
LDFLAGS = -g

all: main 

main: lex.yy.c nico.tab.c
	$(CC) $(LDFLAGS) -o meu_compilador _main.c nico.tab.c lex.yy.c node.c -lfl

lex.yy.c: scanner.l tokens.h
	flex scanner.l

nico.tab.c: nico.y node.h
	yacc -d nico.y

clean:
	rm -f *.o lex.yy.?
