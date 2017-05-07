/**
* @file life.c
* @brief Contains the game of life funcions, including initialization,
* calculations of living and dead cells, and freeing.
* @details Cellular automaton, which its evolution is determined by the
* initial state.
* @author Namir Hassan
* @date 05/01/2017
* @todo None
* @bug None
*/

#include "life.h"

/**
 * This function dynamically allocates memory based on rows and columns sizes.
 * @param rows Number of rows in a two dimensional array.
 * @param cols Number of columns in a two dimensional array
 * @return Pointer to allocated memory will be returned (NULL if unsuccessful)
 */
unsigned char **allocate_grid(int rows, int cols)
{
	int i;
	int j;
	unsigned char **grid;

	grid = (unsigned char **) malloc(rows * sizeof(unsigned char *));

	if (!grid) {
		printf("Error: Malloc could not allocate memory for grid.\n");
		return NULL;
	}
	for (i = 0; i < rows; i++) {
		/* allocates colomns for each row */
		grid[i] = (unsigned char *) malloc(cols * sizeof(unsigned char));
		if (!grid[i]) {

			printf("Error: Malloc could not allocate memory for grid columns.\n");

			for (j = 0; j < i; j++)
				free(grid[j]);
			free(grid);
			return NULL;
		}
	}
	init_grid(grid, rows, cols);

	return (grid);
}

/**
 * This function initializes a 2D array with value DEAD defined in life.h file
 * @param **grid address of a two dimensional array represented by points.
 * @param rows Number of rows in the two dimensional array.
 * @param cols Number of columns in the two dimensional array.
 * @return Nothing.
 */
void init_grid(unsigned char **grid, int rows, int cols)
{
	int i;
	int j;

	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
			grid[i][j] = DEAD;
}

/**
 * This function frees a two dimensional array. Each row contains the pointer of columns
 * @param **grid address of a two dimensional array represented by points.
 * @param rows Number of rows in the two dimensional array.
 * @return Nothing
 */
void free_grid(unsigned char **grid, int rows)
{
	if (grid != NULL) {
		for (int i = 0; i < rows; i++) {
			if (grid[i] != NULL)
				free(grid[i]);
			else
				printf("Error: Attempt to free null pointer\n");
		}
		free(grid);
	} else {
		printf("Error: Attempt to free null grid\n");
	}
}

/**
 * This function reads a Life 1.06 formatted file and put live cells in the passed 2D array.
 * @param **grid address of a two dimensional array represented by points.
 * @param rows Number of rows in the two dimensional array.
 * @param cols Number of cols in the two dimensional array.
 * @param row0 row index of starting point on grid.
 * @param col0 col index of starting point on grid.
 * @param fp File path of a Life 1.06 file.
 * @return Nothing.
 */
void seed_106_to_grid(unsigned char **grid, int rows, int cols, int row0, int col0, FILE *fp)
{
	char buffer[SIZE];
	char *token = NULL;
	char Col[SIZE];
	char Row[SIZE];
	int col = 0;
	int row = 0;
	int gridcol;
	int gridrow;
	int rcount = 0;

	if (grid == NULL) {
		printf("Error: Null grid was passed\n");
	}

	while (fgets(buffer, sizeof(buffer), fp) != NULL) {
		rcount++;

		token = strtok(buffer, " ");
		if (token != NULL) {
			strcpy(Col, token);
			token = strtok(NULL, " ");
		}
		if (token != NULL) {
			token = strtok(token, "\n");
			strcpy(Row, token);
		}

		if (strlen(Col) > 0) {
			col = atoi(Col);
			if (strlen(Row) > 0) {
				row = atoi(Row);

				gridrow = row0 + row;
				gridcol = col0 + col;

				if (gridcol >= 0 && gridcol <= cols - 1 && gridrow >= 0 && gridrow <= rows - 1) {
					grid[gridrow][gridcol] = LIVE;
				} else {
					printf("Cell is outside of grid, (%d, %d)\n", gridcol, gridrow);
				}
			} else {
				printf("No row value for (col, row) coordinates\n");
			}
		} else {
			printf("No col value for (col, row) coordinates\n");
		}
		token = NULL;
	}
	fclose(fp);
}

