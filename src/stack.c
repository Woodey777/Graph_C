#include "stack.h"

Stack* push_(char c, Stack *root) {
    Stack *tmp = malloc(sizeof(Stack));
    tmp->ch = c;
    tmp->next = root;
    return tmp;
}

char pop_(Stack **root) {
    Stack *tmp = *root;
    char c;
    if (*root == NULL) {
        c = '\0';
    } else {
        c = tmp->ch;
        *root = tmp->next;
        free(tmp);
    }
    return c;
}

