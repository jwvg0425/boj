#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

int main()
{
	std::string str;

	std::cin >> str;

	int k = 10;
	int off = 0;

	if (str[0] == '0')
	{
		if (str[1] == 'x')
		{
			//16
			k = 16;
			off = 2;
		}
		else
		{
			//8
			k = 8;
			off = 1;
		}
	}

	int num = 0;

	for (int i = off; i < str.size(); i++)
	{
		int d = 0;

		if (str[i] >= '0' && str[i] <= '9')
			d = str[i] - '0';
		else
			d = str[i] - 'a' + 10;

		num = num * k + d;
	}

	printf("%d", num);

	return 0;
}