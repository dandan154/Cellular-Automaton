#include "cell.h"

/*Creates and initialises a cell object*/
Cell* getCell()
{

	Cell* c = malloc(sizeof(Cell));
	if(c != NULL) {
		c->data = '_';
		c->alive = 0;
	}
	return c;

}

/*Nullifies and frees a cell object*/
void releaseCell(Cell* oldCell)
{
	if (oldCell == NULL) {return;}
	
	oldCell->data = ' ';
	oldCell->alive = 0;	

	free(oldCell);
}
