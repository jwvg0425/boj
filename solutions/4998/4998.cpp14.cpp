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

int main()
{
	double n, m, b;

	while (~scanf("%lf %lf %lf", &n, &b, &m))
	{
		b *= 0.01;
		b += 1.0;

		int year = 0;

		while (n <= m)
		{
			n *= b;
			year++;
		}

		printf("%d\n", year);
	}

	return 0;
}