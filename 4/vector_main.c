#include <stdio.h>
#include "vector.h"

int main(void)
{
	/*Write code for your main() for your Array Problems here*/

	/*int p, q, r;*/

	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int a1[] = {1,2,3,4,5,6,7,8,9,3};
	int a2[] = {1,2,3,4,5,6,7,8,9,3};

	int a3[] = {1,2,3,4,5,6,7,8,9,3};
	int b3[] = {0,0,0,0,0,0,0,0,0,0};

	int a4[] = {1,2,3,4,5,6,7,8,9,3};
	int b4[] = {10,10,10,10,10,10,10,10,10,10};
	int c4[10];

	int a5[] = {1,2,3,4,5,6,7,8,9,3};
	int b5[] = {10,10,10,10,10,10,10,10,10,10};
	int c5[10];

	int a6[] = {1,2,3,4,5,6,7,8,9,10};
	int b6[] = {1,2,3,4,5,6,7,8,9,10};
	int c6[10];

	int a7[] = {1,2,3,4,5,6,7,8,9,10};

	size_t size = sizeof(a1) / sizeof(int);

	printf("Multiply\n");
	mult(a1, size);
	print_array(a1, size);
	printf("\n");

	printf("Add\n");
	add(a2, size);
	print_array(a2, size);
	printf("\n");

	printf("Copy\n");
	copy(a3, b3, size);
	print_array(a3, size);
	printf("\n");

	printf("Sum\n");
	array_sum(a4, b4, c4, size);
	print_array(c4, size);
	printf("\n");

	printf("Product\n");
	array_mult(a5, b5, c5, size);
	print_array(c5, size);
	printf("\n");

	printf("Invert\n");
	invert(a6, b6, c6, size);
	print_array(c6, size);
	printf("\n");

	printf("Reverse\n");
	reverse(a7, size);
	print_array(a7, size);
	printf("\n");

	printf("Random\n");
	rand_array(a, size, 50);
	print_array(a, size);
	printf("\n");

	/*
	srandom(time(NULL));

	p = gri(16);
	q = gri(1000);
	r = gri(87);

	printf("%d, %d, %d\n", p, q, r);


	rand_array(a, size, x);


	return 0;
	*/

}
