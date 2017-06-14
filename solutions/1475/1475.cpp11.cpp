#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>

int main()
{
	std::string str;
	std::cin >> str;

	int count[10] = { 0, };
	int set = 0;

	for (auto& c : str)
	{
		int k = c - '0';

		if (k == 6 || k == 9)
		{
			if (count[6] > count[9])
				k = 9;
			else
				k = 6;
		}

		count[k]++;
		set = std::max(set, count[k]);
	}

	printf("%d", set);

	return 0;
}