#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>


std::vector<std::string> map;

int getSize(int x, int y)
{
	map[x][y] = '0';

	int size = 1;

	if (x > 0 && map[x - 1][y] == '1')
	{
		size += getSize(x - 1, y);
	}

	if (x < map.size() - 1 && map[x + 1][y] == '1')
	{
		size += getSize(x + 1, y);
	}

	if (y > 0 && map[x][y - 1] == '1')
	{
		size += getSize(x, y - 1);
	}

	if (y < map[x].size() - 1 && map[x][y + 1] == '1')
	{
		size += getSize(x, y + 1);
	}

	return size;
}

int main()
{
	int n;

	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::string m;
		std::cin >> m;
		map.push_back(m);
	}

	std::vector<int> size;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == '1')
				size.push_back(getSize(i, j));
		}
	}

	std::sort(size.begin(), size.end());

	std::cout << size.size() << std::endl;

	for (auto& s : size)
	{
		std::cout << s << std::endl;
	}

	return 0;
}