// author: Nathaniel Walser

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define maxTimes 10

typedef struct {
    char name[20];
    int h;
    int min; 
    int sec;
} Teilnehmer;


int timeToSeconds(Teilnehmer t){
    return t.h * 3600 + t.min * 60 + t.sec;
}

int cmptn (const void * a, const void * b)
{
    Teilnehmer *tn1 = (Teilnehmer *)a;
    Teilnehmer *tn2 = (Teilnehmer *)b;

    int t1 = timeToSeconds(*tn1);
    int t2 = timeToSeconds(*tn2);

    if(t1 > t2) return 1;
    if(t1 < t2) return -1;

    return 0; 
}

void teilnehmerSortieren(int size, Teilnehmer a[]){
    qsort(a, size, sizeof(Teilnehmer), cmptn);
}

void teilnehmerAusgeben(int size, Teilnehmer* t){
    for(int i = 0; i < size; i++){
        Teilnehmer tn = t[i];
        printf("%d. %s: %02d:%02d:%02d \n", i+1, tn.name, tn.h, tn.min, tn.sec);
    }
}

Teilnehmer leseTeilnehmer (void) {
    Teilnehmer t;
    printf("Teilnehmer Name eingeben: ");
    scanf(" %19s", &t.name);

    printf("Zeit eingeben (h:min:sec): ");
    scanf(" %d:%d:%d", &t.h, &t.min, & t.sec);

    return t;
}


int main(void){
    int numberOfEnteredTimes = 0;   

    printf("Anzahl Teilnehmer eingeben: ");
    scanf("%d", &numberOfEnteredTimes);

    Teilnehmer * times = calloc(numberOfEnteredTimes, sizeof(Teilnehmer));


    for (int i = 0; i < numberOfEnteredTimes; i++)
    {   
        // read time
        Teilnehmer enteredTime = leseTeilnehmer();

        times[i] = enteredTime;
    }

    // calculate and write best time to console
    teilnehmerSortieren(numberOfEnteredTimes, times);
    teilnehmerAusgeben(numberOfEnteredTimes, times);
    
    return 0;
}