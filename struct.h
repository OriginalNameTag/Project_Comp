#ifndef STUCT_H
#define STUCT_H

typedef struct Node{
    char* token;
    char* value;
    struct  params *param;
    char *type;
    int function;
    struct Node *son;
    struct Node *sibling;
}Node;

typedef struct params{
    char *name;
    char *type;
    struct params *next;
}params;

Node *root;

Node *create_node(char* token, char* value);
Node *add_son(Node * parent, Node * son);
Node *add_sibling(Node * someone, Node * sibling);
void print_tree(Node* root, int numb);
void print_tree_anotated(Node *node, int numb);
void save_type(Node* first, Node* type);

#endif //STRUCT_H