/**
 * @file dyn_array.c
 * @author Namir Hassan
 * @date 04/05/2017
 * @brief finds the min, max, average, and median, prints out.
 */

#include <stdio.h>

void find_min(int *a, size_t size, int *min);
void find_max(int *b, size_t size, int *max);
void find_average(int *c, size_t size, double *avg);
void find_median(int *d, size_t size, double *med);

int main()
{
        int a[] = {4,6,2,4,9,11,14,16,1,15,3};
        size_t size = sizeof(a)/sizeof(int);
        int min = 0;
        int max = 0;
        double average = 0.0;
        double med = 0.0;

        find_min(a, size, &min);
        find_max(a, size, &max);
        find_average(a, size, &average);
        find_median(a, size, &med);

        printf("Min: %d\n", min);
        printf("Max: %d\n", max);
        printf("Average: %lf\n", average);
        printf("Median: %lf\n", med);

        return 0;
}

/**
 * finds the min of the array
 * @param a
 * @param size
 * @param min
 * @return nothing (void)
 */
void find_min(int *a, size_t size, int *min)
{
        int i;
        *min = *a;

        for(i=0;i<size;i++) {

                if(*(a+i) < *min) {

                        *min = *(a+i);
                }
        }
}

/**
 * finds the max of the array
 * @param b
 * @param size
 * @param max
 * @return nothing (void)
 */
void find_max(int *b, size_t size, int *max)
{
        int i;
        *max = *b;

        for(i=0;i<size;i++) {

                if(*(b+i) > *max) {

                        *max = *(b+i);
                }
        }

}

/**
 * finds the average of the array
 * @param c
 * @param size
 * @param avg
 * @return nothing (void)
 */
void find_average(int *c, size_t size, double *avg)
{
        int sum = 0;
        int i;

        for(i = 0; i < size; i++) {

                sum += *(c+i);

        }
        *avg = sum/size;

}

/**
 * finds the median of the array
 * @param d
 * @param size
 * @param m
 * @return nothing (void)
 */
void find_median(int *d, size_t size, double *m)
{
        if (size % 2 == 0) {

                *m = (*(d + size % 2) + *(d + size % 2 + 1))/2;

        } else {

                *m = *(d + size % 2);

        }

}
