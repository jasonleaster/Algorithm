#include "list.h"
#include <stdlib.h>

struct list *init_list(void)
{
    struct list *p_list = malloc(sizeof(struct list));

    if(!p_list)
    {
        printf("init failed!\n")
        return NULL;
    }
    else
    {
        p_list->size = 0;
        p_list->p_head = NULL;
        return p_list;
    }
}

void release_list(struct list* p_list)
{
    if(!p_list)
    {
        return;
    }

    struct node *p_tmp = NULL;

    if(!p_list->p_head)
    {
        free(p_list);
    }
    else
    {
        for(p_tmp;)
    }

}

void show_list(struct list *p_list)
{
    if(!p_list || !(p_list->p_head))
    {
        printf("Empty list\n");
        return ;
    }

    struct node* p_node = p_list->p_head;
    
    for(;p_node != NULL; p_node = p_node->next)
    {
        printf("%d ", p_node->number);
    }

    printf("\n");
}
