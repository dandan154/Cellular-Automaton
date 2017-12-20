#include "cellauto.h"

int main(){

	static const int RULESIZE = 8;
	int ch;
	//set initial rule values
	int ruledec = 0;
	int rulebin = 00011110;

	int cellX = 41;
	int cellY = 21;
	int gen = 20;

	char choice;

	do
	{

		rulebin = decToBin(ruledec);
		
		printf("------------------------------\n");
		printf("MAIN MENU\n");
		printf("------------------------------\n");
		printf("c. Cellular Automaton\n");
		printf("g. Conway's Game of Life\n");
		printf("r. Randomise Current Rule\n");
		printf("c. Change Initial Input\n");
		printf("e. Exit\n");
		printf("------------------------------\n");
		printf("Decimal Rule:	%d \n", ruledec);
		printf("Binary Rule:	%d \n", rulebin);	
		printf("------------------------------\n");
		printf("1D Automaton\n");
		printf("generation length:	%d \n", cellX);	
		printf("no. of generations:	%d \n", gen);	
		printf("------------------------------\n");
		printf("Game of Life\n");
		printf("board length:	%d \n", cellX);	
		printf("board height:	%d \n", cellY);	
		printf("no. of generations:	%d \n", gen);
		printf("------------------------------\n");
		
		choice = fgetc(stdin);
		switch(choice)
		{
			case 'e':
			case 'E':
				return 0;
			break;
			case 'c':
			case 'C':		
				CellAuto1D(cellX,gen);
			break;
			case 'g': 
			case 'G': 
				GameOfLife(cellX, cellY, gen);
			break;
			case 'r': 
			case 'R': 
				ruledec = randomInput();
			break;
			case 'k': 
			case 'K': 
				printf("change initial input");
			break;
			default: printf("Please select an option from the menu");
			break;

		}
		while((ch = getchar()) != '\n' && ch != EOF);
		printf("\n");
	}while(choice != 'e' || choice != 'E');

	
}
