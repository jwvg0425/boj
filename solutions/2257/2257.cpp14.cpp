#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <memory.h>

using ii = std::pair<int, int>;

std::string str;

int main()
{
	std::cin >> str;

	std::stack<int> molcule;

	for (auto& c : str)
	{
		if (c == 'H')
		{
			molcule.push(1);
		}
		else if (c == 'C')
		{
			molcule.push(12);
		}
		else if (c == 'O')
		{
			molcule.push(16);
		}
		else if (c == '(')
		{
			//안쪽에 들어감
			molcule.push(-1);
		}
		else if (c == ')')
		{
			int res = 0;
			while (molcule.top() != -1)
			{
				res += molcule.top();
				molcule.pop();
			}
			molcule.pop();
			molcule.push(res);
		}
		else
		{
			molcule.top() *= c - '0';
		}
	}

	int res = 0;
	while (!molcule.empty())
	{
		res += molcule.top();
		molcule.pop();
	}

	printf("%d", res);


	return 0;
}