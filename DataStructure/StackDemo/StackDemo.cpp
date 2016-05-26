// StackDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stack.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Stack s;
	Init_stack(s);
	Destroy_stack(s);

	return 0;
}

