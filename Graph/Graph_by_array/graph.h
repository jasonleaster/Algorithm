/************************************************************
code file	: graph.h
code writer	: EOF
code date	: 2014.11.22
e-mail		: jasonleaster@gmail.com

code description:
	This file is a header file for out test program.
We abstract the data structure -- Graph here. And we also
declare some useful API to construct out naive graph :)

	What we should know is that this graph is a undirected
graph but not digraph ! But it's easy for us to change it 
to be a digraph. So I just remind somebody is reading this
code and say "Don'a panic".

************************************************************/
#ifndef _GRAPH_H_
#define _GRAPH_H_

	#include <stdio.h>
	#include <stdlib.h>

	#define CONNECTED    1
	#define DISCONNECTED 0

	#define SUCCESS  0
	#define FAILED  -1
	struct graph
	{
		int num_vertex;
		int num_edge;

		char adjacent[0];
	};

	struct graph* init_graph(int vertex,int edge);
	void   release_graph(struct graph* p_graph);
	
	int add_edge(struct graph* p_graph,char from_v,char to_v);
	int print_graph(struct graph* p_graph);

#endif
