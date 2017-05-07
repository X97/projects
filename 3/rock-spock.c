/**
 * @file rock-spock.c
 * @brief Play Rock-paper-scissors-lizard-Spock against the machine
 * @author Namir Hassan
 * @date 2/20/2017
 */
 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define COMPUTER 8088
#define PLAYER 1000

#define CHOICES 5

#define ROCK 0
#define PAPER 1
#define SCISSORS 2
#define LIZARD 3
#define SPOCK 4

void move(int who, int move);
int winner(int computer, int player);
void print_winner(int winner, int comp_move, int player_move);
int nrand(int range);
void seed();


int main(void)
{
	int computer;
	int player;
	int win;

	/* set up the seed value for the random number generator */
	/* call only once */
	seed();

        /* todo - add a while loop to keep playing */

	player = 5;
	int x = 1;
	int usrin = 0;

	while(x == 1) {

	while (usrin == 0) {

		usrin = 1;

	printf("\n\nEnter a move:\n");
	printf("0 for ROCK\n");
	printf("1 for PAPER\n");
	printf("2 for SCISSORS\n");
	printf("3 for LIZARD\n");
	printf("4 for SPOCK\n");
	printf("5 to have SPOCK eat a ROCK while chasing a LIZARD and quit\n");
	printf("Move: ");
	scanf("%d", &player);
	printf("\n\n");

        /* todo - error check input */


	switch (player) {

	case 5:
		if (player == 5) {

			printf("\nQuitting...\n\n");
			break;

		}
	default:
		if (player < 0 || player > 5) {

			printf("Error: please enter a number 0-5. \n\n");
			usrin = -1;
			break;

		}
		break;
		}
}

	/* todo -- exit from program when player selects 5 */
	/* otherwise play a game of rock-paper-scissors-lizard-spock */

        /* debug -- you don't need move() to play game  */
	if (player != 5) {

		usrin = 0;

		move(PLAYER, player);

	        /* generate random number for computers play */
		computer = nrand(CHOICES);

		/*debug -- you don't need this to play the game */
		move(COMPUTER, computer);


	        /* todo --implement function winner() */
	        /* todo --implement function print_winner() */
		//printf("todo -- who wins? implement the winner with switch statements\n");

		printf("\n");

		win = winner(computer, player);

		print_winner(win, computer, player);

		printf("\n");

		} else {
			x = 0;
		}
	}
	return 0;
}


/** prints the player's or computer's  move to stdin
 * used in debugging
 * @param who is it the computer or the player's move?
 * @param move what move did they make
 * @return void
 */
void move(int who, int move)
{
	if (who == COMPUTER)
		printf("Computer's play is ");
	else
		printf("Player's play is ");


	switch(move) {
	case ROCK:
		printf("ROCK\n");
		break;
	case PAPER:
		printf("PAPER\n");
		break;
	case SCISSORS:
		printf("SCISSORS\n");
		break;
	case SPOCK:
		printf("SPOCK\n");
		break;
	case LIZARD:
		printf("LIZARD\n");
		break;
    	}
}


/**
 * determines the winner either COMPUTER or PLAYER
 * @param computer the computer's move
 * @param player the player's move
 * @return the winner of the game
 */
