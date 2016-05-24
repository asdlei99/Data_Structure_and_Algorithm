#ifndef _DUAL_LINKED_LIST_H_
#define _DUAL_LINKED_LIST_H_

/********************
	˫������ڵ�ṹ
********************/
typedef struct _DualNode DualNode;
typedef struct _DualNode
{
	long value;			//˫������ڵ��е���Ч����ֵ
	DualNode *nextNode;	//˫������ڵ��е�ָ����ָ����һ�ڵ�
	DualNode *prevNode; //˫������ڵ��е�ָ����ָ��ǰһ�ڵ�
}DualNode, *pDualNode;

/********************
	˫������ṹ
********************/
typedef struct _DualListHeader
{
	unsigned int linkedListLength;	//˫��������ܳ���
	pDualNode firstNode;	//��ǰ˫��������׽ڵ�ָ��
	pDualNode currentNode;		//˫������ǰ����ָ���ָ��
} DualList;

/*************************************************
  Function:		CreateDualListFromArray
  Description:	�Ӹ�����int�����鴴��һ��˫������
  Input:		(in)arr: �������ݵ�����
				(in)len: ��������ĳ���
  Output:		��
  Return:		ָ��˫������ṹ��ָ��
*************************************************/
DualList* CreateDualListFromArray(const int *arr, int len);

/*************************************************
  Function:		FreeDualList
  Description:	�ͷ�һ��˫������Ľڵ��˫��������
  Input:		(in/out)LList: ϣ���ͷŵ�˫������ṹ
  Output:		��
  Return:		��
*************************************************/
void FreeDualList(DualList** dList);

/*************************************************
  Function:		ShowDualList
  Description:	��ʾһ��˫������ṹ�����еĽڵ�ĸ���Ԫ��ֵ
  Input:		(in)LList: ϣ����ʾ��˫������ṹ
  Output:		��
  Return:		��
*************************************************/
void ShowDualList(const DualList *List);

#endif