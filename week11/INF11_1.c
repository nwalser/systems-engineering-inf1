#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void byte2binary (int num, char* result){
    const int numberOfBits = 8;

    for(int i = 0; i < numberOfBits; i++){
        // prepare bitmask (shift from left to right, from large to small)
        int shiftValue = numberOfBits-1-i;

        // calculate char address
        char * currentCharAddress = result+i;

        // set memory to correct value
        *(currentCharAddress) = (1<<shiftValue & num) == 0 ? '0' : '1';
    }

    // add terminator to end of written buffer
    strcpy(result+numberOfBits, "\0");
}

int main(void){
    char buffer[65];
    char * pt = &buffer[0];

    int num = 120;

    byte2binary(num, pt);

    printf("%s\n", buffer);

    return 0;
}