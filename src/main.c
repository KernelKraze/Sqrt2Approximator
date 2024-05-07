// main.c
#include "my_stdio.h"
#include "sqrt2.h"

int main() {
    int depth = 30;
    double approximation = continuedFraction(depth);
    my_printf("Approximation of sqrt(2) with depth %d is %f\n", depth, approximation);
    return 0;
}

