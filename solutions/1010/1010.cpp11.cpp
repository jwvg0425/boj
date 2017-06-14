#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

long long int arr[32][32];

long long int f(int n, int m)
{
	if (arr[n][m] != -1)
		return arr[n][m];

	if (n == 1)
		return 1;

	long long int& res = arr[n][m];
	res = 0;

	for (int i = 0; i <= m - n; i++)
	{
		res += f(n - 1, m - i - 1);
	}
	return res;
}

int main()
{
	int T;
	scanf("%d", &T);

	memset(arr, -1, sizeof(arr));

	for (int i = 0; i < T; i++)
	{
		int n, m;

		scanf("%d %d", &n, &m);

		printf("%lld\n", f(n+1, m+1));
	}

}