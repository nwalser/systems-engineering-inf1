#include <stdio.h>

int main() {
    int zahl1 = 0;
    int zahl2 = 0;

    printf("Bitte ganze Zahl eingeben: ");
    scanf("%d", &zahl1);

    printf("Bitte weitere Zahl eingeben: ");
    scanf("%d", &zahl2);

    printf("%d \n", zahl1 + zahl2);
    printf("%d \n", zahl1 - zahl2);
    printf("%d \n", zahl1 * zahl2);
    printf("%d \n", zahl1 / zahl2);
    printf("%d \n", zahl1 % zahl2);

    return 0;
}
