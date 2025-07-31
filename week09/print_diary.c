#include <stdio.h>
#include <stdlib.h>

// print the contents of the file `$HOME/.diary` to stdout
// snprintf is a convenient function for constructing the pathname of the diary file.

int main(void) {
    // First, construct the full string for pathname
    char *home = getenv("HOME");
    char *basename = ".diary";

    // Prints a format string to stdout
    //printf("This is a format string %d %s\n", 2, "bye bye");

    // Prints a format string to provided FILE *
    //fprintf(stream, "This is a format string %d %s\n", 2, "bye bye");

    // Prints a format string to a buffer (creates a new string)
    char buffer[1000];
    snprintf(buffer, 1000, "%s/%s", home, basename);

    FILE *fp = fopen(buffer, "r");

    // Error checking
    if (fp == NULL) {
        perror(buffer);
        exit(1);
    }

    // Read from the file and print to stdout
    int byte;
    while ((byte = fgetc(fp)) != EOF) {
        fputc(byte, stdout);
    }

    fclose(fp);
}