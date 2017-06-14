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
	std::string str;
	
	std::cin >> str;

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			if (x == 1 && y == 1)
				std::cout << ":" << str << ":";
			else
				std::cout << ":fan:";
		}

		std::cout << std::endl;
	}

	return 0;
}