#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

int main()
{
	std::vector<int> cards;
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		int c;
		scanf("%d", &c);
		cards.push_back(c);
	}

	int max = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				int sum = cards[i] + cards[j] + cards[k];

				if (sum > m)
					continue;

				max = std::max(sum, max);
			}
		}
	}

	printf("%d", max);

	return 0;
}