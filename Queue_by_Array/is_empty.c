/*******************************************************
code writer	:	EOF
code date	:	2014.09.13
code file	:	is_empty.c
e-mail		:	jasonleaster@gmail.com

*******************************************************/
#include "queue.h"

int is_empty(struct queue* p_queue)
{
	if(!p_queue)
	{
		printf("%s line:%dCan't init! You passed NULL into this function\n",__FUNCTION__,__LINE__);

		return ;
	}
	
	if(! p_queue->size)
	{
		return EMPTY_QUEUE;	
	}
	else
	{
		return UNEMPTY_QUEUE;
	}
}
