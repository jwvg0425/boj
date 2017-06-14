#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <queue>
#include <tuple>
#include <memory.h>

int main()
{
	int a, b, c, d;
	int e, f, g, h;

	scanf("%d %d %d %d", &a, &b, &c, &d);
	scanf("%d %d %d %d", &e, &f, &g, &h);

	printf("%d", std::max(a + b + c + d, e + f + g + h));
	return 0;
}