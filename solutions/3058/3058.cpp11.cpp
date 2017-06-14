#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>

void solve()
{
	int min = 987654321;
	int sum = 0;

	for (int i = 0; i < 7; i++)
	{
		int k;
		scanf("%d", &k);

		if (k % 2 != 0)
			continue;

		min = std::min(min, k);
		sum += k;
	}

	printf("%d %d\n", sum, min);
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
		solve();

	return 0;
}