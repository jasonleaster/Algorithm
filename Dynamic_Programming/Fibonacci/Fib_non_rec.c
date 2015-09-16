/****************************************************
code file : Fibonacci.c
code date : 2014.11.25
e-mail    : jasonleaster@gmail.com

code description:
	
	Here is a implementation of funciont @fib()
which will help us to compute the fibonacci array.

	Aha! Just have glance with my code and you
will find that we didn't use recursion!YES! We do!

	It's very elegent to store the last two var-
ible @prev and @prev_prev which is close to 
current number.Something like this, we have a array,
1 2 3 4 5, @prev is 4 @prev_prev 3, current number is 
5 :)
	This method that we call it as dynamic pro-
gramming.

*****************************************************/

#include <stdio.h>

int main()
{
	int number = 0;
	int prev   = 1;
	int prev_prev = 1;
	int result = 1;
	
	while(!scanf("%d",&number))
	{
		getchar();
		printf("\nerror!input again!\n");
	}

	int temp = 0;
	for(temp = 3;temp <= number;temp++)
	{
		result = prev + prev_prev;
		prev_prev = prev;
		prev = result;
	}

	printf("The %dth fibonacci number is %d\n",number,result);
	
	return 0;
}
