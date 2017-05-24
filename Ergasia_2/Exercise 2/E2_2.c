//***********************************************************************
// *** ΠΛΣ50 "Βασικές Εξειδικεύσεις σε Θεωρία και Λογισμικό" ********************
//***                             Εργασία Ε02 - Θέμα 2                                      *****************
//***                                                                                                          *****************
//***                                    Ακ.έτος 2016-17                                         *****************
//***                                                                                                          *****************
//***********************************************************************

// programma gia tin epektasi tou sistimatos  katagrafis kratimenon theseon

#include <stdio.h>  //* needed for printf(), scanf() */
#include <string.h>  //* defines one variable type, one macro, and various functions for manipulating arrays of characters */
#include <stdlib.h>  //* defines four variable types, several macros, and various functions for performing general functions */

int i,j,nseats,pros;
char pinakida[8],choice;
char fname[20],lname[20];
char telephone[11];
char *p;

typedef struct   //*the typedef means no longer have to write struct all over the place */
    {
    char name[40];  //* variables of the data type of the structure */
    unsigned char number[10];
    unsigned int number_seat;
    }bus_system, temp1;

void readfile(bus_system bus[])  //* function that read the data from the file
{   char b[60];
    FILE *details;
    details = fopen ("bus.txt","r");  /* opening file for reading */
    if (details == NULL)
        {
        printf("Error opening file");
        exit(1);}
    else
        {
        fscanf(details,"%s %d",pinakida, &nseats);   //* taking the value of the bus seats from file and the number of pinakida */
        printf("---------------------------------------------------------------------------\n");
        printf("     Arithmos Pinakidas Leoforeiou: %s\n     Arithmos Theseon Leoforeiou: %d\n", pinakida, nseats);
        printf("---------------------------------------------------------------------------\n");
        for (j=0;j<nseats;j++)
            {bus[j].number_seat=j+1;
            strcpy(bus[j].name,"\0");
            }
        while (fgets(b,sizeof(b),details)!=0)
            {sscanf(b, "%s %s %d %s", fname, lname, &pros,telephone); //* reads formatted input from a string */
            strcpy(bus[pros-1].name,fname);  //* The strcpy() function copies the string pointed by source (including the null character) to the character array destination */
            strcat (bus[pros-1].name, " ");
            strcat(bus[pros-1].name,lname); //* appends the string pointed to */
            i=0;
            for (p=telephone;*p!='\0';p++)
                {
                (bus[pros-1].number[i])=*p -'0';
                i++;
                }
            }
           }
}
void fseats(bus_system bus[]){  //* function for the use of printing the free seats on the bus */
    int freeseats = 0;
        for (j=0; j<nseats; j++)
            {
            strcmp(bus[j].name,"\0")==0 ? freeseats = freeseats + 1 : freeseats ;}
            printf("\n");
            printf ("To leoforeio exei %d eleutheres theseis oi opoies einai:\n", freeseats);
            printf("\n");
        for (j=0; j<nseats; j++)
            {if (strcmp(bus[j].name,"\0")==0)
                printf ("%u\t", bus[j].number_seat);
            }
        freeseats = 0;
        }
void controldata(bus_system *link){    //* function to hold the data of a new passenger in the bus */
    printf("Eisagete to onoma toy epivati:");
    scanf("%s",fname);
    printf("Eisagete to eponymo toy epivati:");
    scanf("%s",lname);
    strcpy(link->name, lname);
    strcat (link->name, " ");
    strcat(link->name,fname);
    printf("Eisagete to tilephono toy epivati:");
    scanf("%s",telephone);
    i=0;
    for (p=telephone;*p!='\0';p++)
        {
        (link->number[i])=*p -'0';
        i++;
        }
    }
void searching(bus_system bus[], char choice) //* function for searching the if a passenger has booked or not a seat of the bus */
{       char s,tf[20],tl[20];
        unsigned char pt[10];
     if (choice == '1')
        {   printf("Eisagete to eponymo toy epivati:");
            scanf("%s",tf);
            printf("Eisagete to onoma toy epivati:");
            scanf("%s",tl);
            strcat (tf, " ");
            strcat(tf,tl);
            for (j=0;j<nseats;j++)
            if (strcmp(bus[j].name,tf)==0)
                printf ("O Epivatis me onoma %s exei tin thesi: %u\n",tf,bus[j].number_seat);
        }
        else if (choice == '2')
        {   printf("Eisagete to tilephono toy epivati:");
            scanf("%s",telephone);
            i=0;
            for (p=telephone;*p!='\0';p++)
            {
            (pt[i])=*p -'0';
            i++;
            }
            for (j=0;j<nseats;j++)
            {if (strcmp(pt, bus[j].number)==0)
                printf("O epivatis %s exei tin thesi:",bus[j].name,bus[j].number_seat);
            }
        }
        }
void cancel(bus_system *link){ //* function for canceling a seat by number */
    strcpy(link->name,"\0");
    for (i=0;i<10;i++)
    link->number[i]=0;
    printf("H thesi %d einai eleytheri",pros);

    }
