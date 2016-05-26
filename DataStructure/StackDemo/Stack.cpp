#include "stdafx.h"
#include "Stack.h"

//初始化一个空栈
void Init_stack(Stack &s)
{
	s.stackSize = 0;
	s.stackCapacity = c_defaultStackSize;
	s.stackBotton = (int *)malloc(s.stackCapacity * sizeof(int));
	s.stackTop = s.stackBotton;
	printf("Stack initialized, default capacity = %d.\n", s.stackCapacity);
}

//释放一个栈
void Destroy_stack(Stack &s)
{
	free(s.stackBotton);
	s.stackSize = s.stackCapacity = 0;
	s.stackBotton = s.stackTop = NULL;
}
