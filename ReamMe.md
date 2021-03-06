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

---
# 第四章 · 二叉树

前面几章所描述的链表、栈和队列均属于线性结构。而在非线性结构中，树是一种非常常用的类型。而二叉树是树形结构中一种常用的特例，在查找、排序等操作中具有重要意义。

## 1、树与二叉树

在数据结构中，树是有限个节点的集合。对于一个非空树，有且仅有一个节点作为根节点root。根节点可能存在若干个子节点，每一个子节点又各自是一个树的根节点。树中每一个节点的上级称作父节点，而下级称作子节点，一个节点只与其父节点和子节点又直接联系。两个同属于一个父节点的节点称为兄弟节点，兄弟节点之间并不存在直接的联系。一个树的节点通过这种组织形式形成一种层次的结构。一个树中每一个节点的子树的个数称为节点的度，距离根节点最远的终端节点（即度为0的节点）的层数为树的深度。

如果一个树的每一个节点最多只能有两个子树，那么这个树就是一个二叉树。二叉树的子树区分左右，不能随便交换。如果一个二叉树深度为k且有2^k-1个节点，即每一层的节点全部铺满，则该二叉树称为满二叉树。如果一个二叉树从上到下、从左到右，只有最后一层的最后几个节点空缺，那么该二叉树称为完全二叉树。

相对于普通的树，二叉树具有一些特殊的特性：

1. 二叉树的第i层最多有2^(i-1)个节点；
2. 深度为k的二叉树最多有2^k-1个节点；
3. 任意二叉树的终端节点比满节点（即度为2的节点）多1个；
4. 包含n个节点的完全二叉树深度为floor(log2(n))+1;
5. 将完全二叉树的节点按顺序编号：
	1. 编号i节点的父节点为floor(i/2)，根节点除外；
	2. 节点i的左右子节点分别为2i和2i+1，除非2i和2i+1超过了n，那么节点i是终端节点；

##2、二叉树的存储结构

一个二叉树由于存在多个链接关系，因此适宜使用链式存储结构，每一个节点包含一个数据域和三个指针域，分别指向父节点和左右子节点。通常声明如下：
	
	typedef struct _BinTreeNode BinTreeNode;
	typedef struct _BinTreeNode
	{
		int value;
		BinTreeNode *parentNode;
		BinTreeNode *leftSubTree;
		BinTreeNode *rightSubTree;
	} BinTreeNode;

## 3、二叉树的遍历

与链表、栈与队列等线性结构不同，由于二叉树是一种非线性结构，所以对于二叉树的遍历需要考虑每个节点的两个子树的遍历先后顺序的问题。通常二叉树的遍历方法分为三种：先序遍历、中序遍历和后序遍历。

1. 二叉树的先序遍历
	1. 访问根节点
	2. 先序遍历左子树
	3. 先序遍历右子树
2. 二叉树的中序遍历
	1. 中序遍历左子树
	2. 访问根节点
	3. 中序遍历右子树
3. 二叉树的后序遍历
	1. 后序遍历左子树
	2. 后序遍历右子树
	3. 访问根节点

---
#第五章 · 图

## 1、 图的概念

除了树之外，图是另一种非线性的数据结构，而且图相对于树更为复杂。树的节点元素之间存在明显的层次关系，而图的各个元素之间的关系可以使任意的，因此图中的节点更加类似于一种网状结构。

在一个图中，数据元素称为**顶点**。根据顶点之间关系的方向性，图可以分为**有向图**和**无向图**两大类。

- 如果一个图中两个顶点没有起止关系，则该图称为**无向图**，此时两个顶点之间的联系称为**边**；
- 若一个图中两个顶点有明确的起止关系，即从一个顶点指向另一个顶点，则该图称为**有向图**，两个顶点之间的联系称为**弧**，弧的起点称为**弧头**，弧的重点称为**弧尾** 。

