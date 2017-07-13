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

std::vector<int> occurs[100001];
int counts[100001][3];
int values[100001][3];
bool removed[100001];

int main()
{
	int n;
	scanf("%d", &n);

	std::queue<int> remove;

	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &values[i][j]);
			counts[values[i][j]][j]++;
			occurs[values[i][j]].push_back(i);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (counts[i][0] == 0 || counts[i][1] == 0 || counts[i][2] == 0)
		{
			remove.push(i);
		}
	}

	int ans = 0;

	while (!remove.empty())
	{
		auto now = remove.front();
		remove.pop();
		for (auto& o : occurs[now])
		{
			if (removed[o])
				continue;

			removed[o] = true;
			ans++;

			for (int j = 0; j < 3; j++)
			{
				int v = values[o][j];
				counts[v][j]--;

				if (counts[v][j] == 0)
					remove.push(v);
			}
		}
	}

	printf("%d", ans);

	return 0;
}