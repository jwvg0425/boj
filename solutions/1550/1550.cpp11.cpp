#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>

int main()
{
	std::string s;

	std::cin >> s;

	int val = 0;

	for (auto& c : s)
	{
		if (c >= '0' && c <= '9')
		{
			val = val * 16 + (c - '0');
		}
		else
		{
			val = val * 16 + (c - 'A') + 10;
		}
	}

	printf("%d", val);
}