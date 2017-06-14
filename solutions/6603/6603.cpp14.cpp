#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <memory.h>

void comb(std::vector<int>& cand, int idx, std::vector<int>& set)
{
	if (set.size() == 6)
	{
		for (auto& s : set)
			printf("%d ", s);
		printf("\n");
		return;
	}

	if (idx >= cand.size())
		return;

	set.push_back(cand[idx]);
	comb(cand, idx + 1, set);
	set.pop_back();
	comb(cand, idx + 1, set);
}

int main()
{
	while (true)
	{
		int n;
		scanf("%d", &n);

		if (n == 0)
			return 0;

		std::vector<int> s;

		for (int i = 0; i < n; i++)
		{
			int a;
			scanf("%d", &a);
			s.push_back(a);
		}

		std::vector<int> set;

		comb(s, 0, set);

		printf("\n");

	}

	return 0;
}