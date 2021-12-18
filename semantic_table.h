/*
#ifndef SYMTAB_H
#define SYMTAB_H

typedef enum {int_type, float32_type, bool_type, char_type, void_type, undef_type} type_type;



typedef struct st{
    char *name;         //FuncDecalration, FuncDefenition or Declaration
    
    type_type type;     //No fucking clue
    
    struct st *next;    //Point to next in line
}symtab;

symtab *insert_element(symtab **symtab, char *str, type_type tt);
symtab *search_element(symtab *symtab, char *str);
void show_table(symtab *symtab);

void printTable(symtab * table);

#endif
*/