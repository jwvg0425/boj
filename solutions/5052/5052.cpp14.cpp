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

void solve()
{
	int n;
	scanf("%d", &n);
	std::vector<std::string> numbers;

	for (int i = 0; i < n; i++)
	{
		std::string number;

		std::cin >> number;

		numbers.push_back(number);
	}

	std::sort(numbers.begin(), numbers.end());

	for (int i = 1; i < n; i++)
	{
		if (numbers[i].size() < numbers[i - 1].size())
			continue;

		if (numbers[i].substr(0, numbers[i - 1].size()) == numbers[i - 1])
		{
			printf("NO\n");
			return;
		}
	}

	printf("YES\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int k = 0; k < t; k++)
	{
		solve();
	}

	return 0;
}