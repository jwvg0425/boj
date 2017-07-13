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

int main()
{
	int n;
	int father[501], mother[501];
	bool america[501] = { false, };

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &father[i], &mother[i]);
	}

	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int k;
		scanf("%d", &k);
		america[k] = true;
	}

	int count = 0;

	for (int i = 1; i <= n; i++)
	{
		int mo = mother[i];
		int fa = father[i];

		if (mo != 0 && fa != 0 && !america[mo] && !america[fa] && !america[i])
			count++;
	}

	printf("%d", count);

	return 0;
}