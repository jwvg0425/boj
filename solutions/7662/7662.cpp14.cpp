#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

void solve()
{
	std::map<int, int> s;

	int k;
	scanf("%d", &k);

	for (int i = 0; i < k; i++)
	{
		std::string op;
		int n;

		std::cin >> op >> n;

		if (op == "I")
		{
			s[n]++;
		}
		else
		{
			if (s.empty())
				continue;

			if (n == 1)
			{
				s.rbegin()->second--;

				if (s.rbegin()->second == 0)
				{
					s.erase(s.rbegin()->first);
				}
			}
			else
			{
				s.begin()->second--;

				if (s.begin()->second == 0)
				{
					s.erase(s.begin()->first);
				}
			}
		}
	}

	if (s.empty())
		printf("EMPTY\n");
	else
		printf("%d %d\n", s.rbegin()->first, s.begin()->first);
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
		solve();

	return 0;
}