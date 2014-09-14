/***************************************************
code writer	:	EOF
code date	:	2014.09.14
code file	:	insertion_sort.c
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

int insertion_sort(struct element* element)
{
	if(!element)
	{
		printf("element is NULL!\n");
		return 0;
	}

	int tmp_1       = 0;
	int tmp_2       = 0;
	int swap	= 0;

	for(tmp_1 = 0;tmp_1 < element->size; tmp_1++)
	{
		for(tmp_2 = tmp_1;tmp_2-1 > 0 && tmp_2 > 0; tmp_2--)
		{
			if(element->array[tmp_2] < element->array[tmp_2-1])
			{
				
				swap		      = element->array[tmp_2];
				element->array[tmp_2] = element->array[tmp_2-1];
				element->array[tmp_2-1] = swap;
			}
			else
			{
				break;
			}
		}	

	}

	return 0;
}
#ifdef DEBUG

void print_element(struct element* const element)
{

	if(!element)
	{
		printf("Function:%s line:%d Somebody passed NULL into print_element\n",__FUNCTION__,__LINE__);
		return ;
	}

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

	insertion_sort(&test_element);

	printf("Before sorting\n");
	print_element(&test_element);

	return 0;
}
#endif
