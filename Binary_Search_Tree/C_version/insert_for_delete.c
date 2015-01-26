/*********************************************************************
* Code writer:EOF
* Code date: 2014.02.20
* code purpose:
		this code is my implementation for the function insert_for_delete
* e-mail: jasonleaster@gmail.com

If something wrong with my code, please touch me by e-mail. Thank you!

*********************************************************************/
#include "bst.h"

int insert_for_delete(struct node* p_node,struct node* tmp)
{
	if((p_node) == NULL)
	{
		return 0;
	}
	else
	{
		if((p_node)->data < tmp->data)
		{
			if(0 == insert_for_delete((p_node)->rightchild,tmp))
			{
				(p_node)->rightchild = tmp;
				tmp->parent = (p_node);
			}
		}
		else if((p_node)->data > tmp->data)
		{
			if(0 ==insert_for_delete((p_node)->leftchild,tmp))
			{
				(p_node)->leftchild = tmp;
				tmp->parent = (p_node);
			}
		}
	}
}

