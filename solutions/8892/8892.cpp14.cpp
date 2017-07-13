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

using ii = std::pair<int, int>;

bool isPalin(const std::string& s)
{
	for (int i = 0; i < s.size() / 2; i++)
	{
		if (s[i] != s[s.size() - 1 - i])
			return false;
	}

	return true;
}

std::string palindrome(const std::vector<std::string>& word)
{
	for (int j = 0; j < word.size(); j++)
	{
		for (int k = 0; k < word.size(); k++)
		{
			if (j == k)
				continue;

			std::string password = word[j] + word[k];

			if (isPalin(password))
				return password;
		}
	}

	return "0";
}

int main()
{
	std::ios::sync_with_stdio(false);

	int t;
	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		std::cin >> n;

		std::vector<std::string> word;

		for (int i = 0; i < n; i++)
		{
			std::string str;
			std::cin >> str;
			word.push_back(str);
		}

		std::cout << palindrome(word) << "\n";
	}

	return 0;
}