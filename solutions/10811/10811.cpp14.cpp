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
	int n, m;
	scanf("%d %d", &n, &m);

	std::vector<int> basket;

	for (int i = 1; i <= n; i++)
	{
		basket.push_back(i);
	}

	for (int i = 0; i < m; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);

		s--; e--;

		while (s <= e)
		{
			std::swap(basket[s], basket[e]);
			s++;
			e--;
		}
	}

	for (auto& b : basket)
	{
		printf("%d ", b);
	}

	return 0;
}