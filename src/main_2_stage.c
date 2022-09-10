#include "main_2_stage.h"

// Основная функция для подсчета значений польской нотации
double parse_line(char *line, int len, double x) {
  double stack[MAX_SIZE];
  int top = 0;
  int flag = 1;
  for (int i = 0; (i < len - 1) && (flag == 1); i++) {
    if ((line[i] != ' ') && (line[i + 1] == ' ')) {
      if (line[i] >= 48 && line[i] <= 57) {
        push((line[i] - 48), stack, &top);
      }
      Switch(line[i], stack, &top);
        for (int j = 0; j < top; ++j) {
          if (isinf(stack[j]) || isnan(stack[j])) {
            flag = 0;
          }
        }
        if (line[i] == 'x') {
          push(x, stack, &top);
        }
      } else {
        Dlinnoe_chislo(&i, line, stack, &top);
      }
    }
  double res;
  if (flag == 0) {
    res = 99999999.;
  } else {
    res = pop(stack, &top);
  }
  return res;
}

// Функция для предачи чисел > 1 символа в стек
void Dlinnoe_chislo(int *i, const char *line, double *stack, int *top) {
  if (line[*i] != ' ') {
    char *unit_line = (char *)malloc(1 * sizeof(char));
    int k = 0;
    while (line[*i] != ' ') {
      unit_line[k] = line[*i];
      (*i)++;
      k++;
      unit_line = (char *)realloc(unit_line, (*i + 1));
      if (NULL == unit_line) {
          printf("REALLOC FAILURE");
          exit(EXIT_FAILURE);
      }
    }
    push(atof(unit_line), stack, top);
    free(unit_line);
  }
}

// Вычисление результата операции и отправка в стек
void Switch(char symbol, double *stack, int *top) {
    switch (symbol) {
        case '+': push(summ(pop(stack, top), pop(stack, top)), stack, top);
            break;
        case '-': push(sub(pop(stack, top), pop(stack, top)), stack, top);
            break;
        case '*': push(mul(pop(stack, top), pop(stack, top)), stack, top);
            break;
        case '/': push(divide(pop(stack, top), pop(stack, top)), stack, top);
            break;
        case '^': { double n = pop(stack, top);
            double a = pop(stack, top);
            push(pow(a, n), stack, top);
            break; }
        case '~': push((-1) * (pop(stack, top)), stack, top);
            break;
        case 's': push(sin(pop(stack, top)), stack, top);
            break;
        case 'c': push(cos(pop(stack, top)), stack, top);
            break;
        case 't': push(tan(pop(stack, top)), stack, top);
            break;
        case 'g': push(1 / tan(pop(stack, top)), stack, top);
            break;
        case 'q': push(sqrt(pop(stack, top)), stack, top);
            break;
        case 'l': push(log(pop(stack, top)), stack, top);
            break;
    }
}

double summ(double a, double b) { return (a + b); }

double sub(double a, double b) { return a - b; }

double mul(double a, double b) { return a * b; }

double divide(double a, double b) { return a / b; }

int isEmpty(int top) { return top == 0; }

void push(double value, double *stack, int *top) { stack[(*top)++] = value; }

double pop(const double *stack, int *top) {
  if (isEmpty(*top)) {
    printf("Not enought operands!\n");
    exit(EXIT_FAILURE);
  }
  (*top)--;
  return stack[*top];
}
