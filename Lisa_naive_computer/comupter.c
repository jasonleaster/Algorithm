/*********************************************************
Code writer : EOF
Code file   : computer.c
Code date   : 2014.11.26
Email	    : jasonleaster@gmail.com
Version	    : 0.0

Code description:

code purpose : 
	This code is my implementation for function creat_stack.
functin creat_stack would creat a the first node of the stack and 
just only the first node. You must know what is stack...

#ATTENTION#	
	You must input with '(' and ')' for each operator,
otherwise you will be puzzle about the result of output.

Usage:
	(1+2) would output 3
	(1+((2*3)+1))  == 8

If there is something wrong with my code, please touch me by e-mail.

*********************************************************/
#include "stack.h"

int computer(void)
{
	char string[ARRAYSIZE] = {0};

	/*
	**	According to Dijsktra's Two Stack scheme,
	** we creat two stack. 
	**	@p_stack_operand is pointer which point to
	** a stack only for operand in the inputed string. 
	** So do @p_stack_operator.
	*/
	struct node* p_stack_operand  = NULL;	
	struct node* p_stack_operator = NULL;	

	p_stack_operand  = creat_stack();
	p_stack_operator = creat_stack();

	int  temp      = 0;
	int  result    = 0;
	int  opr_one   = 0;
	int  opr_two   = 0;
	char operator  = 0;

	/*
	** 	Evil --> --> scanf("%s",&string);
	**
	** scanf family is not safe for string which is inputed.
	** I decide to give it up and use system call read().
	*/

	if(read(STDIN_FILENO,string,ARRAYSIZE) < 0)
	{
		printf("system call read() error"
		       " in function %s()\n",__FUNCTION__);
	}
	
	for(temp = 0;string[temp] != '\n';temp++)
	{
		if(string[temp] == '(')
		{
			continue;
		}

		if(string[temp] == ')')
		{
			opr_one  = pop_stack(p_stack_operand);
			opr_two  = pop_stack(p_stack_operand);

			operator = pop_stack(p_stack_operator);

			switch(operator)
			{
				case '+':
				{
					push_stack(&p_stack_operand,
						   opr_one + opr_two);
					break;
				};
				
				case '-':
				{
					push_stack(&p_stack_operand,
						   opr_one - opr_two);
					break;
				};

				case '*':
				{
					push_stack(&p_stack_operand,
						   opr_one * opr_two);
					break;
				};

				case '/':
				{
					push_stack(&p_stack_operand,
						   opr_one / opr_two);
					break;
				};

				default:
					goto out;
					result = -1;
					printf("ERROR!undefined "
					       "operator %c\n",operator);
	
			}
		}

		if(string[temp] >= '0' && string[temp] <= '9')
		{
			push_stack(&p_stack_operand,string[temp] - '0');
			continue;
		}

		if(string[temp] == '+' || string[temp] == '-'||
		   string[temp] == '*' || string[temp] == '/')
		{
			push_stack(&p_stack_operator,string[temp]);
			continue;
		}
	}
	
	/*
	** Finally, We got the result which is stored in stack--operand
	*/
	result = pop_stack(p_stack_operand);

out:
	release_stack(p_stack_operand);
	release_stack(p_stack_operator);

	return result;
}

