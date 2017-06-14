#include<stdio.h>


int main(void)
{
	int T,n,f[42],i;

	f[0] = 1;
	f[1] = 0;
	f[2] = 1;

	for (i = 3; i < 42; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &n);

		printf("%d %d\n", f[n], f[n + 1]);
	}
}