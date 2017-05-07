/**
* @file gl.c
* @brief Main game which includes calls to the SDL to setup the bitmap to draw
* to the screen. Files are read from the filepath and users enter the various
* command arguments in order to run the program a certain way.
* @details Cellular automaton, its evolution is determined by its initial state.
* @author Namir Hassan
* @date 05/01/2017
* @todo None
* @bug None
*/

#include <stdlib.h>
#include "SDL2/SDL.h"
#include "sdl.h"
#include "life.h"

int main(int argc, char *argv[])
{
	int width = 640;
	int height = 480;
	unsigned char red = 100;
	unsigned char green = 150;
	unsigned char blue = 200;
	int sprite_size = 2;
	char *filepath = "conwaylife/glider_106.lif";
	int row0 = 0;
	int col0 = 0;
	int edge = HEDGE;
	char buffer[SIZE];

	FILE *fp = NULL;
	char *token;
	int c;

	if (argc == 1) {
		printf("usage: life -w 640 -h 480 -r 100 -g 150 -b 200 -s 2 -f conwaylife/glider_106.lif -o 10,10 -e torus\n");
		exit(EXIT_FAILURE);
	}
	while ((c = getopt(argc, argv, ":Hb:e:f:g:h:o:r:s:w:")) != -1)
		switch (c) {
		case 'b':
			if (atoi(optarg) < 0 || atoi(optarg) > 255) {
				printf("%s: option -b value out of range [0-255].\n", argv[0]);
				exit(EXIT_FAILURE);
			} else {
				blue = atoi(optarg);
			}
			break;
		case 'e':
			if (!strcmp(optarg, "hedge"))
				edge = HEDGE;
			else if (!strcmp(optarg, "torus"))
				edge = TORUS;
			else if (!strcmp(optarg, "klein"))
				edge = KLEIN_BOTTLE;
			else {
				printf("%s: option -e value not one of [hedge, torus, klein]. Using Default Edge value: hedge\n", argv[0]);
				edge = HEDGE;
			}
			break;
		case 'f':
			if (optarg != NULL)
				filepath = optarg;
			break;
		case 'g':
			if (atoi(optarg) < 0 || atoi(optarg) > 255) {
				printf("%s: option -g value out of range [0-255].\n",argv[0]);
				exit(EXIT_FAILURE);
			} else {
				green = atoi(optarg);
			}
			break;
		case 'h':
			height = atoi(optarg);
			if (!(height == 480 || height == 600 || height == 768)) {
				printf("%s: option -h value not one of [480, 600, 768]. Using Default width: 480\n", argv[0]);
			}
			break;
		case 'o':
			token = strtok(optarg, ",");
			if (token != NULL) {
				col0 = atoi(token);
				token = strtok(NULL, ",");
			}
			if (token != NULL) {
				row0 = atoi(token);
			}
			break;
		case 'r':
			if (atoi(optarg) < 0 || atoi(optarg) > 255) {
				printf("%s: option -r value out of range [0-255].\n", argv[0]);
				exit(EXIT_FAILURE);
			} else {
				red = atoi(optarg);
			}
			break;
		case 's':
			sprite_size = atoi(optarg);
			if (!(sprite_size == 2 || sprite_size == 4 || sprite_size == 8
					|| sprite_size == 16)) {
				printf("%s: option -s value not one of [2, 4, 8, 16]. Using Default sprite size: 4\n", argv[0]);
			}
			break;
		case 'w':
			width = atoi(optarg);
			if (!(width == 640 || width == 800 || width == 1024)) {
				printf("%s: option -w value not one of [640, 800, 1024]. Using Default width: 640\n", argv[0]);
			}
			break;
		case 'H': /* Help */
			printf("usage: life -w 640 -h 480 -r 100 -g 150 -b 200 -s 2 -f conwaylife/glider_106.lif -o 10,10 -e torus\n");
			printf("or\n");
			printf("usage: life -f filename\n");
			printf("-w width of the screen argument 640, 800, 1024, etc.\n");
			printf("-h height of the screen argument 480, 600, 768, etc\n");
			printf("-e type of edge. Values are hedge, torus or klein (strings)\n");
			printf("-r the red color value, an integer between [0, 255]\n");
			printf("-g the green color value, an integer between [0, 255]\n");
			printf("-b the blue color value, an integer between [0, 255]\n");
			printf("-s size of the sprite. Valid values are 2, 4, 8, or 16 only. An integer.\n");
			printf("-f filename, a life pattern in file format 1.06 or 1.05.\n");
			printf("-o x,y the initial x,y coordinate of the pattern found in the file. No space between the x and y.\n");
			printf("-H help, print out usage information and a brief description of each, option.Note the capitalization,nonstandard,but -h is already taken.\n");
			exit(EXIT_SUCCESS);
		case ':':
			printf("%s: option '-%c' requires an argument\n", argv[0], optopt);
			exit(EXIT_FAILURE);
		case '?':
		default:
			printf("illegal option %c - ignored\n", optopt);
			printf("usage: life -w 640 -h 480 -r 100 -g 150 -b 200 -s 2 -f conwaylife/glider_106.lif -o 10,10 -e torus\n");
			break;
		}

	struct sdl_info_t sdl_info; /* this is needed to graphically display the game */

	init_sdl_info(&sdl_info, width, height, sprite_size, red, green, blue);

	/* your life initialization code here */
	int flip = 0;
	int rows = width / sprite_size;
	int cols = height / sprite_size;
	unsigned char **gridA = allocate_grid(rows, cols);
	unsigned char **gridB = allocate_grid(rows, cols);

	if(gridA == NULL || gridB == NULL){
		exit(EXIT_FAILURE);
	}

    if (row0 < 0 || row0 > rows - 1 || col0 < 0 || col0 > cols -1 ){
    	printf("Initial x, y coordinate (%d, %d) is out or grid range, using default (0,0)\n", col0, row0);
    	row0 = 0;
    	col0 = 0;
    }

	fp = fopen(filepath, "r");
	if (fp == NULL) {
		printf("%s: Failed to open file: %s\n", argv[0], filepath);
		exit(EXIT_FAILURE);
	}

	if (fgets(buffer, sizeof(buffer), fp) != NULL && strlen(buffer) <= 82) {
		if (strstr(buffer, "1.05")) /* Supports Life 1.05 format */
			seed_105_to_grid(gridA, rows, cols, row0, col0, fp);
		else if (strstr(buffer, "1.06")) /* Supports Life 1.06 format */
			seed_106_to_grid(gridA, rows, cols, row0, col0, fp);
		else {/* Unsupported format */
			printf("Error: invalid format: not a 1.05 or 1.06 life format.\n");
			exit(EXIT_FAILURE);
		}
	} else {
		printf("Error: invalid line format, too big.\n");
	}

	/* Main loop: loop forever. */
	while (1) {
		/* your game of life code goes here  */

		if (!flip) {
			sdl_render_life(&sdl_info, gridA);
			if (SDL_GetTicks() % 5 == 0) /* change the  modulus value to slow the rendering */
				//apply_transitions(gridA, gridB, rows, cols, HEDGE);
				apply_transitions(gridA, gridB, rows, cols, edge);
			flip = 1;
		} else {
			if (SDL_GetTicks() % 5 == 0) /* change the  modulus value to slow the rendering */
				sdl_render_life(&sdl_info, gridB);

			apply_transitions(gridB, gridA, rows, cols, edge);
			flip = 0;
		}

		/* Poll for events, and handle the ones we care about.
		 * You can click the X button to close the window
		 */
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_KEYDOWN:
				break;
			case SDL_KEYUP:
				/* If escape is pressed, return (and thus, quit) */
				if (event.key.keysym.sym == SDLK_ESCAPE)
					return 0;
				break;
			case SDL_QUIT:
				return (0);
			}
		}
	}

	free_grid(gridA, rows);
	free_grid(gridB, rows);
	return 0;
}
