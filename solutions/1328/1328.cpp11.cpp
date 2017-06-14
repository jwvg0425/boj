#include <stdio.h>
#include <memory.h>
#define MOD 1000000007

int N;
int table[101][101][101];

int answer(int h, int l, int r)
{
	//base case
	if (h == 0)
	{
		if (l != 0 || r != 0)
			return 0;
		else
			return 1;
	}

	//memo
	int& count = table[h][l][r];

	if (count != -1)
		return count;

	count = 0;

	if (l != 0)
	{
		count += answer(h - 1, l - 1, r);
	}

	if (r != 0)
	{
		count = (count + answer(h - 1, l, r - 1)) % MOD;
	}

	long long int between = ((long long int)answer(h - 1, l, r)) * (N - h - 1);
	between %= MOD;

	count = (count + between) % MOD;

	return count;
}

int main()
{
	int l, r;

	memset(table, -1, sizeof(table));

	scanf("%d %d %d", &N, &l, &r);

	printf("%d", answer(N - 1, l - 1, r - 1));
	return 0;
}