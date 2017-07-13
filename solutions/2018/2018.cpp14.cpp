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

using ii = std::pair<int, int>;

int main()
{
	int n;
	scanf("%d", &n);

	int count = 0;
	int left = 1;
	int right = 1;
	int sum = 0;

	while (left <= n)
	{
		if (sum == n)
			count++;

		if (sum < n)
		{
			sum += right;
			right++;
		}
		else
		{
			sum -= left;
			left++;
		}
	}

	printf("%d", count);

	return 0;
}