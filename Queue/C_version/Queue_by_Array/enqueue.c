/*******************************************************
code writer	:	EOF
code date	:	2014.09.13
code file	:	enqueue.c
e-mail		:	jasonleaster@gmail.com

*******************************************************/

#include "queue.h"

void enqueue(struct queue* p_queue,int num)
{
	if(!p_queue)
	{
		printf("%s line:%dCan't init! You passed NULL into this function\n",__FUNCTION__,__LINE__);

		return ;
	}
	
	if(is_full(p_queue) == FULL_QUEUE)
	{
		printf("ATTENTION! enqueue() failed. The queue is FULL now.\n");

		return ;
	}

	(p_queue->tail)--;

	/*
	**	Circular array
	*/
	if(p_queue->tail < 0)
	{
		p_queue->tail = p_queue->capacity-1;
	}

	(p_queue->size)++;

	p_queue->array[p_queue->tail] = num;
}
