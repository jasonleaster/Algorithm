#include <stdio.h>

static unsigned int Seed = 1;

#define A 48271L
#define M 2147483647L
#define Q (M / A)
#define R (M % A)

double random(void)
{
	long tmp_seed = 0;

	tmp_seed = A * (Seed % Q) - R*(Seed / Q);

	if(tmp_seed >= 0)
	{
		Seed = tmp_seed;
	}
	else
	{
		Seed = tmp_seed  + M;
	}
}

void initialize(unsigned long initial)
{
	Seed = initial;
}

int main()
{
	int temp = 0;
	for(temp = 0;temp < 5;temp++)
	{
		printf("%lf\t",random());
	}
	printf("\n");
	return 0;
}
