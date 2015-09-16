/*********************************************************************************************
code writer : EOF
code date : 2014.03.01
e-mail : jasonleaster@gmail.com
code purpose :
		implementation of function single_rotation_with_right
If something could be changed into a better situation, please touch me. Thank you!

*********************************************************************************************/
#include "avl_tree.h"

struct node* single_rotation_with_right(struct node* p_node)
{
	struct node*  temp;
	temp = p_node->leftchild;
	p_node->leftchild = temp->rightchild;
	temp->rightchild = p_node;

    /*
       update the member of @temp
     */
	return temp;
}

