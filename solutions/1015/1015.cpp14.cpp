#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>
#include <memory.h>
#include <math.h>

int main()
{
	std::vector<int> arr;

	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int a;

		scanf("%d", &a);

		arr.push_back(a);
	}

	std::vector<int> sorted = arr;

	std::sort(sorted.begin(), sorted.end());

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i] == sorted[j])
			{
				printf("%d ", j);
				sorted[j] = -1;
				break;
			}
		}
	}

	return 0;
}