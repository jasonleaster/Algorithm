#ifndef _STACK_H  
#define _STACK_H 1  
  
	#define EMPTY     0  
	#define NON_EMPTY 1  
	  
	struct node  
	{     
	    int data;  
	    struct node* next;  
	};  
	  
	#ifndef _CREAT_STACK_H  
	#define _CREAT_STACK_H 1  
	    #include "creat_stack.h"  
	#endif  
	  
	#ifndef _PUSH_STACK_H  
	#define _PUSH_STACK_H 1  
	    #include "push_stack.h"  
	#endif  
	  
	#ifndef _IS_EMPTY_H  
	#define _IS_EMPTY_H 1  
	    #include "is_empty.h"  
	#endif  
  
#endif
