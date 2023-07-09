#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>
#include <string.h>
#include "lista.h"

Tac* create_inst_tac(const char* res, const char* arg1,const char* op, const char* arg2){
    Tac* taque =(Tac*)malloc(sizeof(Tac));
    
    taque->res = malloc(sizeof(res));
    taque->arg1 = malloc(sizeof(arg1));
    taque->op = malloc(sizeof(op));
    taque->arg2 = malloc(sizeof(arg2));

    if (res != NULL)
        strcpy(taque->res, res);
    if (arg1 != NULL)
        strcpy(taque->arg1, arg1);
    if (arg2 != NULL)
        strcpy(taque->arg2, arg2);
    if (op != NULL)
        strcpy(taque->op, op);

    return taque;
}

void print_inst_tac(FILE* out, Tac i){
    char opr[5];
    if(strchr(i.arg1,'.')!=NULL){
        if(strcmp(i.op,"+")==0){
            char* aux = "FADD";
            strcpy(opr,aux);
        }
        if(strcmp(i.op,"*")==0){
            char* aux = "FMUL";
            strcpy(opr,aux);
        }
        if(strcmp(i.op,"/")==0){
            char* aux = "FDIV";
            strcpy(opr,aux);
        }
        if(strcmp(i.op,"-")==0){
            char* aux = "FSUB";
            strcpy(opr,aux);
        }
        if(strcmp(i.op,"Print")==0){}
    }
    else{
        if(strcmp(i.op,"+")==0){
            char* aux = "ADD";
            strcpy(opr,aux);
        }
        if(strcmp(i.op,"*")==0){
            char* aux = "MUL";
            strcpy(opr,aux);
        }
        if(strcmp(i.op,"/")==0){
            char* aux = "DIV";
            strcpy(opr,aux);
        }
        if(strcmp(i.op,"-")==0){
            char* aux = "SUB";
            strcpy(opr,aux);
        }
        if(strcmp(i.op,"Print")==0){}
    }
    
    printf("%s := %s %s %s \n",i.res, i.arg1, opr, i.arg2);
    fprintf(out, "%s := %s %s %s \n",i.res, i.arg1, opr, i.arg2);
}

void print_tac(FILE* out, Node_tac * code){
    if(code->next!=NULL){
        print_tac(out, code->next);
    }
    if(code==NULL){
        return ;
    }
    
    if(code!=NULL){
        if(code->number<10){
            fprintf(out,"00");
        }
        else if(code->number<100){
            fprintf(out,"0");
        }
        
        fprintf(out,"%d: ",code->number);
        print_inst_tac(out, *code->inst);

    }
    
}


void append_inst_tac(Node_tac ** code, Tac * inst){
    Node_tac ** aux = code;
    Node_tac * novo = (Node_tac*)malloc(sizeof(Node_tac));
    novo->inst = inst;
    if((*aux)==NULL){
        novo->number=0;
        novo->next = NULL;
        novo->prev = NULL;
        (*code)=novo;
        return;
    }
    while((*aux)->next!=NULL){
        (*aux)= (*aux)->next;
    }

    
    
    novo->number=(*aux)->number+1;
    
    novo->next = NULL;
    novo->prev = (*aux);
    (*aux)->next = novo;
    
    
}
void cat_tac(Node_tac ** code_a, Node_tac ** code_b){
    if(*code_a==NULL){
        *code_a=*code_b;
    }
    else if(*code_b!=NULL){
        Node_tac ** aux = code_a;
        while((*aux)->next!=NULL){
            (*aux)= (*aux)->next;
        }
        (*aux)->next = (*code_b);

        (*code_b)->prev = (*aux);
    }
    
}
