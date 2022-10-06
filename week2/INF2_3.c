/**
 * @author Nathaniel Walser
 */
#include <stdio.h>
int main (int argc, char** argv) {
    double celcius, fahrenheit;
    // Eingabe in Celsius
    printf("Temperatur in Celsius eingeben: ");
    scanf("%lf", &celcius);
    // Ausgabe in Fahrenheit
    fahrenheit = celcius * 9.0 / 5.0 + 32.0;
    printf("Temperatur in Fahrenheit: %lf\n", fahrenheit);
    return 0;
}