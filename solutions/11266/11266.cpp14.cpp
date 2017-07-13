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

struct Vertex
{
	int visit = 0;
	std::vector<int> adj;
};

std::vector<Vertex> v;
int order = 1;
std::vector<bool> cut;

int find(int now, bool isRoot)
{
	v[now].visit = order;
	order++;

	int ret = v[now].visit;
	int child = 0;

	for (int a : v[now].adj)
	{
		if (v[a].visit == 0)
		{
			child++;
			int low = find(a, false);

			if (!isRoot && low >= v[now].visit)
			{
				cut[now] = true;
			}

			ret = std::min(ret, low);
		}
		else
		{
			ret = std::min(ret, v[a].visit);
		}
	}

	if (isRoot && child > 1)
		cut[now] = true;

	return ret;
}

int main()
{
	int n, e;
	scanf("%d %d", &n, &e);

	v.resize(n + 1);
	cut.resize(n + 1);

	for (int i = 0; i < e; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		v[a].adj.push_back(b);
		v[b].adj.push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		if (v[i].visit == 0)
			find(i, true);
	}

	int count = 0;

	for (int i = 1; i <= n; i++)
	{
		if (cut[i])
			count++;
	}

	printf("%d\n", count);

	for (int i = 1; i <= n; i++)
	{
		if (cut[i])
			printf("%d ", i);
	}
			

	return 0;
}