/*********************************************************
code writer	:	EOF
code date	:	2014.09.19
code file	:	destroy_heap.c
e-mail		:	jasonleaster@gmail.com

code description:

	**NEVER** forget to call this function to free out
memory which p_heap point to.

*********************************************************/
#include "priority_queue.h"

void destroy_heap(struct heap* p_heap)
{
	if(!p_heap)
	{
		printf("malloc failed in function %s()!\n",__FUNCTION__);
		return ;
	}
	
	free(p_heap);
}
