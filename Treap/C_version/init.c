#include "treap.h"

Treap initialize(void)
{
    if(Null_node == NULL)
    {
        Null_node = malloc(sizeof(struct treap_node));
        if(!Null_node)
        {
            printf("Out of memmory!\n");
            exit(0);
        }

        Null_node->left = Null_node->right = Null_node;
        Null_node->priority = INFINITY;
    }

    return Null_node;


}
