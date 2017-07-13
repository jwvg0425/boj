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

int main()
{
	float n;
	scanf("%f", &n);

	std::vector<std::pair<float, float>> points;

	for (int i = 0; i < 3; i++)
	{
		float a, b;
		scanf("%f %f", &a, &b);

		points.emplace_back(a, b);
	}

	for (int i = 0; i < 3; i++)
	{
		float a, b;
		std::tie(a, b) = points[i];

		if (a == b)
			continue;

		float mid = (a + b) * 0.5f;
		n = std::max(mid, n - mid);

		//위치 맞춰주기
		for (int j = 1; j < 3; j++)
		{
			float x, y;
			std::tie(x, y) = points[j];

			if (x < mid)
				x = mid - x;
			else
				x -= mid;

			if (y < mid)
				y = mid - y;
			else
				y -= mid;

			points[j] = std::make_pair(x, y);
		}
	}

	printf("%.1f", n);

	return 0;
}