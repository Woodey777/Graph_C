#include <stdio.h>
#include <stdlib.h>
#include "main_2_stage.h"
#include "polish.h"
#include "print.h"
#include "stack.h"

int main() {
    char str[100], *pol;
    double y[80], x = 0, dx = X_MAX / 79;
    scanf("%99s", str);
    pol = polinate(str);
    for (int i = 0; i < 80; ++i) {
        y[i] = parse_line(pol, strlen(pol), x);
        x += dx;
    }
    print(y);
    free(pol);
    return 0;
}
