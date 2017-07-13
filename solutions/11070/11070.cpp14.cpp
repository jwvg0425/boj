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

void solve()
{
	long long int plus[1001] = { 0, };
	long long int minus[1001] = { 0, };

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int a, b, p, q;
		scanf("%d %d %d %d", &a, &b, &p, &q);

		plus[a] += p;
		minus[a] += q;
		plus[b] += q;
		minus[b] += p;
	}

	long long int maxVal = -1;
	long long int minVal = 987654321;

	for (int i = 1; i <= n; i++)
	{
		long long int w = 0;
		
		if(plus[i] + minus[i] != 0)
			w = (plus[i] * plus[i] * 1000) / (plus[i] * plus[i] + minus[i] * minus[i]);

		maxVal = std::max(maxVal, w);
		minVal = std::min(minVal, w);
	}

	printf("%d\n%d\n", maxVal, minVal);
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
		solve();

	return 0;
}