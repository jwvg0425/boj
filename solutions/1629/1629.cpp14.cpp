#include <stdio.h>
#include <memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <tuple>

long long int times(long long int a, long long int b, long long int c)
{
	if (b == 0)
		return 1 % c;

	if (b == 1)
		return a % c;

	//반반 나누기
	long long int l = times(a, b / 2, c);
	long long int square = (l*l) % c;

	if (b / 2 * 2 == b)
		return square;
	else
		return (square * a) % c;
}

int main()
{
	long long int a, b, c;

	scanf("%lld %lld %lld", &a, &b, &c);

	printf("%lld", times(a, b, c));
	return 0;
}