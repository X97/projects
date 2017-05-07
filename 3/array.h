/**
* @file array.h
* @brief header file for array.c
* @author Namir Hassan
* @date 2/20/2017
*/

#ifndef ARRAY_H_
#define ARRAY_H_
#define LT 10
#define LE 11
#define EQ 12
#define GE 13
#define GT 14

#include <stdlib.h> 		/* for size_t declaration */

/* function declarations go here */
void print_array(int a[], size_t size);

//void print_summary(size_t size, int max, int min, int mid, int count, int count2, int index, int sum, double ave, int med, int even, int odd, int divi);

int find_max(int a[], size_t size);

int find_min(int a[], size_t size);

int midpoint(int max, int min);

int get_count(int a[], size_t size, int type, int x);

int linear_search(int a[], size_t size, int x);

int add(int a[], size_t size);

double average(int sum, size_t size);

void bubble_sort(int a[], size_t size);

void insertion_sort(int a[], size_t size);

void reverse(int a[], size_t size);

int median(int a[], size_t size);

int even_count(int a[], size_t size);

int odd_count(int a[], size_t size);

int divisible_count(int a[], size_t size, int min);


#endif
