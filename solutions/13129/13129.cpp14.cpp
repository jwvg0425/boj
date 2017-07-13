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
	int n, a, b;
	scanf("%d %d %d", &a, &b, &n);

	for (int i = 1; i <= n; i++)
	{
		int h = a * n + b * i;
		printf("%d ", h);
	}

	return 0;
}