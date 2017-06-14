#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

int main()
{
	std::vector<int> q;
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		q.push_back(i);
	}

	int pos = 0;
	int count = 0;

	for (int i = 0; i < m; i++)
	{
		int k;

		scanf("%d", &k);

		//pos에서 빼면 됨
		if (q[pos] == k)
		{
			q.erase(q.begin() + pos);
			if(q.size() != 0)
				pos %= q.size();
			continue;
		}

		for (int d = 1; d < q.size(); d++)
		{
			int next = (pos + d) % q.size();
			int prev = pos - d;
			if (prev < 0)
				prev += q.size();

			if (q[next] == k)
			{
				count += d;
				pos = next;
				q.erase(q.begin() + pos);
				if (q.size() != 0)
					pos %= q.size();
				break;
			}

			if (q[prev] == k)
			{
				count += d;
				pos = prev;
				q.erase(q.begin() + pos);
				if (q.size() != 0)
					pos %= q.size();
				break;
			}
		}
	}

	printf("%d", count);

	return 0;
}