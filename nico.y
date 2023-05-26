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

%left MIN PLUS
%left AST BAR
%left AND OR
%right NOT




%union {
	char* cadeia;
	struct _node * no;
}

%token<cadeia> IDF
%token<cadeia> VALOR
%token<cadeia> INT
%token<cadeia> DOUBLE
%token<cadeia> FLOAT
%token<cadeia> CHAR
%token<cadeia> OR
%token<cadeia> AND
%token<cadeia> IF
%token<cadeia> ELSE
%token<cadeia> FOR
%token<cadeia> WHILE
%token<cadeia> ATRIB
%token<cadeia> PAROPN
%token<cadeia> PARCLOSE
%token<cadeia> KOPN
%token<cadeia> KCLOSE
%token<cadeia> SEMICOLON
%token<cadeia> NOT
%token<cadeia> PLUS
%token<cadeia> MIN
%token<cadeia> AST
%token<cadeia> BAR
%token<cadeia> GREAT
%token<cadeia> LESS
%token<cadeia> EQ
%token<cadeia> LE
%token<cadeia> GE
%token<cadeia> NE

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
%type<no> AUX_idf_val
%type<no> ifelse
%type<no> comando


/* demais types ... */

%start code

 /* A completar com seus tokens - compilar com 'yacc -d' */

%%
code: comando{ $$ = create_node(@1.first_line, 0, "Root", $1, NULL); syntax_tree = $$; };

comando: { $$ = create_node(1, 0, "Vazio", NULL); } 
| declaracoes code {  $$ = create_node(@1.first_line, code_node, NULL, $1, $2, NULL);}
| acoes code{ $$ = create_node(@1.first_line, code_node, NULL, $1, $2, NULL); };

declaracoes: declaracao SEMICOLON{ 
	Node *no_SEMICOLON = create_node(@1.first_line, pontoevirgula_node,  $2, NULL);

	$$ = create_node(@1.first_line, declaracoes_node, NULL, $1, no_SEMICOLON, NULL);} ;

declaracao: tipo IDF { Node *no_IDF = create_node(@1.first_line, declaracao_node, $2, NULL);
$$ = create_node(@1.first_line, declaracao_node, NULL, $1, no_IDF, NULL);} 
| tipo att {$$ = create_node(@1.first_line, declaracao_node, NULL, $1, $2, NULL);} ;

tipo: INT {Node *no_INT = create_node(@1.first_line, int_node, $1, NULL);
	$$ = create_node(@1.first_line, int_node, NULL, no_INT, NULL);} 
| FLOAT {Node *no_FLOAT = create_node(@1.first_line, float_node, $1, NULL);
	$$ = create_node(@1.first_line, float_node, NULL, no_FLOAT, NULL);} 
| CHAR {Node *no_CHAR = create_node(@1.first_line, char_node, $1, NULL);
	$$ = create_node(@1.first_line, char_node, NULL, no_CHAR, NULL);} ;

acoes: for {$$ = create_node(@1.first_line, for_node, NULL, $1, NULL);} 
| while {$$ = create_node(@1.first_line, while_node, NULL, $1, NULL);}
| if {$$ = create_node(@1.first_line, if_node, NULL, $1, NULL);}
| ifelse {$$ = create_node(@1.first_line, else_node, NULL, $1, NULL);}
| att {$$ = create_node(@1.first_line, atribuicao_node, NULL, $1, NULL);} ;


for: FOR PAROPN att SEMICOLON expressao SEMICOLON att PARCLOSE KOPN code KCLOSE {
	Node *no_FOR = create_node(@1.first_line, forlex_node, $1, NULL);
	Node *no_PAROPN = create_node(@1.first_line, abrepar_node,  $2, NULL);
	Node *no_SEMICOLON = create_node(@1.first_line, pontoevirgula_node,  $4, NULL);
	Node *no_PARCLOSE = create_node(@1.first_line, fechapar_node,  $8, NULL);
	Node *no_KOPN = create_node(@1.first_line, abrechaves_node,  $9, NULL);
	Node *no_KCLOSE = create_node(@1.first_line, fechachaves_node, $11, NULL);
	$$ = create_node(@1.first_line, forlex_node, NULL, no_FOR, no_PAROPN, $3, no_SEMICOLON,$5, no_SEMICOLON, $7, no_PARCLOSE, no_KOPN, $10, no_KCLOSE, NULL);} 
