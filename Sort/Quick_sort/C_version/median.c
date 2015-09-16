/************************************************
code writer	:	EOF
code date	:	2014.09.20
code file	:	median.c
e-mail		:	jasonleaster@gmail.com

************************************************/
int median(int* array,int left,int right)
{
	int center = (left+right)/2;

	if(array[left] > array[right])
	{
		swap(&array[left],&array[right]);
	}

	if(array[left] > array[center])
	{
		swap(&array[left],&array[center]);
	}

	if(array[center] > array[right])
	{	
		swap(&array[center],&array[right]);
	}

	/*
	**	There are three if-statement here,
	** just make sure that :
	**	A[left] <= A[center] <= A[right]
	*/

	/*
	**	Hide pivot
	*/
	swap(&array[center],&array[right]);

	return array[right];
}
