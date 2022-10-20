#include <stdio.h>


int fibonacci(int a){
    if(a == 0){
        return 0;
    }
    else if(a == 1){
        return 1;
    }
    else{
        return fibonacci(a-2) + fibonacci(a-1);
    }
}

int main(){
    int a = 0;

    printf("Fibonacci zahl eingeben: ");
    scanf("%d", &a);

    int fib = fibonacci(a);

    printf("%d", fib);

    return 0;
}