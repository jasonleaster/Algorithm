/***************************************************
code writer	:	EOF
code file	:	heap_sort.c
code date	:	2014.09.19
e-mail		:	jasonleaster@gmail.com

description	:
	This is the kernel of the heap-sort.

*****************************************************/
#include "priority_queue.h"

#define DEBUG

int heap_sort(int* array,int size)
{
	struct heap* p_heap = NULL;

	p_heap = init_heap(size);
	
	if(!p_heap)
	{
		printf("initialization failed in function %s() !\n",__FUNCTION__);

		return -1;
	}

	build_heap(p_heap,array,size);

	int tmp = 0;

	for(tmp = size;tmp > 0;tmp--)
	{
		p_heap->element[tmp] = delete_heap(p_heap);
	}

	p_heap->size = size;
#ifdef DEBUG

	for(tmp = 1;tmp <=size;tmp++)
	{
		printf("%4d",p_heap->element[tmp]);
	}

	printf("\n");

#endif

	destroy_heap(p_heap);

	return 0;
}

#ifdef DEBUG
int main()
{
	int array[] = {16,14,10,8,7,9,3,2,4,1};

	int size = sizeof(array)/sizeof(array[0]);

	heap_sort(array,size);

	return 0;
}
#endif
