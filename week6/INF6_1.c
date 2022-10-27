#include <stdio.h>

int quersumme(int x) {
    int quersumme = 0;
    while (x > 0) {
        quersumme += x % 10;
        x /= 10;
    }
    return quersumme;
}

int main(void){
    int zahl = 0;

    printf("Zahl eingeben: ");
    scanf("%d", &zahl);

    printf("Quersumme: %d", quersumme(zahl));
    return 0;
}