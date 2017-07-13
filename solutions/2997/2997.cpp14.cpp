#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <memory.h>
#include <stack>
#include <queue>
#include <map>
#include <set>

using ii = std::pair<int, int>;

int main()
{
	int arr[3];

	scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);

	std::sort(arr, arr + 3);

	if (arr[1] - arr[0] == arr[2] - arr[1])
	{
		printf("%d", 2 * arr[2] - arr[1]);
	}
	else if (arr[1] - arr[0] > arr[2] - arr[1])
	{
		printf("%d", arr[0] + arr[2] - arr[1]);
	}
	else
	{
		printf("%d", 2 * arr[1] - arr[0]);
	}

	return 0;
}