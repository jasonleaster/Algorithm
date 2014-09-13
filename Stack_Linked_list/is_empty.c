/**********************************************************************
code writer: EOF
code date : 2014.03.03
e-mail: jasonleaster@gmail.com
code purpose :
	This code is a implementation for function is_empty
If there is something wrong with my code, please touch me by e-mail.

**********************************************************************/
#include "stdio.h"
#include "stack.h"

int is_empty(struct node* p_node)
{
	if(p_node->next == NULL)
	{
		return EMPTY;
	}
	else
	{
		return NON_EMPTY;
	}
}

