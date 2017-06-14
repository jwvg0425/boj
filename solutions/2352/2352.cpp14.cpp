#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>
#include <tuple>

int main()
{
	int n;
	std::vector<int> table;
	scanf("%d", &n);

	int start;
	scanf("%d", &start);
	table.push_back(start);

	for (int i = 1; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		if (table.back() < a)
		{
			table.push_back(a);
			continue;
		}
		auto it = std::lower_bound(table.begin(), table.end(), a);
		*it = a;
	}
	
	printf("%d", table.size());

	return 0;
}