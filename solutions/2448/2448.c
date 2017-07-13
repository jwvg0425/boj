#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char output[3073][7145];

void init(int r, int c, int n, int k)
{
	if (n > 3)
	{
		init(r, c, n / 2, k - 1);
		init(r + n / 2, c - n / 2, n / 2, k - 1);
		init(r + n / 2, c + n / 2, n / 2, k - 1);
	}
	else
	{
		output[r][c] = '*';
		output[r + 1][c - 1] = output[r + 1][c + 1] = '*';
		for (int i = 0; i < 5; i++)
			output[r + 2][c - 2 + i] = '*';
	}
}

int main()
{
	int n;
	double k;
	scanf("%d", &n);
	k = log2(n / 3);

	for (int i = 0; i < n; i++)
	{
		memset(output[i], ' ', sizeof(char) * 2 * n - 1);
	}
    
	init(0, n - 1, n, (int)k);
	for (int i = 0; i < n; i++)
		puts(output[i]);
}