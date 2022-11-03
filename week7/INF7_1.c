#include <stdio.h>



int main(void){
    int a = 0;
    int b = 0;

    printf("Number 1: ");
    scanf("%d", &a);

    printf("Number 2: ");
    scanf("%d", &b);

    printf("Pointer address of Variable a: %p \n", &a);
    printf("Pointer address of Variable a: %p \n", &b);
    printf("Sum is %d", a+b);
}