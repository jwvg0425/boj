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

	std::vector<int> plus, minus;
	int zeroCount = 0;

	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		if (k > 0)
			plus.push_back(k);
		else if (k == 0)
			zeroCount++;
		else
			minus.push_back(k);
	}

	std::sort(plus.begin(), plus.end());
	std::reverse(plus.begin(), plus.end());
	std::sort(minus.begin(), minus.end());

	int sum = 0;

	for (int i = 1; i < plus.size(); i += 2)
	{
		if (plus[i] == 1 || plus[i - 1] == 1)
		{
			sum += plus[i] + plus[i - 1];
		}
		else
		{
			sum += plus[i] * plus[i - 1];
		}
	}

	if (plus.size() % 2 == 1)
		sum += plus.back();

	for (int i = 1; i < minus.size(); i += 2)
	{
		sum += minus[i] * minus[i - 1];
	}

	if (minus.size() % 2 == 1)
	{
		if (zeroCount == 0)
			sum += minus.back();
	}

	printf("%d", sum);

	return 0;
}