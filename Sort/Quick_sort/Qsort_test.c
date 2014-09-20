/************************************************
code writer	:	EOF
code date	:	2014.09.20
code file	:	Qsort_test.c
e-mail		:	jasonleaster@gmail.com

************************************************/
#include "quick_sort.h"

int main()
{
	int array[] = {13,81,92,43,31,65,31,57,26,75,0};

	int size = sizeof(array)/sizeof(array[0]);
	int tmp = 0;

	Qsort(array,size);
	
	for(tmp = 0;tmp < size;tmp++)
	{
		printf("%4d",array[tmp]);
	}
	printf("\n");

	return 0;
}
