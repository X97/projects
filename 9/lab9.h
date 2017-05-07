#ifndef LAB9_H_
#define LAB9_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 132

struct bit_t {

        unsigned char n;
        struct bit_t *prev;
        struct bit_t *next;
};

struct cpu_t {

        int word_size;
        int unsign;
        int overflow;
        int carry;
        int sign;
        int parity;
        int zero;
        struct bit_t *r1_head;
        struct bit_t *r1_tail;
        struct bit_t *r2_head;
        struct bit_t *r2_tail;
        struct bit_t *r3_head;
        struct bit_t *r3_tail;
};

char *create_array(int size);
int validate_operand(char *op);
int validate_operator(char *op);
struct bit_t *create_list(char *str, struct cpu_t *cpu);
struct bit_t *insert_tail(struct bit_t *tail, struct bit_t *node);
struct bit_t *insert_head(struct bit_t *head, struct bit_t *node);
int node_count(struct bit_t *head);
void print_list(struct bit_t *head);
void print_node(struct bit_t *node);
struct bit_t *create_node(char val);
void initialize_cpu(struct cpu_t *cpu);
unsigned char sum(struct bit_t *r1, struct bit_t *r2, struct bit_t *r3);
struct bit_t *twos_complement(struct bit_t *list, struct cpu_t *cpu);
int tail_count(struct bit_t *head);
void and(struct bit_t *r1, struct bit_t *r2, struct bit_t *r3);
void or(struct bit_t *r1, struct bit_t *r2, struct bit_t *r3);
void xor(struct bit_t *r1, struct bit_t *r2, struct bit_t *r3);
unsigned char sub(struct cpu_t *cpu);
void set_overflow(struct cpu_t *cpu);
void set_sign_flag(struct cpu_t *cpu);
void set_parity(struct cpu_t *cpu);
void set_zf(struct cpu_t *cpu);
long decimal(struct bit_t *tail);
void cleanup(struct cpu_t *cpu);
void delete_list(struct bit_t *head);
void delete_tlist(struct bit_t *tail);

#endif
