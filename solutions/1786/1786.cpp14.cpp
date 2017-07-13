#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <memory.h>

using ii = std::pair<int, int>;

int main()
{
	std::string text, pattern;

	std::getline(std::cin, text);
	std::getline(std::cin, pattern);

	std::vector<int> pi;
	pi.resize(pattern.size(), 0);
	pi[0] = -1;

	for (int i = 1; i < pattern.size(); i++)
	{
		int j = pi[i - 1] + 1;
		while (pattern[i] != pattern[j] && j > 0)
		{
			j = pi[j - 1] + 1;
		}

		if (pattern[i] == pattern[j])
			pi[i] = j;
		else
			pi[i] = -1;
	}

	std::vector<int> pos;

	for (int i = 0, j = 0; i <= text.size(); i++, j++)
	{
		if (j == pattern.size())
		{
			pos.push_back(i - j + 1);
		}

		if (i == text.size())
			break;

		while (text[i] != pattern[j] && j > 0)
			j = pi[j - 1] + 1;

		if (text[i] != pattern[j])
			j = -1;
	}

	printf("%d\n", pos.size());

	for (auto& p : pos)
	{
		printf("%d ", p);
	}

	return 0;
}