void show(bus_system bus[], char choice)  //* function for showing a list of the booked seats by the data of the passenger */
{       char s,tf[20],tl[20];
        bus_system temp1;
        unsigned char pt[10];
     if (choice == '1')
        {
            for (j=0;j<nseats-1;j++){
                for (i=0;i<nseats-j-1;i++){
            if (strcmp(bus[i].name,bus[i+1].name)>0)
                {
                temp1=bus[i];
                bus[i] = bus[i + 1];
                bus[i+1]=temp1;

        }
                }
            }
            printf("\n");
            printf("TAKSINOMISI KATA EPONIMO\n");
        for (i=0; i<nseats; i++)
            if (strcmp(bus[i].name,"\0")!=0)
            {
                printf("%s, ",bus[i].name);
                for (j=0;j<10;j++)
                {printf("%hu",bus[i].number[j]);}

                printf(", %u\n",bus[i].number_seat);
            }
 }


        else if (choice == '2')
            {

 printf("\n");
 printf("TAKSINOMISI KATA THESI\n");
        for (i=0; i<nseats; i++)
            if (strcmp(bus[i].name,"\0")!=0)
            {
                printf("%s, ",bus[i].name);
                for (j=0;j<10;j++)
                {printf("%hu",bus[i].number[j]);}

                printf(", %u\n",bus[i].number_seat);
            }
 }

        }

void outputfile(bus_system bus[])  //* function for saving the data in a file called output.txt
   {
    FILE * output;
    output = fopen("output.txt","w");
    fprintf(output,"%s %d \n",pinakida,nseats);
    for (i=0; i<nseats; i++)
        {if (strcmp(bus[i].name,"\0")!=0)  //* compares the string pointed to */
        {
            fprintf(output,"%s ",bus[i].name);
            fprintf(output,"%u ",bus[i].number_seat);
            for (j=0;j<10;j++)
            fprintf(output,"%hu",bus[i].number[j]);
            fprintf(output,"%s","\n");
        }
        }
        fclose(output);
        printf("\n");
        printf("---------------------------------------------------------------------------\n");
        printf("Ta dedomena apothikeutikan se arxeio me onoma output.txt\n");
        printf("---------------------------------------------------------------------------\n");
   }

int main(void) //* main program that calls the above function after a menu appears on the screen for that purpose */
{
bus_system bus[53];
readfile(bus);

    do{                                                                                         //* loop for the choices and exit if the choice is zero */
    printf("\n");
    printf("\n");
    printf("--------------MENOY EPILOGON-----------------------------------------------\n");
    printf("---------------------------------------------------------------------------\n");
    printf("         1. Sunoliko Plithos Eleutheros Theseon\n");
    printf("         2. Kratisi Thesis me Sigkekrimeno arithmo vasei stoixeion epivati\n");
    printf("         3. Anazitisi Kratimenis Thesis (onomateponimo i tilephono)\n");
    printf("         4. Akiroso Kratisis Thesis me sigkekrimeno arithmo\n");
    printf("         5. Emfanisi Listas Kratimenon Theseon (onomateponimo i thesi)\n");
    printf("            Exit Program -> enter 0\n");
    printf("---------------------------------------------------------------------------\n");
    printf(             "Eisagete Epilogi: ");
    scanf(" %c",&choice);

    if (choice=='1')  //* list of choices for the user in order to have the appropriate results */
  fseats(bus);
    else if (choice=='2')
        {
        printf("Eisagete epilogi arithmoy thesis (Apodekta Oria [1 - %d] gia kratisi:", nseats);
        scanf("%d",&pros);
        if (pros >nseats || pros <= 0)  //* check if the file has the right seats number  */
            {printf("Ek neou eisagete arithmo thesis Apodekta Oria [1- %d]", nseats);
            }
         else if (strcmp(bus[pros-1].name,"\0")!=0)
            printf("I thesi einai idi kratimenei");
        else
        controldata(&bus[pros-1]);
        }
 else if (choice=='3')
        {
        char s;
        printf("Eisagete (1) gia anazitisi me onoma  - (2) gia anazitisi me tilephono:");
        scanf(" %c",&s);
        searching(bus,s);
        }
    else if (choice=='4')
        {
        printf("Eisagete thesi Apodekta Oria [1-%d] poy epithimeite na akirosete:", nseats);
        scanf("%d",&pros);
        if (pros >nseats || pros <= 0)
            {printf("Ek neou eisagete arithmo thesis Apodekta Oria [1- %d]:", nseats);}
         else if (strcmp(bus[pros-1].name,"\0")==0)
            printf("I thesi einai eleutheri");
        else
        cancel(&bus[pros-1]);
        }
    else if (choice=='5')
        {
        char l;
        printf("Eisagete (1) gia taksinomisi kata onomateponimo - (2) gia taksinomisi me thesi:");
        scanf(" %c",&l);

            show(bus,l);
        }

    } while (choice!='0');
    {
    outputfile(bus);
    }
    }
