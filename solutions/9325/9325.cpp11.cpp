#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

void solve()
{
	int s,n;

	scanf("%d %d", &s,&n);

	for (int i = 0; i < n; i++)
	{
		int p, q;

		scanf("%d %d", &p, &q);
		s += p*q;
	}

	printf("%d\n", s);
}

int main()
{
	int t;

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		solve();
	}
}