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
#include <functional>
#include <stack>

int main()
{
	int n;
	scanf("%d", &n);

	std::stack<std::pair<int, int>> s;
	std::vector<int> idx;

	s.emplace(100000001, 0);

	for (int i = 0; i < n; i++)
	{
		int h;
		scanf("%d", &h);

		while (s.top().first < h)
		{
			s.pop();
		}

		idx.push_back(s.top().second);
		s.emplace(h, i + 1);
	}

	for (auto& i : idx)
		printf("%d ", i);

	return 0;
}