#include"lab9.h"

/**
* dynamically allocates memory based on the given size
* @param size Number of elements to be created for a type
* @return Pointer to allocated memory will be returned
*/
char *create_array(int size)
{

	char *array = (char *) malloc(sizeof(char) * (size + 1)); /* + 1 for end of string '\0' */

	if (array == NULL) {
		printf("ERROR: Could not allocate space from memory.\n");
		exit(1);
	}

	return array;
}

/**
* function purpose to delete the list
* @param head pointer to the head of a list
* @return nothing
*/
void delete_list(struct bit_t *head)
{
	struct bit_t *tmp = head; /* tmp and head points to the first node*/

	while (head != NULL) {

		head = head->next;
		free(tmp);
		tmp = head;
	}
}

/**
* function purpose to delete the list
* @param tail pointer to the tail of a list
* @return nothing
*/
void delete_tlist(struct bit_t *tail)
{

	struct bit_t *tmp = tail; /* tmp and last points to the first node*/

	while (tail != NULL) {

		tail = tail->prev;
		free(tmp);
		tmp = tail;
	}
}

/**
* This function made to free up allocated memory for registers r1, r2, and r3.
* @param cpu, pointer to the main CPU structure.
* @return nothing
*/
void cleanup(struct cpu_t *cpu)
{
	delete_list(cpu->r1_head);
	cpu->r1_tail = NULL;

	delete_list(cpu->r2_head);
	cpu->r2_tail = NULL;

	delete_list(cpu->r3_head);
	cpu->r3_tail = NULL;
}

/**
* This function calculates the decimal value for binary values in a list.
* @param cpu, pointer to the main CPU structure.
* @return decimal value
*/
long decimal(struct bit_t *tail)
{
	long sum = 0;
	int i = 0;
	struct bit_t *tmp = tail;

	while (tmp != NULL) {

		sum = sum + (tmp->n * pow(2, i));
		i++;
		tmp = tmp->prev;
	}
	return sum;
}

/**
* This function sets zeroflag field of the CPU structure.
* @param cpu, pointer to the main CPU structure.
* @return nothing
*/
void set_zf(struct cpu_t *cpu)
{
	struct bit_t *tmp = cpu->r3_head;
	int count = 0;

	while (tmp != NULL) {
		if (tmp->n == 0) {
			count++;
		}
		tmp = tmp->next;
	}
	if (count == cpu->word_size) {

		cpu->zero = 1;

	} else {
		cpu->zero = 0;
	}
}

/**
* This function sets parity field of the CPU structure.
* @param cpu, pointer to the main CPU structure.
* @return nothing
*/
void set_parity(struct cpu_t *cpu)
{
	struct bit_t *tmp = cpu->r3_head;

	int count = 0;

	while (tmp != NULL) {

		if (tmp->n == 1) {
			count++;
		}
		tmp = tmp->next;
	}

	if (count > 0 && count % 2 == 0) {

		cpu->parity = 1;
	} else {
		cpu->parity = 0;
	}
}

/**
* This function sets sign flag field of the CPU structure.
* @param cpu, pointer to the main CPU structure.
* @return nothing
*/
void set_sign_flag(struct cpu_t *cpu)
{
	if (cpu->r3_head->n == 1) {

		cpu->sign = 1;

	} else {
		cpu->sign = 0;
	}
}

/**
* This function sets overflow field of the CPU structure.
* @param cpu, pointer to the main CPU structure.
* @return nothing
*/
void set_overflow(struct cpu_t *cpu)
{
	if (cpu->r1_head->n == 0 && cpu->r2_head->n == 0 && cpu->r3_head->n == 1) {
		cpu->overflow = 1;

	} else if (cpu->r1_head->n == 1 && cpu->r2_head->n == 1 && cpu->r3_head->n == 0) {

		cpu->overflow = 1;

	} else {

		cpu->overflow = 0;
	}
}

/**
* This function creates a node
* @param val value of the node to be created
* @return pointer to the newly created node for the given value.
*/
struct bit_t *create_node(char val)
{
	struct bit_t *node = NULL;

	node = (struct bit_t *) malloc(sizeof(struct bit_t));

	if (node != NULL) {

		if (val == '0')
			node->n = 0;

		if (val == '1')
			node->n = 1;

		node->next = NULL;
		node->prev = NULL;

	} else {
		printf("Error: Can not allocate memory\n");
		exit(1);
	}
	return node;
}

/**
* This function prints the list
* @param head pointer to the head of a list
* @return nothing
*/
void print_list(struct bit_t *head)
{
	while (head != NULL) {

		print_node(head);
		head = head->next;
	}
	printf("\n");
}

/**
* This function prints a node.
* @param node points to a node.
* @return nothing.
*/
void print_node(struct bit_t *node)
{
	if (node != NULL) {
		printf("%d", node->n);

	} else {

		printf("\nError: Can not print NULL node\n");
	}
}

