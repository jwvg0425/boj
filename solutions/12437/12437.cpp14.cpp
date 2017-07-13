#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>


long long int gcd(long long int a, long long int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

long long int solve()
{
	long long int m, md, wd;

	scanf("%lld %lld %lld", &m, &md, &wd);

	long long int g = gcd(md, wd);
	long long int cycle = wd / g;
	long long int cycleLine = (cycle * md + wd - 1) / wd + cycle - 1;
	long long int other = m % cycle;
	long long int otherLine = (other * md + wd - 1) / wd + other - 1;

	if (otherLine < 0)
		otherLine = 0;

	return cycleLine * (m / cycle) + otherLine;
}

int main() 
{
	int t;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++)
	{
		printf("Case #%d: %lld\n", i, solve());
	}
}