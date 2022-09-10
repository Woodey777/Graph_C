#ifndef SRC_POLISH_H_
#define SRC_POLISH_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int checkPrior(char);
char func(char *a, int *n);
int checkMinus(const char *a, const int *n);
void checkOp(char *a, char *res, Stack **stack, int *n, int *pos);
char* polinate(char a[]);

#endif  // SRC_POLISH_H_

