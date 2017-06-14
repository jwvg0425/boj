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
#include<set>

int main()
{
	int n;

	scanf("%d", &n);

	std::vector<int> sums = { 0, };

	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);

		sums.push_back(sums.back() + k);
	}

	int m;

	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);

		printf("%d\n", sums[e] - sums[s - 1]);
	}

	return 0;
}