%error-verbose

%{
  /* Aqui, pode-se inserir qualquer codigo C necessario ah compilacao
   * final do parser. Sera copiado tal como esta no inicio do y.tab.c
   * gerado por Yacc.
   */
	#include <stdio.h>
	#include <stdlib.h>
	#include "node.h"

	extern int yyerror(const char* msg ); 
	extern int yylex();

	extern Node * syntax_tree;

%}

%union {
	char* cadeia;
	struct _node * no;
}

%left '-' '+'
%left '*' '/'
%left AND OR
%right NOT

%token<cadeia> IDF
%token INT
%token DOUBLE
%token REAL

/* demais tokens ...*/

%type<no> code
%type<no> acoes
%type<no> declaracoes
%type<no> declaracao

/* demais types ... */

%start code

 /* A completar com seus tokens - compilar com 'yacc -d' */

%%
code: declaracoes acoes {  $$ = create_node(@1.first_line, code_node, NULL, $1, $2, NULL); syntax_tree = $$;}
    | acoes { $$ = $1; syntax_tree = $$;  }
    ;

/*demais codes ..*/

%%
 /* A partir daqui, insere-se qlqer codigo C necessario.
  */
