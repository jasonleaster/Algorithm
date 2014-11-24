#include "dijstra.h"

void dijkstra(struct graph* p_graph,struct table* p_table)
{
	if(!p_table)
	{
		return;
	}

	struct vertex* p_vertex = NULL;

	struct heap* p_heap = NULL;
	
	p_heap = init_heap(p_graph->num_vertex);

	for(;;)
	{
		
		insert_heap(p_heap,);

		tmp_vertex = ;//need to be fixed it up

	}

	destroy_heap(p_heap);
}
