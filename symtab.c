#include "symtab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern symtab *st;

symtab *insert_element(symtab **st, char *str, type_type tt){
    symtab *new = (symtab *)malloc(sizeof(symtab));
    symtab *aux;
    symtab *previous;

    new->name = strdup(str);
    new->type = tt;
    new->next= NULL;

    if(*st){
        for(aux = *st;aux; previous = aux, aux = aux->next){
            if(strcmp(aux->name, str)==0){
                free(new->name);
                free(new);
                return NULL;
            }
        }
        previous->next=new;
    }else{
        *st = new;
    }
    return new;
}

symtab * search_element(symtab *st, char *str){
    symtab *aux = st;

    for(; aux!=NULL;aux=aux->next){
        if(strcmp(aux->name, str)==0){
            return aux;
        }else{
            return NULL;
        }
    }
}

//welp it receives the global in the frist case and then will keep working until there's no more elements in the table
void show_table(symtab *symtab) {
    while(st != NULL){
        printTable(st);
        st = st->next;
    }
}

//the voices dont stop
void printTable(symtab *table){

    //Print Global Symbol Table, expeted to at least
    if(table->type == 0){
        printf("===== Global Symbol Table =====\n");
        if(table->symbol != NULL){
            symbols *aux = table -> symbol;
            //if there's param
            if(1){
                printf("%s\t%s\tparam\n", aux-> name, aux->type);
            }
            //well... if there isn't lol
            else{
                printf("%s\t%s", aux->name, aux->type);
                //print the params here?
            }

            while(aux->next != NULL){
                aux = aux->next;
                if(1){
                    printf("%s\t%s\tparam\n", aux-> name, aux->type);
                }
            }
        }
    }
    //Print Function Symbol Tables
    else if(table->type == 1){
        printf("===== Function %s(", table->name);
            //idk where to get the parameters this shit is weird as hell, if I go to the next one it won't work cause I'm going to the next function so I need to go to the next symbol of this one I guess 

            //I wanna blow my brains out awful decision to stay up all night especially when I couldn't understand shit of this and the others programs dont help me that much even though I kinda know what I need to do



        printf(") Symbol Table ====\n");

        printf("return\t\t%s", table->symbol);
        
    }
}
void printParameters(symbols * symbols){
    if(symbols != NULL){
        printf("(");
        //no clue need to create more stuff
        //im going insane haha

        printf(")");
    }
}

//Parsing from AST to Symbol Table
/*void tableParse(Node * n, symtab *st){
    



}
*/