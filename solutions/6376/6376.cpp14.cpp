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

using ii = std::pair<int, int>;

int main()
{
	printf("n e\n");
	printf("- -----------\n");
	printf("0 1\n");
	printf("1 2\n");
	printf("2 2.5\n");

	double e = 2.5;

	int fac = 2;

	for (int i = 3; i <= 9; i++)
	{
		fac *= std::max(1, i);
		e += 1.0 / fac;
		printf("%d %.9lf\n", i, e);
	}

	return 0;
}