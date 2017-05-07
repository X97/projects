/**
* @file lab4_q4.c
* @author Namir Hassan
* @date 03/1/2017
* @brief Takes date and outputs the Tropical Zodiac date
*/

#include <stdio.h>
#include <stdlib.h>

#define ENTER_INTEGER 1
#define QUIT 2
#define LEN 32

struct date_t {

         unsigned short month;
         unsigned short day;
         unsigned short year;

};

enum month {

         JAN = 1,
         FEB,
         MAR,
         APR,
         MAY,
         JUNE,
         JUL,
         AUG,
         SEPT,
         OCT,
         NOV,
         DEC

};

enum zodiac {

        CAPRICORN = 20,
        AQUARIUS,
        PISCES,
        ARIES,
        TAURUS,
        GEMINI,
        CANCER,
        LEO,
        VIRGO,
        LIBRA,
        SCORPIO,
        SAGITTARIUS

};

unsigned short zod(unsigned short day, struct date_t date);
unsigned short leap(unsigned short year);
unsigned short find_day(unsigned short month, unsigned short day);
void print_info(struct date_t date, unsigned short zodiac);

int main()
{
         struct date_t date;

         char buf[LEN];
         int n;
         unsigned short h;

         date.month = 0;
         date.day = 0;
         date.year = 0;
         unsigned short zodiac;

         do {

         printf("1.) Enter an integer (Continue)\n2.) (Quit)\n");
         fgets(buf, LEN, stdin);
         n = atoi(buf);

                 switch(n) {
                         case ENTER_INTEGER:

                                printf("Enter a date:\n");
                                fgets(buf, LEN, stdin);

                                sscanf(buf, "%hu/%hu/%hu", &date.month, &date.day, &date.year);

                                printf("\n");

                                h = find_day(date.month, date.day);

                                if(date.month > FEB) {

                                        date.day += leap(date.year);

                                }

                                leap(date.year);
                                zodiac = zod(h, date);

                                print_info(date, zodiac);

                                break;

                        case QUIT:
                                printf("\nQuitting...\n");
                                exit(EXIT_SUCCESS);
                                break;

                        default:
                                printf("You entered something else.\n\n");
                                break;
                }
        } while (n != 2);

        return 0;
}

/**
 * Locates day number
 * @param month
 * @param day
 * @return the number of day
 */
unsigned short find_day(unsigned short month, unsigned short day) {

        switch (month) {

                case DEC:
                        day += 30;

                case NOV:
                        day += 31;

                case OCT:
                        day += 30;

                case SEPT:
                        day += 31;

                case AUG:
                        day += 31;

                case JUL:
                        day += 30;

                case JUNE:
                        day += 31;

                case MAY:
                        day += 30;

                case APR:
                        day += 31;

                case MAR:
                        day += 28;

                case FEB:
                        day += 31;

                case JAN:
                        day += 0;

                        break;
        }

        return day;

}

/**
 * Checks if the year is a leap year
 * @param year
 * @return 1 or 0 based on if it is a leap year or not
 */
unsigned short leap(unsigned short year) {

        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                /* leap year */
                return 1;
        else {
                /* not a leap year */
                return 0;
        }

}

/**
 * Determines the zodiac sign
 * @param day
 * @param date
 * @return the correct zodiac based on the day of the month
 */
unsigned short zod(unsigned short day, struct date_t date)
{


        if(day >= 21 && day < 51) {
                return AQUARIUS;
        }
        if (day >= 51 + leap(date.year) && day < 81 + leap(date.year)) {
                return PISCES;
        }
        if (day >= 81 + + leap(date.year) && day < 111 + + leap(date.year)) {
                return ARIES;
        }
        if (day >= 111 + leap(date.year) && day < 143 + leap(date.year)) {
                return TAURUS;
        }
        if (day >= 143 + leap(date.year) && day < 173 + leap(date.year)) {
                return GEMINI;
        }
        if (day >= 173 + leap(date.year) && day < 205 + leap(date.year)) {
                return CANCER;
        }
        if (day >= 205 + leap(date.year) && day < 235 + leap(date.year)) {
                return LEO;
        }
        if (day >= 235 + leap(date.year) && day < 267 + leap(date.year)) {
                return VIRGO;
        }
        if (day >= 267 + leap(date.year) && day < 297 + leap(date.year)) {
                return LIBRA;
        }
        if (day >= 297 + leap(date.year) && day < 327 + leap(date.year)) {
                return SCORPIO;
        }
        if (day >= 327 + leap(date.year) && day < 356 + leap(date.year)) {
                return SAGITTARIUS;
        }
        if ((day >= 356 + leap(date.year) && day < 356 + leap(date.year)) || (day < 21)) {
                return CAPRICORN;
        }
        return 0;

}

/**
 * Prints the date entered by user as well as the zodiac sign
 * @param date
 * @param zodiac
 * @return nothing (void)
 */
void print_info(struct date_t date, unsigned short zodiac)
{

        switch (date.month) {

                case 1:
                        printf("January %hu", date.day);
                        if(zodiac == CAPRICORN) {
                                printf("\nCAPRICORN\n\n");
                        } else {

                                printf("\nAQUARIUS\n\n");
                        }
                        break;
                case 2:
                        printf("February %hu", date.day);
                        if(zodiac == AQUARIUS) {
                                printf("\nAQUARIUS\n\n");
                        } else {

                                printf("\nPISCES\n\n");
                        }
                        break;
                case 3:
                        printf("March %hu", date.day);
                        if(zodiac == PISCES) {
                                printf("\nPISCES\n\n");
                        } else {

                                printf("\nARIES\n\n");
                        }
                        break;
                case 4:
                        printf("April %hu", date.day);
                        if(zodiac == ARIES) {
                                printf("\nARIES\n\n");
                        } else {

                                printf("\nTAURUS\n\n");
                        }
                        break;
                case 5:
                        printf("May %hu", date.day);
                        if(zodiac == TAURUS) {
                                printf("\nTAURUS\n\n");
                        } else {

                                printf("\nGEMINI\n\n");
                        }
                        break;
                case 6:
                        printf("June %hu", date.day);
                        if(zodiac == GEMINI) {
                                printf("\nGEMINI\n\n");
                        } else {

                                printf("\nCANCER\n\n");
                        }
                        break;
                case 7:
                        printf("July %hu", date.day);
                        if(zodiac == CANCER) {
                                printf("\nCANCER\n\n");
                        } else {

                                printf("\nLEO\n\n");
                        }
                        break;
                case 8:
                        printf("August %hu", date.day);
                        if(zodiac == LEO) {
                                printf("\nLEO\n\n");
                        } else {

                                printf("\nVIRGO\n\n");
                        }
                        break;
                case 9:
                        printf("September %hu", date.day);
                        if(zodiac == VIRGO) {
                                printf("\nVIRGO\n\n");
                        } else {

                                printf("\nLIBRA\n\n");
                        }
                        break;

                case 10:
                        printf("October %hu", date.day);
                        if(zodiac == LIBRA) {
                                printf("\nLIBRA\n\n");
                        } else {

                                printf("\nSCORPIO\n\n");
                        }
                        break;
                case 11:
                        printf("November %hu", date.day);
                        if(zodiac == SCORPIO) {
                                printf("\nSCORPIO\n\n");
                        } else {

                                printf("\nSAGITTARIUS\n\n");
                        }
                        break;
                case 12:
                        printf("December %hu", date.day);
                        if(zodiac == SAGITTARIUS) {
                                printf("\nSAGITTARIUS\n\n");
                        } else {

                                printf("\nCAPRICORN\n\n");
                        }
                        break;
        }

}
