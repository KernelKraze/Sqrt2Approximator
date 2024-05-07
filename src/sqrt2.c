// sqrt2.c
#include "sqrt2.h"

double continuedFraction(int depth) {
    double result = 2.0;
    for (int i = 0; i < depth; i++) {
        result = 2.0 + 1.0 / result;
    }
    return 1.0 + 1.0 / result;
}

