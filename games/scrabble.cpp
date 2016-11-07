/////////////////////////////////////////////////////////////////////////
//                      ***********                                    //
//                      *SCRABBLE *                                    //
//                      ***********                                    //
//                                                                     //
// FILE NAME: SCRABLLE.CPP                                             //
// AUTHOR: JAVERIA ASLAM KHAN                                          //
// PROJECT: SCRABBLE                                                   //
// CREATED: JAN 11 2005                                                //
// DESCRIPTION: MAIN SOURCE CODE FOR SCRABBLE                          //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include "scrab.h"


void main(void)
{

	defin();

	Display_Board();
	while(1)
	{
      
			
       Tiles_Bag(); //asking to refil racks to seven
		Take_input(); //taking letters from players
		 place_word(); // checking if the word fits and placing it on board positions

			while(1)
			 {
			if(check_length==1) //infinite loop to keep asking taking
			{                   // input if word doesnt fit
				 Take_input();
			 place_word();
			 }

			 else // if word fits then go on
		
			break;
			}



			score(); //calculating the score
	    
			system("cls"); //clear screen for next player
		
			Display_Board(); // displaing the board with the tiles placed
	
		if(turn==1) //switiching turns before next play
			turn=2;
		else if(turn==2)
			turn=1;
		

	}


}
/////////////////////////////////////////////////////////////////////////
//                                                                     //
//                      Display_Board()                                //
//                                                                     //
//                                                                     //
// ARGUMENTS/RETURN VALUES: none                                       //
// AUTHOR: JAVERIA ASLAM KHAN                                          //
// PROJECT: SCRABBLE                                                   //
// CREATED: JAN 11 2005                                                //
// DESCRIPTION: Displays the board with placed tiles and score board   //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

