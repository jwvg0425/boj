#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>
#include <time.h>

using ii = std::pair<int, int>;
using dd = std::pair<double, double>;

int main()
{
	ii ai, bi, ci, di;

	scanf("%d %d %d %d %d %d %d %d", &ai.first, &ai.second, &bi.first, &bi.second, &ci.first, &ci.second, &di.first, &di.second);

	dd a, b, c, d;

	a = ai;
	b = bi;
	c = ci;
	d = di;

	double l = sqrt((a.first - c.first) * (a.first - c.first) + (a.second - c.second) * (a.second - c.second));
	double r = sqrt((b.first - d.first) * (b.first - d.first) + (b.second - d.second) * (b.second - d.second));
	double minLength = std::min(l, r);

	for (int i = 0; i < 100; i++)
	{
		dd x, y;
		
		x.first = a.first * 0.5 + b.first * 0.5;
		x.second = a.second * 0.5 + b.second * 0.5;

		y.first = c.first * 0.5 + d.first * 0.5;
		y.second = c.second * 0.5 + d.second * 0.5;

		double leftLength = sqrt((a.first - c.first) * (a.first - c.first) + (a.second - c.second) * (a.second - c.second));
		double rightLength = sqrt((b.first - d.first) * (b.first - d.first) + (b.second - d.second) * (b.second - d.second));

		double midLength = sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));

		minLength = std::min(minLength, midLength);

		if (leftLength < rightLength)
		{
			b = x;
			d = y;
		}
		else
		{
			a = x;
			c = y;
		}
	}

	printf("%.10lf", minLength);


	return 0;
}