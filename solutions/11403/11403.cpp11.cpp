#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>

int edge[101][101];
int n;

void floyd()
{
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				edge[i][j] =
					edge[i][j] | (edge[i][k] & edge[k][j]);
			}
		}
	}
}

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &edge[i][j]);
		}
	}

	floyd();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", edge[i][j]);
		}

		printf("\n");
	}
}