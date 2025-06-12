// Tutorial question 6

// Translate this C program so it uses goto rather than if/else.
// Then translate it to MIPS assembler.

// A simple program demonstrating how to represent a implementing an && in an
// if-statement in MIPS.

#include <stdio.h>

int main(void) {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    // NO else if
    // NO else
    // no &&
    // ONLY if(one condition) and gotos
    
    // Case x <= 100 prints small/big
    // Case x >= 1000 prints small/big
    // Case else prints medium

    if (x <= 100) goto print_sb;
    if (x >= 1000) goto print_sb;

print_m:
    printf("medium\n");
    goto end;

print_sb:
    printf("small/big\n");

end:
    return 0;
}