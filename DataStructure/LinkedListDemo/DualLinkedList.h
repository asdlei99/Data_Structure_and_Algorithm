#ifndef _DUAL_LINKED_LIST_H_
#define _DUAL_LINKED_LIST_H_

/********************
	双向链表节点结构
********************/
typedef struct _DualNode DualNode;
typedef struct _DualNode
{
	long value;			//双向链表节点中的有效负载值
	DualNode *nextNode;	//双向链表节点中的指针域，指向下一节点
	DualNode *prevNode; //双向链表节点中的指针域，指向前一节点
}DualNode, *pDualNode;

/********************
	双向链表结构
********************/
typedef struct _DualListHeader
{
	unsigned int linkedListLength;	//双向链表的总长度
	pDualNode firstNode;	//当前双向链表的首节点指针
	pDualNode currentNode;		//双向链表当前正在指向的指针
} DualList;

/*************************************************
  Function:		CreateDualListFromArray
  Description:	从给定的int型数组创建一个双向链表
  Input:		(in)arr: 保存数据的数组
				(in)len: 整个链表的长度
  Output:		无
  Return:		指向双向链表结构的指针
*************************************************/
DualList* CreateDualListFromArray(const int *arr, int len);

/*************************************************
  Function:		FreeDualList
  Description:	释放一个双向链表的节点和双向链表本身
  Input:		(in/out)LList: 希望释放的双向链表结构
  Output:		无
  Return:		无
*************************************************/
void FreeDualList(DualList** dList);

/*************************************************
  Function:		ShowDualList
  Description:	显示一个双向链表结构中所有的节点的负载元素值
  Input:		(in)LList: 希望显示的双向链表结构
  Output:		无
  Return:		无
*************************************************/
void ShowDualList(const DualList *List);

#endif