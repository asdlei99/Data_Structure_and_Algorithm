// LinkedListDemo.cpp : 数据结构——链表的demo.
//

#include "stdafx.h"
#include "LinkedList.h"

int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int _tmain(int argc, _TCHAR* argv[])
{
	LinkedList *list = CreateLinkedListFromArray(array, sizeof(array)/sizeof(int));

	FreeLinkedList(&list);

	return 0;
}

