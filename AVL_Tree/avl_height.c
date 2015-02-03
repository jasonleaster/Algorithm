/************************************************************************
code writer :EOF
data : 2014.02.28
code purpose:
	My implementation for avl_height function
	
	This function would return current node's height and if current 
node is NULL, -1 would be returned.

	If this node is not NULL ,return height of the node,else return -1.
*************************************************************************/
#include "avl_tree.h"
#include <stdio.h>

int avl_height(struct node* p_node)
{
	if(p_node != NULL)
	{
		return p_node->height; //If current node is not NULL, we return the height of current node.
	}
	else
	{
		return -1;// If current node is NULL, we assume that the height of current node is -1.
	}
}

