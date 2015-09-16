#include "stack.h"

struct string* new_string(void)
{
	struct string* p_string = NULL;

	p_string = (struct string*)malloc(BUFSIZ);

	if(!p_string)
	{
		printf("malloc failed in "
			"function %s()\n",__FUNCTION__);
		return NULL;
	}

	p_string->read    = str_read;
	p_string->release = del_string;
	p_string->size    = BUFSIZ;
	p_string->length  = BUFSIZ - sizeof(struct string);

	return p_string;
}
