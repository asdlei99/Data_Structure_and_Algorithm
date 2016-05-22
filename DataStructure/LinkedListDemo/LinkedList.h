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
	unsigned int linkedListLength;	//��������ܳ���
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
void ShowLinkedList(const LinkedList *List);

/*************************************************
  Function:		GetListNodeValueAt
  Description:	��ʾһ��������ṹ��ĳ���ڵ�ĸ���Ԫ��ֵ
  Input:		(in)LList: ϣ����ʾ�ĵ�����ṹ
				(in)idx��ϣ����ʾ�Ľڵ������
  Output:		��
  Return:		��
*************************************************/
void GetListNodeValueAt(const LinkedList *List, unsigned int pos);

/*************************************************
  Function:		InsertNodeAt
  Description:	��һ��������ṹ�е�ָ��λ�ò���һ���ڵ�
  Input:		(in/out)LList: ϣ����ʾ�ĵ�����ṹ
				(in)idx��ϣ����ʾ�Ľڵ������
				(in)value: ����ڵ�ĸ���Ԫ��ֵ
  Output:		��
  Return:		��
*************************************************/
void InsertNodeAt(LinkedList *List, unsigned int pos, int value);

/*************************************************
  Function:		DeleteNodeAt
  Description:	ɾ��һ��������ṹ�е�ָ��λ�õĽڵ�
  Input:		(in/out)LList: ϣ��ɾ���ڵ�ĵ�����ṹ
				(in)idx��ϣ��ɾ���Ľڵ������
  Output:		��
  Return:		��
*************************************************/
void DeleteNodeAt(LinkedList *List, unsigned int pos);

#endif