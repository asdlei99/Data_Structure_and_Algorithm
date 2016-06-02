#第一章 · 数据结构与算法基础

---
##一、数据结构和算法的基本概念

所谓数据结构，指的是相互之间存在一种或多种特定关系的数据元素的集合。通常，一个数据结构中的数据元素可能有以下几种基本结构：

1. 线性结构：结构中的数据元素存在一对一的关系；
2. 树形结构：结构中的数据元素之间存在一对多的关系；
3. 网状结构：又称图状结构，结构中的数据元素之间存在多对多的关系；

对于结构中各种数据之间的关系，通常指的是数据元素之间的“逻辑关系”。而数据在计算机中实际保存的方式属于“存储结构”，存储结构通常在底层决定了对数据结构进行操作的方法。通常数据结构常见的存储结构有：

1. 顺序存储结构：数据元素之间以存储单元的相对位置来表示逻辑关系；
2. 链式存储结构：数据元素之间以指针的方式来表示逻辑关系；

---
##二、算法和算法分析

算法通常是指对特定问题求解的一种描述。算法应由指令的有限序列构成，每一个指令执行一个或多个基本操作。此外，算法的特性还有：

1. 有穷性：每一个算法在合法输入的情况下，都必须在有限时间内，通过有限步骤结束；
2. 确定性：对于确定的输入，必须只能有唯一的执行路径，相同输入只能产生相同的结果；
3. 可行性：算法的操作必须是可以通过执行有限次已经实现的运算步骤得到；
4. 输入和输出：一个算法可以有[0, n]个输入和[1, n]个输出，各个输入值取自于某个输入集合，而输出值也有着某些特定关系。

设计一个算法应当有以下要求：

1. 正确性：一个正确的算法应当对所有的合法输入数据都产生合理的结果；
2. 可读性：算法的行文表述应当符合大部分阅读代码的开发者的基本风格，便于开发和调试；
3. 健壮性：对于非法的输入数据，算法应当能正确识别并作出适当的处理；
4. 高效率与低存储量：最理想的算法应当尽量降低执行的复杂度，并消耗较少的存储空间。

### 1. 算法效率的度量：

一个算法的实现通常是由某一基本操作以及执行操作的控制结构实现。比较算法的效率通常选定某一基本操作，再以重复执行该基本操作的次数为算法的时间度量。而该时间度量的判定通常依据问题规模n的增大来表示，通常可写作如下表达式：

	T(n) = O(f(n))

这个表达式表示随着问题规模n的不断增大，算法的执行时间与f(n)的增长率相同。比如代码段1：

	//code segment 1
	{ 
		x++;
		s = 0;
	}

这段代码中x自增操作只执行一次，因此其时间复杂度为O(1)，也称作常量阶。

在代码段2中：

	for(int i = 0; i <= n; i++)
	{
		x++;
		s += x; 
	}

这段代码中，x自增操作与n的大小成正比例相关，因此其时间复杂度为O(n)，也称作线性阶。

在代码段3中：

	for (int i = 0; i <= n; i++)
	{
		for (int i = 0; i <= n; i++)
		{
			x++;
			s += x; 
		}
	}

这段代码中的时间复杂度为O(n^2)，又称作平方阶。

此外，算法还可能呈现指数阶O(x^n)或者对数阶O(logn)等不同的量级。

###2. 算法的存储空间需求

算法在运行时所需要的存储空间的度量。程序在运行时需要内存空间来保存程序本身的数据，以及对数据进行操作和存储所需的内存空间。如果出了程序以外的额外空间相对于输入数据量而言不变，则该算法为**原地工作**，例如有些排序算法。而有些所需要的额外空间依赖于问题的规模，那么需要按照最坏情况分析。

---
#第二章 · 链表

链表是线性存储结构的一种实现方式。另一种方式是顺序存储方式，代表方法是静态数组。与数组相比，链表的优点是整个表的长度可以随着数据的数量变化而变化，不需担心空间浪费或不足的问题。而链表的缺点是获取某一个元素必须从头开始遍历，不能像数组一样可以根据元素序号方便地随机存取。

在实现方式上，构成链表的基本元素是**节点**。每一个节点都包含负载数据和指向下一个节点的指针。多个节点通过指针相互连接，构成了不同类型的链表。常见的由单链表、双向链表、循环链表等。

## 1. 单链表

### (1). 单链表的定义

链表有多种不同分类，其中单链表是最简单的一种。单链表的每一个节点除了数据域之外，只包含一个指针域，这个指针域指向的是这个节点的后继节点。一个单链表的节点可以定义为如下格式：

	typedef struct _LNode LNode;
	typedef struct _LNode
	{
		long value;
		LNode *nextNode;
	}LNode, *pLNode;

