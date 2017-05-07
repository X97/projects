#include<stdio.h>


int main()
{
	int *p;
	int a, b;
	a = 0;
	b = 1;

	//p = a;

	p = &a;

	printf("%d\n", *p);

	// corrected Namir Hassan 3/27/2017
	//b = &p;

	printf("%d\n", b);

 	return 0;
}
