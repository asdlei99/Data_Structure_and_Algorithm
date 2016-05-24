#include "stdafx.h"
#include "CircLinkedList.h"

//从给定的int型数组创建一个循环链表
CircLinkedList* CreateCircLinkedListFromArray(const int *arr, int len)
{
	if (0 >= len)
	{
		return NULL;
	}

	CircLinkedList *list = (CircLinkedList *)malloc(sizeof(CircLinkedList));
	list->linkedListLength = len;
	pCLNode node = NULL;

	for (int idx = 0; idx < len; idx++)
	{
		node = (pCLNode)malloc(sizeof(CLNode));
		node->value = arr[idx];
		node->nextNode = NULL;

		if (idx == 0)
		{
			list->currentNode = list->firstNode = node;			
		} 
		else
		{
			list->currentNode->nextNode = node;
			list->currentNode = list->currentNode->nextNode;
		}
	}

	//将末尾节点的后继指向头节点
	list->currentNode->nextNode = list->firstNode;

	return list;
}

//释放一个循环链表的节点和单链表本身
void FreeCircLinkedList(CircLinkedList** LList)
{
	CircLinkedList *clist = *LList;
	if (!clist)
	{
		printf("Error: Null CircLinkedList\n");
		return;
	}

	pCLNode thisNode = clist->firstNode->nextNode;
	while(thisNode != clist->firstNode)
	{
		pCLNode nextCNode = thisNode->nextNode;
		free(thisNode);
		thisNode = nextCNode;
	}

	free(thisNode);
	free(*LList);
	*LList = NULL;
}

//显示一个循环链表结构中所有的节点的负载元素值
void ShowCircLinkedList(const CircLinkedList *cList)
{
	if (!cList)
	{
		printf("Error: Null CircLinkedList\n");
		return;
	}
	int idx = 0;
	pCLNode thisNode = cList->firstNode;
	while(thisNode->nextNode != cList->firstNode)
	{
		printf("Node %d: %d\n",idx++, thisNode->value);
		thisNode = thisNode->nextNode;
	}
	printf("Node %d: %d\n",idx++, thisNode->value);
}
