/**
* @file lab2.c
* @brief This program calculates various geometric problems
* @author Namir Hassan
* @date 2/10/17
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

double area_rectangle(double a, double b);
double perimeter_rectangle(double a, double b);
double diagonal_rectangle(double a, double b);
double area_circle(double a);
double circumference(double a);
double area_triangle(double a, double b);
double hypotenuse(double a, double b);
double perimeter_triangle(double a, double b, double c);
double exterior_angle(double a);
double interior_angle(double a);
double area_regular_polygon(double a, double b);

int main()
{
        int choice;
        double height1;
        double width1;
        double radiuside1;
        double height2;
        double base1;
        double side1;
        double side2;
        double side3;

        char val[32];

        int rectang;
        int circl;
        int triang;
        int regpoly;

        /*Upon each iteration, the follow will be printed before going into the switch*/
        do {
                printf("\nGeometry Calculator by Namir Hassan\n");
                printf("______________________________________________________________\n");
                printf("\nOptions\n\n");
                printf("R.) Rectangle\nC.) Cirlce\nT.) Trianlge\nP.) Regular Polygon\nQ.) Quit\n\n");
                printf("Enter choice (R, C, T, P, or Q): ");

        while((choice = getchar()) == '\n');
        printf("\n______________________________________________________________\n\n");

        switch(choice) {

                case 'r':
                case 'R':
                        printf("A.) Area of a Rectangle\nP.) Perimeter of a Rectangle\nD.) Diagonal of a Rectangle\n\n");
                        printf("Enter choice (A, P, D): ");
                        while((rectang = getchar()) == '\n');
                        printf("\n");

                switch(rectang) { /*switch controls which case is called based on user input*/

                        case 'a': /*first option prompts user to enter values for finding rectangle area*/
                        case 'A':
                                printf("Enter height of Rectangle: ");
                                height1 = 0;
                                while (height1 == 0) {
                                        fgets(val,32,stdin);
                                        height1 = atof(val);
                                }

                                printf("\n");

                                printf("Enter width of Rectangle: ");

                                fgets(val,32,stdin);
                                width1 = atof(val);

                                if(height1 <= 0 || width1 <= 0) {
                                        printf("\n______________________________________________________________\n");
                                        printf("\n\nError: Number must be greater than zero.\n");
                                        printf("\n______________________________________________________________\n");
                                        break;

                                } else {

                                printf("\n______________________________________________________________\n\n");
                                printf("\n\t\t\tRectangle Calculations\n\n");
                                printf("Rectangle Area (%lf and %lf): %lf\n",height1,width1,area_rectangle(height1,width1));
                                printf("\n______________________________________________________________\n\n");
                                break;

                                }
                        case 'p': /*second option obtains user input to output rectangles perimeter*/
                        case 'P':
                                printf("Enter height of Rectangle: ");
                                height1 = 0;
                                while (height1 == 0) {
                                        fgets(val,32,stdin);
                                        height1 = atof(val);
                                }
                                printf("\n");

                                printf("Enter width of Rectangle: ");
                                fgets(val,32,stdin);
                                width1 = atof(val);

                                if(height1 <= 0 || width1 <= 0) {
                                        printf("\n______________________________________________________________\n");
                                        printf("\n\nError: Number must be greater than zero.\n");
                                        printf("\n______________________________________________________________\n");
                                        break;

                                } else {

                                printf("\n______________________________________________________________\n\n");
                                printf("\n\t\t\tRectangle Calculations\n\n");
                                printf("Rectangle Perimeter (%lf and %lf): %lf\n",height1,width1,perimeter_rectangle(height1,width1));
                                printf("\n______________________________________________________________\n\n");
                                break;

                                }
                        case 'd': /*third option asks user to enter heigh and width of recangle to find diagonal of rectangle*/
                        case 'D':
                                printf("Enter height of Rectangle: ");
                                height1 = 0;
                                while (height1 == 0) {
                                        fgets(val,32,stdin);
                                        height1 = atof(val);
                                }
                                printf("\n");

                                printf("Enter width of Rectangle: ");
                                fgets(val,32,stdin);
                                width1 = atof(val);

                                if(height1 <= 0 || width1 <= 0) {
                                        printf("\n______________________________________________________________\n");
                                        printf("\n\nError: Number must be greater than zero.\n");
                                        printf("\n______________________________________________________________\n");
                                        break;

                                } else {

                                printf("\n______________________________________________________________\n\n");
                                printf("\n\t\t\tRectangle Calculations\n\n");
                                printf("Diagonal of Rectangle (%lf and %lf): %lf\n",height1,width1,diagonal_rectangle(height1,width1));
                                printf("\n______________________________________________________________\n\n");
                                break;

                                }
                        }
                        break;

                        case 'c':
                        case 'C':
                                printf("A.) Area of a Circle\nC.) Circumference\n\n");
                                printf("Enter choice (A, C): ");
                                while((circl = getchar()) == '\n');
                                printf("\n");

                switch(circl) {

                        case 'a': /*fourth option calculates area of circle based on users input for radius*/
                        case 'A':
                                printf("Enter radius of Cicle: ");
                                radiuside1 = 0;
                                while (radiuside1 == 0) {
                                fgets(val,32,stdin);
                                radiuside1 = atof(val);
                                }
                                printf("\n");
                                if (radiuside1 <= 0) {
                                printf("\n______________________________________________________________\n\n");
                                printf("Error: Number must be greater than zero.\n");
                                printf("\n______________________________________________________________\n\n");
                                break;

                        } else {
                                printf("\n______________________________________________________________\n\n");
                                printf("\n\t\t\tCircle Calculations\n\n");
                                printf("Area of Circle (with Radius %lf): %lf\n",radiuside1,area_circle(radiuside1));
                                printf("\n______________________________________________________________\n");
                                break;

                        }
                        case 'c': /*fifth option calculates circumference based on users input for radius*/
                        case 'C':
                                printf("Enter radius of Cicle: ");
                                radiuside1 = 0;
                                while (radiuside1 == 0) {
                                fgets(val,32,stdin);
                                radiuside1 = atof(val);
                                }
                                printf("\n");

                                if (radiuside1 <= 0) {
                                printf("\n______________________________________________________________\n\n");
                                printf("Error: Number must be greater than zero.\n");
                                printf("\n______________________________________________________________\n\n");
                                break;

                                } else {

                                printf("\n______________________________________________________________\n\n");
                                printf("\n\t\t\tCircle Calculations\n\n");
                                printf("Circumference of Circle (with Radius %lf): %lf\n",radiuside1,circumference(radiuside1));
                                printf("\n______________________________________________________________\n\n");
                                break;

                                }
                        }
                        break;

                        case 't':
                        case 'T':
                                printf("A.) Area of a triangle\nH.) Hypotenuse\nP.) Perimeter of a Triangle\n\n");
                                printf("Enter choice (A, H, P): ");
                                while((triang = getchar()) == '\n');
                                printf("\n");

                switch(triang) {

                        case 'a': /*sixth option calculates triangle area based on base and height input*/
                        case 'A':
                                printf("Enter height of Right Triangle: ");
                                height2 = 0;
                                while (height2 == 0) {
                                fgets(val,32,stdin);
                                height2 = atof(val);
                                }
                                printf("\n");

                                printf("Enter base of Right Triangle: ");
                                fgets(val,32,stdin);
                                base1 = atof(val);
                                printf("\n");

                                if (height2 <= 0 || base1 <= 0) {
                                printf("\n______________________________________________________________\n\n");
                                printf("Error: Number must be greater than zero.\n");
                                printf("\n______________________________________________________________\n\n");
                                break;

                                } else {

                                printf("\n______________________________________________________________\n\n");
                                printf("\n\t\t\tTriangle Calculations\n\n");
                                printf("Area of Triangle (%lf and %lf): %lf\n",height2,base1,area_triangle(height2,base1));
                                printf("\n______________________________________________________________\n\n");
                                break;

                                }
                        case 'h': /*seventh option calculates hypotenuse with two user inputted varable values*/
                        case 'H':
                                printf("Enter height of Right Triangle: ");
                                height2 = 0;
                                while (height2 == 0) {
                                fgets(val,32,stdin);
                                height2 = atof(val);
                                }
                                printf("\n");
                                printf("Enter base of Right Triangle: ");
                                fgets(val,32,stdin);
                                base1 = atof(val);
                                printf("\n");

                                if (height2 <= 0 || base1 <= 0) {
                                printf("\n______________________________________________________________\n\n");
                                printf("Error: Number must be greater than zero.\n");
                                printf("\n______________________________________________________________\n\n");
                                break;

                                } else {

                                printf("\n______________________________________________________________\n\n");
                                printf("\n\t\t\tTriangle Calculations\n\n");
                                printf("Hypotenuse (%lf and %lf): %lf\n",height2,base1,hypotenuse(height2,base1));
                                printf("\n______________________________________________________________\n\n");
                                break;

                                }

                        case 'p': /*eighth option calcuates triangles perimeter using three user inputted sides*/
                        case 'P':
                                printf("Enter first side of Triangle: ");
                                side1 = 0;
                                while (side1 == 0) {
                                fgets(val,32,stdin);
                                side1 = atof(val);
                                }
                                printf("\n");
                                printf("Enter second side of Triangle: ");
                                fgets(val,32,stdin);
                                side2 = atof(val);

                                printf("\n");
                                printf("Enter third side of Triangle: ");
                                fgets(val,32,stdin);
                                side3 = atof(val);

                                if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
                                printf("\n______________________________________________________________\n\n");
                                printf("Error: Number must be greater than zero.\n");
                                printf("\n______________________________________________________________\n\n");
                                break;

                                } else {

                                printf("\n");
                                printf("\n______________________________________________________________\n\n");
                                printf("\n\t\t\tTriangle Calculations\n\n");
                                printf("Perimeter of Triangle (%lf, %lf and %lf): %lf\n",side1,side2,side3,perimeter_triangle(side1,side2,side3));
                                printf("\n______________________________________________________________\n\n");
                                break;

                                }
                        }
                        break;

                        case 'p':
                        case 'P':

                                printf("E.) Exterior Angle\nI.) Interior Angle\nA.) Area of a Regular Polygon\n\n");
                                printf("Enter choice (E, I, A): ");
                                while((regpoly = getchar()) == '\n');
                                printf("\n");

                switch(regpoly) {

                        case 'e': /*calculates exterior angles when given a number of sides by user*/
                        case 'E':

                                printf("Enter number of sides: ");
                                side1 = 0;
                                while (side1 == 0) {
                                fgets(val,32,stdin);
                                side1 = atof(val);
                                }
                                printf("\n");

                                if (side1 < 3) {
                                printf("\n______________________________________________________________\n\n");
                                printf("Error: Sides must be 3 or more.\n");
                                printf("\n______________________________________________________________\n\n");
                                break;

                                } else {

                                printf("\n______________________________________________________________\n\n");
                                printf("\n\t\t\tPolygon (Regular)\n\n");
                                printf("Exterior Angle (%lf sided): %lf\n",side1,exterior_angle(side1));
                                printf("\n______________________________________________________________\n\n");
                                break;

                                }
                        case 'i': /*calculates interior angle given a number of sides by user*/
                        case 'I':

                                printf("Enter number of sides: ");
                                side1 = 0;
                                while (side1 == 0) {
                                fgets(val,32,stdin);
                                side1 = atof(val);
                                }
                                if (side1 < 3) {
                                        printf("\n______________________________________________________________\n\n");
                                        printf("Error: Sides must be 3 or more.\n");
                                        printf("\n______________________________________________________________\n\n");
                                        break;

                                } else {
                                printf("\n");
                                printf("\n\t\t\tPolygon (Regular)\n\n");
                                printf("Interior Angle (%lf sided): %lf\n",side1,interior_angle(side1));
                                break;

                        }
                        case 'a': /*calculates the area of regular polygon when given number and length of sides*/
                        case 'A':

                                printf("Enter number of sides: ");
                                side1 = 0;
                                while (side1 == 0) {
                                fgets(val,32,stdin);
                                side1 = atof(val);
                        }
                                printf("\n");
                                printf("Enter length of sides: ");
                                fgets(val,32,stdin);
                                side2 = atof(val);

                                if (side1 < 3 || side2 <= 0) {
                                        printf("\n______________________________________________________________\n\n");
                                        printf("Error: Sides must be 3 or more.\n");
                                        printf("\n______________________________________________________________\n\n");
                                        break;

                                } else {
                                printf("\n");
                                printf("\n______________________________________________________________\n\n");
                                printf("\n\t\t\tPolygon (Regular)\n\n");
                                printf("Regular Polygon Area: %lf\n", area_regular_polygon(side1,side2));
                                printf("\n______________________________________________________________\n\n");
                                break;

                                }
                        }
                }
                break;

        } while(choice == 'Q' || choice == 'q'); /*Program will exit upon entering 0 during option prompt*/

        printf("\nQuitting...\n\n");

        return 0;
}

