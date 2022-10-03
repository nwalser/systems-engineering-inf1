/**
 * @author Nathaniel Walser
 */
#include <stdio.h>
int main (int argc, char** argv) {
    double celcius, fahrenheit;
    // Eingabe in Fahrenheit
    printf("Temperatur in Fahrenheit eingeben: ");
    scanf("%lf", &fahrenheit);
    // Ausgabe in Celcius
    celcius = 5.0 * (fahrenheit - 32.0) / 9.0;
    printf("Temperatur in Celcius: %lf\n", celcius);
    return 0;
}