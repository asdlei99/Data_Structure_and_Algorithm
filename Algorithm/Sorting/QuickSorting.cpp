#include "stdafx.h"
#include "QuickSorting.h"

static int partition_arr_front(int *arr, int start, int end)
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

static int partition_arr_end(int *arr, int start, int end)
{
	int left = start, right = end;
	int pivot = arr[end];

	while (left < right)
	{
		while ((arr[left] <= pivot) && (left < right))
		{
			left++;
		}
		if (left < right)
		{
			arr[right] = arr[left];
			right--;
		}
		

		while((pivot <= arr[right]) && (left < right))
		{
			right--;
		}
		if (left < right)
		{
			arr[left] = arr[right];
			left++;
		}
	}

	arr[left] = pivot;

	return left;
}

static void swap_int(int &val1, int &val2)
{
	int temp = val1;
	val1 = val2;
	val2 = temp;
}

static int partition_arr_mid(int *arr, int start, int end)
{
	int left = start, right = end, mid = (left + right) >> 1;
	int pivot = arr[mid], pivotPos = start;

	for (int idx = start; idx < end; idx++)
	{
		if (arr[idx] < pivot)
		{
			pivotPos++;
		}
	}

	if (mid != pivotPos)
	{
		swap_int(arr[mid], arr[pivotPos]);
		swap_int(mid, pivotPos);
	}	

	while (left < right)
	{
		while ((arr[left] <= pivot) && (left < mid))
		{
			left++;
		}
		while((pivot <= arr[right]) && (mid < right))
		{
			right--;
		}

		if (left < right)
		{
			swap_int(arr[left],arr[right]);
		}
	}

	return left;
}

static void quick_sort_fun(int *arr, int start, int end)
{
	int pivotPos = partition_arr_mid(arr, start, end);

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
	if (!arr)
	{
		//空数组，直接返回
		return;
	}

	quick_sort_fun(arr, 0, len - 1);
}
