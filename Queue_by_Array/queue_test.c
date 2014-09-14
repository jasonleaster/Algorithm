/*******************************************************
code writer	:	EOF
code date	:	2014.09.13
code file	:	queue_test.c
e-mail		:	jasonleaster@gmail.com

*******************************************************/
#include "queue.h"

int main()
{
	struct queue* my_queue = NULL;

	if(queue_init(&my_queue,QUEUE_SIZE) < 0)
	{
		return 0;
	}

	enqueue(my_queue,1);
	enqueue(my_queue,2);
	enqueue(my_queue,3);

	printf("dequeue: %d\n",dequeue(my_queue));
	printf("dequeue: %d\n",dequeue(my_queue));
	printf("dequeue: %d\n",dequeue(my_queue));

	/*
	**	Deliberately, I do the dequeue() more than
	** enqueue() one time. :)
	*/
	printf("dequeue: %d\n",dequeue(my_queue));

	queue_release(my_queue);

	return 0;
}
