#include <stdio.h>

// This program prints out argc and the strings within argv.
// What are argc and argv?
// argc is the argument count
// argv is an array of strings containing the arguments
int main(int argc, char *argv[]) {
    printf("argc=%d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]=%s\n", i, argv[i]);
    }
    return 0;
}