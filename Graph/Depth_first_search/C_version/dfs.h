/************************************************************
code file	: dfs.h
code writer	: EOF
code date	: 2014.11.22
e-mail		: jasonleaster@gmail.com

code description:
	This file is a header file for out test program.
We abstract the data structure -- Graph here. And we also
declare some useful API to construct out naive graph :)

************************************************************/

#ifndef _DFS_H_
#define _DFS_H_

	#include <stdio.h>
	#include <stdlib.h>

	#define CONNECTED    1
	#define DISCONNECTED 0

	#define SUCCESS  0
	#define FAILED  -1

	#define UN_VISITED 0
	#define VISITED   1

	#define ENTRY_POINT 3

	struct visited
	{
		int array[0];
	};

	struct vertex
	{
		int value;
		struct vertex* next;
		struct vertex* end;
	};

	struct graph
	{
		int num_vertex;
		int num_edge;
		struct vertex adjacent[0];
	};


	void dfs(struct graph* p_graph,struct vertex* p_vertex,struct visited* p_visited);

	struct graph* init_graph(int vertex,int edge);
	void   release_graph(struct graph* p_graph);
	
	int add_edge(struct graph* p_graph,char from_v,char to_v);
	int print_graph(struct graph* p_graph);

#endif
