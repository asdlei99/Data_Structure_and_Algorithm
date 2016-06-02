#include "stdafx.h"
#include "Queue.h"

void Init_queue(Queue &queue)
{
	queue.length = 0;
	queue.queueHead = queue.queueRear = NULL;
}

void Push_queue(int value, Queue &queue)
{
	pQueueNode node = (pQueueNode)malloc(sizeof(QueueNode));
	node->value = value;
	node->nextNode = NULL;

	if (queue.length == 0)
	{
		//空队列添加第一个节点
		queue.queueRear = queue.queueHead = node;
	}
	else
	{
		queue.queueRear->nextNode = node;
		queue.queueRear->nextNode = queue.queueRear;
	}

	queue.length++;
}

int Pop_queue(Queue &queue)
{
	if (queue.length == 0)
	{
		printf("Error: cannot pop from empty queue\n");
		exit(-1);
	}

	pQueueNode head = queue.queueHead;
	int retVal = head->value;
	queue.queueHead = queue.queueHead->nextNode;
	free(head);

	return retVal;
}
