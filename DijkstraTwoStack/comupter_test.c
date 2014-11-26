/*************************************************************
code writer : EOF
Code file   : computer_test.c
code date   : 2014.03.03
e-mail      : jasonleaster@gmail.com

code purpose :
		This is just a test code for "Lisa" that 
I created. If there is something wrong with my code, please
touche me by e-mail.

******************************************************************/
#include "stack.h"

int main()
{
	int number = 0;
	printf("Hello ! This is a naive computer."
	       "Her name is 'Lisa' :)\n");

	number = computer();

	printf("The result of your inputed :%d\n",number);

	return 0;
}

