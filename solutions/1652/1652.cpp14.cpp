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
	std::vector<std::string> map;

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		std::string str;
		std::cin >> str;

		str.push_back('X');

		map.push_back(str);
	}

	std::string bound(n + 1, 'X');

	map.push_back(bound);

	int r = 0, c = 0;

	for (int y = 0; y <= n; y++)
	{
		int k = 0;
		for (int x = 0; x <= n; x++)
		{
			if (map[y][x] == 'X')
			{
				if (k >= 2)
				{
					r++;
				}

				k = 0;
			}
			else
			{
				k++;
			}
		}
	}

	for (int x = 0; x <= n; x++)
	{
		int k = 0;
		for (int y = 0; y <= n; y++)
		{
			if (map[y][x] == 'X')
			{
				if (k >= 2)
				{
					c++;
				}

				k = 0;
			}
			else
			{
				k++;
			}
		}
	}

	printf("%d %d", r, c);

	return 0;
}