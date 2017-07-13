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
#define MAX 987654321

long long int gcd(long long int a, long long int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

long long int lcm(long long int a, long long int b)
{
	return a * b / gcd(a, b);
}

int main()
{
	long long int arr[5];
	
	for (int i = 0; i < 5; i++)
		scanf("%lld", &arr[i]);

	long long int min = 10000000000ll;

	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			for (int k = j + 1; k < 5; k++)
			{
				min = std::min(min, lcm(lcm(arr[i], arr[j]), arr[k]));
			}
		}
	}

	printf("%lld", min);
	return 0;
}