#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <stack>
#include <memory.h>

using ii = std::pair<int, int>;

int main()
{
	int n;
	scanf("%d", &n);

	int count = 0;

	for (int i = 0; i < n; i++)
	{
		std::string word;
		std::cin >> word;
		std::stack<char> s;

		for (auto& c : word)
		{
			if (s.empty() || s.top() != c)
				s.push(c);
			else
				s.pop();
		}

		if (s.empty())
			count++;
	}

	printf("%d", count);

	return 0;
}