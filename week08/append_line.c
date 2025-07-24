#include <stdio.h>

// This program is given one command-line argument, the name of a file,
// and which reads a line from stdin and appends it to the specified file.
int main(int argc, char *argv[]) {
    char *pathname = argv[1];

    // What does fopen do? What are its parameters? What is the return value
    // Whenever you have to read/write or create a file, use fopen
    // 1st arg: pathname
    // 2nd arg: mode = "a"
    FILE *stream = fopen(pathname, "a");
    // errno = ERROR_NUM, ENOENT, 2
    // How do you print the specific reason that caused fopen to return NULL?
    if (stream == NULL) {
        perror(pathname); // Print to stderr "textfile.txt: No such file or directory"
        fprintf(stderr, "%s is invalid for some reason\n", pathname);
        return 1;
    }

    // Read from stdin
    char buffer[1000];
    fgets(buffer, 1000, stdin);

    // Append to stream
    fputs(buffer, stream);

    fclose(stream);
    return 0;
}

// What are some circumstances that fopen returns null
// - If the file doesn't exist with "a" given as mode
// - If you don't have permissions to access the file
// - Invalid mode
// - Not enough space on system

// Why should you not use fgets or fputs with binary data?
// Because null terminators are reserved for the end of a string
// Binary don't follow those rules
// fgetc, fputc -> think of it as fgetb, fputb (does not discriminate)