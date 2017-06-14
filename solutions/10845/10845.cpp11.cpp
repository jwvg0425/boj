#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>

int main()
{
	int n;

	std::cin >> n;

	std::queue<int> q;

	for (int i = 0; i < n; i++)
	{
		std::string order;

		std::cin >> order;

		if (order == "push")
		{
			int a;
			std::cin >> a;
			q.push(a);
		}
		else if (order == "pop")
		{
			if (q.empty())
				std::cout << -1 << std::endl;
			else
			{
				std::cout << q.front() << std::endl;
				q.pop();
			}
		}
		else if (order == "size")
		{
			std::cout << q.size() << std::endl;
		}
		else if (order == "empty")
		{
			std::cout << (q.empty() ? "1" : "0") << std::endl;
		}
		else if (order == "front")
		{
			if (q.empty())
				std::cout << -1 << std::endl;
			else
				std::cout << q.front() << std::endl;
		}
		else if (order == "back")
		{
			if (q.empty())
				std::cout << -1 << std::endl;
			else
				std::cout << q.back() << std::endl;
		}
	}

	return 0;
}