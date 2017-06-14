#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <memory.h>

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}
int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		printf("%d %d\n", a / gcd(a, b) * b, gcd(a, b));
	}
	return 0;
}