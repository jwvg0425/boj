#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
	int n;
	int arr[1001] = { 1, 3 };
	scanf("%d", &n);

	for (int i = 2; i < n; i++)
	{
		arr[i] = (arr[i - 1] + 2 * arr[i - 2]) % 10007;
	}

	printf("%d", arr[n - 1]);
}