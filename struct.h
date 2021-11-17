#ifndef STUCT_H
#define STUCT_H

typedef struct Node{
    char* token;
    char* value;
    struct Node *son;
    struct Node *sibling;
}Node;

Node *root;

Node *create_node(char* token, char* value);
Node *add_son(Node * parent, Node * son);
Node *add_sibling(Node * someone, Node * sibling);
void print_tree(Node* root, int numb);

#endif //STRUCT_H