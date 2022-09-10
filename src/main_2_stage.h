#ifndef SRC_MAIN_2_STAGE_H_
#define SRC_MAIN_2_STAGE_H_
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

double parse_line(char *line, int n, double x);
double summ(double a, double b);
double sub(double a, double b);
double mul(double a, double b);
double divide(double a, double b);
void Switch(char symbol, double *stack, int *top);
void Dlinnoe_chislo(int * i, const char *line, double *stack, int *top);
int isEmpty(int top);
void push(double value, double *stack, int *top);
double pop(const double *stack, int *top);

#endif  // SRC_MAIN_2_STAGE_H_
