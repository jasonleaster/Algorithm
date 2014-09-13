/*****************************************************
Code writer	:	EOF
Code date	:	2014.09.13
code file	:	stack.h
e-mail		:	jasonleaster@gmail.com

code purpose	:
	This file("stack_release.c") a source file
which is used for implementation of stack_release().

	If there is something wrong with my code, 
please touch me by e-mail. Thank you.

*****************************************************/
#include "stack.h"

void stack_release(struct stack* p_stack)
{
	free(p_stack);
}
