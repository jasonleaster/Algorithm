/*****************************************************************************
code writer : EOF
code date : 2014.03.03
e-mail:jasonleaster@gmail.com
code purpose :
		This is just a test code for stack that I created.
If there is something wrong with my code, please touche me by e-mail.

*****************************************************************************/
#include <stdio.h>
#include "stack.h"

#define ARRAYSIZE 10

int main()
{
	int temp = 0;
	int array[ARRAYSIZE] = {1,2,3,4,5,6,7,8,9,10};
	
	struct node* p_top = NULL;	

	p_top = creat_stack();
	
	for(temp = 0;temp < ARRAYSIZE; temp++)
	{
		push_stack(&p_top,array[temp]);
	}

	for(temp = 0;temp < ARRAYSIZE; temp++)
	{
		pop_stack(p_top);
	}
	
	return 0;
}

