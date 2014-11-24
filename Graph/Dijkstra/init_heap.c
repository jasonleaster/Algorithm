/*********************************************************
code writer	:	EOF
code date	:	2014.09.19
code file	:	init_heap.c
e-mail		:	jasonleaster@gmail.com

code purpose	:	

	@max_size : what's the size of the heap that you
		    want to create it ?

	This function would return a pointer which point 
to the heap that you created.

*********************************************************/
#include "priority_queue.h"

struct heap* init_heap(int max_size)
{
	if(max_size < 0)
	{
		return NULL;
	}

	struct heap* p_heap = NULL;

	p_heap = (struct heap*)malloc(sizeof(int)*(max_size+1) + sizeof(struct heap));

	if(!p_heap)
	{
		printf("malloc failed in function %s()!\n",__FUNCTION__);
		return NULL;
	}

	p_heap->capacity = max_size;
	p_heap->size 	 = 0;
	
	return p_heap;
}
