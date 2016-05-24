#include "stdafx.h"
#include "DualLinkedList.h"

//�Ӹ�����int�����鴴��һ��˫������
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

//�ͷ�һ��˫������Ľڵ��˫��������
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

//��ʾһ��˫������ṹ�����еĽڵ�ĸ���Ԫ��ֵ
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
