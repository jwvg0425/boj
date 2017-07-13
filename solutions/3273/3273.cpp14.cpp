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
bool exists[1000001];

int main()
{
	int n;
	scanf("%d", &n);

	std::vector<int> arr;

	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		exists[k] = true;
		arr.push_back(k);
	}

	int x;
	scanf("%d", &x);

	int count = 0;

	for (auto& a : arr)
	{
		if (x - a >= 0 && x - a <= 1000000 && exists[x - a])
			count++;
	}

	printf("%d", count / 2);

	return 0;
}