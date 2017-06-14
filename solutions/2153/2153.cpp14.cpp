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
#include <deque>

int main()
{
	std::string str;

	std::cin >> str;

	int k = 0;

	for (auto& c : str)
	{
		if (c >= 'a' && c <= 'z')
			k += c - 'a' + 1;

		if (c >= 'A' && c <= 'Z')
			k += c - 'A' + 1;
	}

	for (int i = 2; i < k; i++)
	{
		if (k % i == 0)
		{
			printf("It is not a prime word.");
			return 0;
		}
	}

	printf("It is a prime word.");

	return 0;
}