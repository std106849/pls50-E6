//*************************************************************
//*** ΠΛΣ50 "Βασικές Εξειδικεύσεις σε Θεωρία και Λογισμικό" ***
//***                   Εργασία Ε02 - Θέμα 3                ***
//***                                                       ***
//***                   Ακ.έτος 2016-17                     ***
//***                                                       ***
//*************************************************************



// programma gia thn parallagi toy paixnidioy SET puzzle


#include <stdio.h>  //* needed for printf(), scanf() */
#include <stdlib.h> //* defines four variable types, several macros, and various functions for performing general functions */
#include <time.h>

char *idmembers[1][4] = {
	{ "id player", "a", "        g", "                p" },
	};
char *namemembers[1][4] = {
	{ "name player", "Marina Andreou", "Kostas Grammenos", "Maria Perdika" },
	};





char *names[4][3] = {
	{ "r", "g", "b" },
	{ "c", "t", "r" },
	{ "1", "2", "3" },
	{ "b", "h", "e" }
};

int set[81][81];

void init_sets(void)  //* function initialize the data */
{
	int i, j, t, a, b;
	for (i = 0; i < 81; i++) {
		for (j = 0; j < 81; j++) {
			for (t = 27; t; t /= 3) {
				a = (i / t) % 3;
				b = (j / t) % 3;
				set[i][j] += t * (a == b ? a : 3 - a - b);
			}
		}
	}
}

void getNextCard(int *out, int n)  //* function that gets 12 cards of the 81 randomly * /
{
	int i, j, t, c[81];
	for (i = 0; i < 81; i++) c[i] = i;
	for (i = 0; i < n; i++) {
		j = i + (rand() % (81 - i));  //* with the help of the function rand */
		t = c[i], c[i] = out[i] = c[j], c[j] = t;
	}
}

int get_sets(int *cards, int n, int sets[][3])  //* function that finds the correct sets of the 12 cards thus is 6 pair match cards */
{
	int i, j, k, s = 0;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			for (k = j + 1; k < n; k++) {
				if (set[cards[i]][cards[j]] == cards[k])
					sets[s][0] = i,
					sets[s][1] = j,
					sets[s][2] = k,
					s++;
			}
		}
	}

	return s;
}

void show_card(int c)  //* function that prints the cards in the screen in order the player can choose */
{
	int i, t;
	for (i = 0, t = 27; t; i++, t /= 3)
		printf("%s", names[i][(c/t)%3]);
	putchar('\n');
}

int getNextCard_sets(int ncard, int nset, int score)  //* function that recursively show the cards and the correct sets */
{
	int c[81], value=0, score1;
	int csets[81][3]; //* might not be enough for large ncard */
	int i, j, s, c1,c2,c3,k,l,temp1,temp2,temp3;
	char id;


	do getNextCard(c, ncard); while ((s = get_sets(c, ncard, csets)) != nset);

	printf("--------------------------------------------------------------------\n");
	printf("INITIALIZE CARDS\n", ncard);
	printf("--------------------------------------------------------------------\n");
	for (i = 0; i < ncard; i++) {
		printf("%2d:", i);
		show_card(c[i]);
	}
printf("--------------------------------------------------------------------\n");
printf("THE RESULTS OF THE RIGHT SETS FOR THE USER CONVENIENCE\n", ncard);
printf("--------------------------------------------------------------------\n");
	for (k = 0; k < s; k++) {
	 for (l = 0; l < 3; l++) {
            printf("%2d:", csets[k][l]);

			show_card(c[csets[k][l]]);
              }
		putchar('\n');}

                printf("Choose three cards to make set\n"); //* the choices that a player gives in order to make a set */
                do {
                        printf("Number of choice1 integer between[0-11]:");
                        scanf(" %d", &c1);
                    } while (c1<0 || c1>11 );

                do {
                        printf("Number of choice2 integer between[0-11]:");
                        scanf(" %d", &c2);
                    } while (c2<0 || c2>11 );
                    do {
                        printf("Number of choice3 integer between[0-11]:");
                        scanf(" %d", &c3);
                    } while (c3<0 || c3>11 );

                if (c1>c3) {    //* sorting the order of the player choices when below is given the right set */
                temp1=c1;
                c1=c3;
                c3=temp1;}
                if (c1>c2) {
                    temp2=c1;
                    c1=c2;
                    c2=temp2;}
                if (c2>c3){
                    temp3=c2;
                    c2=c3;
                    c3=temp3;}

	for (i = 0; i < s; i++) {

                if ((c1==csets[i][0]) && (c2==csets[i][1]) && (c3==csets[i][2]))

                    {
                     value=1;
                     score=score+2;
                     putchar('\n');}



	}
                   if (value==0) {
                            if (score==0) {;
                            score=0;
                            putchar('\n');}
                            else {
                            score=score-1;
                            putchar('\n');}

    printf("--------------------------------------------------------------------\n");
	printf("SAME GROUP OF CARDS\n", ncard);
	printf("--------------------------------------------------------------------\n");
                            for (i = 0; i < ncard; i++) {
                            printf("%2d:", i);
                            show_card(c[i]);
                                                        }

	}



                     if (value==1) {
                        init_sets();
                        do getNextCard(c, ncard); while ((s = get_sets(c, ncard, csets)) != nset);

	printf("--------------------------------------------------------------------\n");
	printf("INITIALIZE CARDS\n", ncard);
	printf("--------------------------------------------------------------------\n");
	for (i = 0; i < ncard; i++) {
		printf("%2d:", i);
		show_card(c[i]);
	}
printf("--------------------------------------------------------------------\n");
printf("THE RESULTS OF THE RIGHT SETS FOR THE USER CONVENIENCE\n", ncard);
printf("--------------------------------------------------------------------\n");
	for (k = 0; k < s; k++) {
	 for (l = 0; l < 3; l++) {
            printf("%2d:", csets[k][l]);

			show_card(c[csets[k][l]]);
              }
		putchar('\n');}
				}




return score;




}




