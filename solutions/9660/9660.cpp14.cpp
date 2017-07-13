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
	long long n;
	scanf("%lld", &n);

	printf("%s", (n % 7 == 0 || n % 7 == 2) ? "CY" : "SK");

	return 0;
}