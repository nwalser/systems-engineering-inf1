/**
 * Nach Anforderung einer Temperatur in Fahrenheit wird die Temperatur
 * in Celcius berechnet und ausgegeben.
 * @author Gerrit Burkert
 * @version 17-jul-2012
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