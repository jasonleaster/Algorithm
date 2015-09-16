/************************************************************************************
code writer : EOF
code date : 2014.03.01
e-mail : jasonleaster@gmail.com
code purpose :
		implementation of function double_rotation_with_right
If something could be changed into a better situation, please touch me. Thank you!
**********************************************************************************/
#include "avl_tree.h"

struct node* double_rotation_with_right(struct node* p_node)
{

	p_node = single_rotation_with_right(p_node);

	return single_rotation_with_left(p_node);
}

