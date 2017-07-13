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

std::vector<int> edges[1000001];
int level[1000001];
int table[1000001][2];

int solve(int root, int early)
{
	if (edges[root].empty()) //leaf 노드인 경우가 끝
		return early;

	if (table[root][early] != -1)
		return table[root][early];

	int& res = table[root][early];

	res = early;

	for (auto& e : edges[root])
	{
		if (level[e] < level[root])
			continue;

		int min = solve(e, 1); // 자식이 얼리인 경우.

		if (early == 1) // 내가 이미 얼리면, 자식 얼리 아니어도 됨
			min = std::min(min, solve(e, 0));

		res += min;
	}

	return res;
}

int main()
{
	memset(table, -1, sizeof(table));

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	std::queue<int> q;

	level[1] = 1;

	q.push(1);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (auto& e : edges[now])
		{
			if (level[e] != 0)
				continue;

			level[e] = level[now] + 1;
			q.push(e);
		}
	}

	printf("%d", std::min(solve(1, 0), solve(1, 1)));

	return 0;
}