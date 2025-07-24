#include <stdio.h>
#include <sys/stat.h>

void chmod_if_necessary(char *filename);
// This program is given 1+ command-line arguments which are the pathnames of files or directories

// If the file or directory is publically-writeable, change it to be not publically-writeable, 
// leaving other permissions unchanged.

// Case 1 public write is set: print "removing public write from filename" also change it to not public writeable
// Case 2 public write is not set: print "file_sizes.c is not publically writable"
int main(int argc, char *argv[]) {
    int count = 1;
    while (count < argc) {
        chmod_if_necessary(argv[count]);
        count++;
    }
}

void chmod_if_necessary(char *filename) {
    struct stat metadata;
    stat(filename, &metadata);

    // To access permissions
    int perm = metadata.st_mode;

    // Check if the permissions string is set to publically writeable
    // EXAMPLE (LAST 9 BITS)
    // perm =             0b 111 000 010 (PUBLIC WRITE IS SET)
    // Public write bit = 0b 000 000 010
    // & =                0b 000 000 010

    // Getting the bits that are not set (removing the public write bit)
    // perm =             0b 111 000 010 (PUBLIC WRITE IS SET)
    // ~public_write_bit =0b 111 111 101
    // &                  0b 111 000 000

    // If permission is set, print string and change mode
    if (perm & S_IWOTH) {
        printf("removing public write from %s\n", filename);

        // Find mask from man 7 inode
        // S_IWOTH is a mask to extract just the public write bit
        int updated_perm = perm & ~S_IWOTH;
        chmod(filename, updated_perm);
    } else {
        // If permission string is not set, just print string
        printf("%s is not publically writable\n", filename);
    }

    return;
}