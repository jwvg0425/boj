#include <stdio.h>
#include <memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <tuple>
#include <time.h>

int main()
{
	int n, b;
	std::string str;

	scanf("%d %d", &n,&b);

	while (n > 0)
	{
		int digit = n %b;

		if (digit < 10)
			str.push_back(digit + '0');
		else
			str.push_back(digit - 10 + 'A');

		n /= b;
	}

	if (str.size() == 0)
		str.push_back('0');

	std::reverse(str.begin(), str.end());

	std::cout << str;

	return 0;
}