#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int a, b;

		scanf("%d %d", &a, &b);

		printf("%d\n", a/ gcd(a,b) * b);
	}


	return 0;
}