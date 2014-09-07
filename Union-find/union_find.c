/*********************************************************
code writer	: EOF
code date	: 2014.09.07
code file	: union_find.c
code version	: 1.0
e-mail		: jasonleaster@gmail.com

code purpose	:
	A demo for union-find.

	If there is something wrong with my code, please
touch me by e-mail. Thank you. :-)

**********************************************************/
#include <stdio.h>
#include <malloc.h>

#define SAME 1
#define DIFF 0

#define DEBUG

//----------------------------------------------------
void union_element(int* p_array,int size,int p, int q);
int connected_element(int* p_array,int size,int p,int q);
int root_element(int* p_array,int size,int index);
//----------------------------------------------------

int init_element(int* p_array,int size);

int main()
{
	int num = 0;
	int ret = 0;
	int* all_element = NULL;

	printf("Please input how many number in your union group\n");	

	while(!scanf("%d",&num))
	{
		getchar();
		printf("scanf error, please input again\n");
	}

	all_element = (int*)malloc(sizeof(int) * num);
	
	init_element(all_element,num);
	/*
	**	It's time to test our API
	*/

#ifdef DEBUG
	union_element(all_element,num,4,3);
	union_element(all_element,num,3,8);
	union_element(all_element,num,6,5);
	union_element(all_element,num,9,4);
	union_element(all_element,num,2,1);

	ret = connect_element(all_element,num,0,7);

	if(ret == SAME)
	{
		printf("Y Connected!\n");
	}
	else if (ret == DIFF)
	{
		printf("X Unconnected!\n");
	}

	ret = connect_element(all_element,num,8,9);
	if(ret == SAME)
	{
		printf("Y Connected!\n");
	}
	else if (ret == DIFF)
	{
		printf("X Unconnected!\n");
	}
#endif
	free(all_element);
	all_element = NULL;
	return 0;
}

int root_element(int* p_array,int size,int index)
{
	if(!p_array)
	{
		printf("p_array is NULL!\nNeedless to initialize\n");
		return -1;
	}

	if(index > (size-1))
	{
		printf("'index' bigger than size of array which 'p_array' point to.\n");
		return -1;
	}

	/*
	**	Indexing until we get the root.
	*/
	for(;p_array[index] != index;)
	{
		index = p_array[index];
	}

	return index;
}

void union_element(int* p_array,int size,int p, int q)
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

	int p_union = p_array[p];
	int q_union = p_array[q];

	int tmp = 0;

	/*
	**	Connect the "union-p" into "union-q."
	*/
	p_array[p] = q_union;

}

int connect_element(int* p_array,int size,int p ,int q)
{
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

	if(root_element(p_array,size,p) == root_element(p_array,size,q))
	{
		return SAME;
	}
	else
	{
		return DIFF;
	}
}

int init_element(int* p_array,int size)
{
	if(!p_array)
	{
		printf("p_array is NULL!\nNeedless to initialize\n");
		return -1;
	}

	int tmp = 0;

	/*
	**	Set id of each objects to itself,
	*/
	for(tmp = 0; tmp < size; tmp++)
	{
		p_array[tmp] = tmp;
	}
}
