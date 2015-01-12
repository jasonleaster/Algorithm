#ifndef _QUICK_SORT_H
#define _QUICK_SORT_H
	#include <stdio.h>
	#include <stdlib.h>

	void swap(int* x,int* y);

	int median(int* array,int left,int right);

	void quick_sort(int* array,int left,int right);

	void Qsort(int* array,int size);

#endif
