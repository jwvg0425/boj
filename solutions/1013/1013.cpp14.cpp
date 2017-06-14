#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <string>
#include <algorithm>

int transition[][2] =
//  0  1
{ { 1, 2 } // 0
,{ 8, 0 } // 1
,{ 3, 8 } // 2
,{ 4, 8 } // 3
,{ 4, 5 } // 4
,{ 1, 6 } // 5
,{ 7, 6 } // 6
,{ 4, 0 } // 7
,{ 8, 8 }
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
, false
};

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int state = 0;

		std::string str;

		std::cin >> str;

		for (auto& c : str)
		{
			state = transition[state][c - '0'];
		}

		if (accept[state])
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}