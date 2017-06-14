#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <math.h>

int main()
{
	for (int i = 0; i < 3; i++)
	{
		std::string str;

		std::cin >> str;

		str.push_back('X');

		int maxCount = 1;
		int count = 1;

		for (int j = 1; j < str.size(); j++)
		{
			if (str[j] == str[j - 1])
			{
				count++;
			}
			else
			{
				maxCount = std::max(maxCount, count);
				count = 1;
			}
		}

		printf("%d\n", maxCount);

	}
	return 0;
}