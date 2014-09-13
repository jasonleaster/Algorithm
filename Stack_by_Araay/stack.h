/*****************************************************
Code writer	:	EOF
Code date	:	2014.09.13
code file	:	stack.h
e-mail		:	jasonleaster@gmail.com

code purpose	:
	This file("stack.h") a header file  for
sources file which are used for a implementation
of ADT-stack in array-type.

	If there is something wrong with my code, 
please touch me by e-mail. Thank you.

*****************************************************/
#ifndef _STACK_H
#define _STACK_H 1

	#include <stdio.h>
	#include <stdlib.h>

	#define FAILED_RET   -1
	#define SUCCESS_RET   0

	#define FULL_STACK    1
	#define UNFULL_STACK  0

	#define EMPTY_STACK   1
	#define UNEMPTY_STACK 0

	#define STACK_SIZE 1024

	/*
	**	This is a beautiful abstract of "stack".
	*/
	struct stack
	{
		int top_of_stack;
		int stack_size;
		int array[STACK_SIZE];
	};

	struct stack* init_stack(void);
	void stack_release(struct stack* p_stack);

	int pop(struct stack* p_stack);
	int push(struct stack* p_stack,int num);

	int is_empty(struct stack* p_stack);
	int is_full(struct stack* p_stack);

#endif
