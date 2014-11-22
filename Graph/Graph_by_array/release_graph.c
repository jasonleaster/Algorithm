/************************************************************
code file	: release_graph.c
code writer	: EOF
code date	: 2014.11.22
e-mail		: jasonleaster@gmail.com

code description:
	It's easy and convenient for us to call this API once
and free all the graph.

*************************************************************/
#include "graph.h"
#include "graph.h"
void release_graph(struct graph* p_graph)
{
	if(!p_graph)
	{
		return ;
	}

	free(p_graph);
}
