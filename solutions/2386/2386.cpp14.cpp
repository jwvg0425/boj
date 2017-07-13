#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>
#include <tuple>

int main()
{
	while (true)
	{
		std::string str;

		std::getline(std::cin, str);

		if (str == "#")
			break;

		int count = 0;

		for (int i = 2; i < str.size(); i++)
		{
			if (str[0] == str[i] || str[0] - 'a' + 'A' == str[i])
				count++;
		}

		printf("%c %d\n", str[0], count);
	}

	return 0;
}