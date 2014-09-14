#ifndef _QUEUE_H
#define _QUEUE_H


	#include <stdio.h>
	#include <stdlib.h>

	#define QUEUE_SIZE    10

	#define FULL_QUEUE    1
	#define UNFULL_QUEUE  0

	#define EMPTY_QUEUE   1
	#define UNEMPTY_QUEUE 0

	#define FAILED_RET -1
	#define SUCCESS_RET 0
	struct queue
	{
		int header;
		int tail;
		int size;
		int capacity;
		/*
		** Old trick :)
		*/
		int array[0];
	};

	int queue_init(struct queue** pp_queue,int size);
	void queue_release(struct queue* p_queue);

	int is_full(struct queue* p_queue);
	int is_empty(struct queue* p_queue);

	void enqueue(struct queue* p_queue,int num);
	int dequeue(struct queue* p_queue);
#endif
