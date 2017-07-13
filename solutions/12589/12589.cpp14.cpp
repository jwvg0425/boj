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

char* solve()
{
	int n, k;

	scanf("%d %d", &n, &k);

	int v = (1 << n) - 1;

	if ((k & v) == v)
		return "ON";
	else
		return "OFF";
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++)
	{
		printf("Case #%d: %s\n", i, solve());
	}
	return 0;
}