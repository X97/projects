/**
* @file lab1.c
* @brief This program calculates various geometric problems
* @author Namir Hassan
* @date 2/3/17
*/

#include <stdio.h>
#include <math.h>

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
        double radius;
        double height2;
        double base;
        double side1;
        double side2;
        double side3;

/*Upon each iteration, the following will be printed before going into the switch*/

        do {
                printf("\nGeometry Calculator by Namir Hassan\n\n");

                printf("Options\n\n");
                printf("1.) Area of a Rectangle\n2.) Perimeter of a Rectangle\n3.) Diagonal of a Rectangle\n4.) Area of a Circle\n5.) Circumference\n6.) Area of a triangle\n7.) Hypotenuse\n8.) Perimeter of a Triangle\n9.) Exterior Angle\n10.) Interior Angle\n11.) Area of a Regular Polygon\n\n");

                printf("Enter choice (numerical value 1-11 or 0 to exit): ");
                scanf("%d", &choice);
                printf("\n");

        switch(choice) { /*switch controls which case is called based on user input*/

                case 1: /*first option prompts user to enter values for finding rectangle area*/
                        printf("Enter height of Rectangle: ");
                        scanf("%lf", &height1);
                        printf("Enter width of Rectangle: ");
                        scanf("%lf", &width1);
                        printf("\n\t\t\tRectangle Calculations\n\n");
                        printf("Rectangle Area (%lf and %lf): %lf\n",height1,width1,area_rectangle(height1,width1));
                        break;

                case 2: /*second option obtains user input to output rectangles perimeter*/
                        printf("Enter height of Rectangle: ");
                        scanf("%lf", &height1);
                        printf("Enter width of Rectangle: ");
                        scanf("%lf", &width1);
                        printf("\n\t\t\tRectangle Calculations\n\n");
                        printf("Rectangle Perimeter (%lf and %lf): %lf\n",height1,width1,perimeter_rectangle(height1,width1));
                        break;

                case 3: /*third option asks user to enter heigh and width of recangle to find diagonal of rectangle*/
                        printf("Enter height of Rectangle: ");
                        scanf("%lf", &height1);
                        printf("Enter width of Rectangle: ");
                        scanf("%lf", &width1);
                        printf("\n\t\t\tRectangle Calculations\n\n");
                        printf("Diagonal of Rectangle (%lf and %lf): %lf\n",height1,width1,diagonal_rectangle(height1,width1));
                        break;

                case 4: /*fourth option calculates area of circle based on users input for radius*/
                        printf("Enter radius of Cicle: ");
                        scanf("%lf", &radius);
                        printf("\n\t\t\tCircle Calculations\n\n");
                        printf("Area of Circle (with Radius %lf): %lf\n",radius,area_circle(radius));
                        break;

                case 5: /*fifth option calculates circumference based on users input for radius*/
                        printf("Enter radius of Cicle: ");
                        scanf("%lf", &radius);
                        printf("\n\t\t\tCircle Calculations\n\n");
                        printf("Circumference of Circle (with Radius %lf): %lf\n",radius,circumference(radius));
                        break;

                case 6: /*sixth option calculates triangle area based on base and height input*/
                        printf("Enter height of Right Triangle: ");
                        scanf("%lf", &height2);
                        printf("Enter base of Right Triangle: ");
                        scanf("%lf", &base);
                        printf("\n\t\t\tTriangle Calculations\n\n");
                        printf("Area of Triangle (%lf and %lf): %lf\n",height2,base,area_triangle(height2,base));
                        break;

                case 7: /*seventh option calculates hypotenuse with two user inputted varable values*/
                        printf("Enter height of Right Triangle: ");
                        scanf("%lf", &height2);
                        printf("Enter base of Right Triangle: ");
                        scanf("%lf", &base);
                        printf("\n\t\t\tTriangle Calculations\n\n");
                        printf("Hypotenuse (%lf and %lf): %lf\n",height2,base,hypotenuse(height2,base));
                        break;

                case 8: /*eighth option calcuates triangles perimeter using three user inputted sides*/
                        printf("Enter first side of Triangle: ");
                        scanf("%lf", &side1);
                        printf("Enter second side of Triangle: ");
                        scanf("%lf", &side2);
                        printf("Enter third side of Triangle: ");
                        scanf("%lf", &side3);
                        printf("\n\t\t\tTriangle Calculations\n\n");
                        printf("Perimeter of Triangle (%lf, %lf and %lf): %lf\n",side1,side2,side3,perimeter_triangle(side1,side2,side3));
                        break;

                case 9: /*calculates exterior angles when given a number of sides by user*/
                        printf("Enter number of sides: ");
                        scanf("%lf", &side1);
                        printf("\n\t\t\tPolygon (Regular)\n\n");
                        printf("Exterior Angle (%lf sided): %lf\n",side1,exterior_angle(side1));
                        break;

                case 10: /*calculates interior angle given a number of sides by user*/
                        printf("Enter number of sides: ");
                        scanf("%lf", &side1);
                        printf("\n\t\t\tPolygon (Regular)\n\n");
                        printf("Interior Angle (%lf sided): %lf\n",side1,interior_angle(side1));
                        break;

                case 11: /*calculates the area of regular polygon when given number and length of sides*/
                        printf("Enter number of sides: ");
                        scanf("%lf", &side1);
                        printf("Enter length of sides: ");
                        scanf("%lf", &side2);
                        printf("\n\t\t\tPolygon (Regular)\n\n");
                        printf("Regular Polygon Area: %lf\n", area_regular_polygon(side1,side2));
                        break;

                } /* end of switch */


        } while(choice != 0); /*Program will exit upon entering 0 during option prompt*/

        printf("Quitting...\n\n");

        return 0;
}

