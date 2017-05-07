/**
 * @file smallest.c
 * @author Namir Hassan
 * @date 03/15/2017
 * @brief Finds the smallest positive number that is evenly divisble by 1 to 20
 */

#include <stdio.h>

int main()
{
        /*variables*/
        int i;
        int n;
        int count;

        for(i = 21; i > 0; i++) {

          count = 0;

          for(n = 2; n <= 20; n++)
          {
                if(i % n != 0) {

                break;

                }

                count++;

          }
                if(count == 19) {

                        break;

                }
      }

        printf("%d\n", i);

        return 0;
}
