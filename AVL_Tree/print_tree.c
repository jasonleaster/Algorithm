/*******************************************************************************
* code writer: EOF
* Date : 2014.02.20
* code purpose:
		This code is the definition for function -- print_tree
*e-mail:jasonleaster@gmail.com

If there somthing wrong with my code, please touch me by e-mail.Thank you!
*****************************************************************************/
#include "avl_tree.h"
#include "stdio.h"

int print_tree(struct node* p_node)// use recursion to print out the data in the binary tree
{
	// print the left side of the binary tree
	if((p_node->leftchild) != NULL)
	{
		print_tree(p_node->leftchild);
	}

	printf("%d\n",p_node->data);

	// print the right side of the binary tree
	if((p_node->rightchild) != NULL)
	{
		print_tree(p_node->rightchild);
	}
	//printf("%d\n",p_node->data); we don't need this 
}

