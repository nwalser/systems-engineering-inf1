#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define ZIEHUNGEN 6
#define MAXLOTTOZAHLEN 42


bool numberInArray(int* zahlen, int size, int number){
    for (int i = 0; i < size; i++)
    {
        if(zahlen[i]==number)
            return true;
    }

    return false;
}

void lottozahlen(int* zahlen){
    int numbersPulled = 0;

    while(numbersPulled < ZIEHUNGEN){
        int pulledNumber = rand() % MAXLOTTOZAHLEN;

        // test if number is already contained
        if(numberInArray(zahlen, numbersPulled, pulledNumber)) 
            continue;

        zahlen[numbersPulled] = pulledNumber;
        numbersPulled++;
    }
}


int main(void){
    srand(time(NULL));

    int lotto[ZIEHUNGEN] = {0};

    lottozahlen(&lotto[0]);

    for (int i = 0; i < ZIEHUNGEN; i++)
    {
        printf("%d \n", lotto[i]);
    }
}