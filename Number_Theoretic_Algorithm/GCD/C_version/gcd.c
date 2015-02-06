/***************************************************
code writer	:	EOF
code file	:	gcd.c
code date	:	2014.09.18
e-mail		:	jasonleaster@gmail.com

description	:	
	This is a implementation of GCD :)
	If there is something wrong with my code,
please touch me by e-mail. Thank you.
****************************************************/

unsigned int gcd(unsigned int x,unsigned int y)
{
	unsigned int rem = 0;

	/*
	**	set the bigger one as "x"
	** the smaller one is "y".
	*/
	if(x < y)
	{
		rem	= x;
		x   	= y;
		y	= rem;	
	}

	/*
	**	The min non-zero reminder is GCD.
	*/
	for(rem = 0; y > 0;)
	{
		rem = x % y;

		x = y;
		y = rem;
	}

	return x;
}
