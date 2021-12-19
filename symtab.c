#include "symtab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern symtab *st;

symtab *insert_element(symtab **st, char *str, int tt, char *param, char *returns)
{
    symtab *new = (symtab *)malloc(sizeof(symtab));
    symtab *aux;
    symtab *previous;
    new->name = strdup(str);
    new->type = tt;
    if (param)
        new->params = strdup(param);
    else
        new->params = NULL;

    if (returns)
        new->returns = strdup(returns);
    else
        new->returns = NULL;
    new->next = NULL;

    if (*st)
    {
        for (aux = *st; aux; previous = aux, aux = aux->next)
        {
            if (strcmp(aux->name, str) == 0)
            {
                printf("aux = %s, str = %s\n", aux->name, str);
                free(new->name);
                free(new);
                printf("Symbol %s already defined\n", aux->name);
                return NULL;
            }
        }
        previous->next = new;
    }
    else
    {
        *st = new;
    }
    return new;
}

symtab *search_element(symtab *st, char *str)
{
    symtab *aux = st;

    for (; aux != NULL; aux = aux->next)
    {
        if (strcmp(aux->name, str) == 0)
        {
            return aux;
        }
        else
        {
            return NULL;
        }
    }

    return aux;
}

// welp it receives the global in the frist case and then will keep working until there's no more elements in the table
void show_table(symtab *st)
{
    // printf("showtable\n");
    printTable(st);

    return;
}


void printTable(symtab *table)
{
    // printf("amongus\n");

    // Print Global Symbol Table, expeted to at least
    if (table->type == 0)
    {
        printf("===== Global Symbol Table =====\n");
        while (table->name != NULL)
        {
            if(table->returns!=NULL && strcmp(table->returns, "is_var")==0){
                printf("%s\t\t%s\n", table->name,table->params);
            }else
            // if there's para
            if (table->returns == NULL && table->params != NULL)
            {
                printf("%s\t(%s)\tnone\n", table->name, table->params);
                // printf("Printou\n");
            }
            else if (table->returns != NULL && table->params == NULL)
            {
                printf("%s\t()\t%s\n", table->name, table->returns);
                // printf("Printou\n");
            }
            else if (table->returns == NULL && table->params == NULL)
            {
                printf("%s\t()\tnone\n", table->name);
                // printf("Printou\n");
            }
            else
            {
                printf("%s\t(%s)\t%s\n", table->name, table->params, table->returns);
            }
            if (table->next)
            {
                table = table->next;
            }
            else
            {
                // printf("No other function found\n");
                return;
            }
        }
    }
    // Print Function Symbol Tables
    else if (table->type == 1)
    {
        printf("===== Function %s(", table->name);
        // idk where to get the parameters this shit is weird as hell, if I go to the next one it won't work cause I'm going to the next function so I need to go to the next symbol of this one I guess

       

        printf(") Symbol Table ====\n");

        // printf("return\t\t%s", table->symbol);
    }
}

void printParameters(symbols *symbols)
{
    if (symbols != NULL)
    {
        printf("(");
        // no clue need to create more stuff
        

        printf(")");
    }
}


