/******************************************************************
code writer : EOF
code   date : 2014.09.13
e-mail : jasonleaster@gmail.com
Attention:
	Just a implementation of function queue_init. I would be
happy, if my code will help you to know what is queue.
we assuem that ...

Input data ---> tail | | |queue| | |  header ---> Output data
	
If something wrong with my code please touch me by e-mail.

*******************************************************************/
#include "tls.h"

int queue_init(struct node** pp_queue_header,struct node** pp_queue_tail)
{
	(*pp_queue_header) = NULL;
	(*pp_queue_tail)   = NULL;

	return SUCCESS;	
}

