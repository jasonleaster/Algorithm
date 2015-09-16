/*********************************************************
code writer	:	EOF
code date	:	2014.09.19
code file	:	is_empty.c
e-mail		:	jasonleaster@gmail.com

*********************************************************/
#include "priority_queue.h"

int is_empty(struct heap* p_heap)
{

	if(!p_heap)
	{
		printf("p_heap is NULL in function %s()\n",__FUNCTION__);

		return -1;
	}

	if(!p_heap->size)
	{
		return EMPTY_HEAP;
	}
	
	return NOEMPTY_HEAP;
}
