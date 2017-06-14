#include <stdio.h>
#include <memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <tuple>
#include <time.h>

int main()
{
	int n, t;
	
	scanf("%d %d", &n, &t);

	std::vector<std::pair<int, int>> drink;

	int minSum = 0, maxSum = 0;
	int left = 0, right = 0;

	for (int i = 0; i < n; i++)
	{
		int l, r;
		scanf("%d %d", &l, &r);

		drink.emplace_back(l, r);
		left = std::max(left, l);
		right = std::max(right, r);
		minSum += l;
		maxSum += r;
	}

	if (t < minSum || t > maxSum)
	{
		printf("-1");
		return 0;
	}

	int s = right;
	while (left <= right)
	{
		//S양 검사
		int mid = (left + right) / 2;

		int sum = 0;

		for (auto& d : drink)
		{
			sum += std::min(d.second, mid);
		}

		if (sum >= t)
		{
			s = std::min(s, mid);
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	printf("%d", s);

	return 0;
}