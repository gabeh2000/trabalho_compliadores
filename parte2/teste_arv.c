#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "node.h"

int main(){
    Node* arvore;
    arvore=create_node(0,0,"iasdfhdf",NULL);

    //uncompile(arvore);
    
    deep_free_node(arvore);
    return 0;
};