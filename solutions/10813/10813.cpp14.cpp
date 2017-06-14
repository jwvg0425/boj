#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	std::vector<int> basket;

	for (int i = 0; i < n; i++)
	{
		basket.push_back(i + 1);
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;

		scanf("%d %d", &a, &b);

		std::swap(basket[a - 1], basket[b - 1]);
	}

	for (auto& ball : basket)
	{
		printf("%d ", ball);
	}

	return 0;
}