void Display_Board(void)
{
int 	check=0, check2=0, check1=0;
char h, letter='A';
 h=4365328;

	
	ch='A';	

//displays the board made of characters
	
	
		printf("\n  -----------------------------------------------------------  %c%c%c%c%c%c%c%c%c%c%c%c%c%c", h,h,h,h,h,h,h,h,h,h,h,h,h,h);

	printf("\n | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12| 13| 14| 15||  SCORE      |\n"); //columns

		for(i=0; i<15; i++)
		{
			printf("-|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
		

			printf("%c|", ch);
		       
					
				{	
					for(j=0; j<15; j++)
					{
						printf(" %c |", board[i][j].block);
							
						
				// printing the score board at the right
						if(check==0  && j==14)
				{printf("| PLAYER 1= %d |", Score1); 
						check=1;}
					
						if(check2==0 && ch=='B'&& j==14)
						{printf("| PLAYER 2= %d |", Score2); 
						check2=1;
					}
					
					 if (check1==0 && check2==1 && j==14 && ch=='C')
						{
							printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c", h,h,h,h,h,h,h,h,h,h,h,h,h,h);
							check2=3;
					 check1=1;}

					
}
	//prints letter values at the right for user reference				
 if(check1==1 && check2==3 && i>2)
 {
	 printf(" %c = %2d , ",letter, letter_values[letter-65]); 
 letter++;
printf("%c = %d",letter, letter_values[letter-65]);	
letter++;}
 ch++;

		printf("\n");
				}
		}

		


	printf("--------------------------------------------------------------");

	if(i==1 || i==3 || i==5)
		printf("|              |");
	printf("\n");
	//printing bloxk value for user info
	printf(" *= tword, %c= dword, x= tletter, += dletter ?= blank", 4365316);
  //prints Y and Z values
	printf("\t       %c = %2d , ",letter, letter_values[letter-65]);
	letter++;
	printf("%c = %d  \n",letter, letter_values[letter-65]);
	

}

/////////////////////////////////////////////////////////////////////////
//                                                                     //
//                      score()                                        //
//                                                                     //
//                                                                     //
// ARGUMENTS/RETURN VALUES: none                                       //
// AUTHOR: JAVERIA ASLAM KHAN                                          //
// PROJECT: SCRABBLE                                                   //
// CREATED: JAN 11 2005                                                //
// DESCRIPTION: calculates score every turn & adds it to the total     //
//                                                                     //
/////////////////////////////////////////////////////////////////////////


void score()
{

		int sc=0, i=0,  ch, lettersc;

  //using the row column specified calculates score of each letter

		while(board[srow][scolumn].letter_in_block !='\0') 
		{
			
			if(direction=='a')
			{
			if(board[srow][scolumn].letter_in_block>=91 && board[srow][scolumn].letter_in_block<=122) //checking for any lowercase letters entered
					board[srow][scolumn].letter_in_block=board[srow][scolumn].letter_in_block-32;     //and changing them
			
			ch =(int)(board[srow][scolumn].letter_in_block - 65);
			
			//checking for double letter scores
			if(strcmp(board[srow][scolumn].value_block, double_letter)==0)
				lettersc=letter_values[ch]*2;
			 
			//checking for triple letter scores
			else if(strcmp(board[srow][scolumn].value_block, triple_letter)==0)
				lettersc=letter_values[ch]*3;
			
		     else
				lettersc=letter_values[ch]; //using array letter_values[] for score
			 scolumn++;
			}

				else if(direction=='d')
			{
			if(board[srow][scolumn].letter_in_block>=91 && board[srow][scolumn].letter_in_block<=122) //checking for any lowercase letters entered
					board[srow][scolumn].letter_in_block=board[srow][scolumn].letter_in_block-32;     //and changing them
			
			ch =(int)(board[srow][scolumn].letter_in_block - 65);
			
			if(strcmp(board[srow][scolumn].value_block, double_letter)==0)
				lettersc=letter_values[ch]*2;
			
			else if(strcmp(board[srow][scolumn].value_block, triple_letter)==0)
				lettersc=letter_values[ch]*3;
			
		     else
				lettersc=letter_values[ch];
			 srow++;
			}


       sc = sc + lettersc; //adding it up
		
		}
		
		if(flag_tw>0)
		{//checking triple word scores

			for(i=0; i<flag_tw; i++)
			sc=sc*3;
		}

		if(flag_dw>0)
		{//checking double word scores
			for(i=0; i<flag_dw; i++)
			sc=sc*2;
		}

		fflush(stdin);

		if(turn==1)
		{
			Score1 += sc; //adding sc temp score this turn to the total
			printf("\nTURN SCORE: %d\n", sc);
		}

		else if(turn==2)
		{
			Score2 += sc;
			printf("\nTURN SCORE: %d\n", sc);
		printf("SCORE: %d\n", Score2);
		}
		srow=0; 
		scolumn=0;
		

}


/////////////////////////////////////////////////////////////////////////
//                                                                     //
//                      Tiles_Bag()                                     //
//                                                                     //
//                                                                     //
// ARGUMENTS/RETURN VALUES: none                                       //
// AUTHOR: JAVERIA ASLAM KHAN                                          //
// PROJECT: SCRABBLE                                                   //
// CREATED: JAN 11 2005                                                //
// DESCRIPTION: randomly choses tiles and saves it to the racks        //
//                                                                     //
/////////////////////////////////////////////////////////////////////////



void Tiles_Bag(void)
{
	int q=0, j=0, to_give=0,  loop=0;


	if(bag_empty==0)
	{

		srand(unsigned(time(0))); //seed for random function

		if(turn==1)
		{
	
	to_give=tiles_taken1;
		}
		
		else if(turn==2)
		{
	to_give=tiles_taken2;
		}
	
		loop=to_give;

	for(i=0; i<loop; i++)
	{
	
		j=(rand()%100); //getting a random num


			if(tiles[j].flag_passed==0) //using the num as array field
			{
					while(1)
				{
						 if(turn==1)
						 {
					if(rack1[q]=='\0') //check if position is empty in rack to place
					{
						rack1[q]=tiles[j].letter; //placing letter on rack
						tiles[j].flag_passed=1; //check for tile passed
						q++;
						
						break;
					}

						else 
						q++;
				
						}

							 else if(turn==2)
						 {
				 if(rack2[q]=='\0')
					{
						rack2[q]=tiles[j].letter;
						tiles[j].flag_passed=1;
						q++;
						
						break;
					}

						else 
						q++;
				
						}
						
				
			}
	
		}
			else
				loop++;

}
	

	tiles_used += to_give; //adding up tiles taken out of bag
	
	if(tiles_used==100) //check if bag is empty
	{
		bag_empty=1;
	printf("BAG IS EMPTY\n"); //if its empty then print this
	}
	}

		printf("----------------------------"); //printing the racks


	printf("\n|RACK|");
	
	if(turn==1) //printing rack for player1
		
	{
		for(i=0; i<7; i++)
		printf(" %c ", rack1[i]);
	tiles_taken1=0;
	}
	
	else if(turn==2)
	{
		for(i=0; i<7; i++)
		printf(" %c ", rack2[i]); //rack for player two
	
		tiles_taken2=0;
	}
	printf("|");
		printf("\n----------------------------");



	 
	printf("\n");
 

}

/////////////////////////////////////////////////////////////////////////
//                                                                     //
//                      defin()                                        //
//                                                                     //
//                                                                     //
// ARGUMENTS/RETURN VALUES: none                                       //
// AUTHOR: JAVERIA ASLAM KHAN                                          //
// PROJECT: SCRABBLE                                                   //
// CREATED: JAN 11 2005                                                //
// DESCRIPTION: defines word letter score positions  and defines the   //
// tiles, fills word and racks with null characters                    //                                           //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

void defin(void)
{

		for(i=0; i<15; i++) //setting all board positions to not used status
		{ for(j=0; j<15; j++)
		board[i][j].flag_fill=0; }

		for(i=0; i<15; i++) //filling board with null characters
		{for(j=0; j<15; j++)
		board[i][j].block='\0';}
	
			board[7][7].block=4365316; //middle of board
			


	
	for(i=0; i<100; i++) //setting tiles to not passed status
		tiles[i].flag_passed=0;
/////////////////////////////////////////////////////////////////////
/// filling word and rack arrays with null///


	for(i=0; i<7; i++)
		word[i]='\0';

	for(i=0; i<7; i++)
	{
		rack1[i]='\0';
		rack2[i]='\0';
	}
/////////////////////////////////////////////////////////////////////
/// defining tiles///

	for(i=0; i<9; i++)
   tiles[i].letter='A';

	tiles[9].letter='B';
    tiles[10].letter='B';

 tiles[11].letter='C';
 tiles[12].letter='C';

tiles[13].letter='D';
tiles[14].letter='D';
tiles[15].letter='D';
tiles[16].letter='D';

for(i=17; i<=28; i++)
tiles[i].letter='E';


tiles[29].letter='F';
tiles[30].letter='F';

tiles[31].letter='G';
tiles[32].letter='G';
tiles[33].letter='H';
tiles[34].letter='H';


for(i=35; i<=42; i++)
tiles[i].letter='I';

tiles[43].letter='J';

tiles[44].letter='K';

tiles[45].letter='L';
tiles[46].letter='L';

tiles[47].letter='M';
tiles[48].letter='M';
tiles[49].letter='M';
tiles[50].letter='M';

for(i=51; i<=56; i++)
tiles[i].letter='N';

for(i=57; i<=64; i++)
tiles[i].letter='O';

tiles[65].letter='P';
tiles[66].letter='P';

tiles[67].letter='Q';

for(i=68; i<=73; i++)
tiles[i].letter='R';

for(i=74; i<=79; i++)
tiles[i].letter='S';

for(i=80; i<=85; i++)
tiles[i].letter='T';

tiles[86].letter='U';
tiles[87].letter='U';
tiles[88].letter='U';
tiles[89].letter='U';

tiles[90].letter='V';
tiles[91].letter='V';

tiles[92].letter='W';
tiles[93].letter='W';

tiles[94].letter='X';

tiles[95].letter='Y';
tiles[96].letter='Y';

tiles[97].letter='Z';
tiles[98].letter='?';
tiles[99].letter='?';







	///////////////////////////////////////////////////////////////////////
	//																	 //
	//					TRIPLE WORD SCORES		                         //  
	//																	 //
	///////////////////////////////////////////////////////////////////////
	
	strcpy(board[0][0].value_block, triple_word);
	strcpy(board[0][5].value_block, triple_word);
	strcpy(board[0][9].value_block, "tw");
	strcpy(board[0][14].value_block, "tw");
	strcpy(board[5][0].value_block, "tw");
	strcpy(board[5][14].value_block, "tw");
	strcpy(board[9][0].value_block, "tw");
	strcpy(board[9][14].value_block, "tw");
	strcpy(board[14][0].value_block, "tw");
	strcpy(board[14][5].value_block, "tw");
	strcpy(board[14][9].value_block, "tw");
	strcpy(board[14][14].value_block, "tw");

	
	
	
	///////////////////////////////////////////////////////////////////////
	//																	 //
	//					DOUBLE WORD SCORES		                         //      
	//																	 //
	///////////////////////////////////////////////////////////////////////
	
	strcpy(board[1][1].value_block, "dw");
	strcpy(board[1][6].value_block, "dw");
	strcpy(board[1][8].value_block, "dw");
	strcpy(board[1][13].value_block, "dw");
	strcpy(board[6][1].value_block, "dw");
	strcpy(board[6][13].value_block, "dw");
	strcpy(board[8][1].value_block, "dw");
	strcpy(board[8][13].value_block, "dw");
	strcpy(board[13][1].value_block, "dw");
	strcpy(board[13][6].value_block, "dw");
	strcpy(board[13][8].value_block, "dw");
	strcpy(board[13][13].value_block, "dw");

	///////////////////////////////////////////////////////////////////////
	//																	 //
	//					TRIPLE LETTER SCORES		                     //   
	//																	 //
	///////////////////////////////////////////////////////////////////////
	
	strcpy(board[2][2].value_block, "tl");
	strcpy(board[2][7].value_block, "tl");
	strcpy(board[2][12].value_block, "tl");
	strcpy(board[3][5].value_block, "tl");
	strcpy(board[3][9].value_block, "tl");
	strcpy(board[4][6].value_block, "tl");
	strcpy(board[4][8].value_block, "tl");
	strcpy(board[5][3].value_block, "tl");
	strcpy(board[5][11].value_block, "tl");
	strcpy(board[6][4].value_block, "tl");
	strcpy(board[6][10].value_block, "tl");
	strcpy(board[7][2].value_block, "tl");
	strcpy(board[7][12].value_block, "tl");
	strcpy(board[8][4].value_block, "tl");
	strcpy(board[8][10].value_block, "tl");
	strcpy(board[9][3].value_block, "tl");
	strcpy(board[9][11].value_block, "tl");
	strcpy(board[10][6].value_block, "tl");
	strcpy(board[10][8].value_block, "tl");
	strcpy(board[11][5].value_block, "tl");
	strcpy(board[11][9].value_block, "tl");
	strcpy(board[12][2].value_block, "tl");
	strcpy(board[12][7].value_block, "tl");
	strcpy(board[12][12].value_block, "tl");

	///////////////////////////////////////////////////////////////////////
	//																	 //
	//					DOUBLE LETTER SCORES		                     //    
	//																	 //
	///////////////////////////////////////////////////////////////////////

	strcpy(board[3][3].value_block, "dl");
	strcpy(board[3][11].value_block, "dl");
	strcpy(board[5][7].value_block, "dl");
	strcpy(board[7][5].value_block, "dl");
	strcpy(board[7][9].value_block, "dl");
	strcpy(board[9][7].value_block, "dl");
	strcpy(board[11][3].value_block, "dl");
	strcpy(board[11][11].value_block, "dl");

	//copying special characters for triple and double word scores onto board positions

for(i=0; i<15; i++)
{for(j=0; j<15; j++)
{
	if((strcmp(board[i][j].value_block, "dl"))==0) // + for double letter
		board[i][j].block='+';
}}




for(i=0; i<15; i++)
{for(j=0; j<15; j++)
{
	if((strcmp(board[i][j].value_block, "tl"))==0)
		board[i][j].block='x'; //x for triple letter
}}


for(i=0; i<15; i++)
{for(j=0; j<15; j++)
{
	if((strcmp(board[i][j].value_block, "tw"))==0)
		board[i][j].block='*'; //* for triple word
}}



for(i=0; i<15; i++)
{for(j=0; j<15; j++)
{
	if((strcmp(board[i][j].value_block, "dw"))==0)
		board[i][j].block=4365316; //traingle for double word
}}



}

/////////////////////////////////////////////////////////////////////////
//                                                                     //
//                      place_word()                                   //
//                                                                     //
//                                                                     //
// ARGUMENTS/RETURN VALUES: none                                       //
// AUTHOR: JAVERIA ASLAM KHAN                                          //
// PROJECT: SCRABBLE                                                   //
// CREATED: JAN 11 2005                                                //
// DESCRIPTION: checks if word fits in specified place and copies the  //
// letters to board positions                                          //                                           //
//                                                                     //
/////////////////////////////////////////////////////////////////////////


void place_word(void)
{
	int checkr=0, checkc=0; 
	check_length=0;
		
	row=row-1; column=column-1;
	srow=row;
	scolumn=column;
checkr=row;
checkc=column;

//check if word fits
		if(direction=='a') //for across direction
			checkc=checkc+total_letters;

		else if (direction=='d') //for down direction
			checkr=checkr+total_letters;
		
			if(checkr>15 || checkc>15) //if word doesnt fit, too big for space
			{
				printf("\n** Ur word doesnt fit **\nSELECT LETTERS AGAIN\n");
				check_length=1;
			}


	if(check_length==0)//if word fits
	{

		for(j=0; j<used; j++) //emptying rack
			{
				k=v[j];
				if(turn==1) //rack for player one
			rack1[k]='\0';
				else if(turn==2)   //rack for player two
					rack2[k]='\0';
			 }

		for(i=0; i<total_letters;  i++)	
{  
	
		if(word[i]=='\0') //not to erase letters already on board
		break;
	
		if(direction=='a') // ACROSS PLACEMENT
		{

			if(board[row][column].flag_fill==1) //checking for filled spaces
		   column++;                      //writing letter in next space if filled
		
			board[row][column].block=word[i];
            board[row][column].flag_fill=1;
				board[row][column].letter_in_block=word[i];
		
	if(strcmp(board[row][column].value_block, double_word)==0) //check double word scores
	flag_dw++;

	else if(strcmp(board[row][column].value_block, triple_word)==0) //check triple word scores
				flag_tw++;
	board[row][column].letter_in_block=board[row][column].block;
	 column++;
		
	 }
	

	else if (direction=='d') // DOWN PLACEMENT
	{
			if( board[row][column].flag_fill==1) //check if space is occupied
			row++;                          //writing in next space as above
		
			board[row][column].block=word[i];
		    board[row][column].flag_fill=1;
			board[row][column].letter_in_block=word[i];
		
    if(strcmp(board[row][column].value_block, double_word)==0) //check double word scores
	flag_dw++;

	else if(strcmp(board[row][column].value_block, triple_word)==0) //check triple word scores
				flag_tw++;
	board[row][column].letter_in_block=board[row][column].block;
	 row++;


			}
}
	}
	total_letters=0; //setting letters taken on turn to zero

}


/////////////////////////////////////////////////////////////////////////
//                                                                     //
//                      Take_input()                                   //
//                                                                     //
//                                                                     //
// ARGUMENTS/RETURN VALUES: none                                       //
// AUTHOR: JAVERIA ASLAM KHAN                                          //
// PROJECT: SCRABBLE                                                   //
// CREATED: JAN 11 2005                                                //
// DESCRIPTION: asks for player to chose letters from there racks and  //
// checks if the letters are in rack, asks for row, column and direction/                   //                                           //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

void Take_input(void)
{

	used=0;
	int q=0;
		fflush(stdin);	

	
for(i=0; i<7; i++)  //emptying word rack again
		word[i]='\0';

	printf("\nPlayer %d\n", turn);
 
	i=0;
	j=0;
	printf("Enter letters to place from rack(% to quit):");
while((word[i]=getche())!='\r') //getting word character by character

{
	
	while(1)
	{
		if(word[i]>=97&&word[i]<=122) //changing lowercase input
			word[i]=word[i]-32;

		if(turn==1) //for player one
		{
			if((strcmp(word, "%"))==0) //if player wants to quit
				exit(1);
			
			if(word[i]==rack1[j]) //if entered letter matches one from rack
		
			 { 
				  	if(word[i]=='?') //if letter is blank
				{printf("\nenter a value for blank:"); //asking for another letter
					scanf("%c", &word[i]);} //saving it to the position that had ?

				v[q]=j; //saving array positions to empty them later
			   used++;
			    i++;
				j=0;
				q++;
				tiles_taken1++; //number of tiles taken at turn
			
				break;
			}

	       else 
		    j++;
		}

		else if(turn==2)
		{
  
			if(word[i]==rack2[j])    
		
				{ 	
					 if(word[i]=='?')
					{printf("\nEnter a value for blank:");
				scanf("%c", word[i]);}

				v[q]=j;
			       used++;
				    q++;
					i++;
					j=0;
					tiles_taken2++;
					break;
				}

			else 
				j++;
		}
	
	if(j==7)
	{ //if letter entered is not in rack
		printf("\n*Letter is not in ur rack*\npress enter to continue or add another letter\n");
		j=0;
	break;
	}
	
}
}

 word[i]='\0';
 total_letters=i;

fflush(stdin);
	printf("\nEnter letter row :"); //specifying row
     scanf("%c", &row);

	while(1)
	{
		if(row>=97&&row<=122) //if row is entered in lowercase
		{
			row=row-32;
		break;
		}
			if(row>=65 && row<=79)
				break;
			else
			{
				fflush(stdin); //error for row
				printf("\nentered row does not exist it has to be a letter\n");
           printf("Enter letter row :");
		scanf("%c", &row);

			}
	}
	row=row-64;
    fflush(stdin);

	printf("\nEnter number column:"); //specifying column
	scanf("%d", &column);


	
	fflush(stdin);
	printf("\ndown 'd' or across 'a': "); //specifying dorection
	direction=getche();

		
	while(1)
	{
	 if(direction=='a'||direction=='d')
		break;

		else
			
		{
			printf("Wrong input\n");
printf("Is word down 'd' or across 'a': ");
scanf("%c", &direction);
		}
	
	}

}