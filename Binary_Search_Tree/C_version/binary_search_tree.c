/*******************************************************************************
* code writer: EOF
* Date : 2014.02.20
* code purpose:
		This code is main function.
*e-mail:jasonleaster@gmail.com

If there somthing wrong with my code, please touch me by e-mail.Thank you!
*****************************************************************************/
#include "stdio.h"
#include "stdlib.h"
#include "bst.h"

#define ARRAYSIZE 10


int main(int argc, char* argv[])
{
	int temp = 0;
	int number = 0;
	int array[ARRAYSIZE] = {23,32,4,56,33,98,24,88,45,78};
	
        struct node* root = NULL;

	for(temp = 0;temp < ARRAYSIZE;temp++)
	{
		if((root = insert_node(root, NULL, array[temp])) ==  NULL)
		{
			break;
                        //memory allocation failed ,
                        //so break out of this loop
		}
	}
	
	printf("before delete a node\n");
	print_node(root);

	printf("If you want to delete a numbe in these table,"
                " please enter the number\n");

	while(!scanf("%d",&number))
	{
                while(getchar() != '\n')
                {
   		    printf("scanf error!\nPlease enter again\n");
                }
	}

	printf("I am goint to delete node which included data %d",number);
	delete_node(root,number);
	
	printf("after delete the node\n");
	print_node(root);
	
	free_tree(root);
	return 0;
}

