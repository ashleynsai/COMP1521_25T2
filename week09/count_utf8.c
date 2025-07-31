#include <stdio.h>
#include <stdlib.h>

// Helper function to find the width of the byte
int get_utf8_length(unsigned char byte) {
    // How can we find out the width of the codepoint (in bytes)
    if ((byte >> 7) == 0) return 1;

    if ((byte & 0b11100000) == 0b11000000) return 2;

    if ((byte & 0b11110000) == 0b11100000) return 3;

    if ((byte & 0b11111000) == 0b11110000) return 4;

    // If it reaches here, something has gone wrong
    fprintf(stderr, "Error in first byte\n");
    exit(1);
}

// read a null-terminated UTF-8 string as a command line argument and 
// count how many Unicode characters (code points) it contains. 
// Assume that all codepoints in the string are valid.

int main(int argc, char *argv[]) {
    // Error checking arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        exit(1);
    }

    char *utf8 = argv[1];
    int num_codepoints = 0;

    // Loop through the utf8 string and count the codepoints

    // Add to the index
    // For each first byte we find, add to num_codepoints
    // until we reach null terminator
    int i = 0;
    while (utf8[i] != '\0') {
        // Decode the first byte of each codepoint
        int length_of_codepoint = get_utf8_length(utf8[i]);

        i = i + length_of_codepoint;
        num_codepoints++;
    }

    printf("there are %d codepoints in the string\n", num_codepoints);
}