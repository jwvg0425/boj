#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>

int main()
{
	int n;

	scanf("%d", &n);

	long long int arr[100];
	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	printf("%lld", arr[n]);
}