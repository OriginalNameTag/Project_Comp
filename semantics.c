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
    if (root)
    {
        Node *yeet = root->son;
        // printf("%s", yeet->token);
        while (yeet != NULL)
        {
            Node *no = yeet;
            //printf("entrei aqui %s\n", no->token);
            if (strcmp(no->token, "FuncDecl") == 0)
            {
                func_check(no);
            }
            else if (strcmp(no->token, "VarDecl") == 0)
            {
                var_check(no);
            }
            if (yeet->sibling != NULL)
            {
                // printf("yeet before %s\n", yeet->token);
                yeet = yeet->sibling;
                // printf("amongus %s\n", yeet->token);
            }
            else
            {
                yeet = NULL;
            }
        }
        return;
    }
}
void func_check(Node *node)
{
    Node *node1 = node->son;
    if (strcmp(node->token, "FuncDecl") == 0 && node->son != NULL)
    {   
        

        while(node1 != NULL){
            
            Node *no1 = node->son;
            // printf("Funcdecl\n");
            if (strcmp(no1->token, "FuncHeader") == 0 && no1->son != NULL)
            {
                Node *no = no1->son;
                // printf("funcheader %s\n", no->value);
                Node *aux = no->sibling;
                // printf("aux %s\n", aux->sibling);
                if (aux->sibling != NULL)
                {
                    Node *tipo = aux->sibling;
                    
                        if (strcmp(tipo->token, "FuncParams") == 0 && tipo->son != NULL)
                        {
                            tipo = tipo->son;
                        }
                        else if (strcmp(tipo->token, "FuncParams") == 0 && tipo->son == NULL)
                        {
                            if (strcmp(aux->token, "Int") == 0)
                            {
                                // printf("here\n");
                                insert_element(&global, no->value, 0, "int", NULL);
                                
                                
                            }
                            else if (strcmp(aux->token, "Float32") == 0)
                            {
                                // printf("here\n");
                                insert_element(&global, no->value, 0, "float32", NULL);
                                
                            }
                            else if (strcmp(aux->token, "String") == 0)
                            {
                                // printf("here\n");
                                insert_element(&global, no->value, 0, "string", NULL);
                                
                            }
                            else if (strcmp(aux->token, "Bool") == 0)
                            {
                                // printf("here\n");
                                insert_element(&global, no->value, 0, "bool", NULL);
                                
                            }
                            else
                            {
                                insert_element(&global, no->value, 0, NULL, NULL);
                            }
                        }
                        if (strcmp(tipo->token, "ParamDecl") == 0 && tipo->son != NULL)
                        {
                            if (strcmp(tipo->son->token, "Int") == 0)
                            {
                                if (strcmp(aux->token, "Int") == 0)
                                {
                                    // printf("no value: %s\n", tipo->son->token);
                                    insert_element(&global, no->value, 0, "int", "int");
                                
                                }
                            }
                            else if (strcmp(tipo->son->token, "Int") == 0)
                            {
                                if (strcmp(aux->token, "Float32") == 0)
                                {
                                    // printf("no value: %s\n", tipo->son->token);
                                    insert_element(&global, no->value, 0, "int", "float32");
                                
                                }
                            }
                            else if (strcmp(tipo->son->token, "Int") == 0)
                            {
                                if (strcmp(aux->token, "String") == 0)
                                {
                                    // printf("no value: %s\n", tipo->son->token);
                                    insert_element(&global, no->value, 0, "int", "string");
                                    
                                }
                            }
                            else if (strcmp(tipo->son->token, "Int") == 0)
                            {
                                if (strcmp(aux->token, "Bool") == 0)
                                {
                                    // printf("no value: %s\n", tipo->son->token);
                                    insert_element(&global, no->value, 0, "int", "bool");
                                    
                                }
                            }
                            else if (strcmp(tipo->son->token, "Float32") == 0)
                            {
                                if (strcmp(aux->token, "Int") == 0)
                                {
                                    // printf("no value: %s\n", tipo->son->token);
                                    insert_element(&global, no->value, 0, "float32", "int");
                                    
                                }
                            }
                            else if (strcmp(tipo->son->token, "Float32") == 0)
                            {
                                if (strcmp(aux->token, "Float32") == 0)
                                {
                                    // printf("no value: %s\n", tipo->son->token);
                                    insert_element(&global, no->value, 0, "float32", "float32");
                                    
                                }
                            }
                            else if (strcmp(tipo->son->token, "Float32") == 0)
                            {
                                if (strcmp(aux->token, "Bool") == 0)
                                {
                                    // printf("no value: %s\n", tipo->son->token);
                                    insert_element(&global, no->value, 0, "float32", "bool");
                                    
                                }
                            }
                            else if (strcmp(tipo->son->token, "Float32") == 0)
                            {
                                if (strcmp(aux->token, "String") == 0)
                                {
                                    // printf("no value: %s\n", tipo->son->token);
                                    insert_element(&global, no->value, 0, "float32", "string");
                                    
                                }
                            }
                            else if (strcmp(tipo->son->token, "Bool") == 0)
                            {
                                if (strcmp(aux->token, "Int") == 0)
                                {
                                    // printf("no value: %s\n", tipo->son->token);
                                    insert_element(&global, no->value, 0, "bool", "int");
                                    
                                }
                            }
                            else if (strcmp(tipo->son->token, "Bool") == 0)
                            {
                                if (strcmp(aux->token, "Float32") == 0)
                                {
                                    // printf("no value: %s\n", tipo->son->token);
                                    insert_element(&global, no->value, 0, "bool", "float32");
                                
                                }
                            }
                            else if (strcmp(tipo->son->token, "Bool") == 0)
                            {
                                if (strcmp(aux->token, "Bool") == 0)
                                {
                                    // printf("no value: %s\n", tipo->son->token);
                                    insert_element(&global, no->value, 0, "bool", "bool");
                                    
                                }
                            }
                            else if (strcmp(tipo->son->token, "Bool") == 0)
                            {
                                if (strcmp(aux->token, "String") == 0)
                                {
                                    // printf("no value: %s\n", tipo->son->token);
                                    insert_element(&global, no->value, 0, "bool", "string");
                                    
                                }
                            }
                            else if (strcmp(tipo->son->token, "String") == 0)
                            {
                                if (strcmp(aux->token, "Int") == 0)
                                {
                                    // printf("no value: %s\n", tipo->son->token);
                                    insert_element(&global, no->value, 0, "string", "int");
                                    
                                }
                            }
                            else if (strcmp(tipo->son->token, "String") == 0)
                            {
                                if (strcmp(aux->token, "Float32") == 0)
                                {
                                    // printf("no value: %s\n", tipo->son->token);
                                    insert_element(&global, no->value, 0, "string", "float32");
                                    
                                }
                            }
                            else if (strcmp(tipo->son->token, "String") == 0)
                            {
                                if (strcmp(aux->token, "String") == 0)
                                {
                                    // printf("no value: %s\n", tipo->son->token);
                                    insert_element(&global, no->value, 0, "string", "string");
                                
                                }
                            }
                            else if (strcmp(tipo->son->token, "String") == 0)
                            {
                                if (strcmp(aux->token, "Bool") == 0)
                                {
                                    // printf("no value: %s\n", tipo->son->token);
                                    insert_element(&global, no->value, 0, "string", "bool");
                                
                                }
                            }
                        }
                        else if (!(tipo->token))
                        {
                            if (strcmp(aux->token, "Bool") == 0)
                            {
                                // printf("no value: %s\n", tipo->son->token);
                                insert_element(&global, no->value, 0, NULL, "bool");
                                
                            }
                            else if (strcmp(aux->token, "Int") == 0)
                            {
                                // printf("no value: %s\n", tipo->son->token);
                                insert_element(&global, no->value, 0, NULL, "int");
                                
                            }
                            else if (strcmp(aux->token, "Float32") == 0)
                            {
                                // printf("no value: %s\n", tipo->son->token);
                                insert_element(&global, no->value, 0, NULL, "float32");
                                
                            }
                            else if (strcmp(aux->token, "String") == 0)
                            {
                                // printf("no value: %s\n", tipo->son->token);
                                insert_element(&global, no->value, 0, NULL, "string");
                                
                            }
                            else
                            {
                                insert_element(&global, no->value, 0, NULL, NULL);
                            }
                        }
                    
                }

                else
                {
                    // printf("%s\n", no->value);
                    insert_element(&global, no->value, 0, NULL, NULL);
                }

             if(strcmp(no1->sibling->token, "FuncBody") == 0 && no1->sibling->son != NULL){
               
               funcbody_check(no1->sibling, no1->son->sibling);
               
            }
            }
           
            if (node1->sibling != NULL)
            {
                //printf("yeet before %s\n", node1->token);
                node1 = node1->sibling;
                // printf("amongus %s\n", yeet->token);
            }
            else
            {
                node1 = NULL;
            }
        }
    }
}

