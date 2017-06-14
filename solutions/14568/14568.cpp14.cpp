#include <stdio.h>
#include <memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <tuple>

int main()
{
	int n;
	scanf("%d", &n);

	int count = 0;

	for (int t = 2; t <= n; t += 2)
	{
		int remain = n - t;
		count += std::max((remain - 2) / 2, 0);
	}

	printf("%d", count);
	return 0;
}