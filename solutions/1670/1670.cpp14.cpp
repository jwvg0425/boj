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

long long int table[10001];

int main()
{
	int n;
	scanf("%d", &n);
	table[0] = 1;
	table[2] = 1;

	for (int i = 4; i <= n; i+=2)
	{
		for (int j = 1; j <= i; j ++)
		{
			table[i] += table[j - 1] * table[i - j - 1];
			table[i] %= 987654321;
		}
	}

	printf("%d", table[n]);

	return 0;
}