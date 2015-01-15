#ifndef _LIST_H
#define _LIST_H

    struct node
    {
        int number;
        /*
        ** You could add more message
        ** not only "int a" :)
        */
        struct node *next;
    };

    struct list
    {
        int size;
        struct node* p_head;
    };

    int del_node(struct list* p_list, int num);
    int ins_node(struct list* p_list, int num);

    
    struct list *init_list(void);  
    void release_list(struct list* p_list);
    void show_list(struct list *p_list);
#endif
