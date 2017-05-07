/**
 * @file lab4_q3.c
 * @author Namir Hassan
 * @date 03/1/2017
 * @brief calculates the Euclidean distance and the Manhattan distance between two points
 */


 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>

struct point_t {

         double x;
         double y;

};

double eucl(struct point_t point1, struct point_t point2);

double manh(struct point_t point1, struct point_t point2);


int main()
{
        struct point_t point1;
        struct point_t point2;

        point1.x = 5.1;
        point2.x = 6.9;
        point1.y = 6.4;
        point2.y = 9.9;

        printf("\nEuclidean: %lf\n", eucl(point1, point2));

        printf("\nManhattan: %lf\n", manh(point1, point2));

        printf("\n");

        return 0;
}

/**
 * Takes a double number into a Euclidean equation to be calculated
 * @param point1
 * @param point2
 * @return the calculated value of the Euclidean equation as a double
 */
double eucl(struct point_t point1, struct point_t point2)
{
        return sqrt((pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2)));
}

/**
 * Takes a double number into a Manhattan equation to be calculated
 * @param point1
 * @param point2
 * @return the calculated value of the Manhattan equation as a double
 */
double manh(struct point_t point1, struct point_t point2)
{
        return fabs(point1.x - point2.x) + fabs(point1.y - point2.y);
}