void funcbody_check(Node *node, Node* no1){
     //printf("here\n");
   
        if(strcmp(node->son->token, "Call")==0 || strcmp(node->son->token, "Assign")==0){
                // printf("here1\n");

            if(strcmp(node->son->son->token,"Id")==0){
            //printf("here2\n");
                if(strcmp(no1->token,"Float32")==0){
                    node->son->type = "float32";
                }
                else if(strcmp(no1->token,"RealLit")==0){
                    node->son->type = "int";
                }
            }
        }   
   

    //printf("node1 type %s", node1->type);        
}

void var_check(Node *no)
{
    if (strcmp(no->token, "VarDecl") == 0 && no->son != NULL)
    {
        no = no->son;
        //printf("Vardecl: %s\n", no->token);
        Node *id = no->sibling; // vai ser o id
        if (strcmp(no->token, "String") == 0)
        {
            // printf("no value: %s\n", tipo->son->token);
            insert_element(&global, id->value, 0, "string", "is_var");
           
        }
        else if (strcmp(no->token, "Bool") == 0)
        {
            // printf("no value: %s\n", tipo->son->token);
            insert_element(&global, id->value, 0, "bool", "is_var");
        }
        else if (strcmp(no->token, "Int") == 0)
        {
            // printf("no value: %s\n", tipo->son->token);
            insert_element(&global, id->value, 0, "int", "is_var");
        }
        else if (strcmp(no->token, "Float32") == 0)
        {
            // printf("no value: %s\n", tipo->son->token);
            insert_element(&global, id->value, 0, "float32", "is_var");
        }
    }
}


