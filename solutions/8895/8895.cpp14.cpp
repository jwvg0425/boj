#include <stdio.h>
#include <memory.h>

int N;
long long int table[101][101][101];

long long int answer(int h, int l, int r)
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
	long long int& count = table[h][l][r];

	if (count != -1)
		return count;

	count = 0;

	if (l != 0)
	{
		count += answer(h - 1, l - 1, r);
	}

	if (r != 0)
	{
		count += answer(h - 1, l, r - 1);
	}

	long long int between = ((long long int)answer(h - 1, l, r)) * (N - h - 1);

	count += between;

	return count;
}

void solve()
{
	int l, r;

	memset(table, -1, sizeof(table));

	scanf("%d %d %d", &N, &l, &r);

	printf("%lld\n", answer(N - 1, l - 1, r - 1));
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
		solve();

	return 0;
}