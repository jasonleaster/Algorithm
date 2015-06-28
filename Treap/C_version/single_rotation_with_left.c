/*********************************************************************
code writer: EOF
code date: 2014.02.28
e-mail: jasonleaster@gmail.com
code purpose:
	implementation of function single_rotation_with_left

	If something could be changed into better situation, please 
touche me by e-mail

**********************************************************************/

#include "treap.h"

struct node* single_rotation_with_left(struct node* p_node)
{	
    /*
       when there are only three nodes in the tree,
       we make the middile node -- *p_node as the root-node.
     */
	struct node* temp = p_node->rightchild;
	
	p_node->rightchild = temp->leftchild;
	temp->leftchild = p_node;

    /*
       update the temp's member
     */

	return temp;//new root	
}

