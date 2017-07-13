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

int main()
{
	long long t[36] = { 1, };

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < i; j++)
			t[i] += t[j] * t[i - 1 - j];

	printf("%lld", t[n]);

	return 0;
}