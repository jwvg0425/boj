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

int LCD(int a, int b)
{
	for (int i = std::max(a, b); i >= 1; i--)
	{
		if (a%i == 0 && b%i == 0)
			return i;
	}
}

int main()
{
	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		int A, B;
		scanf("%d %d", &A, &B);

		printf("%d\n", A*B/LCD(A, B));
	}
}