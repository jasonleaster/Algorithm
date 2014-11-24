#include "tls.h"

void topsort(struct graph* p_graph)
{
	if(!p_graph)
	{
		return;
	}

	int counter = 0;

	struct vertex* p_vertex = NULL;

	struct node* p_queue_header = NULL;
	struct node* p_queue_tail   = NULL;

	queue_init(&p_queue_header,&p_queue_tail);

	int temp = 0;
	//Attention! Here we start from point 1 but not temp = 0
	for(temp = 1;temp < p_graph->num_vertex;temp++)
	{
		if(p_graph->adjacent[temp].indegree == 0)
		{
			queue_enter(&p_queue_header,
		    		    &p_queue_tail,
				    temp);
		}
	}

	int vertex_index = 0;

	while(!!p_queue_header)
	{
		vertex_index = queue_out(&p_queue_header,&p_queue_tail);

		/**********/

		p_vertex = (struct vertex*)(&p_graph->adjacent[vertex_index]);
		p_vertex = p_vertex->next;
		for(;!!p_vertex;p_vertex = p_vertex->next)
		{
			if(--(p_graph->adjacent[p_vertex->value].indegree) == 0)
			{
				queue_enter(&p_queue_header,
					    &p_queue_tail,
					    p_vertex->value);
			}
		}
	}

	queue_destory(p_queue_tail);
}
