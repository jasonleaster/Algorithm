/****************************************************************
code file	: test_graph.c
code writer	: EOF
code date	: 2014.11.22
e-mail		: jasonleaster@gmail.com

code description:
	Here , we use this program to call some API which would 
construct a ADT--graph and test it.

*****************************************************************/
#include "dfs.h"

int main()
{
	struct graph* p_graph = NULL;

	FILE* fp = fopen("./text.txt","r+");

	if(!fp)
	{
		printf("fopen() failed!\n");
		return 0;
	}

	int ret    = 0;
	int vertex = 0;
	int edge   = 0;

	int from_v = 0;
	int to_v   = 0;

	fscanf(fp,"%d",&vertex);
	fscanf(fp,"%d",&edge);

	p_graph = init_graph(vertex,edge);

	int temp = 0;
	for(temp = 0;temp < edge;temp++)
	{
		/*
		**	I think it's necessary to check the returned value
		** of scanf() family.
		*/
		ret = fscanf(fp,"%d %d",&from_v,&to_v);
		if(ret != 2)
		{
			break;
		}

		add_edge(p_graph,from_v,to_v);
	}

	struct visited* p_visited = 
	(struct visited*)malloc(sizeof(struct visited) +\
	sizeof(int)*(p_graph->num_vertex));

	for(temp = 0;temp < p_graph->num_vertex;temp++)
	{
		p_visited->array[temp] = UN_VISITED;
	}	

	print_graph(p_graph);

	/*
	**	Here, we start to DFS.
	*/
	dfs(p_graph,&(p_graph->adjacent[ENTRY_POINT]),p_visited);

	release_graph(p_graph);
	free(p_visited);
	p_visited = NULL;
	fclose(fp);
	return 0;
}
