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
	int r, c;

	scanf("%d %d", &r, &c);

	std::vector<std::string> map;

	for (int i = 0; i < r; i++)
	{
		std::string str;

		std::cin >> str;

		std::string rev = str;
		std::reverse(rev.begin(), rev.end());
		map.push_back(str + rev);
	}

	for (int i = r - 1; i >= 0; i--)
	{
		map.push_back(map[i]);
	}

	int a, b;
	scanf("%d %d", &a, &b);
	a--; b--;

	if (map[a][b] == '.')
		map[a][b] = '#';
	else
		map[a][b] = '.';

	for (auto& l : map)
		std::cout << l << std::endl;

	return 0;
}