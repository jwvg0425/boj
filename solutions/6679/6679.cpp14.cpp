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

using ii = std::pair<int, int>;

int dsum(int n, int k)
{
	int res = 0;

	while (n > 0)
	{
		res += n % k;
		n /= k;
	}

	return res;
}

int main()
{
	for (int n = 1000; n <= 9999; n++)
	{
		int d10 = dsum(n, 10), d12 = dsum(n, 12), d16 = dsum(n, 16);

		if (d10 == d12 && d12 == d16)
			printf("%d\n", n);
	}

	return 0;
}