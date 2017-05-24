//*************************************************************
//*** ΠΛΣ50 "Βασικές Εξειδικεύσεις σε Θεωρία και Λογισμικό" ***
//***                   Εργασία Ε01 - Θέμα 4                ***
//***                                                       ***
//***                   Ακ.έτος 2016-17                     ***
//***                                                       ***
//*************************************************************



// program that creates a system of holding or cancel seats of a bus

#include <stdio.h>  //* needed for printf(), scanf() */

void print_menu() //* creating menu list for the user */
{

    printf("       ---------------------------------------------------------------------------\n");
    printf("            1: Calculate number and positions of empty seats of the bus\n");
    printf("            2: Reservation of a seat on the bus\n");
    printf("            3: Searching of a window seat on the bus\n");
    printf("            4: Cancel a seat of the bus\n");
    printf("            5: Searching of a reservation seat with specific number of the bus\n");
    printf("            6: Sorting Reservation seats of the bus\n");
    printf("            7: Print the data of the bus\n");
    printf("            8: Save the data of the bus\n");
    printf("            Exit Program -> enter 0\n");
    printf("       ---------------------------------------------------------------------------\n");
    printf(             "Enter your choice: ");
}
int main()
{
FILE *fp;
char C[100][100], A[100];  //* arrays for use 1D and 2D for the purpose of the questions */
int i, k, m,choice, value;
fp = fopen("bus.txt" , "r"); /* opening file for reading */
if(fp == NULL)
{
printf("Error opening file");
return(-1);
}
if( fgets (A, 100, fp)!=NULL )
{
puts(A);  /* writing content to the file */
}
while(!feof(fp))
{
fscanf(fp,"%[^ \n\t\r]s",A); //get text
}
fp = fopen("bus.txt" , "r");
if(fp == NULL)
{
printf("Error opening file");
return(-1);
}
if (fscanf(fp, "%*s %d", &value) != 1) //* taking only the value of the bus seats from file */
{
printf("Error in the data");
}
else
{
i=value;  //* the value of the bus seats */
m=i+(i/4)-1;  //* this formula represents the exact dimension for the 2D array to represent the data in - and * on output  */
}
if ((((i-5)%4)!=0) || (i>53)) //* check if the file has the right seats number  */
{
printf("not right seats");
}
else
{
print_menu();  //* else is printing the menu to start over someone to execute */
scanf(" %d", &choice);  //* taking the choice of the user to start with */
int B[53];
int j;
for (j=1; j<i+1; j++)
{
B[j]=0;}  //* initial array to zero  */
while(choice!= 0) //* loop for the choices and exit if the choice is zero */
{
if (choice==1)
{
printf("the array is: ");
for (j=1; j<i+1; j++){
printf(" %d", B[j]);
}
printf("\n");
int count=0;  //* finding the count of the seats and the numbers of them with searching the array */
int found = 0;
for (j=1; j<i+1; j++)
{
if (B[j] == 0)
{
printf("\n empty seat position: %d", j);
count=count+1;
found=1;
}
}
if (found)  //* if the logical variable is true the results of the bus seats */
printf("\n total of empty seats on bus=  %d", count);
else
printf("\n All seats are taken in the bus");
printf("\n");
}
else if (choice==2)
{
int number;
printf(" Which number of seat you desire?");  //* put the number of the seat to someone can hold */
scanf("%d", &number);
if (number>i || number<1 || B[number]!=0) //* check if the number is in within limits */
printf("\n probably wrong input number or the seat is taken");
else
B[number]=1;
printf("\n");
}
else if (choice==3)
{
int found1 = 0;
j=1;
while ((j<i+1) && (found1==0)) //* searching the first seat by the window that is free */
{
if (((j%4== 0)||(j%4== 1))&& (j!=i-1)) //* check formula for searching only the numbers by the windows */
{
if (B[j]==0)
{
printf("\n empty window seat position: %d", j);
B[j]=1;
found1=1;
}
}
j=j+1;
}
if (found1==0)
printf("\n all window seats are taken");
printf("\n");
}
else if (choice==4)
{
int number1;
printf(" Which number of seat you want to cancel? "); //* cancel a seat bus that already been taken or not */
scanf("%d", &number1);
if (number1>i || number1<1 || B[number1]!=1) //* check the limits of the input number */
printf("\n probably wrong input number or the seat is not taken");
else
B[number1]=0;
printf("\n");
}
else if (choice==5)
{
int number2;
printf(" Which number of seat you want to search if is taken? ");
scanf("%d", &number2);
if (number2<=i && number2>=1) //* check if a specific number of a seat is taken */
{
if (B[number2]==1)
{
printf("\n this seat is taken");
printf("\n");
}
else
{
printf("\n this seat is not taken");
printf("\n");
}
}
else
{
printf("\n wrong input number");
printf("\n");
}
}
else if (choice==6)
{
int count=0;
int found = 0;
for (j=1; j<i+1; j++) //* creating the 1D array to store the elements of the seats taken only and output in the screen sorting  */
{
if (B[j] == 1)
{
count=count+1;
printf("\n the %d", count);
printf(" taken seat position: %d", j);
found=1;
}
}
if (found==0)
{
printf("\n all seats on bus are empty");
}
printf("\n");
}
else if (choice==7)
{
char C[m/5][5]; //* converting the 1D array to 2D array for output in the screen */
fp = fopen("bus.txt" , "r"); /* opening file for reading */
if(fp == NULL)
{
printf("Error opening file");
return(-1);
}
if( fgets (A, 9, fp)!=NULL )
{
puts(A);  /* writing content to the file */
}
while(!feof(fp))
{
fscanf(fp,"%[^ \n\t\r]s",A); //get text only for the number of the bus
}
fp = fopen("bus.txt" , "r");
if(fp == NULL)
{
printf("Error opening file");
return(-1);
}
if (fscanf(fp, "%*s %d", &value) != 1)
{
printf("Error in the data");
}
for (j=1; j<=(m/5); j++)
for (k=1; k<=5; k++){
if (B[j+k-1] == 0) //* limits for the 2D array to convert the numbers 1 and 0 to * and - */
{
C[j][k]= '-';}
else
{
C[j][k]='*';
}
}
for (j=1; j<=(m/5); j++){
for (k=1; k<=5; k++){
printf("%c", C[j][k]);  //* print results to the screen */
}printf("\n");
}
}
else if (choice==8)
{
FILE *fp;  //* from the previous choice take the results in order to store them to the file named layout.txt */
FILE *fp1;
char C[m/5][5];
for (j=1; j<=(m/5); j++)
for (k=1; k<=5; k++){
if (B[j+k-1] == 0)
{
C[j][k]= '-';}
else
{
C[j][k]='*';
}
}
fp = fopen("bus.txt" , "r");
fgets(A,100,fp);
fclose(fp);
fp1=fopen("layout.txt","w");
fputs(A,fp1);
fprintf(fp1, "\n");
for (i=1; i<=(m/5); i++){
for (j=1; j<=5; j++) {
fprintf(fp1, "%c",C[i][j]);
}
fprintf(fp, "\n");
}
fclose(fp1);
printf("The data are stored in layout.txt\n"); //* store the data */
}
else
{
printf("Error in choice - Try Again please\n");
}
print_menu();
scanf(" %d", &choice);
}
}
return(0);
}
