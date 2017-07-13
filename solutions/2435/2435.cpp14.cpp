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

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	std::vector<int> d = { 0, };

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);

		d.push_back(d.back() + a);
	}
	int max = -100 * k - 1;

	for (int i = k; i <= n; i++)
	{
		max = std::max(max, d[i] - d[i - k]);
	}

	printf("%d", max);

	return 0;
}