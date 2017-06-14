#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <memory.h>
#include <queue>

char upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return c;

	return c - 'a' + 'A';
}


int main()
{
	std::string str;

	while (true)
	{
		std::getline(std::cin, str);

		if (str[0] == '*')
			break;

		bool ok = true;

		for (int i = 1; i < str.size(); i++)
		{
			if (str[i - 1] == ' ' && upper(str[i]) != upper(str[0]))
			{
				ok = false;
				break;
			}
		}

		printf("%s\n", ok ? "Y" : "N");
	}

	return 0;
}