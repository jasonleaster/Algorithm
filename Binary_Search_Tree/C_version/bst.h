/*******************************************************************************
* code writer: EOF
* Date : 2014.02.20
* Update: 2015.01.26
* code purpose:
		This code is  for header file -- bst.h(Binary_Search_Tree)
*e-mail:jasonleaster@gmail.com

If there somthing wrong with my code, please touch me by e-mail.Thank you!
*****************************************************************************/
#ifndef _BST_H
#define _BST_H 


#include<stdio.h>
#include<stdlib.h>

//definition for node structure
struct node
{
	int data;
	struct node* leftchild;	
	struct node* rightchild;
	struct node* parent;
};

//declaration for delete_note function
int delete_node(struct node* p_node,int number);

//declaration for insert_note function
struct node *insert_node(struct node* p_node,
                         struct node *p_parent,
                         int number);

//declaration for print_node function
int print_node(struct node* p_node);

//declaration for free_tree function
void free_tree(struct node* p_node);

//declaration for insert_for_delete function
int insert_for_delete(struct node* p_node,struct node* tmp);

#endif

