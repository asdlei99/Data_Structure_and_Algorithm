#include "stdafx.h"
#include "DualLinkedList.h"

//从给定的int型数组创建一个双向链表
DualList* CreateDualListFromArray(const int *arr, int len)
{
	if (len <= 0)
	{
		return NULL;
	}

	DualList *dlist = (DualList*)malloc(sizeof(DualList));
	dlist->linkedListLength = len;
	
	for (int idx = 0; idx < len; idx++)
	{
		pDualNode node = (pDualNode)malloc(sizeof(DualNode));
		node->value = arr[idx];
		node->prevNode = node->nextNode = NULL;

		if (idx == 0)
		{
			dlist->firstNode = dlist->currentNode = node;
		} 
		else
		{
			dlist->currentNode->nextNode = node;
			node->prevNode = dlist->currentNode;
			dlist->currentNode = dlist->currentNode->nextNode;
		}
	}

	return dlist;
}

//释放一个双向链表的节点和双向链表本身
void FreeDualList(DualList** dList)
{
	DualList *dualList = *dList;
	if (!dualList)
	{
		return;
	}

	int len = dualList->linkedListLength;
	pDualNode thisNode = dualList->firstNode;

	while(!thisNode->nextNode)
	{
		pDualNode nextNode = thisNode->nextNode;
		free(thisNode);
		thisNode = nextNode;
	}

	free(thisNode);
	free(*dList);
	*dList = NULL;
}

//显示一个双向链表结构中所有的节点的负载元素值
void ShowDualList(const DualList *List)
{
	if (!List)
	{
		return;
	}

	int len = List->linkedListLength;
	pDualNode node = List->firstNode;
	for (int idx = 0; idx < len; idx++)
	{
		printf("Node %d : %d\n", idx, node->value);
		node = node->nextNode;
	}
}
