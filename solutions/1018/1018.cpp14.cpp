#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>
#include <memory.h>
#include <math.h>
#include <stack>

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	std::vector<std::string> board;

	for (int y = 0; y < n; y++)
	{
		std::string line;

		std::cin >> line;

		board.push_back(line);
	}

	int min = 65;

	for (int x = 0; x <= m - 8; x++)
	{
		for (int y = 0; y <= n - 8; y++)
		{
			int count = 0;

			for (int nx = x; nx < x + 8; nx++)
			{
				for (int ny = y; ny < y + 8; ny++)
				{
					int mod = (nx + ny - x - y) % 2;

					if (mod == 0 && board[ny][nx] == 'W' ||
						mod == 1 && board[ny][nx] == 'B')
					{
						count++;
					}
				}
			}

			min = std::min({ min, count, 64 - count });
		}
	}

	printf("%d", min);

	return 0;
}