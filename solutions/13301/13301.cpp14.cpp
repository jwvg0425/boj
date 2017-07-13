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

int main()
{
	long long int fibo[81];

	fibo[0] = 1;
	fibo[1] = 2;

	int n;
	scanf("%d", &n);

	for (int i = 2; i <= n; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];

	printf("%lld", 2 * fibo[n]);

	return 0;
}