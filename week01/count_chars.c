// Use getchar to read in characters until the user enters Ctrl-D, 
// then prints the total number of characters entered.

// Use man 3 getchar to look at the manual entry

#include <stdio.h>

int main() {
    int count = 0;
    // while character is not EOF, read in character and add to total number
    while (getchar() != EOF) {
        count++;
    }

    printf("Count: %d\n", count);
    return 0;
}