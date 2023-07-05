%{
  /* Aqui, pode-se inserir qualquer codigo C necessario ah compilacao
   * final do parser. Sera copiado tal como esta no inicio do y.tab.c
   * gerado por Yacc.
   */
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "node.h"
	#include "symbol_table.h"
	#include "lista.h"
	#define YYDEBUG 1

	#define CHAR_TYPE 0
	#define INT_TYPE 1
	#define FLOAT_TYPE 2

	#define CHAR_SIZE 1
	#define INT_SIZE 4
	#define FLOAT_SIZE 8



	extern int yyerror(const char* msg ); 
	extern int yylex();

	extern Node * syntax_tree;
	extern symbol_t* symbol_table;

	int v_size = 0;
	int code_size = 0;
	int max_t_size = 0;
	int v_desloc = 0;
	int reg = 0;
	
	entry_t *new_entry(char *lx){
        entry_t *new_entry = (entry_t *)malloc(sizeof(entry_t));
        new_entry->name = lx;
        new_entry->desloc = v_desloc;
        new_entry->size = v_size;
        v_desloc += new_entry->size;
        return new_entry;
    }

    void atrib(char *lx){
        if (insert(symbol_table, new_entry(lx)) != 0){
            printf("ERROR:%s\n", lx);
            exit(0);
        }
    }

		char *rx(int desloc){
		char *t = malloc(sizeof(char)*2);
		sprintf(t, "%03d(RX)", desloc);
		return t;
	}

	char *sp(char *id){
		entry_t* aux = lookup(*symbol_table, id);
		if(aux != NULL){       
			char *t = malloc(sizeof(char)*2);
			sprintf(t, "%03d(SP)", aux->desloc);
			return t;
		}
		else{			
			printf("UNDEFINED: %s \n", id);
			exit(0);
		}
	}

%}

%left MIN PLUS
%left AST BAR
%left AND OR
%right NOT




%union {
	char* cadeia;
	struct _node * no;
}

%token<cadeia> TEXT 
%token<cadeia> SEMICOLON 
%token<cadeia> INC 
%token<cadeia> DEC 
%token<cadeia> COMA 
%token<cadeia> ATRIB 
%token<cadeia> COLON 
%token<cadeia> PERIOD 
%token<cadeia> BRAKCLOSE 
%token<cadeia> BRAKOPN 
%token<cadeia> PARCLOSE 
%token<cadeia> PAROPN 
%token<cadeia> PLUS 
%token<cadeia> MIN 
%token<cadeia> BAR 
%token<cadeia> AST 
%token<cadeia> KOPN 
%token<cadeia> KCLOSE 
%token<cadeia> INT 
%token<cadeia> DOUBLE 
%token<cadeia> FLOAT 
%token<cadeia> CHAR 
%token<cadeia> QUOTE 
%token<cadeia> DQUOTE 
%token<cadeia> LE 
%token<cadeia> GE 
%token<cadeia> EQ 
%token<cadeia> NE 
%token<cadeia> AND 
%token<cadeia> OR 
%token<cadeia> NOT 
%token<cadeia> IF 
%token<cadeia> THEN 
%token<cadeia> ELSE 
%token<cadeia> WHILE 
%token<cadeia> FOR 
%token<cadeia> CLASS 
%token<cadeia> PUBLIC 
%token<cadeia> PRIVATE 
%token<cadeia> PROTECTED 
%token<cadeia> VOID 
%token<cadeia> NUL 
%token<cadeia> CONST 
%token<cadeia> STATIC 
%token<cadeia> LESS 
%token<cadeia> GREAT 
%token<cadeia> STRING 

%token<cadeia> IDF 
%token<cadeia> INT_LIT 
%token<cadeia> F_LIT 

/* demais tokens ...*/

//%type<no> code
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
//%type<no> AUX_expr
%type<no> and_or
%type<no> comparador
%type<no> calc
%type<no> AUX_idf_val
%type<no> ifelse
%type<no> comando


/* demais types ... */

%start comando

 /* A completar com seus tokens - compilar com 'yacc -d' */

%%
//code: comando{ $$ = create_node(@1.first_line, 0, "Root", $1, NULL); syntax_tree = $$; };

