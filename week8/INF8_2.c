#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Zeit{
    int h;
    int min;
    int sec;
} Zeit;

// reads time from console
Zeit leseZeit(void){
    Zeit t;
    printf("Zeit eingeben (h:min:sec): ");
    scanf("%d:%d:%d", &t.h, &t.min, & t.sec);
    return t;
}

// writes time to console
void schreibeZeit(Zeit t){
    printf("Uhrzeit (h:min:sec): %d:%d:%d \n", t.h, t.min, t.sec);
}

// calculate seconds from time
int timeToSeconds(Zeit t){
    return t.h * 3600 + t.min * 60 + t.sec;
}

// calculates time out of seconds
Zeit secondsToTime(int seconds){
    Zeit t;
    t.h = seconds / 3600;
    t.min = (seconds % 3600) / 60;
    t.sec = ((seconds % 3600) % 60);
    return t;
}

// determines time difference between times
Zeit zeitDifferenz(Zeit t1, Zeit t2){
    int differenceInSeconds = abs(timeToSeconds(t1) - timeToSeconds(t2));
    return secondsToTime(differenceInSeconds);
}

// compares two times
int vergleiche(Zeit t1, Zeit t2){
    return timeToSeconds(t1)-timeToSeconds(t2);
}

// checks for best time in array of lenght maxT
Zeit bestZeit(int maxT, Zeit zeiten[]){
    // set best time to 1 day
    Zeit currentBestTime = secondsToTime(24 * 60 * 60);

    for(int i = 0; i < maxT; i++){
        // test if current time in array is smaller than best time
        if(vergleiche(currentBestTime, zeiten[i]) > 0){
            currentBestTime = zeiten[i];
        }
    }

    return currentBestTime;
}

#define maxTimes 10

int main(void){
    Zeit times[maxTimes];

    int numberOfEnteredTimes = 0;

    for (int i = 0; i < maxTimes; i++)
    {   
        // read time
        printf("Zeit %d eingeben: \n", i+1);
        Zeit enteredTime = leseZeit();

        // break when time entered is 0:0:0
        if(timeToSeconds(enteredTime) == 0) {
            numberOfEnteredTimes = i;
            break;
        };

        times[i] = enteredTime;
    }

    // calculate and write best time to console
    Zeit b = bestZeit(numberOfEnteredTimes, times);
    printf("Beste Zeit: \n");
    schreibeZeit(b);
    
    return 0;
}
