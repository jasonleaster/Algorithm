#ifndef _TREAP_H
#define _TREAP_H

    #include <stdio.h>
    #include <stdlib.h>

    #define INFINITY (2^32 - 1)

    struct treap_node
    {
        int element;
        int priority;
        treap *right;
        treap *left;
    };

    struct treap_node * Null_node = NULL;

#endif