/**
 * This function reads a Life 1.05 formatted file and put live cells in the passed two dimensional array.
 * @param **grid address of a two dimensional array represented by points.
 * @param rows Number of rows in the two dimensional array.
 * @param cols Number of cols in the two dimensional array.
 * @param row0 row index of starting point on grid.
 * @param col0 col index of starting point on grid.
 * @param fp File path of a Life 1.05 file.
 * @return Nothing.
 */
void seed_105_to_grid(unsigned char **grid, int rows, int cols, int row0, int col0, FILE *fp)
{
	char buffer[256];
	int row = 0, col = 0;
	int length = 0;
	int x;
	int y;
	int grow;
	int gcol;

	while (fgets(buffer, sizeof(buffer), fp) != NULL) {
		length = strlen(buffer) - 2;
		if (buffer[0] == '#' && buffer[1] == 'P') {
			char *colstr = strtok(buffer + 3, " ");
			x = atoi(colstr);
			colstr = strtok(strtok(NULL, " "), "\n");
			y = atoi(colstr);
			printf("(x=%d, y=%d)\n", x, y);

		} else if (buffer[0] == '.' || buffer[0] == '*') {
			for (col = 0; col < length; col++) {
				if (buffer[col] == '*') {
					grow = row + y;
					gcol = col + x;

					if ((col0 + gcol) >= 0 && (col0 + gcol) <= (cols - 1) && (row0 + grow) >= 0 && (row0 + grow) <= (rows - 1)) {
						grid[row0 + grow][col0 + gcol] = LIVE;
					} else {
						printf("Cell is outside of grid relative to (%d, %d) initial coordinate, (%d, %d)\n", col0, row0, (col0 + col), (row0 + row));
					}
				}
			}
			row++;
		}
	}
}

/**
 * This function reads each cell in the current_generation two dimensional array, find eight neighbors for each cell and
 * applies transition rules for live or dead cell for the assignment of cells in next generation.
 * @param **current_generation address of a two dimensional array of current generation.
 * @param **next_generation address of a two dimensional array of next generation.
 * @param rows Number of rows in the two dimensional array.
 * @param cols Number of cols in the two dimensional array.
 * @param edge_type Edge type for deciding cell along the border.
 * @return Nothing.
 */
void apply_transitions(unsigned char **current_generation, unsigned char **next_generation, int rows, int cols, int edge_type)
{
	int i;
	int j;
	int live;

	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++) {

			if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
				switch (edge_type) {
				case HEDGE:
					live = hedge_neighbors(i, j, rows, cols, current_generation);
					break;
				case TORUS:
					live = torus_neighbors(i, j, rows, cols, current_generation);
					break;
				case KLEIN_BOTTLE:
					live = klein_bottle_neighbors(i, j, rows, cols, current_generation);
					break;
				default:
					printf("Using default edge method: Hedge.\n");
					break;
				}
			} else {
				live = internal_cell_neighbors(i, j, rows, cols, current_generation);
			}

			if ((current_generation[i][j] == DEAD) && (live == 3)) {
				next_generation[i][j] = LIVE;
			}

			if ((current_generation[i][j] == LIVE) && (live == 2 || live == 3)) {
				next_generation[i][j] = LIVE;
			}

			if ((current_generation[i][j] == LIVE) && (live < 2)) {
				next_generation[i][j] = DEAD;
			}

			if ((current_generation[i][j] == LIVE) && (live > 3)) {
				next_generation[i][j] = DEAD;
			}
		}

	init_grid(current_generation, rows, cols);
}

/**
 * This function calculates number of live neighbor cells for internal cells
 * @param row cell's row index.
 * @param col cell's col index.
 * @param rows Number of rows in the grid.
 * @param cols Number of cols in the grid.
 * @param **grid address of a two dimensional array of a generation.
 * @return number of live cells.
 */
int internal_cell_neighbors(int row, int col, int rows, int cols, unsigned char **grid)
{
	int i;
	int j;
	int live = 0;
	int topleftcorner_r = row - 1;
	int topleftcorner_c = col - 1;
	int bottomrightcorner_r = row + 1;
	int bottomrightcorner_c = col + 1;

	for (i = topleftcorner_r; i <= bottomrightcorner_r; i++)
		for (j = topleftcorner_c; j <= bottomrightcorner_c; j++) {
			if (!(i == row && j == col)) {
				if (grid[i][j])
					live++;
			}
		}
	return (live);
}

