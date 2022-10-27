#include <stdio.h>

double pi(int n) {
    double pi = 0;
    int i = 0;
    int s = 1;
    for (i = 0; i <= n; i ++){
       pi += 4 * (s / (2.0 * i + 1));
       s *= -1;
    }
    return pi;
}

int main(void){
    int zahl = 0;

    printf("PI Iterations: ");
    scanf("%d", &zahl);

    printf("PI: %lf", pi(zahl));
    return 0;
}