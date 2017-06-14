#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <stack>
#include <memory.h>

int main()
{
	int n;
	scanf("%d", &n);

	std::vector<std::pair<long long int, long long int>> arr;
	
	for (int i = 0; i < n; i++)
	{
		long long int a, b;
		scanf("%lld %lld", &a, &b);
		arr.emplace_back(a, b);
	}

	std::sort(arr.begin(), arr.end(), [](auto l, auto r)
	{
		if(l.second != r.second)
			return l.second < r.second;

		return l.first < r.first;
	});

	long long int last = 0;
	int count = 0;

	for (auto& a : arr)
	{
		if (last <= a.first)
		{
			last = a.second;
			count++;
		}
	}

	printf("%d", count);

	return 0;
}