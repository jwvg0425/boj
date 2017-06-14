#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>

int main()
{
	int n;
	scanf("%d", &n);

	int count = 0;
	for (int k = 1; k <= n; k++)
	{
		if (k < 100)
		{
			count++;
			continue;
		}

		auto str = std::to_string(k);

		bool all = true;

		for (int i = 2; i < str.size(); i++)
		{
			if (str[i] - str[i - 1] != str[i - 1] - str[i - 2])
				all = false;
		}

		if (all)
			count++;
	}

	printf("%d", count);

	return 0;
}