#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

int calc(int arr[4])
{
	std::sort(arr, arr + 4);

	if (arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3])
		return arr[0] * 5000 + 50000;

	if (arr[0] == arr[1] && arr[1] == arr[2])
		return arr[0] * 1000 + 10000;

	if (arr[1] == arr[2] && arr[2] == arr[3])
		return arr[1] * 1000 + 10000;

	if (arr[0] == arr[1] && arr[2] == arr[3])
		return arr[0] * 500 + arr[2] * 500 + 2000;

	if (arr[0] == arr[1])
		return arr[0] * 100 + 1000;

	if (arr[1] == arr[2])
		return arr[1] * 100 + 1000;
	
	if (arr[2] == arr[3])
		return arr[2] * 100 + 1000;

	return arr[3] * 100;
}

int main()
{
	int n;
	scanf("%d", &n);

	int gold = 0;

	for (int i = 0; i < n; i++)
	{
		int arr[4];

		scanf("%d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3]);

		gold = std::max(gold, calc(arr));
	}

	printf("%d", gold);


	return 0;
}