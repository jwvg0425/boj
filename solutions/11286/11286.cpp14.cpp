#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <memory.h>

using ii = std::pair<int, int>;

int main()
{
	auto comp = [](int x, int y)
	{
		if (abs(x) > abs(y))
			return true;

		if (abs(x) < abs(y))
			return false;

		return x > y;
	};

	std::priority_queue<int, std::vector<int>, decltype(comp)> q(comp);

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);

		if (x == 0)
		{
			if (q.empty())
				printf("0\n");
			else
			{
				printf("%d\n", q.top());
				q.pop();
			}
		}
		else
		{
			q.push(x);
		}
	}

	return 0;
}