#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <math.h>

void solve()
{
	int n;
	scanf("%d", &n);

	int arr[1001];

	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	bool visited[1001] = { false, };

	int cycle = 0;

	for (int i = 1; i <= n; i++)
	{
		if (visited[i])
			continue;

		int now = i;

		while (!visited[now])
		{
			visited[now] = true;
			now = arr[now];
		}

		cycle++;
	}

	printf("%d\n", cycle);
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
		solve();

	return 0;
}