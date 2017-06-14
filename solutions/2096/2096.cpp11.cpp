#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>

int value[3];

int n;

//min, max
std::pair<int, int> table[2][3];

int main()
{
	scanf("%d", &n);

	scanf("%d %d %d", &value[0], &value[1], &value[2]);

	table[0][0] = std::make_pair(value[0], value[0]);
	table[0][1] = std::make_pair(value[1], value[1]);
	table[0][2] = std::make_pair(value[2], value[2]);

	for (int i = 1; i < n; i++)
	{
		scanf("%d %d %d", &value[0], &value[1], &value[2]);

		for (int j = 0; j < 3; j++)
		{
			table[i % 2][j].first = 987654321;
			table[i % 2][j].second = 0;

			for (int d = -1; d <= 1; d++)
			{
				if (j + d < 0 || j + d > 2)
					continue;

				table[i % 2][j].first = std::min(table[i % 2][j].first, table[(i + 1) % 2][j + d].first + value[j]);
				table[i % 2][j].second = std::max(table[i % 2][j].second, table[(i + 1) % 2][j + d].second + value[j]);
			}
		}
	}

	printf("%d %d", std::max({ table[(n - 1) % 2][0].second, table[(n - 1) % 2][1].second, table[(n - 1) % 2][2].second }),
		std::min({ table[(n - 1)%2][0].first, table[(n - 1) % 2][1].first, table[(n - 1) % 2][2].first }));

	return 0;
}