comando: 
 declaracoes acoes {  $$ = create_node(@1.first_line, code_node, NULL, $1, $2, NULL); init_table(symbol_table); syntax_tree = $$; }
| acoes { $$ = $1; init_table(symbol_table); syntax_tree = $$; };

declaracoes: declaracao SEMICOLON{ 
	Node *no_SEMICOLON = create_node(@1.first_line, pontoevirgula_node,  $2, NULL);

	$$ = create_node(@1.first_line, declaracoes_node, NULL, $1, no_SEMICOLON, NULL);} ;

declaracao: tipo IDF { Node *no_IDF = create_node(@1.first_line, declaracao_node, $2, NULL);
$$ = create_node(@1.first_line, declaracao_node, NULL, $1, no_IDF, NULL); atrib(no_IDF->lexeme);} 
| tipo att {$$ = create_node(@1.first_line, declaracao_node, NULL, $1, $2, NULL); atrib($2->children[0]->lexeme);} ;

tipo: INT {
	$$ = create_node(@1.first_line, int_node, $1, NULL); v_size=INT_SIZE; } 
| FLOAT {
	$$ = create_node(@1.first_line, float_node, $1, NULL);v_size=FLOAT_SIZE;} 
| CHAR {
	$$ = create_node(@1.first_line, char_node, $1, NULL);v_size=CHAR_SIZE;} ;


acoes: for {$$ = create_node(@1.first_line, for_node, NULL, $1, NULL);} 
| while {$$ = create_node(@1.first_line, while_node, NULL, $1, NULL);}
| if {$$ = create_node(@1.first_line, if_node, NULL, $1, NULL);}
| ifelse {$$ = create_node(@1.first_line, else_node, NULL, $1, NULL);}
| att {$$ = $1;} ;
//| att {$$ = create_node(@1.first_line, atribuicao_node, NULL, $1, NULL);} ;


for: FOR PAROPN att SEMICOLON expressao SEMICOLON att PARCLOSE KOPN comando KCLOSE {
	Node *no_FOR = create_node(@1.first_line, forlex_node, $1, NULL);
	Node *no_PAROPN = create_node(@1.first_line, abrepar_node,  $2, NULL);
	Node *no_SEMICOLON = create_node(@1.first_line, pontoevirgula_node,  $4, NULL);
	Node *no_PARCLOSE = create_node(@1.first_line, fechapar_node,  $8, NULL);
	Node *no_KOPN = create_node(@1.first_line, abrechaves_node,  $9, NULL);
	Node *no_KCLOSE = create_node(@1.first_line, fechachaves_node, $11, NULL);
	$$ = create_node(@1.first_line, forlex_node, NULL, no_FOR, no_PAROPN, $3, no_SEMICOLON,$5, no_SEMICOLON, $7, no_PARCLOSE, no_KOPN, $10, no_KCLOSE, NULL);} 
| FOR PAROPN declaracao SEMICOLON expressao SEMICOLON att PARCLOSE KOPN comando KCLOSE {
	Node *no_FOR = create_node(@1.first_line, forlex_node, $1, NULL);
	Node *no_PAROPN = create_node(@1.first_line, abrepar_node,  $2, NULL);
	Node *no_SEMICOLON = create_node(@1.first_line, pontoevirgula_node,  $4, NULL);
	Node *no_PARCLOSE = create_node(@1.first_line, fechapar_node,  $8, NULL);
	Node *no_KOPN = create_node(@1.first_line, abrechaves_node,  $9, NULL);
	Node *no_KCLOSE = create_node(@1.first_line, fechachaves_node, $11, NULL);
	$$ = create_node(@1.first_line, forlex_node, NULL, no_FOR, no_PAROPN, $3, no_SEMICOLON,$5, no_SEMICOLON, $7, no_PARCLOSE, no_KOPN, $10, no_KCLOSE, NULL);};

while: WHILE PAROPN expressao PARCLOSE KOPN comando KCLOSE {
	Node *no_WHILE = create_node(@1.first_line, whilelex_node, $1, NULL);
	Node *no_PAROPN = create_node(@1.first_line, abrepar_node,  $2, NULL);
	Node *no_PARCLOSE = create_node(@1.first_line, fechapar_node,  $4, NULL);
	Node *no_KOPN = create_node(@1.first_line, abrechaves_node,  $5, NULL);
	Node *no_KCLOSE = create_node(@1.first_line, fechachaves_node, $7, NULL);
	$$ = create_node(@1.first_line, whilelex_node, NULL, no_WHILE, no_PAROPN, $3, no_PARCLOSE, no_KOPN,$6, no_KCLOSE, NULL);};

