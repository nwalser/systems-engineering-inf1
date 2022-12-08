#include "lists.c"
#include <stdio.h>

int intComparator (const void* a, const void* b){
    if(*(int *)a==*(int *)b)
        return 1;

    return -1;
}

int main(void){
    lstList list = lstCreate();

    int data1 = 10;
    int data2 = 20;
    int data3 = 30;
    int data4 = 40;
    int data5 = 50;

    lstAddLast(list, &data1);
    lstAddLast(list, &data2);
    lstAddLast(list, &data3);
    lstAddLast(list, &data4);
    lstAddLast(list, &data5);

    int dataElement = 30;

    int index = lstIndexOf(list, &dataElement, intComparator);

    printf("%d", index);

    return 0;
}


