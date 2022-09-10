#include "print.h"

void print(const double mas_y[]) {
  double step_y = fabs((double)(Y_MAX - Y_MIN) / (ROWS - 1));
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if ((mas_y[j] >= (-0.5 * step_y + Y_MIN + step_y * i)) &&
          (mas_y[j] < (0.5 * step_y + Y_MIN + step_y * i)))
        printf("*");
      else
        printf(".");
    }
    if (i != ROWS - 1)
      printf("\n");
  }
}
