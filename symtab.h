#ifndef SYMTAB_H
#define SYMTAB_H

typedef enum {int_type, float32_type, bool_type, char_type, void_type, undef_type} type_type;
typedef struct st{
    char *name;
    type_type type;
    struct st *next;
}symtab;

symtab *insert_element(symtab **symtab, char *str, type_type tt);
symtab *search_element(symtab *symtab, char *str);
void show_table(symtab *symtab);

#endif