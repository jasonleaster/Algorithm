/*********************************************************
code writer	:	EOF
code date	:	2014.09.19
code file	:	priority_queue.h
e-mail		:	jasonleaster@gmail.com

code purpose	:	
	Just a header file for my implementation.
	What you should know is that you may call
init_heap() when you want to create a priority queue.
And then you could use build_heap() to create that queue
with your source--@array.

*********************************************************/
#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H

	#include <stdio.h>
	#include <stdlib.h>

	#define EMPTY_HEAP	-1
	#define NOEMPTY_HEAP	 0

	#define FULL_HEAP	 1
	#define NOFULL_HEAP	 0

	struct heap
	{
		int capacity;
		int size;
		/*
		**	ATTENTION! Just a little trick.
		*/
		int element[0];
	};

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
