/************************************************************
code writer	:	EOF
code date	:	2014.09.19
code file	:	msort.c

*************************************************************/
#include "merge_sort.h"

void msort(int *array,int * tmp_array,int left,int right)
{

	if(!array || !tmp_array)
	{
		printf("You passed NULL in function %s()\n",__FUNCTION__);
		return ;
	}

	if(left > right)
	{
		printf("left %d bigger than right %d\n",left,right);
	}

	int center = 0;

	/*
	**	When left == right, recursion end :)
	*/
	if(left < right)
	{
		center = (left+right)/2;

		msort(array,tmp_array,left,center);
		msort(array,tmp_array,center+1,right);
		merge(array,tmp_array,left,center+1,right);
	}
}
