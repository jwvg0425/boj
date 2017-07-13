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

std::set<int> prev[32001];
std::vector<int> next[32001];
bool visited[32001];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		prev[b].insert(a);
		next[a].push_back(b);
	}

	for (int i = 0; i < n; i++)
	{
		for (int k = 1; k <= n; k++)
		{
			if (visited[k])
				continue;

			if (prev[k].size() != 0)
				continue;

			for (auto& t : next[k])
			{
				prev[t].erase(k);
			}

			printf("%d ", k);
			visited[k] = true;
			break;
		}
	}

	return 0;
}