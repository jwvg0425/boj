#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

using ii = std::pair<int, int>;

std::vector<ii> foods;
bool table[1000000];

int solve()
{
	memset(table, false, sizeof(table));
	foods.clear();
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int p, s;

		scanf("%d %d", &p, &s);

		foods.emplace_back(p, s);
	}

	std::sort(foods.begin(), foods.end(), [](const ii& left, const ii& right)
	{
		return left.first + left.second < right.first + right.second;
	});

	int sum = 0;
	table[0] = true;

	for (auto& f : foods)
	{
		for (int i = std::min(sum, f.first); i >= 0; i--)
		{
			if (table[i])
				table[i + f.second] = true;
		}

		sum += f.second;
	}

	for (int i = sum; i >= 0; i--)
		if (table[i])
			return i;

	return 0;
}


int main() 
{
	int t;
	scanf("%d\n", &t);

	for (int i = 1; i <= t; i++)
	{
		printf("Case #%d: %d\n", i, solve());
	}
}