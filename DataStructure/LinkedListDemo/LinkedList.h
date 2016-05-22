#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

/********************
	������ڵ�ṹ
********************/
typedef struct _LNode LNode;
typedef struct _LNode
{
	long value;			//������ڵ��е���Ч����ֵ
	LNode *nextNode;	//������ڵ��е�ָ����ָ����һ�ڵ�
}LNode, *pLNode;

/********************
	������ṹ
********************/
typedef struct _LinkedListHeader
{
	int linkedListLength;	//��������ܳ���
	pLNode firstNode;	//��ǰ��������׽ڵ�ָ��
	pLNode currentNode;		//������ǰ����ָ���ָ��
} LinkedList;

/*************************************************
  Function:		CreateLinkedListFromArray
  Description:	�Ӹ�����int�����鴴��һ��������
  Input:		(in)arr: �������ݵ�����
				(in)len: ��������ĳ���
  Output:		��
  Return:		ָ������ṹ��ָ��
*************************************************/
LinkedList* CreateLinkedListFromArray(const int *arr, int len);

/*************************************************
  Function:		CreateLinkedListFromArray
  Description:	�ͷ�һ��������Ľڵ�͵�������
  Input:		(in/out)LList: ϣ���ͷŵĵ�����ṹ
  Output:		��
  Return:		��
*************************************************/
void FreeLinkedList(LinkedList** LList);

/*************************************************
  Function:		ShowLinkedList
  Description:	��ʾһ��������ṹ�����еĽڵ�ĸ���Ԫ��ֵ
  Input:		(in)LList: ϣ����ʾ�ĵ�����ṹ
  Output:		��
  Return:		��
*************************************************/
void ShowLinkedList(const LinkedList &List);

#endif