#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <memory.h>
#include <stack>

int main()
{
	int t;
	scanf("%d\n", &t);
	
	for (int i = 0; i < t; i++)
	{
		std::string keylog;

		std::getline(std::cin, keylog);

		std::string forward;
		std::string backward;

		for (auto& k : keylog)
		{
			if (k == '<')
			{
				if (!forward.empty())
				{
					backward.push_back(forward.back());
					forward.pop_back();
				}
			}
			else if (k == '>')
			{
				if (!backward.empty())
				{
					forward.push_back(backward.back());
					backward.pop_back();
				}
			}
			else if (k == '-')
			{
				if (!forward.empty())
				{
					forward.pop_back();
				}
			}
			else
			{
				forward.push_back(k);
			}
		}

		std::reverse(backward.begin(), backward.end());
		std::cout << forward << backward << '\n';
	}

	return 0;
}