/**
* This function counts the number of nodes in a list starting from head of the list.
* @param head pointer to the head of a list.
* @return number of nodes in the list
*/
int node_count(struct bit_t *head)
{
	int count = 0;

	while (head != NULL) {
		head = head->next;
		count++;
	}

	return count;
}

/**
* This function counts the number of nodes in a list starting from tail of the list.
* @param tail pointer to the tail of a list
* @return number of nodes in the list
*/
int tail_count(struct bit_t *tail)
{
	int count = 0;

	while (tail != NULL) {
		tail = tail->prev;
		count++;
	}
	return count;
}

/**
* This function insert a node at the head of a list.
* @param head pointer to the head of the list
* @param node pointer to the node to be inserted.
* @return head pointer of the list
*/
struct bit_t *insert_head(struct bit_t *head, struct bit_t *node)
{
	if (head == NULL) {

		head = node;

	} else {
		node->next = head;
		head->prev = node;
		head = node;
	}
	return head;
}

/**
* This function insert a node at the tail of a list.
* @param tail pointer to the tail of the list
* @param node pointer to the node to be inserted.
* @return tail pointer of the lis
*/
struct bit_t *insert_tail(struct bit_t *tail, struct bit_t *node)
{

	tail->next = node;
	node->prev = tail;

	return node;
}

/**
* This function creates a list.
* @param str pointer to a string from where double linked list will get it's values.
* @param cpu pointer to main CPU structure to store head and tail of different registers (r1, r2, and r3)
* @return head pointer to the head of the created list.
*/
struct bit_t *create_list(char *str, struct cpu_t *cpu)
{

	struct bit_t *node = NULL;
	struct bit_t *tail = NULL;
	struct bit_t *head = NULL;

	while (*str != '\0') {
		node = create_node(*str);
		if (head == NULL) {
			head = node;
			tail = node;
		} else {
			tail = insert_tail(tail, node);
		}
		str++;
	}
	if (cpu->r1_head == NULL) {
		cpu->r1_head = head;
		cpu->r1_tail = tail;
	} else if (cpu->r2_head == NULL) {
		cpu->r2_head = head;
		cpu->r2_tail = tail;
	} else if (cpu->r3_head == NULL) {
		cpu->r3_head = head;
		cpu->r3_tail = tail;
	}
	return head;
}

/**
* This function validate each character in the input string. (1 or 0)
* @param op pointer to a character string.
* @return 1 if valid, otherwise 0.
*/
int validate_operand(char *op)
{
	do {

		if (*op != '1' && *op != '0') {

			printf("error in input -- something other than a 1 or 0 entered\n");
			return 0; /* returning 0 because failed */

		} else {
			op++;
		}
	} while (*op != '\0' && *op != '\n');

	printf("\n");
	return 1;
}

/**
* This function validate operator character in the input string. (-, +, &, |, ^)
* @param op pointer to a character string.
* @return 1 if valid otherwise 0.
*/
int validate_operator(char *op)
{
	do {

		switch (*op) {

		case '-':
		case '+':
		case '&':
		case '|':
		case '^':
			break;
		default:
			return 0;
		}
		op++;
	} while (*op != '\0' && *op != '\n');
	printf("\n");
	return 1;
}

/**
* This function initialize main CPU structure.
* @param cpu address of the main CPU structure.
* @return nothing
*/
void initialize_cpu(struct cpu_t *cpu)
{
	cpu->word_size = 0;
	cpu->unsign = 0;
	cpu->overflow = 0;
	cpu->carry = 0;
	cpu->sign = 0;
	cpu->parity = 0;
	cpu->zero = 0;
	cpu->r1_head = NULL;
	cpu->r1_tail = NULL;
	cpu->r2_head = NULL;
	cpu->r2_tail = NULL;
	cpu->r3_head = NULL;
	cpu->r3_tail = NULL;

}

/**
* This function does binary xor operation.
* @param r1 tail point of 1st list.
* @param r2 tail point of 2nd list.
* @param r3 tail point of result list.
* @return nothing
*/
void xor(struct bit_t *r1, struct bit_t *r2, struct bit_t *r3)
{

	while (r1 != NULL && r2 != NULL && r3 != NULL) {

		/* 0 0 */
		if (r1->n == 0 && r2->n == 0) {

			r3->n = 0;

		}

		/* 0 1 */
		if (r1->n == 0 && r2->n == 1) {

			r3->n = 1;

		}
		/* 1 0 */
		if (r1->n == 1 && r2->n == 0) {

			r3->n = 1;

		}
		/* 1 1 */
		if (r1->n == 1 && r2->n == 1) {

			r3->n = 0;

		}
		r1 = r1->prev;
		r2 = r2->prev;
		r3 = r3->prev;
	}

}

