/*********************************************************
code writer	:	EOF
code file	:	binary_search.c
code date	:	2014.9.18
e-mail		:	jasonleaster@gmail.com

description:
	You may have to KNOW that the @array was
sequenced from min to max  when you use "binary search".

	If this function find the element , return the
location in the @array, otherwise return -1.

********************************************************/
#include <stdio.h>

int binary_search(int* array,int size,int element)
{
	if(!array)
	{
		printf("You passed NULL into function: %s()\n",__FUNCTION__);
		return -1;
	}

	int low = 0;
	int mid = 0;
	int high= 0;

	for(low = 0,high = size-1;low <= high;)
	{
		mid = (low+high)/2;
		
		if(array[mid] < element)
		{
			low = mid+1;
		}
		else if(array[mid] > element)
		{
			high = mid-1;
		}
		else
		{
			/*
			** 	found that.
			*/
			return mid; 
		}
	}

	return -1;
}
