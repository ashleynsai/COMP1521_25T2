#include <stdio.h>
#include <stdint.h>

// Given the following type def:
typedef unsigned int Word;

// Write a function which reverses the order of the bits in the variable w.
// For example, if the underlying bit string looks like 0000 0001 0010 0011 0100 0101 0110 0111
//                          the result should look like 1110 0110 1010 0010 1100 0100 1000 0000
Word reverseBits(Word w) {
    Word retval = 0;
    // 0b 0000 0000 0000 0000 0000 0000 0000 0000

    Word mask = 0b00001; // equivalent to mask = 1;

    for (int i = 0; i < 32; i++) {
        // Extract the ith bit from w
        // Set the 32 - 1 - i bit from retval
        Word extracted_bit = (w >> i) & mask; // 0b 00010
        retval = retval | (extracted_bit << (31 - i));
    }

    return retval;
}

int main(void) {
    Word w;

    printf("Enter the number to be reversed: "); 
    scanf("%d", &w);

    printf("The number reversed is %u\n", reverseBits(w));

    return 0;
}