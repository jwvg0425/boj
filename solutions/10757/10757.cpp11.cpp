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
	std::string a;
	std::string b;

	std::cin >> a >> b;

	std::reverse(a.begin(), a.end());
	std::reverse(b.begin(), b.end());

	std::string c;
	
	int add = 0;

	for (int i = 0; i < std::min(a.size(), b.size()); i++)
	{
		int k = a[i] + b[i] + add - '0' * 2;
		add = k / 10;
		c.push_back(k % 10 + '0');
	}

	for (int j = std::min(a.size(), b.size()); j < std::max(a.size(), b.size()); j++)
	{
		if (a.size() > b.size())
		{
			int k = a[j] + add - '0';
			add = k / 10;
			c.push_back(k % 10 + '0');
		}
		else
		{
			int k = b[j] + add - '0';
			add = k / 10;
			c.push_back(k % 10 + '0');
		}
	}

	if (add != 0)
		c.push_back(add + '0');

	std::reverse(c.begin(), c.end());

	std::cout << c;

	return 0;
}