int winner(int computer, int player)
{
	/* todo - determine the winner; use switch statements */

	switch(computer) {

		case ROCK:

			switch(player) {

				case ROCK:
					return -1;
					break;

				case PAPER:
					return PLAYER;
					break;

				case SCISSORS:
					return COMPUTER;
					break;

				case SPOCK:
					return COMPUTER;
					break;

				case LIZARD:
					return PLAYER;
					break;
			}

		case PAPER:

			switch(player) {

				case ROCK:
					return COMPUTER;
					break;

				case PAPER:
					return -1;
					break;

				case SCISSORS:
					return COMPUTER;
					break;

				case SPOCK:
					return PLAYER;
					break;

				case LIZARD:
					return PLAYER;
					break;
				}

		case SCISSORS:
			switch(player) {

				case ROCK:
					return PLAYER;
					break;

				case PAPER:
					return COMPUTER;
					break;

				case SCISSORS:
					return -1;
					break;

				case SPOCK:
					return PLAYER;
					break;

				case LIZARD:
					return COMPUTER;
					break;
				}

		case SPOCK:
			switch(player) {

				case ROCK:
					return COMPUTER;
					break;

				case PAPER:
					return PLAYER;
					break;

				case SCISSORS:
					return COMPUTER;
					break;

				case SPOCK:
					return -1;
					break;

				case LIZARD:
					return PLAYER;
					break;
			}

		case LIZARD:
			switch(player) {

				case ROCK:
					return PLAYER;
					break;

				case PAPER:
					return COMPUTER;
					break;

				case SCISSORS:
					return PLAYER;
					break;

				case SPOCK:
					return COMPUTER;
					break;

				case LIZARD:
					return -1;
					break;

				}

	}
	return 0;
}

/**
 * prints the winner of the game to stdin
 * @param winner who won the computer or player
 * @param comp_move what move did the computer make
 * @param play_move what move did the player make
 * @return void
 */
void print_winner(int winner, int comp_move, int player_move)
{
    /* todo - use a switch statement

    print Computer Wins! or Player Wins!

    And how they won. Use the phrases below


    Scissors cuts paper
    Paper covers rock
    Rock crushes lizard
    Lizard poisons Spock
    Spock smashes scissors
    Scissors decapitates lizard
    Lizard eats paper
    Paper disproves Spock
    Spock vaporizes rock
    Rock crushes scissors
*/

	int loser;

	if(winner == -1) {

		printf("DRAW");
	} else {



	if (winner == COMPUTER) {

		printf("Computer Wins!\n");

		winner = comp_move;
		loser = player_move;

	} else {

		printf("Player Wins!\n");
		loser = player_move;
		winner = comp_move;

	}


    switch(winner) {

    	case ROCK:

    		switch(loser) {

    			case ROCK:
    				printf("DRAW\n");
    				break;

    			case SCISSORS:
    				printf("Rock crushes scissors\n");
    				break;

    			case LIZARD:
    				printf("Rock crushes lizard\n");
    				break;
    			}
			break;

    	case PAPER:

    		switch(loser) {

    			case ROCK:
    				printf("Paper covers rock\n");
    				break;

    			case PAPER:
    				printf("DRAW\n");
    				break;

    			case SPOCK:
    				printf("Paper disproves Spock\n");
    				break;

    			}
			break;

    	case SCISSORS:
    		switch(loser) {

    			case PAPER:
    				printf("Scissors cuts paper\n");
    				break;

    			case SCISSORS:
    				printf("DRAW\n");
    				break;

    			case LIZARD:
    				printf("Scissors decapitates lizard\n");
    				break;
    			}
			break;

    	case SPOCK:
    		switch(loser) {

    			case ROCK:
    				printf("Spock vaporizes rock\n");
    				break;

    			case SCISSORS:
    				printf("Spock smashes scissors\n");
    				break;

    			case SPOCK:
				printf("DRAW\n");
    				break;

    		}
		break;

    	case LIZARD:
    		switch(loser) {

    			case PAPER:
    				printf("Lizard eats paper\n");
    				break;

    			case SPOCK:
    				printf("Lizard poisons Spock\n");
    				break;

    			case LIZARD:
    				printf("DRAW\n");
    				break;

    			}
			break;
	}
    }

}

/**
 * returns a uniform random integer n, between 0 <= n < range
 * @param range defines the range of the random number [0,range)
 * @return the generated random number
 */
int nrand(int range)
{
	return rand() % range;
}

/**
 * call this to seed the random number generator rand()
 * uses a simple seed -- the number of seconds since the epoch
 * call once before using nrand and similar functions that call rand()
 */
void seed(void)
{
  	srand((unsigned int)time(NULL));
}
