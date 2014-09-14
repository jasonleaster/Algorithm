/***************************************************
code writer	:	EOF
code date	:	2014.09.14
code file	:	selection_sort.c
e-mail		:	jasonleaster@gmail.com

******************************************************/
#include <stdio.h>

#define DEBUG
#define ARRAY_SIZE 6

struct element
{
	int array[ARRAY_SIZE];
	int size;	
};

int selection_sort(struct element* element)
{
	if(!element)
	{
		printf("element is NULL!\n");
		return 0;
	}

	int tmp_1       = 0;
	int tmp_2       = 0;
	int swap	= 0;
	int min_index   = 0;

	for(tmp_1 = 0;tmp_1 < element->size;tmp_1++)
	{
		min_index = tmp_1;

		for(tmp_2 = tmp_1;tmp_2 < element->size;tmp_2++)
		{
			if(element->array[min_index] > element->array[tmp_2])
			{
				min_index = tmp_2;
			}
		}	
	
		swap =  element->array[min_index];
		element->array[min_index] = element->array[tmp_1];
		element->array[tmp_1] = swap;

	}
	return 0;
}
#ifdef DEBUG

void print_element(struct element* const element)
{
	int tmp = 0;

	for(tmp = 0;tmp < element->size; tmp++)
	{
		printf("%d ",element->array[tmp]);
	}

	printf("\n");
}

int main()
{
	/*
	** Initialize this element.
	*/
	struct element test_element = {
					{1,4,9,6,3,2},
					ARRAY_SIZE,
				       };

	printf("Before sorting\n");
	print_element(&test_element);

	selection_sort(&test_element);

	printf("Before sorting\n");
	print_element(&test_element);

	return 0;
}
#endif
