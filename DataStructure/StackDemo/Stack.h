#ifndef _STACK_H_
#define _STACK_H_

const unsigned int c_defaultStackSize = 10;
const unsigned int c_defaultStackIncrement = 5;

/********************
	栈结构
********************/
typedef struct _Stack
{
	unsigned stackSize;
	unsigned stackCapacity;
	int		*stackBotton;
	int		*stackTop;
} Stack;

/*************************************************
  Function:		Init_stack
  Description:	初始化一个空栈
  Input:		(in/out)s: 初始化的栈结构
  Output:		无
  Return:		无
*************************************************/
void Init_stack(Stack &s);

/*************************************************
  Function:		Destroy_stack
  Description:	释放一个栈
  Input:		(in/out)s: 要释放的栈结构
  Output:		无
  Return:		无
*************************************************/
void Destroy_stack(Stack &s);

/*************************************************
  Function:		Tranvers_stack
  Description:	遍历一个栈中所有成员
  Input:		(in)s: 要释放的栈结构
  Output:		无
  Return:		无
*************************************************/
void Tranvers_stack(const Stack &s);

/*************************************************
  Function:		Push
  Description:	将元素val压入栈s中
  Input:		(in)s: 目标栈结构
				(in)val：要压入栈中的元素
  Output:		无
  Return:		无
*************************************************/
void Push(Stack &s, int val);

/*************************************************
  Function:		Pop
  Description:	从栈s中弹出栈顶元素
  Input:		(in)s: 目标栈结构				
  Output:		无
  Return:		弹出的栈顶元素
*************************************************/
int Pop(Stack &s);

#endif