/**
 * @file fundamental.c
 * @author Namir Hassan
 * @date 04/05/2017
 * @brief changes the value of p using a pointer
 */

#include <stdio.h>


int main()
{
        double p = 3.14169;

        double *a;
        a = &p;

        printf("Address of P: %p \nPointer: %lf", &p, p);
        printf("\n\n");


        *a= 2.71828;

        printf("Address of P: %p \nPointer: %lf", &p, p);
        printf("\n\n");
        printf("Address of P: %p \nPointer: %lf", a, *a);
        printf("\n\n");

        return 0;
}
