#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <string>
#include <algorithm>

int transition[][2] =
//  0  1
{ { 1, 2 } // 0
, { -1, 0 } // 1
, { 3, -1 } // 2
, { 4, -1 } // 3
, { 4, 5 } // 4
, { 1, 6 } // 5
, { 7, 6 } // 6
, { 4, 0 } // 7
};

bool accept[] = 
{ true // 0
, false // 1
, false // 2
, false // 3
, false // 4
, true // 5
, true // 6
, false // 7
};

int main()
{
	int state = 0;

	std::string str;

	std::cin >> str;

	for (auto& c : str)
	{
		state = transition[state][c - '0'];
		if (state == -1)
		{
			printf("NOISE");
			return 0;
		}
	}

	if (accept[state])
		printf("SUBMARINE");
	else
		printf("NOISE");

	return 0;
}