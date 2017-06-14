#include<stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

int main()
{
	int n;

	std::vector<std::pair<int, int>> pos;


	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		pos.emplace_back(x, y);
	}

	std::sort(pos.begin(), pos.end(), [](auto& l, auto& r)
	{
		if (l.first == r.first)
			return l.second < r.second;
		else
			return l.first < r.first;
	});

	for (auto& p : pos)
	{
		printf("%d %d\n", p.first, p.second);
	}

	return 0;
}