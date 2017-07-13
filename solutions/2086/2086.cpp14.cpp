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
#define MOD 1000000000

using ii = std::pair<long long, long long>;
using matrix = std::pair<ii, ii>;

matrix operator*(const matrix& l, const matrix& r)
{
	matrix res;

	res.first.first = (l.first.first * r.first.first + l.first.second * r.second.first) % MOD;
	res.first.second = (l.first.first * r.first.second + l.first.second * r.second.second) % MOD;
	res.second.first = (l.second.first * r.first.first + l.second.second * r.second.first) % MOD;
	res.second.second = (l.second.first * r.first.second + l.second.second * r.second.second) % MOD;

	return res;
}

long long int fibo(long long int n)
{
	matrix m = { { 1, 1 },{ 1, 0 } };
	matrix ans = { { 1, 0 },{ 0, 1 } };

	while (n > 0)
	{
		if (n % 2 == 1)
			ans = ans * m;

		m = m * m;
		n /= 2;
	}

	return ans.first.second;
}


int main()
{
	long long int a, b;

	scanf("%lld %lld", &a, &b);

	long long int ans = (fibo(b + 2) + MOD - fibo(a + 1)) % MOD;

	printf("%lld", ans);

	return 0;
}