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
#include <functional>

int main()
{
	std::string arr[5];
	int size = 0;

	for (int i = 0; i < 5; i++)
	{
		std::cin >> arr[i];
		size = std::max<int>(size, arr[i].size());
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i >= arr[j].size())
				continue;

			std::cout << arr[j][i];
		}
	}

	return 0;
}