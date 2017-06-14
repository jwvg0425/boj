#include <stdio.h>
#include <memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <tuple>
#include <time.h>
#include <memory>

void solve(int n)
{
	std::vector<std::string> strs;

	scanf("\n");

	for (int i = 0; i < n; i++)
	{
		std::string str;

		std::getline(std::cin, str);

		strs.push_back(str);
	}

	int pos = 0;
	int line = 0;

	while (line < strs.size())
	{
		if (pos >= strs[line].size() || strs[line][pos] == ' ')
			line++;
		else
			pos++;
	}

	std::cout << pos + 1 << std::endl;
}

int main()
{
	while (true)
	{
		int n;
		scanf("%d", &n);

		if (n == 0)
			break;

		solve(n);
	}

	return 0;
}