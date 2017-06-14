#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>
#include <tuple>
#include<set>
#define MAX 987654321

int main()
{
	int edges[51][51] = { 0, };
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			edges[i][j] = MAX;
		}
	}

	while (true)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		
		if (a == -1 && b == -1)
			break;

		edges[a][b] = edges[b][a] = 1;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				edges[i][j] = std::min(edges[i][k] + edges[k][j], edges[i][j]);
			}
		}
	}

	int minScore = MAX;
	int scores[51];

	for (int i = 1; i <= n; i++)
	{
		scores[i] = 0;

		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				continue;

			scores[i] = std::max(scores[i], edges[i][j]);
		}

		minScore = std::min(minScore, scores[i]);
	}

	std::vector<int> cand;

	for (int i = 1; i <= n; i++)
	{
		if (scores[i] == minScore)
			cand.push_back(i);
	}

	printf("%d %d\n", minScore, cand.size());
	
	for (auto& c : cand)
	{
		printf("%d ", c);
	}

	return 0;
}