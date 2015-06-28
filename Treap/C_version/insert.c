#include "treap.h"

Treap insert(Treap T, int item)
{
    if(T == Null_node)
    {
        /* create and return a one-node tree */
        T = malloc(sizeof(struct treap_node));
        if (!T)
        {
            printf("Out of space\n");
            exit(0);
        }
        else
        {
            T->element = item;
            T->priority = 
            T->left = T->right = Null_node;
        }
    }
    else if(item < T->element)
    {
        T->left = insert(T->left, item);
        if(T->left->priority < T->priority)
        {
            T = SingleRotateWithLeft(T);
        }
    }
    else if(item > T->element)
    {
        T->right = insert(T->right, item);
        if(T->right->priority < T->priority)
        {
            T = SingleRotateWithRight(T);
        }
    }

    /* Otherwise it's a duplicate ; do nothing */

    return T;
}
