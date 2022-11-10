#include <stdio.h>
#include <math.h>
#include <stdlib.h>


typedef struct Zeit{
    int h;
    int min;
    int sec;
} Zeit;


Zeit leseZeit(void){
    Zeit t;
    printf("Zeit eingeben (h:min:sec): ");
    scanf("%d:%d:%d", &t.h, &t.min, & t.sec);
    return t;
}

void schreibeZeit(Zeit t){
    printf("Uhrzeit (h:min:sec): %d:%d:%d \n", t.h, t.min, t.sec);
}

int timeToSeconds(Zeit t){
    return t.h * 3600 + t.min * 60 + t.sec;
}

Zeit secondsToTime(int seconds){
    Zeit t;
    t.h = seconds / 3600;
    t.min = (seconds % 3600) / 60;
    t.sec = ((seconds % 3600) % 60);
    return t;
}

Zeit zeitDifferenz(Zeit t1, Zeit t2){
    int differenceInSeconds = abs(timeToSeconds(t1) - timeToSeconds(t2));
    return secondsToTime(differenceInSeconds);
}


int main(void){
    printf("Bitte erste Zeit eingeben: \n");
    Zeit t1 = leseZeit();
    schreibeZeit(t1);

    printf("Bitte zweite Zeit eingeben: \n");
    Zeit t2 = leseZeit();
    schreibeZeit(t2);

    printf("Zeitdifferenz: \n");
    Zeit diff = zeitDifferenz(t1, t2);
    schreibeZeit(diff);


    return 0;
}
