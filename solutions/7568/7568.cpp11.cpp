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
#include <functional>

int main()
{
	int n;
	scanf("%d", &n);
	std::vector<std::pair<int, int>> arr;

	for (int i = 0; i < n; i++)
	{
		int p, q;
		scanf("%d %d", &p, &q);
		arr.emplace_back(p, q);
	}

	for (int i = 0; i < n; i++)
	{
		int rank = 1;

		for (int j = 0; j < n; j++)
		{
			if (arr[j].first > arr[i].first && arr[j].second > arr[i].second)
				rank++;
		}

		printf("%d ", rank);
	}

	
	return 0;
}