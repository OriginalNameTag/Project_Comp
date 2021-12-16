/*
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
void show_table(symtab *st) {
    if(!st) return;
    symtab *aux;
    printf("===== Global Symbol Table =====\n");
    for(aux = st; aux; aux = aux->next)
    printf("%s\t(%d)\n", aux->name, aux->type);
}


//welp it's wrong because aparently the type is not this
void printTable(symtab *table){
    if(st->type == 0){
        printf("===== Global Symbol Table =====\n");
    }


}
*/