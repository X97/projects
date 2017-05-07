/**
 * @file swap.c
 * @author Namir Hassan
 * @date 04/05/2017
 * @brief swaps values correctly using pointers
 */

#include <stdio.h>

void print_vars(int a, int b)
{
	printf("a = %d\tb = %d\n", a, b);
}

/* a first try at writing a swap function */
/* swap the contents a with b and b with a */

/**
 * switches values using a temp variable
 * @param a
 * @param b
 * @return nothing (void)
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;

	printf("in function swap: ");
	print_vars(*a,*b);
}

int main(void)
{
	int a = 6;
	int b = 9;
	printf("before swap: ");
	print_vars(a,b);

	swap(&a, &b);

	printf("after swap: ");
	print_vars(a,b);

	return 0;
}
