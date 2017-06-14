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
#include<set>

std::vector<int> convert(int k, int b)
{
	std::vector<int> res;

	while (k > 0)
	{
		res.push_back(k%b);
		k = k / b;
	}

	return res;
}

bool possible(int k)
{
	for (int b = 2; b <= 64; b++)
	{
		auto conv = convert(k, b);
		auto rev = conv;

		std::reverse(rev.begin(), rev.end());

		if (conv == rev)
			return true;
	}

	return false;
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int k;
		scanf("%d", &k);

		if (possible(k))
			printf("1\n");
		else
			printf("0\n");
	}

	return 0;
}