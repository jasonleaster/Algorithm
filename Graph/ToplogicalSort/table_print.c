#include "tls.h"

void table_print(struct table* p_table)
{
	if(!p_table)
	{
		return;
	}

	int row_num = p_table->height;
	int col_num = p_table->width;

	int row = 0;

	int know = 0;
	int dist = 0;
	int path = 0;

	printf("\tknow\tdist\tpath\n");

	for(row = 0;row < row_num;row++)
	{
		know = p_table->msg[row*col_num + KNOW_OFFSET];

		switch(know)
		{
			case FOUND:
			{
				printf("\tFound");
				break;
			}
			
			case NOT_FOUND:
			{
				printf("\tNFond");
				break;
			}

			default:
				printf("error value of varible @know\n");
				return;
		}

		dist = p_table->msg[row*col_num + DIST_OFFSET];

		switch(dist)
		{
			case INFINITE:
			{
				printf("\tINF");
				break;
			}

			default:
				printf("\t%d",dist);
		}

		path = p_table->msg[row*col_num + PATH_OFFSET];
		
		switch(path)
		{
			case 0:
			{
				printf("\t0");
				break;
			}
	
			default:
				printf("\tv%d",path);
		}

		printf("\n");
	}

	printf("\n\n\n");
}
