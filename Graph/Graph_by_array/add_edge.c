/************************************************************
code file	: add_edge.c
code writer	: EOF
code date	: 2014.11.22
e-mail		: jasonleaster@gmail.com

code description:
	This function will help us to add a new connection
between different vertex which is in the graph.

*************************************************************/
#include "graph.h"

int add_edge(struct graph* p_graph,char from_v,char to_v)
{
	if(!p_graph || from_v < 0 || to_v < 0)
	{
		return -1;
	}

	*((char*)(p_graph->adjacent)  + from_v*(p_graph->num_vertex) + to_v)  = 1;
	*((char*)(p_graph->adjacent)  + to_v*(p_graph->num_vertex)  + from_v) = 1;

	return 0;
}
