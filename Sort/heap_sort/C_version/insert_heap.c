/*********************************************************
code writer	:	EOF
code date	:	2014.09.19
code file	:	insert_heap.c
e-mail		:	jasonleaster@gmail.com

code purpose	:	
	
	Just call this function and insert @element into
heap that @p_heap point to.

*********************************************************/
#include "priority_queue.h"

void insert_heap(struct heap* p_heap,int element)
{
	if(!p_heap)
	{
		printf("p_heap is NULL in function %s\n",__FUNCTION__);
		return ;
	}

	int child = 0;
	/*
	**	Percolate up
	*/
	for(child = ++p_heap->size; p_heap->element[child/2] > element; child/=2)
	{
		p_heap->element[child] = p_heap->element[child/2];
	}
	
	p_heap->element[child] = element;
}
