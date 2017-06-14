#include <stdio.h>
#include <memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <tuple>
#include <time.h>

int main()
{
	int n;
	scanf("%d", &n);
	std::vector<double> num;

	for (int i = 0; i < n; i++)
	{
		double a;
		scanf("%lf", &a);

		num.push_back(a);
	}

	double max = num[0];
	double max_here = num[0];

	for (int i = 1; i < num.size(); i++)
	{
		auto n = num[i];
		max_here = std::max(n, max_here * n);
		max = std::max(max, max_here);
	}

	printf("%.3lf", max);

	return 0;
}