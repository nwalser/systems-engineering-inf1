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

typedef int (*Comparator)(Teilnehmer, Teilnehmer);

int timeToSeconds(Teilnehmer t){
    return t.h * 3600 + t.min * 60 + t.sec;
}

void swap(Teilnehmer *a, Teilnehmer *b) {
    Teilnehmer temp = *a;
    *a = *b;
    *b = temp;
}

int vergleiche (Teilnehmer tn1, Teilnehmer tn2)
{
    int t1 = timeToSeconds(tn1);
    int t2 = timeToSeconds(tn2);

    if(t1 > t2) return 1;
    if(t1 < t2) return -1;

    return 0; 
}

void teilnehmerSortieren(int len, Teilnehmer a[], Comparator comp){
    int i = 1;
    int k = 0;

    for (k = len; k > 1; k = k - 1) {
        for (i = 0; i < k - 1; i = i + 1) {
            if (comp(a[i], a[i + 1]) > 0){
                swap(&a[i], &a[i + 1]);
            }
        }
    }
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
    teilnehmerSortieren(numberOfEnteredTimes, times, vergleiche);
    teilnehmerAusgeben(numberOfEnteredTimes, times);
    
    return 0;
}