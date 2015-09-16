/************************************************************
code writer	:	EOF
code date	:	2014.09.19
code file	:	merge_sort_test.c

description:
	Code for test function msort() :)

*************************************************************/
#include "merge_sort.h"

int main()
{
	int array[] = {10,12,1,14,6,5,8,15,3,9,7,4,11,13,2};

	int size = sizeof(array)/sizeof(array[0]);

	int tmp = 0;

	int *tmp_array = NULL;
	
	tmp_array = (int*) malloc(sizeof(int)*size);

	if(!tmp_array)
	{
		printf("malloc failed in function %s()\n",__FUNCTION__);
		return 0;
	}

	msort(array,tmp_array,0,size-1);

	free(tmp_array);

	for(tmp = 0;tmp < size;tmp++)
	{
		printf("%5d",array[tmp]);
	}

	printf("\n");

	return 0;
}
