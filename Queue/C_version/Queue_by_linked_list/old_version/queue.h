#ifndef _QUEUE_H
#define _QUEUE_H 1
	
	struct node
	{
		struct node* previous;
		struct node* next;
		int data;
	};

	#define QUEUE_SIZE 10
	#define ARRAY_SIZE 20

	#define SUCCESS 1
	#define FAILED  0

	#include "queue_destory.h"
	#include "queue_enter.h"
	#include "queue_init.h"
	#include "queue_out.h"
	#include "queue_print.h"
#endif

