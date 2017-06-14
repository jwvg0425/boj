#include <stdio.h>
#include <memory.h>
#include <algorithm>

long long int arr[100][2];

long long int f(int n, int i)
{
	if (arr[n][i] != -1)
		return arr[n][i];

	if (n == 0)
		return 0;

	if (n == 1)
	{
		if(i==0)
			return 0;

		if (i == 1)
			return 1;
	}

	long long int& res = arr[n][i];

	if (i == 0)
		res = f(n - 1, 0) + f(n - 1, 1);
	else if (i == 1)
		res = f(n - 1, 0);

	return res;
}

int main()
{
	int N;

	memset(arr, -1, sizeof(arr));

	scanf("%d", &N);

	printf("%lld", f(N, 0) + f(N, 1));
}