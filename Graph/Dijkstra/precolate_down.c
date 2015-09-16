/*********************************************************
code writer	:	EOF
code date	:	2014.09.19
code file	:	precolate_down.c
e-mail		:	jasonleaster@gmail.com

code purpose	:	

	This is a implementation of precolate_down() which
use recursion.

*********************************************************/
#include "priority_queue.h"

void precolate_down(struct heap* p_heap,int parent)
{
	/*
	**	If we got the last parent, precolate_down() end.
	*/
	if(2*parent > p_heap->size)
	{
		return;
	}
	
	int tmp = 0;
	int foo = 0;
	int min = 0;
	int right_child = 0;
	int left_child	= 0;

	tmp = p_heap->element[parent];
		
	foo         = p_heap->element[parent];
	left_child  = p_heap->element[2*parent];

	/*
	**	If we got the last parent and the size of
	** heap is even. This means that the child of the 
	** last parent is just only one.Here is the method
	** to process this situation.	
	*/
	if(p_heap->size %2 == 0 && 2*parent == p_heap->size)
	{
		if(foo > min)
		{

			tmp = p_heap->element[parent];
			p_heap->element[parent] = p_heap->element[2*parent];
			p_heap->element[2*parent] = tmp;
		}
		return ;
	}

	/*
	** If parent have two child.
	*/
	right_child = p_heap->element[2*parent+1];

	min = left_child < right_child	? left_child : right_child;

	if(foo > min)
	{
		if(right_child > left_child)
		{
			tmp = p_heap->element[parent];
			p_heap->element[parent] = p_heap->element[2*parent];
			p_heap->element[2*parent] = tmp;

			precolate_down(p_heap,2*parent);

		}
		else
		{
			tmp = p_heap->element[parent];
			p_heap->element[parent] = p_heap->element[2*parent+1];
			p_heap->element[2*parent+1] = tmp;
		
			precolate_down(p_heap,2*parent+1);
		}
	}
}
