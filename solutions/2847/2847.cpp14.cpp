#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>
#include <tuple>

int main()
{
	int n;
	scanf("%d", &n);

	std::vector<int> level;

	for (int i = 0; i < n; i++)
	{
		int l;
		scanf("%d", &l);

		level.push_back(l);
	}

	int count = 0;

	for (int i = n - 2; i >= 0; i--)
	{
		if (level[i] >= level[i + 1])
		{
			count += level[i] - level[i + 1] + 1;
			level[i] = level[i + 1] - 1;
		}
	}

	printf("%d", count);

	return 0;
}