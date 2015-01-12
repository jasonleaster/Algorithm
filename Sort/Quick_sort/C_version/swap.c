/************************************************
code writer	:	EOF
code date	:	2014.09.20
code file	:	swap.c
e-mail		:	jasonleaster@gmail.com

************************************************/
#include "quick_sort.h"

void swap(int* x,int* y)
{
	/*
	** Don't panic :)
	*/
	*y = *x - *y;

	*x = *x - *y;

	*y = *x + *y;
}
