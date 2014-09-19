/************************************************************
code writer	:	EOF
code date	:	2014.09.19
code file	:	merge.c

*************************************************************/
#include "merge_sort.h"

int merge(int * array,int * tmp_array,int left_pos,int right_pos,int right_end)
{
	if(!array || !tmp_array)
	{
		printf("You passed NULL in function %s()\n",__FUNCTION__);
		return -1;
	}
	
	int tmp 	= 0;
	int tmp_pos	= left_pos;
	int left_end 	= right_pos - 1;
	int num_element = right_end - left_pos + 1;
/*
	It's too expensive to call malloc for costing time.

	int *tmp_array = NULL;

	tmp_array = (int *)malloc(sizeof(int)* num_element);

	if(!tmp_array)
	{
		printf("malloc failed in function :%s()\n",__FUNCTION__);
		return 0;
	}
*/
	while(left_pos <= left_end && right_pos <= right_end)
	{
		if(array[left_pos] <= array[right_pos])
		{
			tmp_array[tmp_pos++] = array[left_pos++];
		}
		else
		{
			tmp_array[tmp_pos++] = array[right_pos++];
		}
	}
	
	while(left_pos <= left_end)
	{
		tmp_array[tmp_pos++] = array[left_pos++];
	}

	while(right_pos <= right_end)
	{
		tmp_array[tmp_pos++] = array[right_pos++];	
	}

	for(tmp = 0;tmp < num_element;tmp++,right_end--)
	{
		array[right_end] = tmp_array[right_end];
	}

/*
	free(tmp_array);	
*/

	return 0;
}
