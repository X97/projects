#include <stdio.h>
#include <stdlib.h>
#include "zombie.h"

/**
* Takes time and day and stores value
* @param zombie[]
* @param index
* @return nothing (void)
*/
void input_time(struct zombie_t zombie[], int index) {

        char buf[32];

        printf("Please choose the day this zombie was encountered: \n");
        printf("1.) Monday\n");
        printf("2.) Tuesday\n");
        printf("3.) Wednesday\n");
        printf("4.) Thursday\n");
        printf("5.) Friday\n");
        printf("6.) Saturday\n");
        printf("7.) Sunday\n");
        printf(">> ");

        fgets(buf, 32, stdin);
        zombie[index].day = atoi(buf);

        printf("Enter time when this zombie was encountered.\n");
        printf("Separate hours, minutes, and seconds by colons.\n");
        printf("HH:MM:SS\n");
        printf(">> ");

        fgets(buf, 32, stdin);
        sscanf(buf, "%d:%d:%d", &zombie[index].hour, &zombie[index].min, &zombie[index].sec);

}

/**
* Takes input for number of toes
* @param zombie[]
* @param index
* @return nothing (void)
*/
void input_toes(struct zombie_t zombie[], int index) {

        char buf[32];

        printf("Please enter the number of toes the zombie has.\n");
        printf(">> ");

        fgets(buf, 32, stdin);
        zombie[index].toes = atoi(buf);


}

/**
* Takes input for blood
* @param zombie[]
* @param index
* @return nothing (void)
*/
void input_blood(struct zombie_t zombie[], int index) {

        char buf[32];

        printf("Please enter the amount of blood that oozed from its body\n");
        printf("after you killed it (in mL)\n");
        printf(">> ");

        fgets(buf, 32, stdin);
        zombie[index].blood = atoi(buf);

}

/**
* Prints the stored values based on status of zombie and the time.
* @param zombie[]
* @param size
* @return nothing (void)
*/
void print_zombies(struct zombie_t zombie[], int size) {

        const char a[8][9] = {"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        int i;

        for(i = 0; i < size; i++) {

                if(zombie[i].dead == 'Y' || zombie[i].dead == 'y') {

                        printf("This zombie was found dead.\n");
                        printf("This zombie had %d toes.\n", zombie[i].toes);


                } else if (zombie[i].dead == 'N' || zombie[i].dead == 'n') {

                        printf("Zombie was found ALIVE!\n");
                        printf("It was drained of %f mL of blood once killed.\n", zombie[i].blood);

                }
                printf("This zombie was sighted %s at %d:%d:%d.\n", a[zombie[i].day], zombie[i].hour, zombie[i].min, zombie[i].sec);

        }

}
