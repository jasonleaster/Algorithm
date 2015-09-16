/*******************************************************
code writer	:	EOF
code date	:	2014.09.13
code file	:	dequeue.c
e-mail		:	jasonleaster@gmail.com

*******************************************************/
#include "queue.h"

int is_full(struct queue* p_queue)
{
	if(!p_queue)
	{
		printf("%s line:%dCan't init! You passed NULL into this function\n",__FUNCTION__,__LINE__);

		return FAILED_RET;
	}

	if((p_queue->size+1) == p_queue->capacity)
	{
		return FULL_QUEUE;
	}
	else
	{
		return UNFULL_QUEUE;
	}
}
