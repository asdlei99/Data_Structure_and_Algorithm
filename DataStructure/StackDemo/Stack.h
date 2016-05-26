#ifndef _STACK_H_
#define _STACK_H_

const unsigned int c_defaultStackSize = 10;
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

/*************************************************
  Function:		Tranvers_stack
  Description:	����һ��ջ�����г�Ա
  Input:		(in)s: Ҫ�ͷŵ�ջ�ṹ
  Output:		��
  Return:		��
*************************************************/
void Tranvers_stack(const Stack &s);

/*************************************************
  Function:		Push
  Description:	��Ԫ��valѹ��ջs��
  Input:		(in)s: Ŀ��ջ�ṹ
				(in)val��Ҫѹ��ջ�е�Ԫ��
  Output:		��
  Return:		��
*************************************************/
void Push(Stack &s, int val);

/*************************************************
  Function:		Pop
  Description:	��ջs�е���ջ��Ԫ��
  Input:		(in)s: Ŀ��ջ�ṹ				
  Output:		��
  Return:		������ջ��Ԫ��
*************************************************/
int Pop(Stack &s);

#endif