#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>

int main()
{
	int n, k;

	scanf("%d %d", &n, &k);
	
	std::vector<int> coins;

	for (int i = 0; i < n; i++)
	{
		int coin;
		scanf("%d", &coin);
		coins.push_back(coin);
	}

	int count = 0;
	int index = coins.size() - 1;

	while (k > 0)
	{
		while (coins[index] > k)
			index--;

		k -= coins[index];
		count++;
	}

	printf("%d", count);

	return 0;
}