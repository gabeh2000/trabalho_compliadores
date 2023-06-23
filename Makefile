CC      = gcc
LDFLAGS = -g

all: main 

main: lex.yy.c nico.tab.c
	$(CC) $(LDFLAGS) -o meu_compilador _main.c lex.yy.c y.tab.c node.c -lfl

lex.yy.c: scanner.l tokens.h
	flex scanner.l

nico.tab.c: nico.y node.h
	yacc -d -t nico.y

clean:
	rm -f *.o lex.yy.?
