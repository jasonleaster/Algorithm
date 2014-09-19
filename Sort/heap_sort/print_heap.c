/*********************************************************
code writer	:	EOF
code date	:	2014.09.19
code file	:	print_heap.c
e-mail		:	jasonleaster@gmail.com

code description:

	Just print out the current heap that @p_heap point
to.

*********************************************************/
#include "priority_queue.h"

void print_heap(struct heap* p_heap)
{
	if(!p_heap)
	{
		printf("You passed NULL in function %s()\n",__FUNCTION__);
		return ;
	}

	printf("The capacity of heap : %d\n",p_heap->capacity);
	printf("The size of heap:%d\n",p_heap->size);

	int index = 0;
	int tmp	  = 1;

	for(index = 0,tmp = 2;index < p_heap->size;index++)
	{
		printf("%d ",p_heap->element[index+1]);

		if(index == 0)
		{
			printf("\n");
		}
		else if(index == tmp)
		{
			tmp += 1<<tmp;

			printf("\n");
		}
	}

	printf("\n");
}