if: IF PAROPN expressao PARCLOSE KOPN comando KCLOSE {
	Node *no_IF = create_node(@1.first_line, iflex_node, $1, NULL);
	Node *no_PAROPN = create_node(@1.first_line, abrepar_node,  $2, NULL);
	Node *no_PARCLOSE = create_node(@1.first_line, fechapar_node,  $4, NULL);
	Node *no_KOPN = create_node(@1.first_line, abrechaves_node,  $5, NULL);
	Node *no_KCLOSE = create_node(@1.first_line, fechachaves_node, $7, NULL);
	$$ = create_node(@1.first_line, iflex_node, NULL, no_IF, no_PAROPN, $3, no_PARCLOSE,no_KOPN,$6,no_KCLOSE, NULL);}; 

ifelse: if ELSE KOPN comando KCLOSE {
	Node *no_ELSE = create_node(@1.first_line, elselex_node, $2, NULL);
	Node *no_KOPN = create_node(@1.first_line, abrechaves_node,  $3, NULL);
	Node *no_KCLOSE = create_node(@1.first_line, fechachaves_node, $5, NULL);
	$$ = create_node(@1.first_line, elselex_node, NULL, $1, no_ELSE, no_KOPN, $4,no_KCLOSE, NULL);};

/*att: IDF ATRIB VALOR {$$ = create_node(@1.first_line, atribuicaolex_node, NULL, $1, $2, $3, NULL);}
| IDF ATRIB calc {$$ = create_node(@1.first_line, atribuicaolex_node, NULL, $1, $2, $3, NULL);} ;*/
//O tac pra parte 3 tem que ser aqui↓
att: IDF ATRIB calc {
	Node *no_IDF = create_node(@1.first_line, idf_node, $1, NULL);
	Node *no_ATRIB = create_node(@1.first_line, atribuicao_node,  $2, NULL);
	
	$$ = create_node(@1.first_line, atribuicaolex_node, NULL, no_IDF, no_ATRIB, $3, NULL);
	
	
	
	};

expressao: expr {$$ = create_node(@1.first_line, expr_node, NULL, $1, NULL);} 
| expr and_or expressao {$$ = create_node(@1.first_line, expr_node, NULL, $1, $2, $3, NULL);};

and_or: AND {
$$ = create_node(@1.first_line, and_node, $1, NULL);} 
| OR {
	$$ = create_node(@1.first_line, or_node, $1, NULL);} ;

expr: calc comparador calc {$$ = create_node(@1.first_line, aux_node, NULL, $1, $2, $3, NULL);} 
| NOT AUX_idf_val {Node *no_NOT = create_node(@1.first_line, notlex_node, $1, NULL);
$$ = create_node(@1.first_line, iflex_node, NULL, no_NOT, $2, NULL);};

/*AUX_expr: AUX_idf_val {$$ = create_node(@1.first_line, idf_node, NULL, $1, NULL);} 
| calc {$$ = create_node(@1.first_line, calc_node, NULL, $1, NULL);} ;*/

AUX_idf_val: IDF {
	$$ = create_node(@1.first_line, idf_node, $1, NULL);} 
| INT_LIT {
	$$ = create_node(@1.first_line, lvalue_node, $1, NULL);} 
| F_LIT {
	$$ = create_node(@1.first_line, lvalue_node, $1, NULL);};


comparador: GREAT {
	$$ = create_node(@1.first_line, maior_node, $1, NULL);} 
| LESS  {
	$$ = create_node(@1.first_line, menor_node, $1,NULL);} 
| EQ {
	$$ = create_node(@1.first_line, igual_node, $1, NULL);} 
| NE {
	$$ = create_node(@1.first_line, diferente_node, $1, NULL);} 
| GE {
	$$ = create_node(@1.first_line, maiorigual_node, $1, NULL);} 
| LE {
	$$ = create_node(@1.first_line, menorigual_node, $1, NULL);} ;

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
