#include "semantics.h"
#include "symtab.h"
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
extern Node *root;
extern symtab *global;
extern symtab *funcs;

void semantic_check(Node *root){
    global = NULL;
    if(root){
        Node* yeet= root->son;

        while(yeet!= NULL){
            Node* no = yeet;
            if(strcmp(no->token, "FuncDecl")==0 || strcmp(no->token, "VarDecl")==0){
                //printf("entrou\n");
                if(strcmp(no->token, "FuncDecl")==0 && no->son!=NULL){
                    no = no->son;
                    //printf("Funcdecl\n");
                    if(strcmp(no->token, "FuncHeader")==0 && no->son!=NULL){
                        no=no->son;
                        //printf("funcheader\n");
                        Node *aux = no->sibling;
                        Node *tipo = aux->sibling;
                        if(strcmp(tipo->token, "FuncParams")==0 && tipo->son!=NULL){
                            tipo=tipo->son;
                        }else if(strcmp(tipo->token, "FuncParams")==0 && tipo->son==NULL){
                            
                        }
                            if(strcmp(tipo->token, "ParamDecl")==0 && tipo->son!=NULL){
                                if(strcmp(tipo->son->token, "Int")==0){
                                    if(strcmp(aux->token, "Int")==0){
                                        insert_element(&global, no->value, 0, "int", "int");
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if(yeet->sibling){
                yeet = yeet->sibling;
            }
        }
    }
}