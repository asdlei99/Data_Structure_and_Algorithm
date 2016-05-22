// LinkedListDemo.cpp : ���ݽṹ���������demo.
//

#include "stdafx.h"
#include "LinkedList.h"

int array[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int _tmain(int argc, _TCHAR* argv[])
{
	LinkedList *list = CreateLinkedListFromArray(array, sizeof(array)/sizeof(int));

	ShowLinkedList(list);

//	GetListNodeValueAt(list, 5);

	InsertNodeAt(list, 0, -5);

	ShowLinkedList(list);

	InsertNodeAt(list, 5, -10);

	ShowLinkedList(list);

	DeleteNodeAt(list, 0);

	ShowLinkedList(list);

	DeleteNodeAt(list, 5);

	ShowLinkedList(list);

	InsertNodeAt(list, 20, -10);

	DeleteNodeAt(list, 15);

	FreeLinkedList(&list);

	return 0;
}

