#include "stdafx.h"
#include "Stack.h"

//��ʼ��һ����ջ
void Init_stack(Stack &s)
{
	s.stackSize = 0;
	s.stackCapacity = c_defaultStackSize;
	s.stackBotton = (int *)malloc(s.stackCapacity * sizeof(int));
	s.stackTop = s.stackBotton;
	printf("Stack initialized, default capacity = %d.\n", s.stackCapacity);
}

//�ͷ�һ��ջ
void Destroy_stack(Stack &s)
{
	free(s.stackBotton);
	s.stackSize = s.stackCapacity = 0;
	s.stackBotton = s.stackTop = NULL;
}

//����һ��ջ�����г�Ա
void Tranvers_stack(const Stack &s)
{
	printf("Stack elements:\n");
	for (int idx = 0; idx < s.stackSize; idx++)
	{
		printf("%d\n",*(s.stackBotton + idx));
	}
	printf("\n");
}

//��Ԫ��valѹ��ջs��
void Push(Stack &s, int val)
{
	if (s.stackSize >= s.stackCapacity)
	{
		//��ǰջ����
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

//��ջs�е���ջ��Ԫ��
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

