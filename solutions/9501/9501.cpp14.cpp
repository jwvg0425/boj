#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <memory.h>
#include <stack>
#include <queue>
#include <map>
#include <set>

using ii = std::pair<int, int>;

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int n, d;
		scanf("%d %d", &n, &d);

		int count = 0;

		for (int j = 0; j < n; j++)
		{
			int v, f, c;
			scanf("%d %d %d", &v, &f, &c);

			int m = v * f;

			if (m >= d * c)
				count++;
		}

		printf("%d\n", count);
	}

	return 0;
}