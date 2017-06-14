#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <deque>
#include <tuple>

using iii = std::tuple<double, double, double>;

double distance(iii point, iii start, iii end)
{
	for (int i = 0; i < 100; i++)
	{
		double px, py, pz;
		double sx, sy, sz;
		double ex, ey, ez;
		
		std::tie(px, py, pz) = point;
		std::tie(sx, sy, sz) = start;
		std::tie(ex, ey, ez) = end;

		iii mid;

		double mx, my, mz;

		mx = (sx + ex) * 0.5;
		my = (sy + ey) * 0.5;
		mz = (sz + ez) * 0.5;

		mid = std::tie(mx, my, mz);

		if ((px - sx) * (px - sx) + (py- sy) * (py-sy) + (pz - sz) * (pz- sz) >
			(px - ex) * (px - ex) + (py - ey) * (py - ey) + (pz - ez) * (pz - ez))
		{
			start = mid;
		}
		else
		{
			end = mid;
		}
	}

	double px, py, pz;
	double sx, sy, sz;
	double ex, ey, ez;

	std::tie(px, py, pz) = point;
	std::tie(sx, sy, sz) = start;
	std::tie(ex, ey, ez) = end;

	double res = sqrt((px - sx) * (px - sx) + (py - sy) * (py - sy) + (pz - sz) * (pz - sz));

	return res;
}

int main()
{
	int ax, ay, az, bx, by, bz, cx, cy, cz;

	scanf("%d %d %d %d %d %d %d %d %d", &ax, &ay, &az, &bx, &by, &bz, &cx, &cy, &cz);

	printf("%.10lf", distance(std::tie(cx,cy,cz), std::tie(ax,ay,az), std::tie(bx,by,bz)));

	return 0;
}