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

std::vector<int> next[501];
int prev[501];
int val[501];
int work[501];

int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &val[i]);

		prev[i] = 0;

		while(true)
		{
			int k;
			scanf("%d", &k);

			if (k == -1)
				break;

			next[k].push_back(i);
			prev[i]++;
		}
	}

	std::queue<int> q;

	for (int i = 1; i <= n; i++)
	{
		if (prev[i] == 0)
		{
			q.push(i);
			work[i] = val[i];
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

			if (prev[k] == 0)
				q.push(k);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", work[i]);
	}

	return 0;
}