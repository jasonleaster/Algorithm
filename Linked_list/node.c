#include <stdio.h>
#include "list.h"

/*
** Trickly, We insert the @num into the end of the list 
** by this @ins_node method.
*/
int ins_node(struct list* p_list, int num)
{
    if(!p_list)
    {
        printf("empty list!\n");
        return -1;
    }

    struct node* p_node = NULL;

    if(!p_list->p_head)
    {
        p_list->p_head = (struct node *)malloc(sizeof(struct node));
        if(!p_list->p_head)
        {
            printf("malloc failed in function %s line %d\n",
                   __FUNCTION__, __LINE__);
            return -1;
        }

        p_list->p_head->number = num;
        p_list->p_head->next   = NULL;
    }
    else
    {
        for(p_node = p_list->p_head; p_node->next != NULL;
            p_node = p_node->next)
        {
        }

        p_node->next = (struct node *)malloc(sizeof(struct node));
        p_node->next->number = num;
        p_node->next->next   = NULL;

    }

    return 0;
}

int del_node(struct list *p_list, int num)
{
    if(!p_list || !(p_list->p_head))
    {
        printf("empty list!\n");
        return -1;
    }

    int i = 0;
    struct node* p_cur = p_list->p_head;
    struct node* p_tmp = NULL;

    if(p_cur->number == num)
    {
        free(p_cur);
        release_list(p_list);
        p_cur  = NULL;
        p_list = NULL;

        return 0;
    }

    for( ; p_cur->next != NULL; p_cur = p_cur->next)
    {
        if(p_cur->next->number == num)
        {
            p_tmp = p_cur->next->next;
            free(p_cur->next);
            p_cur->next = p_tmp;
            return 0;
        }
    }

    printf("There is no node which's value is %d\n", num);

    return -1;
}
