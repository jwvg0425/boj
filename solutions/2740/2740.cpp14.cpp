#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <queue>
#include <tuple>
#include <memory.h>

int main()
{
	int A[101][101];
	int B[101][101];

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}

	int k;
	scanf("%*d %d", &k);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &B[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			int val = 0;

			for (int k = 0; k < m; k++)
			{
				val += A[i][k] * B[k][j];
			}

			printf("%d ", val);
		}
		printf("\n");
	}

	return 0;
}