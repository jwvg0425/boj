#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>
#include <memory.h>
#include <math.h>

int distance(char c, int x, int y)
{
	char ans[5][5] =
	{
		"ABCD",
		"EFGH",
		"IJKL",
		"MNO"
	};

	for (int ax = 0; ax < 4; ax++)
	{
		for (int ay = 0; ay < 4; ay++)
		{
			if (ans[ax][ay] == c)
			{
				return abs(x - ax) + abs(y - ay);
			}
		}
	}

	return 0;
}

int main()
{
	std::string s;

	int count = 0;

	for (int i = 0; i < 4; i++)
	{
		std::cin >> s;

		for (int x = 0; x < 4; x++)
		{
			count += distance(s[x], i, x);
		}
	}

	printf("%d", count);

	return 0;
}