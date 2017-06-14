#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <memory.h>

int main()
{
	while (true)
	{
		int counts[26] = { 0, };

		std::string str;

		std::getline(std::cin, str);

		if (str == "*")
			break;

		for (auto& c : str)
		{
			if (c == ' ')
				continue;

			counts[c - 'a']++;
		}

		bool pangram = true;

		for (int i = 0; i < 26; i++)
		{
			if (counts[i] == 0)
			{
				pangram = false;
			}
		}

		printf("%c\n", pangram ? 'Y' : 'N');
	}

	return 0;
}