/**
* This function does binary or operation.
* @param r1 tail point of 1st list.
* @param r2 tail point of 2nd list.
* @param r3 tail point of result list.
* @return nothing.
*/
void or(struct bit_t *r1, struct bit_t *r2, struct bit_t *r3)
{

	while (r1 != NULL && r2 != NULL && r3 != NULL) {

		/* 0 0 */
		if (r1->n == 0 && r2->n == 0) {

			r3->n = 0;

		}

		/* 0 1 */
		if (r1->n == 0 && r2->n == 1) {

			r3->n = 1;

		}
		/* 1 0 */
		if (r1->n == 1 && r2->n == 0) {

			r3->n = 1;

		}
		/* 1 1 */
		if (r1->n == 1 && r2->n == 1) {

			r3->n = 1;

		}
		r1 = r1->prev;
		r2 = r2->prev;
		r3 = r3->prev;
	}
}

/**
* This function calculates two's complement.
* @param *list tail point of a list.
* @param *cpu Address of the CPU structure.
* @return A list with two's complement binary.
*/
struct bit_t *twos_complement(struct bit_t *list, struct cpu_t *cpu)
{

	int i;
	struct bit_t *result_head = NULL;
	struct bit_t *one_head = NULL;
	struct bit_t *one_tail = NULL;
	struct bit_t *result_tail = NULL;
	struct bit_t *tmp = list;
	/* Taking ones compliment for r2 */
	while (tmp != NULL) {
		if (tmp->n == 0) {
			tmp->n = 1;
		} else {
			tmp->n = 0;
		}
		tmp = tmp->prev;
	}

	char *temp = create_array(cpu->word_size);
	char *one = create_array(cpu->word_size);

	for (i = 0; i < cpu->word_size; i++) {
		temp[i] = '0';
		one[i] = '0';
	}
	temp[i] = '\0';
	one[i - 1] = '1';
	one[i] = '\0';

	result_head = create_list(temp, cpu);
	result_tail = result_head;

	one_head = create_list(one, cpu);
	one_tail = one_head;

	if (one_tail != NULL)
		while (one_tail->next != NULL)
			one_tail = one_tail->next;
	else
		printf("ERROR: one list was not created.\n");


	if (result_tail != NULL)
		while (result_tail->next != NULL)
			result_tail = result_tail->next;
	else
		printf("ERROR: temp list was not created.\n");


	sum(list, one_tail, result_tail);
	print_list(result_head);

	/* frees temporary lists */
	delete_list(one_head);
	return (result_tail);
}

/**
* This function subtracts two list containing binary numbers using two's complement
* @param cpu, address of the main CPU structure.
* @return carry
*/
unsigned char sub(struct cpu_t *cpu)
{
	struct bit_t *tail_r3 = cpu->r3_tail;
	struct bit_t *tail_r1 = cpu->r1_tail;
	unsigned char carry;

	struct bit_t *temp_tail = NULL;

	temp_tail = twos_complement(cpu->r2_tail, cpu);

	carry = sum(tail_r1, temp_tail, tail_r3);

	/* frees temporary lists */
	delete_tlist(temp_tail);
	return carry;
}

/**
* This function does binary and operation.
* @param r1, tail point of 1st list.
* @param r2, tail point of 2nd list.
* @param r3, tail point of result list.
* @return nothing
*/
void and(struct bit_t *r1, struct bit_t *r2, struct bit_t *r3)
{

	while (r1 != NULL && r2 != NULL && r3 != NULL) {

		/* 0 0 */
		if (r1->n == 0 && r2->n == 0) {

			r3->n = 0;

		}

		/* 0 1 */
		if (r1->n == 0 && r2->n == 1) {

			r3->n = 0;

		}
		/* 1 0 */
		if (r1->n == 1 && r2->n == 0) {

			r3->n = 0;

		}
		/* 1 1 */
		if (r1->n == 1 && r2->n == 1) {

			r3->n = 1;

		}
		r1 = r1->prev;
		r2 = r2->prev;
		r3 = r3->prev;
	}

}

/**
* models full adder truth table.
* @param r1, tail point of 1st list.
* @param r2, tail point of 2nd list.
* @param r3, tail point of result list.
* @return carry from the sum.
*/
unsigned char sum(struct bit_t *r1, struct bit_t *r2, struct bit_t *r3)
{
	unsigned char carry = 0;

	while (r1 != NULL && r2 != NULL && r3 != NULL) {

		if (r1->n == 0 && r2->n == 0) {
			if (carry == 1) {
				r3->n = 1;
				carry = 0;
			} else {
				r3->n = 0;
			}
		}

		/* 0 1 */
		if (r1->n == 0 && r2->n == 1) {
			if (carry == 1) {
				r3->n = 0;
				carry = 1;
			} else {
				r3->n = 1;
			}
		}
		/* 1 0 */
		if (r1->n == 1 && r2->n == 0) {
			if (carry == 1) {
				r3->n = 0;
				carry = 1;
			} else {
				r3->n = 1;
			}
		}
		/* 1 1 */
		if (r1->n == 1 && r2->n == 1) {
			if (carry == 1) {
				r3->n = 1;
				carry = 1;
			} else {
				r3->n = 0;
				carry = 1;
			}
		}
		r1 = r1->prev;
		r2 = r2->prev;
		r3 = r3->prev;
	}

	return carry;
}
