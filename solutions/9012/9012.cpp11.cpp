#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>

void solve()
{
	std::string s;

	std::cin >> s;

	std::stack<char> stack;

	for (auto c : s)
	{
		if (c == '(')
		{
			stack.push(c);
		}
		else
		{
			if (stack.empty())
			{
				printf("NO\n");
				return;
			}

			stack.pop();
		}
	}

	if (stack.empty())
		printf("YES\n");
	else
		printf("NO\n");
}

int main()
{
	int T;

	scanf("%d", &T);

	for (int i = 1; i <= T; i++)
	{
		solve();
	}
}