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

int left[10001];
int right[10001];
int min[10001];
int max[10001];
int parent[10001];
int idx = 1;

void find(int now, int level)
{
	if (left[now] != -1)
		find(left[now], level + 1);

	idx++;
	if (min[level] == 0 || min[level] > idx)
		min[level] = idx;

	if (max[level] < idx)
		max[level] = idx;

	if (right[now] != -1)
		find(right[now], level + 1);
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int p, l, r;
		scanf("%d %d %d", &p, &l, &r);

		parent[l] = p;
		parent[r] = p;

		left[p] = l;
		right[p] = r;
	}

	for (int i = 1; i <= n; i++)
	{
		if (parent[i] == 0)
		{
			find(i, 1);
		}
	}

	int maxLevel = 0;
	int maxWidth = 0;

	for (int l = 1; l <= n; l++)
	{
		if (maxWidth < max[l] - min[l] + 1)
		{
			maxWidth = max[l] - min[l] + 1;
			maxLevel = l;
		}
	}

	printf("%d %d", maxLevel, maxWidth);

	return 0;
}