//*************************************************************
//*** ΠΛΣ50 "Βασικές Εξειδικεύσεις σε Θεωρία και Λογισμικό" ***
//***                   Εργασία Ε01 - Θέμα 3                ***
//***                                                       ***
//***                   Ακ.έτος 2016-17                     ***
//***                                                       ***
//*************************************************************


/*
 * C Program to Print Binary Equivalent of a positive integer
 */
#include <stdio.h>  /* needed for printf(), scanf() */


  int main()
  {
    int n;
    const int p=2; /* the number 2 which helps in finding the binary number is given in format of const */
    printf("Enter a number : ");
    scanf(" %d", &n);
    while (n<=0)  /* loop until positive number is given */
    {
      printf("Negative or Zero, enter a positive number : "); /* message for not giving positive number */
      {scanf(" %d", &n);};
      }
printf("the binary format of the number is:");

while(n!=0){ /* loop until initial number is 0 */
        ((n%p)==1)? putchar('1'):putchar('0'); /* creating the if statement with conditional expression instead */
        n=n/p;  /* if the mod is 1 put 1, else 0 and find the div from remaining number  */
            }
            printf("\n");
        return 0;
  }


