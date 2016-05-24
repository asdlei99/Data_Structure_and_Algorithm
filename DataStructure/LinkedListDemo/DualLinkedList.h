#ifndef _DUAL_LINKED_LIST_H_
#define _DUAL_LINKED_LIST_H_

/********************
	双向链表节点结构
********************/
typedef struct _DualNode DualNode;
typedef struct _DualNode
{
	long value;			//双向链表节点中的有效负载值
	pDualNode nextNode;	//双向链表节点中的指针域，指向下一节点
	pDualNode prevNode; //双向链表节点中的指针域，指向前一节点
}DualNode, *pDualNode;

#endif