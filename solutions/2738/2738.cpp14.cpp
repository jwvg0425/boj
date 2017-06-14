#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <memory.h>

int main()
{
	int matrix[101][101] = { 0, };
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int k;
			scanf("%d", &k);
			matrix[i][j] += k;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", matrix[i][j]);
		}

		printf("\n");
	}

	return 0;
}