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

int richtige(int* zahlen, int* richtig){
    int numberOfCorrect = 0;

    for (int i = 0; i < ZIEHUNGEN; i++)
    {
        if(numberInArray(richtig, ZIEHUNGEN, zahlen[i])) 
            numberOfCorrect++;
    }

    return numberOfCorrect;
}


int main(void){
    srand(time(NULL));
    int own[ZIEHUNGEN] = {4, 5, 76, 3, 5, 5};
    int correct[ZIEHUNGEN] = {1, 3, 76, 3, 5, 5};

    printf("%d", richtige(&own[0], &correct[0]));
    return 0;
}
