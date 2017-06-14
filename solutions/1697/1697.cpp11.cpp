#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>

int main()
{
	int n, k;

	scanf("%d %d", &n, &k);

	std::queue<std::pair<int, int>> q;

	q.emplace(0, n);

	int minLine = 100001;

	bool isVisit[200001] = { false, };

	while (!q.empty())
	{
		auto top = q.front();
		q.pop();

		if (isVisit[top.second])
			continue;

		isVisit[top.second] = true;

		if (top.first >= minLine)
			break;

		if (top.second == k)
		{
			printf("%d", top.first);
			return 0;
		}

		if (top.second > k)
		{
			minLine = std::min(minLine, top.first + top.second - k);
		}
		
		if(top.second < k)
		{
			q.emplace(top.first + 1, top.second * 2);
			q.emplace(top.first + 1, top.second + 1);
		}

		if(top.second > 0)
			q.emplace(top.first + 1, top.second - 1);
	}

	printf("%d", minLine);
}