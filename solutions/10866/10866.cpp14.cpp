#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <deque>

int main()
{
	std::deque<int> d;

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		std::string order;

		std::cin >> order;
		
		int k;

		if (order == "push_front")
		{
			std::cin >> k;

			d.push_front(k);
		}
		else if (order == "push_back")
		{
			std::cin >> k;

			d.push_back(k);
		}
		else if (order == "pop_front")
		{
			if (d.empty())
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", d.front());
				d.pop_front();
			}
		}
		else if (order == "pop_back")
		{
			if (d.empty())
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", d.back());
				d.pop_back();
			}
		}
		else if (order == "size")
		{
			printf("%d\n", d.size());
		}
		else if (order == "empty")
		{
			printf("%d\n", d.empty() ? 1 : 0);
		}
		else if (order == "front")
		{
			if (d.empty())
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", d.front());
			}
		}
		else if (order == "back")
		{
			if (d.empty())
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", d.back());
			}
		}
	}

	return 0;
}