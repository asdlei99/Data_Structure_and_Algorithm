#include "stdafx.h"
#include "LinkedList.h"

//从给定的int型数组创建一个单链表
LinkedList* CreateLinkedListFromArray(const int *arr, int len)
{
	if (0 >= len)
	{
		return NULL;
	}

	LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
	pLNode node = NULL;

	list->linkedListLength = len;
	for (int idx = 0; idx < len; idx++)
	{
		node = (pLNode)malloc(sizeof(LNode));
		node->value = arr[idx];
		node->nextNode = NULL;
		if (idx == 0)
		{
			list->firstNode = list->currentNode = node; //设置第一个节点
		}

		list->currentNode->nextNode = node;
	}

	return list;
}

//释放一个单链表的节点和单链表本身
void FreeLindedList(LinkedList** List)
{
	LinkedList *LList = *List;
	if (!LList)
	{
		return;
	}

	pLNode thisNode = LList->firstNode;
	while(thisNode->nextNode)
	{
		pLNode nextNode = thisNode->nextNode;
		free(thisNode);
		thisNode = nextNode;
	}
	free(thisNode);
	free(LList);
}
