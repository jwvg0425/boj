#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <math.h>

void solve()
{
	int n, m;
	scanf("%d %d", &n, &m);

	std::priority_queue<int> important;
	std::queue<std::pair<int, int>> documents;

	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);

		documents.emplace(i, k);
		important.push(k);
	}

	int nowMax = important.top();
	int order = 0;

	while (true)
	{
		auto d = documents.front();
		documents.pop();

		if (d.second == nowMax) //인쇄됨
		{
			order++;
			if (d.first == m)
			{
				printf("%d\n", order);
				break;
			}

			important.pop();
			nowMax = important.top();
		}
		else
		{
			documents.push(d);
		}
	}
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