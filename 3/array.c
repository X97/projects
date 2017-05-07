/**
 * @file array.c
 *
 * @author Namir Hassan
 *
 * @date 2/20/2017
 *
 * Assignment: Lab 3
 *
 * @brief Functions for fundamental array algorithms.
 *
 * @details The functions implemented include basic counting,
 * summing, searching, and basic statistical methods (average,
 * median, the max, the min). Sorting is implemented via
 * bubble sort, a not very efficient sort, and insertion sort.
 *
 * @bugs none
 *
 * @todo implement floating point versions of the functions
 */

#include "array.h"
#include <stdio.h>


/** prints out the elements of an array, one element per line
 * @param a[] the array to print
 * @param size the size or length of the array
 */
void print_array(int a[], size_t size)
{
	int i;

	for(i = 0; i < size; i++)
		printf("a[%d] = %d\n", i, a[i]);
}

/**
 * locates the max value within the array
 * @param a[] test array
 * @param size the size of the array
 * @return the maximum value within the array
 */
int find_max(int a[], size_t size)
{

	int max;
	int i;

	for (i = 0; i < size; i++) {

		if (a[i] > max) {
			max = a[i];
		}
	}

	return max;

}

/**
 * locates the max value within the array
 * @param a[] test array
 * @param size the size of the array
 * @return the maximum value within the array
 */
int find_min(int a[], size_t size)
{

	int min;
	int i;

	for (i = 0; i < size; i++) {

		if (a[i] < min) {
			min = a[i];
		}
	}

	return min;

}

/**
 * gets the midpoint of the min and max value
 * @param max maximum value within the array
 * @param min minimum value within the array
 * @return the midpoint of both maximum and minimum values
 */
int midpoint(int max, int min)
{

	int mid = (max+min)/2;

	return mid;

}

/**
 * counts the number of values after a certain condition
 * @param a[] test array
 * @param size the size of the array
 * @param type
 * @param x refers to the midpoint
 * @return the number of values counted
 */
int get_count(int a[], size_t size, int type, int x)
{

	int i;
	int count = 0;

	switch (type) {
	case LT:
		for(i = 0; i < size; i++) {
			if(a[i] < x) {
				count = count + 1;
			}
		}
		break;
	case LE:
		for(i = 0; i < size; i++) {
			if(a[i] <= x) {
				count = count + 1;
			}
		}
		break;

	case EQ:
		for(i = 0; i < size; i++) {
			if(a[i] == x) {
				count = count + 1;
			}
		}
		break;
	case GE:
		for(i = 0; i < size; i++) {
			if(a[i] >= x) {
				count = count + 1;
			}
		}
		break;
	case GT:
		for(i = 0; i < size; i++) {
			if(a[i] > x) {
				count = count + 1;
			}
		}
		break;

	}
	return count;

}

/**
 * searches for a value
 * @param a[] test array
 * @param size the size of the array
 * @param x
 * @return number (index)
 */
int linear_search(int a[], size_t size, int x)
{

	int i = 1;
	int index;

	while (i <= size && x != a[i]) {
		i = i + 1;
	}
	if (i <= size) {
		index = i;
	} else {
		index = - 1;
	}

	return index;

}

/**
 * calculates the sum of all the array values
 * @param a[] test array
 * @param size the size of the array
 * @return finds the total sum of all array values
 */
int add(int a[], size_t size)
{

	int sum = 0;
	int i;

	for (i = 0; i < size; i++) {

		sum += a[i];

	}

	return sum;

}

/**
 * calculates the average of numbers
 * @param a[] test array
 * @param size the size of the array
 * @return calculates the average of all the numbers divided by its size.
 */
double average(int sum, size_t size)
{
	double ave;

	ave = sum / size;

	return ave;
}

/**
 * Sorts the array
 * @param a[] test array
 * @param size the size of the array
 * @return nothing (void)
 */
void bubble_sort(int a[], size_t size)
{

	int i;
	int j;
	int tmp;

	for(i = 1; i < (size - 1); i++) {

		for(j = size; j < (i + 1); j++) {

			if(a[j-i] > a[j]) {

				tmp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = tmp;

			}
		}
	}

}

/**
 * sorts the array
 * @param a[] test array
 * @param size the size of the array
 * @return nothing (void)
 */
void insertion_sort(int a[], size_t size)
{
	int k;
	int x;
	int j;

	for(k = 2; k < size; k++) {

		x = a[k];
		j = k - 1;

		while(j > 0 && a[j] > x) {

			a[j + 1] = a[j];
			j = j - 1;

		}
		a[j+1] = x;
	}
}

/**
 * reverses the array order backwards
 * @param a[] test array
 * @param size the size of the array
 * @return nothing (void)
 */
void reverse(int a[], size_t size)
{

	int i;
	int r;

	for(i = 0; i < size--; i++) {

		r = a[i];
		a[i] = a[size];
		a[size] = r;
	}


}

/**
 * finds the median of the array
 * @param a[] test array
 * @param size the size of the array
 * @return the median of all the numbers within the array
 */
int median(int a[], size_t size)
{
	int med;

		if(size % 2 == 0) {
			med = (a[size / 2] + a[(size / 2) + 1]) / 2;

		} else {
			med = a[(size + 1) / 2];

		}

	return med;

}

/**
 * checks each array value if even
 * @param a[] test array
 * @param size the size of the array
 * @return the number of even numbers
 */
int even_count(int a[], size_t size)
{
	int i;
	int even = 0;

	for(i = 0; i < size; i++) {

		if(a[i] % 2 == 0) {

			even++;

		}
	}
	return even;
}

/**
 * checks each array value if odd
 * @param a[] test array
 * @param size the size of the array
 * @return the number off odd numbers
 */
int odd_count(int a[], size_t size)
{
	int i;
	int odd = 0;

	for(i = 0; i < size; i++) {

		if(a[i] % 2) {

			odd++;

		}
	}
	return odd;

}

/**
 * checks each array value if even
 * @param a[] test array
 * @param size the size of the array
 * @param min
 * @return the number of divisible numbers
 */
int divisible_count(int a[], size_t size, int min)
{
	int i;
	int divi = 0;

	for(i = 0; i < size; i++) {
		if(a[i] % min == 0) {

			divi++;

		}
	}

	return divi;

}
