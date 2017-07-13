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

using ii = std::pair<long long int, long long int>;

long long int ccw(ii p1, ii p2, ii p3)
{
	return (p2.first - p1.first)  * (p3.second - p1.second) -
		(p2.second - p1.second) * (p3.first - p1.first);
}

long long int distance(ii p1, ii p2)
{
	long long int dx = p1.first - p2.first;
	long long int dy = p1.second - p2.second;

	return dx * dx + dy * dy;
}

int main()
{
	int n;
	std::vector<ii> points;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		long long int x, y;
		scanf("%lld %lld", &x, &y);
		points.emplace_back(x, y);
	}

	std::sort(points.begin(), points.end(), [](ii l, ii r)
	{
		if (l.second < r.second)
			return true;

		if (l.second > r.second)
			return false;

		return l.first < r.first;
	});

	ii start = points[0];

	std::sort(points.begin() + 1, points.end(), [start](ii l, ii r)
	{
		auto c = ccw(start, l, r);
		if (c > 0)
			return true;

		if (c < 0)
			return false;

		return distance(start, l) < distance(start, r);
	});

	std::vector<ii> hull = { points[0], points[1] };

	for (int i = 2; i < points.size();i++)
	{
		while(hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), points[i]) <= 0)
		{
			hull.pop_back();
		}

		hull.push_back(points[i]);
	}

	printf("%d", hull.size());
	return 0;
}