/**
 * This function calculates number of live neighbor cells of border/edge cells based on hedge edge type
 * @param row cell's row index.
 * @param col cell's col index.
 * @param rows Number of rows in the grid.
 * @param cols Number of cols in the grid.
 * @param **grid address of a two dimensional array of a generation.
 * @return number of live cells.
 */
int hedge_neighbors(int row, int col, int rows, int cols, unsigned char **grid)
{
	int i;
	int j;
	int live = 0;
	int dead = 0;
	int topleftcorner_r = row - 1;
	int topleftcorner_c = col - 1;
	int bottomrightcorner_r = row + 1;
	int bottomrightcorner_c = col + 1;

	for (i = topleftcorner_r; i <= bottomrightcorner_r; i++)
		for (j = topleftcorner_c; j <= bottomrightcorner_c; j++) {
			if (i < 0 || i > rows - 1 || j < 0 || j > cols - 1) {
				dead++;
			} else {
				if (!(i == row && j == col)) {
					if (grid[i][j])
						live++;
				}
			}
		}
	return (live);
}

/**
 * This function calculates number of live neighbor cells of border/edge cells based on torus edge type
 * @param row cell's row index.
 * @param col cell's col index.
 * @param rows Number of rows in the grid.
 * @param cols Number of cols in the grid.
 * @param **grid address of a two dimensional array of a generation.
 * @return number of live cells.
 */
int torus_neighbors(int row, int col, int rows, int cols, unsigned char **grid)
{
	int i;
	int j;
	int live = 0;
	int new_row;
	int new_col;
	int topleftcorner_r = row - 1;
	int topleftcorner_c = col - 1;
	int bottomrightcorner_r = row + 1;
	int bottomrightcorner_c = col + 1;

	for (i = topleftcorner_r; i <= bottomrightcorner_r; i++) {
		if (i < 0)
			new_row = rows - 1;
		else if (i > rows - 1)
			new_row = 0;
		else
			new_row = i;
		for (j = topleftcorner_c; j <= bottomrightcorner_c; j++) {
			if (j < 0)
				new_col = cols - 1;
			else if (j > cols - 1)
				new_col = 0;
			else
				new_col = j;

			if (!(i == row && j == col)) {
				if (grid[new_row][new_col])
					live++;
			}
		}
	}
	return (live);
}

/**
 * This function calculates number of live neighbor cells of border/edge cells based on torus edge type
 * @param row cell's row index.
 * @param col cell's col index.
 * @param rows Number of rows in the grid.
 * @param cols Number of cols in the grid.
 * @param **grid address of a two dimensional array of a generation.
 * @return number of live cells.
 */
int klein_bottle_neighbors(int row, int col, int rows, int cols, unsigned char **grid)
{
	int i;
	int j;
	int live = 0;
	int new_row;
	int new_col;
	int flip_row;
	int flip_col;
	int topleftcorner_r = row - 1;
	int topleftcorner_c = col - 1;
	int bottomrightcorner_r = row + 1;
	int bottomrightcorner_c = col + 1;

	for (i = topleftcorner_r; i <= bottomrightcorner_r; i++) {
		for (j = topleftcorner_c; j <= bottomrightcorner_c; j++) {

			if (j < 0 || j > cols - 1) {
				if (i < 0)
					flip_row = 0;
				else if (i > rows - 1)
					flip_row = rows - 1;
				else
					flip_row = rows - 1 - abs(i);
				;
			} else
				flip_row = i;
			flip_col = j;

			if (flip_row < 0)
				new_row = rows - 1;
			else if (flip_row > rows - 1)
				new_row = 0;
			else
				new_row = flip_row;

			if (flip_col < 0)
				new_col = cols - 1;
			else if (flip_col > cols - 1)
				new_col = 0;
			else
				new_col = flip_col;

			if (!(flip_row == row && flip_col == col)) {
				if (grid[new_row][new_col])
					live++;
			}
		}
	}
	return (live);
}
