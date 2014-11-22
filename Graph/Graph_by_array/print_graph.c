/************************************************************
code file	: print_graph.c
code writer	: EOF
code date	: 2014.11.22
e-mail		: jasonleaster@gmail.com

code description:
	This function will print out the connection of graph
which @p_graph point to.

************************************************************/

#include "graph.h"
int print_graph(struct graph* p_graph)
{
	if(!p_graph)
	{
		return FAILED;
	}

	int from_v = 0;
	int to_v = 0;

	int vertex = p_graph->num_vertex;
	int edge   = p_graph->num_edge;

	for(from_v = 0;from_v < vertex;from_v++)
	{
		for(to_v = 0;to_v < vertex;to_v++)
		{
			if(*((char*)(p_graph->adjacent) 
			+ from_v*(vertex) + to_v) == CONNECTED)
			{
				printf("%d\t%d\n",from_v,to_v);
			}
		}
	}

	return SUCCESS;
}
