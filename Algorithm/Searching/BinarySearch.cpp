#include "stdafx.h"

int BinarySearchFun(int *arr, int len, int val)
{
	int mid, ret = -1;
	int low = 0, high = len - 1;

	while(low <= high)
	{
		mid = (low + high) / 2;
		if (arr[mid] == val)
		{
			ret = mid;
			break;
		}
		else if (arr[mid] > val)
		{
			high = mid - 1;
		} 
		else
		{
			low = mid + 1;
		}
	}

	return ret;
}
