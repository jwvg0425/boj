#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <memory.h>

int main()
{
	int arr[4];

	scanf("%d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3]);

	std::sort(arr, arr + 4);

	int maxSize = 0;

	do
	{
		maxSize = std::max(maxSize, std::min(arr[0], arr[1]) * std::min(arr[2], arr[3]));
	} while (std::next_permutation(arr, arr + 4));

	printf("%d", maxSize);

	return 0;
}