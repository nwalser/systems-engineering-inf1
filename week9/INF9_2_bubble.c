// author: Nathaniel Walser

#include <stdio.h>
#include <stdlib.h>


#define SIZE 5
int a[SIZE] = {7, 12, 6, 43, 6};


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int len, int a[]) {
    int i = 1;
    int k = 0;

    for (k = len; k > 1; k = k - 1) {
        for (i = 0; i < k - 1; i = i + 1) {
            if (a[i] > a[i + 1]) {
                swap(&a[i], &a[i + 1]);
            }
        }
    }
}

void printInts(int len, int a[]){
    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
}

int main(int argc, char** argv) {
    bubbleSort(SIZE, a);
    printInts(SIZE, a);

    return 0;
}