| FOR PAROPN declaracao SEMICOLON expressao SEMICOLON att PARCLOSE KOPN code KCLOSE {
	Node *no_FOR = create_node(@1.first_line, forlex_node, $1, NULL);
	Node *no_PAROPN = create_node(@1.first_line, abrepar_node,  $2, NULL);
	Node *no_SEMICOLON = create_node(@1.first_line, pontoevirgula_node,  $4, NULL);
	Node *no_PARCLOSE = create_node(@1.first_line, fechapar_node,  $8, NULL);
	Node *no_KOPN = create_node(@1.first_line, abrechaves_node,  $9, NULL);
	Node *no_KCLOSE = create_node(@1.first_line, fechachaves_node, $11, NULL);
	$$ = create_node(@1.first_line, forlex_node, NULL, no_FOR, no_PAROPN, $3, no_SEMICOLON,$5, no_SEMICOLON, $7, no_PARCLOSE, no_KOPN, $10, no_KCLOSE, NULL);};

while: WHILE PAROPN expressao PARCLOSE KOPN code KCLOSE {
	Node *no_WHILE = create_node(@1.first_line, whilelex_node, $1, NULL);
	Node *no_PAROPN = create_node(@1.first_line, abrepar_node,  $2, NULL);
	Node *no_PARCLOSE = create_node(@1.first_line, fechapar_node,  $4, NULL);
	Node *no_KOPN = create_node(@1.first_line, abrechaves_node,  $5, NULL);
	Node *no_KCLOSE = create_node(@1.first_line, fechachaves_node, $7, NULL);
	$$ = create_node(@1.first_line, whilelex_node, NULL, no_WHILE, no_PAROPN, $3, no_PARCLOSE, no_KOPN,$6, no_KCLOSE, NULL);};

if: IF PAROPN expressao PARCLOSE KOPN code KCLOSE {
	Node *no_IF = create_node(@1.first_line, iflex_node, $1, NULL);
	Node *no_PAROPN = create_node(@1.first_line, abrepar_node,  $2, NULL);
	Node *no_PARCLOSE = create_node(@1.first_line, fechapar_node,  $4, NULL);
	Node *no_KOPN = create_node(@1.first_line, abrechaves_node,  $5, NULL);
	Node *no_KCLOSE = create_node(@1.first_line, fechachaves_node, $7, NULL);
	$$ = create_node(@1.first_line, iflex_node, NULL, no_IF, no_PAROPN, $3, no_PARCLOSE,no_KOPN,$6,no_KCLOSE, NULL);}; 

ifelse: if ELSE KOPN code KCLOSE {
	Node *no_ELSE = create_node(@1.first_line, elselex_node, $2, NULL);
	Node *no_KOPN = create_node(@1.first_line, abrechaves_node,  $3, NULL);
	Node *no_KCLOSE = create_node(@1.first_line, fechachaves_node, $5, NULL);
	$$ = create_node(@1.first_line, elselex_node, NULL, $1, no_ELSE, no_KOPN, $4,no_KCLOSE, NULL);};

/*att: IDF ATRIB VALOR {$$ = create_node(@1.first_line, atribuicaolex_node, NULL, $1, $2, $3, NULL);}
| IDF ATRIB calc {$$ = create_node(@1.first_line, atribuicaolex_node, NULL, $1, $2, $3, NULL);} ;*/
att: IDF ATRIB AUX_expr {
	Node *no_IDF = create_node(@1.first_line, idf_node, $1, NULL);
	Node *no_ATRIB = create_node(@1.first_line, atribuicao_node,  $2, NULL);
	$$ = create_node(@1.first_line, atribuicaolex_node, NULL, no_IDF, no_ATRIB, $3, NULL);};

expressao: expr {$$ = create_node(@1.first_line, expr_node, NULL, $1, NULL);} 
| expr and_or expressao {$$ = create_node(@1.first_line, expr_node, NULL, $1, $2, $3, NULL);};

