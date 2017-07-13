#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <stack>
#include <memory.h>

using ii = std::pair<int, int>;

int main()
{
	long long int n, m;
	scanf("%lld %lld", &n, &m);

	std::vector<long long int> wait;
	long long int minTime = 1000000001;

	for (int i = 0; i < n; i++)
	{
		long long int t;
		scanf("%lld", &t);
		minTime = std::min(minTime, t);

		wait.push_back(t);
	}

	long long int left = 0, right = m * minTime;
	long long int ans = right;

	while (left <= right)
	{
		long long int mid = (left + right) / 2;

		long long int count = 0;

		for (auto& t : wait)
		{
			count += mid / t;
		}

		if (count >= m)
		{
			ans = std::min(ans, mid);
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	printf("%lld", ans);

	return 0;
}