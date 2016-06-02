// QueueDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Queue.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Queue queue;

	Init_queue(queue);

	Push_queue(1, queue);
	Push_queue(2, queue);
	Push_queue(3, queue);
	Push_queue(4, queue);
	Push_queue(5, queue);
	Push_queue(6, queue);

	Empty_queue(queue);
// 	int len = queue.length;
// 	for (int idx = 0; idx <= len; idx++)
// 	{
// 		printf("Queue value %d : %d\n", idx, Pop_queue(queue));
// 	}

	return 0;
}

