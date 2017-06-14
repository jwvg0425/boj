#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <memory.h>

std::vector<int> arr;
int table[202];

int lis(int n)
{
	if (n == 0)
		return 1;

	if (table[n] != -1)
		return table[n];

	int& res = table[n];
	res = 1;

	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i] > arr[n])
			continue;

		res = std::max(res, 1 + lis(i));
	}

	return res;
}

int main()
{
	int n;
	scanf("%d", &n);
	memset(table, -1, sizeof(table));

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		arr.push_back(a);
	}
	arr.push_back(n + 1);

	int c = lis(n) - 1;

	printf("%d", n - c);

	return 0;
}