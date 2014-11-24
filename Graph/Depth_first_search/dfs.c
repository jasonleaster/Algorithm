/*********************************************************
code writer	:	EOF
code date 	: 	2014.11.24
code file	:	dfs.c
e-mail		:	jasonleaster@gmail.com

Code description:
	This function @dfs() is a implementation of 
"Depth first search" which is based on recursion.

**********************************************************/

#include "dfs.h"

void dfs(struct graph* p_graph,struct vertex* p_vertex,struct visited* p_visited)
{
	if(!p_vertex)
	{
		return;
	}

	p_visited->array[p_vertex->value] = VISITED;

	printf("%d->",p_vertex->value);

	for(p_vertex = p_vertex->next;
	   !!p_vertex;
	   p_vertex = p_vertex->next)
	{
		if(p_visited->array[p_vertex->value] == UN_VISITED)
		{
			dfs(p_graph,&(p_graph->adjacent[p_vertex->value]),p_visited);
		}
	}
	printf("\n");
}
