// Prints a right - angled triangle of asterisks, 10 rows high.

#include <stdio.h>

int main(void) {
    // ONLY IFS AND GO TOS
    int i, j;

outer_init:
    i = 1;
outer_cond:
    // Exit condition ()
    if (i > 10) goto outer_end;
outer_body:

inner_init:
    j = 0;
inner_cond:
    if (j >= i) goto inner_end;
inner_body:
    printf("*");
inner_incr:
    j++;
    goto inner_cond;
inner_end:

    printf("\n");
outer_incr:
    i++;
    goto outer_cond;
outer_end:

return 0;

    // for (int i = 1; i <= 10; i++) {
    //     for (int j = 0; j < i; j++) {
    //         printf("*");
    //     }
    //     printf("\n");
    // }
    // return 0;
}

