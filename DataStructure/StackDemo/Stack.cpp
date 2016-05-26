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
