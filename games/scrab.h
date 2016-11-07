/////////////////////////////////////////////////////////////////////////
//                                                                     //
//                           SCRABBLE                                  //
//                                                                     //
// FILE NAME: SCRAB.H                                                  //
// AUTHOR: JAVERIA ASLAM KHAN                                          //
// PROJECT: SCRABBLE                                                   //
// CREATED: JAN 11 2005                                                //
// DESCRIPTION: CONTAINS ALL DECLARATIONS FOR PLAY                     //
//                                                                     //
/////////////////////////////////////////////////////////////////////////


#include <stdio.h>



void Display_Board(void);
void score(void);
void Tiles_Bag(void);
void defin(void);
void place_word(void);
void Take_input(void);

char  ch='A', word[7], row=0, srow=0, q[]={"q"};
	int i, j, column=0, scolumn=0,direction='a'; 
	int letter_values[]={1,2,2,2,1,4,4,4,1,5,5,1,1,1,
			1,2,10,1,1,1,1,2,4,8,2,10};
	
	int tiles_taken1=7, tiles_taken2=7; // num of tiles taken by each player every turn from rack

	char double_letter[]={"dl"}, triple_letter[]={"tl"}, triple_word[]={"tw"},
		double_word[]={"dw"};
	char rack1[7], rack2[7];

	struct bag
	{
		char letter;
		int flag_passed;
	};
	struct bag tiles[100];

	struct boardstr
	{
		int block;
		char value_block[2]; 
			char letter_in_block;
			int flag_fill;
	};
	struct boardstr board[15][15]; 
	 
	int tiles_used=0, bag_empty=0; //checks for number of used tiles & if bag is empty

	int Score1=0, Score2=0, flag_dw=0, flag_tw=0;
	int turn=1, total_letters=0;
	int check_length=0;
	int v[7], used;
	int k=0;
	
