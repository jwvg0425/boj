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
#define MOD 1234567

using ii = std::pair<int, int>;

std::vector<int> cafe[100001];

void solve()
{
	int n;
	scanf("%d", &n);

	int maxX = 0;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);

		cafe[x].push_back(y);

		maxX = std::max(maxX, x);
	}

	std::vector<ii> numbering;

	int nowY = 0;

	for (int x = 0; x <= maxX; x++)
	{
		if (cafe[x].empty())
			continue;

		std::sort(cafe[x].begin(), cafe[x].end());

		if (cafe[x][0] < nowY)
		{
			std::reverse(cafe[x].begin(), cafe[x].end());
		}

		for (auto& c : cafe[x])
		{
			numbering.emplace_back(x, c);
		}

		nowY = cafe[x].back();
	}

	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int k;
		scanf("%d", &k);

		printf("%d %d\n", numbering[k - 1].first, numbering[k - 1].second);
	}


	for (int i = 0; i < n; i++)
	{
		cafe[i].clear();
	}
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
		solve();

	return 0;
}