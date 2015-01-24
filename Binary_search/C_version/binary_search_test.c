#include <stdio.h>
#include "binary_search.h"

int main()
{
	int number[10] = {0,2,6,8,10,15,18,40,99};

	int what_i_want = 18;
	int ret = 0;

	ret = binary_search(number,sizeof(number)/sizeof(number[0]),what_i_want);

	if(ret < 0)
	{
		printf("Not found!\n");
		return 0;
	}

	printf("location:%d number[%d]:%d\n",ret,ret,number[ret]);

	return 0;
}
