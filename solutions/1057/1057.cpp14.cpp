#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <stack>
#include <memory.h>

int main()
{
	int n, a, b;

	scanf("%d %d %d", &n, &a, &b);

	int round = 0;

	while (a != b)
	{
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		round++;
	}

	printf("%d", round);
	return 0;
}