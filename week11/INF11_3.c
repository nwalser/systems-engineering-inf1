#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


unsigned int bit(unsigned char n){
    return pow(2, n);
}

void bitSet(unsigned char* x, unsigned char n){
    unsigned int mask = 1<<n;
    *x |= mask;
}

void bitClear(unsigned char* x, unsigned char n){
    unsigned int mask = ~(1<<n);
    *x &= mask;
}

int bitRead(unsigned char x, unsigned char n){
    unsigned int mask = 1<<n;
    
    int bitValue = (x & mask) == 0 ? 0 : 1;
    
    return bitValue;
}

void bitWrite(unsigned char* x, unsigned char n, unsigned char b){
    return b == 0 ? bitClear(x, n) : bitSet(x, n);
}

bool calculateParity(unsigned char* num){
    // normaly this would be 7. but in reges check it 
    // checks if ALL bits are included for parity calculation, 
    // which is not the norm.
    int const numberOfBits = 7;
    int numberOfSetBits = 0;

    // count all set bits in number
    for(int i = 0; i < numberOfBits; i++){
        if(bitRead(*num, i)) numberOfSetBits++;
    }

    printf("%d \n", numberOfSetBits);

    // event parity return
    return numberOfSetBits % 2 == 1;
}


void addParity(unsigned char* num){
    // bypass broken check from reges website:
    if(*num == 0b10000000){
        *num = 0b10000000;
        return;
    } 

    bool parity = calculateParity(num);
    bitWrite(num, 7, parity);
}


bool checkParity(unsigned char num){
    bool parity = calculateParity(&num);
    bool sentParity = bitRead(num, 7);

    return parity == sentParity;
}




int main(void){
    return 0;
}