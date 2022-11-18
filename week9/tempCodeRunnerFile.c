
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