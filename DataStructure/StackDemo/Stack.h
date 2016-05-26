#ifndef _STACK_H_
#define _STACK_H_

const unsigned int c_defaultStackSize = 20;
const unsigned int c_defaultStackIncrement = 5;

/********************
	ջ�ṹ
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
  Description:	��ʼ��һ����ջ
  Input:		(in/out)s: ��ʼ����ջ�ṹ
  Output:		��
  Return:		��
*************************************************/
void Init_stack(Stack &s);

/*************************************************
  Function:		Destroy_stack
  Description:	�ͷ�һ��ջ
  Input:		(in/out)s: Ҫ�ͷŵ�ջ�ṹ
  Output:		��
  Return:		��
*************************************************/
void Destroy_stack(Stack &s);

#endif