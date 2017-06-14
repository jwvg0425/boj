#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>

int score(int a, int b, int c)
{
	if (a == b && b == c)
		return 10000 + a * 1000;
	else if (a == b)
		return 1000 + 100 * a;
	else if (b == c)
		return 1000 + 100 * b;
	else if (c == a)
		return 1000 + 100 * c;
	else
		return std::max({ a,b,c }) * 100;
}

int main()
{
	int n;

	scanf("%d", &n);

	int max = 0;

	for (int i = 0; i < n; i++)
	{
		int a, b, c;

		scanf("%d %d %d", &a, &b, &c);

		max = std::max(max, score(a, b, c));
	}

	printf("%d", max);
}