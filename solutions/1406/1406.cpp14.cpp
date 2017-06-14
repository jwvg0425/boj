#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	std::string leftstr;
	std::string rightstr;
	std::cin >> leftstr;

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		std::string order;
		std::cin >> order;

		if (order == "L")
		{
			if (!leftstr.empty())
			{
				rightstr.push_back(leftstr.back());
				leftstr.pop_back();
			}
		}
		else if (order == "D")
		{
			if (!rightstr.empty())
			{
				leftstr.push_back(rightstr.back());
				rightstr.pop_back();
			}
		}
		else if (order == "B")
		{
			if (!leftstr.empty())
			{
				leftstr.pop_back();
			}
		}
		else if (order == "P")
		{
			std::string c;
			std::cin >> c;

			leftstr.push_back(c[0]);
		}
	}

	std::cout << leftstr;

	std::reverse(rightstr.begin(), rightstr.end());
	std::cout << rightstr;

	return 0;
}