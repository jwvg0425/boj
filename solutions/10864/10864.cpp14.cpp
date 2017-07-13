#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>
#include <time.h>

using ii = std::pair<int, int>;
int friends[1001];

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		friends[a]++;
		friends[b]++;
	}

	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", friends[i]);
	}

	return 0;
}