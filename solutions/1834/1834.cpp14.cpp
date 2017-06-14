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

	long long int sum = 0;
	
	for (long long int i = 1; i < n; i++)
	{
		sum += n * i + i;
	}

	printf("%lld", sum);

	return 0;
}