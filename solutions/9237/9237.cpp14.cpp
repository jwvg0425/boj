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
	int n;
	scanf("%d", &n);
	std::vector<int> tree;

	for (int i = 0; i < n; i++)
	{
		int day;
		scanf("%d", &day);
		tree.push_back(day);
	}

	std::sort(tree.begin(), tree.end(), [](int l, int r)
	{
		return l > r;
	});

	int max = 0;

	for (int i = 0; i < n; i++)
	{
		max = std::max(max, tree[i] + i + 2);
	}

	printf("%d", max);


	return 0;
}