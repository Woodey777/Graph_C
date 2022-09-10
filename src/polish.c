#include "polish.h"

// Основная функция для перевода в постфиксную нотацию
char* polinate(char a[]) {
  Stack *stack = NULL;
  char *res = malloc(200 * sizeof(char));
  int n = 0, pos = 0;
  while (a[n] != '\0') {
    if (a[n] == ')') {
      while (stack->ch != '(') {
        res[pos] = pop_(&stack);
        ++pos;
      }
      pop_(&stack);
    }
    if ((a[n] >= '0' && a[n] <= '9') || (a[n] == 'x') ||
        (a[n] == '.')) {
        res[pos] = a[n];
        ++pos;
      if (((a[n+1] < '0') || (a[n+1] > '9')) && (a[n+1] != '.')) {
        res[pos] = ' ';
        ++pos;
      }
    }
    if (a[n] == '(') {
      stack = push_(a[n], stack);
    }
    checkOp(a, res, &stack, &n, &pos);
  n++;
  }
  while (stack != NULL) {
    res[pos] = pop_(&stack);
    ++pos;
  }
  res[pos] = '\0';
  return res;
}

// Функция обработки операций ("+", "*"...)
void checkOp(char *a, char *res, Stack **stack, int *n, int *pos) {
  if (a[*n] == '+' || a[*n] == '-' || a[*n] == '/' ||
      a[*n] == '*' || a[*n] == 's' || a[*n] == 'c' ||
      a[*n] == 't' || a[*n] == 'l' || a[*n] == '^' ) {
    if (*stack == NULL) {
      if (checkMinus(a, n)) {
        *stack = push_(' ', *stack);
        *stack = push_('~', *stack);
      } else {
        *stack = push_(' ', *stack);
        *stack = push_(func(a, n), *stack);
      }
    } else {
      if (checkPrior((*stack)->ch) < checkPrior(a[*n])) {
        if (checkMinus(a, n)) {
          *stack = push_(' ', *stack);
          *stack = push_('~', *stack);
        } else {
          *stack = push_(' ', *stack);
          *stack = push_(func(a, n), *stack);
        }
      } else {
        while ((*stack != NULL) && (checkPrior((*stack)->ch) >= checkPrior(a[*n]))) {
          res[(*pos)++] = pop_(stack);
        }
        if (checkMinus(a, n)) {
          *stack = push_(' ', *stack);
          *stack = push_('~', *stack);
        } else {
          *stack = push_(' ', *stack);
          *stack = push_(func(a, n), *stack);
        }
      }
    }
  }
}

// Проверка для унарного минуса
int checkMinus(const char *a, const int *n) {
  int res = 0;
  if (a[*n] == '-' &&
     ((a[*n+1] >= '0' && a[*n+1] <= '9') || a[*n+1] == 'x' || a[*n+1] == '(' ||
       a[*n+1] == 's' || a[*n+1] == 'c' || a[*n+1] == 't' || a[*n+1] == 'l') &&
     ((a[*n-1] < '0' || a[*n-1] > '9') && a[*n-1] != 'x' && a[*n-1] != ')')) {
      res = 1;
  } else {
    res = 0;
  }
  return res;
}

// Проверка на наличие функции
char func(char *a, int *n) {
  char c;
  char res[3] = {a[*n], a[*n+1], '\0'};
  if (strcmp(res, "si") == 0) {
    c = 's';
    *n += 2;
  } else if (strcmp(res, "co") == 0) {
    c = 'c';
    *n += 2;
  } else if (strcmp(res, "ta") == 0) {
    c = 't';
    *n += 2;
  } else if (strcmp(res, "ct") == 0) {
    c = 'g';
    *n += 2;
  } else if (strcmp(res, "sq") == 0) {
    c = 'q';
    *n += 3;
  } else if (strcmp(res, "ln") == 0) {
    c = 'l';
    *n += 1;
  } else {
    c = a[*n];
  }
  return c;
}

// Назначение приоритетов операций
int checkPrior(char a) {
  int temp;
  switch (a) {
  case '^':
    temp = 6;
    break;
  case ' ':
  case 'l':
  case 't':
  case 'c':
  case 's':
    temp = 4;
    break;
  case '*':
  case '~':
  case '/':
    temp = 3;
    break;
  case '-':
  case '+':
    temp = 2;
    break;
  case '(':
    temp = 1;
    break;
  default:
    temp = 0;
    break;
  }
  return temp;
}