/**
* calculates area of rectangle
* @param a is the length
* @param b is the width
* @return (a*b)
*/
double area_rectangle(double a, double b)
{
        return (a*b);
}

/**
* calculates perimeter of rectangle
* @param a is the length
* @param b is the width
* @return ((2*a)+(2*b))
*/
double perimeter_rectangle(double a, double b)
{
        return ((2*a)+(2*b));
}

/**
* calculates diagonal of rectangle
* @param a is the length
* @param b is the width
* @return (sqrt((a*a)+(b*b)))
*/
double diagonal_rectangle(double a, double b)
{
        return (sqrt((a*a)+(b*b)));
}

/**
* calculates area of a circle
* @param a is the radius
* @return (pow(a,2)*(3.141593))
*/
double area_circle(double a)
{
      return (pow(a,2)*(3.141593));
}

/**
* calculates circumference when given radius value
* @param a is the radius
* @return ((a*(2*3.141593)))
*/
double circumference(double a)
{
      return (a*(2*3.141593));
}

/**
* calculates area of triangle when given base and height
* @param a is the base
* @param b is the height
* @return ((.5)*(a*b))
*/
double area_triangle(double a, double b)
{
      return ((.5)*(a*b));
}

/**
* calculates hypotenuse
* @param a is the first side
* @param b is the second side
* @return (pow(a,2)+pow(b,2))
*/
double hypotenuse(double a, double b)
{
      return (sqrt(pow(a,2)+pow(b,2)));
}

/**
* calculates the perimeter of a triangle
* @param a is the first side
* @param b is the second side
* @param c is the thrid side
* @return (a+b+c)
*/
double perimeter_triangle(double a, double b, double c)
{
      return (a+b+c);
}

/**
* calculates exterior angle when given a value for number of sides
* @param a number of sides
* @return (360/a)
*/
double exterior_angle(double a)
{
      return (360/a);
}

/**
* calculates interior angle based on number of sides
* @param a number of sides
* @return ((180*(a-2))/(a))
*/
double interior_angle(double a)
{
      return ((180*(a-2))/(a));
}

/**
* calculates area of regular polygon based on two variable values
* @param a number of sides
* @param b length of sides
* @return ((pow(a,2)*b)/(4.0*tan(3.141593/b)))
*/
double area_regular_polygon(double a, double b) /**/
{
      return ((pow(a,2)*b)/(4.0*tan(3.141593/b)));
}
