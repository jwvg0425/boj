#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>

int main()
{
	std::string str;

	std::cin >> str;

	int second = 0;

	for (auto& c : str)
	{
		if (c < 'P')
		{
			second += 3 + (c - 'A') / 3;
		}
		else if (c < 'T')
		{
			second += 8;
		}
		else if (c < 'W')
		{
			second += 9;
		}
		else
		{
			second += 10;
		}
	}

	printf("%d", second);

	return 0;
}