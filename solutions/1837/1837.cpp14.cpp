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

bool check[1000001];

int main()
{
	std::string p;
	int k;

	std::cin >> p >> k;

	for (int i = 2; i <= k; i++)
	{
		if (check[i])
			continue;

		//prime check
		int mod = 0;

		for (int j = 0; j < p.size(); j++)
		{
			mod = (mod * 10 + (p[j] - '0')) % i;
		}

		if (mod == 0)
		{
			printf("BAD %d", i);
			return 0;
		}

		for (int j = i * 2; j <= k; j += i)
		{
			check[j] = true;
		}
	}

	printf("GOOD");

	return 0;
}