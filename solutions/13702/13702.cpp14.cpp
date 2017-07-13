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
#include <time.h>
#include <bitset>

int main()
{
	long long int n, k;

	std::vector<long long int> drink;

	scanf("%lld %lld", &n, &k);

	long long int left = 1;
	long long int right = 0;

	for (int i = 0; i < n; i++)
	{
		long long int d;
		scanf("%lld", &d);
		drink.push_back(d);
		right += d;
	}

	right /= k;

	long long int max = 0;

	while (left <= right)
	{
		long long int mid = left + (right - left) / 2;

		long long int count = 0;

		for (auto& d : drink)
			count += d / mid;

		if (count < k)
		{
			right = mid - 1;
		}
		else
		{
			max = std::max(max, mid);
			left = mid + 1;
		}
	}

	printf("%lld", max);

	return 0;
}