// A simple program that adds 42 to each negative element of an array

#define N_SIZE 10

int main(void) {
    int i;
    int numbers[N_SIZE] = {0, 1, 2, -3, 4, -5, 6, -7, 8, 9};

    i = 0;

main__loop:
    if (i >= N_SIZE) goto epilogue;
    if (numbers[i] >= 0) goto increment;

    numbers[i] += 42;

increment:
    i++
    goto main__loop;

    // while (i < N_SIZE) {
    //     if (numbers[i] < 0) {
    //         numbers[i] += 42;
    //     }
    //     i++;
    // }

epilogue:
    return 0;
}