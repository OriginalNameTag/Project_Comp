#ifndef SEMANTICS_H
#define SEMANTICS_H
#include "struct.h"
extern Node *root;
void semantic_check(Node *root);
void func_check(Node *no);
void var_check(Node *no);
#endif // SEMANTICS_H