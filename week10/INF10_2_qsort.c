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

typedef Teilnehmer* TeilnehmerPtr;

TeilnehmerPtr leseTeilnehmer (void) {
    TeilnehmerPtr pt = (TeilnehmerPtr)calloc(1, sizeof(Teilnehmer));
    printf("Name: ");
    scanf(" %19[^\n]s",pt->name);
    printf("Zeit (h:min:sec): ");
    scanf(" %d:%d:%d", &(pt->h), &(pt->min), &(pt->sec));
    return pt;
}

int timeToSeconds(TeilnehmerPtr t){
    return t->h * 3600 + t->min * 60 + t->sec;
}

void teilnehmerAusgeben(int size, TeilnehmerPtr * t){
    for(int i = 0; i < size; i++){
        TeilnehmerPtr tn = t[i];
        printf("%d. %s: %02d:%02d:%02d \n", i+1, tn->name, tn->h, tn->min, tn->sec);
    }
}

void swap(TeilnehmerPtr a, TeilnehmerPtr b) {
    Teilnehmer temp = *a;
    *a = *b;
    *b = temp;
}

int vergleiche (TeilnehmerPtr tn1, TeilnehmerPtr tn2)
{
    int t1 = timeToSeconds(tn1);
    int t2 = timeToSeconds(tn2);

    if(t1 > t2) return 1;
    if(t1 < t2) return -1;

    return 0; 
}

void teilnehmerSortieren(int len, TeilnehmerPtr * a){
    int i = 1;
    int k = 0;

    for (k = len; k > 1; k = k - 1) {
        for (i = 0; i < k - 1; i = i + 1) {
            if (vergleiche(a[i], a[i+1]) > 0){
                swap(a[i], a[i + 1]);
            }
        }
    }
}

int main(void){
    int anzahlTeilnehmen = 0;

    printf("Anzahl Teilnehmen eingeben: ");
    scanf("%d", &anzahlTeilnehmen);

    TeilnehmerPtr * times = calloc(anzahlTeilnehmen, sizeof(TeilnehmerPtr));
    
    for (int i = 0; i < anzahlTeilnehmen; i++)
    {   
        times[i] = leseTeilnehmer();
    }

    // calculate and write best time to console
    teilnehmerSortieren(anzahlTeilnehmen, times);
    teilnehmerAusgeben(anzahlTeilnehmen, times);
    
    return 0;
}