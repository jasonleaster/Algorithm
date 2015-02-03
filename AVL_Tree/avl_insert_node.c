/*****************************************************************************************
code writer : EOF
code date : 2014.03.01
e-mail: jasonleaster@gmail.com

code purpose:
		implementation of function avl_insert_node
If something could be changed into better situation, please touch me by e-mail. Thank you!

******************************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "avl_tree.h"

struct node* avl_insert_node(struct node** pp_node, 
                             struct node* p_parent,
                             int number)
{
	if((*pp_node) == NULL)
	{
		(*pp_node) = (struct node*)malloc(sizeof(struct node));
		if((*pp_node) == NULL)
		{
			printf("malloc faild!\n");
			return 0;
		}

		//initilization for new node
		(*pp_node)->data = number;
		(*pp_node)->height = 0;
		(*pp_node)->parent = p_parent;
		(*pp_node)->rightchild = NULL;
		(*pp_node)->leftchild  = NULL;
		
	}
	else if((*pp_node)->data > number)//right_rotation
	{
		(*pp_node)->leftchild = avl_insert_node(&((*pp_node)->leftchild),(*pp_node),number);
		//Now, we have inserted a node and interrupt the balance of the tree. So, we should rebalance the tree.What we should do is rotation.
		
		(*pp_node)->height = (avl_height((*pp_node)->leftchild) > avl_height((*pp_node)->rightchild) ?\
				      avl_height((*pp_node)->leftchild) : avl_height((*pp_node)->rightchild))+1;
		
		if(abs(avl_height((*pp_node)->rightchild) - avl_height((*pp_node)->leftchild))  == 2)
		{
			if((*pp_node)->leftchild->data > number)
			{
				(*pp_node) = single_rotation_with_right(*pp_node);
			}
			else if((*pp_node)->leftchild->data < number)
			{
				(*pp_node) = double_rotation_with_right(*pp_node);
			}
		}
	}
	else if((*pp_node)->data < number)//left_rotation
	{
		
		(*pp_node)->rightchild = avl_insert_node(&((*pp_node)->rightchild),(*pp_node),number);
		
		(*pp_node)->height = (avl_height((*pp_node)->leftchild) > avl_height((*pp_node)->rightchild) ?\
				      avl_height((*pp_node)->leftchild) : avl_height((*pp_node)->rightchild))+1;
	
		if(abs(avl_height((*pp_node)->rightchild) - avl_height((*pp_node)->leftchild))  == 2)
		{
			if((*pp_node)->rightchild->data < number)
			{
				(*pp_node) = single_rotation_with_left(*pp_node);
			}
			else if((*pp_node)->rightchild->data > number)		
			{
				(*pp_node) = double_rotation_with_left(*pp_node);
			}
		}
	}
	
	return (*pp_node);
}

