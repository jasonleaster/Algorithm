/*****************************************************
Code writer	:	EOF
Code date	:	2014.09.13
code file	:	stack_test.c
e-mail		:	jasonleaster@gmail.com

code purpose	:
	This file("stack_test.c") a source file  which
contain a main-function which is used for testing
my stack.

	If there is something wrong with my code, 
please touch me by e-mail. Thank you.

*****************************************************/
#include "stack.h"

int main()
{
	struct stack* my_stack = init_stack();

	int tmp = 0;

	for(tmp = 0; tmp < 10; tmp++)
	{
		printf("%3d ",tmp+1);
		push(my_stack,tmp+1);
	}
	printf("\n");

	for(tmp = 0; tmp < 10; tmp++)
	{
		printf("%3d ",pop(my_stack));
	}
	printf("\n");

	stack_release(my_stack);

	return 0;
}