and_or: AND {Node *no_AND = create_node(@1.first_line, and_node, $1, NULL);
$$ = create_node(@1.first_line, and_node, NULL, no_AND, NULL);} 
| OR {Node *no_OR = create_node(@1.first_line, or_node, $1, NULL);
	$$ = create_node(@1.first_line, or_node, NULL, no_OR, NULL);} ;

expr: AUX_expr comparador AUX_expr {$$ = create_node(@1.first_line, aux_node, NULL, $1, $2, $3, NULL);} 
| NOT AUX_idf_val {Node *no_NOT = create_node(@1.first_line, notlex_node, $1, NULL);
$$ = create_node(@1.first_line, iflex_node, NULL, no_NOT, $2, NULL);};

AUX_expr: AUX_idf_val {$$ = create_node(@1.first_line, idf_node, NULL, $1, NULL);} 
| calc {$$ = create_node(@1.first_line, calc_node, NULL, $1, NULL);} ;

AUX_idf_val: IDF {
	Node *no_IDF = create_node(@1.first_line, idf_node, $1, NULL);
	$$ = create_node(@1.first_line, idf_node, NULL, no_IDF, NULL);} 
| VALOR {
	Node *no_VALOR = create_node(@1.first_line, lvalue_node, $1, NULL);
	$$ = create_node(@1.first_line, lvalue_node, NULL, no_VALOR, NULL);} ;

comparador: GREAT {
	Node *no_GREAT = create_node(@1.first_line, maior_node, $1, NULL);
	$$ = create_node(@1.first_line, maior_node, NULL, no_GREAT, NULL);} 
| LESS  {
	Node *no_LESS = create_node(@1.first_line, menor_node, $1, NULL);
	$$ = create_node(@1.first_line, menor_node, NULL, no_LESS, NULL);} 
| EQ {
	Node *no_EQ = create_node(@1.first_line, igual_node, $1, NULL);
	$$ = create_node(@1.first_line, igual_node, NULL, no_EQ, NULL);} 
| NE {
	Node *no_NE = create_node(@1.first_line, diferente_node, $1, NULL);
	$$ = create_node(@1.first_line, diferente_node, NULL, no_NE, NULL);} 
| GE {
	Node *no_GE = create_node(@1.first_line, maiorigual_node, $1, NULL);
	$$ = create_node(@1.first_line, maiorigual_node, NULL, no_GE, NULL);} 
| LE {
	Node *no_LE = create_node(@1.first_line, menorigual_node, $1, NULL);
	$$ = create_node(@1.first_line, menorigual_node, NULL, no_LE, NULL);} ;

calc: /*VALOR {$$ = create_node(@1.first_line, lvalue_node, NULL, $1, NULL);}
| IDF {$$ = create_node(@1.first_line, idf_node, NULL, $1, NULL);}*/
AUX_idf_val {$$ = create_node(@1.first_line, lvalue_node, NULL, $1, NULL);}
| calc PLUS calc       {
	Node *no_PLUS = create_node(@1.first_line, soma_node, $2, NULL);
	$$ = create_node(@1.first_line, soma_node, NULL, $1, no_PLUS, $3, NULL);}
| calc MIN calc       {
	Node *no_MIN = create_node(@1.first_line, sub_node, $2, NULL);
	$$ = create_node(@1.first_line, sub_node, NULL, $1, no_MIN, $3, NULL);}
| calc AST calc       {
	Node *no_MULTI = create_node(@1.first_line, multi_node, $2, NULL);
	$$ = create_node(@1.first_line, multi_node, NULL, $1, no_MULTI, $3, NULL);}
| calc BAR calc       {
	Node *no_BAR = create_node(@1.first_line, div_node, $2, NULL);
	$$ = create_node(@1.first_line, div_node, NULL, $1, no_BAR, $3, NULL);}
| PAROPN calc PARCLOSE       {
	Node *no_PAROPN = create_node(@1.first_line, abrepar_node,  $1, NULL);
	Node *no_PARCLOSE = create_node(@1.first_line, fechapar_node,  $3, NULL);
	$$ = create_node(@1.first_line, calc_node, NULL, no_PAROPN, $2, no_PARCLOSE, NULL);} ;


/*demais codes ..*/

%%
 /* A partir daqui, insere-se qlqer codigo C necessario.
  */
