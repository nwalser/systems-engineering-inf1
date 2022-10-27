#include <stdio.h>

double kontostand(int jahr) {
    double kapital = 0.1;
    int i;
    for (i = 0; i < jahr; i++) {
        kapital *= 1.05;
    }
    return kapital;
}

int main(void){
    int zahl = 0;

    printf("Startbetrag eingeben: ");
    scanf("%d", &zahl);

    printf("Endkontostand: %lf", kontostand(zahl));
    return 0;
}