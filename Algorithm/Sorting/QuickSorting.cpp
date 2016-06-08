#include "stdafx.h"
#include "QuickSorting.h"

static int partition_arr(int *arr, int start, int end)
{
	int left = start, right = end;
	int pivot = arr[left];

	while (left < right)
	{
		while ((pivot <= arr[right]) && (left < right))
		{
			right--;
		}
		if (left < right)
		{
			arr[left] = arr[right];
			left++;
		}

		while((arr[left] <= pivot) && (left < right))
		{
			left++;
		}
		if (left < right)
		{
			arr[right] = arr[left];
			right--;
		}
	}
	arr[right] = pivot;

	return right;
}

static void quick_sort_fun(int *arr, int start, int end)
{
	if (!arr)
	{
		//空数组，直接返回
		return;
	}

	int pivotPos = partition_arr(arr, start, end);

	if (start < pivotPos-1)
	{
		quick_sort_fun(arr, start, pivotPos-1);
	}
	if (pivotPos+1 < end)
	{
		quick_sort_fun(arr, pivotPos+1, end);
	}
}

void Quick_sort(int *arr, int len)
{
	quick_sort_fun(arr, 0, len - 1);
}
