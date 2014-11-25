#include "colonel.h"

int main()
{

	int stream_cost[STATION_NUM][STATION_LEN] = 
	{
		{7,9,3,4,8,4},
		{8,5,6,4,5,7}
	};

	int change_cost[STATION_LEN -1][STATION_NUM] = 
	{
		{0,2},
		{2,0},
	};
		struct 	node
		{
			int a;
			short b;
			char c;
		};

	union test
	{
		struct 	node hehe;

		char d;
	};

	union test wawa;

	printf("sizeof :%zu\n",sizeof(wawa));

	return 0;
}
