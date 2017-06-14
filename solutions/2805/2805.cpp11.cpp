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

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	std::vector<long long int> height;

	long long int left = 0, right = 0;

	for (int i = 0; i < n; i++)
	{
		long long int h;

		scanf("%lld", &h);

		height.push_back(h);

		right = std::max(right, h);
	}

	long long mid = 0;

	while (true)
	{
		long long mid = (left + right) / 2;

		long long k = 0;

		for (auto& h : height)
		{
			k += std::max(0ll, h - mid);
		}

		if (k == m || right - left <= 1ll)
		{
			printf("%lld", k >= m ? mid : mid + 1ll);
			break;
		}

		if (k > m)
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}

	return 0;
}