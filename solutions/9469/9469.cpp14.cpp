#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <memory.h>

using ii = std::pair<int, int>;

int main()
{
	int p;
	scanf("%d", &p);

	for (int i = 0; i < p; i++)
	{
		int n;
		float d, a, b, f;

		scanf("%d %f %f %f %f", &n, &d, &a, &b, &f);

		printf("%d %.2f\n", n, d / (a + b) * f);
	}

	return 0;
}