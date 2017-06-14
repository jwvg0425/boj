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
	int k, n;
	scanf("%d %d", &k, &n);

	std::vector<long long int> line;
	long long int left = 0, right = 0;

	for (int i = 0; i < k; i++)
	{
		long long int l;
		scanf("%lld", &l);
		line.push_back(l);

		right = std::max(right, l);
	}
	
	long long int ans = 0;
	while (left <= right)
	{
		long long int mid = (left + right) / 2;
		long long int count = 0;

		for (auto& l : line)
		{
			count += l / mid;
		}

		if (count < n)
			right = mid - 1;
		else
		{
			ans = std::max(ans, mid);
			left = mid + 1;
		}
	}

	printf("%lld", ans);

	return 0;
}