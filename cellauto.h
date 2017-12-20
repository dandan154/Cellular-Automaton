#include <math.h>
#include <time.h>
#include "cell_manager.h"

/*Determines the rules by which each cell generation is formed*/
char ruleset(char a, char b, char c);

void lifeRules();

int randomInput();

/*Converts a binary number into a decimal number then returns it*/
int binToDec(int bin);

/*Converts a decimal number into a binary number then returns it*/
int decToBin(int dec);

/*Creates a one dimensional cellular automaton, displays it and then prints it*/
void CellAuto1D(int cell, int gen);

/*Creates the 'Game of Life', a two dimensional cellular automaton, then displays it*/
void GameOfLife();


