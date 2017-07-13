#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>
#include <time.h>

using ii = std::pair<int, int>;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	std::vector<std::string> map;

	for (int i = 0; i < n; i++)
	{
		std::string str;
		std::cin >> str;

		map.push_back(str);
	}

	int row = 0;
	int col = 0;

	for (int y = 0; y < n; y++)
	{
		bool exist = false;
		for (int x = 0; x < m; x++)
		{
			if (map[y][x] == 'X')
			{
				exist = true;
				break;
			}
		}

		if (!exist)
			row++;
	}

	for (int x = 0; x < m; x++)
	{
		bool exist = false;
		for (int y = 0; y < n; y++)
		{
			if (map[y][x] == 'X')
			{
				exist = true;
				break;
			}
		}

		if (!exist)
			col++;
	}

	printf("%d", std::max(row, col));

	return 0;
}