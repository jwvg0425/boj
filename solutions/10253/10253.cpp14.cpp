#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <memory.h>
#include <stack>

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	int t;

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int a, b;

		scanf("%d %d", &a, &b);

		int last = 0;

		while (a > 0)
		{
			last = (b+a-1) / a;
			int g = gcd(last, b);
			int lg = last / g;
			int bg = b / g;

			a *= lg;
			a -= bg;

			b = g * lg * bg;

		}

		printf("%d\n", last);
	}

	return 0;
}