#include<stdio.h>
#include<memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

std::vector<int> a;
int lis[1001];
int bit[1001];

int calc_lis(int n)
{
	if (n == 0)
		return 1;

	if (lis[n] != -1)
		return lis[n];

	int& res = lis[n];
	res = 1;

	for (int i = 0; i < n; i++)
	{
		if (a[i] >= a[n])
			continue;

		res = std::max(1 + calc_lis(i), res);
	}

	return res;
}

int bitonic(int n)
{
	if (n == 0)
		return 1;

	if (bit[n] != -1)
		return bit[n];

	int& res = bit[n];
	res = 1;

	for (int i = 0; i < n; i++)
	{
		if (a[i] <= a[n])
			continue;

		res = std::max({ res, 1 + bitonic(i), 1 + calc_lis(i) });
	}

	return res;
}

int main()
{
	int n;
	scanf("%d", &n);

	memset(lis, -1, sizeof(lis));
	memset(bit, -1, sizeof(bit));

	for (int i = 0; i < n; i++)
	{
		int ai;
		scanf("%d", &ai);
		a.push_back(ai);
	}

	a.push_back(0);

	printf("%d", bitonic(n) - 1);

	return 0;
}