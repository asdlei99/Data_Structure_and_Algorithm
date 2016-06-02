#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef struct _QueueNode *pQueueNode;
typedef struct _QueueNode
{
	int value;
	pQueueNode nextNode;
} QueueNode, *pQueueNode;

typedef struct _Queue
{
	unsigned int length;
	pQueueNode queueHead;
	pQueueNode queueRear;
} Queue;

void Init_queue(Queue &queue);

void Push_queue(int value, Queue &queue);

int Pop_queue(Queue &queue);

#endif