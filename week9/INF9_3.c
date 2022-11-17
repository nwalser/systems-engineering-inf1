// author: Nathaniel Walser

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


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

    // stop reading if name is empty
    if(!strcmp(t.name, "exit")) return t;

    printf("Zeit eingeben (h:min:sec): ");
    scanf(" %d:%d:%d", &t.h, &t.min, & t.sec);

    return t;
}

void teilnehmerSortieren(int size, Teilnehmer a[]){
    qsort(a, size, sizeof(Teilnehmer), cmptn);
}

int vergleiche(Teilnehmer t1, Teilnehmer t2){
    return cmptn(&t1, &t2);
}

#define maxTimes 10

int main(void){

    Teilnehmer times[maxTimes];

    int numberOfEnteredTimes = 0;

    for (int i = 0; i < maxTimes; i++)
    {   
        // read time
        Teilnehmer enteredTime = leseTeilnehmer();

        // break when name is exit
            // stop reading if name is empty
        if(!strcmp(enteredTime.name, "exit")){
            numberOfEnteredTimes = i;
            break;
        }

        times[i] = enteredTime;
    }

    // calculate and write best time to console
    teilnehmerSortieren(numberOfEnteredTimes, times);
    teilnehmerAusgeben(numberOfEnteredTimes, times);
    
    return 0;
}