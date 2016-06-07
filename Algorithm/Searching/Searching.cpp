// Searching.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int arr[10] = {9,7,5,3,1,8,6,4,2,0};
	int sortedArr[10] = {1,3,5,7,9,10,12,14,16,18};

// 	printf("Find 1: %d\n", Sequential_search_fun(arr, 10, 1));
// 	printf("Find -5: %d\n", Sequential_search_fun(arr, 10, -5));

	printf("Find 10: %d\n", BinarySearchFun(sortedArr, 10, 10));
	printf("Find 6: %d\n", BinarySearchFun(sortedArr, 10, 6));
	return 0;
}

