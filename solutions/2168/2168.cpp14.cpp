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

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	printf("%d", n + m - gcd(n, m));

	return 0;
}