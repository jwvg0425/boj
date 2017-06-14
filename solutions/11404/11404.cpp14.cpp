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

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j  && edges[i][j] == 0)
				edges[i][j] = 987654321;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		edges[a][b] = std::min(edges[a][b], w);
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

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) 
		{
			if (edges[i][j] == 987654321)
				printf("0 ");
			else
				printf("%d ", edges[i][j]);
		}
		printf("\n");
	}

	return 0;
}