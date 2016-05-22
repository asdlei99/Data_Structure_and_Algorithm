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
		else
		{
			list->currentNode->nextNode = node;
			list->currentNode = list->currentNode->nextNode; 
		}
	}

	return list;
}

//释放一个单链表的节点和单链表本身
void FreeLinkedList(LinkedList** List)
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
	*List = NULL;
}

//显示一个单链表结构中所有的节点的负载元素值
void ShowLinkedList(const LinkedList *List)
{
	if (!List)
	{
		printf("Error: list is null.\n");
		return;
	}
	int len = List->linkedListLength;
	pLNode node = List->firstNode;

	for (int idx = 0; idx < len; idx++)
	{
		printf("Node %d : %d\n", idx, node->value);
		node = node->nextNode;
	}
}

//显示一个单链表结构中某个节点的负载元素值
void GetListNodeValueAt(const LinkedList *List, unsigned int pos)
{
	if (!List)
	{
		printf("Error: list is null.\n");
		return;
	}
	if (pos > List->linkedListLength)
	{
		printf("Error: index value exceeds the list length.\n");
		return;
	}

	pLNode node = List->firstNode;
	for (unsigned int idx = 0; idx < pos; idx++)
	{
		node = node->nextNode;
	}

	printf("Value at %d : %d\n", pos, node->value);
}
