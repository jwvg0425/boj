#include <stdio.h>
#include <memory.h>
#include <algorithm>

int arr[20];

int f(int n)
{
	if (arr[n] != -1)
		return arr[n];

	if (n == 1)
		return 1;

	if (n == 2)
		return 2;

	if (n == 3)
		return 4;

	int& res = arr[n];

	res = f(n - 1) + f(n - 2) + f(n - 3);

	return res;
}

int main()
{
	int T;

	scanf("%d", &T);

	memset(arr, -1, sizeof(arr));

	for (int i = 0; i < T; i++)
	{
		int n;
		scanf("%d", &n);

		printf("%d\n", f(n));
	}
}