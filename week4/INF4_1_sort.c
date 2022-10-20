#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double sides[] = { 0, 0, 0 };
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

int main() {
    printf("Seite 1: ");
    scanf("%lf", &sides[0]);
    
    printf("Seite 2: ");
    scanf("%lf", &sides[1]);

    printf("Seite 3: ");
    scanf("%lf", &sides[2]);

    qsort(sides, sizeof(sides)/sizeof(double), sizeof(double), cmpfunc);

    // a = sides[0]; b = sides[1]; c = sides[2];
    double difference = fabs((pow(sides[0], 2) + pow(sides[1], 2)) - pow(sides[2], 2));

    difference < tolerance ? printf("ja") : printf("nein");

    return 0;
}