#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <memory.h>
#include <stack>
#include <queue>
#include <map>
#include <set>

using ii = std::pair<int, int>;

int choice[100001];
int visit[100001];

void solve()
{
	memset(visit, 0, sizeof(visit));

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &choice[i]);
	}

	int cycles = 0;
	int idx = 1;

	for (int i = 1; i <= n; i++)
	{
		if (visit[i] != 0)
			continue;

		int now = i;
		int startIdx = idx;

		while (true)
		{
			visit[now] = idx;
			idx++;

			if (visit[choice[now]] != 0)
				break;

			now = choice[now];
		}

		if (visit[choice[now]] >= startIdx)
		{
			cycles += visit[now] - visit[choice[now]] + 1;
		}
	}

	printf("%d\n", n - cycles);
}


int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		solve();
	}

	return 0;
}