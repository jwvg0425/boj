#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>
#include <functional>

std::vector<int> v = { 0, };
int table[1001];
int n;

int solve(int k)
{
	if (k == n)
		return v[k];

	if (table[k] != -1)
		return table[k];

	int& res = table[k];
	res = v[k];

	for (int i = k + 1; i <= n; i++)
	{
		if (v[i] > v[k])
			res = std::max(res, v[k] + solve(i));
	}

	return res;
}

int main()
{
	scanf("%d", &n);

	memset(table, -1, sizeof(table));

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}

	printf("%d", solve(0));
	
	return 0;
}