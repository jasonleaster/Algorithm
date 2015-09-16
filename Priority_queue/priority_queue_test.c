/*********************************************************
code writer	:	EOF
code date	:	2014.09.19
code file	:	priority_queue_test.c
e-mail		:	jasonleaster@gmail.com

code description:

	This code would help us to test our implementation
of heap.

*********************************************************/
#include "priority_queue.h"

int main()
{
	int array[] = {10,12,1,14,6,5,8,15,3,9,7,4,11,13,2};

	int size = sizeof(array)/sizeof(array[0]);

	struct heap* p_heap = NULL;

	p_heap = init_heap(size);

	if(!p_heap)
	{
		printf("Inintialize failed!\n");
		return 0;
	}

	build_heap(p_heap,array,size);

	print_heap(p_heap);

	delete_heap(p_heap);

	print_heap(p_heap);

	insert_heap(p_heap,43);

	print_heap(p_heap);

	destroy_heap(p_heap);
	return 0;
}
