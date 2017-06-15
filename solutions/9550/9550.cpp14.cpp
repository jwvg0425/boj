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

void solve()
{
	int n, k;
	scanf("%d %d", &n, &k);

	int count = 0;

	for (int i = 0; i < n; i++)
	{
		int candy;
		scanf("%d", &candy);

		count += candy / k;
	}

	printf("%d\n", count);
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
		solve();

	return 0;
}