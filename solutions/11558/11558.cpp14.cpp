#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <tuple>
#include <memory.h>

void solve()
{
	int n;
	scanf("%d", &n);

	int point[10001];
	bool visited[10001] = { false, };

	for (int i = 1; i <= n; i++)
		scanf("%d", &point[i]);

	int length = 0;
	int now = 1;

	while (now != n)
	{
		if (visited[now])
		{
			printf("0\n");
			return;
		}

		visited[now] = true;
		length++;
		now = point[now];
	}

	printf("%d\n", length);
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