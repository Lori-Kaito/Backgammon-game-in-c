/*
Description: This program runs a backgammon game that is played by 2 players.
Programmed by: Raico Luis C. Madrinan S16 & Rahmon Khayle U. Del Mundo S12
Last modified: Dec 11
To run: gcc madrinan_delmundoMP.c -o backgammon.exe
then run .\backgammon.exe
*/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void red () { // for text colors
  printf("\033[1;31m");
}
void blue () {
  printf("\033[0;34m");
}
void green () {
  printf("\033[0;32m");
}
void yellow () {
  printf("\033[1;33m");
}
void purple () {
  printf("\033[0;35m");
}
void cyan () {
  printf("\033[0;36m");
}
void reset () { // for resetting the text color to default
  printf("\033[0m");
}
int RollDice(int *nDice1, int *nDice2, int *nDice3, int *nDice4, char cChoice, int *nDiceTotal) //function for getting the random values of dice and returning the total moves
{
	*nDice1=((rand()%6) +1);
	*nDice2=((rand()%6) +1);
	*nDice3=*nDice1;
	*nDice4=*nDice1;
	printf("first die: %d\n", *nDice1);
	printf("second die: %d\n", *nDice2);
  if(nDice1==nDice2) //if player rolled the same value of dice
    *nDiceTotal=*nDice1*4;
  else if (nDice1!=nDice2)
    *nDiceTotal=*nDice1+*nDice2;
	cChoice = ' ';
}
int DiceUseConditional( int *nDice1, int *nDice2, int *nDice3, int *nDice4, char cChoice, int *nDiceTotal) //for emptying the value of the Die used
{
    	if (cChoice == 'A')
    		*nDice1= 0;
		else if (cChoice == 'B')
    		*nDice2= 0;
		else if (cChoice == 'C')
    		*nDice3= 0;
		else if (cChoice == 'D')
    		*nDice4= 0;
		else if (cChoice == 'Z')
		{
			*nDice1= 0;
			*nDice2= 0;
			*nDice3= 0;
			*nDice4= 0;
		}	
		*nDiceTotal=*nDice1+*nDice2+*nDice3+*nDice4;
}
int ComputeMovementBlack(int toPiece, int *fromPiece, int *nDice1, int *nDice2, int *nDice3, int *nDice4, char *cChoice, int *nDiceTotal)
{
	    if (*cChoice == 'A')						//if-statements for player choices on how many spaces to move
    		toPiece=*fromPiece-*nDice1;         //deduction because Black player is in decrement
		else if (*cChoice == 'B')
			toPiece=*fromPiece-*nDice2;
		else if (*cChoice == 'C')
			toPiece=*fromPiece-*nDice3;
		else if (*cChoice == 'D')
			toPiece=*fromPiece-*nDice4;
		else if (*cChoice == 'Z')
			toPiece=*fromPiece-*nDiceTotal;
}
int ComputeMovementWhite(int *toPiece, int *fromPiece, int *nDice1, int *nDice2, int *nDice3, int *nDice4, char *cChoice, int *nDiceTotal)
{
	    if (*cChoice == 'A')						//if-statements for player choices on how many spaces to move
    		*toPiece=*fromPiece+*nDice1;         //addition because White player is in increment
		else if (*cChoice == 'B')
			*toPiece=*fromPiece+*nDice2;
		else if (*cChoice == 'C')
			*toPiece=*fromPiece+*nDice3;
		else if (*cChoice == 'D')
			*toPiece=*fromPiece+*nDice4;
		else if (*cChoice == 'Z')
			*toPiece=*fromPiece+*nDiceTotal;
}
void clear() // for clearing the screen every instance
{
    system("@cls||clear");
}

