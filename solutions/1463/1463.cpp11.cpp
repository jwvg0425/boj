#include <stdio.h>
#include <memory.h>
#include <algorithm>

int arr[1000001];

int f(int x)
{
	arr[1] = 0;
	for (int i = 2; i <= x; i++)
	{
		int min = arr[i - 1];

		if (i % 2 == 0)
			min = std::min(arr[i / 2], min);


		if (i % 3 == 0)
			min = std::min(arr[i / 3], min);

		arr[i] = min + 1;
	}
	return arr[x];
}

int main()
{
	int n;

	scanf("%d", &n);

	memset(arr, -1, sizeof(arr));

	printf("%d", f(n));
}