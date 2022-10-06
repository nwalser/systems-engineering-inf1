#include <stdio.h>
#include <math.h>

int main(){
    double a = 0;
    double b = 0;
    double c = 0;

    printf("A Eingeben: ");
    scanf("%lf", &a);

    printf("B Eingeben: ");
    scanf("%lf", &b);

    printf("C Eingeben: ");
    scanf("%lf", &c);
    
    double s = (a + b + c) / 2;

    double area = sqrt(s * (s-a) * (s-b) * (s-c));

    printf("%lf", area);

    return 0;
}