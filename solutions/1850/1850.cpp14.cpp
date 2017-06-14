#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>
#include <queue>
#include <tuple>
#include <map>
#include <functional>

long long int gcd(long long int a, long long int b)
{
	return b ? gcd(b, a%b) : a;
}

int main()
{
	long long int a, b;

	scanf("%lld %lld", &a, &b);

	long long int g = gcd(a, b);

	for (long long int i = 0; i < g; i++)
		printf("1");

	return 0;
}