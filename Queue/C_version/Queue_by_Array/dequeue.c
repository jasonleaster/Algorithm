/*******************************************************
code writer	:	EOF
code date	:	2014.09.13
code file	:	dequeue.c
e-mail		:	jasonleaster@gmail.com

*******************************************************/
#include "queue.h"

int dequeue(struct queue* p_queue)
{
	if(!p_queue)
	{
		printf("%s line:%dCan't init! You passed NULL\
 into this function\n",__FUNCTION__,__LINE__);

		return ;
	}

	if(is_empty(p_queue) == EMPTY_QUEUE)
	{
		printf("ATTENTION! dequeue() failed. \
The queue is EMPTY now.\n");
		return FAILED_RET; 
	}

	int ret = p_queue->array[(p_queue->header)];

	(p_queue->header)--;

	/*
	**	Circular array
	*/
	if(p_queue->header < 0)
	{
		p_queue->header = p_queue->capacity-1;
	}

	(p_queue->size)--;
	
	return ret;
}
