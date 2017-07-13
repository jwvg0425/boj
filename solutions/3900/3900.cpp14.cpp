#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

//(u,v,w)
using Edge = std::tuple<int, int, int>;
std::vector<Edge> edges;
int counts[101];
int parents[101];

int n, m;

int root(int k)
{
	int p = k;

	while (parents[p] > 0)
		p = parents[p];

	if (p != k)
		parents[k] = p;

	return p;
}

int spanning(int k)
{
	memset(parents, 0, sizeof(parents));
	std::fill(counts + 1, counts + n + 1, 1);

	for (int i = k; i < m; i++)
	{
		int u, v, w;
		std::tie(u, v, w) = edges[i];

		int ru = root(u);
		int rv = root(v);

		if (ru == rv)
			continue;

		parents[ru] = rv;
		counts[rv] += counts[ru];

		if (counts[rv] == n)
		{
			int su, sv, sw;
			std::tie(su, sv, sw) = edges[k];
			return w - sw;
		}
	}

	return -1;
}

bool solve()
{
	edges.clear();

	scanf("%d %d", &n, &m);

	if (n == 0 && m == 0)
		return false;

	for (int i = 0; i < m; i++)
	{
		int u, v, w;

		scanf("%d %d %d", &u, &v, &w);

		edges.emplace_back(u, v, w);
	}

	std::sort(edges.begin(), edges.end(), [](const Edge& l, const Edge& r)
	{
		return std::get<2>(l) < std::get<2>(r);
	});

	int res = -1;

	for (int i = 0; i < m;)
	{
		int slim = spanning(i);

		if (slim == -1)
			break;

		if (res == -1 || slim < res)
			res = slim;

		int iw = std::get<2>(edges[i]);

		while (i < m && std::get<2>(edges[i]) == iw)
			i++;
	}

	printf("%d\n", res);

	return true;
}

int main()
{
	while (solve());

	return 0;
}