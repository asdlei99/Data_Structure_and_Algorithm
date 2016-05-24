#include "stdafx.h"
#include "CircLinkedList.h"

//�Ӹ�����int�����鴴��һ��ѭ������
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

	//��ĩβ�ڵ�ĺ��ָ��ͷ�ڵ�
	list->currentNode->nextNode = list->firstNode;

	return list;
}

//�ͷ�һ��ѭ������Ľڵ�͵�������
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

//��ʾһ��ѭ������ṹ�����еĽڵ�ĸ���Ԫ��ֵ
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
