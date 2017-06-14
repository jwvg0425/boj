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
	long long int n;

	scanf("%lld", &n);

	printf("%s", n % 2 == 0 ? "CY" : "SK");
	return 0;
}