/************************************************************
code file	: init_table.c
code writer	: EOF
code date	: 2014.11.23
e-mail		: jasonleaster@gmail.com

code description:
	
	This function will help us to create a table which's
size is @row multiply @col. And the size of each unit int
this table is sizeof(int).

************************************************************/

#include "tls.h"

struct table* init_table(int row,int col)
{
	if(row <= 0 || col <= 0)
	{
		return NULL;
	}

	struct table* p_table = (struct table*)malloc(sizeof(struct table) + row*col*sizeof(int));

	if(!p_table)
	{
		return NULL;
	}
	
	p_table->height = row;
	p_table->width  = col;

	int num_row = row;
	int num_col = col;

	//We must initialize the table !
	for(row = 0;row < num_row;row++)
	{
		*((int*)(p_table->msg) + row*num_col + KNOW_OFFSET) = NOT_FOUND;
		if(row != ENTRY_POINT)
		{
			*((int*)(p_table->msg) + row*num_col + DIST_OFFSET) = INFINITE;
		}
		else
		{
			*((int*)(p_table->msg) + row*num_col + DIST_OFFSET) = 0;
		}
		*((int*)(p_table->msg) + row*num_col + PATH_OFFSET) = 0;
		
	}

	return p_table;
}
