#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>

int main()
{
	int arr[3];

	scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);

	std::string str;

	std::cin >> str;

	std::sort(arr, arr + 3);

	for (auto& c : str)
	{
		printf("%d ", arr[c - 'A']);
	}
}