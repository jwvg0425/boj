#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>
#include <time.h>

using ii = std::pair<int, int>;

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

int main()
{
	int g, l;
	scanf("%d %d", &g, &l);

	int ab = l / g;

	int mina = 1, minb = ab;

	for (int i = 2; i * i <= ab; i++)
	{
		if (ab %i != 0)
			continue;

		int a = i, b = ab / i;

		if (gcd(a, b) != 1)
			continue;

		if (a + b < mina + minb)
		{
			mina = a;
			minb = b;
		}
	}

	printf("%d %d", mina * g, minb *g);

	return 0;
}