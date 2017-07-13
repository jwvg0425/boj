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

using iii = std::tuple<int, int, int>;

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	std::set<iii> visited;

	std::set<int> ans = { c, };

	std::queue<iii> q;

	q.emplace(0, 0, c);

	while (!q.empty())
	{
		int ai, bi, ci;

		std::tie(ai, bi, ci) = q.front();
		q.pop();

		std::vector<iii> cand;

		int na, nb, nc, gap;

		na = ai; nb = bi; nc = ci;
		gap = std::min(ai, b - bi);
		na -= gap; nb += gap;
		cand.emplace_back(na, nb, nc);

		na = ai; nb = bi; nc = ci;
		gap = std::min(ai, c - ci);
		na -= gap; nc += gap;
		cand.emplace_back(na, nb, nc);

		na = ai; nb = bi; nc = ci;
		gap = std::min(bi, a - ai);
		na += gap; nb -= gap;
		cand.emplace_back(na, nb, nc);

		na = ai; nb = bi; nc = ci;
		gap = std::min(bi, c - ci);
		nc += gap; nb -= gap;
		cand.emplace_back(na, nb, nc);

		na = ai; nb = bi; nc = ci;
		gap = std::min(ci, a - ai);
		nc -= gap; na += gap;
		cand.emplace_back(na, nb, nc);

		na = ai; nb = bi; nc = ci;
		gap = std::min(ci, b - bi);
		nc -= gap; nb += gap;
		cand.emplace_back(na, nb, nc);

		for (auto& c : cand)
		{
			if (visited.find(c) != visited.end())
				continue;

			visited.insert(c);

			if (std::get<0>(c) == 0)
				ans.insert(std::get<2>(c));

			q.push(c);
		}
	}

	for (auto& a : ans)
		printf("%d ", a);

	return 0;
}