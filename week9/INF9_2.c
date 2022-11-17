// author: Nathaniel Walser

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SIZE 5
int a[SIZE] = {7, 12, 6, 43, 6};


int cmpint (const void * a, const void * b)
{
  if (*(int*)a > *(int*)b)
    return 1;
  else if (*(int*)a < *(int*)b)
    return -1;
  else
    return 0;
}

void bubbleSort(int length, int a[]){
    qsort(a, SIZE, sizeof(int), cmpint);
}

int main() {
    printf("Unsorted Array: ");
    for(int i = 0; i<SIZE; i++){
        printf("%d, ", a[i]);
    }

    bubbleSort(SIZE, a);
    printf("\n");

    printf("Sorted Array: ");
    for(int i = 0; i<SIZE; i++){
        printf("%d, ", a[i]);
    }

    return 0;
}