//*************************************************************
//*** ΠΛΣ50 "Βασικές Εξειδικεύσεις σε Θεωρία και Λογισμικό" ***
//***                   Εργασία Ε01 - Θέμα 2                ***
//***                                                       ***
//***                   Ακ.έτος 2016-17                     ***
//***                                                       ***
//*************************************************************



/*
 * C program to find the perimeter of different geometrical shapes such as
 * circle, square, rectangle etc using switch statements.
 */
#include <stdio.h> /* needed for printf(), scanf() */
#define PI 3.14159 /* definition of the Pi mathematical constant */
#include <math.h>   /* needed for sqrt() */
float Circle (float);
float Rectangle (float, float);
float Triangle (float,float);
float Square (float);  /* definition of the variables of the functions are used */

void print_menu() /* creating the menu that user input choice */
{

   printf("-------------------------\n");
    printf(" 1:Circle\n");
    printf(" 2:Rectangle\n");
    printf(" 3:Triangle\n");
    printf(" 4:Square\n");
    printf("Exit Program -> enter 0\n");
    printf("-------------------------\n");
    printf("Enter the choice of you selection: ");
}

    int main()
{
    int choice;
    float perimeter1, perimeter2, perimeter3, perimeter4; /* definition of the variables */
    float a,b,c,r,base,height;
    print_menu();

    scanf(" %d", &choice); /* reading the choice of the user */
    while(choice!= 0) /* while statement that user can keep searching for the perimeter until exit */
    {
     if (choice==1) /* if else if statement for the choices */
     {
       printf("Enter the radius of the circle: ");
       scanf(" %f", &r);
       perimeter1=Circle(r);  /* calling the function that calculus the perimeter of circle */
       printf("perimeter of a circle = %f\n", perimeter1);
       printf("back to menu\n");
            }

    else if (choice==2)
    {
     printf("Enter the breadth and length of the Rectangle:");
        scanf(" %f %f", &b, &c);
        perimeter2=Rectangle(b,c); /* calling the function that calculus the perimeter of rectangle */
       printf("perimeter of a Rectangle = %f\n", perimeter2);
printf("back to menu\n");
    }

    else if (choice==3)
    {
     printf("Enter the base and height:");
        scanf(" %f %f", &base, &height);
        perimeter3=Triangle(base,height); /* calling the function that calculus the perimeter of triangle */
        printf("Perimeter of a Triangle = %f\n", perimeter3);
printf("back to menu\n");
    }

    else if (choice==4)
    {
      printf("Enter the side of the square:");
        scanf(" %f", &a);
        perimeter4=Square(a); /* calling the function that calculus the perimeter of square */
        printf("Perimeter of a Square = %f\n", perimeter4);
printf("back to menu\n");
    }

       else /* in case that user accidentally choice input is different than given above */
     {
    printf("Error in the selection choice - Try Again please\n");
    }


        print_menu();
        scanf(" %d", &choice);  /* needed for the while statement to print again the menu and read the choice of the user */
}
        return 0;
}

float Circle (float r) /* creating the function that calculus the perimeter of circle */
  {
    float perimeter1;
    perimeter1=2*PI*r;
    return perimeter1;
  }

  float Rectangle (float b, float c) /* creating the function that calculus the perimeter of rectangle with 2 variables */
  {
    float perimeter2;
    perimeter2=2*(b+c);
    return perimeter2;
  }

  float Triangle(float base, float height) /* creating the function that calculus the perimeter of triangle */
  {
    float perimeter3;
    perimeter3=base+height+sqrt(base*base + height*height); /* the type that we calculate the perimeter of the triangle */
    return perimeter3;
  }

  float Square(float a) /* creating the function that calculus the perimeter of square */
  {
    float perimeter4;
    perimeter4=4*a;
    return perimeter4;
  }
