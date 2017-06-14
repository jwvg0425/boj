#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
#include <string>

int main()
{
	std::stack<int> st;

	int n;

	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::string order;
		int k;
		std::cin >> order;

		if (order == "push")
		{
			std::cin >> k;
			st.push(k);
		}
		else if (order == "top")
		{
			if (st.size() == 0)
				printf("-1\n");
			else
				printf("%d\n", st.top());
		}
		else if (order == "pop")
		{
			if (st.size() == 0)
				printf("-1\n");
			else
			{
				printf("%d\n", st.top());
				st.pop();
			}
		}
		else if (order == "empty")
		{
			printf("%d\n", st.empty() ? 1 : 0);
		}
		else if (order == "size")
		{
			printf("%d\n", st.size());
		}
	}
}