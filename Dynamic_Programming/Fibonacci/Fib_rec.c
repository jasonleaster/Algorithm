/****************************************************
code file : Fibonacci.c
code date : 2014.11.25
e-mail    : jasonleaster@gmail.com

code description:
	
	Here is a implementation of funciont @fib()
which will help us to compute the fibonacci array
and what we should pay attention to is that this 
method is using recursion!

	Reader must know that this method is convenient
way which is used to compute fibonacci array but not a
elegent way.

*****************************************************/
#include <stdio.h>

int fib(int num)
{
	if(num <= 1)
	{
		return 1;
	}
	else
	{
		return fib(num-1) + fib(num - 2);
	}
}

int main()
{
	int number = 0;
	
	while(!scanf("%d",&number))
	{
		getchar();
		printf("\nerror!input again!\n");
	}

	printf("The %dth fibonacci number is %d\n",number,fib(number));

	return 0;
}
