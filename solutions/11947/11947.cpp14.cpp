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

long long int rev(long long int n)
{
	std::string str = std::to_string(n);

	for (auto& c : str)
		c = '9' - c + '0';

	return std::stoll(str);
}

long long int solve()
{
	long long int n;
	scanf("%lld", &n);

	long long int tmp = 1;

	while (tmp <= n) tmp *= 10;

	long long int maxPoint = tmp / 2;

	if (n > maxPoint) n = maxPoint;

	return n * rev(n);
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		printf("%lld\n", solve());
	}
	return 0;
}