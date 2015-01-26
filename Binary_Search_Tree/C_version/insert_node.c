
#include "bst.h"

struct node *insert_node(struct node* p_node,
                         struct node* p_parent, 
                         int number)
{
     if(!p_node)
     {

	 struct node *p_temp = (struct node*)malloc(sizeof(struct node));

	 if(!p_temp)
	 {
	     printf("malloc failed!\n");
	     return NULL;
	 }

	 p_temp->data = number;
	 p_temp->leftchild = p_temp->rightchild = NULL;
         p_temp->parent = p_parent;

         return p_temp;
     }
     else if (p_node->data > number)
     {
         p_node->leftchild = insert_node(p_node->leftchild,
                                         p_node,
                                         number);
     }
     else if (p_node->data < number)
     {
         p_node->rightchild = insert_node(p_node->rightchild,
                                          p_node,
                                          number);
     }

     return p_node;
}
