/**
* @file life.h
* @brief contains define statements and function prototypes
* @author Namir Hassan
* @date 05/01/17
*/

#ifndef LIFE_H_
#define LIFE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <errno.h>

#define SIZE 20

#define HEDGE 1
#define TORUS 2
#define KLEIN_BOTTLE 3

#define LIVE 1
#define DEAD 0

unsigned char **allocate_grid(int width_in_sprite, int height_in_sprite);
void init_grid(unsigned char **grid, int rows, int cols);
void free_grid(unsigned char **grid, int rows);
void seed_106_to_grid(unsigned char **grid, int rows, int cols, int row0, int col0, FILE *fp);
void seed_105_to_grid(unsigned char **grid, int rows, int cols, int row0, int col0, FILE *fp);
int internal_cell_neighbors(int row, int col, int rows, int cols, unsigned char **grid);
int hedge_neighbors(int row, int col, int rows, int cols, unsigned char **grid);
int torus_neighbors(int row, int col, int rows, int cols, unsigned char **grid);
int klein_bottle_neighbors(int row, int col, int rows, int cols, unsigned char **grid);
void apply_transitions(unsigned char **gridA, unsigned char **gridB, int rows, int cols, int edge_type);
#endif
