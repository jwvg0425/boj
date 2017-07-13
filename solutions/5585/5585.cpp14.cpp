#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <memory.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define MOD 1234567

using ii = std::pair<int, int>;

int main()
{
	std::vector<int> coins = { 500,100,50,10,5,1 };

	int n;

	scanf("%d", &n);

	n = 1000 - n;

	int count = 0;

	for (auto& c : coins)
	{
		while (c <= n)
		{
			n -= c;
			count++;
		}
	}

	printf("%d", count);

	return 0;
}