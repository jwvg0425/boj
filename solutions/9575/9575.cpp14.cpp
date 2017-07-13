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

bool lucky(int k)
{
	while (k > 0)
	{
		int d = k % 10;
		
		if (d != 5 && d != 8)
			return false;

		k /= 10;
	}

	return true;
}

void solve()
{
	std::set<int> s;
	
	std::vector<int> v[3];

	for (int i = 0; i < 3; i++)
	{
		int k;
		scanf("%d", &k);

		for (int j = 0; j < k; j++)
		{
			int a;
			scanf("%d", &a);
			v[i].push_back(a);
		}
	}

	for (auto& a : v[0])
	{
		for (auto& b : v[1])
		{
			for (auto& c : v[2])
			{
				if (lucky(a + b + c))
				{
					s.insert(a + b + c);
				}
			}
		}
	}

	printf("%d\n", s.size());
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
		solve();

	return 0;
}