int main(void)
{
    srand(time(NULL));  //*  call the function of randomize initializing data */
    putchar('\n');
    printf("--------------------------------------------------------------------\n");
    printf("THE SET GAME PUZZLE IS STARTING NOW! BELOW ARE THE AVAILABLE PLAYERS\n");
    printf("--------------------------------------------------------------------\n");


    printf("--------------------------------------------------------------------\n");
    int i, j;
	for (i = 0; i<1; i++) {
            for (j = 0; j<4; j++) {
                    printf("%s\t", idmembers[i][j]);
            }

		   }
putchar('\n');
for (i = 0; i<1; i++) {
            for (j = 0; j<4; j++) {
                    printf("%s\t", namemembers[i][j]);
            }

		   }
putchar('\n');
printf("--------------------------------------------------------------------\n");

putchar('\n');
putchar('\n');

     int choice, score, score1, score_a=0,score_g=0,score_p=0,m,n;
     char id;
     score=0, score1=0;
     while (choice != 0 && score!=10)
      {
      printf("1. Start the game or continue the game\n");
      printf("0. End of the game\n");
      putchar('\n');
      printf("Number of choice:");
      scanf(" %d", &choice);
      switch(choice) {
        case 1:
            do {
        printf("Give the correct id of the player=");
        scanf(" %c", &id);
        } while (id != 'a' && id != 'g' && id != 'p');
        printf("active player is %c",id);
        putchar('\n');

        init_sets();
        score=getNextCard_sets(12, 6, score);
        //printf("%d", score );
        putchar('\n');

        if (id=='a')
            {
            score_a=score;
            //printf("score of player a is=%d",score_a);
                putchar('\n');
            }

        else
            if (id=='g')
                {
                    score_g=score;
               // printf("score of player g is=%d",score_g);
                putchar('\n');
        }
        else
            if (id=='p')
                {
                    score_p=score;
               // printf("score of player p is=%d",score_p);
                putchar('\n');
        }

        case 0:  /* min kaneis tipote */
            printf("--------------------------------------------------------------------\n");
    int i, j;
	for (i = 0; i<1; i++) {
            for (j = 0; j<4; j++) {
                    printf("%s\t", idmembers[i][j]);
            }

		   }
putchar('\n');
for (i = 0; i<1; i++) {
            for (j = 0; j<4; j++) {
                    printf("%s\t", namemembers[i][j]);
            }

		   }
putchar('\n');
printf("--------------------------------------------------------------------\n");
		   printf("%s\t%d\t%9d\t%17d\t", "TOTAL SCORE", score_a,score_g,score_p);
		   putchar('\n');

printf("--------------------------------------------------------------------\n");
		   putchar('\n');
		   putchar('\n');

                    break;
        default:
           printf("akatallili epilogi\n");
      }

}

}

