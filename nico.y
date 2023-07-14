%{
  /* Aqui, pode-se inserir qualquer codigo C necessario ah compilacao
   * final do parser. Sera copiado tal como esta no inicio do y.tab.c
   * gerado por Yacc.
   */
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <assert.h>
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
	extern symbol_t symbol_table;
	
	int v_size = 0;
	int t_size_now = 0;
	int t_size = 0;
	int max_t_size = 0;
	int v_desloc = 0;
	int reg = 0;
	int file_num = 0;
	int rot_num = 0;
	entry_t *new_entry(char *lx){
        entry_t *new_entry = (entry_t *)malloc(sizeof(entry_t));
        new_entry->name = strdup(lx);
        new_entry->desloc = v_desloc;
        new_entry->size = v_size;
        v_desloc += new_entry->size;
        return new_entry;
    }

    void atrib(char *lx){
		//print_table(symbol_table);
		if(lookup(symbol_table,lx)){
			printf("entrou no if\n");
			return;
		}
        if (insert(&symbol_table, new_entry(lx)) != 0){
            printf("Symbol table atrib ERROR:%s\n", lx);
			free_table(&symbol_table);
            exit(0);
        }
    }

	char *rx(int desloc){
		char *t = malloc(sizeof(char)*2);
		sprintf(t, "%03d(RX)", desloc);
		return t;
	}

	char *sp(char *id){
		entry_t* aux = lookup(symbol_table, id);
		
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
%token<cadeia> PRINT 
%token<cadeia> TRUE_
%token<cadeia> FALSE_
%token<cadeia> IDF 
%token<cadeia> INT_LIT 
%token<cadeia> F_LIT 

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
//%type<no> AUX_expr
%type<no> and_or
%type<no> comparador
%type<no> calc
%type<no> AUX_idf_val
%type<no> ifelse
%type<no> comando
%type<no> print
%type<no> texto


/* demais types ... */

%start code

 /* A completar com seus tokens - compilar com 'yacc -d' */

%%
code: comando{ $$ = create_node(@1.first_line, 0, "Root", $1, NULL); syntax_tree = $$; cat_tac(&($$->code),  &($1->code)); 
		/*char *t = malloc(sizeof(char)*12);
		sprintf(t, "lista%d.txt", file_num++);
		FILE* file = fopen(t, "w");
    	print_tac(file, $$->code);*/
};
//tirar o ações do declacacoes acoes
comando:                               { $$ = create_node(1, 0, "Vazio", NULL); }
| declaracoes comando{ $$ = create_node(@1.first_line, code_node, NULL, $1, $2, NULL);  
	cat_tac(&($$->code),  &($1->code)); cat_tac(&($$->code),  &($2->code));
		/*char *t = malloc(sizeof(char)*12);
		sprintf(t, "lista%d.txt", file_num++);
		FILE* file = fopen(t, "w");
    	print_tac(file, $$->code);*/
		}
| acoes comando{ $$ = create_node(@1.first_line, code_node, NULL, $1,$2, NULL); 
	cat_tac(&($$->code),  &($1->code));cat_tac(&($$->code),  &($2->code)); 
		/*char *t = malloc(sizeof(char)*12);
		sprintf(t, "lista%d.txt", file_num++);
		FILE* file = fopen(t, "w");
    	print_tac(file, $$->code);*/
};

declaracoes: declaracao SEMICOLON { 
	Node *no_SEMICOLON = create_node(@1.first_line, pontoevirgula_node,  $2, NULL);

	$$ = create_node(@1.first_line, declaracoes_node, NULL, $1, no_SEMICOLON, NULL);
	cat_tac(&($$->code),  &($1->code));
	
		/*char *t = malloc(sizeof(char)*12);
		sprintf(t, "lista%d.txt", file_num++);
		FILE* file = fopen(t, "w");
    	print_tac(file, $$->code);*/
	
	} 

	;

declaracao: tipo IDF { Node *no_IDF = create_node(@1.first_line, declaracao_node, $2, NULL);
$$ = create_node(@1.first_line, declaracao_node, NULL, $1, no_IDF, NULL);
 		atrib($2);
		Tac* tac_vazio = create_inst_tac("","","","");
		append_inst_tac(&($$->code),tac_vazio);
 		/*char *t = malloc(sizeof(char)*12);
		sprintf(t, "lista%d.txt", file_num++);
		FILE* file = fopen(t, "w");
    	print_tac(file, $$->code);*/
 } 
| tipo att {$$ = create_node(@1.first_line, declaracao_node, NULL, $1, $2, NULL); cat_tac(&($$->code),  &($2->code));

		/*char *t = malloc(sizeof(char)*12);
		sprintf(t, "lista%d.txt", file_num++);
		FILE* file = fopen(t, "w");
    	print_tac(file, $$->code);*/
} ;

tipo: INT {
	$$ = create_node(@1.first_line, int_node, $1, NULL); v_size=INT_SIZE; } 
| FLOAT {
	$$ = create_node(@1.first_line, float_node, $1, NULL);v_size=FLOAT_SIZE;} 
| CHAR {
	$$ = create_node(@1.first_line, char_node, $1, NULL);v_size=CHAR_SIZE;} ;


acoes: for {$$ = create_node(@1.first_line, for_node, NULL, $1, NULL);} 
| while {$$ = create_node(@1.first_line, while_node, NULL, $1, NULL);}
| if {$$ = create_node(@1.first_line, if_node, NULL, $1, NULL);cat_tac(&($$->code),  &($1->code));}
| ifelse {$$ = create_node(@1.first_line, else_node, NULL, $1, NULL);cat_tac(&($$->code),  &($1->code));}
| print {$$ = create_node(@1.first_line, print_node, NULL, $1, NULL);cat_tac(&($$->code),  &($1->code));}
| att {$$ = create_node(@1.first_line, atribuicao_node, NULL, $1, NULL); cat_tac(&($$->code),  &($1->code));
		//printa uma lista de tac pra cada operação aritmética
		/*char *t = malloc(sizeof(char)*12);
		sprintf(t, "lista%d.txt", file_num++);
		FILE* file = fopen(t, "w");
    	print_tac(file, $$->code);
		fclose(file);*/
} ;
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
	$$ = create_node(@1.first_line, iflex_node, NULL, no_IF, no_PAROPN, $3, no_PARCLOSE,no_KOPN,$6,no_KCLOSE, NULL);
	$$->f = strdup("novo_rot");

	$3->t = strdup("novo_rot");
	$3->f = strdup($$->f);

	$6->f= strdup($$->f);

	Tac* new_true= create_inst_tac($3->t,"",":","");//label1:
	Tac* new_false = create_inst_tac($$->f,"",":","");

	append_inst_tac(&($6->code),new_false);
	append_inst_tac(&($3->code),new_true);

	cat_tac(&($3->code),&($6->code));
	cat_tac(&($$->code),&($3->code));
	
	}; 

ifelse: IF PAROPN expressao PARCLOSE KOPN comando KCLOSE ELSE KOPN comando KCLOSE {
	Node *no_IF = create_node(@1.first_line, iflex_node, $1, NULL);
	Node *no_ELSE = create_node(@1.first_line, elselex_node, $8, NULL);
	Node *no_KOPN = create_node(@1.first_line, abrechaves_node,  $5, NULL);
	Node *no_KCLOSE = create_node(@1.first_line, fechachaves_node, $7, NULL);
	Node *no_PAROPN = create_node(@1.first_line, abrepar_node,  $2, NULL);
	Node *no_PARCLOSE = create_node(@1.first_line, fechapar_node,  $4, NULL);
	$$ = create_node(@1.first_line, elselex_node, NULL, no_IF, no_PAROPN, $3, no_PARCLOSE,no_KOPN,$6,no_KCLOSE,no_ELSE, no_KOPN, $10,no_KCLOSE, NULL); 
	$3->t = strdup("novo_rot");
	$3->f = strdup("novo_rot");

	$6->f = strdup($$->f);
	$10->f = strdup($$->f);

	Tac* new_true= create_inst_tac($3->t,"",":","");
	Tac* new_goto= create_inst_tac("","","goto",$$->f);
	Tac* new_false= create_inst_tac($3->f,"",":","");
	Tac* new_next= create_inst_tac($$->f,"",":","");

	append_inst_tac(&($10->code), new_next);
	append_inst_tac(&($6->code), new_goto);
	append_inst_tac(&($6->code), new_false);
	append_inst_tac(&($3->code), new_true);

	cat_tac(&($6->code),&($10->code));
	cat_tac(&($3->code),&($6->code));
	cat_tac(&($$->code),&($3->code));

	};

print: PRINT PAROPN texto PARCLOSE SEMICOLON {
	
	Node *no_PRINT = create_node(@1.first_line, print_lex_node, $1, NULL);
	Node *no_PAROPN = create_node(@1.first_line, abrepar_node, $2, NULL);
	Node *no_PARCLOSE = create_node(@1.first_line, fechapar_node,  $4, NULL);
	Node *no_SEMICOLON = create_node(@1.first_line, pontoevirgula_node,  $5, NULL);

	$$ = create_node(@1.first_line, print_lex_node, NULL, no_PRINT, no_PAROPN, $3, no_PARCLOSE,no_SEMICOLON, NULL);
	
	Tac* new_tac = create_inst_tac(sp($3->lexeme),"","PRINT","");
	//printf("\n\n Tac dentro do att %s := %s \n",sp($1),$3->lexeme);

 	cat_tac(&($$->code), &($3->code));

 	append_inst_tac(&($$->code),new_tac);

	} ;

texto: TEXT{$$ = create_node(@1.first_line, text_lex_node, $1, NULL); 
	Tac* tac_vazio = create_inst_tac("","","","");
	t_size_now = CHAR_SIZE;
	append_inst_tac(&($$->code),tac_vazio);}
|
IDF{
	$$ = create_node(@1.first_line, idf_node, $1, NULL); 
	Tac* tac_vazio = create_inst_tac("","","","");
	entry_t* aux = lookup(symbol_table,$1);
	t_size_now = aux->size;
	append_inst_tac(&($$->code),tac_vazio);
}
;

/*att: IDF ATRIB VALOR {$$ = create_node(@1.first_line, atribuicaolex_node, NULL, $1, $2, $3, NULL);}
| IDF ATRIB calc {$$ = create_node(@1.first_line, atribuicaolex_node, NULL, $1, $2, $3, NULL);} ;*/
//O tac pra parte 3 tem que ser aqui↓
att: IDF ATRIB calc {
	Node *no_IDF = create_node(@1.first_line, idf_node, $1, NULL);
	Node *no_ATRIB = create_node(@1.first_line, atribuicao_node,  $2, NULL);
	
	$$ = create_node(@1.first_line, atribuicaolex_node, NULL, no_IDF, no_ATRIB, $3, NULL);
	
	atrib($1);
	
	/*
	Anotação pra raciocinar como utilizar o lista.h aqui pra fazer um código TAC decente
	
	a gente quer gerar algo como: 000:000(Rx) := 000(SP) := 0
	isso seria o equivalente a: int i = 0;
	vou precisar pegar a posição da variável na symbol table
	pra criar uma instrução tac temos a função: Tac* create_inst_tac(const char* res, const char* arg1,const char* op, const char* arg2)
	então, pra gerar o tac de int i = 0 eu teria que passar create_inst_tac(i,0,NULL,NULL)
	pra algo como i = 2 + 3 seria create_inst_tac(i,2,+,3)
	mas o certo seria algo como create_inst_tac("000(SP)","2","+","3")
	ok, com isso a gente tem uma noção do que tem que fazer, quando for um terminal a gente tem que transformar ele em um SP caso seja um IDF
	caso a operação seja com mais de dois argumentos precisaremos de guardar alguns resultados em um RX, aka temporário

	Blz, com isso tirado do caminho, falta definirmos como vamos usar o resto das funções do lista.h
	Nossa lista está dentro do nosso nodo
	Então, toda a vez que a gente gerar um tac temos que colocá-lo dentro de um node tac com o append_inst_tac
	Também é preciso concatenar as listas de tacs, considerando que cada uma delas está dentro de um nodo, com o cat_tac
	
	*/
	Tac* new_tac = create_inst_tac(sp($1),$3->lexeme,"atribuicao","");
	printf("\n\n Tac dentro do att %s := %s \n",sp($1),$3->lexeme);

 	cat_tac(&($$->code), &($3->code));

 	append_inst_tac(&($$->code),new_tac);
	t_size = 0;

	/*char *t = malloc(sizeof(char)*12);
		sprintf(t, "lista%d.txt", file_num++);
		FILE* file = fopen(t, "w");
    	print_tac(file, $$->code);*/
};

//Aqui a gente faz os esquemas dos bool - fiz tudo errado, era pra fazer só a parte do curto-circuito
expressao: expr {$$ = create_node(@1.first_line, expr_node, NULL, $1, NULL);
				cat_tac(&($$->code), &($1->code));
} 
| expressao and_or expressao {$$ = create_node(@1.first_line, expr_node, NULL, $1, $2, $3, NULL);

	if(strcmp($2->lexeme,"or")==0){
		$1->t=strdup($$->t);
		//↓ esse a gente vai ter que colocar algo descente dps
		$1->f = strdup("novo_rot");

		$3->t=strdup($$->t);
		$3->f=strdup($1->f);

		Tac* new_tac_lab = create_inst_tac("","","goto",$1->f);
		/*Tac* new_tac = create_inst_tac($$->lexeme,$1->lexeme,$2->lexeme,$3->lexeme);
		t_size_now = CHAR_SIZE;
		t_size+=t_size_now;*/
		
		append_inst_tac(&($1->code),new_tac_lab);
		cat_tac( &($1->code),&($3->code) );
		cat_tac( &($$->code),&($1->code) );
		//append_inst_tac(&($$->code),new_tac);
	}
	else{
		$1->f=strdup($$->f);
		//↓ esse a gente vai ter que colocar algo descente dps
		$1->f = strdup("novo_rot");
		
		Tac* new_tac_lab = create_inst_tac("","","goto",$1->t);
		append_inst_tac(&($1->code),new_tac_lab);
		cat_tac( &($1->code),&($3->code) );
		cat_tac( &($$->code),&($1->code) );
	}

}
|NOT expressao {
	Node* no_NOT = create_node(@1.first_line, idf_node, $1, NULL);
	$$ = create_node(@1.first_line, expr_node, NULL, no_NOT,$2, NULL);
	$2->t=strdup($$->f);
	$2->f=strdup($$->t);
	cat_tac( &($$->code),&($2->code) );
	/*cat_tac( &($$->code),&($2->code) );
	Tac* new_tac = create_inst_tac($$->lexeme,$2->lexeme,"not","");
	t_size_now = CHAR_SIZE;
	t_size+=t_size_now;
	append_inst_tac(&($$->code), new_tac);*/
} 
| PAROPN expressao PARCLOSE { Node *no_PAROPN = create_node(@1.first_line, abrepar_node,  $1, NULL);
	Node *no_PARCLOSE = create_node(@1.first_line, fechapar_node,  $3, NULL);
	$$ = create_node(@1.first_line, expr_node, NULL, no_PAROPN, $2, no_PARCLOSE, NULL);
	
	$$->t= strdup($2->t);
	$$->f= strdup($2->f);

	cat_tac( &($$->code),&($2->code) );

}
| TRUE_{$$ = create_node(@1.first_line, lvalue_node, NULL, NULL);

	Tac* tac_vazio = create_inst_tac("","","goto",$$->t);
	append_inst_tac(&($$->code),tac_vazio);
	/*Tac* tac_vazio = create_inst_tac($$->lexeme,"1","","");
	t_size_now = CHAR_SIZE;
	t_size+=t_size_now;
	append_inst_tac(&($$->code),tac_vazio);*/
}
| FALSE_{$$ = create_node(@1.first_line, lvalue_node, rx(t_size), NULL);
	Tac* tac_vazio = create_inst_tac("","","goto",$$->f);
	append_inst_tac(&($$->code),tac_vazio);
	/*Tac* tac_vazio = create_inst_tac($$->lexeme,"0","","");
	t_size_now = CHAR_SIZE;
	t_size+=t_size_now;
	append_inst_tac(&($$->code),tac_vazio);*/
};

and_or: AND {
$$ = create_node(@1.first_line, and_node, $1, NULL);} 
| OR {
	$$ = create_node(@1.first_line, or_node, $1, NULL);} ;

expr:calc{$$ = create_node(@1.first_line, aux_node, NULL, $1, NULL);}
| calc comparador calc {$$ = create_node(@1.first_line, aux_node, NULL, $1, $2, $3, NULL);
	Tac* tac_true = create_inst_tac($$->t,$1->lexeme,$2->lexeme,$3->lexeme);//“if” E1.local relop.lexval E2.local “goto” B.t)
	Tac* tac_false = create_inst_tac("","","goto",$$->f);
	append_inst_tac(&($2->code),tac_true);
	append_inst_tac(&($2->code),tac_false);
	cat_tac( &($1->code),&($2->code) );
	cat_tac( &($$->code),&($1->code) );

} ;

//Criar codes com atributos vazios
AUX_idf_val: IDF {
	$$ = create_node(@1.first_line, idf_node, $1, NULL); 
	Tac* tac_vazio = create_inst_tac("","","","");
	entry_t* aux = lookup(symbol_table,$1);
	t_size_now = aux->size;
	append_inst_tac(&($$->code),tac_vazio);
	} 
| INT_LIT {
	$$ = create_node(@1.first_line, lvalue_node, $1, NULL);
	Tac* tac_vazio = create_inst_tac("","","","");
	t_size_now = INT_SIZE;

	append_inst_tac(&($$->code),tac_vazio);	} 
| F_LIT {
	$$ = create_node(@1.first_line, lvalue_node, $1, NULL);
	Tac* tac_vazio = create_inst_tac("","","","");
	t_size_now = FLOAT_SIZE;
	append_inst_tac(&($$->code),tac_vazio);	};


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

calc:
//concatenar coisas aqui
AUX_idf_val {$$ = create_node(@1.first_line, lvalue_node, NULL, $1, NULL);
	$$->lexeme= strdup($1->lexeme);
	cat_tac(&($$->code),&($1->code));
}
| calc PLUS calc       {
	Node *no_PLUS = create_node(@1.first_line, soma_node, $2, NULL);
	$$ = create_node(@1.first_line, soma_node, rx(t_size), $1, no_PLUS, $3, NULL);
	t_size+=t_size_now;
	Tac* new_tac = create_inst_tac($$->lexeme,$1->lexeme,$2,$3->lexeme);

	printf("\n\n Tac dentro do calc %s := %s %s %s \n",$$->lexeme,$1->lexeme,$2,$3->lexeme);
	append_inst_tac(&($3->code),new_tac);
 	cat_tac(&($1->code), &($3->code));

 	cat_tac(&($$->code), &($1->code));

 	 
	/*char *t = malloc(sizeof(char)*12);
		sprintf(t, "lista%d.txt", file_num++);
		FILE* file = fopen(t, "w");
    	print_tac(file, $$->code);*/
	}
| calc MIN calc       {
	Node *no_MIN = create_node(@1.first_line, sub_node, $2, NULL);
	$$ = create_node(@1.first_line, sub_node, rx(t_size), $1, no_MIN, $3, NULL);
	
	t_size+=t_size_now;
	Tac* new_tac = create_inst_tac($$->lexeme,$1->lexeme,$2,$3->lexeme);

	printf("\n\n Tac dentro do calc %s := %s %s %s \n",$$->lexeme,$1->lexeme,$2,$3->lexeme);

 	cat_tac(&($$->code), &($1->code));

 	cat_tac(&($$->code), &($3->code));

 	append_inst_tac(&($$->code),new_tac);
	}
| calc AST calc       {
	Node *no_MULTI = create_node(@1.first_line, multi_node, $2, NULL);
	$$ = create_node(@1.first_line, multi_node, rx(t_size), $1, no_MULTI, $3, NULL);

	t_size+=t_size_now;
	Tac* new_tac = create_inst_tac($$->lexeme,$1->lexeme,$2,$3->lexeme);

	printf("\n\n Tac dentro do calc %s := %s %s %s \n",$$->lexeme,$1->lexeme,$2,$3->lexeme);

 	cat_tac(&($$->code), &($1->code));

 	cat_tac(&($$->code), &($3->code));

 	append_inst_tac(&($$->code),new_tac);
	}
| calc BAR calc       {
	Node *no_BAR = create_node(@1.first_line, div_node, $2, NULL);
	$$ = create_node(@1.first_line, div_node, rx(t_size), $1, no_BAR, $3, NULL);

	t_size+=t_size_now;
	Tac* new_tac = create_inst_tac($$->lexeme,$1->lexeme,$2,$3->lexeme);

	printf("\n\n Tac dentro do calc %s := %s %s %s \n",$$->lexeme,$1->lexeme,$2,$3->lexeme);

 	cat_tac(&($$->code), &($1->code));

 	cat_tac(&($$->code), &($3->code));

 	append_inst_tac(&($$->code),new_tac);
	}
| PAROPN calc PARCLOSE       {
	Node *no_PAROPN = create_node(@1.first_line, abrepar_node,  $1, NULL);
	Node *no_PARCLOSE = create_node(@1.first_line, fechapar_node,  $3, NULL);
	$$ = create_node(@1.first_line, calc_node, NULL, no_PAROPN, $2, no_PARCLOSE, NULL);
	$$->lexeme= strdup($2->lexeme);
	cat_tac(&($$->code),&($2->code));
	} ;


/*demais codes ..*/

%%
 /* A partir daqui, insere-se qlqer codigo C necessario.
  */
