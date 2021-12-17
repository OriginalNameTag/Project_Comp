#ifndef SYMTAB_H
#define SYMTAB_H

typedef enum {int_type, float32_type, bool_type, char_type, void_type, undef_type} type_type;

typedef struct symbols{
    char *name;                 //Identificador do "Type"
    char *type;                 // 
    struct symbols *next;       //Point to next in line
}symbols;

typedef struct st{
    char *name;                 //Function Name
    int type;                   //Function Identifier, 0 = Global, 1 = Everything else  
    char *params;               //parameters of the functions
    char *returns;              //What the function returns, cause we use the type_type for this maybe? idk
    struct st *next;            //Points to next in line
    struct symbols *symbol;     //Points to the symbols 
}symtab;

symtab *insert_element(symtab **symtab, char *str, int tt, char* params, char* returns);
symtab *search_element(symtab *symtab, char *str);
void show_table(symtab *symtab);

void printTable(symtab * table);
void printParameters(symbols * symbols);

//void tableParse(Node *n, symtab *symtab);

#endif