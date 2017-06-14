#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

int main()
{
	std::string str;

	std::cin >> str;

	while (str.size() % 3 != 0)
		str.insert(str.begin(), '0');

	for (int i = 0; i < str.size(); i += 3)
	{
		std::string s = str.substr(i, 3);
		int k = (s[0] - '0') * 4 + (s[1] - '0') * 2 + (s[2] - '0');

		printf("%d", k);
	}

	return 0;
}