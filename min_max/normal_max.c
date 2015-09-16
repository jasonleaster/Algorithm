/***************************************************
code writer	:	EOF
code date	:	2014.09.21
code file	:	normal_max.c
e-mail		:	jasonleaster@gmail.com

code description:
	
	A normal way to find max value in array.

****************************************************/
#include <stdio.h>

void max_min(int* array,int size,int* max)
{
	int tmp = 0;

	for(tmp = 0,*max = array[0];tmp < size;tmp++)
	{
		*max = *max > array[tmp] ? *max : array[tmp];
	}
}

int main()
{
	int array[10] = {2,3,7,1,9,6,4,5,8,0};

	int size = sizeof(array)/sizeof(array[0]);

	int tmp = 0;
	int max = 0;

	for(tmp = 0;tmp < size;tmp++)
	{
		printf("%3d",array[tmp]);
	}

	printf("\n");

	max_min(array,size,&max);

	printf("max:%4d\n",max);

	return 0;
}
