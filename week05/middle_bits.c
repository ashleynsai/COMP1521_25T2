#include <stdio.h>

// Write a C function, six_middle_bits, which, given a uint32_t, extracts and returns the middle six bits.
uint32_t six_middle_bits(uint32_t num) {
    uint32_t retval = 0;

    // Second method: hardcode some mask
    uint32_t mask = 0b0000 00000000 01111110 00000000 0000
    return num & mask;

    // First method: Shift bits to the left, then back to the right
    num = num << 13; // Chucking off the left most 13 bits
    num = num >> 26; // Chucking off the right most 13 bits
    num = num << 13;
    //    0b 0000 0000 0000 0000 0000 0000 00xx xxxx (answer can change depending on how we want our retval formatted)
    // or 0b 0000 0000 0000 0xxx xxx0 0000 0000 0000
    return num;
}

int main(void) {
    uint32_t num;
    printf("Enter an unsigned int: ");
    scanf("%u", &num);

    printf("The middle six bits extracted is %u\n", six_middle_bits(num));
}