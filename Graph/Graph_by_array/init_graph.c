/************************************************************
code file	: init_graph.c
code writer	: EOF
code date	: 2014.11.22
e-mail		: jasonleaster@gmail.com

code description:
	This function is used for initializing the graph
with inputed parameter @vertex and @edge.

************************************************************/

#include "graph.h"

struct graph* init_graph(int vertex,int edge)
{
	if(vertex <=0 || edge <= 0)
	{
		return NULL;
	}

	int temp = 0;

	struct graph* p_graph = NULL;
        p_graph = (struct graph*)malloc(sizeof(struct graph) + vertex*vertex*sizeof(char));

	if(!p_graph)
	{
		printf("malloc failed in function %s()\n",__FUNCTION__);
		return NULL;
	}

	p_graph->num_vertex = vertex;
	p_graph->num_edge   = edge;

	//initialize the adjacent relationship
	for(temp = 0;temp < vertex*vertex;temp++)
	{
		p_graph->adjacent[temp] = 0;
	}
	
	return p_graph;
}
