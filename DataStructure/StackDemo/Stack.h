#ifndef _STACK_H_
#define _STACK_H_

const unsigned int c_defaultStackSize = 20;
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

#endif