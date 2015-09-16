/*********************************************************
code writer	: EOF
code date	: 2014.09.07
code file	: weighted_QU.c
code version	: 1.0v
e-mail		: jasonleaster@gmail.com

code purpose	:
	A demo for weighted quick-union.

	If there is something wrong with my code, please
touch me by e-mail. Thank you. :-)

**********************************************************/
#include <stdio.h>
#include <malloc.h>

#define SAME 1
#define DIFF 0

#define INIT_DEPTH 1

#define DEBUG

//#define DEBUG_DEPTH

struct union_element
{
	int index;
	int depth;
};

//-------------------------------------------------------------------------------------
int  quick_root_element(struct union_element* p_array,int size,int index);
void quick_union_element(struct union_element* p_array,int size,int p, int q);
int  quick_connected_element(struct union_element* p_array,int size,int p,int q);
//-------------------------------------------------------------------------------------

int init_element(struct union_element* p_array,int size);
int print_union(struct union_element* p_array,int size);

int main()
{
	int num = 0;
	int ret = 0;
	struct union_element* all_element = NULL;

	printf("Please input how many number in your union group\n");	

	while(!scanf("%d",&num))
	{
		getchar();
		printf("scanf error, please input again\n");
	}

	all_element = (struct union_element*)malloc(sizeof(struct union_element) * num);

	if(init_element(all_element,num) < 0)
	{
		return 0;
	}

#ifdef DEBUG

	if(num < 10)
	{
		return 0;
	}

	quick_union_element(all_element,num,2,9);
	quick_union_element(all_element,num,4,3);
	quick_union_element(all_element,num,2,4);
	quick_union_element(all_element,num,5,6);

	printf("Before union(6,9)\n");

	print_union(all_element,num);

	printf("After union(6,9)\n");
	quick_union_element(all_element,num,6,9);

	print_union(all_element,num);


#endif

	free(all_element);
	all_element = NULL;
	return 0;
}

/*
**	There are two different print_union() you could use.
** If you want to debug and use the second one, just change
** Macro"#ifdef" into "#ifndef". :)
*/
#ifndef DEBUG
int print_union(struct union_element* p_array,int size)
{
	if(!p_array)
	{
		printf("function:%s line:%d 'p_array' is NULL\n",__FUNCTION__,__LINE__);

		return -1;
	}
	
	int tmp = 0;
	for(tmp = 0; tmp < size;tmp++)
	{
		printf("%2d ",p_array[tmp].index);
	}

	printf("\n");
}
#else
int print_union(struct union_element* p_array,int size)
{
	int ret_tmp = 0;
	int ret_grp = 0;

	if(!p_array)
	{
		printf("function:%s line:%d 'p_array' is NULL\n",__FUNCTION__,__LINE__);

		return -1;
	}

	int tmp = 0;
	int grp = 0;

	for(grp = 0;grp < size; grp++)
	{
		for(tmp = 0;tmp < size; tmp++)
		{
			if(tmp == 0)
			{
				printf("######### group :%d ##########\n",grp);
			}

			ret_tmp = quick_root_element(p_array,size,tmp);
			ret_grp = quick_root_element(p_array,size,grp);
	
			if(ret_grp != grp)
			{
				/*
				**	We need not to print out the same message on the screen.
				*/
				break;
			}

			/*
			**	Check error.
			*/
			if(ret_tmp < 0 || ret_grp < 0)
			{
				return 0;
			}

			if(ret_tmp == ret_grp)
			{
				printf("%3d ",tmp);
			}
		}

		printf("\n");
	}

	return 0;
}
#endif

int quick_root_element(struct union_element* p_array,int size,int index)
{
	if(!p_array)
	{
		printf("p_array is NULL!\n");
		return -1;
	}

	if(index > (size-1))
	{
		printf("'index' bigger than size of array which 'p_array' point to.\n");
		return -1;
	}

	for(;p_array[index].index != index;)
	{
		index = p_array[index].index;
	}

	return index;
}

int init_element(struct union_element* p_array,int size)
{
	if(!p_array)
	{
		printf("p_array is NULL!\nNeedless to initialize\n");
		return -1;
	}

	int tmp = 0;

	for(tmp = 0; tmp < size; tmp++)
	{
		p_array[tmp].index = tmp;
		p_array[tmp].depth = INIT_DEPTH;
	}

	return 0;
}

void quick_union_element(struct union_element* p_array,int size,int p, int q)
{
	if(!p_array)
	{
		printf("function:%s line: %d p_array is NULL\n",__FUNCTION__,__LINE__);
		return ;
	}

	if(p > (size-1) || q > (size-1))
	{
		printf("index 'p' 'q' are bigger than the max size of array\n");
		printf("p: %3d q: %3d",p,q);
		return ;
	}

	int root_p_union = 0;

	if((root_p_union = quick_root_element(p_array,size,p)) < 0)
	{
		return;
	}

	int root_q_union = 0;

	if((root_q_union = quick_root_element(p_array,size,q)) < 0)
	{
		return;
	}

#ifdef DEBUG_DEPTH
	printf("\n\n%3d ",p_array[root_p_union].depth);
	printf("%3d \n\n",p_array[root_q_union].depth);
#endif

	/*
	**	Weighting and unioning !
	*/
	if(p_array[root_q_union].depth < p_array[root_p_union].depth)
	{
		p_array[root_q_union].index  = root_p_union;
		p_array[root_p_union].depth += p_array[root_q_union].depth;
	}
	else
	{
		p_array[root_p_union].index  = root_q_union;
		p_array[root_q_union].depth += p_array[root_p_union].depth;
	}

}

int quick_connect_element(struct union_element* p_array,int size,int p ,int q)
{
	int ret_p = 0;
	int ret_q = 0;

	if(!p_array)
	{
		printf("function:%s line: %d p_array is NULL\n",__FUNCTION__,__LINE__);
		return -1;
	}

	if(p > (size-1) || q > (size-1))
	{
		printf("index 'p' 'q' are bigger than the max size of array\n");
		printf("p: %3d q: %3d",p,q);
		return ;
	}

	ret_p = quick_root_element(p_array,size,p);
	ret_q = quick_root_element(p_array,size,q);

	if(ret_p < 0|| ret_q < 0)
	{
		return -1;
	}
	else if(ret_q == ret_p)
	{
		return SAME;
	}
	else
	{
		return DIFF;
	}
}

