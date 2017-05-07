/**
* @file credit.c
* @brief determine if a credit card is valid using Luhn's algorithm.
* @author Namir Hassan
* @date 2/20/2017
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_DIGITS 16
#define VALID 0
#define INVALID -1

void convert_card(int card[], char num[], int num_digits);
void print_card(int card[], int size);
void alg1(int card[], int size);
int sum(int card[], int size);
int card_valid(int add);


int main(void)
{
	int card[NUM_DIGITS];
	int a;

	char visa[] = "4012888888881881"; /* valid card */
	//char visa[] = "4012888888881882"; /*invalid card */
	convert_card(card, visa, NUM_DIGITS);
	print_card(card, NUM_DIGITS);

	printf("\n");

	alg1(card, NUM_DIGITS);

	print_card(card, NUM_DIGITS);

	a = sum(card, NUM_DIGITS);

	//printf("Sum: %d", a);

	printf("\n");

	if (card_valid(a) == VALID) {

		printf("\nCard is valid.\n");

	} else {

		printf("\nInvalid card!\n");

	}

	printf("\n\n");

	return 0;

}

/**
 * converts card to an int array
 * @param card
 * @param num
 * @param num_digits
 * @return nothing (void)
 */
void convert_card(int card[], char num[], int num_digits)
{
	int i;

	for(i = 0; i < num_digits; i++)
		card[i] = num[i] - '0';

}

/**
 * prints each element of the array
 * @param card
 * @param size
 * @return nothing (void)
 */
void print_card(int card[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("card[%d] = %d\n", i, card[i]);
}

/**
 * multiplies every other element
 * @param card
 * @param size
 * @return nothing (void)
 */
void alg1(int card[], int size) {


	int i;

	for (i = 0; i < size;) {

		card[i] *= 2;
		i+= 2;

	}

}

/**
 * converts card to an int array
 * @param card
 * @param size
 * @return sum of the undoubled elements in the array
 */
int sum(int card[], int size) {

	int i;
	int add = 0;

	for (i = 0; i < size; i++) {

		if(card[i] / 10 == 1) {

			add += card[i] / 10;

			add += card[i] % 10;

		} else {

		add += card[i];

		}

	}

	return add;
}

/**
 * checks validity of the card
 * @param add
 * @return returns the card if valid or not
 */
int card_valid(int add) {

	int n;

	if (add % 10 == 0) {

		n = VALID;

	} else {

		n = INVALID;

	}

	return n;

}
