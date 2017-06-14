#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <deque>

int gcm(int a, int b)
{
	return b == 0 ? a : gcm(b, a % b);
}

int main()
{
	int r, g;

	scanf("%d %d", &r, &g);

	int m = gcm(r, g);

	std::vector<int> c;

	for (int i = 1; i * i <= m; i++)
	{
		if (m % i == 0)
		{
			c.push_back(i);

			if(i != m/i)
				c.push_back(m / i);
		}
	}

	for (auto& k : c)
	{
		printf("%d %d %d\n", k, r / k, g / k);
	}

	return 0;
}