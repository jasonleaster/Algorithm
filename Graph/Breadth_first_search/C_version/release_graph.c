/************************************************************
code file	: release_graph.c
code writer	: EOF
code date	: 2014.11.22
e-mail		: jasonleaster@gmail.com

code description:
	It's easy and convenient for us to call this API once
and free all the graph.

*************************************************************/
#include "BFS.h"

void release_graph(struct graph* p_graph)
{
	if(!p_graph)
	{
		return ;
	}
	
	int temp = 0;
	int num_vertex = p_graph->num_vertex;
	struct vertex* p_temp = NULL;

	for(temp = 0;temp < num_vertex;temp++)
	{
		if(p_graph->adjacent[temp].next)
		{
			p_temp = (p_graph->adjacent[temp].next->next);
			while(p_temp)
			{
				free(p_graph->adjacent[temp].next);
				p_graph->adjacent[temp].next = p_temp;
				p_temp = p_temp->next;
			}
			free(p_graph->adjacent[temp].next);
		}
	}

	free(p_graph);
}
