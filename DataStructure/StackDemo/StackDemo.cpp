// StackDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stack.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Stack s;
	Init_stack(s);

	Push(s, 1);
	Push(s, 2);
	Push(s, 3);
	Push(s, 4);
	Push(s, 5);

	Tranvers_stack(s);

	Push(s, 6);
	Push(s, 7);
	Push(s, 8);
	Push(s, 9);
	Push(s, 10);

	Tranvers_stack(s);

	Push(s, 11);

	Tranvers_stack(s);

	int len = s.stackSize;
	for (int idx = 0; idx < len ; idx++)
	{
		printf("Stack elements: %d\n", Pop(s));
	}

	Destroy_stack(s);
	return 0;
}

