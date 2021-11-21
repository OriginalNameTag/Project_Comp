#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

//useless because now we use char* token
/*
char states[][500] = {"Program", "Declarations", "VarDeclaration", "VarSpec", "VarSpecHelper", "Type", "FuncDeclaration", 
"Parameters", "ParametersHelper", "FuncBody", "VarsAndStatements", "Statement", "StatementHelper", "ParseArgs", "FuncInvocation", "FuncInvocationHelper", "Expr"};
*/

//Creates a Node
Node *create_node(char* token, char* value){
    Node *n = (Node *)malloc(sizeof(Node));
    n -> son = NULL;
    n -> sibling = NULL;
    n -> token = token;
    n -> value = value;
    //printf("Node created: %s\n", n->token);
    return n;
}

//Creates and ads a son to given parent
Node *add_son(Node * parent, Node * son){
    //if given son is NULL well that's about it
    if(son == NULL){
        return NULL;
    }
    //if son exists but is empty we add it
    if(parent -> son == NULL){ 
        parent -> son = (Node *)(malloc)(sizeof(Node));
        parent -> son = son;
       
    }
    //if the son already exists checks every son of given parent until there is a son that has no sibling
    // then adds the node 'son' to the empty node
    else{
        Node *aux = (Node *)(malloc)(sizeof(Node));
        Node *old = (Node *)(malloc)(sizeof(Node));
        old = parent -> son;
        aux = parent -> son -> sibling;

         while(aux != NULL){
        old = aux;
        aux = aux -> sibling; 
    }
    
    old -> sibling = (Node *)(malloc)(sizeof(Node));
    old -> sibling = son;
    }
    //printf("Child %s added to parent %s\n", son->token, parent->token);
    return parent;
}

//Adds a sibling to a given Node
Node *add_sibling(Node * someone, Node * sibling){
    
    if(sibling == NULL){
        return NULL;
    }
    Node *aux = (Node *)(malloc)(sizeof(Node));
    Node *old = (Node *)(malloc)(sizeof(Node));
    old = someone;
    aux = someone -> sibling;

    while(aux != NULL){
        old = aux;
        aux = aux -> sibling; 
    }
    
    old -> sibling = (Node *)(malloc)(sizeof(Node));
    old -> sibling = sibling;

    return someone;
}

void print_tree(Node *node, int numb){

    if(root == NULL){
        printf("Root %s is null\n",root->token);
        return;
    }
    for(int i = 0; i < numb; i++){
        printf("..");
    }
    if(node -> value != NULL){
        printf("%s(%s)\n",  node -> token, node -> value );
    }
    else{
        printf("%s\n", node -> token);
    }

   
    if(node -> son != NULL){
        print_tree(node -> son, numb+1);
    }
    
    if(node -> sibling != NULL){
        print_tree(node -> sibling, numb);
    }
};


