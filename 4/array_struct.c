/**
 * @file array_struct.c
 * @author Namir Hassan
 * @date 03/1/2017
 * @brief finds minimum, maximum, and average of age and height
 */

#include "array_struct.h"
#include <stdio.h>

int main(void)
{

	struct data_t data[SIZE];
	int min;
	int max;
	int min_h;
	int max_h;

	/* data initialization calls */
	init_array(data, 0, 'A', 23, 74);
	init_array(data, 1, 'B', 22, 64);
	init_array(data, 2, 'C', 19, 68);
	init_array(data, 3, 'D', 20, 76);
	init_array(data, 4, 'E', 22, 62);

	min = min_ages(data, SIZE);
	/*printf("Minimum Age: %d\n", data[min].age);*/

	min_h = min_heights(data, SIZE);
	/*printf("Minimum Height: %d\n", data[min_h].height);*/

	max = max_ages(data, SIZE);
	/*printf("Maximum Age: %d\n", data[max].age);*/

	max_h = max_heights(data, SIZE);
	/*printf("Maximum Height: %d\n", data[max_h].height);*/

	print_struct(data, min);
	print_struct(data, min_h);
	print_struct(data, max);
	print_struct(data, max_h);

	printf("\nAverage Age: %d\n", ave_age(data, SIZE));
	printf("\nAverage Height: %d\n", ave_height(data, SIZE));

	return 0;
}

/**
 * Assigns each array to a variable in the structure
 * @param data[]
 * @param index
 * @param id
 * @param years
 * @param inches
 * @return nothing (void)
 */
void init_array(struct data_t data[], int index, char id, int years, int inches)
{

	data[index].age = years;
	data[index].height = inches;
	data[index].subject = id;

}

/**
 * Finds the minimum age
 * @param data[]
 * @param size
 * @return minimum value for age
 */
int min_ages(struct data_t data[], int size)
{

	int min = 0;
	int i;

	for (i = 0; i < size; i++) {

		if (data[i].age < data[min].age) {
			min = i;
		}

	}
	return min;
}

/**
 * Finds the minimum height
 * @param data[]
 * @param size
 * @return minimum value for height
 */
int min_heights(struct data_t data[], int size)
{

	int min_h = 0;
	int i;

	for (i = 0; i < size; i++) {

		if (data[i].height < data[min_h].height) {
			min_h = i;
		}

	}
	return min_h;
}

/**
 * Finds the maximum age
 * @param data[]
 * @param size
 * @return maximum value for age
 */
int max_ages(struct data_t data[], int size)
{

	int max = 0;
	int i;

	for (i = 0; i < size; i++) {

		if (data[i].age > data[max].age) {
			max = i;
		}

	}

	return max;

}

/**
 * Finds the maximum height
 * @param data[]
 * @param size
 * @return maximum value for height
 */
int max_heights(struct data_t data[], int size)

{
	int max_h = 0;
	int i;

	for (i = 0; i < size; i++) {

		if (data[i].height > data[max_h].height) {
			max_h = i;
		}

	}

	return max_h;
}

/**
 * Finds the average age
 * @param data[]
 * @param size
 * @return the average of the ages
 */
int ave_age(struct data_t data[], int size)
{
	int sum = 0;
	int i;

	for (i = 0; i < size; i++) {

		sum += data[i].age;

		}

	return sum / size;

}

/**
 * Finds the average height
 * @param data[]
 * @param size
 * @return the average of the heights
 */
int ave_height(struct data_t data[], int size)
{
	int sum = 0;
	int i;

	for (i = 0; i < size; i++) {

		sum += data[i].height;

		}

	return sum / size;


}

/**
 * Prints subject, age, and height
 * @param data[]
 * @param index
 * @return nothing (void)
 */
void print_struct(struct data_t data[], int index)
{

	printf("\nSubject: %c\n Age: %d\n Height: %d\n", data[index].subject, data[index].age, data[index].height);

}
