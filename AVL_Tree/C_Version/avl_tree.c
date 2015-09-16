/*************************************************************************
code writer : EOF
code date : 2014.03.01
e-mail: jasonleaster@gmail.com

code purpose:
	This is the main functin of this program. 
Just modify a avl-tree and print out the data we writed in.

    If something could be changed into better situation, 
please touch me by e-mail. Thank you!

*************************************************************************/
#include <stdio.h>
#include "avl_tree.h"

#define ARRAY_SIZE 10

int main()
{
	int array[ARRAY_SIZE] = {2,4,23,15,98,34,66,75,41,17};
	int temp = 0;
	
	struct node* root;
	root = NULL;

	for(temp = 0;temp < ARRAY_SIZE;temp++)
	{
		root =  avl_insert_node(&root, root,array[temp]);
	}

	if(root == NULL)
	{
		printf("insert failed!\nProcess end!\n");
	}

	print_tree(root);

    avl_destroy(root);
	return 0;
}

