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

int n;
int adj[1001][1001];

std::vector<int> curcuit;

void getEulerCurcuit(int now)
{
	for (int i = 0; i < n; i++)
	{
		while (adj[now][i] > 0)
		{
			adj[now][i]--;
			adj[i][now]--;

			getEulerCurcuit(i);
		}
	}

	curcuit.push_back(now + 1);
}

int main()
{
	scanf("%d", &n);

	int start = 0;

	for (int i = 0; i < n; i++)
	{
		int degree = 0;
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &adj[i][j]);
			degree += adj[i][j];
		}

		if (degree % 2 == 1)
		{
			printf("-1");
			return 0;
		}

		if (degree > 0)
			start = i;
	}

	getEulerCurcuit(start);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (adj[i][j] != 0)
			{
				printf("-1");
				return 0;
			}
		}
	}

	for (auto& c : curcuit)
	{
		printf("%d ", c);
	}

	return 0;
}