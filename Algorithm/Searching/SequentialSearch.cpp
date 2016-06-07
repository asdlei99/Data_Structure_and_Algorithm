#include "stdafx.h"

int Sequential_search_fun(int *arr, int len, int val)
{
	int ret = -1;
	if (!arr)
	{
		return -1;
	}

	for (int idx = 0; idx < len; idx++)
	{
		if (arr[idx] == val)
		{
			ret = idx;
			break;
		}
	}

	return ret;
}