如果一个无向图中包含n个节点，那么最多含有n(n-1)/2条边，如果这些边全部存在，那么该图称为**完全图**。如果是一个有向图的话，其弧的总数最多为n(n-1)，这些弧全部存在的图称之为**完全有向图** 。如果一个图的边或弧携带权值，那么该图又称作**网** 。

对于无向图中的某一个顶点，与该顶点相连接的边称为该顶点的**度**。 对于有向图来说，还需根据与该顶点链接的弧的方向分为 **入度** 和 **出度**。 

从一个图中取出部分节点与相关的边或弧便形成了原图的一个**子图**。 在一个无向图中，如果任意两个顶点都是连通的（即存在一条由此及彼的路径），那么该图称作一个**连通图**。 如果一个图是非连通的，其内部每一个极大连通子图称为其**连通分量**。 对于有向图，任意两个节点之间存在有向路径，则该图称为**强连通图**。其内部的极大强连通子图称为**强连通分量**。 

一个连通图还包含一种特殊的子图，这类子图包含图中所有的n个顶点，但只有n-1条边，这n-1条边刚好可以生成一个树结构。这样的树结构称之为**生成树**。

## 2、 图的遍历

同树类似，图的遍历要求从某一个顶点出发，依次访问图中剩余的所有节点，每个节点必须且只能访问一次。由于图的网状结构，遍历图的顶点远比遍历树更加复杂。遍历图通常有两种方法：**深度优先搜索** 和 **广度优先搜索**。

###(1). 深度优先搜索

深度优先搜索类似于树的先序遍历。在搜索的开始阶段，图中所有的顶点都未被访问，此时选择一个顶点作为搜索的起始顶点。首先访问起始顶点，然后从该顶点尚未被访问的邻接点中选择一个递归执行深度优先搜索，直至所有与起始顶点连通的节点都被访问。而后，若还有未被访问的顶点，则选中某一个未访问的顶点继续深度优先搜索，直到所有顶点都被访问。

###(2). 广度优先搜索

广度优先搜索类似于树的层次遍历。广度优先搜索从某一个顶点开始，依次访问与该顶点链接的每一个顶点。在于该顶点直接相连的顶点被访问完成之后，再依次从这些顶点出发，访问与其直接相连的顶点。递归执行这一过程，直至与起始顶点连通的所有顶点都被访问到。如果此时还有其他顶点未被访问，则选择其中一个再次执行递归遍历过程。

---
#第六章 · 查找

查找是数据结构与算法中重要的应用场景。查找操作希望从一组同一类型的数据元素集合中查询某一个元素。这组数据元素的集合称之为**查找表**。查找表通常所需要的操作有：

1. 查询某个特定元素是否存在；
2. 检索某个特定元素的各种属性；
3. 在查找表中插入一个元素；
4. 向查找表中新增一个元素；

通常查找表可分为两类：

- 静态查找表：只能在查找表中进行查询操作；
- 动态查找表：可以在查询过程中进行增加或删除操作。

##1. 静态查找表

静态查找表的形式主要有静态线性表、静态树形表和索引线性表等，这里主要讨论静态线性表。静态线性表的查找方式根据数据特性的不同可以采用不同的方式。

###(1)、无序表

如果线性查找表中的所有元素是乱序的，那么只有通过依次遍历的方式进行查找，这种方式为顺序查找法。顺序查找法的时间复杂度为O(n)。

###(2)、有序表

如果一个线性表中所欲的元素都按照顺序排列好，那么可以提高查找的效率。对于有序表，可以采用二分法查找。

二分法的查找过程为：确定目标元素的范围，然后逐步递归缩小查找范围，直到查找到目标元素或者确认查找失败。二分法查找的时间复杂度为O(logn)。

##2. 动态查找表

动态查找表相对于静态查找表的特点是，动态查找表本身是在查找过程中动态生成的。对于一个待查找的目标数据，如果查找表中存在该元素，则查找成功；否则将该元素插入查找表中。

