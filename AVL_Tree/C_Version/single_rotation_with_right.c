/*************************************************************************
code writer : EOF
code date : 2014.03.01
e-mail : jasonleaster@gmail.com
code purpose :
		implementation of function single_rotation_with_right
If something could be changed into a better situation, please touch me. 
Thank you!

*************************************************************************/
#include "avl_tree.h"

struct node* single_rotation_with_right(struct node* p_node)
{
	struct node*  temp;
	temp = p_node->leftchild;
 
    if(p_node->parent)
    {
        if(p_node->parent->rightchild == p_node)
        {
            p_node->parent->rightchild = p_node->leftchild;
        }
        else
        {
            p_node->parent->leftchild  = p_node->leftchild;
        }
    }
    else
    {
        printf("the parent of p_node->data: %d is NULL!!!\n", p_node->data);
        exit(-1);
    }

    temp->parent = p_node->parent;
    p_node->parent = temp;
	p_node->leftchild = temp->rightchild;
	temp->rightchild = p_node;

	p_node->height = (avl_height(p_node->rightchild) > \
                      avl_height(p_node->leftchild) ? \
			          avl_height(p_node->rightchild) : \
                      avl_height(p_node->leftchild));
    (p_node->height)++;
	
	temp->height = (avl_height(temp->leftchild) >  \
                    avl_height(temp->rightchild) ? \
       			    avl_height(temp->leftchild) : \
                    avl_height(temp->rightchild));
    (temp->height)++;

	return temp;
}

