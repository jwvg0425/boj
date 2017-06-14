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
	int r, c, zr, zc;

	scanf("%d %d %d %d", &r, &c, &zr, &zc);

	for (int i = 0; i < r; i++)
	{
		std::string str;

		std::cin >> str;

		for (int y = 0; y < zr; y++)
		{
			for (auto& c : str)
			{
				for (int j = 0; j < zc; j++)
				{
					printf("%c", c);
				}
			}
			printf("\n");
		}
	}

	return 0;
}