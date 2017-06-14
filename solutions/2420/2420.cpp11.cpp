#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>

int main()
{
	long long int a, b;

	scanf("%lld %lld", &a, &b);

	printf("%lld", llabs(a - b));
	return 0;
}