/*********************************************************
Code writer : EOF
Code file   : stack.h
Code date   : 2014.11.26
Email	    : jasonleaster@gmail.com

Code description:
	
	Here is a implementation of a naive computer
It based on two stack scheme which was found by Dijkstra.

*********************************************************/
#ifndef _STACK_H  
#define _STACK_H 1  
  
	#define EMPTY     0  
	#define NON_EMPTY 1  
	  
	#define ARRAYSIZE 1024

	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>

	struct node  
	{     
	    int data;  
	    struct node* next;  
	};  
	  
	int computer(void);

	struct node* creat_stack(void);
	int push_stack(struct node** pp_top,int number);
	int is_empty(struct node* p_node);
	void release_stack(struct node* p_top);
  
#endif
