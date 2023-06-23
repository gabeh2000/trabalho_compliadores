#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "node.h"

/* Programa principal. */
char* progname;
int lineno;

extern FILE* yyin;
int yydebug = 1;
extern int yyparse();
extern Node * syntax_tree;

int main(int argc, char* argv[])
{
	if (argc < 2) {
		printf("uso: %s <input_file>. Try again!\n", argv[0]);
		exit(-1);
	}
	yyin = fopen(argv[1], "r");
	if (!yyin) {
		printf("Uso: %s <input_file>. Could not find %s. Try again!\n",
				argv[0], argv[1]);
		exit(-1);
	}

	progname = argv[0];
    FILE *saida=fopen(argv[2],"w");

	int result = yyparse();

	if(argc == 3) //testing
    //printf("Oi\n");	
	uncompile(saida, syntax_tree);
	else
	{
		if(!result)
			printf("OKAY.\n");
		else
			printf("ERROR.\n");
	}

	return 0;
}

void yyerror(char* s) {
	fprintf(stderr, "%s: %s", progname, s);
	fprintf(stderr, "line %d\n", lineno);
}
