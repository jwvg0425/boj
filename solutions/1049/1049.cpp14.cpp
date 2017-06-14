#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>
#include <queue>
#include <tuple>
#include <map>




int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	std::vector<std::pair<int, int>> cost;

	for (int i = 0; i < m; i++)
	{
		int package, k;

		scanf("%d %d", &package, &k);
		cost.emplace_back(package, k);
	}

	auto p = cost;
	auto k = cost;

	std::sort(p.begin(), p.end());
	std::sort(k.begin(), k.end(), [](auto& l, auto& r)
	{
		if (l.second != r.second)
			return l.second < r.second;

		return l.first < r.first;
	});

	int min = (n + 5) / 6 * p[0].first;
	
	min = std::min(min, n / 6 * p[0].first + k[0].second * (n % 6));
	min = std::min(min, n * k[0].second);

	printf("%d", min);

	return 0;
}