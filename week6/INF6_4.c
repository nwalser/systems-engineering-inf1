#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

double nullstelle() {
    double x0 = 0, x1 = 10, y = 0, mitte = 0;
    const double EPS = 1E-10;
	do {
        mitte = (x0 + x1) / 2;
        y = mitte * mitte * mitte - 14.8 * mitte * mitte - 152 * mitte + 960;
        if (y > 0) {
            x0 = mitte;
        } else {
            x1 = mitte;
        }
    }
    while (fabs(y) > EPS);
    return x0;
}

int main(void){
    printf("Nullstelle: %lf", nullstelle());
    return 0;
}