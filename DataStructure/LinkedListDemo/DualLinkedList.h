#ifndef _DUAL_LINKED_LIST_H_
#define _DUAL_LINKED_LIST_H_

/********************
	˫������ڵ�ṹ
********************/
typedef struct _DualNode DualNode;
typedef struct _DualNode
{
	long value;			//˫������ڵ��е���Ч����ֵ
	pDualNode nextNode;	//˫������ڵ��е�ָ����ָ����һ�ڵ�
	pDualNode prevNode; //˫������ڵ��е�ָ����ָ��ǰһ�ڵ�
}DualNode, *pDualNode;

#endif