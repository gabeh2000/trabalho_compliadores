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
        printf("\n\n\ncreate tac r: %s",res);
    if (arg1 != NULL)
        strcpy(taque->arg1, arg1);
        printf("\n\n\ncreate tac a1: %s",arg1);
    if (arg2 != NULL)
        strcpy(taque->arg2, arg2);
        printf("\n\n\ncreate tac a2: %s\n",arg2);
    if (op != NULL)
        strcpy(taque->op, op);
    
    return taque;
}

void print_inst_tac(FILE* out, Tac i){
    char * opr = strdup("");

    if(strcmp(i.op,"goto")==0){
        fprintf(out, "goto %s \n",i.arg2);

    }
    else if(strcmp(i.op,":")==0){
        fprintf(out, "%s : \n",i.res);

    }
    else if(strcmp(i.res,"novo_rot")>0){
        fprintf(out, "if %s %s %s goto %s\n",i.arg1, i.op, i.arg2, i.res);
    }
    else if(strcmp(i.op,"PRINT")==0){
        fprintf(out, "PRINT %s \n",i.res);
        
    }
    else if(strcmp(i.op,"")!=0){
        if(strchr(i.arg1,'.')!=NULL){
            if(strcmp(i.op,"+")==0){
                char* aux = "FADD";
                opr = strdup(aux);
            }
            if(strcmp(i.op,"*")==0){
                char* aux = "FMUL";
                opr = strdup(aux);
            }
            if(strcmp(i.op,"/")==0){
                char* aux = "FDIV";
                opr =strdup(aux);
            }
            if(strcmp(i.op,"-")==0){
                char* aux = "FSUB";
                opr =strdup(aux);
            }
            
        }
        else{
            if(strcmp(i.op,"+")==0){
                char* aux = "ADD";
                opr =strdup(aux);
            }
            if(strcmp(i.op,"*")==0){
                char* aux = "MUL";
                opr =strdup(aux);
            }
            if(strcmp(i.op,"/")==0){
                char* aux = "DIV";
                opr =strdup(aux);
            }
            if(strcmp(i.op,"-")==0){
                char* aux = "SUB";
                opr =strdup(aux);
            }
            
        }
        
        printf("%s := %s %s %s \n",i.res, i.arg1, opr, i.arg2);
        fprintf(out, "%s := %s %s %s \n",i.res, i.arg1, opr, i.arg2);
    }
    
}

void print_tac(FILE* out, Node_tac * code){
    if(code!=NULL){    
        fprintf(out,"%.3d: ",code->number);
        print_inst_tac(out, *code->inst);

    }
    if(code->next!=NULL){
        print_tac(out, code->next);
    }
    
}


void append_inst_tac(Node_tac ** code, Tac * inst){
    Node_tac ** aux = code;
    Node_tac * novo = (Node_tac*)malloc(sizeof(Node_tac));
    novo->inst = inst;
    novo->number = 0;
    // printf("\n\n\nappend r: %s",novo->inst->res);
    // printf("\n\n\nappend a1: %s",novo->inst->arg1);
    // printf("\n\n\nappend a2: %s\n",novo->inst->arg2);

    if((*aux)==NULL){
        novo->prev = NULL;
        novo->next = NULL;
        (*code)=novo;
    }
    else{

        while((*aux)->next!=NULL){
            (*aux)= (*aux)->next;
        }
        novo->number=(*aux)->number+1;
        
        (*aux)->next = novo;
        novo->prev = (*aux);
        
    }

    struct node_tac *p = NULL;
    int i = 0;
    p = *code;
    while (p != NULL)
    {
        p->number = i;
        i++;
        p = p->next;
    }
}
void cat_tac(Node_tac ** code_a, Node_tac ** code_b){
    if(*code_a==NULL){
        *code_a=*code_b;
        printf("cruzou no cat_tac\n");
    }
    else if(*code_b!=NULL){
        Node_tac ** aux = code_a;
        while((*aux)->next!=NULL){
            (*aux)= (*aux)->next;
        }
        (*code_b)->prev = (*aux);
        (*aux)->next = (*code_b);

        
        printf("cruzou no cat_tac\n");
    }
    
}
