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

std::vector<int> nums;

long long int table[101][21];

long long int solve(int k, int now)
{
	if (k == nums.size() - 2)
		return (now == nums[k+1]) ? 1 : 0;

	if (table[k][now] != -1)
		return table[k][now];

	long long int& res = table[k][now];
	res = 0;

	if (now + nums[k + 1] <= 20 && now + nums[k + 1] >= 0)
		res += solve(k + 1, now + nums[k + 1]);

	if (now - nums[k + 1] <= 20 && now - nums[k + 1] >= 0)
		res += solve(k + 1, now - nums[k + 1]);

	return res;
}

int main()
{
	memset(table, -1, sizeof(table));

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		nums.push_back(k);
	}

	printf("%lld", solve(0, nums[0]));

	return 0;
}