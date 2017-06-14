#include <stdio.h>
#include <memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <tuple>
#include <time.h>

int left[200001];
int right[200001];
int count[200001];
int table[200001];

int next(int k)
{
	if (left[k] != -1 && right[k] != -1)
		return k;

	while (k != -1 && left[k] == -1 || right[k] == -1)
	{
		if (left[k] == -1 && right[k] == -1)
			return k;

		k = std::max(left[k], right[k]);
	}

	return k;
}

//k번 노드 사이클 크기
int getSize(int k)
{
	if (left[k] == -1 && right[k] == -1)
		return 1;

	if (table[k] != -1)
		return table[k];
	
	else if (left[k] == -1 || right[k] == -1)
	{
		return table[k] = getSize(next(std::max(left[k], right[k])));
	}
	else
	{
		auto l = getSize(next(left[k]));
		auto r = getSize(next(right[k]));
		table[k] = std::max(l, r) * 2;

		return table[k];
	}
}

int findNode(int node, int pos)
{
	if (left[node] == -1 && right[node] == -1)
		return node;

	if (left[node] == -1)
		return findNode(next(right[node]), pos);

	if (right[node] == -1)
		return findNode(next(left[node]), pos);

	if (pos % 2 == 0) //left 기준 검색
		return findNode(next(left[node]), (pos / 2) % getSize(next(left[node])));
	else
		return findNode(next(right[node]), (pos / 2) % getSize(next(right[node])));
}

int main()
{
	int n;
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &left[i], &right[i]);
	}

	memset(table, -1, sizeof(table));

	long long int k;

	scanf("%lld", &k);

	auto cycleSize = getSize(1);

	int pos = (k - 1) % cycleSize;

	printf("%d", findNode(1, pos));

	return 0;
}