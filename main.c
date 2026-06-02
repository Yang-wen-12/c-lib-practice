#include <stdio.h>
#include "add.h"

int main() {
    int x = 3, y = 5;
    printf("%d + %d = %d\n", x, y, add(x, y));
    return 0;
}