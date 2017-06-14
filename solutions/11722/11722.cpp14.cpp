#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <stack>
#include <memory.h>

int arr[1002];
int table[1002];
int n;

int solve(int k)
{
	if (k == 0)
		return 1;

	if (table[k] != -1)
		return table[k];

	int& res = table[k];
	res = 1;

	for (int i = 0; i < k; i++)
	{
		if (arr[i] > arr[k])
			res = std::max(res, 1 + solve(i));
	}

	return res;
}

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	arr[n] = 0;

	memset(table, -1, sizeof(table));

	printf("%d", solve(n) - 1);

	return 0;
}