/***************************************************
code writer	:	EOF
code date	:	2014.09.21
code file	:	min_max.c
e-mail		:	jasonleaster@gmail.com

code description:
	
	A faster way to find min and max value in 
data array.

****************************************************/
#include <stdio.h>

void max_min(int* array,int size,int* min,int* max)
{
	int tmp = 0;

	for(tmp = 0,*min = array[0],array[1];tmp < size;tmp += 2)
	{
		if(array[tmp] < array[tmp+1])
		{
			*min = *min < array[tmp]   ? *min : array[tmp];
			*max = *max > array[tmp+1] ? *max : array[tmp+1];
		}
		else
		{
			*min = *min < array[tmp+1]   ? *min : array[tmp+1];
			*max = *max > array[tmp]     ? *max : array[tmp];
		}
	}
}

int main()
{
	int array[10] = {2,3,7,1,9,6,4,5,8,0};

	int size = sizeof(array)/sizeof(array[0]);

	int tmp = 0;
	int min = 0;
	int max = 0;

	for(tmp = 0;tmp < size;tmp++)
	{
		printf("%3d",array[tmp]);
	}

	printf("\n");

	max_min(array,size,&min,&max);

	printf("min:%4d max:%4d\n",min,max);

	return 0;
}
