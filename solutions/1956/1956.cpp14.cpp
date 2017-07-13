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
#define MAX 987654321

int edges[401][401];

int main()
{
	int v, e;

	scanf("%d %d", &v, &e);

	for (int i = 1; i <= v; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			edges[i][j] = MAX;
		}
	}

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		edges[a][b] = c;
	}

	for (int k = 1; k <= v; k++)
	{
		for (int i = 1; i <= v; i++)
		{
			for (int j = 1; j <= v; j++)
			{
				edges[i][j] = std::min(edges[i][j], edges[i][k] + edges[k][j]);
			}
		}
	}

	int min = MAX;

	for (int i = 1; i <= v; i++)
	{
		min = std::min(min, edges[i][i]);
	}

	if (min == MAX)
		min = -1;

	printf("%d", min);

	return 0;
}