#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <memory.h>

using ii = std::pair<int, int>;

std::vector<ii> v;

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		v.emplace_back(a, b);
	}

	int m;
	scanf("%d", &m);

	for (int x = 1; x <= m; x++)
	{
		int gas = v[0].first * x + v[0].second;
		int sum = x;

		for (int i = 1; i < n; i++)
		{
			int r = gas - v[i].second;

			if (r < 0 || r % v[i].first != 0)
			{
				sum = m + 1;
				break;
			}

			sum += r / v[i].first;
		}

		if (sum == m)
		{
			printf("%d", gas);
			return 0;
		}
	}

	printf("0");

	return 0;
}