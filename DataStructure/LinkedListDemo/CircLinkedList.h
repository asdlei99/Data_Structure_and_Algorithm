#ifndef _CIRC_LINKED_LIST_H_
#define _CIRC_LINKED_LIST_H_

/********************
	循环链表节点结构
********************/
typedef struct _CLNode CLNode;
typedef struct _CLNode
{
	long value;			//循环链表节点中的有效负载值
	CLNode *nextNode;	//循环链表节点中的指针域，指向下一节点
}CLNode, *pCLNode;

/********************
	循环链表结构
********************/
typedef struct _CircLinkedList
{
	unsigned int linkedListLength;	//单链表的总长度
	pCLNode firstNode;	//当前单链表的首节点指针
	pCLNode currentNode;		//单链表当前正在指向的指针
} CircLinkedList;

/*************************************************
  Function:		CreateCircLinkedListFromArray
  Description:	从给定的int型数组创建一个循环链表
  Input:		(in)arr: 保存数据的数组
				(in)len: 整个链表的长度
  Output:		无
  Return:		指向单链表结构的指针
*************************************************/
CircLinkedList* CreateCircLinkedListFromArray(const int *arr, int len);

/*************************************************
  Function:		FreeCircLinkedList
  Description:	释放一个循环链表的节点和单链表本身
  Input:		(in/out)LList: 希望释放的循环链表结构
  Output:		无
  Return:		无
*************************************************/
void FreeCircLinkedList(CircLinkedList** LList);

/*************************************************
  Function:		ShowCircLinkedList
  Description:	显示一个循环链表结构中所有的节点的负载元素值
  Input:		(in)LList: 希望显示的单链表结构
  Output:		无
  Return:		无
*************************************************/
void ShowCircLinkedList(const CircLinkedList *cList);

#endif