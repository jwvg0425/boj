#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <memory.h>

using ii = std::pair<int, int>;

int main()
{
	int c, k;

	scanf("%d %d", &c, &k);

	int digit = 1;

	for (int i = 0; i < k; i++)
		digit *= 10;

	if (digit == 1)
	{
		printf("%d", c);
		return 0;
	}
	digit /= 10;

	c /= digit;

	if (c % 10 < 5)
		c -= c % 10;
	else
		c += 10 - c % 10;

	c *= digit;

	printf("%d", c);

	return 0;
}