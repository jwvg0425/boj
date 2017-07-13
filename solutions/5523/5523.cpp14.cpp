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
	int n;
	scanf("%d", &n);

	int awin = 0, bwin = 0;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		if (a > b)
			awin++;
		
		if (b > a)
			bwin++;
	}

	printf("%d %d", awin, bwin);

	return 0;
}