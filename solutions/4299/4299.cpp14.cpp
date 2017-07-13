#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <stack>
#include <memory.h>

using ii = std::pair<int, int>;

int main()
{
	int sum, sub;
	scanf("%d %d", &sum, &sub);

	int a = sum + sub;

	if (a % 2 != 0)
	{
		printf("-1");
		return 0;
	}
	a /= 2;

	int b = sum - a;

	if (b < 0)
	{
		printf("-1");
		return 0;
	}

	if (a < b)
		std::swap(a, b);

	printf("%d %d", a, b);

	return 0;
}