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

using ii = std::pair<int, int>;

int edges[51][51];
int multiplied[51][51];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		std::string str;
		std::cin >> str;

		for (int j = 0; j < n; j++)
		{
			if (str[j] == 'N')
				edges[i][j] = 987654321;
			else
				edges[i][j] = 1;
		}
	}

	for (int i = 0; i < n; i++)
		edges[i][i] = 0;

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				edges[i][j] = std::min(edges[i][j], edges[i][k] + edges[k][j]);
			}
		}
	}

	int maxCount = 0;

	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;

			if (edges[i][j] <= 2)
				count++;
		}

		maxCount = std::max(maxCount, count);
	}

	printf("%d", maxCount);

	return 0;
}