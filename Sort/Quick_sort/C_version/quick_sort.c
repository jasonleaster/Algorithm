/************************************************
code writer	:	EOF
code date	:	2014.09.20
code file	:	quick_sort.c
e-mail		:	jasonleaster@gmail.com

************************************************/
#include "quick_sort.h"

#define CUT_OFF 3

void quick_sort(int* array,int left,int right)
{
	if(!array)
	{
		printf("You passed NULL into function %s()\n",__FUNCTION__);
		return;
	}

	if(left > right)
	{
		printf("Parameter @left and @right error!\
 @left should less or equal to @right\n");
		return ;
	}

	int pivot = 0;
	int smaller_region_index = left;
	int bigger_region_index  = right-1;

	int tmp   = 0;
	int index = 0;
	int sentinel = 0;

	if(left + CUT_OFF <= right)
	{
		pivot = median(array,left,right);

		for(smaller_region_index -=1, bigger_region_index += 1;;)
		{
			while(array[++smaller_region_index] < pivot)
			{
				/*
				** DON'T do ++smaller_region_index here!
				** That must be hide a bug!
				*/
			}

			while(array[--bigger_region_index] > pivot)
			{
				/*
				** DON'T do --bigger_region_index here!
				** That must be hide a bug!
				*/
			}

			if(smaller_region_index < bigger_region_index)
			{
				swap(&array[smaller_region_index],&array[bigger_region_index]);
			}
			else
			{
				break;
			}

		}

		/*
		**	Restore pivot
		*/
		swap(&array[smaller_region_index],&array[right]);
		if(left == smaller_region_index)
		{
			quick_sort(array,left,smaller_region_index);	
		}
		else
		{
			quick_sort(array,left,smaller_region_index-1);	
		}

		if(right == bigger_region_index)
		{
			quick_sort(array,bigger_region_index,right);
		}
		else
		{
			quick_sort(array,bigger_region_index+1,right);
		}
	}
	else
	{
		/*
		**	Insertion sort.
		*/
		tmp 	= 0;
		index 	= 0;

		for(tmp = left; tmp <= right;tmp++)
		{
			sentinel = array[tmp];
			for(index = tmp;array[index-1] > sentinel &&  index > left;index--)
			{
				array[index] = array[index - 1];
			}
			array[index] = sentinel;
		}		
	}
}

void Qsort(int* array,int size)
{
	quick_sort(array,0,size-1);
}
