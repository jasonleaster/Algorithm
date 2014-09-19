#ifndef _MERGE_SORT_H
#define _MERGE_SORT_H

	#include <stdio.h>
	#include <stdlib.h>	

	int merge(int * array,int * tmp_array,int left_pos,int right_pos,int right_end);
	
	void msort(int *array,int * tmp_array,int left,int right);

#endif
