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
#include <deque>

long long int table[101];

long long int solve(int n)
{
	if (n == 0)
		return 0;

	if (n == 1)
		return 1;

	if (table[n] != -1)
		return table[n];

	//ctrl + C, ctrl + V 하거나 그냥 a하나 붙이거나

	long long int& res = table[n];

	res = solve(n - 1) + 1;

	//그 이전들 시점 다 검사해서 - 여기서 ctrl + v 넣는 경우 다 검사
	for (int i = 0; i < n - 3; i++)
	{
		res = std::max(res, solve(i) * (n - 1 - i));
	}

	return res;
}

int main()
{
	std::fill(table, table + 101, -1);
	int n;
	scanf("%d", &n);

	printf("%lld", solve(n));
	return 0;
}