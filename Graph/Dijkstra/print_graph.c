/************************************************************
code file	: print_graph.c
code writer	: EOF
code date	: 2014.11.22
e-mail		: jasonleaster@gmail.com

code description:
	This function will print out the connection of graph
which @p_graph point to.

************************************************************/

#include "dijstra.h"

int print_graph(struct graph* p_graph)
{
	if(!p_graph)
	{
		return FAILED;
	}

	int from_v = 0;
	int to_v = 0;

	int num_vertex = p_graph->num_vertex;

	struct vertex* p_vertex = NULL;

	for(from_v = 0;from_v < num_vertex;from_v++)
	{	
		p_vertex = &(p_graph->adjacent[from_v]);
		while(p_vertex)
		{
			printf("\t%d",p_vertex->value);
			p_vertex = p_vertex->next;
		}
		printf("\n");
	}

	return SUCCESS;
}
