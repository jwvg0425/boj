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
#include <bitset>

std::bitset<33554433> b;

int main()
{
	int n;

	while (~scanf("%d", &n))
	{
		if (b.test(n))
			continue;

		printf("%d ", n);
		b.set(n);
	}

	return 0;
}