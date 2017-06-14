#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <deque>

int table[300001];

std::vector<int> nums;

int main()
{

	int n;
	scanf("%d", &n);
	nums.push_back(1);

	for (int i = 2; nums.back() <= n; i++)
	{
		nums.push_back(nums.back() + (i * (i + 1)) / 2);
	}

	nums.pop_back();

	for (int i = 1; i <= n; i++)
	{
		table[i] = i;

		if (i > 4)
			table[i] = std::min(table[i], i / 4 + i % 4);

		for (int j = 2; j < nums.size() && i >= nums[j]; j++)
		{
			table[i] = std::min(table[i], 1 + table[i - nums[j]]);
		}
	}

	printf("%d", table[n]);

	return 0;
}