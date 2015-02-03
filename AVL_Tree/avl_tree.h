#ifndef _AVL_TREE_H
#define _AVL_TREE_H

//declaration for node
struct node
{
	int data;
	int height;
	int balance_factor;
	struct node* parent;
	struct node* rightchild;
	struct node* leftchild;
};

int avl_height(struct node* p_node);

struct node* avl_insert_node(struct node** pp_node, 
                             struct node* p_parent,
                             int number);

struct node* double_rotation_with_left(struct node* p_node);
struct node* double_rotation_with_right(struct node* p_node);

int print_tree(struct node* p_node);

struct node* single_rotation_with_left(struct node* p_node);
struct node* single_rotation_with_right(struct node* p_node);

#endif

