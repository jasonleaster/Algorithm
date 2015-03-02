/************************************************************
code file	: init_graph.c
code writer	: EOF
code date	: 2014.11.22
e-mail		: jasonleaster@gmail.com

code description:
	This function is used for initializing the graph
with inputed parameter @vertex and @edge.

************************************************************/
#include "BFS.h"

struct graph* init_graph(int num_vertex,int num_edge)
{

	if(num_vertex <= 0 || num_edge <= 0)
	{
		return NULL;
	}

	struct graph* p_graph = NULL;

        p_graph = (struct graph*)malloc(sizeof(struct graph) +\
		  num_vertex*sizeof(struct vertex));

	if(!p_graph)
	{
		printf("malloc failed in function %s()\n",__FUNCTION__);
		return NULL;
	}
	
	p_graph->num_vertex = num_vertex;
	p_graph->num_edge   = num_edge;

	int temp = 0;
	//initialize the adjacent relationship
	for(temp = 0;temp < num_vertex;temp++)
	{
		p_graph->adjacent[temp].value = temp;
		p_graph->adjacent[temp].next  = NULL;
		p_graph->adjacent[temp].end   = NULL;
	}
	
	return p_graph;
}
