/*********************************************************
Code writer : EOF
Code file   : stack.h
Code date   : 2014.11.27
Email	    : jasonleaster@gmail.com

Code description:
	
	Here is a implementation of a naive computer
It based on two stack scheme which was found by Dijkstra.

*********************************************************/
#ifndef _STACK_H  
#define _STACK_H 1  
  
	#define EMPTY     0  
	#define NON_EMPTY 1  

	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>


	struct node  
	{     
		int data;  
	    	struct node* next;  
	};  

	struct string
	{
		/*
		** The size of this object
		*/
		int size;

		/*
		** The length of string which is in this object
		*/
		int length;

		/*
		**	Method for this object to read meassage from 
		** Input--stream.
		*/
		struct string* (*read)(struct string*p_string);

		/*
		**	Method for release thid object
		*/
		void (*release)(struct string* p_string);

		char   str[0];	
	};
  
	int computer(void);
	struct string* new_string(void);
	struct string* str_read(struct string* p_string);
	void           del_string(struct string* p_string);

	struct node* creat_stack(void);
	int push_stack(struct node** pp_top,int number);
	int is_empty(struct node* p_node);
	void release_stack(struct node* p_top);
  
#endif
