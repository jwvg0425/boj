#include <stdio.h>
#include <memory.h>

int table[1001][1001];

int c(int n, int k)
{
	if (k > n)
		return 0;

	if (n == 1)
		return 1;

	if (k == 0)
		return 1;

	if (table[n][k] != -1)
		return table[n][k];

	return table[n][k] = (c(n - 1, k) + c(n - 1, k - 1)) % 10007;
}

int main()
{
	memset(table, -1, sizeof(table));

	int n, k;

	scanf("%d %d", &n, &k);

	printf("%d", c(n, k));

	return 0;
}