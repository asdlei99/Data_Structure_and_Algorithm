#ifndef _CIRC_LINKED_LIST_H_
#define _CIRC_LINKED_LIST_H_

/********************
	ѭ������ڵ�ṹ
********************/
typedef struct _CLNode CLNode;
typedef struct _CLNode
{
	long value;			//ѭ������ڵ��е���Ч����ֵ
	CLNode *nextNode;	//ѭ������ڵ��е�ָ����ָ����һ�ڵ�
}CLNode, *pCLNode;

/********************
	ѭ������ṹ
********************/
typedef struct _CircLinkedList
{
	unsigned int linkedListLength;	//��������ܳ���
	pCLNode firstNode;	//��ǰ��������׽ڵ�ָ��
	pCLNode currentNode;		//������ǰ����ָ���ָ��
} CircLinkedList;

/*************************************************
  Function:		CreateCircLinkedListFromArray
  Description:	�Ӹ�����int�����鴴��һ��ѭ������
  Input:		(in)arr: �������ݵ�����
				(in)len: ��������ĳ���
  Output:		��
  Return:		ָ������ṹ��ָ��
*************************************************/
CircLinkedList* CreateCircLinkedListFromArray(const int *arr, int len);

/*************************************************
  Function:		FreeCircLinkedList
  Description:	�ͷ�һ��ѭ������Ľڵ�͵�������
  Input:		(in/out)LList: ϣ���ͷŵ�ѭ������ṹ
  Output:		��
  Return:		��
*************************************************/
void FreeCircLinkedList(CircLinkedList** LList);

/*************************************************
  Function:		ShowCircLinkedList
  Description:	��ʾһ��ѭ������ṹ�����еĽڵ�ĸ���Ԫ��ֵ
  Input:		(in)LList: ϣ����ʾ�ĵ�����ṹ
  Output:		��
  Return:		��
*************************************************/
void ShowCircLinkedList(const CircLinkedList *cList);

#endif