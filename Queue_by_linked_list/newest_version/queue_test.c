/***********************************************************
code writer : EOF
code date : 2014.03.07
e-mail: jasonleaster@gmail.com
code purpose:
		Just a test source file for queue. I would be
happy, if my code will help you to know what is queue.

We assume that:

Input data ---> tail | | |queue| | |  header ---> Output data

If something wrong with my code, please touch me by e-mail.

************************************************************/
#include <stdio.h>
#include "queue.h"

int main()
{
	int temp = 0;

	int array[ARRAY_SIZE] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

	struct node* p_queue_tail;
	struct node* p_queue_header;
	
	queue_init(&p_queue_header,&p_queue_tail);	

	for(temp = 0; temp < ARRAY_SIZE; temp++)
	{
		if(SUCCESS != queue_enter(&p_queue_header,&p_queue_tail,array[temp]))
		{
			printf("enter error!\n");
			queue_destory(p_queue_tail);
			return 0;
		}
	}

	queue_print(p_queue_tail);

	printf("queue out:%d\n",queue_out(&p_queue_header));

	printf("queue out:%d\n",queue_out(&p_queue_header));
	
	queue_print(p_queue_tail);

	queue_destory(p_queue_tail);

	return 0;
}

