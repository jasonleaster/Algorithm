/*********************************************************
code writer	:	EOF
code date	:	2014.09.19
code file	:	build_heap.c
e-mail		:	jasonleaster@gmail.com

code purpose	:
	
	@p_heap : A pointer which point to our heap.
	@array  : A pointer which point to our input-data
		  which we want to fill heap with it.
	@size	: The size of our array.

*********************************************************/
#include "priority_queue.h"

void build_heap(struct heap* p_heap,int* array,int size)
{
	if(!p_heap || !array)
	{
		printf("In function: %s() p_heap: %p array: %p\n",__FUNCTION__,p_heap,array);
		return ;
	}

	p_heap->size = size;

	int index  = 0;
	int tmp	   = 0;
	int foo    = 0;
	int min	   = 0;

	int parent 	= 0;
	int right_child = 0;
	int left_child  = 0;
	
	for(index = 0; index < size ;index++)
	{
		p_heap->element[index+1] = array[index];
	}

	for(parent = size/2; parent > 0; parent--)
	{
		precolate_down(p_heap,parent);
	}
}
