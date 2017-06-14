#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>

int main()
{
	int sum = 0;
	std::string str;

	std::cin >> str;

	str.push_back(',');

	int start = 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ',')
		{
			sum += std::stoi(str.substr(start, i - start));
			start = i + 1;
		}
	}

	printf("%d", sum);

	return 0;
}