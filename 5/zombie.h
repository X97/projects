#include <stdio.h>
#include <stdlib.h>

#ifndef ZOMBIE_H_
#define ZOMBIE_H_

#define SIZE 5

struct zombie_t {

        enum {MONDAY = 1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY} day;

        float blood;
        int toes;
        int hour;
        int min;
        int sec;
        char dead; /* y if dead, x if alive */


};

void input_time(struct zombie_t zombie[], int index);

void input_toes(struct zombie_t zombie[], int index);

void input_blood(struct zombie_t zombie[], int index);

void print_zombies(struct zombie_t zombie[], int size);

#endif