###(1)二叉排序树

二叉排序树又称作二叉查找树，这是一种特殊的二叉树。一个非空的二叉排序树的主要特点是：该树中某一个节点的非空左子树中的所有节点的值都小于该节点，所有非空右子树的所有节点的值都大于该节点。

二叉排序树通常不是一次生成的，新节点在查找失败时添加在查找路径上最后一个节点的左或右子节点。从一个空树出发，经过一系列查找插入操作，可以生成一个二叉排序树，然后对这个二叉排序树进行中序遍历则可以产生一个有序的元素序列。

如果希望从二叉排序树中删除一个节点，那么需要分多钟情况。如果要删除的节点是一个终端节点，那么直接将该节点删除即可；如果要删除的节点的度为1，即只有一个左子树或右子树，那么只需在删除节点之后，将该子树接到该节点的父节点上；如果要删除的节点度为2，即有左子树和右子树，那么情况将比较复杂。

如果希望删除的节点有两个子树，那么必须重新组织二叉排序树的结构。根据二叉排序树的特性，按照中序遍历，这个节点左子树最右下的终端节点为其直接前驱，右子树最左下的节点为其直接后继。所以，如果希望删除一个度为2的节点，可以有两种实现方法：1、将节点删去后，将左子树接到该节点的位置上，将右子树接到右子树最左下节点（也就是其直接前驱）的右子树上；2、保持该节点的左子节点不变，将左子树的最右下节点（该节点一定无右子节点）替换到该节点的位置，如果左子树最右下节点还有左子树的话，这个左子树接到该节点的位置上。

对于二叉排序树的查找，其平均运算复杂度为O(logn)。

###(2)平衡二叉树

平衡二叉树是一种特殊的二叉排序树。它的特点是：平衡二叉树及其任意的子树，其左右两个子树的深度差最大不超过1。对一个平衡二叉树插入一个节点可能会导致二叉树失去平衡性，此时需要对二叉树进行再次调整，使其重新恢复平衡性。根据插入节点的位置不同，调整二叉树可分为4种情况：

假设因为插入节点而失去平衡性的二叉树子树的根节点为A，其两个子节点分别为Al和Ar，那么：

1. 如果是在节点Al的左子树上插入一个节点导致不平衡，那么需要对Al进行一次右旋平衡处理；
2. 如果是在Ar的右子树上插入一个节点导致不平衡，那么需要对Ar进行一次左旋平衡处理；
3. 如果在Al的右子树上插入一个节点导致不平衡，那么需要先对Al进行一次左旋，再对A进行一次右旋操作；
4. 如果在Ar的左子树上插入一个节点导致不平衡，那么需要先对Ar进行一次右旋，再对A进行一次左旋操作。

使用平衡二叉树进行查找的运算复杂度为O(logn)。

###(3)哈希表

哈希表是一种特殊的查找表，在哈希表中，元素的实际存储位置与关键字之间存在确定的关系，这个关系称之为**哈希函数**。这样，在查询时就不再需要各种遍历算法，而是可以通过关键字和哈希函数直接计算出元素的位置。

哈希函数的构造方法主要有：直接定址法、数字分析法、平方取中法、折叠法、除留余数法等。

在使用哈希表中极可能遇到的一个问题就是**冲突**。所谓的冲突，指的是不同的关键字经过哈希函数，定位到了同一个元素地址。事实上，无论设计怎样的哈希函数，只可能尽量降低冲突的概率，不可能完全将冲突消除。处理冲突的方法主要有：开放定址法、再哈希法、链地址发和公共溢出区等。

---
#第七章 · 内部排序

排序操作是计算机另一项最基本的操作之一，其功能是将一系列乱序的数据元素排列为一个按照关键字有序排列的序列。排序操作通常可以分为内部排序和外部排序两类，前者的排序操作全部在计算机内存内部实现，后者需借助外部存储空间实现更大规模的排序。