而一个单链表的头，实际上就是一个节点的指针。另外还可以加一个表示整个链表长度的值，以及当前正在操作的节点的指针：

	typedef struct _LinkedListHeader
	{
		int linkedListLength;
		pLNode firstNode;
		pLNode currentNode;
	} LinkedListHeader;

### (2). 单链表相关算法

创建单链表：

	//从给定的int型数组创建一个单链表
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
				list->firstNode = list->currentNode = node; //设置第一个节点
			}
			else
			{
				list->currentNode->nextNode = node;
				list->currentNode = list->currentNode->nextNode; 
			}
		}
	
		return list;
	}

释放单链表：

	//释放一个单链表的节点和单链表本身
	void FreeLindedList(LinkedList** List)
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

## 2、循环链表

循环链表顾名思义，是指其中存在循环结构的链表。事实上，循环链表的实现形式同单链表是相似的，唯一的区别在于其末尾的节点的后继不是空指针，而是指向头结点。通过这种方式形成一个闭环，这样，从链表的任何一个节点开始遍历都可以访问到其他所有节点。

循环链表的节点定义：

	typedef struct _CLNode CLNode;
	typedef struct _CLNode
	{
		long value;			//循环链表节点中的有效负载值
		CLNode *nextNode;	//循环链表节点中的指针域，指向下一节点
	}CLNode, *pCLNode;

实际上，可以看出循环链表节点的定义与单链表是相同的。在使用时，需注意判断循环链表是否到达结束的条件不是当前节点的后继是否为NULL，而是其后继是否指向头结点。比如在遍历输出循环链表元素中的循环判断条件：

	//显示一个循环链表结构中所有的节点的负载元素值
	void ShowCircLinkedList(const CircLinkedList *cList)
	{
		if (!cList)
		{
			printf("Error: Null CircLinkedList\n");
			return;
		}
		int idx = 0;
		pCLNode thisNode = cList->firstNode;
		while(thisNode->nextNode != cList->firstNode)
		{
			printf("Node %d: %d\n",idx++, thisNode->value);
			thisNode = thisNode->nextNode;
		}
		printf("Node %d: %d\n",idx++, thisNode->value);
	}

## 3、双向链表

链表的第三种形式是双向链表。双向链表的节点结构同单链表和循环链表不同，后两者都只有一个指针域，只能指向一个后继，而双向链表的节点包含两个指针域，分别指向当前节点的前驱和后继两个元素。双向链表的节点定义如下：

	typedef struct _DualNode DualNode;
	typedef struct _DualNode
	{
		long value;			//双向链表节点中的有效负载值
		DualNode *nextNode;	//双向链表节点中的指针域，指向下一节点
		DualNode *prevNode; //双向链表节点中的指针域，指向前一节点
	}DualNode, *pDualNode;

双向链表在涉及到遍历等操作时只针对一个方向进行操作，那么与单链表并无实质的差异。当涉及到插入、删除等操作时，需要同时修改两个方向上的指针。如创建双向链表的方法如下：

	//从给定的int型数组创建一个双向链表
	DualList* CreateDualListFromArray(const int *arr, int len)
	{
		if (len <= 0)
		{
			return NULL;
		}
	
		DualList *dlist = (DualList*)malloc(sizeof(DualList));
		dlist->linkedListLength = len;
		
		for (int idx = 0; idx < len; idx++)
		{
			pDualNode node = (pDualNode)malloc(sizeof(DualNode));
			node->value = arr[idx];
			node->prevNode = node->nextNode = NULL;
	
			if (idx == 0)
			{
				dlist->firstNode = dlist->currentNode = node;
			} 
			else
			{
				dlist->currentNode->nextNode = node;
				node->prevNode = dlist->currentNode;
				dlist->currentNode = dlist->currentNode->nextNode;
			}
		}
	
		return dlist;
	}

--- 

# 第三章 · 栈和队列

栈和队列分别都是极为常见的线性数据结构。这两种结构都可以看作是一种特殊的线性表，因为其存储结构依赖于线性表的实现，而其操作再线性表的基础上增加了一些限制。

## 1. 栈 

### (1). 栈的定义

栈是一种特殊的线性表，这种线性表只允许在尾部进行元素的添加和删除操作。栈中添加和删除元素的位置，即表的尾部，称为“栈顶”，表的头部称为“栈底”。栈中元素的出入按照“先入后出”的顺序执行，即第一个压入栈中的元素最后被弹出。

一个栈可用如下方式定义：
	
	/********************
		栈结构
	********************/
	typedef struct _Stack
	{
		unsigned stackSize;		//栈中当前元素个数
		unsigned stackCapacity;	//栈的总容量
		int		*stackBotton;
		int		*stackTop;
	} Stack;

