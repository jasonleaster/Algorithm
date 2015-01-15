
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

int randomized_partition(int* array,int right,int left)
{
	if(!array)
	{
		printf("You passed NULL into function %s()\n",__FUNCTION__);
		return ;
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
			/*
			**	Restore pivot
			*/
			swap(&array[smaller_region_index],&array[right]);
			return bigger_region_index;
		}

	}

}

int randomized_selected(int *array,int left,int right,int i_th)
{
	if(left == right)
	{
		return array[left];
	}

	int q = 0;

	q = randomized_partition(array,left,right);

	int k_th = 0;

	k_th = q - left + 1;

	if(i_th == k_th)
	{
		return array[q];
	}
	else if(i_th < k_th)
	{
		randomized_selected(array,left,q-1,i_th);
	}
	else
	{
		randomized_selected(array,q+1,i_th - k_th);
	}
}
