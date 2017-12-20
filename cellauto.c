#include "cellauto.h"


/*Determines the rules by which each cell generation is formed*/
char ruleset(char a, char b, char c){
	
		
	//NOTE - NEEDS TO BE CHANGED FOR USER INPUT

	if(a=='#' && b=='#' && c=='#')
	{
		return '_';
	}
	else if(a=='#' && b=='#' && c=='_')
	{
		return '_';
	}
	else if(a=='#' && b=='_' && c=='#')
	{
		return '_';
	}
	else if(a=='#' && b=='_' && c=='_')
	{
		return '#';
	}
	else if(a=='_' && b=='#' && c=='#')
	{
		return '#';
	}
	else if(a=='_' && b=='#' && c=='_')
	{
		return '#';
	}
	else if(a=='_' && b=='_' && c=='#')
	{
		return '#';
	}
	else if(a=='_' && b=='_' && c=='_')
	{
		return '_';
	}
}


/*Generate random values between 0 - 255*/
int randomInput(){
	int r;	
	for(int i = 0; i < 100; i++){
		r = rand() % 256;
	}
	return r;
}

/*Converts a binary number into a decimal number then returns it*/
int binToDec(int bin){

	int dec_val = 0;	//decimal value
	int i = 1;			//base
	int rem;			//remainder

	while(bin > 0)
	{
		rem = bin % 10;
		dec_val = dec_val + rem * i;
		bin = bin/10;
		i = i*2;
	}
	return dec_val;

}

/*Converts a decimal number into a binary number then returns it*/
int decToBin(int dec){

	int bin = 0;	//binary value
	int i = 1;		//base
	int rem;		//remainder

	while(dec != 0)
	{
		rem = dec%2;
		dec = dec/2;
		bin = bin + (rem*i);
		i = i*10;
	}
	return bin;	

}

/*pauses the program for a given number of seconds*/
void pause(double pause){

	time_t start = time(NULL);
	time_t end = time(NULL);

	while(difftime(end, start) < pause)
	{
		end = time(NULL);
	}

}

/*Creates a one dimensional cellular automaton, displays it and then prints it to file*/
void CellAuto1D(int cell, int gen){

	int rule[8] = {0,0,0,1,1,1,1,0};

	char parentCell[cell]; 
	char childCell[cell];

	
	//set cells to dead
	for(int i = 0; i<cell; i++)
		{
			parentCell[i] = '_';
			childCell[i] = '_'; 
		}

	//TEMPORARY - set static value to provoke change
	parentCell[(cell-1)/2]='#';


	for(int i=0; i<gen; i++)
	{
		//determine the value of the child generation
		for(int i=1; i<(cell-1); i++)
		{

			char left = parentCell[i-1];		//get value of left parent
			char mid = parentCell[i];		//get value of main parent
			char right = parentCell[i+1];		//get value of right parent
			
			childCell[i]=ruleset(left,mid,right); //determine new cell value

	 	}

		//print and write current parent generation
		for(int i = 0; i<cell; i++)
		{
			printf("%c",parentCell[i]);
		}

		//assign parent gen to child gen
		for(int i=1; i<(cell-1); i++)
		{
			parentCell[i]=childCell[i];
	 	}
		printf("\n");
	}
	
	//print and write final generation
	for(int i = 0; i<cell; i++)
	{
			printf("%c",childCell[i]);
	}
}


/*Create a 2D cellular automaton based on Conway's Game of Life*/
void GameOfLife(int column, int row, int gen){

	Cell* board[column][row];
	
	//initialise all instances of cells on the board
	for(int i = 0; i<column; i++)
	{
		for(int j = 0; j<row; j++)
		{
			board[i][j] = getCell();
		}
	}

	//TEMPORARY - create some alive cells to stimulate change
	board[(column-1)/2][(row-1)/2]->data = '#';
	board[(column+1)/2][(row-1)/2]->data = '#';
	board[(column+3)/2][(row-1)/2]->data = '#';
	board[(column-1)/2][(row+1)/2]->data = '#';
	board[(column+1)/2][(row+1)/2]->data = '#';
	board[(column+3)/2][(row+1)/2]->data = '#';

	//loop for given number of turns 
	for(int t = 0; t<gen; t++)
	{
		

		for(int i = 1; i<column-1; i++)
		{
			for(int j = 1; j<row-1; j++)
			{


				//determine how many adjacent cells are alive
				int alivecount = 0;
				if(board[i-1][j]->data == '#') {alivecount++;}
				if(board[i-1][j-1]->data == '#') {alivecount++;}
				if(board[i-1][j+1]->data == '#') {alivecount++;}
				if(board[i+1][j]->data == '#') {alivecount++;}
				if(board[i+1][j-1]->data == '#') {alivecount++;}
				if(board[i+1][j+1]->data == '#') {alivecount++;}
				if(board[i][j+1]->data == '#') {alivecount++;}
				if(board[i][j-1]->data == '#') {alivecount++;}
				board[i][j]->alive = alivecount;
			}
			printf("\n");
		}
		


		for(int i = 1; i<column-1; i++)
		{
			for(int j = 1; j<row-1; j++)
			{
				//display current board
				printf("%c",board[i][j]->data);	

				//update board based on rules
				lifeRules(board[i][j]);
			}
		}
		pause(2);		
	}

}

void lifeRules(Cell* input){

	if(input->data == '#')
	{
		if(input->alive > 3 || input->alive < 2)
		{
			input->data = 'D';	//cell is dead
		}
	}
	else
	{
		if(input->alive == 3)
		{		
			input->data = '#';	//cell is alive
		}
	}
}






























