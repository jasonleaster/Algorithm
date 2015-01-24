/*******************************************************************************
* code writer: EOF
* Date : 2014.02.20
* code purpose:
		This code is my implementation for function -- free_tree
*e-mail:jasonleaster@gmail.com

If there somthing wrong with my code, please touch me by e-mail.Thank you!
*****************************************************************************/
#include "bst.h"

void free_tree(struct node* p_node)// use recursion to free the memory we allocated
{
	if(p_node->leftchild == NULL && p_node->rightchild == NULL)
	{
		free(p_node);
		p_node = NULL;
	}
	else if(p_node->leftchild != NULL && p_node->rightchild == NULL)
	{
		free_tree(p_node->leftchild);	
	}
	else if(p_node->leftchild == NULL && p_node->rightchild != NULL)  
	{
		free_tree(p_node->rightchild);
	}
	else if (p_node->leftchild != NULL && p_node->rightchild != NULL)
	{
		free_tree(p_node->rightchild);
		free_tree(p_node->leftchild);	
	}
	
}

