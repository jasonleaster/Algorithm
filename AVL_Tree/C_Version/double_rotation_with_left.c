/******************************************************************************
code writer : EOF
code date : 2014.03.01
e-mail : jasonleaster@gmail.com
code purpose :
		implementation of function double_rotation_with_left
If something could be changed into a situation, please touch me. Thank you!

*******************************************************************************/

#include "avl_tree.h"
#include "stdio.h"

struct node* double_rotation_with_left(struct node* p_node)
{
	struct node* temp = NULL;

	p_node = single_rotation_with_left(p_node);
	
	return  single_rotation_with_right(p_node);
}

