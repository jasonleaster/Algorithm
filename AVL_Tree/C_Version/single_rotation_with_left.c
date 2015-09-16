/*********************************************************************
code writer: EOF
code date: 2014.02.28
e-mail: jasonleaster@gmail.com
code purpose:
	implementation of function single_rotation_with_left

	If something could be changed into better situation, please 
touche me by e-mail

**********************************************************************/

#include "avl_tree.h"

struct node* single_rotation_with_left(struct node* p_node)
{	
//when there are only three nodes in the tree, we make the middile node -- *p_node as the root-node.
	struct node* temp = p_node->rightchild;
	
    if(p_node->parent)
    {
        if(p_node->parent->rightchild == p_node)
        {
            p_node->parent->rightchild = p_node->rightchild;
        }
        else
        {
            p_node->parent->leftchild  = p_node->rightchild;
        }
    }
    else
    {
        printf("the parent of p_node->data: %d is NULL!!!\n", p_node->data);
        exit(-1);
    }

    temp->parent = p_node->parent;
    p_node->parent = temp;

	p_node->rightchild = temp->leftchild;
	temp->leftchild = p_node;

	p_node->height = (avl_height(p_node->rightchild) > avl_height(p_node->leftchild) ?\
		   	  avl_height(p_node->rightchild) : avl_height(p_node->leftchild));
    (p_node->height)++;
	
	temp->height = (avl_height(temp->rightchild) > avl_height(temp->leftchild) ?\
			avl_height(temp->rightchild) : avl_height(temp->leftchild));
    (p_node->height)++;

	return temp;//new root	
}

