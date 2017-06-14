#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <memory.h>

using ii = std::pair<int, int>;

void solve()
{
	int n;

	std::vector<ii> arr;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		arr.emplace_back(a, b);
	}

	int prevb = n + 1;

	std::sort(arr.begin(), arr.end());

	int count = 0;

	for (auto& a : arr)
	{
		if (a.second < prevb)
		{
			prevb = a.second;
			count++;
		}
	}

	printf("%d\n", count);
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		solve();
	}

	return 0;
}