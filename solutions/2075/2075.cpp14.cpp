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
#include <time.h>

using ii = std::pair<int, int>;

int main()
{
	int n;
	scanf("%d", &n);

	auto comp = [](const int& l, const int& r)
	{
		return l > r;
	};

	std::priority_queue<int, std::vector<int>, decltype(comp)> nums(comp);

	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);

		nums.push(k);
	}
	for (int j = 0; j < n - 1; j++)
	{
		for (int i = 0; i < n; i++)
		{
			int k;
			scanf("%d", &k);

			if (nums.top() > k)
				continue;

			nums.pop();
			nums.push(k);
		}
	}


	printf("%d", nums.top());

	return 0;
}