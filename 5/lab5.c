/**
* @file lab5.c
* @author Namir Hassan
* @date 03/15/2017
* @brief Takes user input for multiple options and stores them until user wants to display its value
*/

#include <stdio.h>
#include <stdlib.h>
#include "zombie.h"

int main()
{
        struct zombie_t zombie[SIZE];

        char buf[32];
        int index = 0;
        int choice;
        char choice1;

        do {

        printf("1.) Enter new zombie information\n");
        printf("2.) Display zombie information\n");
        printf("3.) Return to fighting zombies\n");
        printf(">> ");

        fgets(buf, 32, stdin);
        choice = atoi(buf);

        switch(choice) {

                case 1:
                        printf("Was the zombie found dead? Y or N\n");
                        printf(">> ");

                        fgets(buf, 32, stdin);
                        sscanf(buf, "%c", &choice1);
                        zombie[index].dead = choice1;
                        if (choice1 == 'Y' || choice1 == 'y') {

                        input_toes(zombie, index);


                } else {

                        input_blood(zombie, index);

                }
                        input_time(zombie, index);

                        if(index < SIZE) {

                        index++;

                        }
                        break;

                case 2:

                        print_zombies(zombie, index);
                        break;

                }

        } while (choice != 3);

        printf("\nStay alert! Keep a watch out for zombies!!\n\n");
        printf("GOODBYE and GOOD LUCK!\n\n");

        return 0;
}
