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

int main()
{
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	if (c % 2 == 0)
		printf("%d", a);
	else
		printf("%d", a ^ b);
	return 0;
}