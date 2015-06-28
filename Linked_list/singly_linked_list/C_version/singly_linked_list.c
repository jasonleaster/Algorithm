/*********************************************************
Code writer : EOF
Code file   : single_linked_list.c
Code date   : 2015.01.15
e-mail      : jasonleaster@gmail.com

Code description:
        Here is a implementation for singly linked list.

    If there is something wrong with my code please touch me
by e-mail, thank you.

Update: 2015.06.28
    I find a bug in function @release_list() which will
cause memory leak. 

**********************************************************/
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

// Abstraction for our node which is in list.
struct node
{
    int num;
    struct node *next;
};

struct node *list_search(struct node* p_head, int k)
{
    if(!p_head)
    {
         printf("Empty list!\n");
         return NULL;
    }

    struct node* p_tmp = p_head->next;
    for(;p_tmp != NULL; p_tmp = p_tmp->next)
    {
        if(p_tmp->num == k)
        {
            break;
        }
    }

    return p_tmp;
}

int list_insert(struct node *p_head, int num)
{
    if(!p_head)
    {
         printf("Empty list!\n");
         return -1;
    }

    struct node *p_node = malloc(sizeof(struct node));

    if(!p_node)
    {
        printf("malloc failed!\n");
        return -1;
    }
    
    p_node->num  = num;
    p_node->next = p_head->next;
    p_head->next = p_node;

    return 0;   
}

int list_delete(struct node *p_head, int num)
{
    struct node *p_node = p_head;
    struct node *p_tmp  = NULL;

    if(!p_head || !p_node)
    {
        printf("Empty list!\n");
        return -1;
    }

    for(;p_node->next != NULL; p_node = p_node->next)
    {
        if(p_node->next->num == num)
        {
            p_tmp = p_node->next;
            p_node->next = p_tmp->next;
            free(p_tmp);
            p_tmp = NULL;
            return 0;
        }
    }

    printf("There is node element %d in the list\n", num);

    return -1;
}

struct node *init_list(void)
{
    struct node *p_head = malloc(sizeof(struct node));

    if(!p_head)
    {
        printf("malloc failed!\n");
        return NULL;
    }
    
    p_head->next = NULL;
    /*
    **    just garbage number, we don't use this
    **  member in header node
    */
    p_head->num  = -1;

    return p_head;

}

void release_list(struct node* p_head)
{
    if(!p_head)
    {
       return ;
    }

    struct node *p_node = NULL;
    struct node *p_tmp  = NULL;

    for(p_node = p_head ;
        p_node->next != NULL;)
    {
        p_tmp = p_node->next;
        p_node->next = p_tmp->next;
        free(p_tmp);
    }

    free(p_node);
}

void list_show(struct node *p_head)
{
    if(!p_head)
    {
        return ;
    }

    struct node *p_node = p_head;
    for(; p_node->next != NULL; p_node = p_node->next)
    {
         printf("\t%d", p_node->next->num);
    }

    printf("\n");
}

/*-------------------------test our API---------------------------------*/
int main()
{
    struct node *p_head = init_list();
    int array[ARRAY_SIZE] = {1,2,3,4,5,6,7,8,9,10};

    int i = 0;
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        if(list_insert(p_head, array[i]) < 0)
        {
            goto failed;
        }
    }

    list_show(p_head);
failed:
    release_list(p_head);
    return 0;
}
