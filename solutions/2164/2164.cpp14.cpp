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
	std::queue<int> nums;

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		nums.push(i);

	int t = 0;

	while (nums.size() > 1)
	{
		if (t == 1)
			nums.push(nums.front());

		nums.pop();

		t = (t + 1) % 2;
	}

	printf("%d", nums.front());

	return 0;
}