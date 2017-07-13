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
	int n, m, k;

	scanf("%d %d %d", &n, &m, &k);

	int count = 0;

	while (n >= 2 && m >= 1 && n + m - 3 >= k)
	{
		count++;
		n -= 2;
		m -= 1;
	}

	printf("%d", count);

	return 0;
}