#include "skip_list.h"

void flush_hp_num(struct skip_list* p_skip_list)
{
	if(!p_skip_list)
	{
		printf("Error! Skip list doesn't exist!\n");
		return ;
	}

	int temp      = p_skip_list->node_number + 1;
	int old_level = p_skip_list->level;
	int counter   = 0;

	while(temp)
	{
		temp >>= 1;
		counter++;
	}

	if(counter != old_level)
	{
		p_skip_list->level = counter;
		
		p_skip_list->header.next = 
		(struct node*)realloc(p_skip_list->header.next,
				      sizeof(struct node*)*(counter));

		if(!(p_skip_list->header.next))
		{
			printf("realloc failed %s()\n",__FUNCTION__);
			return ;
		}

		p_skip_list->header.next[counter-1] = NULL;

	}

}
