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
	std::string s;

	std::cin >> s;

	int stack = 0;
	int count = 0;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			stack++;
		else if (s[i] == ')')
		{
			stack--;
			//razor
			if (s[i - 1] == '(')
			{
				count += stack;
			}
			else
			{
				count++;
			}
		}
	}

	printf("%d", count);

	return 0;
}