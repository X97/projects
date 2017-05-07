/**
 * @file sundays.c
 * @author Namir Hassan
 * @date 03/15/2017
 * @brief Finds how many Sundays fell on the first of the month between 1 Jan 1901 and 31 Dec 2000
 */

 #include <stdio.h>

int main()
{
        int count = 0;
        int days_month;
        int days_past = 2;
        int i;
        int n;

        for (i = 1901; i <= 2000; i++) {

                for (n = 1; n <= 12; n++) {

                        if (n == 4 || n == 6 || n == 9 || n == 11) {

                                days_month = 30;

                        } else if (n == 2) {

                        /* leap year check */

                        if (i % 365 == 0 || (i % 4 == 0 && i % 100 != 0)) {

                                days_month = 29;

                       } else {

                               days_month = 28;

                       }

                       } else {

                               days_month = 31;

                       }

                       if (days_past % 7 == 0) {

                               count++;

                       }

                       days_past += days_month;
               }
       }

         printf("%d\n", count);

         return 0;

}
