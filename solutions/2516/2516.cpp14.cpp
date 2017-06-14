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
#include <deque>

int monkey[100000][4], N, group[100000];

int main()
{
	int i, j, k;

	scanf("%d", &N);
	for (i = 0; i<N; i++)
	{
		scanf("%d", &monkey[i][0]);
		for (j = 0; j<monkey[i][0]; j++)
			scanf("%d", &monkey[i][j + 1]);
		if (i<N / 2)group[i] = 1;
		else group[i] = 0;
	}
	for (i = 0; i<N; i++)
	{
		k = 0;
		for (j = 0; j<monkey[i][0]; j++)
		{
			k += (group[i] == group[monkey[i][j + 1] - 1]);
		}
		if (k >= 2)
			group[i] = (group[i] + 1) % 2;
	}
	for (i = 0; i<N; i++)
	{
		k = 0;
		for (j = 0; j<monkey[i][0]; j++)
		{
			k += (group[i] == group[monkey[i][j + 1] - 1]);
		}
		if (k >= 2)
			group[i] = (group[i] + 1) % 2;
	}
	for (i = 0; i<N; i++)
	{
		k = 0;
		for (j = 0; j<monkey[i][0]; j++)
		{
			k += (group[i] == group[monkey[i][j + 1] - 1]);
		}
		if (k >= 2)
			group[i] = (group[i] + 1) % 2;
	}
	for (i = 0; i<N; i++)
	{
		k = 0;
		for (j = 0; j<monkey[i][0]; j++)
		{
			k += (group[i] == group[monkey[i][j + 1] - 1]);
		}
		if (k >= 2)
			group[i] = (group[i] + 1) % 2;
	}
	for (i = 0; i<N; i++)
	{
		k = 0;
		for (j = 0; j<monkey[i][0]; j++)
		{
			k += (group[i] == group[monkey[i][j + 1] - 1]);
		}
		if (k >= 2)
			group[i] = (group[i] + 1) % 2;
	}
	for (i = 0; i<N; i++)
	{
		k = 0;
		for (j = 0; j<monkey[i][0]; j++)
		{
			k += (group[i] == group[monkey[i][j + 1] - 1]);
		}
		if (k >= 2)
			group[i] = (group[i] + 1) % 2;
	}
	for (i = 0; i<N; i++)
	{
		k = 0;
		for (j = 0; j<monkey[i][0]; j++)
		{
			k += (group[i] == group[monkey[i][j + 1] - 1]);
		}
		if (k >= 2)
			group[i] = (group[i] + 1) % 2;
	}

	std::vector<int> a;
	std::vector<int> b;

	for (i = 0; i<N; i++)
	{
		k = 0;
		for (j = 0; j<monkey[i][0]; j++)
		{
			k += (group[i] == group[monkey[i][j + 1] - 1]);
		}
		if (k >= 2)
			group[i] = (group[i] + 1) % 2;
		if (group[i] == 0)
			a.push_back(i + 1);
	}
	for (i = 0; i<N; i++)
	{
		if (group[i] == 1)
			b.push_back(i + 1);
	}

	printf("%d ", a.size());
	for (auto& i : a)
		printf("%d ", i);
	printf("\n");
	printf("%d ", b.size());
	for (auto& i : b)
		printf("%d ", i);
}