/**
* calculates area of rectangle
* @param a is the length
* @param b is the width
* @return product of a and b
*/
double area_rectangle(double a, double b)
{
        return a*b;
}

/**
* calculates perimeter of rectangle
* @param a is the length
* @param b is the width
* @return (2*a)+(2*b)
*/
double perimeter_rectangle(double a, double b)
{
        return (2*a)+(2*b);
}

/**
* calculates diagonal of rectangle
* @param a is the length
* @param b is the width
* @return sqrt((a*a)+(b*b))
*/
double diagonal_rectangle(double a, double b)
{
        return sqrt((a*a)+(b*b));
}

/**
* calculates area of a circle
* @param a is the radius
* @return pow(a,2)*(3.141593)
*/
double area_circle(double a)
{
      return pow(a,2)*(3.141593);
}

/**
* calculates circumference when given radius value
* @param a is the radius
* @return (a*(2*3.141593))
*/
double circumference(double a)
{
      return (a*(2*3.141593));
}

/**
* calculates area of triangle when given base and height
* @param a is the base
* @param b is the height
* @return (.5)*(a*b)
*/
double area_triangle(double a, double b)
{
      return (.5)*(a*b);
}

/**
* calculates hypotenuse
* @param a is the first side
* @param b is the second side
* @return pow(a,2)+pow(b,2)
*/
double hypotenuse(double a, double b)
{
      return sqrt(pow(a,2)+pow(b,2));
}

/**
* calculates the perimeter of a triangle
* @param a is the first side
* @param b is the second side
* @param c is the thrid side
* @return a+b+c
*/
double perimeter_triangle(double a, double b, double c)
{
      return a+b+c;
}

/**
* calculates exterior angle when given a value for number of sides
* @param a number of sides
* @return 360/a
*/
double exterior_angle(double a)
{
      return 360/a;
}

/**
* calculates interior angle based on number of sides
* @param a number of sides
* @return (180*(a-2))/(a)
*/
double interior_angle(double a)
{
      return (180*(a-2))/(a);
}

/**
* calculates area of regular polygon based on two variable values
* @param a number of sides
* @param b length of sides
* @return (pow(a,2)*b)/(4.0*tan(3.141593/b))
*/
double area_regular_polygon(double a, double b) /**/
{
      return (pow(a,2)*b)/(4.0*tan(3.141593/b));
}
