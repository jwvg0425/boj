#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>
#include <memory.h>
#include <math.h>
#include <stack>
#include <map>

int main()
{
	std::stack<char> s;
	std::string input;

	std::cin >> input;

	int num[31] = { 0, };

	for (auto& c : input)
	{
		int mult = 2;
		char open = '(';

		if (c == '(' || c == '[')
		{
			s.push(c);
		}
		else
		{
			if (c == ']')
			{
				mult = 3;
				open = '[';
			}

			if (s.empty() || s.top() != open)
			{
				printf("0");
				return 0;
			}

			if (num[s.size()] == 0)
				num[s.size() - 1] += mult;
			else
				num[s.size() - 1] += mult * num[s.size()];

			num[s.size()] = 0;

			s.pop();
		}
	}

	printf("%d", num[0]);

	return 0;
}