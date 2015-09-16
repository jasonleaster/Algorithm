#include "stack.h"

struct string* str_read(struct string* p_string)
{
	int ret  = 0;

	if(!p_string)
	{
		return NULL;
	}

	/*
	** 	Evil --> --> scanf("%s",&string);
	**
	** scanf family is not safe for string which is inputed.
	** I decide to give it up and use system call read().
	*/
	ret = read(STDIN_FILENO,p_string->str,p_string->length);


	if(ret < 0)
	{
		printf("system call read() error"
		       " in function %s()\n",__FUNCTION__);

		return NULL;
	}
	else if (ret == p_string->length)
	{
		do
		{
			(p_string->size)   += BUFSIZ;
			(p_string->length) += BUFSIZ;

			p_string = (struct string*)realloc(p_string,
					             p_string->size);

			ret = read(STDIN_FILENO,
				   (char*)(p_string) + (p_string->size) - BUFSIZ,
				   BUFSIZ);

			if(ret < 0)
			{
				printf("system call read() error"
				       " in function %s()\n",__FUNCTION__);

				return NULL;
			}
		}while(ret == BUFSIZ);
	}
	
	return p_string;
}
