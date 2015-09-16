#include "treap.h"

Treap remove(Treap T, int item)
{
    if (T != Null_node)
    {
        if (item < T->element)
        {
            T->left = remove(T->left, item);
        }
        else if(item > T->element)
        {
            T->right = remove(T->right, item);
        }
        else
        {
            /*match found*/
            {
                if (T->left->priority < T->right->priority)
                {
                    T = SingleRotateWithLeft(T);
                }
                else
                {
                    T = SingleRotateWithRight(T);
                }

                if (T != Null_node)
                {
                    T = remove(T, item);
                }
                else
                {
                    /* at a leaf */
                    free(T->left);
                    T->left = Null_node;
                }
            }
        }
    }

    return T;
}
