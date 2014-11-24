/************************************************************
code file	: BFS.h
code writer	: EOF
code date	: 2014.11.22
e-mail		: jasonleaster@gmail.com

code description:
	This file is a header file for out test program.
We are using digraph but not undirected graph in BFS.

************************************************************/

#ifndef _DIJSTRA_H_
#define _DIJSTRA_H_

	#include <stdio.h>
	#include <stdlib.h>

	#define CONNECTED    1
	#define DISCONNECTED 0

	#define SUCCESS  0
	#define FAILED  -1

	/*
	**  Macro for heap
	*/
	#define EMPTY_HEAP	-1
	#define NOEMPTY_HEAP	 0

	#define FULL_HEAP	 1
	#define NOFULL_HEAP	 0

	/*
	**	We use these macro as index for struct table
	*/
	#define KNOW_OFFSET 0 //vertex that have been found
	#define DIST_OFFSET 1 //distance of vertex
	#define PATH_OFFSET 2 //parent vertex of current vertex
	
	#define FOUND	    1
	#define NOT_FOUND   0

	/*
	**	Liitle trick. I use minus one to 
	** represent positive infinite :)
	*/
	#define INFINITE   -1

	#define ENTRY_POINT 3

	struct heap
	{
		int capacity;
		int size;
		/*
		**	ATTENTION! Just a little trick.
		*/
		int element[0];
	};

	struct vertex
	{
		int value;
		int ver_dist;
		struct vertex* next;
		struct vertex* end;
	};

	struct graph
	{
		int num_vertex;
		int num_edge;
	};

	struct table
	{
		int height;
		int width;
		int msg[0];//we store message of table in this array.
	};

	struct graph* init_graph(int vertex,int edge);
	void   release_graph(struct graph* p_graph);
	
	int add_edge(struct graph* p_graph,char from_v,char to_v,int distance);
	int print_graph(struct graph* p_graph);

	/*
	**	Creat and desctory a table which's size is row*col.
	*/
	struct table* init_table(int row,int col);
	void table_print(struct table* p_table);
	void release_table(struct table* p_table);

	/*
	**	I implement some API to use ADT-Heap
	*/

	struct heap* init_heap(int max_size);
	void destroy_heap(struct heap* p_heap);

	void insert_heap(struct heap* p_heap,int element);
	int  delete_heap(struct heap* p_heap);

	void build_heap(struct heap* p_heap,int* array,int size);
	void precolate_down(struct heap* p_heap,int parent);

	int is_empty(struct heap* p_heap);	
	int is_full(struct heap* p_heap);	

	void print_heap(struct heap* p_heap);
#endif
