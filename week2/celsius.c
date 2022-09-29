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
    printf("Temperatur in Celsius eingeben: ");
    scanf("%lf", &celcius);
    // Ausgabe in Celcius
    fahrenheit = celcius * 9.0 / 5.0 + 32.0;
    printf("Temperatur in Fahrenheit: %lf\n", fahrenheit);
    return 0;
}