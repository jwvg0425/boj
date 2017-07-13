#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>
#include <time.h>

using ii = std::pair<int, int>;

int main()
{
	int n, l;
	scanf("%d %d", &n, &l);

	for (int t = l; t <= 100; t++)
	{
		int p = 2 * n - t * (t - 1);

		if (p < 0 || p % (2 * t) != 0)
			continue;

		int k = p / (2 * t);

		for (int i = k ; i < k + t; i++)
		{
			printf("%d ", i);
		}

		return 0;
	}

	printf("-1");

	return 0;
}