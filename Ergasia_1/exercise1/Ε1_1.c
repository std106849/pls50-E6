//*************************************************************
//*** ΠΛΣ50 "Βασικές Εξειδικεύσεις σε Θεωρία και Λογισμικό" ***
//***                   Εργασία Ε01 - Θέμα 1                ***
//***                                                       ***
//***                   Ακ.έτος 2016-17                     ***
//***                                                       ***
//*************************************************************



// program that performs addition, subtraction, multiplication or division depending the input from user

# include <stdio.h> //* needed for printf(), scanf() */
# include <conio.h> //* needed for getch() *//
int main() {

    char operator;    /* Variables for operator input */
    double firstNumber,secondNumber;  /* Variables for input numbers */

    printf("Enter an operator (+, -, *,) and two operands as follows:\n");
    printf("operand operator operand:\n");
    scanf("%lf %c %lf",&firstNumber, &operator, &secondNumber);    /* reading the operator and the numbers */

   switch(operator)  /* switch statement depending the input operator that user gives */
    {
        case '+':
            printf("result: %.2lf + %.2lf = %.2lf",firstNumber, secondNumber, firstNumber + secondNumber);
            break;    /* adding the numbers */

        case '-':
            printf("result: %.2lf - %.2lf = %.2lf",firstNumber, secondNumber, firstNumber - secondNumber);
            break;  /* subtract the numbers */


        case '*':
            printf("result: %.2lf * %.2lf = %.2lf",firstNumber, secondNumber, firstNumber * secondNumber);
            break;  /* multiply  the numbers */


        case '/':
             if(secondNumber==0) // division the numbers with the if statement in case of the second number is zero
        printf("division by zero is not allowed");
                else
            printf("result: %.2lf / %.2lf = %.2lf",firstNumber, secondNumber, firstNumber / secondNumber);
            break;

        // operator doesn't match any case constant (+, -, *, /)
        default:
            printf("Error! operator is not correct");
    }
    getch();
    return 0;
}
