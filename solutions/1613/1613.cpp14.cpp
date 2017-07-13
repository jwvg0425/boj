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

bool edges[401][401];

int main()
{
	int n, t;
	scanf("%d %d", &n, &t);

	for (int i = 0; i < t; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		edges[a][b] = true;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				edges[i][j] = edges[i][j] || (edges[i][k] && edges[k][j]);
			}
		}
	}

	int s;
	scanf("%d", &s);

	for (int i = 0; i < s; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		if (edges[a][b])
			printf("-1\n");
		else if (edges[b][a])
			printf("1\n");
		else
			printf("0\n");
	}

	return 0;
}