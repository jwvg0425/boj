#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <memory.h>

int main()
{
	int n, m;
	int edges[101][101] = { 0, };

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		edges[a][b] = edges[b][a] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (edges[i][j] == 0)
				edges[i][j] = 987654321;
		}
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (edges[i][j] > edges[i][k] + edges[k][j])
					edges[i][j] = edges[i][k] + edges[k][j];
			}
		}
	}

	int minCount = 987654321;
	int minIndex = 0;

	for (int i = 1; i <= n; i++)
	{
		int count = 0;
		for (int j = 1; j <= n; j++)
			count += edges[i][j];

		if (count < minCount)
		{
			minCount = count;
			minIndex = i;
		}
	}

	printf("%d", minIndex);

	return 0;
}