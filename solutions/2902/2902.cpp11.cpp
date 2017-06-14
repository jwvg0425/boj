#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>

int main()
{
	std::string s;

	std::cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		if (i == 0)
			printf("%c", s[i]);

		if (s[i] == '-')
			printf("%c", s[i + 1]);
	}
}