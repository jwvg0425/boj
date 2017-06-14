#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>
using namespace std;

int n, m;
int cow[201];
int shed[201];
std::vector<int> adj[201];
bool visited[201];

bool dfs(int a)
{
	visited[a] = true;

	for (auto b : adj[a])
	{
		if (shed[b] == -1 || !visited[shed[b]] && dfs(shed[b]))
		{
			cow[a] = b;
			shed[b] = a;
			return true;
		}
	}

	return false;
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		int s;
		scanf("%d", &s);
		for (int j = 0; j < s; j++)
		{
			int k;
			scanf("%d", &k);
			adj[i].push_back(k - 1);
		}
	}

	int match = 0;

	fill(cow, cow + n, -1);
	fill(shed, shed + m, -1);

	for (int i = 0; i < n; i++)
	{
		if (cow[i] == -1)
		{
			fill(visited, visited + n, false);
			if (dfs(i))
				match++;
		}
	}

	printf("%d\n", match);

	return 0;
}