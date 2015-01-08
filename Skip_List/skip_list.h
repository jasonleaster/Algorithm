#ifndef _SKIP_LIST_H
#define _SKIP_LIST_H

	#include <stdio.h>
	#include <stdlib.h>

	#define SUCCESS_RET ( 0)
	#define FAILED_RET  (-1)

	struct node
	{
		int data;
		int level;
		struct node next[0];
	};

	/*
	**	Description about members of @struct skip_list:
	**	
	**	@node_numer	: how many node in this skip list
	**
	**	@level	   	: how many pointers are neended in
	**				@struct node header.next
	**
	**	@new_skip_list 	: function pointer which point to 
	**		a function that will initialize a new 
	**		@struct skip_list
	**
	**	@del_skip_list	: function pointer which point to
	**		a function that will release the resource
	**		that the structure have.
	*/
	struct skip_list
	{
		int node_number;
		int level;
		struct skip_list* (*new_skip_list)(void);
		void (*free_skip_list)(struct node*p_skip_list);

		struct node header;
	};

	struct skip_list* init_skip_list(void);
	void release_skip_list(struct skip_list* p_skip_list);

	/*
	** 	This API would be used everytime we inserting a 
	** new node into the skip list.
	*/
	void flush_hp_num(struct skip_list* p_skip_list);
	int node_level(void);

	struct node* init_inserting_num(int number);

	int insert_node(struct skip_list* p_skip_list,struct node* p_node);
	int delete_node(struct skip_list* p_skip_list,struct node* p_node);

#endif
