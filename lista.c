#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>
#include <string.h>
#include "lista.h"

Tac* create_inst_tac(const char* res, const char* arg1,const char* op, const char* arg2){
    Tac* taque =(Tac*)malloc(sizeof(Tac));
    
    taque->res=res;
    taque->arg1=arg1;
    taque->arg2=arg2;
    taque->op=op;

    return taque;
}

void print_inst_tac(FILE* out, Tac i){
    fprintf(out, "%s := %s %s %s \n",i.res, i.arg1, i.op, i.arg2);
}

void print_tac(FILE* out, Node_tac * code){
    if(code->next!=NULL){
        print_tac(out, code->next);
    }
    if(code!=NULL){
        if(code->number<10){
            fprintf(out,"00");
        }
        else if(code->number<100){
            fprintf(out,"0");
        }
        
        fprintf(out,"%d: ",code->number);
        print_inst_tac(out, * code->inst);

    }
}

void append_inst_tac(Node_tac ** code, Tac * inst){
    Node_tac ** aux = code;
    while((*aux)->next!=NULL){
        (*aux)= (*aux)->next;
    }
    Node_tac * novo = (Node_tac*)malloc(sizeof(Node_tac));

    novo->inst = inst;
    if(aux==NULL){
        novo->number=0;
    }
    else{
        novo->number=(*aux)->number+1;
    }
    novo->next = NULL;
    novo->prev = (*aux);
    
    (*aux)->next = novo;
}
void cat_tac(Node_tac ** code_a, Node_tac ** code_b){
    Node_tac ** aux = code_a;
    while((*aux)->next!=NULL){
        (*aux)= (*aux)->next;
    }
    (*aux)->next = (*code_b);

    (*code_b)->prev = (*aux);
}
