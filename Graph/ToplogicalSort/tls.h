/************************************************************
code file	: tls.h
code writer	: EOF
code date	: 2014.11.22
e-mail		: jasonleaster@gmail.com

code description:

************************************************************/

#ifndef _TLS_H_
#define _TLS_H_

	#include <stdio.h>
	#include <stdlib.h>

	#define CONNECTED    1
	#define DISCONNECTED 0

	#define SUCCESS  0
	#define FAILED  -1

	#define QUEUE_SIZE 10
	#define ARRAY_SIZE 20

	#define EMPTY_QUEUE   -1
	#define UNEMPTY_QUEUE  0 

	#define FOUND	    1
	#define NOT_FOUND   0

	#define ENTRY_POINT 3

	struct node
	{
		struct node* previous;
		struct node* next;
		int data;
	};

	struct vertex
	{
		int value;
		int indegree;
		struct vertex* next;
		struct vertex* end;
	};

	struct graph
	{
		int num_vertex;
		int num_edge;
		struct vertex adjacent[0];
	};

	struct table
	{
		int height;
		int width;
		int msg[0];//we store message of table in this array.
	};


	struct graph* init_graph(int vertex,int edge);
	void   release_graph(struct graph* p_graph);
	
	int add_edge(struct graph* p_graph,char from_v,char to_v);
	int print_graph(struct graph* p_graph);

	/*
	**	I implement some API to use ADT-Queue
	*/
	int queue_destory(struct node* p_queue_tail);

	int queue_enter(struct node** pp_queue_header,
			struct node** pp_queue_tail,
			int number);

	int queue_init(struct node** pp_queue_header,
 		       struct node** pp_queue_tail);

	int queue_out(struct node** pp_queue_header,
		      struct node** pp_queue_tail);

	void queue_print(struct node* p_queue_tail);

#endif
