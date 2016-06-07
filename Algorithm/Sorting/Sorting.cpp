// Sorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

static void show_array(int *arr, int len)
{
	printf("Array Values:\n");
	for (int idx = 0; idx < len; idx++)
	{
		printf("%d ", arr[idx]);
	}
	printf("\n");
}

static void fill_array(int *arr, int len)
{
	srand(time(NULL));

	for (int idx = 0; idx < len; idx++)
	{
		arr[idx] = rand() % 20;
	}
}

static void bubble_sort(int *arr, int len)
{
	if (!arr)
	{
		return;
	}

	for (int run1 = 0; run1 < len - 1; run1++)
	{
		for (int run2 = run1 + 1; run2 < len; run2++)
		{
			if (arr[run2] < arr[run1])
			{
				int temp = arr[run2];
				arr[run2] = arr[run1];
				arr[run1] = temp;
			}
		}
	}
}

static void select_sort(int *arr, int len)
{
	if (!arr)
	{
		return;
	}
	
	int minIdx;

	for(int idx1 = 0; idx1 < len; idx1++)
	{
		minIdx = idx1;
		for (int idx2 = idx1 + 1; idx2 < len; idx2++)
		{
			if (arr[minIdx] > arr[idx2])
			{
				minIdx = idx2;
			}
		}
		if (minIdx != idx1)
		{
			int temp = arr[minIdx];
			arr[minIdx] = arr[idx1];
			arr[idx1] = temp;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[10];
	fill_array(arr, sizeof(arr)/sizeof(int));
	show_array(arr, sizeof(arr)/sizeof(int));
//	bubble_sort(arr, sizeof(arr)/sizeof(int));
	select_sort(arr, sizeof(arr)/sizeof(int));
	show_array(arr, sizeof(arr)/sizeof(int));

	return 0;
}

