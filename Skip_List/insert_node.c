#include "skip_list.h"

int insert_node(struct skip_list* p_skip_list,struct node* p_node)
{
	if(!p_skip_list)
	{
		printf("Empty Skip List! in function %s()\n",__FUNCTION__);
		return  FAILED_RET;
	}

	if(!p_node)
	{
		printf("Empty node! in function %s()\n",__FUNCTION__);
		return  FAILED_RET;
	}

	/*
	**	ATTENTION! It's important to update the level of header
	*/
	flush_hp_num(p_skip_list);

	struct node* p_node_updating[p_skip_list->level] = {0};

	struct node* p_tmp  = NULL;
	struct node* p_next = NULL;

	int temp = 0;
	for(temp =  p_skip_list->level,	    
	   p_tmp = &(p_skip_list->header);
	    temp > 0;)
	{
		if(!(p_tmp->next[temp-1]) && temp == 1)
		{
			/*
			** 	This 'if' condition over there, 
			** is a special case.
			*/
			p_tmp->next[temp-1] = p_node;
			break;
		}
		else
		{
			for (;
			     !!(p_tmp->next[temp-1]);
			     p_tmp = p_tmp->next[temp-1])
			{
				if(temp != 1 && 
				p_node->data < p_tmp->next[temp-1]->data)
				{
					p_node_updating[temp-1] = p_tmp;
					temp--;
					break;
				}
				else if(temp == 1 && 
				p_node->data < p_tmp->next[temp-1]->data)
				{
					/*
					**  	Here, It's time to insert
					**  the new node
					*/
					p_node_updating[temp-1] = p_tmp;

					for(temp = p_node->level;
					    temp > 0;
					    temp--)
					{
						if(p_node_updating[temp-1] != NULL)
						{
							p_next = p_node_updating[temp-1]->next;
							p_node_updating[temp-1]->next = p_node;
							p_node->next[temp-1] = p_next;
						}
					}
				}
			}
		}
		
	}

	/*
	**	Finally, we update the number of node in the skip list
	*/
	(p_skip_list->node_number)++;
	return SUCCESS_RET;
}
