/*********************************************************
code writer	:	EOF
code date	:	2014.09.19
code file	:	delete_heap.c
e-mail		:	jasonleaster@gmail.com

*********************************************************/

#include "priority_queue.h"

int delete_heap(struct heap* p_heap)
{
	if(!p_heap)
	{
		printf("malloc failed in function %s()!\n",__FUNCTION__);
		return -1;
	}

	/*
	**	You have to know that heap data get start from
	** element[1] which is just for simplicty to implement
	** heap in array.
	*/
	int min_element  = p_heap->element[1];
	int last_element = p_heap->element[p_heap->size--];

	int me    = 0;
	int child = 0;
	
	for(me = 1;me*2 < p_heap->size; me = child)
	{
		child = me*2;

		/*
		**	Make sure that child index into the smaller one
		** between the right child and the left child.
		*/
		if(child != p_heap->size && p_heap->element[child+1]
					  < p_heap->element[child])
		{
			child++;
		}

		if(last_element > p_heap->element[child])
		{
			p_heap->element[me] = p_heap->element[child];
		}
		else
		{
			break;
		}
	}

	p_heap->element[me] = last_element;
	return min_element;
}
