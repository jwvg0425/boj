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

int main()
{
	int a, b, n;
	scanf("%d %d %d", &a, &b, &n);

	for (int i = 0; i < n; i++)
	{
		a %= b;
		a *= 10;
	}

	printf("%d", a / b);

	return 0;
}