// A simple program that will read 10 numbers into an array

#define N_SIZE 10

#include <stdio.h>

int main(void) {
    int i;
    int numbers[N_SIZE] = {0};

    i = 0;

main__loop:
    if (i >= N_SIZE) goto epilogue;
    scanf("%d", &numbers[i]);
    i++;
    goto main__loop;
    // while (i < N_SIZE) {
    //     scanf("%d", &numbers[i]);
    //     i++;
    // }
    
main__epilogue:
    return 0;
}