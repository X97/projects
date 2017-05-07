/**
* @file difference.c
* @author Namir Hassan
* @date 10/10/2016
* @brief Finds the difference between the sum of the square of first 100 natural numbers and the square of the sum
*/

#include <stdio.h>
#include <math.h>


int sum_squares(int lim);
int square_sum(int lim);

int main()
{
     /* checking the sum of square and square of sum outputs */
     /* printf("%d\n", sum_squares(100));
     printf("%d\n", square_sum(100)); */
     printf("%d\n",square_sum(100) - sum_squares(100));

     return 0;
}

/**
* calculates the sum of the squares
* @param lim
* @return sum of the squares
*/
int sum_squares(int lim)
{
     int sum = 0;
     int i;

     for(i = 1; i <= lim; i++)
     {
         sum += pow(i,2);
     }
     return sum;
}

/**
* calculates the square of the sum
* @param lim
* @return square of the sum
*/
int square_sum(int lim)
{
     int sum = 0;
     int square = 0;
     int i;

     for(i = 1; i <= lim; i++)
     {
         sum += i;
     }
     square = pow(sum,2);

     return square;
}
