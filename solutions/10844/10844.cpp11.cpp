#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int arr[101][10];

int get(int n, int d)
{
	if (n == 1)
	{
		if (d == 0)
			return 0;
		else
			return 1;
	}

	if (arr[n][d] != -1)
		return arr[n][d];

	int& res = arr[n][d];
	res = 0;

	if (d == 0)
		res = get(n - 1, 1);
	else if (d == 9)
		res = get(n - 1, 8);
	else
		res = (get(n - 1, d - 1) + get(n - 1, d + 1)) % 1000000000;

	return res;
}

int main()
{
	int n;

	memset(arr, -1, sizeof(arr));

	scanf("%d", &n);

	int sum = 0;

	for (int i = 0; i < 10; i++)
	{
		sum = (sum + get(n, i)) % 1000000000;
	}

	printf("%d", sum);

	return 0;
}