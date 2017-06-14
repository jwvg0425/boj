#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>

int main()
{
	int n;
	std::vector<std::string> passwords;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		std::string password;

		std::cin >> password;

		passwords.push_back(password);
	}

	for (auto s1 : passwords)
	{
		std::reverse(s1.begin(), s1.end());

		for (auto& s2 : passwords)
		{
			if (s1 != s2)
			{
				continue;
			}

			printf("%d %c", s1.size(), s1[s1.size() / 2]);
			return 0;
		}
	}

	return 0;
}