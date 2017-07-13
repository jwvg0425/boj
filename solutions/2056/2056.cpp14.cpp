#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

std::vector<int> next[10001];
int prev[10001];
int val[10001];
int work[10001];

int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &val[i], &prev[i]);

		for (int j = 0; j < prev[i]; j++)
		{
			int k;
			scanf("%d", &k);
			
			next[k].push_back(i);
		}
	}

	std::queue<int> q;
	int maxTime = 0;

	for (int i = 1; i <= n; i++)
	{
		if (prev[i] == 0)
		{
			q.push(i);
			work[i] = val[i];
			maxTime = std::max(maxTime, work[i]);
		}
	}

	while (!q.empty())
	{
		int i = q.front();
		q.pop();

		for (auto& k : next[i])
		{
			prev[k]--;
			work[k] = std::max(work[k], work[i] + val[k]);
			maxTime = std::max(maxTime, work[k]);

			if (prev[k] == 0)
				q.push(k);
		}
	}

	printf("%d", maxTime);

	return 0;
}