#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>
#include <memory.h>
#include <math.h>
#include <stack>
#include <map>

void solve()
{
	int n;
	scanf("%d", &n);

	std::vector<std::pair<int, int>> points;
	long long int sum_x = 0;
	long long int sum_y = 0;

	for (int i = 0; i < n; i++)
	{
		int x, y;

		scanf("%d %d", &x, &y);

		points.emplace_back(x, y);

		sum_x += x;
		sum_y += y;
	}

	int k = n / 2;
	long long int min_ls = 9223372036854775807LL;

	for (int i = (1 << k) - 1; i < (1 << n); i++)
	{
		if (std::bitset<32>(i).count() != k)
			continue;

		long long int x = 0;
		long long int y = 0;

		for (int j = 0; j < n; j++)
		{
			if ((i & (1 << j)) == 0)
				continue;

			x += points[j].first;
			y += points[j].second;
		}

		long long int ls = (sum_x - 2 * x) * (sum_x - 2 * x) + (sum_y - 2 * y) * (sum_y - 2 * y);

		if (ls < min_ls)
			min_ls = ls;
	}

	printf("%.6lf\n", sqrt((double)min_ls));

}

int main()
{
	int t;

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		solve();
	}

	return 0;
}