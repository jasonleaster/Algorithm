/************************************************************************
code writer : EOF
code date : 2015.08.02
e-mail: jasonleaster@gmail.com

code purpose:
		implementation of function avl_insert_node
If something could be changed into better situation, 
please touch me by e-mail. Thank you!

**************************************************************************/

#include "avl_tree.h"

void avl_destroy(struct node* p_node)
{
    if(!p_node)
    {
        return ;
    }

    if(free_node(p_node) == 0)
    {
        return;
    }

    avl_destroy(p_node->leftchild);

    if(free_node(p_node) == 0)
    {
        return;
    }

    avl_destroy(p_node->rightchild);

    if(free_node(p_node) == 0)
    {
        return;
    }
}

int free_node(struct node* p_node)
{
    if(p_node->leftchild == NULL && p_node->rightchild == NULL)
    {
        if(p_node->parent->rightchild == p_node)
        {
            p_node->parent->rightchild = NULL;
        }
        else
        {
            p_node->parent->leftchild = NULL;
        }

        free(p_node);

        return 0;
    }
    else
    {
        return -1;
    }
}
