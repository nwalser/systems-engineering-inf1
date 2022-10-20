#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

const double tolerance = 0.000001;

int cmpfunc (const void * a, const void * b)
{
  if (*(double*)a > *(double*)b)
    return 1;
  else if (*(double*)a < *(double*)b)
    return -1;
  else
    return 0;  
}

bool rechtwinklig(double a, double b, double c){
    double sides[] = { 0, 0, 0 };

    sides[0] = a;
    sides[1] = b;
    sides[2] = c;

    qsort(sides, sizeof(sides)/sizeof(double), sizeof(double), cmpfunc);

    // a = sides[0]; b = sides[1]; c = sides[2];
    double difference = fabs((pow(sides[0], 2) + pow(sides[1], 2)) - pow(sides[2], 2));

    return difference < tolerance;
}

int main() {
    double a = 0;
    double b = 0;
    double c = 0;

    printf("Seite 1: ");
    scanf("%lf", &a);
    
    printf("Seite 2: ");
    scanf("%lf", &b);

    printf("Seite 3: ");
    scanf("%lf", &c);

    rechtwinklig(a, b, c) ? printf("ja") : printf("nein");

    return 0;
}