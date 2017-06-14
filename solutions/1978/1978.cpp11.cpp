#include <stdio.h>
#include <memory.h>
#include <algorithm>

bool isPrime(int n)
{
	if (n == 1)
		return false;

	for (int k = 2; k < n; k++)
	{
		if (n%k == 0)
			return false;
	}

	return true;
}

int main()
{
	int n;

	scanf("%d", &n);

	int count = 0;

	for (int i = 0; i < n; i++)
	{
		int a;

		scanf("%d", &a);

		if (isPrime(a))
			count++;
	}
	printf("%d", count);
}