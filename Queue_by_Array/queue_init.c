/*******************************************************
code writer	:	EOF
code date	:	2014.09.13
code file	:	queue_init.c
e-mail		:	jasonleaster@gmail.com

*******************************************************/


/******************************************************************
	You MUST call queue_cap_init() before you call queue_init().
*******************************************************************/
#include "queue.h"

int queue_init(struct queue** pp_queue,int capacity)
{
	if(!pp_queue)
	{
		printf("%s line:%dCan't init! You passed NULL into this function\n",__FUNCTION__,__LINE__);

		return ;
	}
	else
	{
		
		*pp_queue = (struct queue*)malloc(sizeof(struct queue) + capacity*sizeof(int));

		if(! (*pp_queue))
		{
			printf("%s line:%d malloc failed!\n",__FUNCTION__,__LINE__);
			return;
		}
	}
	/**************************************************
		-----------------------
	Input->	tail | | ... | | header -> Output
		-----------------------

		Just think about it, if the tail is before 
	the header, the queue is empty.

		For this reason, I initialized
	 header = 0; tail = 1;

		Don't panic! :)
	***************************************************/

	(*pp_queue)->header   = 0;
	(*pp_queue)->tail     = 1;

	(*pp_queue)->size     = 0;
	(*pp_queue)->capacity = capacity;

	return SUCCESS_RET;
}
