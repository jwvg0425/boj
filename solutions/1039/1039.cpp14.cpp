#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <memory.h>
#include <queue>
#include <set>



int main()
{
	int n, k;

	scanf("%d %d", &n, &k);

	std::set<int> visited;

	//(n,k)
	std::queue<std::pair<int, int>> q;

	int max = -1;

	q.emplace(n, 0);

	while (!q.empty())
	{
		auto now = q.front();
		q.pop();

		if (now.second != 0 && now.second % 2 == k % 2)
		{
			max = std::max(max, now.first);
		}

		if (now.second == k)
			continue;

		std::string str = std::to_string(now.first);

		for (int i = 0; i < str.size(); i++)
		{
			for (int j = i + 1; j < str.size(); j++)
			{
				if (i == 0 && str[j] == '0')
					continue;

				std::swap(str[i], str[j]);
				int changed = std::stoi(str);

				if (now.second % 2 == k % 2 || visited.find(changed) == visited.end())
				{
					q.emplace(changed, now.second + 1);

					if (now.second % 2 != k % 2)
						visited.insert(changed);
				}

				std::swap(str[i], str[j]);
			}
		}
	}

	printf("%d", max);

	return 0;
}