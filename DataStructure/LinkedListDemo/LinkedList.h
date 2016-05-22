#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

/********************
	单链表节点结构
********************/
typedef struct _LNode LNode;
typedef struct _LNode
{
	long value;			//单链表节点中的有效负载值
	LNode *nextNode;	//单链表节点中的指针域，指向下一节点
}LNode, *pLNode;

/********************
	单链表结构
********************/
typedef struct _LinkedListHeader
{
	unsigned int linkedListLength;	//单链表的总长度
	pLNode firstNode;	//当前单链表的首节点指针
	pLNode currentNode;		//单链表当前正在指向的指针
} LinkedList;

/*************************************************
  Function:		CreateLinkedListFromArray
  Description:	从给定的int型数组创建一个单链表
  Input:		(in)arr: 保存数据的数组
				(in)len: 整个链表的长度
  Output:		无
  Return:		指向单链表结构的指针
*************************************************/
LinkedList* CreateLinkedListFromArray(const int *arr, int len);

/*************************************************
  Function:		CreateLinkedListFromArray
  Description:	释放一个单链表的节点和单链表本身
  Input:		(in/out)LList: 希望释放的单链表结构
  Output:		无
  Return:		无
*************************************************/
void FreeLinkedList(LinkedList** LList);

/*************************************************
  Function:		ShowLinkedList
  Description:	显示一个单链表结构中所有的节点的负载元素值
  Input:		(in)LList: 希望显示的单链表结构
  Output:		无
  Return:		无
*************************************************/
void ShowLinkedList(const LinkedList *List);

/*************************************************
  Function:		GetListNodeValueAt
  Description:	显示一个单链表结构中某个节点的负载元素值
  Input:		(in)LList: 希望显示的单链表结构
				(in)idx：希望显示的节点的索引
  Output:		无
  Return:		无
*************************************************/
void GetListNodeValueAt(const LinkedList *List, unsigned int pos);

/*************************************************
  Function:		InsertNodeAt
  Description:	在一个单链表结构中的指定位置插入一个节点
  Input:		(in/out)LList: 希望显示的单链表结构
				(in)idx：希望显示的节点的索引
				(in)value: 插入节点的负载元素值
  Output:		无
  Return:		无
*************************************************/
void InsertNodeAt(LinkedList *List, unsigned int pos, int value);

/*************************************************
  Function:		DeleteNodeAt
  Description:	删除一个单链表结构中的指定位置的节点
  Input:		(in/out)LList: 希望删除节点的单链表结构
				(in)idx：希望删除的节点的索引
  Output:		无
  Return:		无
*************************************************/
void DeleteNodeAt(LinkedList *List, unsigned int pos);

#endif