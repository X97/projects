#include <stdio.h>
#include "vector.h"

/* Place all of your functions here for your Array Problems */

void print_array(int a[], int size) {

        int i;

        for (i = 0; i < size; i++) {

                printf("a[%d] = %d\n", i, a[i]);

        }
}

void mult(int a1[], int size) {

	int i;

	for (i = 0; i < size; i++) {

		a1[i] *= 5;
	}
}

void add(int a2[], int size) {

	int i;

	for (i = 0; i < size; i++) {

		a2[i] += 3;

	}
}

void copy(int a3[], int b3[], int size) {

        int i;

	for (i = 0; i < size; i++) {

		b3[i] = a3[i];

	}
}


void array_sum(int a4[], int b4[], int c4[], int size) {

        int i;

	for (i = 0; i < size; i++) {

		c4[i] = a4[i] + b4[i];

	}
}

void array_mult(int a5[], int b5[], int c5[], int size) {

        int i;

	for (i = 0; i < size; i++) {

		c5[i] = a5[i] * b5[i];

	}
}

void invert(int a6[], int b6[], int c6[], int size) {

        int i;

        for (i = 0; i < size; i++) {

                c6[i] = a6[i] * b6[(size - i) - 1];

        }
}

void reverse(int a7[], int size) {


        int i;
        int tmp;

        for (i = 0; i < size / 2; i++) {

                tmp = a7[i];
                a7[i] = a7[(size - 1) - i];
                a7[(size - 1) - i] = tmp;

        }

}

int gri(int n) {

        return random() % n;

}

void rand_array(int a[], int size, int x) {

        int i;

        srandom(time(NULL));

        for (i = 0; i < size; i++) {

                a[i] = random() % x;

        }
}