### (2). 栈的操作

首先我们需要定义两个常量，分别表示栈的初始大小，以及增加栈空间时的大小：

	const unsigned int c_defaultStackSize = 10;
	const unsigned int c_defaultStackIncrement = 5;

初始化一个空栈的方法：
	
	//初始化一个空栈
	void Init_stack(Stack &s)
	{
		s.stackSize = 0;
		s.stackCapacity = c_defaultStackSize;
		s.stackBotton = (int *)malloc(s.stackCapacity * sizeof(int));
		s.stackTop = s.stackBotton;
		printf("Stack initialized, default capacity = %d.\n", s.stackCapacity);
	}

释放当前栈：

	//释放一个栈
	void Destroy_stack(Stack &s)
	{
		free(s.stackBotton);
		s.stackSize = s.stackCapacity = 0;
		s.stackBotton = s.stackTop = NULL;
	}

遍历栈中元素：
	
	//遍历一个栈中所有成员
	void Tranvers_stack(const Stack &s)
	{
		printf("Stack elements:\n");
		for (int idx = 0; idx < s.stackSize; idx++)
		{
			printf("%d\n",*(s.stackBotton + idx));
		}
		printf("\n");
	}

从栈顶弹出元素：

	//从栈s中弹出栈顶元素
	int Pop(Stack &s)
	{
		if (s.stackSize == 0)
		{
			printf("Stack is empty.\n");
			return -32767;
		}
	
		int ret = *(--s.stackTop);	
		s.stackSize--;
		return ret;
	}

对于将新元素压栈的操作，需要考虑的是如果当前的栈容量已经到达上限，那么需要重新分配栈的内存空间：
	
	//将元素val压入栈s中
	void Push(Stack &s, int val)
	{
		if (s.stackSize >= s.stackCapacity)
		{
			//当前栈已满
			void *temp = realloc(s.stackBotton, (s.stackCapacity += c_defaultStackIncrement) * sizeof (int));
			if (!temp)
			{
				Destroy_stack(s);
				return;
			}
			s.stackBotton = (int *)temp;
			printf("Stack capacity extended, new capacity: %d\n", s.stackCapacity);
		}
			
		*(s.stackTop) = val;
		s.stackSize++;
		s.stackTop++;
	}

## 2. 队列

### (1). 队列的定义

同栈类似，队列也是一种线性结构。队列与栈的不同点在于，后者只能在线性表的一端（即栈顶）增删元素，而前者则是在一端（队尾）添加元素，另一端（队首）删除元素。由于这种特性，一个队列中元素所占据的内存通常不是固定的，因此队列不适合使用顺序表存储，而更适用于链表结构来保存。

定义一个队列结构，一般需要包含队列长度、队列头和队列尾三个值：
	
	typedef struct _QueueNode *pQueueNode;
	typedef struct _QueueNode
	{
		int value;
		pQueueNode nextNode;
	} QueueNode, *pQueueNode;
	
	typedef struct _Queue
	{
		unsigned int length;
		pQueueNode queueHead;
		pQueueNode queueRear;
	} Queue;

### (2). 队列的操作

初始化一个空的队列：
	
	void Init_queue(Queue &queue)
	{
		queue.length = 0;
		queue.queueHead = queue.queueRear = NULL;
	}

清空队列：
	
	void Empty_queue(Queue &queue)
	{
		pQueueNode thisNode = NULL;
	
		while(queue.queueHead != queue.queueRear)
		{
			thisNode = queue.queueHead;
			queue.queueHead = queue.queueHead->nextNode;
			free(thisNode);
		}
		queue.queueHead = queue.queueRear = NULL;
		queue.length = 0;
	}

从队列尾向队列中添加数据：
	
	void Push_queue(int value, Queue &queue)
	{
		pQueueNode node = (pQueueNode)malloc(sizeof(QueueNode));
		node->value = value;
		node->nextNode = NULL;
	
		if (queue.length == 0)
		{
			//空队列添加第一个节点
			queue.queueRear = queue.queueHead = node;
		}
		else
		{
			queue.queueRear->nextNode = node;
			queue.queueRear = queue.queueRear->nextNode;
		}
	
		queue.length++;
	}

从队列头取出数据：
	
	int Pop_queue(Queue &queue)
	{
		if (queue.length == 0)
		{
			printf("Error: cannot pop from empty queue\n");
			exit(-1);
		}
	
		pQueueNode head = queue.queueHead;
		int retVal = head->value;
		queue.queueHead = queue.queueHead->nextNode;
		free(head);
	
		queue.length--;
		return retVal;
	}