int main(void)
{
printf("\n--------------------------------------------------------------------------\n");
printf("		\n\n\t\t\tWelcome to Backgammon Board Game		\n");
printf("		\n\n\t\t\t\t Created by:		\n");
printf("		\n\n\t\t\tRahmon Khayle U. Del Mundo & Raico Luis C. Madrinan	\n");
printf("\n----------------------------------------------------------------------------\n");
char namewhite[15];
char nameblack[15];

int nDice1=0,nDice2=0, nDice3=0, nDice4=0, nDiceTotal;
char Player1;
int moves, fromPiece=0, toPiece=0;
char cChoice;
char BlackGoSign, WhiteGoSign;
char GoVar='N'; //go variable
  
  srand(time(NULL)); //function for randomizing dice value every instance
  
int Black[26] = {0, 0, 0, 0, 0, 0, 5, 0, 3, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0};
    // 24 boards, 1 for the middle when eaten, 1 for points
int White[26] = {0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 3, 0, 5, 0, 0, 0, 0, 0, 0};
  // 24 boards, 1 for the middle when eaten, 1 for points
  //  Black ----- 0 0 0 0 0 0 5 0 3 0 0 0 0 5 0 0 0 0 0 0 0 0 0 0 2 0 decrement
  //  White ----- 0 2 0 0 0 0 0 0 0 0 0 0 5 0 0 0 0 3 0 5 0 0 0 0 0 0 increment
  //   Black[25] = the bar    Black[0] = points
  //   White[0]  = the bar    White[25]= points
int BlackBearingOff= Black[1] + Black[2] + Black[3] + Black[4] + Black[5] + Black[6];
int WhiteBearingOff= White[19] + White[20] + White[21] + White[22] + White[23] + White[24];

  nDiceTotal=nDice1+nDice2;

  printf("Enter your nickname white player: "); //Ask white player to enter nickname
  fgets(namewhite,15,stdin);
  printf("\n");
  printf("Enter your nickname black player: "); //Ask black player to enter nickname
  fgets(nameblack,15,stdin);
  printf("\n");
  printf("White player name: %s", namewhite);
  printf("Black player name: %s", nameblack);
  

  while (nDice1 == nDice2) //rolling of dice to know who will go first
    {
      while(cChoice != 'R')
        {
        printf("\nEnter R to Roll a Dice\n");
        scanf("%c", &cChoice);
        }
  	nDice1=((rand()%6) +1);
  	nDice2=((rand()%6) +1); // CUSTOMIZED MUNA
  	printf("first die: %d\n", nDice1);
  	printf("second die: %d\n", nDice2);
      if(nDice1 == nDice2)
      {
      printf ("Roll again.\n");
      cChoice=' ';
      }
    }
    if (nDice1 > nDice2) 
    {
      printf ("\tWhite Player will be Player 1.\n\tBlack Player will be Player 2.\n\n");
      printf("\t\tPlayer 1: %s\n", namewhite);
      printf("\t\tPlayer 2: %s\n", nameblack);
      Player1='W';
    }
    else if (nDice1 < nDice2)
    {
      printf ("\tBlack Player will be Player 1.\n\tWhite Player will be Player 2.\n\n");
      printf("\t\tPlayer 1: %s\n", nameblack);
      printf("\t\tPlayer 2: %s\n", namewhite);
      Player1='B';
    }
	printf("Press any key to continue...\n");
    (getche());
    clear();


      //for (int x = 0; x < 26; x++) to print the board for black
            //printf("%d ", Black[x]);//
      //for (int y = 0; y < 26; y++) to print the board for white
            //printf("%d ", White[y]);//
            
while (Black[0] != 15 && White[25] != 15)
{
  	if (Player1 == 'B')
 	{
    //PLAYER BLACK
    printf("Player Black rolls... \n");
    RollDice(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
    moves=nDiceTotal;
    printf("Press any key to continue...\n");
    (getche());
    while(cChoice != 'S' && moves != 0) // FOR BLACK
    	{
    	clear();
    	printf("\t\t[BLACK'S TURN]");
    	printf("You've rolled %d and %d \n", nDice1, nDice2);
    	printf("What checkers do you want to move? \n");
	    for (int x = 0; x < 26; x++) //loop for printing the board containing Black's Checkers
    		printf("%d ", Black[x]);
    	printf(" [BLACK'S CHECKERS]\n");
    	for (int y = 0; y < 26; y++) //loop for printing the board containing White's Checkers
            printf("%d ", White[y]);
        printf(" [WHITE'S CHECKERS]");
        fromPiece=0;
        while (Black[fromPiece]<1)
        	{
    		printf("\n\nFrom: ");
    		scanf("%d", &fromPiece);
        	if (Black[fromPiece]<1)
        	printf("No black checkers on this slot, try again.");
    		}
    	cChoice=' ';
    	while (GoVar!='Y' && cChoice!= 'X')
	    	{
	      	printf("\nHow many spaces? [To the left] \n");
	      	if (nDice1 != nDice2) // IF DICE ARE NOT THE SAME
	      		{
	      		nDice3=0, nDice4=0;
	      		printf("A: [%d] B: [%d] Z: [%d]\n", nDice1, nDice2, nDiceTotal);
	      		scanf("%c\n", &cChoice);
	      		}
	      	else if (nDice1 == nDice2) // IF DICE ARE SAME
	      		{
	      		nDiceTotal=nDice1+nDice2+nDice3+nDice4;
		      	printf("A: [%d] B: [%d] C: [%d] D: [%d] Z:[%d]\n", nDice1, nDice2, nDice3, nDice4, nDiceTotal);
		      	scanf("%c\n", &cChoice);
	        	}
	    	if (cChoice == 'A')						//if-statements for player choices on how many spaces to move
    			toPiece=fromPiece-nDice1;         //deduction because Black player is in decrement
			if (cChoice == 'B')
				toPiece=fromPiece-nDice2;
			if (cChoice == 'C')
				toPiece=fromPiece-nDice3;
			if (cChoice == 'D')
				toPiece=fromPiece-nDice4;
			if (cChoice == 'Z')
				toPiece=fromPiece-nDiceTotal;
			moves=nDiceTotal;
		    if (toPiece<0) //if the space is not exactly 1 space away from the border
	        	printf("Invalid tile count [may not exceed 2 or more tiles from the border], repeat. \n");
	      	else if (toPiece>0)//if it's anywhere on the board other than the "point tile" and the "bar"
		      	{
		    	if(White[toPiece]!=0) // if the checker to be added on a tile board is occupied (BLACK START)
		        	{
		        	if (Black[fromPiece]>=White[toPiece] && White[toPiece]==1) // if 1 checker only on the slot (FOR BLACK)
		            	{
		            	White[0]+=White[toPiece]; //changing the value of the bar
		            	White[toPiece]==0; //replacing the value of the occupied tile into no white pieces
		            	Black[toPiece]++; //occupying the tile with new pieces
		            	Black[fromPiece]--;
		            	nDice1=DiceUseConditional(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
		            	nDice2=DiceUseConditional(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
		            	nDice3=DiceUseConditional(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
		            	nDice4=DiceUseConditional(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
		            	nDiceTotal=DiceUseConditional(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
		            	printf("New tile value of Tile %d = %d", toPiece, Black[toPiece]);
		            	toPiece=0;
		            	}
		            else if (White[toPiece]>1) // if more than 1 circle on the slot
		            	{
		            	printf("There are more than 1 of the Player White's checkers on this tile");
		            	}
		        	}
		        else
				  	{
		            Black[toPiece]++;
		            Black[fromPiece]--;
		            DiceUseConditional(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
		            printf("New tile value of Tile %d = %d\n\n", toPiece, Black[toPiece]);
		            cChoice='X';
		            toPiece=0;
		        	}
		      	}
		else if (BlackBearingOff!=15 && toPiece == 0)
		    printf("You can't start earning points if you haven't put all your checkers on the home board!\n");
		    if (BlackBearingOff==15 || BlackGoSign=='Y') //Condition if the player is in state of bearing off
		    	{
		    	BlackGoSign='Y';
		        if (toPiece==0) //Black's array assignment for points
		      		{
			        printf("Black earned a point! \n");
			        Black[toPiece]++; //Black earning a point
			        Black[fromPiece]--;
					DiceUseConditional(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
					cChoice='X';
					toPiece=0;
		     		}
	     		}
	    	}
	GoVar=' ';
	moves=nDiceTotal; //for recording the total moves left from nDiceTotal
    printf("Do you still want to use your moves? %d moves remaining. \n", moves);
    printf("Enter Q to continue, [S] to skip. \n");
    scanf("%c", &cChoice);
	}
    printf("Press any key to continue...\n");
    (getche());
	clear();
	moves=0;
    //PLAYER WHITE
    printf("Player White rolls... \n");
    RollDice(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
    moves=nDiceTotal;
    printf("Press any key to continue...\n");
    (getche());
    while(cChoice != 'S' && moves != 0) // FOR WHITE
    	{
    	clear();
    	printf("\t\t[WHITE'S TURN]");
    	printf("You've rolled %d and %d \n", nDice1, nDice2);
    	printf("What checkers do you want to move? \n");
	    for (int x = 0; x < 26; x++) //loop for printing the board containing Black's Checkers
    		printf("%d ", Black[x]);
    	printf(" [BLACK'S CHECKERS]\n");
    	for (int y = 0; y < 26; y++) //loop for printing the board containing White's Checkers
            printf("%d ", White[y]);
        printf(" [WHITE'S CHECKERS]");
        fromPiece=0;
        while (White[fromPiece]<1)
        	{
    		printf("\n\nFrom: ");
    		scanf("%d", &fromPiece);
        	if (White[fromPiece]<1)
        	printf("No white checkers on this slot, try again.");
    		}
    	cChoice=' ';
    	while (GoVar!='Y' && cChoice!= 'X')
	    	{
	      	printf("\nHow many spaces? [To the left] \n");
	      	if (nDice1 != nDice2) // IF DICE ARE NOT THE SAME
	      		{
	      		nDice3=0, nDice4=0;
	      		printf("A: [%d] B: [%d] Z: [%d]\n", nDice1, nDice2, nDiceTotal);
	      		scanf("%c\n", &cChoice);
	      		}
	      	else if (nDice1 == nDice2) // IF DICE ARE SAME
	      		{
	      		nDiceTotal=nDice1+nDice2+nDice3+nDice4;
		      	printf("A: [%d] B: [%d] C: [%d] D: [%d] Z:[%d]\n", nDice1, nDice2, nDice3, nDice4, nDiceTotal);
		      	scanf("%c\n", &cChoice);
	        	}
	    	if (cChoice == 'A')						//if-statements for player choices on how many spaces to move
    			toPiece=fromPiece+nDice1;         //addition because White player is in increment
			if (cChoice == 'B')
				toPiece=fromPiece+nDice2;
			if (cChoice == 'C')
				toPiece=fromPiece+nDice3;
			if (cChoice == 'D')
				toPiece=fromPiece+nDice4;
			if (cChoice == 'Z')
				toPiece=fromPiece+nDiceTotal;
			moves=nDiceTotal;
		    if (toPiece<0) //if the space is not exactly 1 space away from the border
	        	printf("Invalid tile count [may not exceed 2 or more tiles from the border], repeat. \n");
	      	else if (toPiece>0)//if it's anywhere on the board other than the "point tile" and the "bar"
		      	{
		    	if(Black[toPiece]!=0) // if the checker to be added on a tile board is occupied (WHITE START)
		        	{
		        	if (White[fromPiece]>=Black[toPiece] && Black[toPiece]==1) // if 1 checker only on the slot (FOR WHITE)
		            	{
		            	Black[0]+=Black[toPiece]; //changing the value of the bar
		            	Black[toPiece]==0; //replacing the value of the occupied tile into no black pieces
		            	White[toPiece]++; //occupying the tile with new pieces
		            	White[fromPiece]--;
		            	nDice1=DiceUseConditional(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
		            	nDice2=DiceUseConditional(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
		            	nDice3=DiceUseConditional(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
		            	nDice4=DiceUseConditional(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
		            	nDiceTotal=DiceUseConditional(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
		            	printf("New tile value of Tile %d = %d", toPiece, White[toPiece]);
		            	toPiece=0;
		            	}
		            else if (Black[toPiece]>1) // if more than 1 circle on the slot
		            	{
		            	printf("There are more than 1 of the Player Black's checkers on this tile");
		            	}
		        	}
		        else
				  	{
		            White[toPiece]++;
		            White[fromPiece]--;
		            DiceUseConditional(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
		            printf("New tile value of Tile %d = %d\n\n", toPiece, White[toPiece]);
		            cChoice='X';
		            toPiece=0;
		        	}
		      	}
		else if (WhiteBearingOff!=15 && toPiece == 0)
		    printf("You can't start earning points if you haven't put all your checkers on the home board!\n");
		    if (WhiteBearingOff==15 || WhiteGoSign=='Y') //Condition if the player is in state of bearing off
		    	{
		    	WhiteGoSign='Y';
		        if (toPiece==25) //White's array assignment for points
		      		{
			        printf("White earned a point! \n");
			        White[toPiece]++; //White earning a point
			        White[fromPiece]--;
					DiceUseConditional(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
					cChoice='X';
					toPiece=0;
		     		}
	     		}
	    	}
	GoVar=' ';
	moves=nDiceTotal; //for recording the total moves left from nDiceTotal
    printf("Do you still want to use your moves? %d moves remaining. \n", moves);
    printf("Enter Q to continue, [S] to skip. \n");
    scanf("%c", &cChoice);
	}
    printf("Press any key to continue...\n");
    (getche());
	clear();
	moves=0;
    }
 //until here is the instance where Black is the Player 1 and White is the Player 2
//////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (Player1 == 'W')
  {
    //PLAYER WHITE
    printf("Player White rolls... \n");
    RollDice(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
    moves=nDiceTotal;
    printf("Press any key to continue...\n");
    (getche());
    while(cChoice != 'S' && moves != 0) // FOR WHITE
    	{
    	clear();
    	printf("\t\t[WHITE'S TURN]");
    	printf("You've rolled %d and %d \n", nDice1, nDice2);
    	printf("What checkers do you want to move? \n");
	    for (int x = 0; x < 26; x++) //loop for printing the board containing Black's Checkers
    		printf("%d ", Black[x]);
    	printf(" [BLACK'S CHECKERS]\n");
    	for (int y = 0; y < 26; y++) //loop for printing the board containing White's Checkers
            printf("%d ", White[y]);
        printf(" [WHITE'S CHECKERS]");
        fromPiece=0;
        while (White[fromPiece]<1)
        	{
    		printf("\n\nFrom: ");
    		scanf("%d", &fromPiece);
        	if (White[fromPiece]<1)
        	printf("No white checkers on this slot, try again.");
    		}
    	cChoice=' ';
    	while (GoVar!='Y' && cChoice!= 'X')
	    	{
	      	printf("\nHow many spaces? [To the left] \n");
	      	if (nDice1 != nDice2) // IF DICE ARE NOT THE SAME
	      		{
	      		nDice3=0, nDice4=0;
	      		printf("A: [%d] B: [%d] Z: [%d]\n", nDice1, nDice2, nDiceTotal);
	      		scanf("%c\n", &cChoice);
	      		}
	      	else if (nDice1 == nDice2) // IF DICE ARE SAME
	      		{
	      		nDiceTotal=nDice1+nDice2+nDice3+nDice4;
		      	printf("A: [%d] B: [%d] C: [%d] D: [%d] Z:[%d]\n", nDice1, nDice2, nDice3, nDice4, nDiceTotal);
		      	scanf("%c\n", &cChoice);
	        	}
	    	if (cChoice == 'A')						//if-statements for player choices on how many spaces to move
    			toPiece=fromPiece+nDice1;         //addition because White player is in increment
			if (cChoice == 'B')
				toPiece=fromPiece+nDice2;
			if (cChoice == 'C')
				toPiece=fromPiece+nDice3;
			if (cChoice == 'D')
				toPiece=fromPiece+nDice4;
			if (cChoice == 'Z')
				toPiece=fromPiece+nDiceTotal;
			moves=nDiceTotal;
		    if (toPiece<0) //if the space is not exactly 1 space away from the border
	        	printf("Invalid tile count [may not exceed 2 or more tiles from the border], repeat. \n");
	      	else if (toPiece>0)//if it's anywhere on the board other than the "point tile" and the "bar"
		      	{
		    	if(Black[toPiece]!=0) // if the checker to be added on a tile board is occupied (WHITE START)
		        	{
		        	if (White[fromPiece]>=Black[toPiece] && Black[toPiece]==1) // if 1 checker only on the slot (FOR WHITE)
		            	{
		            	Black[0]+=Black[toPiece]; //changing the value of the bar
		            	Black[toPiece]==0; //replacing the value of the occupied tile into no black pieces
		            	White[toPiece]++; //occupying the tile with new pieces
		            	White[fromPiece]--;
		            	nDice1=DiceUseConditional(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
		            	nDice2=DiceUseConditional(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
		            	nDice3=DiceUseConditional(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
		            	nDice4=DiceUseConditional(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
		            	nDiceTotal=DiceUseConditional(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
		            	printf("New tile value of Tile %d = %d", toPiece, White[toPiece]);
		            	toPiece=0;
		            	}
		            else if (Black[toPiece]>1) // if more than 1 circle on the slot
		            	{
		            	printf("There are more than 1 of the Player Black's checkers on this tile");
		            	}
		        	}
		        else
				  	{
		            White[toPiece]++;
		            White[fromPiece]--;
		            DiceUseConditional(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
		            printf("New tile value of Tile %d = %d\n\n", toPiece, White[toPiece]);
		            cChoice='X';
		            toPiece=0;
		        	}
		      	}
		else if (WhiteBearingOff!=15 && toPiece == 0)
		    printf("You can't start earning points if you haven't put all your checkers on the home board!\n");
		    if (WhiteBearingOff==15 || WhiteGoSign=='Y') //Condition if the player is in state of bearing off
		    	{
		    	WhiteGoSign='Y';
		        if (toPiece==25) //White's array assignment for points
		      		{
			        printf("White earned a point! \n");
			        White[toPiece]++; //White earning a point
			        White[fromPiece]--;
					DiceUseConditional(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
					cChoice='X';
					toPiece=0;
		     		}
	     		}
	    	}
	GoVar=' ';
	moves=nDiceTotal; //for recording the total moves left from nDiceTotal
    printf("Do you still want to use your moves? %d moves remaining. \n", moves);
    printf("Enter Q to continue, [S] to skip. \n");
    scanf("%c", &cChoice);
	}
    printf("Press any key to continue...\n");
    (getche());
	clear();
	moves=0;
    //PLAYER BLACK
    printf("Player Black rolls... \n");
    RollDice(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
    moves=nDiceTotal;
    printf("Press any key to continue...\n");
    (getche());
    while(cChoice != 'S' && moves != 0) // FOR BLACK
    	{
    	clear();
    	printf("\t\t[BLACK'S TURN]");
    	printf("You've rolled %d and %d \n", nDice1, nDice2);
    	printf("What checkers do you want to move? \n");
	    for (int x = 0; x < 26; x++) //loop for printing the board containing Black's Checkers
    		printf("%d ", Black[x]);
    	printf(" [BLACK'S CHECKERS]\n");
    	for (int y = 0; y < 26; y++) //loop for printing the board containing White's Checkers
            printf("%d ", White[y]);
        printf(" [WHITE'S CHECKERS]");
        fromPiece=0;
        while (Black[fromPiece]<1)
        	{
    		printf("\n\nFrom: ");
    		scanf("%d", &fromPiece);
        	if (Black[fromPiece]<1)
        	printf("No black checkers on this slot, try again.");
    		}
    	cChoice=' ';
    	while (GoVar!='Y' && cChoice!= 'X')
	    	{
	      	printf("\nHow many spaces? [To the left] \n");
	      	if (nDice1 != nDice2) // IF DICE ARE NOT THE SAME
	      		{
	      		nDice3=0, nDice4=0;
	      		printf("A: [%d] B: [%d] Z: [%d]\n", nDice1, nDice2, nDiceTotal);
	      		scanf("%c\n", &cChoice);
	      		}
	      	else if (nDice1 == nDice2) // IF DICE ARE SAME
	      		{
	      		nDiceTotal=nDice1+nDice2+nDice3+nDice4;
		      	printf("A: [%d] B: [%d] C: [%d] D: [%d] Z:[%d]\n", nDice1, nDice2, nDice3, nDice4, nDiceTotal);
		      	scanf("%c\n", &cChoice);
	        	}
	    	if (cChoice == 'A')						//if-statements for player choices on how many spaces to move
    			toPiece=fromPiece-nDice1;         //deduction because Black player is in decrement
			if (cChoice == 'B')
				toPiece=fromPiece-nDice2;
			if (cChoice == 'C')
				toPiece=fromPiece-nDice3;
			if (cChoice == 'D')
				toPiece=fromPiece-nDice4;
			if (cChoice == 'Z')
				toPiece=fromPiece-nDiceTotal;
			moves=nDiceTotal;
		    if (toPiece<0) //if the space is not exactly 1 space away from the border
	        	printf("Invalid tile count [may not exceed 2 or more tiles from the border], repeat. \n");
	      	else if (toPiece>0)//if it's anywhere on the board other than the "point tile" and the "bar"
		      	{
		    	if(White[toPiece]!=0) // if the checker to be added on a tile board is occupied (BLACK START)
		        	{
		        	if (Black[fromPiece]>=White[toPiece] && White[toPiece]==1) // if 1 checker only on the slot (FOR BLACK)
		            	{
		            	White[0]+=White[toPiece]; //changing the value of the bar
		            	White[toPiece]==0; //replacing the value of the occupied tile into no white pieces
		            	Black[toPiece]++; //occupying the tile with new pieces
		            	Black[fromPiece]--;
		            	nDice1=DiceUseConditional(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
		            	nDice2=DiceUseConditional(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
		            	nDice3=DiceUseConditional(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
		            	nDice4=DiceUseConditional(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
		            	nDiceTotal=DiceUseConditional(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
		            	printf("New tile value of Tile %d = %d", toPiece, Black[toPiece]);
		            	toPiece=0;
		            	}
		            else if (White[toPiece]>1) // if more than 1 circle on the slot
		            	{
		            	printf("There are more than 1 of the Player White's checkers on this tile");
		            	}
		        	}
		        else
				  	{
		            Black[toPiece]++;
		            Black[fromPiece]--;
		            DiceUseConditional(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
		            printf("New tile value of Tile %d = %d\n\n", toPiece, Black[toPiece]);
		            cChoice='X';
		            toPiece=0;
		        	}
		      	}
		else if (BlackBearingOff!=15 && toPiece == 0)
		    printf("You can't start earning points if you haven't put all your checkers on the home board!\n");
		    if (BlackBearingOff==15 || BlackGoSign=='Y') //Condition if the player is in state of bearing off
		    	{
		    	BlackGoSign='Y';
		        if (toPiece==0) //Black's array assignment for points
		      		{
			        printf("Black earned a point! \n");
			        Black[toPiece]++; //Black earning a point
			        Black[fromPiece]--;
					DiceUseConditional(&nDice1, &nDice2, &nDice3, &nDice4, cChoice, &nDiceTotal);
					cChoice='X';
					toPiece=0;
		     		}
	     		}
	    	}
	GoVar=' ';
	moves=nDiceTotal; //for recording the total moves left from nDiceTotal
    printf("Do you still want to use your moves? %d moves remaining. \n", moves);
    printf("Enter Q to continue, [S] to skip. \n");
    scanf("%c", &cChoice);
	}
    printf("Press any key to continue...\n");
    (getche());
	clear();
	moves=0;
}
}


  //winning remarks

  if (White[25]==15){
    red();
    printf("\n\n\n\t\t Congratulations! White Player won the game. \t\t\n\n\n");
  }
  else if (Black[0]==15){
    green();
    printf("\n\n\n\t\t Congratulations! Black Player won the game. \t\t\n\n\n");
  }
  system("pause");
  return 0;
}
