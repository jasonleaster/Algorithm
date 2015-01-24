/*******************************************************************************
* code writer: EOF
* Date : 2014.02.20
* code purpose:
		This code is my implementation for function -- delete_node
*e-mail:jasonleaster@gmail.com

If there somthing wrong with my code, please touch me by e-mail.Thank you!
*******************************************************************************/
#include "bst.h"

int delete_node(struct node* p_node,int number)
{
	struct node* temp = NULL;

	if(p_node->data == number)
	{
		//when both the rightchild and leftchild of the node which is to be deleted are NULL
		if((p_node)->leftchild == NULL && (p_node)->rightchild == NULL)
		{
			if((p_node)->parent->rightchild == (p_node))
			{
				(p_node)->parent->rightchild = NULL;
				free((p_node));
			}
			else if((p_node)->parent->leftchild == (p_node))
			{
				(p_node)->parent->leftchild = NULL;
				free((p_node));
			}
		}

		//when the leftchild is NULL but the rightchild isn't NULL
		if((p_node)->leftchild == NULL && (p_node)->rightchild != NULL)
		{
			if((p_node)->parent->rightchild == (p_node))
			{
				(p_node)->parent->rightchild = (p_node)->rightchild;
				(p_node)->rightchild->parent = (p_node)->parent;
				free((p_node));
			}
			else if((p_node)->parent->leftchild == (p_node))
			{
				(p_node)->parent->leftchild = (p_node)->rightchild;
				(p_node)->rightchild->parent = (p_node)->parent;
				free((p_node));
			}
		}
		
		//when the rightchild is NULL but the leftchild isn't NULL
		if((p_node)->rightchild == NULL && (p_node)->leftchild != NULL)
		{
			if((p_node)->parent->rightchild == (p_node))
			{
				(p_node)->parent->rightchild = (p_node)->leftchild;
				(p_node)->leftchild->parent = (p_node)->parent;
				free((p_node));
			}
			else if((p_node)->parent->leftchild == (p_node))
			{
				(p_node)->parent->leftchild = (p_node)->leftchild;
				(p_node)->leftchild->parent = (p_node)->parent;
				free((p_node));
			}
		}

		//when both child are not NULL
		if((p_node)->rightchild != NULL && (p_node)->leftchild != NULL)
		{
			if((p_node)->parent->rightchild == (p_node))
			{
				//(*pp_node)->parent->rightchild = NULL;
				(p_node)->parent->rightchild = (p_node)->rightchild;
				//temp = (*pp_node)->parent;
				//temp.rightchild = (*pp_node)->rightchild;
				insert_for_delete(((p_node)->rightchild),(p_node)->leftchild);
				free((p_node));
				
			}
			else if((p_node)->parent->leftchild == (p_node))
			{
				//(*pp_node)->parent->leftchild = NULL;
				(p_node)->parent->leftchild = (p_node)->rightchild;
				insert_for_delete(((p_node)->rightchild),(p_node)->leftchild);
				free((p_node));
			}
		}
	}
	else
	{
		if((p_node)->data < number)
		{
			delete_node((((p_node)->rightchild)),number);	
		}
		
		if((p_node)->data > number)
		{
			delete_node((((p_node)->leftchild)),number);
		}
	}
}

