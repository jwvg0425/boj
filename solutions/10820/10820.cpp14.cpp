#include<stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
	std::string str;

	while (std::getline(std::cin, str))
	{
		int count[4] = { 0, };

		for (auto& c : str)
		{
			if (c >= 'a' && c <= 'z')
				count[0]++;
			else if (c >= 'A' && c <= 'Z')
				count[1]++;
			else if (c >= '0' && c <= '9')
				count[2]++;
			else
				count[3]++;
		}

		for (int i = 0; i < 4; i++)
			printf("%d ", count[i]);
		puts("");
	}

	return 0;
}