#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>
#include <functional>

int main()
{
	long long int n;

	scanf("%lld", &n);

	long long int a = (n + 1)*(n + 2) / 2;
	long long int b = n*(n + 1);

	long long int k = (a + b) % 45678;

	printf("%lld", k);
}