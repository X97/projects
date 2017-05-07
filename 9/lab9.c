/**
* @file lab9.c
* @author Namir Hassan
* @date 04/25/2017
* @brief this program is a binary calculator. The user must enter a word size and tell
* whether it is an unsigned value or not followed by a binary expression that
* not not bigger than word size. Calculation will output the answer of the
* expression followed by various flags and decimal value.
*/

#include"lab9.h"

int main()
{

	char buffer[SIZE];
	int wordsize = 0;
	char choice;
	char *r1;
	char *op;
	char *r2;
	char* operand1 = NULL;
	char* operand2 = NULL;
	char* zero = NULL;
	int op1size = 0;
	int op2size = 0;
	int i;

	struct cpu_t cpu;

	/* initialize cpu structure */
	REPEAT: initialize_cpu(&cpu);

	r1 = NULL;
	op = NULL;
	r2 = NULL;

	do {
		printf("\nenter word size: ");
		fgets(buffer, sizeof(buffer), stdin);
		sscanf(buffer, "%d", &wordsize);

		if ((wordsize < 1) || (wordsize > 64))
			printf("error in word size, must be between 1 and 64\n");

	} while ((wordsize < 1) || (wordsize > 64));

	cpu.word_size = wordsize;

	printf("\nunsigned values [y/N]: ");
	fgets(buffer, sizeof(buffer), stdin);
	sscanf(buffer, "%c", &choice);

	if ((choice == 'Y') || (choice == 'y')) {
		cpu.unsign = 1;
	}

	printf("\nenter binary expression: ");
	if (fgets(buffer, sizeof(buffer), stdin) != NULL) {

		r1 = strtok(buffer, " ");

		if (r1 != NULL && validate_operand(r1) == 0) {
			printf("Error in first operand. retry.\n");
			goto REPEAT;
		}

	} else {

		printf("Error: Enter valid expression\n");

	}

	if (strlen(r1) > cpu.word_size) {
		printf("error in input -- length is greater than the word size\n");
		printf("Error in first operand. retry.\n");
		goto REPEAT;
	}

	if (r1 != NULL) {

		op = strtok(NULL, " ");

		if (op != NULL && validate_operator(op) == 0) {
			printf("Error in operator. retry.\n");
			goto REPEAT;
		}

	} else {
		printf("Error: Operator needed.\n");
	}

	if (op != NULL) {

		r2 = strtok(NULL, " ");

		if (r2 != NULL && validate_operand(r2) == 0) {
			printf("Error in second operand. retry.\n");
		}
	} else {
		printf("Error: Second operand needed.\n");

	}

	r2 = strtok(r2, "\n");

	if (strlen(r2) > cpu.word_size) {
		printf("error in input -- length is greater than the word size\n");
		printf("Error in second operand. retry.\n");
		goto REPEAT;
	}

	operand1 = create_array(wordsize);
	operand2 = create_array(wordsize);
	zero = create_array(wordsize);

	for (i = 0; i < wordsize; i++)
		zero[i] = '0';
	zero[i] = '\0';

	op1size = strlen(r1);
	op2size = strlen(r2);
	strncpy(operand1, zero, wordsize - op1size);
	strncpy(operand2, zero, wordsize - op2size);
	operand1[wordsize - op1size] = '\0';
	operand2[wordsize - op2size] = '\0';
	strncat(operand1, r1, op1size);
	strncat(operand2, r2, op2size);
	operand1[wordsize] = '\0';
	operand2[wordsize] = '\0';

	create_list(operand1, &cpu);
	print_list(cpu.r1_head);

	create_list(operand2, &cpu);

	create_list(zero, &cpu);

	switch (*op) {

	case '+':
		printf("%s\n", op);
		print_list(cpu.r2_head);
		cpu.carry = sum(cpu.r1_tail, cpu.r2_tail, cpu.r3_tail);
		break;
	case '-':
		printf("%s\n", "+");
		cpu.carry = sub(&cpu);
		break;
	case '&':
		printf("%s\n", op);
		print_list(cpu.r2_head);
		and(cpu.r1_tail, cpu.r2_tail, cpu.r3_tail);
		break;
	case '|':
		printf("%s\n", op);
		print_list(cpu.r2_head);
		or(cpu.r1_tail, cpu.r2_tail, cpu.r3_tail);
		break;
	case '^':
		printf("%s\n", op);
		print_list(cpu.r2_head);
		xor(cpu.r1_tail, cpu.r2_tail, cpu.r3_tail);
		break;

	}

	for (i = 0; i < wordsize; i++) {

		printf("-");

	}
	printf("\n");

	print_list(cpu.r3_head);

	printf("flags\n");
	set_overflow(&cpu);
	printf("OF: %d\n", cpu.overflow);
	printf("CF: %d\n", cpu.carry);
	set_sign_flag(&cpu);
	printf("SF: %d\n", cpu.sign);
	set_parity(&cpu);
	printf("PF: %d\n", cpu.parity);
	set_zf(&cpu);
	printf("ZF: %d\n", cpu.zero);

	if (cpu.unsign == 1)
		printf("unsigned decimal: %ld", decimal(cpu.r3_tail));
	else {

		if (cpu.r3_head->n == 1)
			printf("decimal: -%ld",
					decimal(twos_complement(cpu.r3_tail, &cpu)));
		else
			printf("decimal: %ld", decimal(cpu.r3_tail));
	}

	cleanup(&cpu);
	if (operand1 != NULL)
		free(operand1);
	if (operand2 != NULL)
		free(operand2);
	if (zero != NULL)
		free(zero);

	printf("\ndo you want to continue [Y/n]?: ");
	if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
		sscanf(buffer, "%c", &choice);
		if (choice == 'n') {
			printf("Goodbye\n");
			exit(1);
		} else {
			goto REPEAT;
		}
	} else {
		printf("Could not read from stdin.\n");
	}
	printf("\n");

	return 0;
}
