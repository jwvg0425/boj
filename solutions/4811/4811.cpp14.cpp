#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <stack>
#include <memory.h>

using ii = std::pair<int, int>;

long long int table[31][31];

long long int solve(int w, int h)
{
	if (w == 0 && h == 0)
		return 1;

	if (table[w][h] != -1)
		return table[w][h];

	long long int& res = table[w][h];
	res = 0;
	
	if(w > 0)
		res = solve(w - 1, h + 1);

	if (h > 0)
		res += solve(w, h - 1);

	return res;
}

int main()
{
	memset(table, -1, sizeof(table));

	while(true)
	{
		int n;
		scanf("%d", &n);

		if (n == 0)
			break;

		printf("%lld\n", solve(n, 0));

	}
	return 0;
}