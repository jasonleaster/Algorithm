/****************************************************************
code file	: test_graph.c
code writer	: EOF
code date	: 2014.11.22
e-mail		: jasonleaster@gmail.com

code description:
	
	This test program is used for testing dijstra.

*****************************************************************/
#include "dijstra.h"

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

	int from_v   = 0;
	int to_v     = 0;
	int distance = 0;

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
		ret = fscanf(fp,"%d %d %d",&from_v,&to_v,&distance);
		if(ret != 3)
		{
			printf("scanf() error!\n");
			break;
		}

		add_edge(p_graph,from_v,to_v,distance);
	}

		
	struct table* p_table =  init_table(vertex,3);


	print_graph(p_graph);
	release_table(p_table);
	release_graph(p_graph);
	fclose(fp);
	return 0;
}
