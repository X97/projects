#ifndef ARRAY_STRUCT_H_
#define ARRAY_STRUCT_H_


#define SIZE 5

struct data_t {

	int age;  /* age of the subject */
	int height;  /* height of subject in inches */
	char subject; 	/* one capital letter id for subject */

};

void init_array(struct data_t data[], int index, char id, int years, int inches);

int min_ages(struct data_t data[], int size);

int min_heights(struct data_t data[], int size);

int max_ages(struct data_t data[], int size);

int max_heights(struct data_t data[], int size);

int ave_age(struct data_t data[], int size);

int ave_height(struct data_t data[], int size);

void print_struct(struct data_t data[], int index);

#endif
