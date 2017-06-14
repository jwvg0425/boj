#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>
#include <queue>

int main()
{
	std::vector<std::pair<int, int>> pos;
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int x, y;

		scanf("%d %d", &x, &y);
		pos.emplace_back(x, y);
	}

	std::sort(pos.begin(), pos.end(), [](const auto& l, const auto& r)
	{
		if (l.second != r.second)
			return l.second < r.second;

		return l.first < r.first;
	});

	for (auto& p : pos)
	{
		printf("%d %d\n", p.first, p.second);
	}

	return 0;
}