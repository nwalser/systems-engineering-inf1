#include <stdio.h>

int main() {
    double zahl1 = 0;
    double zahl2 = 0;

    printf("Bitte ganze Zahl eingeben: ");
    scanf("%lf", &zahl1);
    printf("%lf \n", zahl1);

    printf("Bitte weitere Zahl eingeben: ");
    scanf("%lf", &zahl2);
    printf("%lf \n", zahl2);

    printf("%lf \n", zahl1 + zahl2);
    printf("%lf \n", zahl1 - zahl2);
    printf("%lf \n", zahl1 * zahl2);
    printf("%lf \n", zahl1 / zahl2);

    return 0;
}
