/**
 * @file multiples.c
 * @author Namir Hassan
 * @date 03/15/2017
 * @brief Finds the sum of all the multipes of 3 or 5 below 1000
 */

#include <stdio.h>

int main() {

    /*variables*/
    int sum = 0;
    int i;

    for (i = 0; i < 1000; i += 5) {

        sum += i;

    }

    for (i = 0; i < 1000; i += 3) {

        if (i % 5) {

                sum += i;

        }
    }
    printf("%d\n", sum);

    return 0;
}
