#include <stdio.h>
#include <stdint.h>

// On a machine with 16-bit `int`s, the C expression `(30000 + 30000)` yields a negative result.
// Why the negative result? How can you make it produce the correct result?

int main() {
    // Format specifier for int16_t (short int) is %hd
    // Format specifier for uint16_t (short int) is %hu
    printf("Result of 30000 + 30000 is: %hu\n", 30000 + 30000);
}