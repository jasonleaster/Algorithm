/*******************************************************
code writer	:	EOF
code date	:	2014.09.13
code file	:	queue_release.c
e-mail		:	jasonleaster@gmail.com

*******************************************************/
#include "queue.h"

void queue_release(struct queue* p_queue)
{
	if(!p_queue)
	{
		printf("%s line:%dCan't release! You passed NULL into queue_release()\n",__FUNCTION__,__LINE__);

		return ;
	}

	free(p_queue);
}
