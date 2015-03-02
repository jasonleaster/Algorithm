/************************************************************
code file	: add_edge.c
code writer	: EOF
code date	: 2014.11.22
e-mail		: jasonleaster@gmail.com

code description:
	This function will help us to add a new connection
between different vertex which is in the graph.

*************************************************************/
#include "dfs.h"

int add_edge(struct graph* p_graph,char from_v,char to_v)
{
	if(!p_graph || from_v < 0 || to_v < 0)
	{
		return FAILED;
	}

	struct vertex* p_to_v    = (struct vertex*)malloc(sizeof(struct vertex));

	if(!p_to_v)
	{
		printf("malloc failed in function %s()\n",__FUNCTION__);

		return FAILED;		
	}

	if(!(p_graph->adjacent[from_v].end))
	{
		p_graph->adjacent[from_v].next  = p_to_v;
		p_graph->adjacent[from_v].end   = p_to_v;
		p_to_v->next  = NULL;
		p_to_v->value = to_v;
	}
	else
	{
		p_graph->adjacent[from_v].end->next = p_to_v;
		p_graph->adjacent[from_v].end       = p_to_v;//update the new end node.
		p_to_v->next  = NULL;
		p_to_v->value = to_v;
		
	}

	return SUCCESS;
}
