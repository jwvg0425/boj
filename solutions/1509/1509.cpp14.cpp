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

bool isPalindrome[2501][2501];

int main()
{
	std::string s;
	std::cin >> s;

	for (int i = 0; i < s.size(); i++)
		isPalindrome[i][i] = true;

	for (int i = 0; i < s.size() - 1; i++)
			isPalindrome[i][i + 1] = (s[i] == s[i + 1]);

	for (int length = 3; length <= s.size(); length++)
		for (int i = 0; i <= s.size() - length; i++)
			isPalindrome[i][i + length - 1] =
				(s[i] == s[i + length - 1] &&
					isPalindrome[i + 1][i + length - 2]);
	
	int table[2501] = { 0, 1, };

	for (int i = 2; i <= s.size(); i++)
	{
		table[i] = 987654321;
		for (int j = 0; j < i; j++)
		{
			if (!isPalindrome[j][i - 1])
				continue;

			table[i] = std::min(table[i], table[j] + 1);
		}
	}

	printf("%d", table[s.size()]);

	return 0;
}