/************************************************************
code file	: unweighted_path.c
code writer	: EOF
code date	: 2014.11.23
e-mail		: jasonleaster@gmail.com

code description:

	This function will do the work of searching.
This job is based on a ADT--Queue. You could read "BFS.h"
and find that decleration of these functions which is used
for Queue.

************************************************************/

#include "BFS.h"

void unweighted_path(struct table* p_table,struct graph* p_graph)
{
	if(!p_table || !p_graph)
	{
		return;
	}

	struct node* p_queue_tail;
	struct node* p_queue_header;
	
	queue_init(&p_queue_header,&p_queue_tail);	
	
	queue_enter(&p_queue_header,
		    &p_queue_tail,
		    p_graph->adjacent[ENTRY_POINT].value);

	int vertex_index = 0;
	struct vertex* p_vertex = NULL;

	while(!!p_queue_header)
	{
		
		vertex_index = queue_out(&p_queue_header,&p_queue_tail);
		printf("v%d dequeue\n",vertex_index);


		*((int*)(p_table->msg)\
		+ vertex_index*(p_table->width) + KNOW_OFFSET) = FOUND;

		p_vertex = (struct vertex*)p_graph->adjacent + vertex_index;
		p_vertex = p_vertex->next;
		for(;p_vertex;p_vertex = p_vertex->next)
		{
			if(*((int*)(p_table->msg) \
			+ (p_vertex->value)*(p_table->width)
			+ DIST_OFFSET ) == INFINITE)
			{

				*((int*)(p_table->msg) \
				+ (p_vertex->value)*(p_table->width)
				+ DIST_OFFSET ) = \
				*((int*)(p_table->msg)\
				+ (vertex_index)*(p_table->width)\
				+ DIST_OFFSET) + 1;
				
				*((int*)(p_table->msg) \
				+ (p_vertex->value)*(p_table->width)
				+ PATH_OFFSET ) = vertex_index;

				queue_enter(&p_queue_header,
					    &p_queue_tail,
					    p_vertex->value);
			}
		}

		table_print(p_table);
	}

	queue_destory(p_queue_tail);
}

