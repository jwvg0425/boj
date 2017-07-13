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

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	std::vector<int> buckets;

	for (int i = 1; i <= n; i++)
		buckets.push_back(i);

	for (int i = 0; i < m; i++)
	{
		int l, r, m;
		scanf("%d %d %d", &l, &r, &m);
		l--; r--; m--;

		std::vector<int> copied = buckets;

		for (int j = m; j <= r; j++)
			buckets[j - m + l] = copied[j];

		for (int j = l; j < m; j++)
			buckets[j + r - m + 1] = copied[j];
	}

	for (auto& b : buckets)
		printf("%d ", b);

	return 0;
}