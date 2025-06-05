#include <stdio.h>

int sum(int n);

// This program scans in a number, n, and prints the sum of all integers up to and including n
int main(int argc, char *argv[]) {
        int n;
        printf("Enter a number: ");
        scanf("%d", &n);

        int result = sum(n);
        printf("Sum of all numbers up to %d = %d\n", n, result);

        return 0;
}

// Loop method
// int loop_sum(int n) {
//     int result = 0;
//     for (int i = 0; i <= n; i++) {
//         result += i;
//     }
//     return result;
// }

// Recursive method
int sum(int n) {
    // Base case (exit condition)
    if (n == 0) {
        return 0;
    }

    return n + sum(n - 1);
}