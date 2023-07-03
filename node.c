#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>
#include "node.h"


Node * syntax_tree;

Node* create_node(int nl, Node_type t, char* lexeme,  /* Node* children */ ...)
{
	
	Node* new_node = (Node *)malloc(sizeof(Node));

	//Code ...
    va_list ap;
    va_start(ap, lexeme);

    int n_args = 0;
    const Node* arg = va_arg(ap, const Node*);
    for (;  arg != NULL;  arg = va_arg(ap, const Node*)) {
        //printf("Recebi um '%s'\n", arg);
        n_args ++;
    }
	//printf("adicionei nmr");
	new_node->n_child = n_args;
    va_end(ap);
    va_start(ap, lexeme);
	//printf("segundo start");
    new_node->children = (Node**)malloc(sizeof(Node*)*n_args);

    for(int i = 0; i < n_args; i++){
        Node *aux = va_arg(ap, Node *);
        //aux->dad = new_node;
        new_node->children[i] = aux;
    }

    va_end(ap);
	new_node->type=t;
	new_node->line_num=nl;
    new_node->lexeme=lexeme;
	//printf("cheguei no fim da cracao");
	return new_node;
}

int nb_of_children(Node* n)
{
	assert(n != NULL);
	return n->n_child;
}

int is_leaf(Node* n)
{
	assert(n != NULL);
	return n->n_child == 0;
}

Node* child(Node* n, int i)
{
	assert(n != NULL);
	assert((0 <= i) && ((unsigned int)i < n->n_child));
	return n->children[i];
}

int deep_free_node(Node* n)
{
	//TODO: Cant we set the original pointer to NULL?
	if(n != NULL)
	{
		if(is_leaf(n)){
			free(n);
		}
		else{
			for(int i = 0; i<n->n_child; i++){
				deep_free_node(n->children[i]);
			}
		}

		//return 1;
	}
	return 0;
}

int height(Node* n)
{
	assert(n != NULL);
	int h = 0;
	if(n->n_child != 0)
	{
		//Code ...
		for(int i = 0; i<n->n_child; i++){
			int h_aux = height(n->children[i])+1;
			if(h_aux > h){
				h = h_aux;
			}
		}
		return h;
	}
	return h + 1;
}

void uncompile(FILE* outfile, Node *n)
{
    printf("Entrando\n");
	if(n != NULL)
	{
    printf("Cheguei\n");
        if(!is_leaf(n)) { 
			for(int i = 0; i < n->n_child; i++){
			//for (int i = 0; i < level; i++)
                uncompile(outfile,n->children[i]);
                printf("No folhq!\n");
            }
        } else{
  		//Code ...
		    printf("Folha\n");
            fprintf(outfile ,"Node: %s\n", n->lexeme);
	    }

    }

}
