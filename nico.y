%define parse.error verbose

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
%token INT
%token DOUBLE
%token FLOAT
%token CHAR
%token OR
%token AND
%token IF
%token ELSE
%token FOR
%token WHILE
%token ATRIB
%token PAROPN
%token PARCLOSE
%token KOPN
%token KCLOSE
%token SEMICOLON
%token NOT
%token PLUS
%token MIN
%token AST
%token BAR
%token GREAT
%token LESS
%token EQ
%token LE
%token GE
%token NE

%union {
	char* cadeia;
	struct _node * no;
}

%left '-' '+'
%left '*' '/'
%left AND OR
%right NOT


%token<cadeia> IDF
%token<cadeia> VALOR



/* demais tokens ...*/

%type<no> code
%type<no> acoes
%type<no> declaracoes
%type<no> declaracao
%type<no> tipo
%type<no> for
%type<no> while
%type<no> if
%type<no> att
%type<no> expressao
%type<no> expr
%type<no> AUX_expr
%type<no> and_or
%type<no> comparador
%type<no> calc
/* demais types ... */

%start code

 /* A completar com seus tokens - compilar com 'yacc -d' */

%%
code: declaracoes acoes {  $$ = create_node(@1.first_line, code_node, NULL, $1, $2, NULL); syntax_tree = $$;}
    | acoes { $$ = $1; syntax_tree = $$;  }
    ;

declaracoes: declaracao { $$ = create_node(@1.first_line, declaracoes_node, NULL, $1, NULL);} ;

declaracao: tipo IDF SEMICOLON { Node *no_IDF = create_node(@1.first_line, declaracao_node, $2, NULL);
	$$ = create_node(@1.first_line, declaracao_node, NULL, $1, no_IDF, $3, NULL);} 
	| tipo IDF ATRIB VALOR SEMICOLON {$$ = create_node(@1.first_line, declaracao_node, NULL, $1, $2, $3, $4, NULL);} ;

tipo: INT {$$ = create_node(@1.first_line, int_node, NULL, $1, NULL);} 
| FLOAT {$$ = create_node(@1.first_line, float_node, NULL, $1, NULL);} 
| CHAR {$$ = create_node(@1.first_line, char_node, NULL, $1, NULL);} ;

acoes: for{$$ = create_node(@1.first_line, for_node, NULL, $1, NULL);} 
  | while {$$ = create_node(@1.first_line, while_node, NULL, $1, NULL);}
  | if {$$ = create_node(@1.first_line, if_node, NULL, $1, NULL);}
  | att {$$ = create_node(@1.first_line, atribuicao_node, NULL, $1, NULL);};

for: FOR PAROPN att SEMICOLON expressao SEMICOLON att PARCLOSE KOPN code KCLOSE {$$ = create_node(@1.first_line, forlex_node, NULL, $1, $2, $3, $4,$5,$6,$7,$8,$9,$10,$11 NULL);}
  | FOR PAROPN declaracao SEMICOLON expressao SEMICOLON att PARCLOSE KOPN code KCLOSE {$$ = create_node(@1.first_line, forlex_node, NULL, $1, $2, $3, $4,$5,$6,$7,$8,$9,$10,$11 NULL);}
;

while: WHILE PAROPN expressao PARCLOSE KOPN code KCLOSE {$$ = create_node(@1.first_line, whilelex_node, NULL, $1, $2, $3, $4,$5,$6, NULL);};

if: IF PAROPN expressao PARCLOSE KOPN code KCLOSE {$$ = create_node(@1.first_line, iflex_node, NULL, $1, $2, $3, $4,$5,$6, NULL);} 
  | IF PAROPN expressao PARCLOSE KOPN code KCLOSE ELSE KOPN code KCLOSE {$$ = create_node(@1.first_line, elselex_node, NULL, $1, $2, $3, $4,$5,$6,$7,$8,$9,$10, NULL);};

att: IDF ATRIB VALOR {$$ = create_node(@1.first_line, atribuicaolex_node, NULL, $1, $2, $3, NULL);}
| IDF ATRIB calc {$$ = create_node(@1.first_line, atribuicaolex_node, NULL, $1, $2, $3, NULL);} ;

expressao: expr {$$ = create_node(@1.first_line, expr_node, NULL, $1, NULL);} 
  | expr and_or expressao {$$ = create_node(@1.first_line, expr_node, NULL, $1, $2, $3, NULL);};

and_or: AND {$$ = create_node(@1.first_line, and_node, NULL, $1, NULL);} | OR {$$ = create_node(@1.first_line, or_node, NULL, $1, NULL);} ;

expr: AUX_expr comparador AUX_expr {$$ = create_node(@1.first_line, aux_node, NULL, $1, $2, $3, NULL);} | NOT IDF {$$ = create_node(@1.first_line, iflex_node, NULL, $1, $2, NULL);};

AUX_expr: IDF {$$ = create_node(@1.first_line, idf_node, NULL, $1, NULL);} 
| VALOR {$$ = create_node(@1.first_line, lvalue_node, NULL, $1, NULL);} 
| calc {$$ = create_node(@1.first_line, calc_node, NULL, $1, NULL);} ;

comparador: GREAT {$$ = create_node(@1.first_line, maior_node, NULL, $1, NULL);} 
| LESS  {$$ = create_node(@1.first_line, menor_node, NULL, $1, NULL);} 
| EQ {$$ = create_node(@1.first_line, igual_node, NULL, $1, NULL);} 
| NE {$$ = create_node(@1.first_line, diferente_node, NULL, $1, NULL);} 
| GE {$$ = create_node(@1.first_line, maiorigual_node, NULL, $1, NULL);} 
| LE {$$ = create_node(@1.first_line, menorigual_node, NULL, $1, NULL);} ;

calc: VALOR {$$ = create_node(@1.first_line, lvalue_node, NULL, $1, NULL);}
      | IDF {$$ = create_node(@1.first_line, idf_node, NULL, $1, NULL);}
      | calc PLUS calc       {$$ = create_node(@1.first_line, soma_node, NULL, $1, $2, $3, NULL);}
      | calc MIN calc       {$$ = create_node(@1.first_line, sub_node, NULL, $1, $2, $3, NULL);}
      | calc AST calc       {$$ = create_node(@1.first_line, multi_node, NULL, $1, $2, $3, NULL);}
      | calc BAR calc       {$$ = create_node(@1.first_line, div_node, NULL, $1, $2, $3, NULL);}
      | PAROPN calc PARCLOSE       {$$ = create_node(@1.first_line, calc_node, NULL, $1, $2, $3, NULL);} ;


/*demais codes ..*/

%%
 /* A partir daqui, insere-se qlqer codigo C necessario.
  */
