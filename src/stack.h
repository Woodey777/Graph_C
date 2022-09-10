#ifndef SRC_STACK_H_
#define SRC_STACK_H_
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    char ch;
    struct node *next;
} Stack;

Stack* push_(char c, Stack *root);
char pop_(Stack **root);

#endif  // SRC_STACK_H_
