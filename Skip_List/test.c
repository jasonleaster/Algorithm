#include "skip_list.h"

int main()
{
	struct skip_list* p_skip_list = NULL;

	p_skip_list = init_skip_list();

	p_skip_list.free_skip_list(p_skip_list);

	return 0;
}
