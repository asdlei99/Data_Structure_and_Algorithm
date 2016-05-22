#include "stdafx.h"
#include "LinkedList.h"

//�Ӹ�����int�����鴴��һ��������
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
			list->firstNode = list->currentNode = node; //���õ�һ���ڵ�
		}
		else
		{
			list->currentNode->nextNode = node;
			list->currentNode = list->currentNode->nextNode; 
		}
	}

	return list;
}

//�ͷ�һ��������Ľڵ�͵�������
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

//��ʾһ��������ṹ�����еĽڵ�ĸ���Ԫ��ֵ
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

//��ʾһ��������ṹ��ĳ���ڵ�ĸ���Ԫ��ֵ
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
