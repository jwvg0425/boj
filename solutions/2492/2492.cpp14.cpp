#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

using ii = std::pair<int, int>;

int main()
{
	int n, m, t, a;

	scanf("%d %d %d %d", &n, &m, &t, &a);

	std::vector<ii> points;

	for (int i = 0; i < t; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		points.emplace_back(x, y);
	}

	ii max = points[0];
	int maxCount = 1;

	for (int i = 0; i < points.size(); i++)
	{
		for (int j = i + 1; j < points.size(); j++)
		{
			std::vector<ii> starts;
			int ix, iy, jx, jy;

			std::tie(ix, iy) = points[i];
			std::tie(jx, jy) = points[j];

			starts.emplace_back(std::min(ix, jx), std::max(iy, jy) - a);
			starts.emplace_back(std::max(ix, jx) - a, std::min(iy, jy));
			starts.emplace_back(std::min(ix, jx), std::min(iy, jy));
			starts.emplace_back(std::max(ix, jx) - a, std::max(iy, jy) - a);

			for (int k = 0; k < starts.size(); k++)
			{
				int count = 0;
				for (int l = 0; l < points.size(); l++)
				{
					if (points[l].first >= starts[k].first && points[l].first <= starts[k].first + a &&
						points[l].second >= starts[k].second && points[l].second <= starts[k].second + a)
					{
						count++;
					}
				}

				if (count > maxCount)
				{
					maxCount = count;
					max = std::make_pair(starts[k].first, starts[k].second + a);
				}
			}
		}
	}

	if (max.first < 0)
		max.first = 0;

	if (max.first + a > n)
		max.first = a - n;

	if (max.second > m)
		max.second = m;

	if (max.second - a < 0)
		max.second = m;

	printf("%d %d\n%d", max.first, max.second, maxCount);
}