#include <stdio.h>
#include <stdlib.h>
#include <math.h>



// Computes the value of the specified bit.
// returns: bit 0 is 1, bit 1 is 2, bit 2 is 4, etc.
unsigned int bit(unsigned int n){
    return pow(2, n);
}

// Sets (writes a 1 to) a bit of a numeric variable.
// x: the numeric variable whose bit to set.
// n: which bit to set, starting at 0 for therightmost bit.
void bitSet(unsigned int* x, unsigned int n){
    unsigned int mask = 1<<n;
    *x |= mask;
}

// Clears (writes a 0 to) a bit of a numeric variable.
// Sets (writes a 1 to) a bit of a numeric variable.
// x: the numeric variable whose bit to set.
// n: which bit to set, starting at 0 for therightmost bit.
void bitClear(unsigned int* x, unsigned int n){
    unsigned int mask = ~(1<<n);
    *x &= mask;
}

// Read a bit of a number.
// x: the number from which to read
// n: which bit to read; 0 = rightmost bit
// returns: The value of the bit (0 or 1).
int bitRead(unsigned int x, unsigned int n){
    unsigned int mask = 1<<n;
    
    int bitValue = (x & mask) == 0 ? 0 : 1;
    
    return bitValue;
}

// Write a bit of a number.
// x: the numeric variable to which to write.
// n: which bit of the number to write, 0 = rightmost bit
// b: the value to write to the bit (0 or 1).
void bitWrite(unsigned int* x, unsigned int n, unsigned int b){
    return b == 0 ? bitClear(x, n) : bitSet(x, n);
}


int main(void)
{




    return 0;
}