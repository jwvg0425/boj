#include<stdio.h>
#include<memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	std::vector<std::string> hear;
	std::vector<std::string> see;

	for (int i = 0; i < n; i++)
	{
		std::string h;

		std::cin >> h;
		hear.push_back(h);
	}

	for (int i = 0; i < m; i++)
	{
		std::string s;

		std::cin >> s;
		see.push_back(s);
	}

	std::sort(hear.begin(), hear.end());
	std::sort(see.begin(), see.end());

	int hi = 0, si = 0;
	int k = 0;
	std::vector<std::string> list;

	while (hi < hear.size() && si < see.size())
	{
		if (hear[hi] == see[si])
		{
			k++;
			list.push_back(hear[hi]);
			hi++;
			si++;
		}
		else if (hear[hi] < see[si])
			hi++;
		else
			si++;
	}

	std::cout << k << std::endl;
	for (auto& l : list)
		std::cout << l << std::endl;

	return 0;
}