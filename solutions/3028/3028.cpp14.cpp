#include<stdio.h>
#include<memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
	bool pos[4] = { false,true,false,false };

	std::string str;

	std::cin >> str;

	for (auto& c : str)
	{
		switch (c)
		{
		case 'A':
			std::swap(pos[1], pos[2]);
			break;
		case 'B':
			std::swap(pos[2], pos[3]);
			break;
		case 'C':
			std::swap(pos[1], pos[3]);
			break;
		}
	}

	for (int i = 1; i <= 3; i++)
		if (pos[i])
			printf("%d", i);

	return 0;
}